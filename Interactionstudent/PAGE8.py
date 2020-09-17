# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'page8.ui'
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

class Ui_Dialog(object):
    def setupUi(self, Dialog):
        Dialog.setObjectName(_fromUtf8("Dialog"))
        Dialog.resize(658, 535)
        Dialog.setWindowOpacity(1.0)
        Dialog.setLayoutDirection(QtCore.Qt.LeftToRight)
        Dialog.setAutoFillBackground(False)
        Dialog.setLocale(QtCore.QLocale(QtCore.QLocale.Tagalog, QtCore.QLocale.Philippines))
        self.timeEdit = QtGui.QTimeEdit(Dialog)
        self.timeEdit.setGeometry(QtCore.QRect(350, 170, 118, 22))
        self.timeEdit.setLocale(QtCore.QLocale(QtCore.QLocale.Tagalog, QtCore.QLocale.Philippines))
        self.timeEdit.setObjectName(_fromUtf8("timeEdit"))
        self.progressBar = QtGui.QProgressBar(Dialog)
        self.progressBar.setGeometry(QtCore.QRect(420, 280, 131, 23))
        self.progressBar.setProperty("value", 24)
        self.progressBar.setObjectName(_fromUtf8("progressBar"))
        self.progressBar_2 = QtGui.QProgressBar(Dialog)
        self.progressBar_2.setGeometry(QtCore.QRect(420, 360, 131, 23))
        self.progressBar_2.setProperty("value", 24)
        self.progressBar_2.setObjectName(_fromUtf8("progressBar_2"))
        self.label = QtGui.QLabel(Dialog)
        self.label.setGeometry(QtCore.QRect(270, 290, 91, 16))
        self.label.setObjectName(_fromUtf8("label"))
        self.label_2 = QtGui.QLabel(Dialog)
        self.label_2.setGeometry(QtCore.QRect(270, 370, 121, 20))
        self.label_2.setObjectName(_fromUtf8("label_2"))
        self.lcdNumber = QtGui.QLCDNumber(Dialog)
        self.lcdNumber.setGeometry(QtCore.QRect(420, 320, 91, 23))
        self.lcdNumber.setObjectName(_fromUtf8("lcdNumber"))
        self.label_3 = QtGui.QLabel(Dialog)
        self.label_3.setGeometry(QtCore.QRect(270, 330, 121, 20))
        self.label_3.setObjectName(_fromUtf8("label_3"))
        self.pushButton = QtGui.QPushButton(Dialog)
        self.pushButton.setGeometry(QtCore.QRect(350, 210, 81, 23))
        self.pushButton.setObjectName(_fromUtf8("pushButton"))
        self.pushButton_2 = QtGui.QPushButton(Dialog)
        self.pushButton_2.setGeometry(QtCore.QRect(350, 450, 81, 23))
        self.pushButton_2.setObjectName(_fromUtf8("pushButton_2"))
        self.comboBox = QtGui.QComboBox(Dialog)
        self.comboBox.setGeometry(QtCore.QRect(350, 70, 81, 41))
        self.comboBox.setObjectName(_fromUtf8("comboBox"))
        self.comboBox.addItem(_fromUtf8(""))
        self.comboBox.addItem(_fromUtf8(""))
        self.comboBox.addItem(_fromUtf8(""))
        self.comboBox.addItem(_fromUtf8(""))
        self.label_4 = QtGui.QLabel(Dialog)
        self.label_4.setGeometry(QtCore.QRect(290, 140, 46, 13))
        self.label_4.setObjectName(_fromUtf8("label_4"))
        self.label_5 = QtGui.QLabel(Dialog)
        self.label_5.setGeometry(QtCore.QRect(290, 180, 46, 13))
        self.label_5.setObjectName(_fromUtf8("label_5"))
        self.dateEdit = QtGui.QDateEdit(Dialog)
        self.dateEdit.setGeometry(QtCore.QRect(350, 130, 111, 22))
        self.dateEdit.setObjectName(_fromUtf8("dateEdit"))
        self.lcdNumber_2 = QtGui.QLCDNumber(Dialog)
        self.lcdNumber_2.setGeometry(QtCore.QRect(420, 400, 91, 23))
        self.lcdNumber_2.setObjectName(_fromUtf8("lcdNumber_2"))
        self.label_6 = QtGui.QLabel(Dialog)
        self.label_6.setGeometry(QtCore.QRect(270, 410, 141, 20))
        self.label_6.setObjectName(_fromUtf8("label_6"))

        self.retranslateUi(Dialog)
        QtCore.QMetaObject.connectSlotsByName(Dialog)

    def retranslateUi(self, Dialog):
        Dialog.setWindowTitle(_translate("Dialog", "Dialog", None))
        self.label.setText(_translate("Dialog", "UNDERSTAND(%)", None))
        self.label_2.setText(_translate("Dialog", "NOT UNDERSTAND(%)", None))
        self.label_3.setText(_translate("Dialog", "UNDERSTAND(NUMBER)", None))
        self.pushButton.setText(_translate("Dialog", "OK", None))
        self.pushButton_2.setText(_translate("Dialog", "BACK", None))
        self.comboBox.setItemText(0, _translate("Dialog", "FRA221", None))
        self.comboBox.setItemText(1, _translate("Dialog", "FRA231", None))
        self.comboBox.setItemText(2, _translate("Dialog", "FRA241", None))
        self.comboBox.setItemText(3, _translate("Dialog", "FRA261", None))
        self.label_4.setText(_translate("Dialog", "DATE", None))
        self.label_5.setText(_translate("Dialog", "TIME", None))
        self.label_6.setText(_translate("Dialog", "NOT UNDERSTAND(NUMBER)", None))


if __name__ == "__main__":
    import sys
    app = QtGui.QApplication(sys.argv)
    Dialog = QtGui.QDialog()
    ui = Ui_Dialog()
    ui.setupUi(Dialog)
    Dialog.show()
    sys.exit(app.exec_())

