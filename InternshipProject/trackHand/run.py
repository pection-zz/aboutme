from __future__ import print_function, unicode_literals
import tensorflow as tf
import numpy as np
import scipy.misc
import matplotlib
from sys import platform as sys_pf
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from numpy import array
from nets.ColorHandPose3DNetwork import ColorHandPose3DNetwork
from utils.general import detect_keypoints, trafo_coords, plot_hand, plot_hand_3d
import cv2
import argparse ,os,glob,time

#cv2.namedWindow("Capture Image")

img_counter = 0
FirstTime = True
if __name__ == '__main__':
#    ap = argparse.ArgumentParser()
#    ap.add_argument("-i", "--imagepath",
#                    help="path to folder which contain images.")
#    ap.add_argument("-c", "--capture", action='store_true',
#                                    help="To save dataset")
#    args = vars(ap.parse_args())
#    # images to be shown
#    if args["capture"]:
#        dirname='./ImageReal/'
#        dirname_remove = './ImageReal/*'
#        if (FirstTime==True):
#            dataname_file = glob.glob(dirname_remove)
#            for i in dataname_file:
#                os.remove(i)
#        FirstTime = False
#        cap = cv2.VideoCapture(0)
#        while(True):
#            ret, frame = cap.read()
#            cv2.imshow('frame',frame)
#            if not ret:
#                break
#            k = cv2.waitKey(1)
#            if k%256 == 27:
#                print("Escape hit, closing...")
#                break
#            elif k%256 == 32:
#                # SPACE pressed
#                img_name = "ImageforTest_{}.png".format(img_counter)
#                cv2.imwrite(os.path.join(dirname,img_name), frame)
#                print("{} written!".format(img_name))
#                img_counter += 1
#        cap.release()
#        cv2.destroyAllWindows()
#        image_list = glob.glob(os.path.abspath(dirname)+"/*.*")
#    else :
#        image_list = glob.glob(os.path.abspath(args["imagepath"])+"/*.*")
    os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'
    image_list = list()

    image_list.append('./power_left/12.jpg')
#    image_list.append('./data/img2.png')
#    image_list.append('./data/img3.png')
#    image_list.append('./data/img4.png')
#    image_list.append('./data/img5.png')
    print (image_list)
    # network input
    image_tf = tf.placeholder(tf.float32, shape=(1, 240, 320, 3))
    hand_side_tf = tf.constant([[1.0, 0.0]])  # left hand (true for all samples provided)
    evaluation = tf.placeholder_with_default(True, shape=())

    # build network
    net = ColorHandPose3DNetwork()
    hand_scoremap_tf, image_crop_tf, scale_tf, center_tf,\
    keypoints_scoremap_tf, keypoint_coord3d_tf = net.inference(image_tf, hand_side_tf, evaluation)

    # Start TF
    gpu_options = tf.GPUOptions(per_process_gpu_memory_fraction=0.8)
    sess = tf.Session(config=tf.ConfigProto(gpu_options=gpu_options))

    # initialize network
    net.init(sess)

    # Feed image list through network
    for img_name in image_list:
        image_raw = scipy.misc.imread(img_name,mode='RGB')
        image_raw = scipy.misc.imresize(image_raw, (240, 320))
        image_v = np.expand_dims((image_raw.astype('float') / 255.0) - 0.5, 0)
        hand_scoremap_v, image_crop_v, scale_v, center_v,\
        keypoints_scoremap_v, keypoint_coord3d_v = sess.run([hand_scoremap_tf, image_crop_tf, scale_tf, center_tf,
                                                             keypoints_scoremap_tf, keypoint_coord3d_tf],
                                                            feed_dict={image_tf: image_v})

        hand_scoremap_v = np.squeeze(hand_scoremap_v)
        image_crop_v = np.squeeze(image_crop_v)
        keypoints_scoremap_v = np.squeeze(keypoints_scoremap_v)
        keypoint_coord3d_v = np.squeeze(keypoint_coord3d_v)

        # post processing
        image_crop_v = ((image_crop_v + 0.5) * 255).astype('uint8')
        coord_hw_crop = detect_keypoints(np.squeeze(keypoints_scoremap_v))
        coord_hw = trafo_coords(coord_hw_crop, center_v, scale_v, 256)

        # visualize
        fig = plt.figure(1)
        ax1 = fig.add_subplot(221)
        ax2 = fig.add_subplot(222)
        ax3 = fig.add_subplot(223)
        ax4 = fig.add_subplot(224, projection='3d')
        ax1.imshow(image_raw)
        plot_hand(coord_hw, ax1)
        ax2.imshow(image_crop_v)
        plot_hand(coord_hw_crop, ax2)
        ax3.imshow(np.argmax(hand_scoremap_v, 2))
        plot_hand_3d(keypoint_coord3d_v, ax4)
        ax4.view_init(azim=-90.0, elev=-90.0)  # aligns the 3d coord with the camera view
        ax4.set_xlim([-3, 3])
        ax4.set_ylim([-3, 1])
        ax4.set_zlim([-3, 3])
        plt.show()

