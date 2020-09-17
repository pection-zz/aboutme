
# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'classprofile1.ui'
#
# Created by: PyQt4 UI code generator 4.11.4
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui
import matplotlib
from Realtime_Server import Databaze_2
import matplotlib.pyplot as plt
import matplotlib.pyplot
import random
import MySQLdb
import time
try:
    _fromUtf8 = QtCore.QString.fromUtf8
except AttributeError:
    def _fromUtf8(s):
        return s

try:
    _encoding = QtGui.QApplication.UnicodeUTF8
    def _translate(context, text, disambig):
        return QtGui.QApplication.translate(context, text, disambig, _encoding)
except AttributeError:
    def _translate(context, text, disambig):
        return QtGui.QApplication.translate(context, text, disambig)

class Classprofile(object):
    sub = ""





    def monthToNum(self,shortMonth):

        return{'Jan' : 1,'Feb' : 2,'Mar' : 3,'Apr' : 4,'May' : 5,'Jun' : 6, 'Jul' : 7,'Aug' : 8,'Sep' : 9, 'Oct' : 10,'Nov' : 11,'Dec' : 12}[shortMonth]


    def setupUi(self, MainWindow,subj,PythonicDate,PythonicTime):

        self.sub = "FRA"+str(subj)
        MainWindow.setObjectName(_fromUtf8("MainWindow"))
        MainWindow.setFixedSize(280, 650)
        #MainWindow.setFixedSize(280, 430)
        self.centralwidget = QtGui.QWidget(MainWindow)
        self.centralwidget.setObjectName(_fromUtf8("centralwidget"))
        self.bg = QtGui.QLabel(self.centralwidget)
        self.bg.setGeometry(QtCore.QRect(0, 0, 280, 650))
        self.bg.setText(_fromUtf8(""))
        self.bg.setPixmap(QtGui.QPixmap(_fromUtf8("teacherBackground_6")))
        self.bg.setObjectName(_fromUtf8("bg"))
        # this is the Canvas Widget that displays the `figure`
        # it takes the `figure` instance as a parameter to __init__
        self.ok = QtGui.QPushButton(self.centralwidget)
        self.ok.setGeometry(QtCore.QRect(200, 370, 50, 20))
        self.ok.setObjectName(_fromUtf8("ok"))
        self.timeEdit = QtGui.QTimeEdit(self.centralwidget)
        self.timeEdit.setGeometry(QtCore.QRect(180, 75, 70, 20))
        self.timeEdit.setLocale(QtCore.QLocale(QtCore.QLocale.Tagalog, QtCore.QLocale.Philippines))
        self.timeEdit.setObjectName(_fromUtf8("timeEdit"))
        self.timeEdit.setTime(QtCore.QTime.fromString(PythonicTime, 'hh:mm:ss'))
        self.graph = QtGui.QLabel(self.centralwidget)

        self.graph.setGeometry(QtCore.QRect(15, 420, 250, 200))
        #self.graph.setStyleSheet("color:black;font-size: 9pt;border: white")
        self.graph.setPixmap(QtGui.QPixmap(_fromUtf8("graph.png")))
        self.graph.setObjectName(_fromUtf8("graph"))
        self.label_3 = QtGui.QLabel(self.centralwidget)
        self.label_3.setGeometry(QtCore.QRect(220-50, 120, 121, 20))
        self.label_3.setObjectName(_fromUtf8("label_3"))
        self.back = QtGui.QPushButton(self.centralwidget)
        self.back.setGeometry(QtCore.QRect(20, 370, 50, 20))
        self.back.setObjectName(_fromUtf8("back"))
        self.pri = QtGui.QPushButton(self.centralwidget)
        self.pri.setGeometry(QtCore.QRect(140, 370, 50, 20))
        self.pri.setObjectName(_fromUtf8("print"))
        self.label_4 = QtGui.QLabel(self.centralwidget)
        self.label_4.setGeometry(QtCore.QRect(20, 80, 46, 13))
        self.label_4.setObjectName(_fromUtf8("label_4"))
        self.label_5 = QtGui.QLabel(self.centralwidget)
        self.label_5.setGeometry(QtCore.QRect(145, 75 , 46, 20))
        self.label_5.setObjectName(_fromUtf8("label_5"))
        self.dateEdit = QtGui.QDateEdit(self.centralwidget)
        self.dateEdit.setGeometry(QtCore.QRect(50, 75, 80, 20))
        self.dateEdit.setLocale(QtCore.QLocale(QtCore.QLocale.English, QtCore.QLocale.UnitedStates))
        self.dateEdit.setObjectName(_fromUtf8("dateEdit"))
        self.dateEdit.setDate(QtCore.QDate.fromString(PythonicDate, 'yyyy-MM-dd'))
        self.comboBox = QtGui.QLabel(self.centralwidget)
        self.comboBox.setGeometry(QtCore.QRect(20, 40, 100, 40))
        self.comboBox.setObjectName(_fromUtf8("comboBox"))
        self.progressBar = QtGui.QProgressBar(self.centralwidget)
        self.progressBar.setGeometry(QtCore.QRect(120, 100, 140, 20))
        self.progressBar.setProperty("value", 24)
        self.progressBar.setObjectName(_fromUtf8("progressBar"))
        self.progressBar.setValue(0)
        self.label = QtGui.QLabel(self.centralwidget)
        self.label.setGeometry(QtCore.QRect(20, 100, 100, 20))
        self.label.setObjectName(_fromUtf8("label"))
        self.header = QtGui.QLabel(self.centralwidget)
        self.header.setGeometry(QtCore.QRect(20, 30, 150, 20))
        self.header.setObjectName(_fromUtf8("header"))
        self.lineEdit = QtGui.QTextEdit(self.centralwidget)
        self.lineEdit.setGeometry(QtCore.QRect(20, 160, 230, 200))
        self.lineEdit.setObjectName(_fromUtf8("lineEdit"))
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtGui.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 346, 21))
        self.menubar.setObjectName(_fromUtf8("menubar"))
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtGui.QStatusBar(MainWindow)
        self.statusbar.setObjectName(_fromUtf8("statusbar"))
        MainWindow.setStatusBar(self.statusbar)
        self.label.setStyleSheet("color: white;font-size: 9pt;border: white")
        self.label_3.setStyleSheet("color: white;font-size: 9pt;border: white")
        self.label_4.setStyleSheet("color: white;font-size: 9pt;border: white")
        self.label_5.setStyleSheet("color: white;font-size: 9pt;border: white")
        self.comboBox.setStyleSheet("color: white;font-size: 9pt;border: white")
        self.header.setStyleSheet("color: white;font-size: 13pt;border: white")
        self.ok.setStyleSheet("background-color: green;color: white;font-size: 9pt;border: white")
        self.pri.setStyleSheet("background-color: green;color: white;font-size: 9pt;border: white")
        self.back.setStyleSheet("background-color: green;color: white;font-size: 9pt;border: white")

        lis = self.func()
        ret = lis[0]
        tim = lis[1]
        qq = lis[2]
        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)
        newdatabase = Databaze_2()
        l = newdatabase.callClick(t=ret,sid=self.sub[3:],hr=int(tim[:2]))

        l2 = newdatabase.Oneshot(t=ret,sid=self.sub[3:],time=float(str(tim)[:5].replace(":",".")))
        self.progressBar.setValue(l2[2])
        self.label_3.setText(_translate("MainWindow", "amount "+str(l2[0])+" / "+str(int(l2[0]+l2[1])), None))
        lis = [[],[]]
        i = 0
        for a in l:
            lis[0].append(a[2])
            i+=1
            lis[1].append(a[3])
        lisx = []
        for e in lis[1]:
            ee = float(e)
            lisx.append(((1.0/0.6)*(ee-int(ee)))+int(ee))
        lis[1] = lisx
        self.plot(lis)

        return (ret,tim,qq)


    def func(self):
        # เอา date มาใส่ด
        temp_var = self.dateEdit.date()
        date = temp_var.toPyDate()
        tam =  self.timeEdit.time()
        tam = tam.toPyTime()
        if int(str(tam)[:2]) > 13:
            timee = 1
        else:
            timee = 0
        newdatabase = Databaze_2()
        ques = newdatabase.allQuestion(self.sub[3:],date,timee)
        self.lineEdit.setText(_translate("MainWindow", ques, None))
        return (str(self.dateEdit.date().toPyDate()),str(self.timeEdit.time().toPyTime()),ques)



    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow", None))
        self.ok.setText(_translate("MainWindow", "OK", None))
        self.pri.setText(_translate("MainWindow", "Print", None))

        self.back.setText(_translate("MainWindow", "back", None))
        self.label_4.setText(_translate("MainWindow", "Date", None))
        self.label_5.setText(_translate("MainWindow", "Time", None))
        self.comboBox.setText(_translate("MainWindow", "Subject : "+self.sub, None))
        self.label.setText(_translate("MainWindow", "Understand(%)", None))
        self.header.setText(_translate("MainWindow", "Class Stat", None))

    def plot(self,lis):
        font = {'family' : 'normal',
        'size'   : 7}

        matplotlib.rc('font', **font)

        figg = matplotlib.pyplot.figure(figsize=(2.50,2.00))

        y = []
        x= []
        a = 50
        for i in range(0,200):
            x.append(i)
            a+= random.randrange(-10,10)
            y.append(a)
        figg.add_subplot(111).plot(lis[1],lis[0],'w-')
        figg.add_subplot(111).grid(True)
        figg.savefig("graph.png", facecolor='#00a022', transparent=True,edgecolor='green')
        self.graph.setPixmap(QtGui.QPixmap(_fromUtf8("graph.png")))

        #plt.plot([1,2,3,4,5],[3,4,8,2,1],'r--')
        #plt.savefig("graph.png",figg)
        #plt.show()


if __name__ == "__main__":
    import sys
    app = QtGui.QApplication(sys.argv)
    MainWindow = QtGui.QMainWindow()
    ui = Classprofile()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())

