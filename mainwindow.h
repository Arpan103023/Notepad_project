#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QFile>
#include<QFileDialog>
#include <QMessageBox>
#include <QMimeData>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNew_2_triggered();

    void on_actionUndo_triggered();

    void on_actionOpen_triggered();

    void on_actionRedo_2_triggered();

//    void on_actionSave_As_triggered();

    void on_actionExit_triggered();

    void on_actionCopy_triggered();

    void on_actionCut_triggered();

    void on_actionBold_triggered();

    void on_actionPaste_triggered();

    void on_actionUn_Bold_triggered();

    void on_actionSuperscript_triggered();

    void on_actionSubscript_triggered();

    void on_actionAbout_ME_triggered();

    void on_pushButton_clicked();

    void on_actionSave_As_2_triggered();

private:
    Ui::MainWindow *ui;
    QString currentFile="";
};
#endif // MAINWINDOW_H
