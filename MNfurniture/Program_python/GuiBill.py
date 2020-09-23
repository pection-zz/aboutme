import PySimpleGUI as sg
from creategui import changedicttolist ,CreateTablegui,Data_template
from resizefill import resize,xyaxis
import cv2
from PIL import ImageFont, ImageDraw, Image
import tldextract

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

Data_template=['PhotoPath','Name','Phone','Address','Order','Delivery','Price','Value','Discount','Deposit','Remain']

imgdefault=cv2.imread(Data["PhotoPath"])
img = resize(image=imgdefault,width=200,height=200)


template=cv2.imread("/Users/pection/Programing/aboutme/MNfurniture/Bill/Template/TemplateBill.jpg")
template[y_offset:y_offset+img.shape[0], x_offset:x_offset+img.shape[1]] = img

cv2.imwrite("/Users/pection/Programing/aboutme/MNfurniture/Bill/PretoPaid/Pretopaid.jpg",template)
image = Image.open("/Users/pection/Programing/aboutme/MNfurniture/Bill/PretoPaid/Pretopaid.jpg")
draw = ImageDraw.Draw(image)

for item in Data:
    for key, value in item.iteritems():
        try:
            item[key] = int(value)
        except ValueError:
            item[key] = float(value)

font = ImageFont.truetype("/System/Library/Fonts/HelveticaNeue.ttc", 13)
draw.text((xyaxis["x_value"],xyaxis["y_value"]),Data["Value"], font=font,fill=(0,0,0,0))
draw.text((xyaxis["x_discount"],xyaxis["y_discount"]),Data["Discount"], font=font,fill=(0,0,0,0))
draw.text((xyaxis["x_price"],xyaxis["y_price"]),Data["Price"], font=font,fill=(0,0,0,0))
draw.text((xyaxis["x_priceafterdiscount"],xyaxis["y_priceafterdiscount"]),Data["Price"], font=font,fill=(0,0,0,0))

print(Data["Price"])
image.save("/Users/pection/Programing/aboutme/MNfurniture/Bill/PretoPaid/Pretopaid2.jpg")
