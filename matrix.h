#pragma once
#include <iostream>
#include <QTableWidgetItem>
class matrix {
public:
    float** arr;
    matrix(int Rows, int Columns);
    void fill(int i,int j,float arg);
    void print();
    float retRC(int row,int col);
    void similitude (const matrix& other);
    void operator + (matrix& other);
    void operator - (matrix& other);
    void operator * (matrix& other);
    void char_multi(matrix arrchar);
    void Diagonal_matrix();
    void transposition();
    float determinant();
     ~matrix();
     int rows, columns;
     float memN,res=1;
};

