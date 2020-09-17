# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'question.ui'
#
# Created by: PyQt4 UI code generator 4.11.4
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui
from PyQt4.QtGui import QDialog
from PyQt4.QtCore import SIGNAL
import time
from Server import Databaze

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

class Ui_MainWindowQuestion(QDialog):
    textEdit = 0
    ClassID = 241001
    StuID = 58340500051

    def setupUi(self, MainWindow):
        MainWindow.setObjectName(_fromUtf8("MainWindow"))
        MainWindow.setFixedSize(300, 200)
        self.ques_table = Databaze(server='10.61.3.223',username='2016FRA241G5',password='SzTGde9E9AxVaNXA',database='2016FRA241G5',use_unicode=True)

        self.centralwidget = QtGui.QWidget(MainWindow)
        self.centralwidget.setObjectName(_fromUtf8("centralwidget"))
        self.bg = QtGui.QLabel(self.centralwidget)
        self.bg.setGeometry(QtCore.QRect(0, 0, 300, 200))
        self.bg.setText(_fromUtf8(""))
        self.bg.setPixmap(QtGui.QPixmap(_fromUtf8("bg5")))
        self.bg.setObjectName(_fromUtf8("bg"))
        self.textEdit = QtGui.QLineEdit(self.centralwidget)

        self.textEdit.setGeometry(QtCore.QRect(50, 50, 200, 80))
        self.textEdit.setObjectName(_fromUtf8("textEdit"))
        self.textEdit.setStyleSheet("background-color: white; color: blue;font-size: 15pt")
        #self.label = QtGui.QLabel(self.centralwidget)
        #self.label.setGeometry(QtCore.QRect(90, 70, 53, 16))
        #self.label.setObjectName(_fromUtf8("label"))
        self.Sendbutton = QtGui.QPushButton(self.centralwidget)
        self.Sendbutton.setGeometry(QtCore.QRect(200, 150, 93, 28))
        self.Sendbutton.setObjectName(_fromUtf8("Sendbutton"))
        self.Sendbutton.setStyleSheet("background-color: blue; color: white;font-size: 14pt")
        self.connect(self.Sendbutton, SIGNAL("clicked()"),self.button_click)
        MainWindow.setCentralWidget(self.centralwidget)
        self.statusbar = QtGui.QStatusBar(MainWindow)
        self.statusbar.setObjectName(_fromUtf8("statusbar"))
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def button_click(self):

        texy = unicode(self.textEdit.text()).encode('utf-8')
        f = open("test.txt",'w')
        f.write(texy)
        f.close()
        print texy
        click_id = self.ques_table.SELECT_MAX(table="Question Table",column="Question ID")[0][0]
        datetime = time.asctime( time.localtime(time.time())) #Tue Nov 08 12:41:18 2016
        datetime = datetime[20:24]+"-"+str(self.ques_table.monthToNum(datetime[4:7]))+"-"+datetime[8:10]+" "+datetime[11:19]
        if click_id is None:
            click_id  = 0
        else:
            click_id += 1
        self.ques_table.ADD(table='Question Table',column=['Question ID','Class ID','Student ID','Question','Vote','Seen','time'],value=[str(click_id),str(self.ClassID),str(self.StuID),texy,0,0,datetime])
        self.lastdatetime = datetime
        self.textEdit.setText("")

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow", None))
        #self.label.setText(_translate("MainWindow", "Question", None))
        self.Sendbutton.setText(_translate("MainWindow", "Send",None))



if __name__ == "__main__":
    import sys
    app = QtGui.QApplication(sys.argv)
    MainWindow = QtGui.QMainWindow()
    ui = Ui_MainWindowQuestion()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())

