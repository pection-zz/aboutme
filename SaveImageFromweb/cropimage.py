import cv2
import os
import sys
import numpy as np
from PIL import Image
num=1
path ="//Users/pection/Documents/Crop/"
#we shall store all the file names in this list
filelist=[]
for root, dirs, files in os.walk(path):
    for file in files:
        if(file.endswith(".png")):
            filelist.append(os.path.join(root,file))
print (filelist)
# logo=Image.open('logo.png')
# logo2=Image.open('logo2.png')
# watermark = Image.open('WatermarkB5.png')
# watermark2 = Image.open('WatermarkB3.png')
#
# logoWidth = watermark.width
# logoHeight = watermark.height
# watermarkW=watermark.width
# watermarkH=watermark.height
# logo2Width = watermark2.width
# logo2Height = watermark2.height
for filename in filelist:
    img = cv2.imread(filename,-1)
    crop_img = img[40:450, 40:450]
    cv2.imwrite(filename,crop_img)
