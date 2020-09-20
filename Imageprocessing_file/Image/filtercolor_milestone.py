import cv2
import numpy as np 
import imutils

def filter_colors(image,datacolorthresh):
	lower_thresh = np.array([datacolorthresh[0],datacolorthresh[1],datacolorthresh[2]])
	upper_thresh = np.array([datacolorthresh[3],datacolorthresh[4],datacolorthresh[5]])
	color_mask = cv2.inRange(image, lower_thresh, upper_thresh)
	color_image = cv2.bitwise_and(image, image, mask=color_mask)
	return color_image

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
def detec_color(image,color):
    i = 0
    ratio = image.shape[0] / float(image.shape[0])
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    blured = cv2.GaussianBlur(gray, (5, 5), 0)
    thresh = cv2.threshold(blured,0,255, cv2.THRESH_BINARY)[1]
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
        # data = [c]
        cv2.drawContours(image, [c], -1, (0, 255, 0), 2)
        cv2.putText(image, shape+ color, (cX, cY), cv2.FONT_HERSHEY_SIMPLEX,
            0.5, (255, 255, 255), 2)
        i += 1
    return image
# 197 166 210
# 212 200 255 pink

# 66 115 34
# 81 190 86 green

# 21 24 144
# 255 78 255 red

# 0 0 0
# 0 255 255 yellow

datacolor_pink=[197,166,210,212,200,255]
datacolor_green=[66,115,34,81,190,86]
datacolor_red=[1,0,110,73,78,255]
datacolor_yellow=[0,0,0,0,255,255]

img = cv2.imread("img.jpg")
img_pink = filter_colors(img,datacolor_pink)
img_green = filter_colors(img,datacolor_green)
img_red =filter_colors(img,datacolor_red)
img_yellow =filter_colors(img,datacolor_yellow)

# img_pink_shape,datapink= detec_color(img_pink,"_pink")
# img_green_shape,datagreen = detec_color(img_green,"_green")
img_red_shape = detec_color(img_red,"_red")
# img_yellow_shape,datayellow = detec_color(img_yellow,"_yellow")
# allshape = img_pink_shape + img_green_shape + img_red_shape + img_yellow_shape

# file = open("datafile.txt","w")
# file.write(str(datapink[0]))
# file.close()
# print (datapink[0])

cv2.imshow("Final",img_red_shape)
cv2.waitKey(0)

