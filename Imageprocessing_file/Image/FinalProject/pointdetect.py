import imutils
import cv2
import numpy as np



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


x_point = []
y_point=[]
mix_point=[]
img = cv2.imread('img7.jpg',0)
img_blur = cv2.blur(img, (7,7))

img_canny = cv2.Canny(img_blur, 10,25)

kernel = cv2.getStructuringElement(cv2.MORPH_RECT, (7, 7))
closed = cv2.morphologyEx(img_canny, cv2.MORPH_CLOSE, kernel)

point_img= detec_point(closed)

# for i in range(0,len(x_point)):
#     mix_point.append([])
#     mix_point[i].append(x_point[i])
#     mix_point[i].append(y_point[i])
print (x_point)
print (y_point)
# print (mix_point)
cv2.imshow('detected circles',img_canny)
cv2.imshow('ORi',closed)
cv2.waitKey(0)
cv2.destroyAllWindows()
# cv2.imshow("OR",img)
# cv2.imshow("Image",closed)
# cv2.waitKey(0)