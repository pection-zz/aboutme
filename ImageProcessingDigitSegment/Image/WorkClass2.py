import cv2
cap = cv2.VideoCapture(1)
cap.set(cv2.CAP_PROP_FRAME_WIDTH,640)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT,480)
while(True):
    k = cv2.waitKey(1)
    ret, frame = cap.read()
    gray_image = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    cv2.imshow('frame',frame)
    cv2.imshow('gray',gray_image)
    if k == ord('s'):
        cv2.imwrite('MIKE1.jpg',frame)
        break
    if k == ord('q'):
        break

cap.release()
cv2.destroyAllWindows() 