import PySimpleGUI as sg

sg.theme('DarkAmber')   # Add a touch of color
# All the stuff inside your window.
layout = [  [sg.Text('Name'), sg.InputText()],
            [sg.Text('Phone'), sg.InputText()],
            [sg.Text('Address'), sg.InputText()],
            [sg.Text('Order'), sg.InputText()],
            [sg.Text('Delivery'), sg.InputText()],
            [sg.Text('Price'), sg.InputText()],
            [sg.Text('Value'), sg.InputText()],
            [sg.Text('Discount'), sg.InputText()],
            # [sg.Text('ValueAfterPromotoin'), sg.InputText()],
            # [sg.Text('Summary'), sg.InputText()],
            [sg.Text('Deposit'), sg.InputText()],
            [sg.Text('Remain'), sg.InputText()],
            [sg.Button('Ok'), sg.Button('Cancel')] ]

# Create the Window
window = sg.Window('Window Title', layout)
# Event Loop to process "events" and get the "values" of the inputs
while True:
    event, values = window.read()
    if event == sg.WIN_CLOSED or event == 'Cancel': # if user closes window or clicks cancel
        break
    print('You entered ', values[0])

window.close()
