#include "secondwindow.h"
#include "ui_secondwindow.h"
#include <iostream>
secondWindow::secondWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::secondWindow)
{
    ui->setupUi(this);
}
int fMR,fMC,sMR,sMC,op;
bool check;
secondWindow::~secondWindow(){delete ui;}

void secondWindow::on_pushButton_clicked()
{
    this->close();
    emit firstWindow();
}
void secondWindow::setFM(int row, int col){
    for (int i=0;i<row;i++){
        for (int j=0;j<col;j++){
            QTableWidgetItem *a=new QTableWidgetItem("0");
            ui->firstMatrix->setItem(i,j,a);
        }
    }
}
void secondWindow::setSM(int row, int col){
    for (int i=0;i<row;i++){
        for (int j=0;j<col;j++){
            QTableWidgetItem *a=new QTableWidgetItem("0");
            ui->secondMatrix->setItem(i,j,a);
        }
    }
}
void secondWindow::fillFM(int row, int col, matrix *arr){
    for(int i=0; i<row; i++){
        for(int j=0;j<col;j++){
            QString a = ui->firstMatrix->item(i,j)->text();
            float b = a.split(" ")[0].toFloat();
            arr->fill(i,j,b);
        }

    }
}
void secondWindow::fillSM(int row, int col, matrix *arr){
    for(int i=0; i<row; i++){
        for(int j=0;j<col;j++){
            QString a = ui->secondMatrix->item(i,j)->text();
            float b = a.split(" ")[0].toFloat();
            arr->fill(i,j,b);
        }

    }
}
void secondWindow::fillRes(int row, int col, matrix *arr){
    for (int i=0;i<row;i++){
        for (int j=0;j<col;j++){
            float res=arr->retRC(i,j);
            QString r=QString::number(res);
            QTableWidgetItem *a = new QTableWidgetItem(r);
            ui->res->setItem(i,j,a);
        }
    }
}
void secondWindow::receiveAll(int arg1,int arg2, int arg3, int arg4, int arg5, bool arg6){
    fMR=arg1;
    fMC=arg2;
    sMR=arg3;
    sMC=arg4;
    op=arg5;
    check=arg6;
    ui->label_3->hide();
    ui->res->hide();
    if (check){
        ui->label_2->hide();
        ui->secondMatrix->hide();
        ui->firstMatrix->setRowCount(fMR);
        ui->firstMatrix->setColumnCount(fMC);
        setFM(fMR,fMC);
    }
    else{
        ui->label_2->show();
        ui->secondMatrix->show();
        ui->firstMatrix->setRowCount(fMR);
        ui->firstMatrix->setColumnCount(fMC);
        ui->secondMatrix->setRowCount(sMR);
        ui->secondMatrix->setColumnCount(sMC);
        setFM(fMR,fMC);
        setSM(sMR,sMC);
    }
}
void secondWindow::on_pushButton_2_clicked(){
    ui->res->show();
    ui->label_3->show();
    if (check){
        matrix arr(fMR,fMC);
        fillFM(fMR,fMC,&arr);
        if (op==1){
            ui->res->setRowCount(fMC);
            ui->res->setColumnCount(fMR);
            arr.transposition();
            fillRes(arr.rows,arr.columns,&arr);


        }
        if (op==2){
            ui->res->setRowCount(fMR);
            ui->res->setColumnCount(fMC);
            arr.Diagonal_matrix();
            fillRes(arr.rows,arr.columns,&arr);
        }
        if (op==3){
            ui->res->setRowCount(1);
            ui->res->setColumnCount(1);
            float res=arr.determinant();
            QString r = QString::number(res);
            QTableWidgetItem *a = new QTableWidgetItem(r);
            ui->res->setItem(0,0,a);
        }
    }
    else{
        matrix arr1(fMR,fMC);
        matrix arr2(sMR,sMC);
        fillFM(fMR,fMC,&arr1);
        fillSM(sMR,sMC,&arr2);
        if (op==4){
            ui->res->setRowCount(fMR);
            ui->res->setColumnCount(fMC);
            arr1+arr2;
            fillRes(arr1.rows,arr1.columns,&arr1);
        }
        if (op==5){
            ui->res->setRowCount(fMR);
            ui->res->setColumnCount(fMC);
            arr1-arr2;
            fillRes(arr1.rows,arr1.columns,&arr1);
        }
        if (op==6){
            ui->res->setRowCount(fMR);
            ui->res->setColumnCount(sMC);
            arr1*arr2;
            fillRes(arr1.rows,arr1.columns,&arr1);
        }
    }


}
void secondWindow::on_firstMatrix_itemChanged(QTableWidgetItem *item){
    QString a = item->text();
    float b = a.split(" ")[0].toFloat();
    QString r= QString::number(b);
    item->setText(r);
}
void secondWindow::on_secondMatrix_itemChanged(QTableWidgetItem *item){
    QString a = item->text();
    float b = a.split(" ")[0].toFloat();
    QString r= QString::number(b);
    item->setText(r);
}

