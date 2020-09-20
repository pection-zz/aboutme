import cv2# Load two images
img1 = cv2.imread('C:\Code_python\Image\Picture\Tiger.jpg')
img2 = cv2.imread('C:\Code_python\Image\Picture\Human.jpg')
rows,cols,channels = img2.shape
x =60
y =250
roi = img1[x:rows+x, y:cols+y ]
img2gray = cv2.cvtColor(img2,cv2.COLOR_BGR2GRAY)
ret, mask = cv2.threshold(img2gray, 10, 255, cv2.THRESH_BINARY)
img2_fg = cv2.bitwise_and(img2,img2,mask = mask)
print (img2_fg)
img1[x:rows+x,y:cols+y ] = img2_fg

cv2.imshow('res',img1)
cv2.waitKey(0)
cv2.destroyAllWindows()