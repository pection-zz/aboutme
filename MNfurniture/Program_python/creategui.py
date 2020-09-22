import PySimpleGUI as sg

sg.theme('DarkAmber')   # Add a touch of color
layoutdata =[]
# All the stuff inside your window.
Datatemplate=['Name','Phone','Address','Order','Delivery','Price','Value','Discount','Deposit','Remain']
for i in range(len(Datatemplate)):
    layoutdata.append([sg.Text(Datatemplate[i]), sg.InputText()])
layoutdata.append([sg.Button('Ok'), sg.Button('Cancel')])

window = sg.Window('Billing Address',layoutdata)
# Event Loop to process "events" and get the "values" of the inputs
while True:
    event, values = window.read()
    window.Element('_LISTBOX_').Update(values=Datatemplate)
    if event == sg.WIN_CLOSED or event == 'Cancel': # if user closes window or clicks cancel
        break

    # for key , value in values.iteritems():
        # temp =[key,value]
        # dictlist.append(value)
# window.Close()
    Data = dict(zip(Datatemplate,values))
    print (values)
#     Data ={ 'Name': values[0],
#     'Phone':values[1],
#     'Address':values[2],
#     'Order': values[3],
#     'Delivery':values[4],
#     'Price':values[5],
#     'Discount':values[6],
#     'Deposit':values[7],
#     'Remain':values[8]
#     }
#     for datas in Data:
#         print(datas)
window.close()
