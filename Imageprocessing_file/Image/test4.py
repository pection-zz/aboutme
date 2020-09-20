import cv2
import numpy as np

img1 = cv2.imread('C:\Code_python\Image\Picture\Tiger.jpg')
img2 = cv2.imread('C:\Code_python\Image\Picture\Human.jpg')

imageWidth1 = img1.shape[1] #Get image width
imageHeight1 = img1.shape[0] #Get image height

imageWidth2 = img2.shape[1] #Get image width
imageHeight2 = img2.shape[0] #Get image height


xPos, yPos = 150, 150
yPosbefore=150
while xPos < imageWidth2: #Loop through rows
    while yPos < imageHeight2: #Loop through collumns

        img1.itemset((yPos, xPos, 0), 255) #Set B to 255
        img1.itemset((yPos, xPos, 1), 255) #Set G to 255
        img1.itemset((yPos, xPos, 2), 255) #Set R to 255
        
        yPos = yPos + 1 #Increment Y position by 1

    yPos =yPosbefore
    xPos = xPos + 1 #Increment X position by 1

cv2.imwrite("image1.jpg", img1) #Write image to file