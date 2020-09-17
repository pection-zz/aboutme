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
        #RealTimeSystem.setEnabled(True)
        RealTimeSystem.setFixedSize(240, 475)
        self.centralwidget = QtGui.QWidget(RealTimeSystem)
        self.centralwidget.setObjectName(_fromUtf8("centralwidget"))
        self.la = QtGui.QLabel(self.centralwidget)
        #alis = self.ques_table.SELECT(select = "Question",table= "Question Table",column= "Class ID",IS=(self.ClassID),order="Time",reverse=True)
        #alis = self.ques_table.SQL("select `Question ID` FROM `Question Table`;")
        self.la.setGeometry(QtCore.QRect(20, 20, 250, 30))
        self.la.setObjectName(_fromUtf8("textEdit"))
        self.la.setText("Choose your class.")
        self.la.setStyleSheet("color: orange;font-size: 13pt")
        self.verticalLayoutWidget = QtGui.QWidget(self.centralwidget)
        self.verticalLayoutWidget.setGeometry(QtCore.QRect(20, 50, 200, 400))
        self.verticalLayoutWidget.setObjectName(_fromUtf8("verticalLayoutWidget"))
        self.verticalLayout = QtGui.QVBoxLayout(self.verticalLayoutWidget)
        self.verticalLayout.setObjectName(_fromUtf8("verticalLayout"))
        self.FRA141 = QtGui.QPushButton(self.verticalLayoutWidget)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Preferred, QtGui.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.FRA141.sizePolicy().hasHeightForWidth())
        self.FRA141.setSizePolicy(sizePolicy)
        self.FRA141.setObjectName(_fromUtf8("FRA141 Programming I"))
        self.verticalLayout.addWidget(self.FRA141)
        self.FRA142 = QtGui.QPushButton(self.verticalLayoutWidget)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Preferred, QtGui.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.FRA142.sizePolicy().hasHeightForWidth())
        self.FRA142.setSizePolicy(sizePolicy)
        self.FRA142.setObjectName(_fromUtf8("FRA142 Programming II"))
        self.verticalLayout.addWidget(self.FRA142)
        self.FRA162 = QtGui.QPushButton(self.verticalLayoutWidget)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Preferred, QtGui.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.FRA162.sizePolicy().hasHeightForWidth())
        self.FRA162.setSizePolicy(sizePolicy)
        self.FRA162.setObjectName(_fromUtf8("FRA162 Robotic Lab I"))
        self.verticalLayout.addWidget(self.FRA162)
        self.FRA221 = QtGui.QPushButton(self.verticalLayoutWidget)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Preferred, QtGui.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.FRA221.sizePolicy().hasHeightForWidth())
        self.FRA221.setSizePolicy(sizePolicy)
        self.FRA221.setObjectName(_fromUtf8("FRA221 Digital Electronic"))
        self.verticalLayout.addWidget(self.FRA221)
        self.FRA241 = QtGui.QPushButton(self.verticalLayoutWidget)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Preferred, QtGui.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.FRA241.sizePolicy().hasHeightForWidth())
        self.FRA241.setSizePolicy(sizePolicy)
        self.FRA241.setObjectName(_fromUtf8("FRA241 Software Dev"))
        self.verticalLayout.addWidget(self.FRA241)
        self.FRA351 = QtGui.QPushButton(self.verticalLayoutWidget)
        sizePolicy = QtGui.QSizePolicy(QtGui.QSizePolicy.Preferred, QtGui.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.FRA351.sizePolicy().hasHeightForWidth())
        self.FRA351.setSizePolicy(sizePolicy)
        self.FRA351.setObjectName(_fromUtf8("FRA351 Computer-AID"))
        self.verticalLayout.addWidget(self.FRA351)
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
        self.FRA141.setText(_translate("RealTimeSystem", "FRA141 Programming I", None))
        self.FRA142.setText(_translate("RealTimeSystem", "FRA142 Programming II", None))
        self.FRA162.setText(_translate("RealTimeSystem", "FRA162 Robotic Lab I", None))
        self.FRA221.setText(_translate("RealTimeSystem", "FRA221 Digital Electronic", None))
        self.FRA241.setText(_translate("RealTimeSystem", "FRA241 Software Dev", None))
        self.FRA351.setText(_translate("RealTimeSystem", "FRA351 Computer-AID", None))



if __name__ == "__main__":
    import sys
    app = QtGui.QApplication(sys.argv)
    RealTimeSystem = QtGui.QMainWindow()
    ui = MAINWINDOW()
    ui.setupUi(RealTimeSystem)
    RealTimeSystem.show()
    sys.exit(app.exec_())

