# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'bbb.ui'
#
# Created by: PyQt4 UI code generator 4.11.4
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui
import MySQLdb
from Realtime_Server import Databaze_2
import time
from Realtime_Server import Databaze

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

    dataquestion=''
    def __init__(self):
        pass



    def getvalue(self,name):
        mikefile =" "
        leng=len(name)
        value=15-leng
        for i in range(0,value):
            mikefile = mikefile +" "
        name=name+mikefile
        return name
    #print('%d' % (dataquestion[0][1]))
    #print('%d' % (dataquestion[2][1]))

    def setupUi(self, QuestionFormStudent_2,id):
        QuestionFormStudent_2.setObjectName(_fromUtf8("QuestionFormStudent_2"))
        QuestionFormStudent_2.setFixedSize(240,400)#240,400
        datetime = time.asctime( time.localtime(time.time())) #Tue Nov 08 12:41:18 2016
        datetime = datetime[20:24]+"-"+str(self.monthToNum(datetime[4:7]))+"-"+datetime[8:10]+" "+datetime[11:19]
        dbdb = Databaze_2()
        self.dataquestion = dbdb.allQuestion_vote(date=datetime[:10],sid=id)
        print self.dataquestion
        self.centralwidget = QtGui.QWidget(QuestionFormStudent_2)
        self.centralwidget.setObjectName(_fromUtf8("centralwidget"))

        self.bg = QtGui.QLabel(self.centralwidget)
        self.bg.setGeometry(QtCore.QRect(0, 0, 240, 400))
        self.bg.setText(_fromUtf8(""))
        self.bg.setPixmap(QtGui.QPixmap(_fromUtf8("teacherBackground_3")))
        self.bg.setObjectName(_fromUtf8("bg"))
        self.verticalLayoutWidget = QtGui.QLabel(self.centralwidget)
        self.verticalLayoutWidget.setGeometry(QtCore.QRect(20, 60, 200, 260))#(20, 60, 200, 260))
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
        self.back.setGeometry(QtCore.QRect(30, 330 , 50, 31)) #(30, 330 , 50, 31))
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
        self.back.setStyleSheet("background-color:Green;color: white;font-size: 11pt;border: white")#coller
        self.retranslateUi(QuestionFormStudent_2) #blakไม่ออก
        QtCore.QMetaObject.connectSlotsByName(QuestionFormStudent_2) #blakไม่ออก

        self.lineEdit = QtGui.QLabel(self.centralwidget)
        self.lineEdit.setGeometry(QtCore.QRect(20, 75, 200, 30)) #ช่องสีขาว lineEdit
        self.lineEdit.setObjectName(_fromUtf8("lineEdit"))
        self.lineEdit.setStyleSheet("background-color: green;font-size: 9pt;border:1px solid black")
        self.lineEdit2 = QtGui.QLabel(self.centralwidget)
        self.lineEdit2.setGeometry(QtCore.QRect(20, 108, 200, 30)) #ช่องสีขาว lineEdit2
        self.lineEdit2.setObjectName(_fromUtf8("lineEdit"))
        self.lineEdit2.setStyleSheet("background-color: green;font-size: 9pt;border:1px solid black")
        self.lineEdit3 = QtGui.QLabel(self.centralwidget)
        self.lineEdit3.setGeometry(QtCore.QRect(20, 141, 200, 30)) #ช่องสีขาว lineEdit3
        self.lineEdit3.setObjectName(_fromUtf8("lineEdit"))
        self.lineEdit3.setStyleSheet("background-color: green;font-size: 9pt;border:1px solid black")
        self.lineEdit4 = QtGui.QLabel(self.centralwidget)
        self.lineEdit4.setGeometry(QtCore.QRect(20, 174, 200, 30)) #ช่องสีขาว lineEdit3
        self.lineEdit4.setObjectName(_fromUtf8("lineEdit"))
        self.lineEdit4.setStyleSheet("background-color: green;font-size: 9pt;border:1px solid black")
        self.lineEdit5 = QtGui.QLabel(self.centralwidget)
        self.lineEdit5.setGeometry(QtCore.QRect(20, 207, 200, 30)) #ช่องสีขาว lineEdit3
        self.lineEdit5.setObjectName(_fromUtf8("lineEdit"))
        self.lineEdit5.setStyleSheet("background-color:green;font-size: 9pt;border:1px solid black")
        self.lineEdit6 = QtGui.QLabel(self.centralwidget)
        self.lineEdit6.setGeometry(QtCore.QRect(20, 240, 200, 30)) #ช่องสีขาว lineEdit3
        self.lineEdit6.setObjectName(_fromUtf8("lineEdit"))
        self.lineEdit6.setStyleSheet("background-color: green;font-size: 9pt;border:1px solid black")
        self.lineEdit7 = QtGui.QLabel(self.centralwidget)
        self.lineEdit7.setGeometry(QtCore.QRect(20, 273, 200, 30)) #ช่องสีขาว lineEdit3
        self.lineEdit7.setObjectName(_fromUtf8("lineEdit"))
        self.lineEdit7.setStyleSheet("background-color: green;font-size: 9pt;border:1px solid black")


        self.lineEdit = QtGui.QLabel(self.centralwidget) #self.lineEdit = QtGui.QLineEdit(self.centralwidget)
        self.lineEdit.setGeometry(QtCore.QRect(30, 70, 200, 40))#20
        self.lineEdit.setObjectName(_fromUtf8("lineEdit"))
        # self.lineEdit.setText(_translate("QuestionFormStudent_2", str(self.Que), None))
        print self.dataquestion
        try:
            aaaii=self.dataquestion[0][0]
            if(len(aaaii)<15):
                mike =self.getvalue(aaaii)
            else:
                mike=aaaii[0:15]
            print mike , "hello"
            self.lineEdit.setText(mike+'|vote  %d|'% (self.dataquestion[0][1])) #ขนาดข้อความที่รับมาอยู่ข่อง 1
        except:
            pass

        self.lineEdit2 = QtGui.QLabel(self.centralwidget) #self.lineEdit2 = QtGui.QLineEdit(self.centralwidget)
        self.lineEdit2.setGeometry(QtCore.QRect(30, 102, 200, 40))#self.lineEdit2.setGeometry(QtCore.QRect(20, 102, 200, 40))
        self.lineEdit2.setObjectName(_fromUtf8("lineEdit"))
        # self.lineEdit2.setText(_translate("QuestionFormStudent_2", str(self.Que2), None))
        try:
            b=self.dataquestion[1][0]
            if(len(b)<15):
                mike2 =self.getvalue(b)
            else:
                mike2=aaaii[0:15]
            self.lineEdit2.setText(mike2+'|vote  %d|'% (self.dataquestion[1][1])) #ขนาดข้อความที่รับมาอยู่ข่อง2
        except:
            pass
        self.lineEdit3 = QtGui.QLabel(self.centralwidget)#self.lineEdit3 = QtGui.QLineEdit(self.centralwidget)
        self.lineEdit3.setGeometry(QtCore.QRect(30, 134, 200, 40))#self.lineEdit3.setGeometry(QtCore.QRect(20, 142, 200, 40))
        self.lineEdit3.setObjectName(_fromUtf8("lineEdit"))
        # self.lineEdit.setText(_translate("QuestionFormStudent_2", str(self.Que), None))
        try:
            c=self.dataquestion[2][0]
            if(len(c)<15):
                mike3 =self.getvalue(c)
            else:
                mike3 = c[0:15]
                self.lineEdit3.setText(mike3+'|vote  %d|'% (self.dataquestion[2][1])) #ขนาดข้อความที่รับมาอยู่ข่อง3
        except:
            pass
        self.lineEdit4 = QtGui.QLabel(self.centralwidget)#self.lineEdit4 = QtGui.QLineEdit(self.centralwidget)
        self.lineEdit4.setGeometry(QtCore.QRect(30, 166, 200, 40))#self.lineEdit4.setGeometry(QtCore.QRect(20, 182, 200, 40))
        self.lineEdit4.setObjectName(_fromUtf8("lineEdit"))
        # self.lineEdit.setText(_translate("QuestionFormStudent_2", str(self.Que), None))
        try:
            d=self.dataquestion[3][0]
            if(len(d)<15):
                mike4 =self.getvalue(d)
            else:
                mike4=d[0:15]

            self.lineEdit4.setText(mike4+'|vote  %d|'% (self.dataquestion[3][1])) #ขนาดข้อความที่รับมาอยู่ข่อง4
        except:
            pass
        self.lineEdit5 = QtGui.QLabel(self.centralwidget)##self.lineEdit5 = QtGui.QLineEdit(self.centralwidget)
        self.lineEdit5.setGeometry(QtCore.QRect(30, 200, 200, 40))#self.lineEdit5.setGeometry(QtCore.QRect(30, 222, 200, 40))
        self.lineEdit5.setObjectName(_fromUtf8("lineEdit"))
        # self.lineEdit.setText(_translate("QuestionFormStudent_2", str(self.Que), None))
        try:
            e=self.dataquestion[4][0]
            if(len(e)<15):
                mike5 =self.getvalue(e)
            else:
                mike5=e[0:15]

            self.lineEdit5.setText(mike5+'|vote  %d|'% (self.dataquestion[4][1])) #ขนาดข้อความที่รับมาอยู่ข่อง4
        except:
            pass
        self.lineEdit6 = QtGui.QLabel(self.centralwidget)#self.lineEdit6 = QtGui.QLineEdit(self.centralwidget)
        self.lineEdit6.setGeometry(QtCore.QRect(30, 232, 200, 40))#self.lineEdit6.setGeometry(QtCore.QRect(20, 262, 200, 40))
        self.lineEdit6.setObjectName(_fromUtf8("lineEdit"))
        # self.lineEdit.setText(_translate("QuestionFormStudent_2", str(self.Que), None))
        try:
            f=self.dataquestion[5][0]
            if(len(f)<15):
                mike6 =self.getvalue(f)
            else:
                mike6=f[0:15]

                self.lineEdit6.setText(mike6+'|vote  %d|'% (self.dataquestion[5][1])) #ขนาดข้อความที่รับมาอยู่ข่อง4
        except:
            pass
        self.lineEdit7 = QtGui.QLabel(self.centralwidget)#self.lineEdit6 = QtGui.QLineEdit(self.centralwidget)
        self.lineEdit7.setGeometry(QtCore.QRect(30, 264, 200, 40))#self.lineEdit6.setGeometry(QtCore.QRect(20, 262, 200, 40))
        self.lineEdit7.setObjectName(_fromUtf8("lineEdit"))
        # self.lineEdit.setText(_translate("QuestionFormStudent_2", str(self.Que), None))
        try:
            g=self.dataquestion[6][0]
            if(len(g)<15):
                mike7 =self.getvalue(g)
            else:
                mike7=g[0:15]
            self.lineEdit7.setText(mike7+'|vote  %d|'% (self.dataquestion[6][1])) #ขนาดข้อความที่รับมาอยู่ข่อง4
        except:
            pass







    def monthToNum(self,shortMonth):

        return{'Jan' : 1,'Feb' : 2,'Mar' : 3,'Apr' : 4,'May' : 5,'Jun' : 6, 'Jul' : 7,'Aug' : 8,'Sep' : 9, 'Oct' : 10,'Nov' : 11,'Dec' : 12}[shortMonth]





    def retranslateUi(self, QuestionFormStudent_2):
        QuestionFormStudent_2.setWindowTitle(_translate("QuestionFormStudent_2", "MainWindow", None))
        #self.QuestionFormStudent.setStyleSheet("background-color: white; color: red;font-size: 15pt")#สีแดง,ตัวหนังสือ15
        self.back.setText(_translate("QuestionFormStudent_2", "Back", None))
        #self.QuestionFormStudent.setHtml(_translate("QuestionFormStudent_2", "No Question", None))
        self.label_2.setText(_translate("QuestionFormStudent_2", "Question ", None))
        #self.QuestionFormStudent.setHtml(_translate("QuestionFormStudent_2", "no Question <br> new line here.", None))












    #def ID(self,i):
     #   self.stuID  = long(self.stuID)+ i
      #  self.lineEdit.setText(_translate("QuestionFormStudent_2", str(self.stuID), None))




if __name__ == "__main__":
    import sys
    app = QtGui.QApplication(sys.argv)
    QuestionFormStudent_2 = QtGui.QMainWindow()
    ui = QUESTIONSTUDENT()
    ui.setupUi(QuestionFormStudent_2)
    QuestionFormStudent_2.show()
    sys.exit(app.exec_())


