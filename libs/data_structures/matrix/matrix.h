//
// Created by Akelk on 09.02.2022.
//

#ifndef INC_5D_MATRIX_H
#define INC_5D_MATRIX_H

#include <stdlib.h>

typedef struct matrix {
    int **values; // элементы матрицы
    int nRows; // количество рядов
    int nCols; // количество столбцов
} matrix;

typedef struct position {
    int rowIndex;
    int colIndex;
} position;

// Возвращает матрицу. Размещает в динамической памяти матрицу размером nRows на nCols.
matrix getMemMatrix(int nRows, int nCols);

// Возвращает указатель на нулевую матрицу. Размещает в динамической памяти массив из nMatrices матриц размером nRows на nCols.
matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols);

// Освобождает память, выделенную под хранение матрицы m.
void freeMemMatrix(matrix *m);

// Освобождает память, выделенную под хранение массива ms из nMatrices матриц.
void freeMemMatrices(matrix *ms, int nMatrices);

// ввод матрицы m.
void inputMatrix(matrix m);

// ввод массива из nMatrices матриц, хранящейся по адресу ms.
void inputMatrices(matrix *ms, int nMatrices);

//вывод матрицы m.
void outputMatrix(matrix m);

// вывод массива из nMatrices матриц, хранящейся по адресу ms.
void outputMatrices(matrix *ms, int nMatrices);

// Обмен строк с порядковыми номерами i1 и i2 в матрице m.
void swapRows(matrix m, int i1, int i2);

//  обмен строк с порядковыми номерами i1 и i2 в матрице m.
void swapRows(matrix m, int i1, int i2);

#endif //INC_5D_MATRIX_H
