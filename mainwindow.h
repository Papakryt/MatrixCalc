#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "secondwindow.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class MainWindow : public QMainWindow{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_radioButton_toggled(bool checked);
    void on_spinBox_valueChanged(int arg1);
    void on_spinBox_2_valueChanged(int arg1);
    void on_spinBox_3_valueChanged(int arg1);
    void on_spinBox_4_valueChanged(int arg1);
    void on_pushButton_clicked();
    void checking(int fMR,int fMC, int sMR, int sMC, bool check);
    void on_comboBox_currentIndexChanged(int index);
private:
    int firstMatrixRows=0,firstMatrixColumns=0,secondMatrixRows=0,secondMatrixColumns=0, operation=0;
    bool oneMatrix=false;
    Ui::MainWindow *ui;
    secondWindow *ui2;
};
#endif // MAINWINDOW_H
