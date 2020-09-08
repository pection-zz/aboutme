
import cv2
import numpy as np
def filter_colors(image,datacolorthresh):
	lower_thresh = np.array([datacolorthresh[0],datacolorthresh[1],datacolorthresh[2]])
	upper_thresh = np.array([datacolorthresh[3],datacolorthresh[4],datacolorthresh[5]])
	color_mask = cv2.inRange(image, lower_thresh, upper_thresh)
	color_image = cv2.bitwise_and(image, image, mask=color_mask)
	return color_image

def nothing(x):
    pass

from skimage.filters import threshold_local

import argparse
import imutils

# construct the argument parser and parse the arguments
ap = argparse.ArgumentParser()
ap.add_argument("-i", "--image", required = True,
	help = "Path to the image to be scanned")
args = vars(ap.parse_args())

image = cv2.imread(args["image"])
ratio = image.shape[0] / 500.0
orig = image.copy()
image = imutils.resize(image, height = 500)
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
gray = cv2.GaussianBlur(gray, (5, 5), 0)
img_canny = cv2.Canny(gray, 0, 0)

cv2.imshow('image', image)
cv2.imshow('canny_edge', img_canny)
cv2.createTrackbar('threshold1','canny_edge',0,500,nothing)
cv2.createTrackbar('threshold2','canny_edge',0,500,nothing)
while(1):
    cv2.imshow('image', image)
    cv2.imshow('canny_edge', img_canny)
     
    threshold1 = cv2.getTrackbarPos('threshold1', 'canny_edge')
    threshold2 = cv2.getTrackbarPos('threshold2', 'canny_edge')
 
    img_canny = cv2.Canny(gray,threshold1,threshold2)
     
    k = cv2.waitKey(37)
    if k == 27:
        break