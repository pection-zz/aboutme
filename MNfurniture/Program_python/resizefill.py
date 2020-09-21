import cv2
import argparse
import tldextract
from PIL import ImageFont, ImageDraw, Image  
import PySimpleGUI as sg

broken_images = []
image_urls=[]
parser = argparse.ArgumentParser(description="This is Resize image  script")
parser.add_argument("-i","--in",action="store",dest="input",default=None,help="<Required>image path",required=True)
parser.add_argument("-o","--out",action="store",dest="output",default="/Users/pection/Programing/aboutme/MNfurniture/Bill/PretoPaid/Pretopaid.jpg",help="<Required>image path",required=False)
parser.add_argument("-wi","--width",action="store",dest="width",default=200,help="<Required>image path",required=False)
parser.add_argument("-hi","--height",action="store",dest="height",default=200,help="<Required>image path",required=False)
results = parser.parse_args()
xyaxis={"x_number":350,"x_price":400,"x_promotion":450,"x_priceafterpromotion":520 ,"x_summary":520,"x_deposit":520,"x_remain":520,"y_number":450,"y_price":450,"y_promotion":450,"y_priceafterpromotion":450,"y_summary":660,"y_deposit":700,"y_remain":750}
x_offset=100
y_offset=350
imgpath = results.input
savepath= results.output
width_image=results.width
height_image=results.height

def resize(image, width = None, height = None, inter = cv2.INTER_AREA):
    # initialize the dimensions of the image to be resized and grab the image size
    dim = None
    (h, w) = image.shape[:2]
    # if both the width and height are None, then return the original image
    if width is None and height is None:
        return image
        # check to see if the width is None
    if width is None:
        # calculate the ratio of the height and construct the dimensions
        r = height / float(h)
        dim = (int(w * r), height)
    # otherwise, the height is None
    else:
        # calculate the ratio of the width and construct the dimensions
        r = width / float(w)
        dim = (width, int(h * r))
    # resize the image
    resized = cv2.resize(image, dim, interpolation = inter)
    # return the resized image
    return resized

imgdefault=cv2.imread(imgpath)
img = resize(image=imgdefault,width=int(width_image),height=int(height_image))
template=cv2.imread("/Users/pection/Programing/aboutme/MNfurniture/Bill/Template/TemplateBill.jpg")
print(width_image,height_image)

template[y_offset:y_offset+img.shape[0], x_offset:x_offset+img.shape[1]] = img
# cv2.putText(
#      template, 
#      "1", 
#      (xyaxis["x_number"],xyaxis["y_number"]),
#      cv2.FONT_HERSHEY_SIMPLEX, 
#      1, (0, 0, 0, 255), 3) 
cv2.imwrite(savepath,template)

# cv2.wait(0)
# if cv2.imwrite(savepath,)
image = Image.open(savepath)  

draw = ImageDraw.Draw(image)  

# use a truetype font  
font = ImageFont.truetype("/System/Library/Fonts/HelveticaNeue.ttc", 13)  

draw.text((xyaxis["x_number"],xyaxis["y_number"]), "1", font=font,fill=(0,0,0,0))  

image.save("/Users/pection/Programing/aboutme/MNfurniture/Bill/PretoPaid/Pretopaid2.jpg")  

