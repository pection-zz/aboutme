
import cv2
import numpy as np 

input_value = 0
state = 0
x_mouse = 0
y_mouse = 0
img = cv2.imread('C:\Code_python\Image\Picture\Tiger.jpg')
img2 = cv2.imread('C:\Code_python\Image\Picture\Human.jpg')
img2_x_position = img2.shape[0]
img2_y_position = img2.shape[1]
img1_x_position = img.shape[0]
img1_y_position = img.shape[1]
cv2.namedWindow('SHOW_IMAGE')

def mouseclick(event,x,y,flags,param):  
    if event == cv2.EVENT_LBUTTONDOWN:
        global x_mouse , y_mouse , img2_x_position , img2_y_position , img , img2 ,image , input_value ,state , new_value_img
        x_mouse,y_mouse  = x,y
        if input_value == ord("1"):
            if img1_x_position - y_mouse < img2_x_position and img1_y_position - x_mouse < img2_y_position :
                new_value_img = np.add(img[img1_x_position - img2_x_position : img1_x_position ,img1_y_position - img2_y_position : img1_y_position],img2)
                img[img1_x_position - img2_x_position : img1_x_position ,img1_y_position - img2_y_position : img1_y_position] = new_value_img
                cv2.imshow('SHOW_IMAGE',img)
            if img1_x_position - y_mouse < img2_x_position and img1_y_position - x_mouse >= img2_y_position :
                new_value_img = np.add(img[img1_x_position - img2_x_position : img1_x_position ,x_mouse:x_mouse + img2_y_position],img2)
                img[img1_x_position - img2_x_position : img1_x_position ,x_mouse:x_mouse + img2_y_position] = new_value_img
                cv2.imshow('SHOW_IMAGE',img)
            if img1_x_position - y_mouse >= img2_x_position and img1_y_position - x_mouse < img2_y_position :
                new_value_img = np.add(img[y_mouse:y_mouse + img2_x_position ,img1_y_position - img2_y_position : img1_y_position],img2)
                img[y_mouse:y_mouse + img2_x_position,img1_y_position - img2_y_position : img1_y_position] = new_value_img
                cv2.imshow('SHOW_IMAGE',img)
            else:
                new_value_img = np.add(img[y_mouse:y_mouse + img2_x_position,x_mouse:x_mouse + img2_y_position],img2)
                img[y_mouse:y_mouse + img2_x_position,x_mouse:x_mouse + img2_y_position] = new_value_img
                cv2.imshow('SHOW_IMAGE',img)
        if input_value== ord("2"):
            if img1_x_position - y_mouse < img2_x_position and img1_y_position - x_mouse < img2_y_position :
                new_value_img = np.subtract(img[img1_x_position - img2_x_position : img1_x_position ,img1_y_position - img2_y_position : img1_y_position],img2)
                img[img1_x_position - img2_x_position : img1_x_position ,img1_y_position - img2_y_position : img1_y_position] = new_value_img
                cv2.imshow('SHOW_IMAGE',img)
            if img1_x_position - y_mouse < img2_x_position and img1_y_position - x_mouse >= img2_y_position :
                new_value_img = np.subtract(img[img1_x_position - img2_x_position : img1_x_position ,x_mouse:x_mouse + img2_y_position],img2)
                img[img1_x_position - img2_x_position : img1_x_position ,x_mouse:x_mouse + img2_y_position] = new_value_img
                cv2.imshow('SHOW_IMAGE',img)
            if img1_x_position - y_mouse >= img2_x_position and img1_y_position - x_mouse < img2_y_position :
                new_value_img = np.subtract(img[y_mouse:y_mouse + img2_x_position ,img1_y_position - img2_y_position : img1_y_position],img2)
                img[y_mouse:y_mouse + img2_x_position,img1_y_position - img2_y_position : img1_y_position] = new_value_img
                cv2.imshow('SHOW_IMAGE',img)
            else:
                new_value_img = np.subtract(img[y_mouse:y_mouse + img2_x_position,x_mouse:x_mouse + img2_y_position],img2)
                img[y_mouse:y_mouse + img2_x_position,x_mouse:x_mouse + img2_y_position] = new_value_img
                cv2.imshow('SHOW_IMAGE',img)
        if input_value == ord("3"):
            if img1_x_position - y_mouse < img2_x_position and img1_y_position - x_mouse < img2_y_position :
                new_value_img = np.multiply(img[img1_x_position - img2_x_position : img1_x_position ,img1_y_position - img2_y_position : img1_y_position],img2)
                img[img1_x_position - img2_x_position : img1_x_position ,img1_y_position - img2_y_position : img1_y_position] = new_value_img
                cv2.imshow('SHOW_IMAGE',img)
            if img1_x_position - y_mouse < img2_x_position and img1_y_position - x_mouse >= img2_y_position :
                new_value_img = np.multiply(img[img1_x_position - img2_x_position : img1_x_position ,x_mouse:x_mouse + img2_y_position],img2)
                img[img1_x_position - img2_x_position : img1_x_position ,x_mouse:x_mouse + img2_y_position] = new_value_img
                cv2.imshow('SHOW_IMAGE',img)
            if img1_x_position - y_mouse >= img2_x_position and img1_y_position - x_mouse < img2_y_position :
                new_value_img = np.multiply(img[y_mouse:y_mouse + img2_x_position ,img1_y_position - img2_y_position : img1_y_position],img2)
                img[y_mouse:y_mouse + img2_x_position,img1_y_position - img2_y_position : img1_y_position] = new_value_img
                cv2.imshow('SHOW_IMAGE',img)
            else:
                new_value_img = np.multiply(img[y_mouse:y_mouse + img2_x_position,x_mouse:x_mouse + img2_y_position],img2)
                img[y_mouse:y_mouse + img2_x_position,x_mouse:x_mouse + img2_y_position] = new_value_img
                cv2.imshow('SHOW_IMAGE',img)
        if input_value == ord("4"):
            if img1_x_position - y_mouse < img2_x_position and img1_y_position - x_mouse < img2_y_position :
                new_value_img = np.divide(img[img1_x_position - img2_x_position : img1_x_position ,img1_y_position - img2_y_position : img1_y_position],img2)
                img[img1_x_position - img2_x_position : img1_x_position ,img1_y_position - img2_y_position : img1_y_position] = new_value_img
                cv2.imshow('SHOW_IMAGE',img)
            if img1_x_position - y_mouse < img2_x_position and img1_y_position - x_mouse >= img2_y_position :
                new_value_img = np.divide(img[img1_x_position - img2_x_position : img1_x_position ,x_mouse:x_mouse + img2_y_position],img2)
                img[img1_x_position - img2_x_position : img1_x_position ,x_mouse:x_mouse + img2_y_position] = new_value_img
                cv2.imshow('SHOW_IMAGE',img)
            if img1_x_position - y_mouse >= img2_x_position and img1_y_position - x_mouse < img2_y_position :
                new_value_img = np.divide(img[y_mouse:y_mouse + img2_x_position ,img1_y_position - img2_y_position : img1_y_position],img2)
                img[y_mouse:y_mouse + img2_x_position,img1_y_position - img2_y_position : img1_y_position] = new_value_img
                cv2.imshow('SHOW_IMAGE',img)
            else:
                new_value_img = np.divide(img[y_mouse:y_mouse + img2_x_position,x_mouse:x_mouse + img2_y_position],img2)
                img[y_mouse:y_mouse + img2_x_position,x_mouse:x_mouse + img2_y_position] = new_value_img
                cv2.imshow('SHOW_IMAGE',img)
        if input_value  == ord("5"):
            if img1_x_position - y_mouse < img2_x_position and img1_y_position - x_mouse < img2_y_position :
                new_value_img = np.bitwise_and(img[img1_x_position - img2_x_position : img1_x_position ,img1_y_position - img2_y_position : img1_y_position],img2)
                img[img1_x_position - img2_x_position : img1_x_position ,img1_y_position - img2_y_position : img1_y_position] = new_value_img
                cv2.imshow('SHOW_IMAGE',img)
            if img1_x_position - y_mouse < img2_x_position and img1_y_position - x_mouse >= img2_y_position :
                new_value_img = np.bitwise_and(img[img1_x_position - img2_x_position : img1_x_position ,x_mouse:x_mouse + img2_y_position],img2)
                img[img1_x_position - img2_x_position : img1_x_position ,x_mouse:x_mouse + img2_y_position] = new_value_img
                cv2.imshow('SHOW_IMAGE',img)
            if img1_x_position - y_mouse >= img2_x_position and img1_y_position - x_mouse < img2_y_position :
                new_value_img = np.bitwise_and(img[y_mouse:y_mouse + img2_x_position ,img1_y_position - img2_y_position : img1_y_position],img2)
                img[y_mouse:y_mouse + img2_x_position,img1_y_position - img2_y_position : img1_y_position] = new_value_img
                cv2.imshow('SHOW_IMAGE',img)
            else:
                new_value_img = np.bitwise_and(img[y_mouse:y_mouse + img2_x_position,x_mouse:x_mouse + img2_y_position],img2)
                img[y_mouse:y_mouse + img2_x_position,x_mouse:x_mouse + img2_y_position] = new_value_img
                cv2.imshow('SHOW_IMAGE',img)
        if input_value == ord("6"):
            if img1_x_position - y_mouse < img2_x_position and img1_y_position - x_mouse < img2_y_position :
                new_value_img = np.bitwise_or(img[img1_x_position - img2_x_position : img1_x_position ,img1_y_position - img2_y_position : img1_y_position],img2)
                img[img1_x_position - img2_x_position : img1_x_position ,img1_y_position - img2_y_position : img1_y_position] = new_value_img
                cv2.imshow('SHOW_IMAGE',img)
            if img1_x_position - y_mouse < img2_x_position and img1_y_position - x_mouse >= img2_y_position :
                new_value_img = np.bitwise_or(img[img1_x_position - img2_x_position : img1_x_position ,x_mouse:x_mouse + img2_y_position],img2)
                img[img1_x_position - img2_x_position : img1_x_position ,x_mouse:x_mouse + img2_y_position] = new_value_img
                cv2.imshow('SHOW_IMAGE',img)
            if img1_x_position - y_mouse >= img2_x_position and img1_y_position - x_mouse < img2_y_position :
                new_value_img = np.bitwise_or(img[y_mouse:y_mouse + img2_x_position ,img1_y_position - img2_y_position : img1_y_position],img2)
                img[y_mouse:y_mouse + img2_x_position,img1_y_position - img2_y_position : img1_y_position] = new_value_img
                cv2.imshow('SHOW_IMAGE',img)
            else:
                new_value_img = np.bitwise_or(img[y_mouse:y_mouse + img2_x_position,x_mouse:x_mouse + img2_y_position],img2)
                img[y_mouse:y_mouse + img2_x_position,x_mouse:x_mouse + img2_y_position] = new_value_img
                cv2.imshow('SHOW_IMAGE',img)
        if input_value == ord("7"):
            if img1_x_position - y_mouse < img2_x_position and img1_y_position - x_mouse < img2_y_position :
                new_value_img = np.bitwise_xor(img[img1_x_position - img2_x_position : img1_x_position ,img1_y_position - img2_y_position : img1_y_position],img2)
                img[img1_x_position - img2_x_position : img1_x_position ,img1_y_position - img2_y_position : img1_y_position] = new_value_img
                cv2.imshow('SHOW_IMAGE',img)
            if img1_x_position - y_mouse < img2_x_position and img1_y_position - x_mouse >= img2_y_position :
                new_value_img = np.bitwise_xor(img[img1_x_position - img2_x_position : img1_x_position ,x_mouse:x_mouse + img2_y_position],img2)
                img[img1_x_position - img2_x_position : img1_x_position ,x_mouse:x_mouse + img2_y_position] = new_value_img
                cv2.imshow('SHOW_IMAGE',img)
            if img1_x_position - y_mouse >= img2_x_position and img1_y_position - x_mouse < img2_y_position :
                new_value_img = np.bitwise_xor(img[y_mouse:y_mouse + img2_x_position ,img1_y_position - img2_y_position : img1_y_position],img2)
                img[y_mouse:y_mouse + img2_x_position,img1_y_position - img2_y_position : img1_y_position] = new_value_img
                cv2.imshow('SHOW_IMAGE',img)
            else:
                new_value_img = np.bitwise_xor(img[y_mouse:y_mouse + img2_x_position,x_mouse:x_mouse + img2_y_position],img2)
                img[y_mouse:y_mouse + img2_x_position,x_mouse:x_mouse + img2_y_position] = new_value_img
                cv2.imshow('SHOW_IMAGE',img)
        else :
            print('non')
    if event == cv2.EVENT_RBUTTONDOWN:    
        img = cv2.imread('Tiger.jpg')
        cv2.imshow('SHOW_IMAGE',img)
cv2.setMouseCallback('SHOW_IMAGE',mouseclick)
cv2.imshow('SHOW_IMAGE',img)
while(1):
    input_value = cv2.waitKey(0)
    print(input_value)
    if input_value & 0xFF == 27:
        break
cv2.destroyAllWindows()

ป