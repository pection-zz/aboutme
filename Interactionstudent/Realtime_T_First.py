
from PyQt4 import QtCore, QtGui
import time
from Realtime_Server import Databaze_2
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

class DETAIL(object):


    def setupUi(self, MainWindow,clas):
        MainWindow.setObjectName(_fromUtf8("MainWindow"))
        MainWindow.setFixedSize(210, 320)
        self.centralwidget = QtGui.QWidget(MainWindow)
        self.centralwidget.setObjectName(_fromUtf8("centralwidget"))
        self.bg = QtGui.QLabel(self.centralwidget)
        self.bg.setGeometry(QtCore.QRect(0, 0, 210, 320))
        self.bg.setText(_fromUtf8(""))
        self.bg.setPixmap(QtGui.QPixmap(_fromUtf8("teacherBackground_2")))
        self.bg.setObjectName(_fromUtf8("bg"))
        self.verticalLayoutWidget = QtGui.QWidget(self.centralwidget)
        self.verticalLayoutWidget.setGeometry(QtCore.QRect(20, 50, 170, 200))
        self.verticalLayoutWidget.setObjectName(_fromUtf8("verticalLayoutWidget"))
        self.verticalLayout = QtGui.QVBoxLayout(self.verticalLayoutWidget)
        self.verticalLayout.setObjectName(_fromUtf8("verticalLayout"))
        self.la2 = QtGui.QLabel(self.centralwidget)
        self.la2.setGeometry(QtCore.QRect(20, 20, 250, 30))
        self.la2.setObjectName(_fromUtf8("textEdit"))
        self.la2.setText("FRA "+ str(clas))
        self.la2.setStyleSheet("color: white;font-size: 15pt")
        self.CLASSPROFILE = QtGui.QPushButton(self.verticalLayoutWidget)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Preferred, QtGui.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.CLASSPROFILE.sizePolicy().hasHeightForWidth())
        self.CLASSPROFILE.setSizePolicy(sizePolicy)
        self.CLASSPROFILE.setObjectName(_fromUtf8("CLASSPROFILE"))
        self.verticalLayout.addWidget(self.CLASSPROFILE)
        self.STUDENTPROFILE = QtGui.QPushButton(self.verticalLayoutWidget)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Preferred, QtGui.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.STUDENTPROFILE.sizePolicy().hasHeightForWidth())
        self.STUDENTPROFILE.setSizePolicy(sizePolicy)
        self.STUDENTPROFILE.setObjectName(_fromUtf8("STUDENTPROFILE"))

        self.verticalLayout.addWidget(self.STUDENTPROFILE)
        self.SHOWQUESTION = QtGui.QPushButton(self.verticalLayoutWidget)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Preferred, QtGui.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.SHOWQUESTION.sizePolicy().hasHeightForWidth())
        self.SHOWQUESTION.setSizePolicy(sizePolicy)
        self.SHOWQUESTION.setObjectName(_fromUtf8("SHOWQUESTION"))
        self.verticalLayout.addWidget(self.SHOWQUESTION)
        self.StatRealTimeUnderstand = QtGui.QProgressBar(self.verticalLayoutWidget)

        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Expanding, QtGui.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.StatRealTimeUnderstand.sizePolicy().hasHeightForWidth())
        self.StatRealTimeUnderstand.setSizePolicy(sizePolicy)
        self.StatRealTimeUnderstand.setProperty("value", 24)
        self.StatRealTimeUnderstand.setObjectName(_fromUtf8("StatRealTimeUnderstand"))
        self.StatRealTimeUnderstand.setValue(0)
        self.verticalLayout.addWidget(self.StatRealTimeUnderstand)
        self.back1 = QtGui.QPushButton(self.centralwidget)
        self.back1.setGeometry(QtCore.QRect(100, 270, 80, 20))
        self.back1.setObjectName(_fromUtf8("BACK"))
        self.label = QtGui.QLabel(self.centralwidget)
        self.label.setGeometry(QtCore.QRect(60, 220, 71, 21))
        font = QtGui.QFont()
        font.setPointSize(10)
        self.label.setFont(font)
        self.label.setObjectName(_fromUtf8("label"))
        self.label.setStyleSheet("color: gray;font-size: 10pt")
        self.amount = QtGui.QLabel(self.centralwidget)
        self.amount.setGeometry(QtCore.QRect(120, 240, 150, 15))
        font = QtGui.QFont()
        font.setPointSize(10)
        self.amount.setFont(font)
        self.amount.setObjectName(_fromUtf8("amount"))
        self.amount.setStyleSheet("color: black;font-size: 8pt")
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtGui.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 356, 21))
        self.menubar.setObjectName(_fromUtf8("menubar"))
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtGui.QStatusBar(MainWindow)
        self.statusbar.setObjectName(_fromUtf8("statusbar"))
        MainWindow.setStatusBar(self.statusbar)
        self.CLASSPROFILE.setStyleSheet("background-color: green;color: white;font-size: 11pt;border: white")
        self.STUDENTPROFILE.setStyleSheet("background-color: green;color: white;font-size: 11pt;border: white")
        self.SHOWQUESTION.setStyleSheet("background-color: green;color: white;font-size: 11pt;border: white")
        self.back1.setStyleSheet("background-color: green;color: white;font-size: 11pt;border: white")
        datetime = time.asctime( time.localtime(time.time())) #Tue Nov 08 12:41:18 2016
        datetime = datetime[20:24]+"-"+str(self.monthToNum(datetime[4:7]))+"-"+datetime[8:10]+" "+datetime[11:19]
        database2 = Databaze_2()
        l2 = database2.Oneshot(t=datetime[:10],sid=clas,time=float(datetime[11:19][:5].replace(":",".")))
        self.StatRealTimeUnderstand.setValue(l2[2])
        self.amount.setText(_translate("MainWindow", "amount "+str(l2[0])+" / "+str(int(l2[0]+l2[1])), None))
        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def monthToNum(self,shortMonth):

        return{'Jan' : 1,'Feb' : 2,'Mar' : 3,'Apr' : 4,'May' : 5,'Jun' : 6, 'Jul' : 7,'Aug' : 8,'Sep' : 9, 'Oct' : 10,'Nov' : 11,'Dec' : 12}[shortMonth]


    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow", None))

        self.CLASSPROFILE.setText(_translate("MainWindow", "Class Statistic", None))
        self.STUDENTPROFILE.setText(_translate("MainWindow", "Student Profile", None))
        self.SHOWQUESTION.setText(_translate("MainWindow", "Question", None))
        self.back1.setText(_translate("MainWindow", "Back", None))
        self.label.setText(_translate("MainWindow", "Understand", None))



if __name__ == "__main__":
    import sys
    app = QtGui.QApplication(sys.argv)
    MainWindow = QtGui.QMainWindow()
    ui = DETAIL()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())

