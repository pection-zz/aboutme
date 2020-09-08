from skimage.filters import threshold_local
import numpy as np
import argparse
import cv2
import imutils
def filter_colors(image):
	white_threshold = 110#130
	lower_white = np.array([white_threshold, white_threshold, white_threshold])
	upper_white = np.array([255, 255, 255])
	white_mask = cv2.inRange(image, lower_white, upper_white)
	white_image = cv2.bitwise_and(image, image, mask=white_mask)
	return white_image
def nothing(x):
    pass

img = cv2.imread("./../../trackHand/power_left/2.jpg")
ratio = img.shape[0] / 500.0
orig = img.copy()
img = imutils.resize(img, height = 500)
# img = cv2.imread("test.jpeg")

# img_canny =cv2.Canny(img,100,200)
white_threshold = 110#130
lower_white = np.array([white_threshold, white_threshold, white_threshold])
upper_white = np.array([255, 255, 255])
white_mask = cv2.inRange(img, lower_white, upper_white)
white_image = cv2.bitwise_and(img, img, mask=white_mask)

img_filter = white_image
cv2.imshow("Original",img)
cv2.imshow("imgfilter",img_filter)
cv2.createTrackbar('threshold1','imgfilter',0,255,nothing)
cv2.createTrackbar('threshold2','imgfilter',0,255,nothing)
cv2.createTrackbar('threshold3','imgfilter',0,255,nothing)
cv2.createTrackbar('threshold4','imgfilter',0,255,nothing)
cv2.createTrackbar('threshold5','imgfilter',0,255,nothing)
cv2.createTrackbar('threshold6','imgfilter',0,255,nothing)
while(1):
    cv2.imshow("Original",img)
    cv2.imshow("imgfilter",img_filter)

    white_threshold = cv2.getTrackbarPos('threshold1', 'imgfilter')
    thres2 =  cv2.getTrackbarPos('threshold2', 'imgfilter')
    thres3 =  cv2.getTrackbarPos('threshold3', 'imgfilter')
    thres4 =  cv2.getTrackbarPos('threshold4', 'imgfilter')
    thres5 =  cv2.getTrackbarPos('threshold5', 'imgfilter')
    thres6 =  cv2.getTrackbarPos('threshold6', 'imgfilter')

    lower_white = np.array([white_threshold,thres2,thres3])
    upper_white = np.array([thres4,thres5,thres6])

    white_mask = cv2.inRange(img, lower_white, upper_white)
    white_image = cv2.bitwise_and(img, img, mask=white_mask)
    img_filter = white_image
    k = cv2.waitKey(30)
    if k == 27:
        break
