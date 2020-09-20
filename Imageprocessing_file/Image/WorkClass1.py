import numpy as np
import cv2

cap = cv2.VideoCapture(0)

while(True):
    k = cv2.waitKey(1)
    ret, frame = cap.read()

    cv2.imshow('frame',frame)
    if k == ord('s'):
        cv2.imwrite('MIKE1.jpg',frame)
        break
    if k == ord('q'):
        break

cap.release()
cv2.destroyAllWindows() 