#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H
#include <QMainWindow>
#include "matrix.h"
namespace Ui {class secondWindow;}
class secondWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit secondWindow(QWidget *parent = nullptr);
    ~secondWindow();
    void receiveAll(int arg1,int arg2, int arg3, int arg4, int arg5, bool arg6);
signals:
    void firstWindow();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void setFM(int row, int col);
    void setSM(int row, int col);
    void fillFM(int row, int col, matrix *arr);
    void fillSM(int row, int col, matrix *arr);
    void fillRes(int row,int col, matrix *arr);
    void on_firstMatrix_itemChanged(QTableWidgetItem *item);
    void on_secondMatrix_itemChanged(QTableWidgetItem *item);
private:
    Ui::secondWindow *ui;

};
#endif // SECONDWINDOW_H
