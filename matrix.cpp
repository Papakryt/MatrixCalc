#include "matrix.h"
matrix::matrix(int Rows, int Columns) {
    this->arr = new float* [Rows];
    for (int i = 0; i < Rows; i++) {
        arr[i] = new float[Columns];
    }
    rows=Rows;
    columns=Columns;
}
void matrix::fill(int i,int j,float arg) {
    arr[i][j]=arg;
}
void matrix::print() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << "\t" << arr[i][j] << "\t";
        }
        std::cout << "\n";
    }
}
float matrix::retRC(int row,int col){return arr[row][col];}
void matrix::similitude (const matrix& other) {
    this->rows = other.rows;
    this->columns = other.columns;
    if (this->arr != nullptr) {
        for (int i = 0; i < rows; i++) {
            delete[] arr[i];
        }
        delete[] arr;
    }
    this->arr = new float* [other.rows];
    for (int i = 0; i < rows; i++) {
        this->arr[i] = new float[other.columns];
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            this->arr[i][j] = other.arr[i][j];
        }
    }
}
void matrix::operator + (matrix& other) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            this->arr[i][j] += other.arr[i][j];
        }
    }

}
void matrix::operator - (matrix& other) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            this->arr[i][j] -= other.arr[i][j];
        }
    }

}
void matrix::operator * (matrix& other) {
    matrix res(rows, other.columns);
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < other.columns; j++) {
            float mem = 0;
            for (int g = 0; g < this->columns; g++) {
                mem += this->arr[i][g] * other.arr[g][j];
            }
            res.arr[i][j] = mem;
        }
    }
    similitude(res);
}
void matrix::char_multi(matrix arrchar) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            arr[i][j] *= arrchar.arr[0][0];
        }
    }
    std::cout << "Result\n";
    print();
}
void matrix::Diagonal_matrix() {
    for (int z = 0; z < rows; z++) {
        float *mem = new float[columns] {};
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (i == z) {
                    mem[j] = arr[i][j];
                }
                else if ((i > z) and (j == z)) {
                    memN = arr[i][j];
                    arr[i][z] = 0;
                }
                else if ((i > z) and (j >= z)) {
                    float ymn = memN / mem[z];
                    arr[i][j] = arr[i][j] - mem[j] * ymn;
                }
            }
        }
    }
}
void matrix::transposition() {
    matrix res(columns, rows);
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < rows; j++) {
            res.arr[i][j] = arr[j][i];
        }
    }
    similitude(res);

}
float matrix::determinant() {
    Diagonal_matrix();
    for (int i = 0; i < rows; i++) {
        res *= arr[i][i];
    }
    return res;
}
matrix::~matrix() {
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}
