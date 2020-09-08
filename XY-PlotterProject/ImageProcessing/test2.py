import cv2
import numpy as np



img1 = cv2.imread('C:\Code_python\Image\Picture\Tiger.jpg')
img2 = cv2.imread('C:\Code_python\Image\Picture\Human.jpg')

imageWidth1 = img1.shape[1] #Get image width
imageHeight1 = img1.shape[0] #Get image height

imageWidth2 = img2.shape[1] #Get image width
imageHeight2 = img2.shape[0] #Get image height
xPos, yPos,xReal,yReal = 10, 10, 0, 0
print (imageHeight2)
print (imageWidth2)
while xReal < imageWidth2: #Loop through rows
    while yReal < imageHeight2: #Loop through collumns

        img1.itemset((yPos, xPos, 0), cv2.add(img1[yPos,xPos,0],img2[yReal,xReal,0])) #Set B to 255
        img1.itemset((yPos, xPos, 1), cv2.add(img1[yPos,xPos,0],img2[yReal,xReal,1])) #Set G to 255
        img1.itemset((yPos, xPos, 2), cv2.add(img1[yPos,xPos,0],img2[yReal,xReal,2]))
        yPos = yPos + 1 #Increment Y position by 1
        yReal= yReal+1
    yPos = 0
    yReal =0
    xPos = xPos + 1 #Increment X position by 1
    xReal = xReal +1
cv2.imwrite("result1.jpg", image) #Write image to file