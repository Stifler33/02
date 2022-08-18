#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this->ui->openBtn, &QPushButton::clicked, this, &MainWindow::openFile);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openFile()
{
    pathFile = QFileDialog::getOpenFileName(this, "open file", "C:\\", tr("file txt (*.txt)"));
    if (!pathFile.isEmpty())
    {
        ui->textEdit->clear();
         QFile file(pathFile);
         if(!file.open(QIODevice::ReadWrite | QIODevice::Text))
         {
             printText("file not open");
             return;
         }

             while(file.atEnd())
             {
                 QByteArray t = file.readLine();
                 printText(t);
             }

    }else{
        printText("file empty");
    }
}

void MainWindow::printText(QString text)
{
    ui->textEdit->append(text);
}
