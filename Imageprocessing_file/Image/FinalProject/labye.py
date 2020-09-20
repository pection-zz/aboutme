import numpy as np
import cv2
import copy

contour_value = []
pts = []
re_arrange = []
Mike_X_Y_Value = []
img = cv2.imread("gofill.png")
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
blured = cv2.GaussianBlur(gray, (5, 5), 0)
thresh = cv2.threshold(blured,0,255, cv2.THRESH_BINARY)[1]
diagmask = cv2.imread("noise_2.png", 0)
cropped_image= thresh.copy()
kernel = np.ones((2, 2), np.uint8)
h, w = cropped_image.shape[:2]
diagmask = diagmask[0:h,0:w]
black_img = np.zeros((h, w), np.uint8)
black_img2 = copy.copy(black_img)
cntss = cv2.findContours(thresh.copy(), cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
for cnt in cntss[1]:
    moment = cv2.moments(cnt)
    if 500 < moment['m00'] < 40000:
        contour_value.append(cnt)
for valid in contour_value:
    moment = cv2.moments(cnt)
    cv2.drawContours(edge_img, [cnt], -1, 255, -1)
    approx = cv2.approxPolyDP(cnt, 0.01 * cv2.arcLength(cnt, True), True)
    cv2.drawContours(black_img, [valid], 0, 255, -1)
    if 0:
        pts.append(valid)
    else:
        pts.append(approx)
filled = cv2.bitwise_and(diagmask,thresh)
_fill, contoursfill, hierarchyfill = cv2.findContours(filled, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
for cntfill in contoursfill:
    pts.append(cntfill)
for i in pts:
    cv2.drawContours(black_img2, [i], 0, 255, 1)
counter = 0
for i in pts:
    re_arrange.append([])
    for j in i:
        re_arrange[counter].append((int((j[0][0]) * 0.077668 * 100),
                                    int((j[0][1]) * 0.077668 * 100)))
    counter += 1
for i in re_arrange:
    Mike_X_Y_Value.append([])
    for c in range(len(i)):
        Mike_X_Y_Value[re_arrange.index(i)].append([])
        Mike_X_Y_Value[re_arrange.index(i)][c].append(i[c])
        if c == len(i) - 1:
            Mike_X_Y_Value[re_arrange.index(i)][c].append(i[0])
        else:
            Mike_X_Y_Value[re_arrange.index(i)][c].append(i[c + 1])
a =0 
for i in Mike_X_Y_Value:
    if (a !=0):
        for j in i:
            print(j)  
        if Mike_X_Y_Value.index(i) == len(Mike_X_Y_Value) - 1:
            print("Line_FINISH= "+str(a))
        else:
            print("Line_Start = "+str(a))
    a = a +1
cv2.imshow("Edge",  thresh)
cv2.imshow("Final", black_img2)
cv2.waitKey(0)
