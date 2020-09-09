import os
import sys
import numpy as np
from PIL import Image
num=1
path ="/Users/pection/Documents/mn_furniture/AddwatermarkProgram/imagess/"
#we shall store all the file names in this list
filelist=[]
for root, dirs, files in os.walk(path):
    for file in files:
        if(file.endswith(".jpg")):
            filelist.append(os.path.join(root,file))
print (filelist)
logo=Image.open('logo.png')
logo2=Image.open('logo2.png')
watermark = Image.open('WatermarkB5.png')
watermark2 = Image.open('WatermarkB3.png')

logoWidth = watermark.width
logoHeight = watermark.height
watermarkW=watermark.width
watermarkH=watermark.height
logo2Width = watermark2.width
logo2Height = watermark2.height
for filename in filelist:
    # image = Image.open(filename)
    # imageWidth = image.width
    # imageHeight = image.height
    # if imageWidth<500 :
    #     img_w, img_h = image.size
    #     bg_w, bg_h = watermark2.size
    #     offset = ((bg_w - img_w) // 2, (bg_h - img_h) // 2)
    #     image.paste(logo2, (0, 0), logo2)
    #     image2=image.copy()
    #     image2.paste(watermark2,(int((img_w-logo2Width)/2),int((img_h-logo2Height)/2)),watermark2)
    # else :
    #     img_w, img_h = image.size
    #     bg_w, bg_h = watermark.size
    #     offset = ((bg_w - img_w) // 2, (bg_h - img_h) // 2)
    #     image.paste(logo, (0, 0), logo)
    #     image2=image.copy()
    #     image2.paste(watermark,(int((img_w-logoWidth)/2),int((img_h-logoHeight)/2)),watermark)
    num += 1
    image2.save(filename)
    # image.save('/Users/pection/Documents/mn_furniture/AddwatermarkProgram/New/'+str(num)+'.png')