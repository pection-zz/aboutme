# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'detail.ui'
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

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName(_fromUtf8("MainWindow"))
        MainWindow.resize(356, 517)
        self.centralwidget = QtGui.QWidget(MainWindow)
        self.centralwidget.setObjectName(_fromUtf8("centralwidget"))
        self.verticalLayoutWidget = QtGui.QWidget(self.centralwidget)
        self.verticalLayoutWidget.setGeometry(QtCore.QRect(60, 30, 171, 381))
        self.verticalLayoutWidget.setObjectName(_fromUtf8("verticalLayoutWidget"))
        self.verticalLayout = QtGui.QVBoxLayout(self.verticalLayoutWidget)
        self.verticalLayout.setObjectName(_fromUtf8("verticalLayout"))
        self.MINIQUIZ = QtGui.QPushButton(self.verticalLayoutWidget)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Preferred, QtGui.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.MINIQUIZ.sizePolicy().hasHeightForWidth())
        self.MINIQUIZ.setSizePolicy(sizePolicy)
        self.MINIQUIZ.setObjectName(_fromUtf8("MINIQUIZ"))
        self.verticalLayout.addWidget(self.MINIQUIZ)
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
        self.verticalLayout.addWidget(self.StatRealTimeUnderstand)
        self.StatRealTimeNotUnderstand = QtGui.QProgressBar(self.verticalLayoutWidget)
        self.StatRealTimeNotUnderstand.setProperty("value", 24)
        self.StatRealTimeNotUnderstand.setObjectName(_fromUtf8("StatRealTimeNotUnderstand"))
        self.verticalLayout.addWidget(self.StatRealTimeNotUnderstand)
        self.BACK = QtGui.QPushButton(self.centralwidget)
        self.BACK.setGeometry(QtCore.QRect(170, 430, 75, 23))
        self.BACK.setObjectName(_fromUtf8("BACK"))
        self.label = QtGui.QLabel(self.centralwidget)
        self.label.setGeometry(QtCore.QRect(240, 360, 71, 21))
        font = QtGui.QFont()
        font.setPointSize(10)
        self.label.setFont(font)
        self.label.setObjectName(_fromUtf8("label"))
        self.label_2 = QtGui.QLabel(self.centralwidget)
        self.label_2.setGeometry(QtCore.QRect(240, 390, 101, 21))
        font = QtGui.QFont()
        font.setPointSize(10)
        self.label_2.setFont(font)
        self.label_2.setObjectName(_fromUtf8("label_2"))
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtGui.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 356, 21))
        self.menubar.setObjectName(_fromUtf8("menubar"))
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtGui.QStatusBar(MainWindow)
        self.statusbar.setObjectName(_fromUtf8("statusbar"))
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow", None))
        self.MINIQUIZ.setText(_translate("MainWindow", "MINI QUIZ", None))
        self.CLASSPROFILE.setText(_translate("MainWindow", "CLASS PROFILE", None))
        self.STUDENTPROFILE.setText(_translate("MainWindow", "STUDENT PROFILE", None))
        self.SHOWQUESTION.setText(_translate("MainWindow", "SHOW QUESTION", None))
        self.BACK.setText(_translate("MainWindow", "BACK", None))
        self.label.setText(_translate("MainWindow", "Understand", None))
        self.label_2.setText(_translate("MainWindow", "Not Understand", None))


if __name__ == "__main__":
    import sys
    app = QtGui.QApplication(sys.argv)
    MainWindow = QtGui.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())

