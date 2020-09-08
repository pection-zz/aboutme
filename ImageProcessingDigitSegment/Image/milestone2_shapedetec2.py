import imutils
import cv2
def nothing(x):
    pass
def detect(c):
	shape = "unidentified"
	peri = cv2.arcLength(c, True)
	approx = cv2.approxPolyDP(c, 0.01*peri, True)
	if len(approx) == 2:
		shape = "line"
	elif len(approx) == 3:
		shape = "triangle"
	elif len(approx) == 4:
		(x, y, w, h) = cv2.boundingRect(approx)
		ar = w / float(h)
		shape = "square" if ar >= 0.95 and ar <= 1.05 else "rectangle"
	elif len(approx) == 5:
		shape = "pentagon"
	elif len(approx) == 6:
		shape = "polygon"
	else:
		shape = "circle"
	return shape
image = cv2.imread("allshapecolor.png")
ratio = image.shape[0] / float(image.shape[0])
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
blured = cv2.GaussianBlur(gray, (5, 5), 0)
thresh = cv2.threshold(blured, 0, 0, cv2.THRESH_BINARY)[1]
cv2.imshow('Original_img', image)
cv2.imshow('Blur_img', blured)
cv2.imshow('Cut_Thresh', thresh)
cv2.createTrackbar('threshold1','Cut_Thresh',0,500,nothing)
cv2.createTrackbar('threshold2','Cut_Thresh',0,500,nothing)
while(1):
	cv2.imshow('Original_img', image)
	cv2.imshow('Blur_img', blured)

	threshold1 = cv2.getTrackbarPos('threshold1', 'Cut_Thresh')
	threshold2 = cv2.getTrackbarPos('threshold2', 'Cut_Thresh')

	thresh = cv2.threshold(blured,threshold1,threshold2, cv2.THRESH_BINARY)[1]
	cv2.imshow('Cut_Thresh', thresh)
	k = cv2.waitKey(30)
	if k == ord("s"):
		break
	if k == ord("i"):
		thresh = cv2.bitwise_not(thresh)
		break
cnts = cv2.findContours(thresh.copy(), cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
cnts = cnts[0] if imutils.is_cv2() else cnts[1]
for c in cnts:
	M = cv2.moments(c)
	if M["m00"] != 0:
		cX = int((M["m10"] / M["m00"]) * ratio)
		cY = int((M["m01"] / M["m00"]) * ratio)
	else:
		cX, cY = 0,0
	shape = detect(c)
	c = c.astype("float")
	c *= ratio
	c = c.astype("int")
	cv2.drawContours(image, [c], -1, (0, 255, 0), 2)
	cv2.putText(image, shape, (cX, cY), cv2.FONT_HERSHEY_SIMPLEX,
		0.5, (255, 255, 255), 2)
	cv2.imshow("Image", image)
cv2.waitKey(0)
