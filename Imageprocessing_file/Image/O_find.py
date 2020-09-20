import numpy as np
import cv2

kernel_301 = np.ones((1,30),np.uint8)
kernel_401 = np.ones((40,1),np.uint8)
kernel_551 = np.ones((5,5),np.uint8)
kernel_201 = np.ones((3,20),np.uint8)

img = cv2.imread('mor.png',0)
def dilationmorp_return(img,kernel_40,kernel_20,img2):
    opening_40 = cv2.morphologyEx(img2, cv2.MORPH_OPEN, kernel_40)
    dilation = cv2.morphologyEx(opening_40, cv2.MORPH_DILATE, kernel_20)
    for i in range (100):
        opening_40 = cv2.morphologyEx(dilation, cv2.MORPH_OPEN, kernel_20)
        dilation=cv2.bitwise_and(dilation,img)    
    dilation_morp = cv2.bitwise_xor(dilation,img2)
    return dilation_morp


pic1=dilationmorp_return(img,kernel_401,kernel_201,img)
pic2=dilationmorp_return(img,kernel_301,kernel_201,pic1)

x , y = img.shape[:2]
mask  = np.zeros((x+2,y+2),np.uint8)
cv2.floodFill(pic2,mask,(0,0),255);
img_flodfill = cv2.bitwise_not(pic2)

opening_40 = cv2.morphologyEx(img_flodfill, cv2.MORPH_OPEN, kernel_201)
dilation5 = cv2.morphologyEx(opening_40, cv2.MORPH_DILATE, kernel_551)

for i in range(100):
    dilation5 = cv2.morphologyEx(dilation5, cv2.MORPH_DILATE, kernel_551)
    dilation5=cv2.bitwise_and(dilation5,img) 



cv2.imshow('pic1',pic1)
# cv2.imwrite('Result.jpg',dilation5)
cv2.imshow('pic2',pic2)

cv2.imshow('imgflood',pic2)
cv2.imshow('opening',opening_40)
# cv2.imshow('floodfill',img_flodfill)
cv2.waitKey(0)