import numpy as np
import cv2

def draw_hand_rect(frame):
    rows,cols,_ = frame.shape
        
    hand_row_nw = np.array([6*rows/20,6*rows/20,6*rows/20, 10*rows/20,10*rows/20,10*rows/20, 14*rows/20,14*rows/20,14*rows/20])
    hand_col_nw = np.array([9*cols/20,10*cols/20,11*cols/20, 9*cols/20,10*cols/20,11*cols/20, 9*cols/20,10*cols/20,11*cols/20])
    hand_row_se = hand_row_nw + 10
    hand_col_se = hand_col_nw + 10
    
    size = hand_row_nw.size
#    print (size)
    for i in range(size):
        cv2.rectangle(frame,(int(hand_col_nw[i]),int(hand_row_nw[i])),(int(hand_col_se[i]),int(hand_row_se[i])),(0,255,0),1)
    black = np.zeros(frame.shape, dtype=frame.dtype)
    frame_final = np.vstack([black, frame])
    return frame_final

def flip(frame):
    flipped = cv2.flip(frame, 1)
    return flipped

cap = cv2.VideoCapture(0)

while(True):

    ret, frame = cap.read()
    
    frame2=flip(frame)
    cv2.imshow('framew',draw_hand_rect(frame))
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break
cap.release()
cv2.destroyAllWindows()
