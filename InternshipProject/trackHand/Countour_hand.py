
from Image_Proces import *
import os,glob
import argparse
import PIL
from collections import namedtuple
import matplotlib.pyplot as plt
import random

Point = namedtuple('Point', 'x y')

def get_hull_points(self):
    if self._points and not self._hull_points:
        self.compute_hull()
        
        return self._hull_points
    
    def display(self):
        # all points
        x = [p.x for p in self._points]
        y = [p.y for p in self._points]
        plt.plot(x, y, marker='D', linestyle='None')
        
        # hull points
        hx = [p.x for p in self._hull_points]
        hy = [p.y for p in self._hull_points]
        plt.plot(hx, hy)
        
        plt.title('Convex Hull')
        plt.show()

if __name__ == "__main__":
    #XY point Data
#    x_point,xaxis,xcrop,xaxiscrop =list(),list(),list(),list()
#    y_point,yaxis,ycrop,yaxiscrop =list(),list(),list(),list()
#

    #dataColorCutHelp
    datacolor_red=[150,154,153,255,255,255]
    
    #setup os for matplot with low level
    os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'

    #Set up Path arg
    ap = argparse.ArgumentParser()
    ap.add_argument("-i", "--imagepath", required=True,
                        help="path to folder which contain images.")
    ap.add_argument("-c", "--capture", action='store_true',
                        help="Capture Image for Testdata")
    ap.add_argument("-o", "--onepicture",
                            help="Capture Image for Testdata")
    ap.add_argument("-s", "--showresult",action = 'store_true',
                    help="show image picture")
    args = vars(ap.parse_args())
    # images to be shown
    if args["capture"]:
        dirname='./ImageReal/'
        dirname_remove = './ImageReal/*'
        if (FirstTime==True):
            dataname_file = glob.glob(dirname_remove)
            for i in dataname_file:
                os.remove(i)
        FirstTime = False
        cap = cv2.VideoCapture(0)
        while(True):
            ret, frame = cap.read()
            cv2.imshow('frame',frame)
            if not ret:
                break
            k = cv2.waitKey(1)
            if k%256 == 27:
                print("Escape hit, closing...")
                break
            elif k%256 == 32:
                # SPACE pressed
                img_name = "ImageforTest_{}.png".format(img_counter)
                cv2.imwrite(os.path.join(dirname,img_name), frame)
                print("{} written!".format(img_name))
                img_counter += 1
        cap.release()
        cv2.destroyAllWindows()
        image_list = glob.glob(os.path.abspath(dirname)+"/*.*")
    elif args["onepicture"]:

        image_list = glob.glob(os.path.abspath(args["imagepath"]+args["onepicture"]))
#        print (image_list)
#        print (glob.glob(os.path.abspath(args["imagepath"])))
    else :
#        path without capture image to read file and Process data
#        example     ("./power_left/3.jpg")
        image_list = glob.glob(os.path.abspath(args["imagepath"])+"/*.*")

    print (image_list)
    # Feed image list through network
    for img_name in image_list:
        x_point,xaxis,xcrop,xcrop2,xaxiscrop =list(),list(),list(),list(),list()
        y_point,yaxis,ycrop,ycrop2,yaxiscrop =list(),list(),list(),list(),list()
    
        #imgname
        img = cv2.imread(img_name)
#        img=cv2.flip(img,1)
        imgori_full = copyImage(img)
        #SetupIntitial Plot DATA
        fig,rows,columns=IntitialPlotData(4,2)
        
        #SetupImageProces
        ratio = img.shape[0] / 500.0
        orig = copyImage(img)
        img = imutils.resize(img, height = 500)
        
        #ImageProcessData
        img = BlurImg(img)
        img_erosion = erosionImage(img)
        dilate = morphologyData(img_erosion)
        
        #FilterImageforCutthresh
        img_filter,img_orig =filter_colors(img_erosion,datacolor_red)
        
        #copyOrigImageBeforeDraw
        imgcontour = copyImage(img_filter)
        imgcontour2 = copyImage(img_filter)
        imgcontour3 = copyImage(img_filter)
        imgcontour4 = copyImage(img_filter)

        #detec point in img
        img_eiei,x_point,y_point,xaxis,yaxis = FindCon(imgcontour,x_point,y_point)

        #Find zone are point and chnage it to dic lib
        ALLDATA_HAND = FindZone_Point(xaxis,yaxis)
        DATA_dic = DatatoDic("DATA_Left_Zone","DATA_Right_Zone","HAND",ALLDATA_HAND)
        
        #FindMaxmin data in xy point


        #Cropimage for Process data
        if DATA_dic["HAND"] == "Left-Hand":
            Max_x,Min_x,Cen_data_X = find_Max_Min(xaxis)
            Max_y,Min_y,Cen_data_Y = find_Max_Min(yaxis)
            #find max min area for crop image
            Img_Focus_Hand= CropImage(Min_y,Max_y,Min_x,Max_x,imgcontour2)
            #crop image in x y axis only hand
            IMGCrop = CropImage(Min_y,Max_y,Min_x,int(Cen_data_X),imgcontour2)
            #this is !IMGCrop   it is at thrump finger
            IMG_thrump = CropImage(Min_y,Max_y,int(Cen_data_X)+50,Max_x,imgcontour3)
            
            #find contour area and draw contour and find degree of geometyy
            img_ori,xcrop,ycrop,xaxiscrop,yaxiscrop = FindCon(IMGCrop,xcrop,ycrop)
            
            #Find contour area and draw contour and find dreegree of geomerty in thump
            img_ori2,imgFull= FindCon2(IMG_thrump,xcrop,ycrop,Min_y,Max_y,int(Cen_data_X)+50,Max_x,imgcontour4)
            
            #last step to draw image in joint and convert it in to Real image
            dataxhull,datayhull,MaxJointx,MaxJointy,jointda,imgDraw,imgDrawJoint,imgbeforecut,ori_img,imgFull =DrawImageHand(img_ori,xaxiscrop,yaxiscrop,xcrop,ycrop,imgFull,Min_y,Min_x)
        



        else :
            print("RIGHTHAND")
            #flip image for get image same condition in left hand

            imgcontour2=cv2.flip(imgcontour2,1)
            imgcontour3=cv2.flip(imgcontour3,1)

            #find max min are for crop image
            Max_x,Min_x,Cen_data_X = find_Max_Min(xaxis)
            Max_y,Min_y,Cen_data_Y = find_Max_Min(yaxis)
            #crop image in x y axis only hand
            Img_Focus_Hand= CropImage(Min_y,Max_y,Max_x,Min_x,imgcontour2)
            IMGCrop = CropImage(Min_y,Max_y,Min_x-50,int(Cen_data_X),imgcontour2)
            #this is !IMGCrop   it is at thrump finger

            IMG_thrump = CropImage(Min_y,Max_y,int(Cen_data_X),Max_x,imgcontour3)
            #find contour area and draw contour and find degree of geometyy

            img_ori2,imgFull= FindCon3(IMG_thrump,xcrop,ycrop,Min_y,Max_y,int(Cen_data_X),Max_x,imgcontour4)
            #Find contour area and draw contour and find dreegree of geomerty in thump

            img_ori,xcrop,ycrop,xaxiscrop,yaxiscrop = FindCon(IMGCrop,xcrop,ycrop)
            #last step to draw image in joint and convert it in to Real image

            dataxhull,datayhull,MaxJointx,MaxJointy,jointda,imgDraw,imgDrawJoint,imgbeforecut,ori_img,imgFull =DrawImageHand2(img_ori,xaxiscrop,yaxiscrop,xcrop,ycrop,imgFull,Min_y,int(Cen_data_X))


        #output in terminal
#        print ("X point = ",x_point,"\nY point = ",y_point)
#        print ("X axis point = ",xaxis,"\nY axis point = ",yaxis)
#        print ("X axis point  len = ",len(xaxis),"\nY axis point len = ",len(yaxis))
#        print (DATA_dic)
#        print ("CENTER DATA Value = ",Cen_data_X)
#        print (" Ymin = ",IMGCrop.shape[0])
#        print (" xmin = ",IMGCrop.shape[1])

        args = vars(ap.parse_args())

        if args["showresult"]:
            #plot data in matplotlib
            fig.add_subplot(rows, columns, 1)
            plt.imshow(orig)
            fig.add_subplot(rows, columns, 2)
            plt.imshow(imgcontour)
            fig.add_subplot(rows, columns, 3)
            plt.imshow(img_filter)
            fig.add_subplot(rows, columns, 4)
            plt.imshow(img_erosion)
            fig.add_subplot(rows, columns, 5)
            plt.plot(x_point,y_point, 'ro')
            plt.axis([0,450,450,100])
            fig.add_subplot(rows, columns, 6)
#            plt.imshow(Img_Focus_Hand)
#            fig.add_subplot(rows, columns, 7)
            plt.imshow(imgDraw)
            fig.add_subplot(rows, columns, 7)
            plt.imshow(IMGCrop)
            plt.show()
#
            for i in range(0,4):
                cv2.line(IMGCrop,(0,int(IMGCrop.shape[0]/4)*i),(188,int(IMGCrop.shape[0]/4)*i),(255,0,0),1)
##            imgcontour=cv2.flip(imgcontour,1)
##            IMGCrop=cv2.flip(IMGCrop,1)
##            imgDraw=cv2.flip(imgDraw,1)
##            imgDrawJoint=cv2.flip(imgDrawJoint,1)
##            imgbeforecut=cv2.flip(imgbeforecut,1)
            cv2.imshow("IMAGEMAIN",orig)
            cv2.imshow("IMAGEAFTERCUT ",IMGCrop)
            cv2.imshow("IMAGECONVEX",imgDraw)
            cv2.imshow("IMAGEDRAWJOINT",imgDrawJoint)
            cv2.imshow("IMGBEFORECUT ",imgbeforecut)
            cv2.imshow("THRUMP",IMG_thrump)
            cv2.imshow("IMGFULLFINDJOINT",imgFull)

#save image
#            cv2.imwrite('./Result/ImageMain'+DATA_dic["HAND"]+'.jpg',orig)
#            cv2.imwrite('./Result/ImageCrop'+DATA_dic["HAND"]+'.jpg',IMGCrop)
#            cv2.imwrite('./Result/ImageDraw'+DATA_dic["HAND"]+'.jpg',imgDraw)
#            cv2.imwrite('./Result/ImageDrawJoint'+DATA_dic["HAND"]+'.jpg',imgDrawJoint)
#            cv2.imwrite('./Result/Imagebeforecut'+DATA_dic["HAND"]+'.jpg',imgbeforecut)
#            cv2.imwrite('./Result/Img_thrump'+DATA_dic["HAND"]+'.jpg',IMG_thrump)
#            cv2.imwrite('./Result/ImageFULL'+DATA_dic["HAND"]+'.jpg',imgFull)

            if cv2.waitKey(0) & 0xFF == ord('q'):
                break

    cv2.destroyAllWindows()



