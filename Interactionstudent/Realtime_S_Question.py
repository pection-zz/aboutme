# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'vote.ui'
#
# Created by: PyQt4 UI code generator 4.11.4
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui
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



class Ui_MainWindowVote(object):
    ques_table = 0
    ClassID = 241
    StuID = 58340500051
    Click_table = 0
    lastdatetime = ''
    seen = []

    def __init__(self,Username = None,Cls=None):
        self.StuID = Username
        self.ClassID = Cls

    def setupUi(self, MainWindow,alis):

        MainWindow.setObjectName(_fromUtf8("MainWindow"))
        MainWindow.setFixedSize(400, 250)
        self.centralwidget = QtGui.QWidget(MainWindow)
        self.centralwidget.setObjectName(_fromUtf8("centralwidget"))
        self.bg = QtGui.QLabel(self.centralwidget)
        self.bg.setGeometry(QtCore.QRect(0, 0, 400, 250))
        self.bg.setText(_fromUtf8(""))
        self.bg.setPixmap(QtGui.QPixmap(_fromUtf8("bg3")))
        self.bg.setObjectName(_fromUtf8("bg"))
        self.textEdit = QtGui.QLabel(self.centralwidget)
        #alis = self.ques_table.SELECT(select = "Question",table= "Question Table",column= "Class ID",IS=(self.ClassID),order="Time",reverse=True)
        #alis = self.ques_table.SQL("select `Question ID` FROM `Question Table`;")
        self.textEdit.setGeometry(QtCore.QRect(40, 40, 250, 30))
        self.textEdit.setObjectName(_fromUtf8("textEdit"))

        try:
            self.textEdit.setText(alis[0][1])
        except:
            pass
        self.textEdit.setStyleSheet("background-color: white; color: orange;font-size: 13pt")
        self.textEdit_2 = QtGui.QLabel(self.centralwidget)
        self.textEdit_2.setGeometry(QtCore.QRect(40, 90, 250, 30))
        try:
            self.textEdit_2.setText(alis[1][1])
        except:
            pass
        self.textEdit_2.setStyleSheet("background-color: white; color: orange;font-size: 13pt")
        self.textEdit_2.setObjectName(_fromUtf8("textEdit_2"))
        self.textEdit_3 = QtGui.QLabel(self.centralwidget)
        self.textEdit_3.setGeometry(QtCore.QRect(40, 140, 250, 30))
        self.textEdit_3.setStyleSheet("background-color: white; color: orange;font-size: 13pt")
        self.textEdit_3.setObjectName(_fromUtf8("textEdit_3"))
        try:
            self.textEdit_3.setText(alis[2][1])
        except:
            pass
        self.textEdit_4 = QtGui.QLabel(self.centralwidget)
        self.textEdit_4.setGeometry(QtCore.QRect(40, 190, 250, 30))
        self.textEdit_4.setStyleSheet("background-color: white; color: orange;font-size: 13pt")
        self.textEdit_4.setObjectName(_fromUtf8("textEdit_4"))
        try:
            self.textEdit_4.setText(alis[3][1])
        except:
            pass
        self.Vote1 = QtGui.QPushButton(self.centralwidget)
        self.Vote1.setGeometry(QtCore.QRect(310, 40, 50 , 30))
        self.Vote1.setStyleSheet("background-color: orange; color: white;font-size: 14pt")
        self.Vote1.setObjectName(_fromUtf8("Vote1"))
        self.Vote2 = QtGui.QPushButton(self.centralwidget)
        self.Vote2.setGeometry(QtCore.QRect(310, 90, 50 , 30))
        self.Vote2.setStyleSheet("background-color: orange; color: white;font-size: 14pt")
        self.Vote2.setObjectName(_fromUtf8("Vote2"))
        self.Vote3 = QtGui.QPushButton(self.centralwidget)
        self.Vote3.setGeometry(QtCore.QRect(310, 140, 50 , 30))
        self.Vote3.setStyleSheet("background-color: orange; color: white;font-size: 14pt")
        self.Vote3.setObjectName(_fromUtf8("Vote3"))
        self.Vote4 = QtGui.QPushButton(self.centralwidget)
        self.Vote4.setGeometry(QtCore.QRect(310, 190,50 , 30))
        self.Vote4.setStyleSheet("background-color: orange; color: white;font-size: 14pt")
        self.Vote4.setObjectName(_fromUtf8("Vote4"))
        MainWindow.setCentralWidget(self.centralwidget)
        self.statusbar = QtGui.QStatusBar(MainWindow)
        self.statusbar.setObjectName(_fromUtf8("statusbar"))
        MainWindow.setStatusBar(self.statusbar)
        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow", None))
        self.Vote1.setText(_translate("MainWindow", "vote", None))
        self.Vote2.setText(_translate("MainWindow", "vote", None))
        self.Vote3.setText(_translate("MainWindow", "vote", None))
        self.Vote4.setText(_translate("MainWindow", "vote", None))


if __name__ == "__main__":
    import sys
    app = QtGui.QApplication(sys.argv)
    MainWindow = QtGui.QMainWindow()
    ui = Ui_MainWindowVote()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())

