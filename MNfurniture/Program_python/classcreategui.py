import PySimpleGUI as sg

sg.theme('DarkAmber')   # Add a touch of color


# All the stuff inside your window.
class CreateGui:
    def __intit__(self):
        self.Data_template=['Name','Phone','Address','Order','Delivery','Price','Value','Discount','Deposit','Remain']
    def CreateTablegui(self,Datatemplate):
        self.layoutdata = []
        for i in range(len(self.Datatemplate)):
            self.layoutdata.append([sg.Text(self.Datatemplate[i]), sg.InputText()])
        self.layoutdata.append([sg.Button('Ok'), sg.Button('Cancel')])
        return self.layoutdata
    def changedicttolist(self,listofdict):
        self.listvalues=[]
        for valuefrombill in listofdict.values():
            self.listvalues.append(valuefrombill)
        return self.listvalues

Mikeclass=CreateGui()
print(Mikeclass.Data_template)
layout=Mikeclass.CreateTablegui(Mikeclass.Data_template)
window = sg.Window('Billing Address',layout)
# Event Loop to process "events" and get the "values" of the inputs
while True:
    event, values = window.read()
#    window.Element('_LISTBOX_').Update(values=Datatemplate)
    if event == sg.WIN_CLOSED or event == 'Cancel' or event == 'Ok': # if user closes window or clicks cancel
        window.close()
        break


listofvalues=Mikeclass.changedicttolist(values)
Data = dict(zip(Data_template,listofvalues))
print (Data)
