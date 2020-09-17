# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'untitled.ui'
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
        MainWindow.resize(872, 699)

        self.centralwidget = QtGui.QWidget(MainWindow)
        self.centralwidget.setObjectName(_fromUtf8("centralwidget"))
        self.verticalLayoutWidget = QtGui.QWidget(self.centralwidget)
        self.verticalLayoutWidget.setGeometry(QtCore.QRect(0, 0, 871, 641))
        self.verticalLayoutWidget.setObjectName(_fromUtf8("verticalLayoutWidget"))
        self.verticalLayout = QtGui.QVBoxLayout(self.verticalLayoutWidget)
        self.verticalLayout.setObjectName(_fromUtf8("verticalLayout"))
        self.tabWidget = QtGui.QTabWidget(self.verticalLayoutWidget)
        self.tabWidget.setObjectName(_fromUtf8("tabWidget"))
        self.tab_3 = QtGui.QWidget()
        self.tab_3.setObjectName(_fromUtf8("tab_3"))
        self.textEdit = QtGui.QTextEdit(self.tab_3)
        self.textEdit.setGeometry(QtCore.QRect(50, 70, 771, 131))
        self.textEdit.setObjectName(_fromUtf8("textEdit"))
        self.pushButton = QtGui.QPushButton(self.tab_3)
        self.pushButton.setGeometry(QtCore.QRect(710, 250, 93, 28))
        self.pushButton.setObjectName(_fromUtf8("pushButton"))
        self.tabWidget.addTab(self.tab_3, _fromUtf8(""))
        self.tab_5 = QtGui.QWidget()
        self.tab_5.setObjectName(_fromUtf8("tab_5"))
        self.textEdit_2 = QtGui.QTextEdit(self.tab_5)
        self.textEdit_2.setGeometry(QtCore.QRect(30, 90, 541, 61))
        self.textEdit_2.setObjectName(_fromUtf8("textEdit_2"))
        self.radioButton = QtGui.QRadioButton(self.tab_5)
        self.radioButton.setGeometry(QtCore.QRect(650, 110, 95, 20))
        self.radioButton.setObjectName(_fromUtf8("radioButton"))
        self.textEdit_3 = QtGui.QTextEdit(self.tab_5)
        self.textEdit_3.setGeometry(QtCore.QRect(30, 190, 541, 61))
        self.textEdit_3.setObjectName(_fromUtf8("textEdit_3"))
        self.textEdit_4 = QtGui.QTextEdit(self.tab_5)
        self.textEdit_4.setGeometry(QtCore.QRect(30, 290, 541, 61))
        self.textEdit_4.setObjectName(_fromUtf8("textEdit_4"))
        self.textEdit_5 = QtGui.QTextEdit(self.tab_5)
        self.textEdit_5.setGeometry(QtCore.QRect(30, 390, 541, 61))
        self.textEdit_5.setObjectName(_fromUtf8("textEdit_5"))
        self.radioButton_2 = QtGui.QRadioButton(self.tab_5)
        self.radioButton_2.setGeometry(QtCore.QRect(650, 200, 95, 20))
        self.radioButton_2.setObjectName(_fromUtf8("radioButton_2"))
        self.radioButton_3 = QtGui.QRadioButton(self.tab_5)
        self.radioButton_3.setGeometry(QtCore.QRect(650, 310, 95, 20))
        self.radioButton_3.setObjectName(_fromUtf8("radioButton_3"))
        self.radioButton_4 = QtGui.QRadioButton(self.tab_5)
        self.radioButton_4.setGeometry(QtCore.QRect(650, 420, 95, 20))
        self.radioButton_4.setObjectName(_fromUtf8("radioButton_4"))
        self.tabWidget.addTab(self.tab_5, _fromUtf8(""))
        self.tab_4 = QtGui.QWidget()
        self.tab_4.setObjectName(_fromUtf8("tab_4"))
        self.tabWidget.addTab(self.tab_4, _fromUtf8(""))
        self.verticalLayout.addWidget(self.tabWidget)
        MainWindow.setCentralWidget(self.centralwidget)
        self.toolBar = QtGui.QToolBar(MainWindow)
        self.toolBar.setObjectName(_fromUtf8("toolBar"))
        MainWindow.addToolBar(QtCore.Qt.TopToolBarArea, self.toolBar)
        self.actionSendtext = QtGui.QAction(MainWindow)
        self.actionSendtext.setObjectName(_fromUtf8("actionSendtext"))
        self.toolBar.addAction(self.actionSendtext)
        self.toolBar.addSeparator()

        self.retranslateUi(MainWindow)
        self.tabWidget.setCurrentIndex(1)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow", None))
        self.pushButton.setText(_translate("MainWindow", "Send", None))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab_3), _translate("MainWindow", "Message", None))
        self.radioButton.setText(_translate("MainWindow", "Vote", None))
        self.radioButton_2.setText(_translate("MainWindow", "Vote", None))
        self.radioButton_3.setText(_translate("MainWindow", "Vote", None))
        self.radioButton_4.setText(_translate("MainWindow", "Vote", None))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab_5), _translate("MainWindow", "Question", None))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tab_4), _translate("MainWindow", "Quiz", None))
        self.toolBar.setWindowTitle(_translate("MainWindow", "toolBar", None))
        self.actionSendtext.setText(_translate("MainWindow", "sendtext", None))
        self.actionSendtext.setToolTip(_translate("MainWindow", "Sendt text", None))


if __name__ == "__main__":
    import sys
    app = QtGui.QApplication(sys.argv)
    MainWindow = QtGui.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())

