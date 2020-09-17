# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'bbb.ui'
#
# Created by: PyQt4 UI code generator 4.11.4
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui
import MySQLdb
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




class QUESTIONSTUDENT(object):

    def callQuestion(self,d="",sid=""):#d is date like "2016-10-2" sid "241001"
        mydb = MySQLdb.connect(host='10.61.3.223',port=3306,user='2016FRA241G5',passwd='SzTGde9E9AxVaNXA',db='2016FRA241G5')


        cur = mydb.cursor()
        call = "SELECT `Question`,`Vote`,`Seen` FROM `Question Table` WHERE TIME>='2016-11-08 00:00:00' AND TIME<='2016-11-08 23:59:59' AND `Student ID` = '58340500051'"
        call=call.replace('2016-11-08',d)
        call=call.replace('241001',sid)
        cur.execute(call)

        data = cur.fetchall()

        mydb.close()
        return data


    def setupUi(self, QuestionFormStudent_2):

        data = self.callQuestion("2016-11-08","241001")
        print data
        get = str(data)



        QuestionFormStudent_2.setObjectName(_fromUtf8("QuestionFormStudent_2"))
        QuestionFormStudent_2.setFixedSize(500, 600)#240,400
        self.centralwidget = QtGui.QWidget(QuestionFormStudent_2)
        self.centralwidget.setObjectName(_fromUtf8("centralwidget"))
        self.bg = QtGui.QLabel(self.centralwidget)
        self.bg.setGeometry(QtCore.QRect(0, 0, 240, 400))
        self.bg.setText(_fromUtf8(""))
        self.bg.setPixmap(QtGui.QPixmap(_fromUtf8("teacherBackground_3")))
        self.bg.setObjectName(_fromUtf8("bg"))
        self.verticalLayoutWidget = QtGui.QLabel(self.centralwidget)
        self.verticalLayoutWidget.setGeometry(QtCore.QRect(20, 60, 460, 500))#(20, 60, 200, 260))
        self.verticalLayoutWidget.setObjectName(_fromUtf8("verticalLayoutWidget"))
        self.verticalLayout = QtGui.QVBoxLayout(self.verticalLayoutWidget)
        self.verticalLayout.setObjectName(_fromUtf8("verticalLayout"))
        self.QuestionFormStudent = QtGui.QTextBrowser(self.verticalLayoutWidget)
        self.QuestionFormStudent.setStyleSheet("background-color: green;")
        self.label_2 = QtGui.QLabel(self.centralwidget)
        self.label_2.setGeometry(QtCore.QRect(20, 10, 100, 51))
        self.label_2.setObjectName(_fromUtf8("label_2"))
        self.label_2.setStyleSheet("color: white;font-size: 18pt;border: white")
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Preferred, QtGui.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.QuestionFormStudent.sizePolicy().hasHeightForWidth())
        self.QuestionFormStudent.setSizePolicy(sizePolicy)
        self.QuestionFormStudent.setObjectName(_fromUtf8("QuestionFormStudent"))
        self.verticalLayout.addWidget(self.QuestionFormStudent)
        self.back = QtGui.QPushButton(self.centralwidget)
        self.back.setGeometry(QtCore.QRect(20, 550 , 50, 31)) #(30, 330 , 50, 31))
        self.back.setObjectName(_fromUtf8("back"))
        QuestionFormStudent_2.setCentralWidget(self.centralwidget)
        self.menubar = QtGui.QMenuBar(QuestionFormStudent_2)
        self.menubar.setGeometry(QtCore.QRect(50, 200, 331, 21))
        self.menubar.setObjectName(_fromUtf8("menubar"))
        QuestionFormStudent_2.setMenuBar(self.menubar)
        self.statusbar = QtGui.QStatusBar(QuestionFormStudent_2)
        self.statusbar.setObjectName(_fromUtf8("statusbar"))
        QuestionFormStudent_2.setStatusBar(self.statusbar)
        self.verticalLayoutWidget.setStyleSheet("background-color: green;color: white;font-size: 13pt;border: white")
        self.back.setStyleSheet("background-color:green;color: white;font-size: 11pt;border: white")#coller
        self.retranslateUi(QuestionFormStudent_2)
        QtCore.QMetaObject.connectSlotsByName(QuestionFormStudent_2)




    def retranslateUi(self, QuestionFormStudent_2): #เพิ่ม callQuestion
        QuestionFormStudent_2.setWindowTitle(_translate("QuestionFormStudent_2", "MainWindow", None))


        data = self.callQuestion("2016-11-08","241001") #self.callQuestion('2016-11-08','241001')
        data = str(data)
       # self.callQuestion('2016-11-08','241001')
        self.QuestionFormStudent.setHtml(_translate("QuestionFormStudent",data , None))
        self.QuestionFormStudent.setStyleSheet("background-color: white; color: red;font-size: 15pt")#สีแดง,ตัวหนังสือ15
        self.back.setText(_translate("QuestionFormStudent_2", "Back", None))
        self.label_2.setText(_translate("QuestionFormStudent_2", "Question", None))


   # print callQuestion('2016-11-08','241001')



if __name__ == "__main__":
    import sys
    app = QtGui.QApplication(sys.argv)
    QuestionFormStudent_2 = QtGui.QMainWindow()
    ui = QUESTIONSTUDENT()
    ui.setupUi(QuestionFormStudent_2)
    QuestionFormStudent_2.show()
    sys.exit(app.exec_())

