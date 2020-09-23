import PySimpleGUI as sg

sg.theme('DarkAmber')   # Add a touch of color


# All the stuff inside your window.
Data_template=['PhotoPath','Name','Phone','Address','Order','Delivery','Price','Value','Discount','Deposit','Remain']
def CreateTablegui(Datatemplate):
    layoutdata = []
    for i in range(len(Datatemplate)):
        layoutdata.append([sg.Text(Datatemplate[i]), sg.InputText()])
    layoutdata.append([sg.Button('Ok'), sg.Button('Cancel')])
    return layoutdata
def changedicttolist(listofdict):
    listvalues=[]
    for valuefrombill in listofdict.values():
        listvalues.append(valuefrombill)
    return listvalues

# layout=CreateTablegui(Data_template)
# window = sg.Window('Billing Address',layout)
# Event Loop to process "events" and get the "values" of the inputs
# while True:
#     event, values = window.read()
# #    window.Element('_LISTBOX_').Update(values=Datatemplate)
#     if event == sg.WIN_CLOSED or event == 'Cancel' or event == 'Ok': # if user closes window or clicks cancel
#         window.close()
#         break
#
#
# listofvalues=changedicttolist(values)
# Data = dict(zip(Data_template,listofvalues))
# print (Data)
