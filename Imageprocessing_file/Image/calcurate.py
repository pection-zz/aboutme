
WorldCoor_X,WorldCoor_Y = 0,0
Size_Image_Real_X = 20 #cm
Size_Image_Real_Y = 15 #cm
Pixel_Max_X = 640 
Pixel_Max_Y = 480
Pixel_Image_X = 265
Pixel_Image_Y = 283
Start_X = 300
Start_y = 94 
Pixel_Per_CM_X = Size_Image_Real_X/Pixel_Image_X
Pixel_Per_CM_Y = Size_Image_Real_Y/Pixel_Image_Y
New_Start_X =250
New_Start_Y =50
Imagesize_IN_Camera = [Pixel_Per_CM_X*Pixel_Image_X,Pixel_Per_CM_Y*Pixel_Image_Y]
Move_CM=[(Start_X-New_Start_X)*Pixel_Per_CM_X,(Start_y-New_Start_Y)*Pixel_Per_CM_Y]
WorldCoor_X=(Start_X-New_Start_X)
WorldCoor_Y=(Start_y-New_Start_Y)
print (Imagesize_IN_Camera)
print ("MOVE AXIS X =",Move_CM[0],"CM")
print ("MOVE AXIS Y =",Move_CM[1],"CM")
print ("World Coordinate Axis X After Move = ",WorldCoor_X)
print ("World Coordinate Axis Y After Move = ",WorldCoor_Y)