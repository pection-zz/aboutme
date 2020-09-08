import cv2

e1 = cv2.getTickCount()
# your code here
for i in range(5,0,2):
    img1 = cv2.medianBlur(img1,i)
e2 = cv2.getTickCount()
t = (e2 - e1)/cv2.getTickFrequency()
print (t)