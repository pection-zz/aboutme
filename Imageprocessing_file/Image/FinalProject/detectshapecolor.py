import numpy as np
import cv2
import imutils
def detectpoint(c):
    shape = "unidentified"
    peri = cv2.arcLength(c, True)
    approx = cv2.approxPolyDP(c, 0.01*peri, True)
    point_x=[]
    point_y=[]

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
    elif len(approx) == 7:
        shape = "polygon"+str(len(approx))
    elif len(approx) == 8:
        shape = "polygon"+str(len(approx))
    elif len(approx) == 9:
        shape = "polygon"+str(len(approx))
    elif len(approx) == 10:
        shape = "polygon"+str(len(approx))
    elif len(approx) == 11:
        shape = "polygon"+str(len(approx))
    elif len(approx) == 12:
        shape = "polygon"+str(len(approx))
    elif len(approx) == 13:
        shape = "polygon"+str(len(approx))
    elif len(approx) == 14:
        shape = "polygon"+str(len(approx))
    elif len(approx) == 15:
        shape = "polygon"+str(len(approx))
    elif len(approx) == 16:
        shape = "polygon"+str(len(approx))
    else:
        shape = "circle"
    return shape
def appendfunc(valuex,valuey,x,y):
    for i in range(0,len(x)):
        valuex.append(x[i])
        valuey.append(y[i])
    return valuex,valuey
def detec_point(image):
    i = 0
    ratio = image.shape[0] / float(image.shape[0])
    thresh = cv2.threshold(image,0,255, cv2.THRESH_BINARY)[1]
    cnts = cv2.findContours(thresh.copy(), cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
    # print (cnts)
    cnts = cnts[0] if imutils.is_cv2() else cnts[1]
    for c in cnts:
        # if c >50:
        area = cv2.contourArea(c)
        # print (area)
        # print ("")
        if area <50 :
            M = cv2.moments(c)
            rect = cv2.minAreaRect(c)
            if M["m00"] != 0:
                cX = int((M["m10"] / M["m00"]) * ratio)
                cY = int((M["m01"] / M["m00"]) * ratio)
            else:
                cX, cY = 0,0
            shape= detectpoint(c)

            if shape != "line":

                c = c.astype("float")
                c *= ratio
                c = c.astype("int")
                cv2.drawContours(image, [c], -1, (0, 255, 0), 2)
                x_point.append(cX)
                y_point.append(cY)
                cv2.putText(image, shape, (cX, cY), cv2.FONT_HERSHEY_SIMPLEX,
                    0.5, (255, 255, 255), 2)
                i += 1
    return image

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
        shape = "circle"
        for i in range(0,len(approx)):
            point_x.append(approx[i][0][0])
            point_y.append(approx[i][0][1])
    elif len(approx) == 14:
        shape = "circle"
        for i in range(0,len(approx)):
            point_x.append(approx[i][0][0])
            point_y.append(approx[i][0][1])
    elif len(approx) == 15:
        shape = "circle"
        for i in range(0,len(approx)):
            point_x.append(approx[i][0][0])
            point_y.append(approx[i][0][1])
    elif len(approx) == 16:
        shape = "circle"
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
        # if area > 5000:
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
x_point = []
y_point=[]
datacolor_red=[150,154,153,255,255,255]
datacolor_blue=[231,112,0,255,184,255]
datacolor_green=[118,188,36,215,255,162]

datacolor_shape=[0,3,0,255,232,255]
kernel = np.ones((5,5),np.uint8)

cap = cv2.VideoCapture(1)

cap.set(640,480)
while(cap.isOpened()):
    ret, frame = cap.read()
#   cv2.line(frame,(0,40),(640,40),(255,0,0),1)
#     cv2.line(frame,(0,465),(640,465),(255,0,0),1)
#     cv2.line(frame,(50,0),(50,480),(255,0,0),1)
#     cv2.line(frame,(580,0),(580,480),(255,0,0),1)
    # cv2.imshow("Final",img_red_shape)
    # cv2.rectangle(frame,(120,150),(430,450),(250,250,250))
    # huhu = frame[(460,50),(465,40)]
    cv2.imshow("Fina2l",frame)
    # cv2.imshow("Fi22na2l",huhu)
    # cv2.imshow("thresh",img_red)
    k = cv2.waitKey(30)
    if  k == ord('s'):
        pass
    if  k ==27 :
        crop = frame[150:450,120:430]
        cv2.imwrite("img2.jpg",frame)
        break
cap.release()
cv2.destroyAllWindows()
x_point = []
y_point=[]

# img = cv2.imread('img2.jpg',0)
# img_blur = cv2.blur(img, (7,7))

# img_canny = cv2.Canny(img_blur, 59,95)

# kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (7, 7))
# closed = cv2.morphologyEx(img_canny, cv2.MORPH_CLOSE, kernel)

# point_img= detec_point(closed)

# print (x_point)
# print (y_point)
# cv2.imshow('detected circles',img_canny)
# cv2.imshow('ORi',closed)
# cv2.waitKey(0)
# cv2.destroyAllWindows()


img = cv2.imread("test2.jpg")
ratio = img.shape[0] / 500.0
orig = img.copy()
img = imutils.resize(img, height = 500)
img = cv2.blur(img, (7,7))
dilate = cv2.morphologyEx(img, cv2.MORPH_DILATE, kernel)

img_red =filter_colors(img,datacolor_red)
# cv2.imwrite("gofill.png",img_red)
img_red_shape = detec_color(img_red,"_red")

img_green =filter_colors(dilate,datacolor_green)
img_green_shape = detec_color(img_green,"_green")

img_blue =filter_colors(dilate,datacolor_blue)
img_blue_shape = detec_color(img_blue,"_blue")

img_green =filter_colors(dilate,datacolor_green)
img_green_shape = detec_color(img_green,"_green")
# cv2.bitwise_and()

allshape =  img_green_shape +img_blue_shape + img_red_shape

cv2.imshow("image",allshape)
# cv2.imshow("image",img_green_shape)
cv2.waitKey(0)


print (x_point)
print (y_point)