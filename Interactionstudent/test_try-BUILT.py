from PyQt4 import QtGui,QtCore

class Window1(QtGui.QMainWindow):
    def __init__(self):
        super(Window1, self).__init__()

        self.setGeometry(30, 50, 500, 300)
        self.setWindowTitle("Real Time System")
        self.setWindowIcon(QtGui.QIcon('vr.jpg'))

        self.word1 = QtGui.QLabel('Teacher',self)
        self.word1.move(200,150)

        self.pushbutton1 = QtGui.QPushButton(self)
        self.pushbutton1.setText("FRA")
        self.pushbutton1.setGeometry(20, 200, 460, 50)
        self.pushbutton1.clicked.connect(self.closeEvent())

#    def click(self)
 #       self.add

class Window2(QtGui.QMainWindow):
    def __init__(self):
        super(Window2, self).__init__()








import sys


app = QtGui.QApplication(sys.argv)
app.setApplicationName('MyWindow')

main = Window1()
main.show()

sys.exit(app.exec_())