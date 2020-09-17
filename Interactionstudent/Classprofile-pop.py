# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'classprofile1.ui'
#
# Created by: PyQt4 UI code generator 4.11.4
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

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

    def setupUi(self, MainWindow,subj):
        self.sub = "FRA"+str(subj)
        MainWindow.setObjectName(_fromUtf8("MainWindow"))
        MainWindow.setFixedSize(280, 430)
        self.centralwidget = QtGui.QWidget(MainWindow)
        self.centralwidget.setObjectName(_fromUtf8("centralwidget"))
        self.ok = QtGui.QPushButton(self.centralwidget)
        self.ok.setGeometry(QtCore.QRect(200, 370, 50, 20))
        self.ok.setObjectName(_fromUtf8("ok"))
        self.timeEdit = QtGui.QTimeEdit(self.centralwidget)
        self.timeEdit.setGeometry(QtCore.QRect(180, 75, 70, 20))
        self.timeEdit.setLocale(QtCore.QLocale(QtCore.QLocale.Tagalog, QtCore.QLocale.Philippines))
        self.timeEdit.setObjectName(_fromUtf8("timeEdit"))
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

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow", None))
        self.ok.setText(_translate("MainWindow", "OK", None))
        self.pri.setText(_translate("MainWindow", "Print", None))
        self.label_3.setText(_translate("MainWindow", "amount 00 / 00", None))
        self.back.setText(_translate("MainWindow", "BACK", None))
        self.label_4.setText(_translate("MainWindow", "DATE", None))
        self.label_5.setText(_translate("MainWindow", "TIME", None))
        self.comboBox.setText(_translate("MainWindow", "Subject : "+self.sub, None))
        self.label.setText(_translate("MainWindow", "UNDERSTAND(%)", None))


if __name__ == "__main__":
    import sys
    app = QtGui.QApplication(sys.argv)
    MainWindow = QtGui.QMainWindow()
    ui = Classprofile()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())

