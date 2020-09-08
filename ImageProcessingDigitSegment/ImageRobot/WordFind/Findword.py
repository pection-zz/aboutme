from imgtran.transform import four_point_transform
from skimage.filters import threshold_local
import numpy as np
import argparse
import cv2
import imutils

round =0
point_x,point_y=[[],[],[],[],[],[],[],[],[],[]],[[],[],[],[],[],[],[],[],[],[]]
def ReadImage():
    ap = argparse.ArgumentParser()
    ap.add_argument("-i", "--image", required = True)
    args = vars(ap.parse_args())
    return cv2.imread(args["image"])
def resizeImg(img,height_img):
    ratio_img = img.shape[0] / height_img
    Original_image = img.copy()
    image_resize= imutils.resize(img, height = height_img)
    return Original_image,image_resize,ratio_img
def CutThreshold_Blur_Canny(img,threshold1,threshold2,threshold3,threshold4,threshold5,threshold6,blur1,blur2,canny1,canny2):
    threshold_lower = np.array([threshold1,threshold2,threshold3])
    threshold_upper = np.array([threshold4,threshold5,threshold6])
    image_thresh = cv2.inRange(img,threshold_lower,threshold_upper)
    gray = cv2.bitwise_and(image, image, mask=image_thresh)
    gray = cv2.GaussianBlur(gray, (blur1, blur2), 0)
    img_canny = cv2.Canny(gray, canny1,canny2)
    return img_canny

ap = argparse.ArgumentParser()
ap.add_argument("-i", "--image", required = True)
args = vars(ap.parse_args())
img = cv2.imread(args["image"])
Original,image,ratio= resizeImg(img,500)
edged= CutThreshold_Blur_Canny(image,150,99,120,255,255,255,5,5,0,285)
cnts = cv2.findContours(edged.copy(), cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
cnts = cnts[0] if imutils.is_cv2() else cnts[1]
for c in cnts:
    peri = cv2.arcLength(c, True)
    approx = cv2.approxPolyDP(c, 0.01* peri, True)
    area = cv2.contourArea(c)
    if len(approx) ==4 and area >50:

        screenCnt = approx
        for i in range(0,len(approx)):
            if (round != 0 ):
                if(abs(approx[0][0][0] - point_x[round-1][0]) >5  or  abs(approx[0][0][1] -point_y[round-1][0]) > 5 ):
                    point_x[round].append(approx[i][0][0])
                    point_y[round].append(approx[i][0][1])
                    state = True
                else :
                    state = False
            else :
                point_x[round].append(approx[i][0][0])
                point_y[round].append(approx[i][0][1])
                state = True                
        if(state == True ):
            cv2.drawContours(image, [screenCnt], -1, (0, 255, 0), 2)
            cv2.imshow("Outline", image)
            warped = four_point_transform(Original, screenCnt.reshape(4, 2) * ratio)
            warped = cv2.cvtColor(warped, cv2.COLOR_BGR2GRAY)
            T = threshold_local(warped, 11, offset = 10, method = "gaussian")
            warped = (warped > T).astype("uint8") * 255
            warped = imutils.resize(warped, height = 650)
            cv2.imshow("TEXT", warped)
            round =round +1
            cv2.imwrite("C:\Code_python\ImageRobot\WordFind\images\img"+str(round)+".jpg",warped)
            print ("X  = ",point_x)
            print ("Y  = ",point_y)
            cv2.waitKey(0)

cv2.waitKey(0)    