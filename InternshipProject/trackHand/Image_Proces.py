import numpy as np
import cv2
import imutils
import matplotlib.pyplot as plt
from skimage import io, morphology, img_as_bool, segmentation
from scipy import ndimage as ndi
from collections import namedtuple
import math

def IntitialPlotData(len_row,len_co):
    # plot data for image
    fig=plt.figure(figsize=(8,8))
    
    return fig,len_row,len_co
def BlurImg(img):
    #img blur with (7,7) numpy
    img1 =cv2.blur(img, (7,7))
    
    return img1
def erosionImage(img):
    #intitial Kernel Data
    kernel = np.ones((5,5),np.uint8)
    
    #erode img with kerneldata
    img1=cv2.erode(img, kernel, iterations=1)
    
    return img1
def CropImage(miny,maxy,minx,maxx,img):
    #miny maxy minx maxx assert Image shape
    img1 = img[miny:maxy,minx:maxx]
    
    return img1
def morphologyData(data):
    #intitial Kernel for morp
    kernel = np.ones((5,5),np.uint8)
    
    #morpdata with dialate and kernel
    morpholoDATA = cv2.morphologyEx(data, cv2.MORPH_DILATE, kernel)
    
    return morpholoDATA
def DatatoDic(data1,data2,data3,dic):
    #zip data and change it  to dic
    NAME_DATA =  [data1,data2,data3]
    Zip_data = zip(NAME_DATA,dic)
    Dic_Data = dict(Zip_data)
    
    return Dic_Data
def copyImage(img):
    #Copy img
    img1 = img.copy()
    
    return img1
def appendfunc(valuex,valuey,x,y):
    #append value to x y point data
    for i in range(0,len(x)):
        valuex.append(x[i])
        valuey.append(y[i])
    
    return valuex,valuey
def filter_colors(image,datacolorthresh):
    #change threshold value to numpyarray
    lower_thresh = np.array([datacolorthresh[0],datacolorthresh[1],datacolorthresh[2]])
    upper_thresh = np.array([datacolorthresh[3],datacolorthresh[4],datacolorthresh[5]])
    
    #Create mask with numpyarray cut threshold
    color_mask = cv2.inRange(image, lower_thresh, upper_thresh)
    color_image = cv2.bitwise_and(image, image, mask=color_mask)
    
    return color_image,image
def detect(c,data):
    #detec point and get number of point
    point_x=[]
    point_y=[]
    peri = cv2.arcLength(c, True)
    approx = cv2.approxPolyDP(c, data*peri, True)

    #append Value for return data
    for i in range(0,len(approx)):
        point_x.append(approx[i][0][0])
        point_y.append(approx[i][0][1])
    
    
    return point_x,point_y
def FindCon2(image,x_point_1,y_point_1,miny,maxy,centerx,maxx,imgori):
    i = 0
    #find ratio image
    Ori = image.copy()
    ratio = image.shape[0] / float(image.shape[0])
    
    #imgColorchangeandBlur
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    blured = cv2.GaussianBlur(gray, (5, 5), 0)
    
    #cut threshold
    thresh = cv2.threshold(blured,0,255, cv2.THRESH_BINARY)[1]
    ret,thresh = cv2.threshold(blured,127,255,0)
    im2, contours, hierarchy = cv2.findContours(thresh,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)
    cv2.imshow("THURMP",thresh)
    cv2.waitKey(0)
    cv2.drawContours(image, contours, -1, (0,255,255), 3)
#DrawContour in image
    x_axis = list()
    y_axis = list()
    for i in range(len(contours[0])):
        x_axis.append(contours[0][i][0][0])
        y_axis.append(contours[0][i][0][1])
    min_xaxis=min(x_axis)
    max_xaxis=max(x_axis)
    min_yaxis=min(y_axis)
    max_yaxis=max(y_axis)
    center = abs(min_xaxis-max_xaxis)/2
    print (min_xaxis,max_xaxis,center,max_yaxis,min_yaxis)
    print (int(((min_xaxis+(1*center)-10))))
    print (int(((max_yaxis+min_yaxis)/2)))
    print (centerx,maxx)
    print (int(((centerx+min_xaxis+(1*center)-30))))
    for i in range(1,3):
        cv2.putText(image, str(i) ,(int(((min_xaxis+(i*center)-30))) ,(int(((max_yaxis+min_yaxis)/2)))), cv2.FONT_HERSHEY_SIMPLEX,0.5, (150,154,153), 2)
        cv2.putText(imgori, str(i) ,(int(((centerx+min_xaxis+(i*center)-30))),miny+(int(((max_yaxis+min_yaxis)/2)))), cv2.FONT_HERSHEY_SIMPLEX,0.5, (255,0,0), 2)
    return Ori,imgori
def FindCon3(image,x_point_1,y_point_1,miny,maxy,centerx,maxx,imgori):
    i = 0
    #find ratio image
    Ori = image.copy()
    ratio = image.shape[0] / float(image.shape[0])
    
    #imgColorchangeandBlur
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    blured = cv2.GaussianBlur(gray, (5, 5), 0)
    
    #cut threshold
    thresh = cv2.threshold(blured,0,255, cv2.THRESH_BINARY)[1]
    ret,thresh = cv2.threshold(blured,127,255,0)
    im2, contours, hierarchy = cv2.findContours(thresh,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)
    cv2.imshow("THURMP",thresh)
    cv2.waitKey(0)
    cv2.drawContours(image, contours, -1, (0,255,255), 3)
    #DrawContour in image
    x_axis = list()
    y_axis = list()
    for i in range(len(contours[0])):
        x_axis.append(contours[0][i][0][0])
        y_axis.append(contours[0][i][0][1])
    min_xaxis=min(x_axis)
    max_xaxis=max(x_axis)
    min_yaxis=min(y_axis)
    max_yaxis=max(y_axis)
    center = abs(min_xaxis-max_xaxis)/2
    print (min_xaxis,max_xaxis,center,max_yaxis,min_yaxis)
    print (int(((min_xaxis+(1*center)-10))))
    print (int(((max_yaxis+min_yaxis)/2)))
    print (centerx,maxx)
    print (int(((centerx+min_xaxis+(1*center)-30))))
    for i in range(1,3):
        cv2.putText(image, str(i) ,(int(((min_xaxis+(i*center)-30))) ,(int(((max_yaxis+min_yaxis)/2)))), cv2.FONT_HERSHEY_SIMPLEX,0.5, (150,154,153), 2)
        cv2.putText(imgori, str(i) ,(int(centerx-((min_xaxis+(i*center)+15))),miny+(int(((max_yaxis+min_yaxis)/2)))), cv2.FONT_HERSHEY_SIMPLEX,0.5, (255,0,0), 2)
    return Ori,imgori
def FindCon(image,x_point_1,y_point_1):
    i = 0
    #find ratio image
    Ori = image.copy()
    ratio = image.shape[0] / float(image.shape[0])
    
    #imgColorchangeandBlur
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    blured = cv2.GaussianBlur(gray, (5, 5), 0)
    
    #cut threshold
    thresh = cv2.threshold(blured,0,255, cv2.THRESH_BINARY)[1]
    
    #findAllcontour in img with ChainAPPROX
    cnts = cv2.findContours(thresh.copy(), cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
    # print (cnts)

    cnts = cnts[0] if imutils.is_cv2() else cnts[1]

    number_con=0
    #DrawContour in image
    x_axis = list()
    y_axis = list()
    for c in cnts:
        area = cv2.contourArea(c)
        if area > 200:
            M = cv2.moments(c)
            rect = cv2.minAreaRect(c)
            if M["m00"] != 0:
                cX = int((M["m10"] / M["m00"]) * ratio)
                cY = int((M["m01"] / M["m00"]) * ratio)
            else:
                cX, cY = 0,0
            point_x,point_y= detect(c,0.003)
            data1,data2= appendfunc(x_point_1,y_point_1,point_x,point_y)
            c = c.astype("float")
            c *= ratio
            c = c.astype("int")
            number_con = number_con+1
            for z in range(0,number_con):
                for y in range(0,len(cnts[z])):
                    for i in range(0,len(cnts[z][y])):
                        x_axis.append(cnts[z][y][i][0])
                        y_axis.append(cnts[z][y][i][1])

        #Putname in image with number of point
    for i in range(len(x_point_1)):
        cv2.putText(image, str(i) , (x_point_1[i], y_point_1[i]), cv2.FONT_HERSHEY_SIMPLEX,0.5, (150,154,153), 2)
    
    #number of point in image
    i += 1
    return Ori,data1,data2,x_axis,y_axis
def find_Max_Min(DATA):
    #Setup min max data for find differtent data
    Max_DATA =0
    Min_DATA =520
    
    #LoopForCountDataLeftRight
    for i in range(len(DATA)):
        if DATA[i] >= Max_DATA:
            Max_DATA = DATA[i]
        if DATA[i] <= Min_DATA:
            Min_DATA = DATA[i]

    #FindCenter_data
    Center_data = ((Max_DATA - Min_DATA)/2) + Min_DATA
    return Max_DATA,Min_DATA,Center_data
def FindZone_Point(xpoint,ypoint):
    #Intital Value DATA
    DatainLeft =  0
    DatainRight =  0
    
    #Find Max Min  Center of point for cutImage
    Max_x,Min_x,Cen_data_x = find_Max_Min(xpoint)
    Max_y,Min_y,Cen_data_y = find_Max_Min(xpoint)

    Center = Cen_data_x
    Center_2 = Cen_data_y
#    print (Max_x,Min_x,Center)

    shape = "unidentified"
    data = []
    
    #Checken point x and Y
    assert len(xpoint) == len(ypoint)
    
    #Find number of zone area
    for i in range(len(xpoint)):
        if xpoint[i] <= Center  :
            DatainRight = DatainRight+1
        else:
            DatainLeft = DatainLeft+1

    #Define Image to Left or Right Hand
    if DatainRight == DatainLeft :
        pass
    if DatainRight < DatainLeft:
        shape = "Right-Hand"
    if DatainRight > DatainLeft:
        shape = "Left-Hand"

    #Append data and return
    data.append(DatainRight)
    data.append(DatainLeft)
    data.append(shape)
    return data

def CutNearPoint(datax,datay):
    assert len(datax) == len(datay)
    newdatax,newdatay,newdatax2,newdatay2,maxdatax,maxdatay =list(),list(),list(),list(),list(),list()
    newdatax.append(datax[0])
    newdatay.append(datay[0])
    Countdata=0
    Countdata_notappend =0
#    print(datax[1])
#    print(newdatax[0])
    for i in range(1,len(datax)):
        if abs(datay[i] - newdatay[Countdata]) >= 50  :
            if Countdata_notappend != 0 :
                index = maxdatax.index(min(maxdatax))
                newdatax.append(maxdatax[index])
                newdatay.append(maxdatay[index])
                maxdatax,maxdatay =[],[]
                Countdata_notappend =0
            newdatax.append(datax[i])
            newdatay.append(datay[i])
            Countdata += 1
            NewPoint = True
        else:
            NewPoint = False
        if NewPoint == False :
            maxdatax.append(datax[i])
            maxdatay.append(datay[i])
#            print (maxdatax,maxdatay)
            Countdata_notappend += 1
    roundloop = len(newdatax)
    newdatax2.append(newdatax[0])
    newdatay2.append(newdatay[0])
    for i in range(0,roundloop-1):
        if abs(newdatax[i] - newdatax[i+1] ) <= 10 and abs(newdatay[i] - newdatay[i+1] ) <=50 :
            pass
        else :
            newdatax2.append(newdatax[i+1])
            newdatay2.append(newdatay[i+1])
    del newdatay2[0]
    del newdatax2[0]
    return newdatax2,newdatay2
def CutNearPoint2(datax,datay):
    assert len(datax) == len(datay)
    newdatax,newdatay,newdatax2,newdatay2,maxdatax,maxdatay =list(),list(),list(),list(),list(),list()
    newdatax.append(datax[0])
    newdatay.append(datay[0])
    Countdata=0
    Countdata_notappend =0
    #    print(datax[1])
    #    print(newdatax[0])
    for i in range(1,len(datax)):
        if abs(datay[i] - newdatay[Countdata]) >= 50  :
            if Countdata_notappend != 0 :
                index = maxdatax.index(max(maxdatax))
                newdatax.append(maxdatax[index])
                newdatay.append(maxdatay[index])
                maxdatax,maxdatay =[],[]
                Countdata_notappend =0
            newdatax.append(datax[i])
            newdatay.append(datay[i])
            Countdata += 1
            NewPoint = True
        else:
            NewPoint = False
        if NewPoint == False :
            maxdatax.append(datax[i])
            maxdatay.append(datay[i])
            #            print (maxdatax,maxdatay)
            Countdata_notappend += 1
    roundloop = len(newdatax)
    newdatax2.append(newdatax[0])
    newdatay2.append(newdatay[0])
    for i in range(0,roundloop-1):
        if abs(newdatax[i] - newdatax[i+1] ) <= 10 and abs(newdatay[i] - newdatay[i+1] ) <=50 :
            pass
        else :
            newdatax2.append(newdatax[i+1])
            newdatay2.append(newdatay[i+1])
    del newdatay2[0]
    del newdatax2[0]
    return newdatax2,newdatay2
def FindRightPoint(dataHullx,dataHully,datax,datay):
    LastPointx,LastPointy,maxdatax,maxdatay=list(),list(),list(),list()
    assert len(datax) == len(datay)
    assert len(dataHullx) == len(dataHully)
    for y in range(0,len(dataHully)):
        for i in range(0,len(datay)):
            if abs(dataHully[y] -datay[i])<=20:
                maxdatax.append(datax[i])
                maxdatay.append(datay[i])
        index = maxdatax.index(max(maxdatax))
        LastPointx.append(maxdatax[index])
        LastPointy.append(maxdatay[index])
        maxdatax,maxdatay =[],[]
    return LastPointx,LastPointy
def FindLeftPoint(dataHullx,dataHully,datax,datay):
    LastPointx,LastPointy,mindatax,mindatay=list(),list(),list(),list()
    assert len(datax) == len(datay)
    assert len(dataHullx) == len(dataHully)
    for y in range(0,len(dataHully)):
        for i in range(0,len(datay)):
            if abs(dataHully[y] -datay[i])<=20:
                mindatax.append(datax[i])
                mindatay.append(datay[i])
        index = mindatax.index(min(mindatax))
        LastPointx.append(mindatax[index])
        LastPointy.append(mindatay[index])
        mindatax,mindatay =[],[]
    return LastPointx,LastPointy
def FindJoint(datax,datay,Hullx,Hully):
    jointx,jointy=list(),list()
    assert len(datax) == len(Hullx)
    assert len(datay) == len(Hully)
    for i in range(0,len(datax)):
        range_joint = abs(datax[i]-Hullx[i])/3
        jointx.append(int(range_joint))
    return jointx
def findnearestindex(yjoint,ycon):
    value =10000
    for i in range(len(ycon)):
        if value > abs((yjoint)-ycon[i]):
            data = ycon[i]
            value = abs((yjoint)-ycon[i])
    return data

def DrawHandJointCenter(allindex,valuemidy):
    listdata=list()
    
    for i in range(len(allindex)):
        listdata.append((allindex[i]-valuemidy))

#    print ("allindex",allindex)
#    print ("listdata",listdata)


#    print("LISTDATA",listdata)
    minindex=listdata.index(max([n for n in listdata if n<0]))
#    print("LISTDATAindex",minindex)

    minvalue1 = allindex[minindex]
    listdata.pop(minindex)
    allindex.pop(minindex)
    minindex2=listdata.index(min([n for n in listdata  if n>0]))
#    print("LISTDATAindex",minindex2)
    minvalue2 = allindex[minindex2]

#    print ("MINVALUE1 2 ",minvalue1,minvalue2,valuemidy)
    centerValue = int((minvalue1+minvalue2)/2)
#    print (minvalue1,minvalue2)
    return centerValue
def DrawImageHand2(img,allconx,allcony,xdata,ydata,imgori,miny,minx):
    MidValuelist,ypointcenter,indexlist,x_point_4,x_point_1,y_point_1,x_point_2,y_point_2,x_point_3=list(),list(),list(),list(),list(),list(),list(),list(),list()
    img2 = copyImage(img)
    img3 = copyImage(img)
    edges = cv2.Canny(img2,200,200*2)
    drawing = np.zeros(img2.shape,np.uint8)     # Image to draw the contours
    drawing2 = np.zeros(img2.shape,np.uint8)     # Image to draw the contours
    drawing3 = np.zeros(img2.shape,np.uint8)     # Image to draw the contours

    _,contours,hierarchy = cv2.findContours(edges,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)
    number_con=0
    countjoint  = 1
    #DrawContour in image
    x_axis = list()
    y_axis = list()
    maxlength = max(map(len, contours))
    cnts = []
    for cnt in contours:
        hull = cv2.convexHull(cnt)
        cv2.drawContours(drawing,[cnt],0,(150,154,153),2)   # draw contours in green color
        cv2.drawContours(drawing2,[cnt],0,(150,154,153),2)   # draw contours in green color
        cv2.drawContours(drawing,[hull],0,(0,0,255),2)  # draw contours in red color
        number_con = number_con+1
    for z in range(0,number_con):
        for y in range(0,len(contours[z])):
            for i in range(0,len(contours[z][y])):
                x_axis.append(contours[z][y][i][0])
                y_axis.append(contours[z][y][i][1])

    point_x,point_y= detect(hull,0.002)
    x_point_1,y_point_1= appendfunc(x_point_1,y_point_1,point_x,point_y)
    point_x2,point_y2= detect(cnt,0.0001)
    x_point_2,y_point_2= appendfunc(x_point_2,y_point_2,point_x2,point_y2)
    for cnt in contours:
        hull = cv2.convexHull(cnt)
        cv2.drawContours(drawing3,[cnt],0,(150,154,153),2)   # draw contours in green color
        cv2.drawContours(drawing3,[hull],0,(0,0,255),2)  # draw contours in red color
    drawing3=cv2.flip(drawing3,1)
    drawing2=cv2.flip(drawing2,1)
    drawing=cv2.flip(drawing,1)
    for i in range(len(x_point_2)):
        x_point_2[i]=abs(drawing3.shape[1]-x_point_2[i])
    for i in range(len(x_point_2)):
        cv2.putText(drawing3, str(i) , (x_point_2[i]-10, y_point_2[i]), cv2.FONT_HERSHEY_SIMPLEX,0.5, (0,255,0), 2)
    x_point_1,y_point_1 = CutNearPoint(x_point_1,y_point_1)
    Lastx,Lasty=FindRightPoint(x_point_1,y_point_1,xdata,ydata)
    Jointdata1 = FindJoint(Lastx,Lasty,x_point_1,y_point_1)
    allindex=[]
#    findnearestindex
#    for i in range(len(x_point_1)):
#        for y in range(1,4):
#            print("?ADSDSDS")
#            MidValue = x_point_1[i]+(y*Jointdata1[i])-int(Jointdata1[i]/2)
#            for number in range(0,10):
#                MidValuelist.append(MidValue+number)
#                for c in range(len(MidValuelist)):
#                    allindexdata = [k for k, e in enumerate(x_point_2) if e == MidValuelist[c]]
#                    allindex.extend(allindexdata)
#                MidValuelist = []
#                for b in range(0,len(allindex)):
#                    indexlist.append(y_axis[allindex[b]])
#                    #                print ("INDEXLIST = ",indexlist,y_point_1[i])
#                    ypointcenter.extend(DrawHandJointCenter(indexlist,y_point_1[i]))
#                print(" Ypointcenter",ypointcenter)
#    print ("INDEX " ,allindex)
#    print ("X " ,x_point_1[0])
#    for i in range(0,len(allindex)):
#        print ("YAXIS TOP and BOT =",y_axis[allindex[i]])

    
    for i in range(len(x_point_1)):
        x_point_3.append(x_point_1[i])
        x_point_1[i]=abs(drawing2.shape[1]-x_point_1[i])
    for i in range(len(x_point_2)):
        x_point_4.append(x_point_2[i])
        x_point_2[i]=abs(drawing2.shape[1]-x_point_2[i])

    for i in range(len(Lastx)):
        Lastx[i]=abs(drawing.shape[1]-Lastx[i])
    for i in range(len(x_point_1)):
        cv2.putText(drawing, str(i) , (x_point_1[i]-10, y_point_1[i]), cv2.FONT_HERSHEY_SIMPLEX,0.5, (0,255,0), 2)
    for i in range(len(Lastx)):
        cv2.putText(drawing, str(i) , (Lastx[i]-10, Lasty[i]), cv2.FONT_HERSHEY_SIMPLEX,0.5, (255,255,0), 2)
#    print(minx)
#    print(abs(drawing2.shape[1]-(x_point_3[0]+(1*Jointdata1[0])-int(Jointdata1[0]/2))))
    for i in range(len(x_point_3)):
        for y in range(1,4):
            if countjoint >=13:
                break
            countjoint = countjoint+1


            indexlist = []
            cv2.putText(drawing2, str(countjoint) , (abs(drawing2.shape[1]-(x_point_3[i]+(y*Jointdata1[i])-int(Jointdata1[i]/2))),y_point_1[i]), cv2.FONT_HERSHEY_SIMPLEX,0.5, (255,0,255), 2)
            cv2.putText(imgori, str(countjoint) , (minx-30+abs(drawing2.shape[1]-(x_point_3[i]+(y*Jointdata1[i])-int(Jointdata1[i]/2))),miny+y_point_1[i]), cv2.FONT_HERSHEY_SIMPLEX,0.5, (255,0,0), 2)


#    cv2.imshow('output',drawing)
#    cv2.imshow('input',img2)
    return x_point_1,y_point_1,Lastx,Lasty,Jointdata1,drawing,drawing2,drawing3,img2,imgori




def rotate(image_path, degrees_to_rotate, saved_location):
    """
        Rotate the given photo the amount of given degreesk, show it and save it
        
        @param image_path: The path to the image to edit
        @param degrees_to_rotate: The number of degrees to rotate the image
        @param saved_location: Path to save the cropped image
        """
    image_obj = image_path
    rotated_image = image_obj.rotate(degrees_to_rotate)
    rotated_image.show()
    return image_obj

def DrawImageHand(img,allconx,allcony,xdata,ydata,imgori,miny,minx):
    MidValuelist,allindexdata,x_point_1,indexlist,y_point_1,x_point_2,y_point_2=list(),list(),list(),list(),list(),list(),list()
    img2 = copyImage(img)
    img3 = copyImage(img)
    edges = cv2.Canny(img2,200,200*2)
    drawing = np.zeros(img2.shape,np.uint8)     # Image to draw the contours
    drawing2 = np.zeros(img2.shape,np.uint8)     # Image to draw the contours
    drawing3 = np.zeros(img2.shape,np.uint8)     # Image to draw the contours
    
    _,contours,hierarchy = cv2.findContours(edges,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)
    number_con=0
    countjoint  = 1
    #DrawContour in image
    x_axis = list()
    y_axis = list()
    maxlength = max(map(len, contours))
    cnts = []

    for cnt in contours:
        hull = cv2.convexHull(cnt)
        cv2.drawContours(drawing,[cnt],0,(150,154,153),2)   # draw contours in green color
        cv2.drawContours(drawing2,[cnt],0,(150,154,153),2)   # draw contours in green color
        cv2.drawContours(drawing,[hull],0,(0,0,255),2)  # draw contours in red color
        number_con = number_con+1
    for z in range(0,number_con):
        for y in range(0,len(contours[z])):
            for i in range(0,len(contours[z][y])):
                x_axis.append(contours[z][y][i][0])
                y_axis.append(contours[z][y][i][1])

    point_x,point_y= detect(hull,0.002)
    x_point_1,y_point_1= appendfunc(x_point_1,y_point_1,point_x,point_y)
    point_x2,point_y2= detect(cnt,0.0001)
    x_point_2,y_point_2= appendfunc(x_point_2,y_point_2,point_x2,point_y2)
#    print("LEN X 2 Y 2 =",len(point_x2),len(point_y2))
#    print("LEN X 2 Y 2 =",len(y_point_2),len(x_point_2))
    for cnt in contours:
        hull = cv2.convexHull(cnt)
        cv2.drawContours(drawing3,[cnt],0,(150,154,153),1)   # draw contours in green color
        cv2.drawContours(drawing3,[hull],0,(0,0,255),1)  # draw contours in red color
        for i in range(len(x_point_2)):
            cv2.putText(drawing3, str(i) , (x_point_2[i]-10, y_point_2[i]), cv2.FONT_HERSHEY_SIMPLEX,0.5, (0,255,0), 2)
        x_point_1,y_point_1 = CutNearPoint(x_point_1,y_point_1)
        Lastx,Lasty=FindRightPoint(x_point_1,y_point_1,xdata,ydata)
#        print("LASTX = " ,Lastx,"\nLASTY = ",Lasty)
#        print("X = " ,len(xdata),"\nY = ",len(ydata))
        Jointdata1 = FindJoint(Lastx,Lasty,x_point_1,y_point_1)

        for i in range(len(x_point_1)):
            cv2.putText(drawing, str(i) , (x_point_1[i]-10, y_point_1[i]), cv2.FONT_HERSHEY_SIMPLEX,0.5, (0,255,0), 2)
    for i in range(len(Lastx)):
        cv2.putText(drawing, str(i) , (Lastx[i]-10, Lasty[i]), cv2.FONT_HERSHEY_SIMPLEX,0.5, (255,255,0), 2)
        allindex = []
        for i in range(len(x_point_1)):
            for y in range(1,4):
                if countjoint >=13:
                    break
                countjoint = countjoint+1
#                print("I , Y ",i,y)
                MidValue = x_point_1[i]+(y*Jointdata1[i])-int(Jointdata1[i]/2)
                for number in range(0,10):
                    MidValuelist.append(MidValue+number)
                for c in range(len(MidValuelist)):
                    allindexdata = [k for k, e in enumerate(x_point_2) if e == MidValuelist[c]]
                    allindex.extend(allindexdata)
                MidValuelist = []

#                print ("ALL",allindex,y_point_1[i])
                for b in range(0,len(allindex)):
#                    print ("YAXIS TOP and BOT =",y_axis[allindex[b]])
                    indexlist.append(y_axis[allindex[b]])
#                print ("INDEXLIST = ",indexlist,y_point_1[i])
                ypointcenter=DrawHandJointCenter(indexlist,y_point_1[i])
#                print(" Ypointcenter",ypointcenter)
                indexlist = []
                cv2.putText(drawing2, str(countjoint) , (x_point_1[i]+(y*Jointdata1[i])-int(Jointdata1[i]/2),ypointcenter), cv2.FONT_HERSHEY_SIMPLEX,0.5, (255,0,255), 2)
                cv2.putText(imgori, str(countjoint+1) , (minx+x_point_1[i]+(y*Jointdata1[i])-int(Jointdata1[i]/2),miny+ypointcenter), cv2.FONT_HERSHEY_SIMPLEX,0.5, (255,0,0), 2)

    #    cv2.imshow('output',drawing)
    #    cv2.imshow('input',img2)
    return x_point_1,y_point_1,Lastx,Lasty,Jointdata1,drawing,drawing2,drawing3,img2,imgori







