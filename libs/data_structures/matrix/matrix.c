//
// Created by Akelk on 09.02.2022.
//

#include <assert.h>
#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>


static void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

matrix getMemMatrix(int nRows, int nCols) {
    int **values = (int **) malloc(sizeof(int *) * nRows);
    for (int i = 0; i < nRows; i++)
        values[i] = (int *) malloc(sizeof(int) * nCols);

    return (matrix) {values, nRows, nCols};
}

matrix *getMemArrayOfMatrices(int nMatrices, int nRows, int nCols) {
    matrix *ms = (matrix *) malloc(sizeof(matrix) * nMatrices);
    for (int i = 0; i < nMatrices; i++)
        ms[i] = getMemMatrix(nRows, nCols);

    return ms;
}

void freeMemMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        free(m.values[i]);
    free(m.values);
}

void freeMemMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        freeMemMatrix(ms[i]);
    free(ms);
}

void inputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            scanf("%d", &m.values[i][j]);
}

void inputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        inputMatrix(ms[i]);
}

void outputMatrix(matrix m) {
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++)
            printf("%d ", m.values[i][j]);
        printf("\n");
    }
    printf("%\n");
}

void outputMatrices(matrix *ms, int nMatrices) {
    for (int i = 0; i < nMatrices; i++)
        outputMatrix(ms[i]);
    printf("\n");
}

void swapRows(matrix m, int i1, int i2) {
    swap(&m.values[i1], &m.values[i2]);
}

void swapColumns(matrix m, int j1, int j2) {
    for (int i = 0; i < m.nRows; i++) {
        swap(&m.values[i][j1], &m.values[i][j2]);
    }
}

void insertionSortRowsMatrixByRowCriteria(matrix m, int (*criteria)(const int *, int)) {
    int *a = (int *) malloc(sizeof(int) * m.nRows);
    for (int i = 0; i < m.nRows; i++) {
        a[i] = criteria(m.values[i], m.nCols);
    }
    for (int i = 1; i < m.nRows; i++) {
        int iRead = i;
        while (a[iRead - 1] > a[iRead] && iRead > 0) {
            swap(&a[iRead - 1], &a[iRead]);
            swapRows(m, iRead - 1, iRead);
            iRead--;
        }
    }
}

void insertionSortColsMatrixByColCriteria(matrix m, int (*criteria)(const int *, int)) {
    int *a = (int *) malloc(sizeof(int) * m.nCols);
    int *col = (int *) malloc(sizeof(int) * m.nRows);
    for (int j = 0; j < m.nCols; j++) {
        for (int i = 0; i < m.nRows; i++) {
            col[i] = m.values[i][j];
        }
        a[j] = criteria(col, m.nRows);
    }
    for (int i = 1; i < m.nCols; i++) {
        int iRead = i;
        while (a[iRead - 1] > a[iRead] && iRead > 0) {
            swapColumns(m, iRead - 1, iRead);
            swap(&a[iRead - 1], &a[iRead]);
            iRead--;
        }
    }
}

bool isSquareMatrix(matrix m) {
    return m.nRows == m.nCols;
}

bool areTwoMatricesEqual(matrix m1, matrix m2) {
    if (m1.nCols == m2.nCols && m1.nRows == m2.nRows) {
        for (int i = 0; i < m1.nRows; i++)
            for (int j = 0; j < m2.nCols; j++)
                if (m1.values[i][j] != m2.values[i][j])
                    return false;
    } else
        return false;

    return true;
}

bool isEMatrix(matrix m) {
    if (!isSquareMatrix(m))
        return false;
    else {
        for (int i = 0; i < m.nRows; i++) {
            for (int j = 0; j < m.nCols; j++) {
                if (i == j && m.values[i][j] != 1 || i != j && m.values[i][j] != 0)
                    return false;
            }
        }
    }
    return true;
}

bool isSymmetricMatrix(matrix m) {
    if (!isSquareMatrix(m))
        return false;
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            if (m.values[i][j] != m.values[j][i])
                return false;
        }
    }
    return true;
}

void transposeSquareMatrix(matrix m) {
    assert(isSquareMatrix(m));
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < i; j++) {
            swap(&m.values[i][j], &m.values[j][i]);
        }
    }
}

position getMinValuePos(matrix m) {
    position positionOfMinElem = {0, 0};
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            position curPosition = {i, j};
            if (m.values[curPosition.rowIndex][curPosition.colIndex] <
                m.values[positionOfMinElem.rowIndex][positionOfMinElem.colIndex])
                positionOfMinElem = curPosition;
        }
    }

    return positionOfMinElem;
}

position getMaxValuePos(matrix m) {
    position positionOfMaxElem = {0, 0};
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            position curPosition = {i, j};
            if (m.values[curPosition.rowIndex][curPosition.colIndex] >
                m.values[positionOfMaxElem.rowIndex][positionOfMaxElem.colIndex])
                positionOfMaxElem = curPosition;
        }
    }

    return positionOfMaxElem;
}

matrix createMatrixFromArray(const int *a, size_t nRows, size_t nCols) {
    matrix m = getMemMatrix(nRows, nCols);

    int k = 0;
    for (int i = 0; i < nRows; i++)
        for (int j = 0; j < nCols; j++)
            m.values[i][j] = a[k++];

    return m;
}

matrix *createArrayOfMatrixFromArray(const int *values, size_t nMatrices, size_t nRows, size_t nCols) {
    matrix *ms = getMemArrayOfMatrices(nMatrices, nRows, nCols);
    int l = 0;
    for (int k = 0; k < nMatrices; k++)
        for (int i = 0; i < nRows; i++)
            for (int j = 0; j < nCols; j++)
                ms[k].values[i][j] = values[l++];

    return ms;
}

