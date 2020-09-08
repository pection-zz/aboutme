import cv2
from matplotlib import pyplot as plt
def nothing(x):
    pass

image = cv2.imread("img.jpg")
thresh = cv2.threshold(blured, 0, 0, cv2.THRESH_BINARY)[1]


cv2.imshow('Original_img', image)
cv2.imshow('Cut_Thresh', thresh)
cv2.createTrackbar('threshold1','Cut_Thresh',0,500,nothing)
cv2.createTrackbar('threshold2','Cut_Thresh',0,500,nothing)
while(1):
    cv2.imshow('Original_img', image)

    threshold1 = cv2.getTrackbarPos('threshold1', 'Cut_Thresh')
    threshold2 = cv2.getTrackbarPos('threshold2', 'Cut_Thresh')
 
    thresh = cv2.threshold(thresh,threshold1,threshold2, cv2.THRESH_BINARY)[1]
    cv2.imshow('Cut_Thresh', thresh)
    k = cv2.waitKey(30)
    if k == 27:
        break