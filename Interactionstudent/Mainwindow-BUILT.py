# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'MainWindow.ui'
#
# Created by: PyQt4 UI code generator 4.11.4
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui
# from Detail import DETAIL

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

class MAINWINDOW(object):

    ques_table = 0
    classID = 241001
    stuID = 58340500051
    click_table = 0
    lastdatetime = ''
    seen = []

    def setupUi(self, RealTimeSystem):
        RealTimeSystem.setObjectName(_fromUtf8("RealTimeSystem"))
        RealTimeSystem.setEnabled(True)
        RealTimeSystem.resize(260, 525)
        self.centralwidget = QtGui.QWidget(RealTimeSystem)
        self.centralwidget.setObjectName(_fromUtf8("centralwidget"))
        self.verticalLayoutWidget = QtGui.QWidget(self.centralwidget)
        self.verticalLayoutWidget.setGeometry(QtCore.QRect(50, 30, 160, 441))
        self.verticalLayoutWidget.setObjectName(_fromUtf8("verticalLayoutWidget"))
        self.verticalLayout = QtGui.QVBoxLayout(self.verticalLayoutWidget)
        self.verticalLayout.setObjectName(_fromUtf8("verticalLayout"))
        self.FRA222 = QtGui.QPushButton(self.verticalLayoutWidget)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Preferred, QtGui.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.FRA222.sizePolicy().hasHeightForWidth())
        self.FRA222.setSizePolicy(sizePolicy)
        self.FRA222.setObjectName(_fromUtf8("FRA222"))
        self.verticalLayout.addWidget(self.FRA222)
        self.FRA221 = QtGui.QPushButton(self.verticalLayoutWidget)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Preferred, QtGui.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.FRA221.sizePolicy().hasHeightForWidth())
        self.FRA221.setSizePolicy(sizePolicy)
        self.FRA221.setObjectName(_fromUtf8("FRA221"))
        self.verticalLayout.addWidget(self.FRA221)
        self.FRA241 = QtGui.QPushButton(self.verticalLayoutWidget)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Preferred, QtGui.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.FRA241.sizePolicy().hasHeightForWidth())
        self.FRA241.setSizePolicy(sizePolicy)
        self.FRA241.setObjectName(_fromUtf8("FRA241"))
        self.verticalLayout.addWidget(self.FRA241)
        self.FRA231 = QtGui.QPushButton(self.verticalLayoutWidget)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Preferred, QtGui.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.FRA231.sizePolicy().hasHeightForWidth())
        self.FRA231.setSizePolicy(sizePolicy)
        self.FRA231.setObjectName(_fromUtf8("FRA231"))
        self.verticalLayout.addWidget(self.FRA231)
        self.FRA261 = QtGui.QPushButton(self.verticalLayoutWidget)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Preferred, QtGui.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.FRA261.sizePolicy().hasHeightForWidth())
        self.FRA261.setSizePolicy(sizePolicy)
        self.FRA261.setObjectName(_fromUtf8("FRA261"))
        self.verticalLayout.addWidget(self.FRA261)
        self.Upload = QtGui.QPushButton(self.verticalLayoutWidget)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Preferred, QtGui.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.Upload.sizePolicy().hasHeightForWidth())
        self.Upload.setSizePolicy(sizePolicy)
        self.Upload.setObjectName(_fromUtf8("Upload"))
        self.verticalLayout.addWidget(self.Upload)
        RealTimeSystem.setCentralWidget(self.centralwidget)
        self.menubar = QtGui.QMenuBar(RealTimeSystem)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 260, 21))
        self.menubar.setObjectName(_fromUtf8("menubar"))
        RealTimeSystem.setMenuBar(self.menubar)
        self.statusbar = QtGui.QStatusBar(RealTimeSystem)
        self.statusbar.setObjectName(_fromUtf8("statusbar"))
        RealTimeSystem.setStatusBar(self.statusbar)

        self.retranslateUi(RealTimeSystem)
        QtCore.QMetaObject.connectSlotsByName(RealTimeSystem)

    def retranslateUi(self, RealTimeSystem):
        RealTimeSystem.setWindowTitle(_translate("RealTimeSystem", "MainWindow", None))
        self.FRA222.setText(_translate("RealTimeSystem", "FRA 222", None))
        self.FRA221.setText(_translate("RealTimeSystem", "FRA 221", None))
        self.FRA241.setText(_translate("RealTimeSystem", "FRA 241", None))
        self.FRA231.setText(_translate("RealTimeSystem", "FRA 231", None))
        self.FRA261.setText(_translate("RealTimeSystem", "FRA 261", None))
        self.Upload.setText(_translate("RealTimeSystem", "UPLOAD", None))



if __name__ == "__main__":
    import sys
    app = QtGui.QApplication(sys.argv)
    RealTimeSystem = QtGui.QMainWindow()
    ui = MAINWINDOW()
    ui.setupUi(RealTimeSystem)
    RealTimeSystem.show()
    sys.exit(app.exec_())

