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
    approx = cv2.approxPolyDP(c, 0.3*peri, True)
    point_x=[]
    point_y=[]

    if len(approx) == 2:
        shape = "line"
    elif len(approx) == 3:
        shape = "triangle"
        for i in range(0,len(approx)):
            point_x.append(approx[i][0][0])
            point_y.append(approx[i][0][1])
    elif len(approx) == 4:
        (x, y, w, h) = cv2.boundingRect(approx)
        ar = w / float(h)
        for i in range(0,len(approx)):
            point_x.append(approx[i][0][0])
            point_y.append(approx[i][0][1])
        shape = "square" if ar >= 0.95 and ar <= 1.05 else "rectangle"
    elif len(approx) == 5:
        shape = "pentagon"
        for i in range(0,len(approx)):
            point_x.append(approx[i][0][0])
            point_y.append(approx[i][0][1])
    elif len(approx) == 6:
        shape = "polygon"
        for i in range(0,len(approx)):
            point_x.append(approx[i][0][0])
            point_y.append(approx[i][0][1])
    elif len(approx) == 7:
        shape = "polygon"+str(len(approx))
        for i in range(0,len(approx)):
            point_x.append(approx[i][0][0])
            point_y.append(approx[i][0][1])
    elif len(approx) == 8:
        shape = "polygon"+str(len(approx))
        for i in range(0,len(approx)):
            point_x.append(approx[i][0][0])
            point_y.append(approx[i][0][1])
    elif len(approx) == 9:
        shape = "polygon"+str(len(approx))
        for i in range(0,len(approx)):
            point_x.append(approx[i][0][0])
            point_y.append(approx[i][0][1])
    elif len(approx) == 10:
        shape = "polygon"+str(len(approx))
        for i in range(0,len(approx)):
            point_x.append(approx[i][0][0])
            point_y.append(approx[i][0][1])
    elif len(approx) == 11:
        shape = "polygon"+str(len(approx))
        for i in range(0,len(approx)):
            point_x.append(approx[i][0][0])
            point_y.append(approx[i][0][1])
    elif len(approx) == 12:
        shape = "polygon"+str(len(approx))
        for i in range(0,len(approx)):
            point_x.append(approx[i][0][0])
            point_y.append(approx[i][0][1])
    elif len(approx) == 13:
        shape = "polygon"+str(len(approx))
        for i in range(0,len(approx)):
            point_x.append(approx[i][0][0])
            point_y.append(approx[i][0][1])
    elif len(approx) == 14:
        shape = "polygon"+str(len(approx))
        for i in range(0,len(approx)):
            point_x.append(approx[i][0][0])
            point_y.append(approx[i][0][1])
    elif len(approx) == 15:
        shape = "polygon"+str(len(approx))
        for i in range(0,len(approx)):
            point_x.append(approx[i][0][0])
            point_y.append(approx[i][0][1])
    elif len(approx) == 16:
        shape = "polygon"+str(len(approx))
        for i in range(0,len(approx)):
            point_x.append(approx[i][0][0])
            point_y.append(approx[i][0][1])    
    else:
        shape = "circle"
    return shape,point_x,point_y
def appendfunc(valuex,valuey,x,y):
    for i in range(0,len(x)):
        valuex.append(x[i])
        valuey.append(y[i])
    return valuex,valuey
def detec_color(image,color):
    i = 0
    ratio = image.shape[0] / float(image.shape[0])
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    blured = cv2.GaussianBlur(gray, (5, 5), 0)
    thresh = cv2.threshold(blured,0,255, cv2.THRESH_BINARY)[1]
    cnts = cv2.findContours(thresh.copy(), cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
    # print (cnts)
    cnts = cnts[0] if imutils.is_cv2() else cnts[1]
    for c in cnts:
        # if c >50:
        area = cv2.contourArea(c)
        # print (area)
        # print ("")
        # if area > 10000:
        M = cv2.moments(c)
        rect = cv2.minAreaRect(c)
        if M["m00"] != 0:
            cX = int((M["m10"] / M["m00"]) * ratio)
            cY = int((M["m01"] / M["m00"]) * ratio)
        else:
            cX, cY = 0,0
        shape,point_x,point_y= detect(c)
        appendfunc(x_point,y_point,point_x,point_y)
        c = c.astype("float")
        c *= ratio
        c = c.astype("int")
        cv2.drawContours(image, [c], -1, (0, 255, 0), 2)
        cv2.putText(image, shape+ color, (cX, cY), cv2.FONT_HERSHEY_SIMPLEX,
            0.5, (255, 255, 255), 2)
        i += 1
    return image
x_point=[]
y_point=[]
datacolor_pink=[197,166,210,212,200,255]
datacolor_green=[0,0,0,238,255,221]
datacolor_red=[100,11,0,152,199,255]
datacolor_yellow=[0,0,0,0,255,255]
datacolor_blue=[178,102,85,255,167,210]

kernel = np.ones((5,5),np.uint8)
img = cv2.imread("img3.jpg")
# img = cv2.morphologyEx(img, cv2.MORPH_DILATE, kernel)

allshape = detec_color(img,"point")

cv2.imshow("Final2",img)
cv2.imshow("Final",allshape)
cv2.waitKey(0)

