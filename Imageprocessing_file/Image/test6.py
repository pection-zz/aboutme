import numpy as np
import cv2

# mouse callback function
def draw_circle(event,x,y,flags,param):
    global human,tiger,logo
    positionX = tiger.shape[1]
    positionY = tiger.shape[0]
    col = human.shape[1]
    row = human.shape[0]


    if event == cv2.EVENT_LBUTTONDOWN: #  click.
        y -= row/2                  #
        x -= col/2                  # center.

        if y+row > positionY :      ## error.
            #row = positionY-y
            y = positionY-row
        elif y < 0:
            y = 0
        if x + col > positionX:
            #col = positionX - x
            x = positionX - col
        elif x < 0:
            x = 0                   ## error.
        # print (x,y) # position x,y

        # print (positionX,positionY)
        logo = tiger[y:y + row, x:x + col] # show tiger picture before add human picture.
        k = cv2.waitKey(1000) & 0xFF # ESC Exit.
        if k == ord('1'):                               # function
            logo = np.add(logo,human[0:row,0:col])
        if k == ord('2'):
            logo = np.subtract(logo,human[0:row,0:col])
        if k == ord('3'):
            logo = np.multiply(logo,human[0:row,0:col])
        if k == ord('4'):
            logo = np.divide(logo,human[0:row,0:col])
        if k == ord('5'):
            logo = np.bitwise_and(logo,human[0:row,0:col])
        if k == ord('6'):
            logo = np.bitwise_or(logo,human[0:row,0:col])
        if k == ord('7'):
            logo = np.bitwise_xor(logo,human[0:row,0:col]) # function.
        tiger[y:y+row, x:x+col] = logo # show tiger picture after add human picture.

# Create a black image, a window and bind the function to window
tiger = cv2.imread('C:\Code_python\Image\Picture\Tiger.jpg')
human = cv2.imread('C:\Code_python\Image\Picture\Human.jpg')


while(1):
    cv2.setMouseCallback('image', draw_circle)
    cv2.imshow('image',tiger)
    #cv2.imshow('eiei',img2)

    k = cv2.waitKey(20) & 0xFF
    if k == 27:
        break
cv2.destroyAllWindows()
