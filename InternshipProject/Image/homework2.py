import cv2
img = cv2.imread('img.jpg')

gray_image = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
cv2.imwrite('img2.jpg',gray_image)