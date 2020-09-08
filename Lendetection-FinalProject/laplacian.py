import cv2
import numpy as np
from matplotlib import pyplot as plt
import argparse
import glob
import os
from skimage.feature import hog
from skimage import data, exposure

def binarize_image(image):
	image2 =cv2.adaptiveThreshold(image,255,cv2.ADAPTIVE_THRESH_MEAN_C,cv2.THRESH_BINARY,5,2)
	return image2
def morphology(image):
	kernel = cv2.getStructuringElement(cv2.MORPH_ELLIPSE,(3,3))
	cv2.morphologyEx(image, cv2.MORPH_OPEN, kernel, image)
def filter_colors(image):
	white_threshold = 0
	lower_white = np.array([white_threshold, white_threshold, white_threshold])
	upper_white = np.array([255, 255, 255])
	white_mask = cv2.inRange(image, lower_white, upper_white)
	white_image = cv2.bitwise_and(image, image, mask=white_mask)
	return white_image
ap = argparse.ArgumentParser()
ap.add_argument("-i","--input",required = True, help="IMAGE input")
ap.add_argument("-o","--onepicture",action = 'store_true',help="one input")
args = vars(ap.parse_args())

if args["onepicture"]:
    fileList = glob.glob(os.path.abspath(args["input"]))
else:
    fileList = glob.glob(os.path.abspath(args["input"])+"/*.*")
    
print (args)
print (fileList)
for name in fileList:
    assert name is not None

    figManager = plt.get_current_fig_manager()
    figManager.window.showMaximized()
    img = cv2.imread(name)

    laplacian = cv2.Laplacian(img,cv2.CV_64F,ksize=7)
    laplacian2 = cv2.Laplacian(img,cv2.CV_64F,ksize=5)
    # laplacian2 = filter_colors(laplacian2)

    sobelx = cv2.Sobel(img,cv2.CV_64F,1,0,ksize=5)
    sobely = cv2.Sobel(img,cv2.CV_64F,0,1,ksize=5)

    plt.subplot(2,3,1),plt.imshow(img)
    plt.title(name), plt.xticks([]), plt.yticks([])
    plt.subplot(2,3,2),plt.imshow(laplacian)
    plt.title('Laplacian'), plt.xticks([]), plt.yticks([])
    plt.subplot(2,3,4),plt.imshow(sobelx)
    plt.title('Sobel X'), plt.xticks([]), plt.yticks([])
    plt.subplot(2,3,5),plt.imshow(sobely)
    plt.title('Sobel Y'), plt.xticks([]), plt.yticks([])
    plt.subplot(2,3,3),plt.imshow(laplacian2)
    plt.title('Laplacian k10'), plt.xticks([]), plt.yticks([])
    # plt.subplot(2,3,6),plt.imshow(hog_image_rescaled,cmap = 'gray')
    # plt.title('Laplacia after filter'), plt.xticks([]), plt.yticks([])
    plt.show()
    cv2.imwrite("laplacianimg.jpg",laplacian)
