import os
import sys
import numpy as np
import argparse
from PIL import Image
parser = argparse.ArgumentParser(description='This is fill address bill script')

parser.add_argument('-i','--in',action='store',dest='inputimg',default=None,help='<Required>Path',required=True)
results = parser.parse_args()
imgpath = results.input
filelist=[]
for root, dirs, files in os.walk(imgpath):
    for file in files:
        if(file.endswith(".png") or file.endswith(".jpg)):
            filelist.append(os.path.join(root,file))
print (filelist)
Template=Image.open('/Users/pection/Programing/aboutme/MNfurniture/Bill/Template/TemplatePython.png')
TemplateEdit=Template.copy()
for filename in Imagelist:
    Item = Image.open(filename)
    TemplateEdit.paste(Item,(100,370,Item))
TemplateEdit.save('/Users/pection/Programing/aboutme/MNfurniture/Bill/PretoPaid/Bill.png)

