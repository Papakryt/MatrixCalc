#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);

    ui2 = new secondWindow();

    connect(ui2,&secondWindow::firstWindow,this,&MainWindow::show);
}
MainWindow::~MainWindow(){delete ui;}
void MainWindow::checking(int fMR,int fMC, int sMR, int sMC, bool check){
    ui->comboBox->clear();
    operation=0;
    if (not((fMR==0) or (fMC==0))){
        ui->comboBox->addItem("");
        if (check){
            ui->comboBox->addItem("Транспонировать");
            if(fMR==fMC){
                ui->comboBox->addItem("Диагональный вид");
                ui->comboBox->addItem("Нахождение определителя");
            }
        }
        else{
            if (not((sMR==0)or(sMC==0))){
                if((fMR==sMR)and(fMC==sMC)){
                    ui->comboBox->addItem("Сложение");
                    ui->comboBox->addItem("Вычитание");
                }
                if (fMC==sMR){
                    ui->comboBox->addItem("Умножение");
                }
            }
        }
    }

}
void MainWindow::on_radioButton_toggled(bool checked){
    if (checked){
        ui->spinBox_3->hide();
        ui->spinBox_4->hide();
        ui->label_2->hide();
        ui->label->setText("Введите размер матрицы");
        oneMatrix=true;
    }
    else{
        ui->spinBox_3->show();
        ui->spinBox_4->show();
        ui->label_2->show();
        ui->label->setText("Введите размер первой матрицы");
        oneMatrix=false;
    }
    checking(firstMatrixRows,firstMatrixColumns,secondMatrixRows,secondMatrixColumns,oneMatrix);
}
void MainWindow::on_spinBox_valueChanged(int arg1){
    firstMatrixRows=arg1;
    checking(firstMatrixRows,firstMatrixColumns,secondMatrixRows,secondMatrixColumns,oneMatrix);
}


void MainWindow::on_spinBox_2_valueChanged(int arg1){
    firstMatrixColumns=arg1;
    checking(firstMatrixRows,firstMatrixColumns,secondMatrixRows,secondMatrixColumns,oneMatrix);
}
void MainWindow::on_spinBox_3_valueChanged(int arg1){
    secondMatrixRows=arg1;
    checking(firstMatrixRows,firstMatrixColumns,secondMatrixRows,secondMatrixColumns,oneMatrix);
}
void MainWindow::on_spinBox_4_valueChanged(int arg1){
    secondMatrixColumns=arg1;
    checking(firstMatrixRows,firstMatrixColumns,secondMatrixRows,secondMatrixColumns,oneMatrix);
}
void MainWindow::on_pushButton_clicked(){
    if (operation==1 or operation==2 or operation==3 or operation==4 or operation==5 or operation==6){
        ui2->show();
        ui2->receiveAll(firstMatrixRows,firstMatrixColumns,secondMatrixRows,secondMatrixColumns,operation,oneMatrix);
        this->close();
    }
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    if(oneMatrix){
        operation=index;
    }
    else{
        if ((firstMatrixRows==secondMatrixRows)and(firstMatrixColumns==secondMatrixColumns)){
            operation=index+3;
        }
        else if(firstMatrixColumns==secondMatrixRows){
            operation=index+5;
        }
    }
}

