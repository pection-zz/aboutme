import cv2
import numpy as np



def add(img1, img2, xyCor):
    xPos,yPos = xyCor
    xBefore,yBefore=xPos,yPos
    xReal,yReal=0,0
    imageWidth2 = img2.shape[1]
    imageHeight2 = img2.shape[0]
    while xReal < imageWidth2: 
        while yReal < imageHeight2:
            Pos1=cv2.add(int(img1[yPos,xPos,0]),int(img2[yReal,xReal,0]))
            Pos2=cv2.add(int(img1[yPos,xPos,1]),int(img2[yReal,xReal,1]))
            Pos3=cv2.add(int(img1[yPos,xPos,2]),int(img2[yReal,xReal,2]))
            img1.itemset((yPos, xPos, 0),int(Pos1[0][0]) ) 
            img1.itemset((yPos, xPos, 1),int(Pos2[0][0]) )
            img1.itemset((yPos, xPos, 2),int(Pos3[0][0]) )
            yPos = yPos + 1 
            yReal= yReal+1
        yPos = yBefore
        yReal = 0
        xPos = xPos + 1 
        xReal = xReal +1
    return img1
def subtract(img1,img2,xyCor):
    xPos,yPos = xyCor
    xBefore,yBefore=xPos,yPos
    xReal,yReal=0,0
    imageWidth2 = img2.shape[1]
    imageHeight2 = img2.shape[0]
    while xReal < imageWidth2:
        while yReal < imageHeight2: 
            Pos1=cv2.subtract(int(img1[yPos,xPos,0]),int(img2[yReal,xReal,0]))
            Pos2=cv2.subtract(int(img1[yPos,xPos,1]),int(img2[yReal,xReal,1]))
            Pos3=cv2.subtract(int(img1[yPos,xPos,2]),int(img2[yReal,xReal,2]))
            img1.itemset((yPos, xPos, 0),int(Pos1[0][0]) ) 
            img1.itemset((yPos, xPos, 1),int(Pos2[0][0]) )
            img1.itemset((yPos, xPos, 2),int(Pos3[0][0]) )
            yPos = yPos + 1
            yReal= yReal+1
        yPos = yBefore
        yReal = 0
        xPos = xPos + 1 
        xReal = xReal +1
    return img1 
def multiply(img1,img2,xyCor):
    xPos,yPos = xyCor
    xBefore,yBefore=xPos,yPos
    xReal,yReal=0,0
    imageWidth2 = img2.shape[1]
    imageHeight2 = img2.shape[0]
    while xReal < imageWidth2:
        while yReal < imageHeight2: 
            Pos1=cv2.multiply(int(img1[yPos,xPos,0]),int(img2[yReal,xReal,0]))
            Pos2=cv2.multiply(int(img1[yPos,xPos,1]),int(img2[yReal,xReal,1]))
            Pos3=cv2.multiply(int(img1[yPos,xPos,2]),int(img2[yReal,xReal,2]))
            if(np.isnan(Pos1[0][0]) or np.isinf(Pos1[0][0])):
                Pos1[0][0] = 0
            if(np.isnan(Pos2[0][0]) or np.isinf(Pos2[0][0])):
                Pos2[0][0] = 0
            if(np.isnan(Pos3[0][0]) or np.isinf(Pos3[0][0])):
                Pos3[0][0] = 0
            img1.itemset((yPos, xPos, 0),int(Pos1[0][0]) ) 
            img1.itemset((yPos, xPos, 1),int(Pos2[0][0]) )
            img1.itemset((yPos, xPos, 2),int(Pos3[0][0]) )
            yPos = yPos + 1
            yReal= yReal+1
        yPos = yBefore
        yReal = 0
        xPos = xPos + 1 
        xReal = xReal +1
    return img1 
def divide(img1,img2,xyCor):   
    xPos,yPos = xyCor
    xBefore,yBefore=xPos,yPos
    xReal,yReal=0,0
    imageWidth2 = img2.shape[1]
    imageHeight2 = img2.shape[0]
    while xReal < imageWidth2:
        while yReal < imageHeight2: 
            Pos1=cv2.divide(int(img1[yPos,xPos,0]),int(img2[yReal,xReal,0]))
            Pos2=cv2.divide(int(img1[yPos,xPos,1]),int(img2[yReal,xReal,1]))
            Pos3=cv2.divide(int(img1[yPos,xPos,2]),int(img2[yReal,xReal,2]))
            if(np.isnan(Pos1[0][0]) or np.isinf(Pos1[0][0])):
                Pos1[0][0] = 0
            if(np.isnan(Pos2[0][0]) or np.isinf(Pos2[0][0])):
                Pos2[0][0] = 0
            if(np.isnan(Pos3[0][0]) or np.isinf(Pos3[0][0])):
                Pos3[0][0] = 0
            img1.itemset((yPos, xPos, 0),int(Pos1[0][0]) ) 
            img1.itemset((yPos, xPos, 1),int(Pos2[0][0]) )
            img1.itemset((yPos, xPos, 2),int(Pos3[0][0]) )
            yPos = yPos + 1
            yReal= yReal+1
        yPos = yBefore
        yReal = 0
        xPos = xPos + 1 
        xReal = xReal +1
    return img1 
def bitwise_and(img1,img2,xyCor):
    xPos,yPos = xyCor
    xBefore,yBefore=xPos,yPos
    xReal,yReal=0,0
    imageWidth2 = img2.shape[1]
    imageHeight2 = img2.shape[0]
    while xReal < imageWidth2:
        while yReal < imageHeight2: 
            Pos1=np.bitwise_and(int(img1[yPos,xPos,0]),int(img2[yReal,xReal,0]))
            Pos2=np.bitwise_and(int(img1[yPos,xPos,1]),int(img2[yReal,xReal,1]))
            Pos3=np.bitwise_and(int(img1[yPos,xPos,2]),int(img2[yReal,xReal,2]))
            if(np.isnan(Pos1[0][0]) or np.isinf(Pos1[0][0])):
                Pos1[0][0] = 0
            if(np.isnan(Pos2[0][0]) or np.isinf(Pos2[0][0])):
                Pos2[0][0] = 0
            if(np.isnan(Pos3[0][0]) or np.isinf(Pos3[0][0])):
                Pos3[0][0] = 0
            img1.itemset((yPos, xPos, 0),int(Pos1[0][0]) ) 
            img1.itemset((yPos, xPos, 1),int(Pos2[0][0]) )
            img1.itemset((yPos, xPos, 2),int(Pos3[0][0]) )
            yPos = yPos + 1
            yReal= yReal+1
        yPos = yBefore
        yReal = 0
        xPos = xPos + 1 
        xReal = xReal +1
    return img1 
def bitwise_or(img1,img2,xyCor):
    xPos,yPos = xyCor
    xBefore,yBefore=xPos,yPos
    xReal,yReal=0,0
    imageWidth2 = img2.shape[1]
    imageHeight2 = img2.shape[0]
    while xReal < imageWidth2:
        while yReal < imageHeight2: 
            Pos1=np.bitwise_or(int(img1[yPos,xPos,0]),int(img2[yReal,xReal,0]))
            Pos2=np.bitwise_or(int(img1[yPos,xPos,1]),int(img2[yReal,xReal,1]))
            Pos3=np.bitwise_or(int(img1[yPos,xPos,2]),int(img2[yReal,xReal,2]))
            if(np.isnan(Pos1[0][0]) or np.isinf(Pos1[0][0])):
                Pos1[0][0] = 0
            if(np.isnan(Pos2[0][0]) or np.isinf(Pos2[0][0])):
                Pos2[0][0] = 0
            if(np.isnan(Pos3[0][0]) or np.isinf(Pos3[0][0])):
                Pos3[0][0] = 0
            img1.itemset((yPos, xPos, 0),int(Pos1[0][0]) ) 
            img1.itemset((yPos, xPos, 1),int(Pos2[0][0]) )
            img1.itemset((yPos, xPos, 2),int(Pos3[0][0]) )
            yPos = yPos + 1
            yReal= yReal+1
        yPos = yBefore
        yReal = 0
        xPos = xPos + 1 
        xReal = xReal +1
    return img1 
def bitwise_xor(img1,img2,xyCor):
    xPos,yPos = xyCor
    xBefore,yBefore=xPos,yPos
    xReal,yReal=0,0
    imageWidth2 = img2.shape[1]
    imageHeight2 = img2.shape[0]
    while xReal < imageWidth2:
        while yReal < imageHeight2: 
            Pos1=np.bitwise_xor(int(img1[yPos,xPos,0]),int(img2[yReal,xReal,0]))
            Pos2=np.bitwise_xor(int(img1[yPos,xPos,1]),int(img2[yReal,xReal,1]))
            Pos3=np.bitwise_xor(int(img1[yPos,xPos,2]),int(img2[yReal,xReal,2]))
            if(np.isnan(Pos1[0][0]) or np.isinf(Pos1[0][0])):
                Pos1[0][0] = 0
            if(np.isnan(Pos2[0][0]) or np.isinf(Pos2[0][0])):
                Pos2[0][0] = 0
            if(np.isnan(Pos3[0][0]) or np.isinf(Pos3[0][0])):
                Pos3[0][0] = 0
            img1.itemset((yPos, xPos, 0),int(Pos1[0][0]) ) 
            img1.itemset((yPos, xPos, 1),int(Pos2[0][0]) )
            img1.itemset((yPos, xPos, 2),int(Pos3[0][0]) )
            yPos = yPos + 1
            yReal= yReal+1
        yPos = yBefore
        yReal = 0
        xPos = xPos + 1 
        xReal = xReal +1
    return img1  
def changecolor(event,x,y,flags,param):
    global img1
    global img2
    # print ("CLCK")
    if event == cv2.EVENT_LBUTTONDOWN:
        if State_1==True and (x+img2.shape[1])<img1.shape[1] and (y+img2.shape[0])<img1.shape[0]:
            img1 = add(img1,img2,(x,y))
        if State_2==True and (x+img2.shape[1])<img1.shape[1] and (y+img2.shape[0])<img1.shape[0]:
            img1 = subtract(img1,img2,(x,y))
        if State_3==True and (x+img2.shape[1])<img1.shape[1] and (y+img2.shape[0])<img1.shape[0]:
            img1 = multiply(img1,img2,(x,y))
        if State_4==True and (x+img2.shape[1])<img1.shape[1] and (y+img2.shape[0])<img1.shape[0]:
            img1 = divide(img1,img2,(x,y))
        if State_5==True and (x+img2.shape[1])<img1.shape[1] and (y+img2.shape[0])<img1.shape[0]:
            img1 = bitwise_and(img1,img2,(x,y))
        if State_6==True and (x+img2.shape[1])<img1.shape[1] and (y+img2.shape[0])<img1.shape[0]:
            img1 = bitwise_or(img1,img2,(x,y))
        if State_7==True and (x+img2.shape[1])<img1.shape[1] and (y+img2.shape[0])<img1.shape[0]:
            img1 = bitwise_xor(img1,img2,(x,y))
State_1 , State_2, State_3, State_4, State_5, State_6, State_7=False,False,False,False,False,False,False

img1 = cv2.imread('C:\Code_python\Image\Picture\Tiger.jpg')
img2 = cv2.imread('C:\Code_python\Image\Picture\Human.jpg')

cv2.namedWindow('image', cv2.WINDOW_NORMAL)

cv2.setMouseCallback('image',changecolor)
while(1):
    cv2.imshow('image',img1)
    k = cv2.waitKey(1000)
    # print(k)
    if k == ord("1"):
        State_1,State_2,State_3,State_4,State_5,State_6,State_7 =True,False,False,False,False,False,False
        print("1")
    if k == ord("2"):
        State_1,State_2,State_3,State_4,State_5,State_6,State_7 =False,True,False,False,False,False,False
    if k == ord("3"):
        State_1,State_2,State_3,State_4,State_5,State_6,State_7 =False,False,True,False,False,False,False
    if k == ord("4"):
        State_1,State_2,State_3,State_4,State_5,State_6,State_7 =False,False,False,True,False,False,False
    if k == ord("5"):
        State_1,State_2,State_3,State_4,State_5,State_6,State_7 =False,False,False,False,True,False,False
    if k == ord("6"):
        State_1,State_2,State_3,State_4,State_5,State_6,State_7 =False,False,False,False,False,True,False
    if k == ord("7"):
        State_1,State_2,State_3,State_4,State_5,State_6,State_7 =False,False,False,False,False,False,True
    
    if k & 0xFF ==27:
        break
        
