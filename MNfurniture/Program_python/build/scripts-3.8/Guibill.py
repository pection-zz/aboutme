import PySimpleGUI as sg
from creategui import changedicttolist ,CreateTablegui,Data_template
from resizefill import resize,xyaxis
import cv2
from PIL import ImageFont, ImageDraw, Image
import tldextract
Data_template=['PhotoPath','Name','Phone','Address','Order','Delivery','Delivery2','Price','Value','Discount','Deposit']
watermark = Image.open('/Users/pection/Programing/aboutme/MNfurniture/Bill/Template/PAID.png')

sg.theme('DarkAmber')
x_offset=100
y_offset=350
layout=CreateTablegui(Data_template)
window = sg.Window('Billing Address',layout)
# Event Loop to process "events" and get the "values" of the inputs
while True:
    event, values = window.read()
#    window.Element('_LISTBOX_').Update(values=Datatemplate)
    if event == sg.WIN_CLOSED or event == 'Cancel' or event == 'Ok': # if user closes window or clicks cancel
        window.close()
        break
listofvalues=changedicttolist(values)
Data = dict(zip(Data_template,listofvalues))

if(len(Data["PhotoPath"]))<5:
    Data["PhotoPath"]="/Users/pection/Programing/aboutme/MNfurniture/Bill/Template/48848.jpg"
if(len(Data["Discount"]))<5:
    Data["Discount"]=0
if(len(Data["Phone"]))<5:
    Data["Phone"]="xxx-xxx-xxxx"
if(len(Data["Name"]))<5:
    Data["Name"]="xxx"
if(len(Data["Value"]))<1:
    Data["Value"]=1

imgdefault=cv2.imread(Data["PhotoPath"])
img = resize(image=imgdefault,width=200,height=200)


template=cv2.imread("/Users/pection/Programing/aboutme/MNfurniture/Bill/Template/TemplateBill.jpg")
template[y_offset:y_offset+img.shape[0], x_offset:x_offset+img.shape[1]] = img

cv2.imwrite("/Users/pection/Programing/aboutme/MNfurniture/Bill/PretoPaid/Pretopaid.jpg",template)
image = Image.open("/Users/pection/Programing/aboutme/MNfurniture/Bill/PretoPaid/Pretopaid.jpg")
draw = ImageDraw.Draw(image)


font=ImageFont.truetype("/Library/Fonts/Arial Unicode.ttf",13)
font2=ImageFont.truetype("/Library/Fonts/Arial Unicode.ttf",11)
Summaryvalue=(int((Data["Price"]))*int((Data["Value"])))-int((Data["Discount"]))
RemainValue=Summaryvalue-int((Data["Deposit"]))

draw.text((xyaxis["x_name"],xyaxis["y_name"]),Data["Name"]+"  ("+Data["Phone"]+")", font=font,fill=(0,0,0,0))
draw.text((xyaxis["x_address"],xyaxis["y_address"]),Data["Address"], font=font,fill=(0,0,0,0))
draw.text((xyaxis["x_order"],xyaxis["y_order"]),Data["Order"], font=font,fill=(0,0,0,0))
draw.text((xyaxis["x_delivery"],xyaxis["y_delivery"]),Data["Delivery"]+ " -", font=font2,fill=(0,0,0,0))
draw.text((xyaxis["x_delivery2"],xyaxis["y_delivery2"]),Data["Delivery2"], font=font2,fill=(0,0,0,0))

draw.text((xyaxis["x_value"],xyaxis["y_value"]),Data["Value"], font=font,fill=(0,0,0,0))
draw.text((xyaxis["x_discount"],xyaxis["y_discount"]),Data["Discount"], font=font,fill=(0,0,0,0))
draw.text((xyaxis["x_price"],xyaxis["y_price"]),Data["Price"], font=font,fill=(0,0,0,0))
draw.text((xyaxis["x_priceafterdiscount"],xyaxis["y_priceafterdiscount"]),str(Summaryvalue), font=font,fill=(0,0,0,0))
draw.text((xyaxis["x_summary"],xyaxis["y_summary"]),str(Summaryvalue), font=font,fill=(0,0,0,0))

draw.text((xyaxis["x_deposit"],xyaxis["y_deposit"]),Data["Deposit"], font=font,fill=(0,0,0,0))

draw.text((xyaxis["x_remain"],xyaxis["y_remain"]),str(RemainValue), font=font,fill=(0,0,0,0))


image2=image.copy()
img_w = image2.width
img_h = image2.height
watermarkW=watermark.width
watermarkH=watermark.height
image2.paste(watermark,(int((img_w-watermarkW)/2),int((img_h-watermarkH)/2)),watermark)
image.save("/Users/pection/Programing/aboutme/MNfurniture/Bill/PretoPaid/Pretopaid2.jpg")
image2.save("/Users/pection/Programing/aboutme/MNfurniture/Bill/PretoPaid/Pretopaid2_paid.jpg")
