import cv2
import numpy as np
import time


img1 = cv2.imread('C:\Code_python\Image\Picture\Tiger.jpg')
img2 = cv2.imread('C:\Code_python\Image\Picture\Human.jpg')

imageWidth1 = img1.shape[1] #Get image width
imageHeight1 = img1.shape[0] #Get image height

imageWidth2 = img2.shape[1] #Get image width
imageHeight2 = img2.shape[0] #Get image height

xPos, yPos,xReal,yReal =450, -301, 0, 0
print (imageHeight2)
print (imageWidth1)
print (imageHeight2)
print (imageWidth2)
print (img1[15,15,0])
print (img2[yReal,xReal,0])
# x = int(img1[15,15,0])
# y =  int(img2[15,15,0])
mike = cv2.bitwise_xor(img1,img1)
# data = float(mike)

print (mike)
# print (int(mike[0][0]))

# print ( cv2.add(np.uint8([250]),np.uint8([10])))
# while xReal < imageWidth2: #Loop through rows
#     while yReal < imageHeight2: #Loop through collumns
#         Pos1=cv2.bitwise_xor(int(img1[yPos,xPos,0]),int(img2[yReal,xReal,0]))
#         Pos2=cv2.bitwise_xor(int(img1[yPos,xPos,1]),int(img2[yReal,xReal,1]))
#         Pos3=cv2.bitwise_xor(int(img1[yPos,xPos,2]),int(img2[yReal,xReal,2]))
#         # print (Pos1)
#         if(np.isnan(Pos1[0][0]) or np.isinf(Pos1[0][0])):
#             Pos1[0][0] = 0
#         if(np.isnan(Pos2[0][0]) or np.isinf(Pos2[0][0])):
#             Pos2[0][0] = 0
#         if(np.isnan(Pos3[0][0]) or np.isinf(Pos3[0][0])):
#             Pos3[0][0] = 0
#         img1.itemset((yPos, xPos, 0),int(Pos1[0][0]) ) #Set B to 255
#         img1.itemset((yPos, xPos, 1),int(Pos2[0][0]) )
#         img1.itemset((yPos, xPos, 2),int(Pos3[0][0]) )
#         yPos = yPos + 1 #Increment Y position by 1
#         yReal= yReal+1
#         # print (yReal)
#     yPos = 0
#     yReal =0
#     xPos = xPos + 1 #Increment X position by 1
#     xReal = xReal +1

# cv2.imwrite("result1.jpg", img1) #Write image to file