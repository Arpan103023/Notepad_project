#include "mainwindow.h"
#include "./ui_mainwindow.h"


#include <QFileDialog>
#include <QTextStream>
#include <QFile>
#include<QCoreApplication>
#include <QTextCharFormat>
#include <QFont>
#include <QTextCursor>
#include <QMessageBox>
#include <QDebug>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);

//    this->setCentralWidget(ui->actionBold);

}


MainWindow::~MainWindow()
{

    delete ui;
}


void MainWindow::on_actionNew_2_triggered()
{
   currentFile.clear();
   ui->textEdit->setText(QString());
}


void MainWindow::on_actionUndo_triggered()
{
 ui->textEdit->undo();
}


void MainWindow::on_actionOpen_triggered()
{
  QString filename = QFileDialog::getOpenFileName(this, "Open the file");
  QFile file(filename);
  currentFile = filename;
  if(!file.open(QIODevice::ReadOnly| QFile::Text))
  {
      QMessageBox::warning(this, "Warning","Cannot open file : " +file.errorString());

  }
  setWindowTitle(filename);
  QTextStream in(&file);
  QString text = in.readAll();
  ui->textEdit->setText(text);
file.close();



}


void MainWindow::on_actionRedo_2_triggered()
{
    ui->textEdit->redo();

}







void MainWindow::on_actionExit_triggered()
{
    QApplication :: quit();


}



void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();

}



void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}





void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}
void MainWindow::on_actionBold_triggered()
{
    QFont font = ui -> textEdit -> currentFont();
    font.bold() == true ? font.setBold(false) : font.setBold(true);
    ui -> textEdit -> setCurrentFont(font);
}




void MainWindow::on_actionUn_Bold_triggered()
{
    ui->textEdit->undo();
}


void MainWindow::on_actionSuperscript_triggered()
{
    QTextCharFormat format;
       format.setVerticalAlignment(QTextCharFormat::AlignSuperScript);
       if(ui->textEdit->hasFocus())
          ui->textEdit->mergeCurrentCharFormat(format);
}


void MainWindow::on_actionSubscript_triggered()
{
    QTextCharFormat format;
       format.setVerticalAlignment(QTextCharFormat::AlignSubScript);
       if(ui->textEdit->hasFocus())
          ui->textEdit->mergeCurrentCharFormat(format);
}


void MainWindow::on_actionAbout_ME_triggered()
{
     QFile file(":/Myresume/Resume.rtf");
     if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
         QMessageBox::information(0,"info",file.errorString());

     QTextStream in(&file);
      qDebug()<<in.readAll();

}


void MainWindow::on_pushButton_clicked()
{
    QFile file(QFileDialog::getOpenFileName(this,tr(":/Myresume/Resume.rtf"),"",tr("Text Files(*.txt)")));
    file.open(QIODevice::ReadOnly| QIODevice::Text);
    QTextStream stream(&file);
    QString text =stream.readAll();
    QMessageBox Box;
    Box.setText(text);
    Box.exec();
    file.close();



};


//void MainWindow::on_actionSave_As_triggered()
//{
//    QString fileName= QFileDialog:: getSaveFileName(this, "Save as");
//    QFile file(fileName);
//    if(!file.open(QFile::WriteOnly | QFile::Text))
//    {
//        QMessageBox::warning(this , "Warning", "Cannot Save the File : " +file.errorString());
//        return;

//    }
//    currentFile=fileName;
//    setWindowTitle(fileName);
//    QTextStream out(&file);
//    QString text = ui->textEdit->toPlainText();
//    out << text;
//    file.close();

//}


void MainWindow::on_actionSave_As_2_triggered()
{
    QString fileName= QFileDialog:: getSaveFileName(this, "Save as");
    QFile file(fileName);
    if(!file.open(QFile::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this , "Warning", "Cannot Save the File : " +file.errorString());
        return;

    }
    currentFile=fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    QString text = ui->textEdit->toPlainText();
    out << text;
    file.close();
}

