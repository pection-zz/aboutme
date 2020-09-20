from tkinter import *
root = Tk()
a = "THRESHOLD_MASK"
b = "0"
def Threshold1():
    global a
    a="THRESHOLD_MASK"
r1=Radiobutton(root, text="THRESHOLD_MASK", variable=a, value="THRESHOLD_MASK",command=Threshold1)
def Threshold2():
    global a
    a="THRESHOLD_GRAY_MASK"
r2=Radiobutton(root, text="THRESHOLD_GRAY_MASK", variable=a, value="THRESHOLD_GRAY_MASK",command=Threshold2)
def Threshold3():
    global a
    a="BACKPROSECTION_MASK"
r3=Radiobutton(root, text="BACKPROSECTION_MASK", variable=a, value="BACKPROSECTION_MASK",command=Threshold3)
r1.select()
r2.select()
r3.select()
r1.pack(anchor=W)
r2.pack(anchor=W)
r3.pack(anchor=W)
L1 = Label(root, text="Choose Camera")
L1.pack( )
E1 = Entry(root, bd =5)
E1.pack()
def Print():
    global a
    global b
    print(a)
    b=E1.get()
    print(b)
frame = Frame(root)
frame.pack()
q = Button(frame, text="QUIT", fg="red", command=frame.quit)
q.pack(side=RIGHT)
hi = Button(frame, text="LUNCH",command=Print)
hi.pack(side=RIGHT)
mainloop()
