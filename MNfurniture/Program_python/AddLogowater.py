import os
import sys
import numpy as np
import argparse
from PIL import Image
num=1
image_urls=[]
parser = argparse.ArgumentParser(description='This is Add Logo script')
parser.add_argument('-i','--in',action='store',dest='input',default=None,help='<Required>image path',required=True)
results = parser.parse_args()
imgpath = results.input
#we shall store all the file names in this list
filelist=[]
for root, dirs, files in os.walk(imgpath):
    for file in files:
        if(file.endswith(".jpg") or file.endswith(".png")):
            filelist.append(os.path.join(root,file))
print (filelist)
logo=Image.open('/Users/pection/Programing/aboutme/MNfurniture/static/image/logo.png')
logo2=Image.open('/Users/pection/Programing/aboutme/MNfurniture/static/image/logo2.png')
watermark = Image.open('/Users/pection/Programing/aboutme/MNfurniture/static/image/WatermarkWo4.png')
# watermark2 = Image.open('/Users/pection/Programing/aboutme/MNfurniture/static/image/WatermarkWo4.png')

logoWidth = watermark.width
logoHeight = watermark.height
watermarkW=watermark.width
watermarkH=watermark.height
# watermark2W = watermark2.width
# watermark2 = watermark2.height
for filename in filelist:
    image = Image.open(filename)
    imageWidth = image.width
    imageHeight = image.height
    if imageWidth<500 :
        img_w, img_h = image.size
        bg_w, bg_h = watermark.size
        # offset = ((bg_w - img_w) // 2, (bg_h - img_h) // 2)
        # image.paste(logo2, (0, 0), logo2)
        image2=image.copy()
        image2.paste(watermark,(int((img_w-watermarkW)/2),int((img_h-watermarkH)/2)),watermark)
    else :
        img_w, img_h = image.size
        bg_w, bg_h = watermark.size
        # offset = ((bg_w - img_w) // 2, (bg_h - img_h) // 2)
        # image.paste(logo2, (0, 0), logo2)
        image2=image.copy()
        image2.paste(watermark,(int((img_w-watermarkW)/2),int((img_h-watermarkH)/2)),watermark)
    num += 1
    image2.save(filename)
    # image.save('/Users/pection/Programing/aboutme/MNfurniture/static/ExtractFolderImage/'+str(num)+'.png')
