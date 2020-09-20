import cv2
img = cv2.imread('C:\Code_python\Image\Picture\Tiger.jpg')

img1 = cv2.imread('C:\Code_python\Image\Picture\Human.jpg')
print (type(img))
print (img.size)
print (img1.size)
print (img.shape)
print (img1.shape)