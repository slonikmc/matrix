#include "libs/data_structures/matrix/matrix.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

void test_getMemMatrix_commonCase() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6
            },
            2, 3
    );
    int nRows = m.nRows;
    int nCols = m.nCols;
    matrix m2 = getMemMatrix(nRows, nCols);
    assert(m2.nRows == nRows);
    assert(m2.nCols == nCols);
    freeMemMatrix(m);
    freeMemMatrix(m2);
}

void test_getMemArrayOfMatrices_commonCase() {
    matrix *m = getMemArrayOfMatrices(3, 2, 2);
    assert(m != 0);
    assert(m[0].nRows == 2);
    assert(m[0].nCols == 2);
    assert(m[1].nRows == 2);
    assert(m[1].nCols == 2);
    assert(m[2].nRows == 2);
    assert(m[2].nCols == 2);
    assert(m[0].values != 0);
    assert(m[1].values != 0);
    assert(m[2].values != 0);
    freeMemMatrices(m, 3);
}

void test_swapRows_commonCase() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6
            },
            2, 3
    );
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    4, 5, 6,
                    1, 2, 3
            },
            2, 3
    );
    swapRows(m, 0, 1);

    assert(m.values[0][0] == m2.values[0][0]);
    assert(m.values[0][2] == m2.values[0][2]);
    assert(m.values[0][1] == m2.values[0][1]);
    freeMemMatrix(m);
    freeMemMatrix(m2);
}

void test_swapRows_sameRow() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6
            },
            2, 3
    );
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6
            },
            2, 3
    );
    swapRows(m, 1, 1);

    assert(m.values[0][1] == m2.values[0][1]);
    assert(m.values[0][2] == m2.values[0][2]);
    assert(m.values[0][0] == m2.values[0][0]);
    freeMemMatrix(m);
    freeMemMatrix(m2);
}

void test_swapRows() {
    test_swapRows_commonCase();
    test_swapRows_sameRow();
}

void test_swapColumns_commonCase() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6
            },
            2, 3
    );
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6
            },
            2, 3
    );
    swapColumns(m, 0, 1);

    assert(m.values[0][0] == m2.values[0][1]);
    assert(m.values[0][1] == m2.values[0][0]);
    assert(m.values[0][2] == m2.values[0][2]);
    freeMemMatrix(m);
    freeMemMatrix(m2);
}

void test_swapColumns_sameColumn() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6
            },
            2, 3
    );
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6
            },
            2, 3
    );
    swapColumns(m, 1, 1);

    assert(m.values[0][0] == m2.values[0][0]);
    assert(m.values[0][1] == m2.values[0][1]);
    assert(m.values[0][2] == m2.values[0][2]);
    freeMemMatrix(m);
    freeMemMatrix(m2);
}

void test_swapColumns() {
    test_swapColumns_commonCase();
    test_swapColumns_sameColumn();
}

int getMin_criteriaForSort(const int *a, int n) {
    int min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min)
            min = a[i];
    }
    return min;
}

void test_insertionSortRowsMatrixByRowCriteria() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    7, 8, 8,
                    4, 5, 6,
                    7, 8, 1
            },
            3, 3
    );
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    7, 8, 1,
                    4, 5, 6,
                    7, 8, 8
            },
            3, 3
    );
    insertionSortRowsMatrixByRowCriteria(m, getMin_criteriaForSort);
    assert(areTwoMatricesEqual(m, m2));
    freeMemMatrix(m);
    freeMemMatrix(m2);
}

void test_insertionSortColsMatrixByColCriteria() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    7, 8, 8,
                    4, 5, 6,
                    7, 8, 1
            },
            3, 3
    );
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    8, 7, 8,
                    6, 4, 5,
                    7, 8, 1
            },
            3, 3
    );

    insertionSortColsMatrixByColCriteria(m, getMin_criteriaForSort);
    assert(areTwoMatricesEqual(m, m2));
    freeMemMatrix(m);
    freeMemMatrix(m2);
}

void test_isSquareMatrix_commonCase() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9
            },
            3, 3
    );
    assert(isSquareMatrix(m));
    freeMemMatrix(m);
}

void test_isSquareMatrix_matrix_1_at_1() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1
            },
            1, 1
    );
    assert(isSquareMatrix(m));
    freeMemMatrix(m);
}

void test_isSquareMatrix() {
    test_isSquareMatrix_commonCase();
    test_isSquareMatrix_matrix_1_at_1();
}

void test_areTwoMatricesEqual() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6
            },
            2, 3
    );
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6
            },
            2, 3
    );
    assert(areTwoMatricesEqual(m, m2));
    freeMemMatrix(m);
    freeMemMatrix(m2);
}

void test_isEMatrix_commonCase() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 1, 0,
                    0, 0, 1
            },
            3, 3
    );
    assert(isEMatrix(m));
    freeMemMatrix(m);
}

void test_isEMatrix_matrix_1_at_1() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1,
            },
            1, 1
    );
    assert(isEMatrix(m));
    freeMemMatrix(m);
}

void test_isEMatrix() {
    test_isEMatrix_commonCase();
    test_isEMatrix_matrix_1_at_1();
}

void test_isSymmetricMatrix_commonCase() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 42, 9,
                    42, 1, 5,
                    9, 5, 42
            },
            3, 3
    );
    assert(isSymmetricMatrix(m));
    freeMemMatrix(m);
}

void test_isSymmetricMatrix_matrix_1_at_1() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1,
            },
            1, 1
    );
    assert(isSymmetricMatrix(m));
    freeMemMatrix(m);
}

void test_isSymmetricMatrix() {
    test_isSymmetricMatrix_commonCase();
    test_isSymmetricMatrix_matrix_1_at_1();
}

void test_transposeSquareMatrix() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9
            },
            3, 3
    );
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    1, 4, 7,
                    2, 5, 8,
                    3, 6, 9
            },
            3, 3
    );
    transposeSquareMatrix(m);
    assert(areTwoMatricesEqual(m, m2));
    freeMemMatrix(m);
    freeMemMatrix(m2);
}

void test_getMinValuePos() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9
            },
            3, 3
    );
    position pos = getMinValuePos(m);
    assert(pos.rowIndex == 0);
    assert(pos.colIndex == 0);
    freeMemMatrix(m);
}

void test_getMaxValuePos() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9
            },
            3, 3
    );
    position pos = getMaxValuePos(m);
    assert(pos.rowIndex == 2);
    assert(pos.colIndex == 2);
    freeMemMatrix(m);
}

void test() {
    test_getMemMatrix_commonCase();
    test_getMemArrayOfMatrices_commonCase();
    test_swapRows();
    test_swapColumns();
    test_insertionSortRowsMatrixByRowCriteria();
    test_insertionSortColsMatrixByColCriteria();
    test_isSquareMatrix();
    test_areTwoMatricesEqual();
    test_isEMatrix();
    test_isSymmetricMatrix();
    test_transposeSquareMatrix();
    test_getMinValuePos();
    test_getMaxValuePos();
}

///////// Chapter 2  //////////

void task_1() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9
            },
            3, 3
    );
    position min = getMinValuePos(m);
    position max = getMaxValuePos(m);
    swapRows(m, min.rowIndex, max.rowIndex);
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int getMax(const int *a, int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

void sortRowsByMaxElement(matrix m) {
    insertionSortRowsMatrixByRowCriteria(m, getMax);
}

void task_2() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 42, 3,
                    4, 5, 6,
                    7, 8, 9
            },
            3, 3
    );
    sortRowsByMaxElement(m);
}

int getMin(const int *a, int n) {
    int min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min)
            min = a[i];
    }
    return min;
}

void sortColsByMinElement(matrix m) {
    insertionSortColsMatrixByColCriteria(m, getMin);
}

void task_3() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 9, 3,
                    4, 5, 6,
                    7, 8, 9
            },
            3, 3
    );
    sortColsByMinElement(m);
}

matrix mulMatrices(matrix m1, matrix m2) {
    matrix res = getMemMatrix(m1.nRows, m1.nCols);
    for (int i = 0; i < m1.nRows; i++)
        for (int j = 0; j < m1.nCols; j++) {
            res.values[i][j] = 0;
            for (int nRow = 0; nRow < m2.nRows; nRow++)
                res.values[i][j] += m1.values[i][nRow] * m2.values[nRow][j];
        }
    return res;
}

void getSquareOfMatrixIfSymmetric(matrix *m) {
    matrix m1 = *m;
    matrix m2 = *m;
    *m = mulMatrices(m1, m2);
}

void task_4() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    2, 1, 2,
                    3, 2, 1
            },
            3, 3
    );
    if (isSymmetricMatrix(m)) {
        getSquareOfMatrixIfSymmetric(&m);
    }
}

bool isUnique(const long long *a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j] == a[i])
                return false;
        }
    }
    return true;
}

long long getSum(const int *a, int n) {
    long long res = 0;
    for (int i = 0; i < n; i++)
        res += a[i];
    return res;
}

void transposeIfMatrixHasNotEqualSumOfRows(matrix m) {
    assert(isSquareMatrix(m));
    long long *sumOfElemRow = (long long *) malloc(sizeof(int) * m.nRows);
    for (int i = 0; i < m.nRows; i++) {
        sumOfElemRow[i] = getSum(m.values[i][0], m.nCols);
    }
    if (isUnique(sumOfElemRow, m.nRows)) {
        for (int i = 0; i < m.nRows; i++) {
            for (int j = 0; j < i; j++) {
                swap(&m.values[i][j], &m.values[j][i]);
            }
        }
    }
}

void task_5() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 1, 3,
                    2, 1, 2,
                    7, 8, 9
            },
            3, 3
    );
    matrix answerM = createMatrixFromArray(
            (int[]) {
                    1, 2, 7,
                    1, 1, 8,
                    3, 2, 9
            },
            3, 3
    );
    transposeIfMatrixHasNotEqualSumOfRows(m);
    outputMatrix(m);
    assert(areTwoMatricesEqual(m, answerM));
}

bool isMutuallyInverseMatrices(matrix m1, matrix m2) {
    matrix chekEMatrix = mulMatrices(m1, m2);
    if (isEMatrix(chekEMatrix))
        return true;
    return false;
}

void task_6() {
    matrix m1 = createMatrixFromArray(
            (int[]) {
                    1, 2,
                    3, 5
            },
            2, 2
    );
    matrix m2 = createMatrixFromArray(
            (int[]) {
                    -5, 2,
                    3, -1
            },
            2, 2
    );
    assert(isMutuallyInverseMatrices(m1, m2) == true);
    freeMemMatrix(m1);
    freeMemMatrix(m2);
}

long long max(long long a, long long b) {
    return a > b ? a : b;
}

long long findSumOfMaxesOfPseudoDiagonal(matrix m) {
    long long sum = 0;
    for (int i = 1; i < m.nRows; i++) {
        int row = i;
        int column = 0;
        long long maxValue = m.values[row][column];
        while (row < m.nRows - 1 && column < m.nCols - 1) {
            row++;
            column++;
            maxValue = max(maxValue, m.values[row][column]);
        }
        sum += maxValue;
    }
    for (int j = 1; j < m.nCols; j++) {
        int row = 0;
        int column = j;
        long long maxValue = m.values[row][column];
        while (row < m.nRows - 1 && column < m.nCols - 1) {
            row++;
            column++;
            maxValue = max(maxValue, m.values[row][column]);
        }
        sum += maxValue;
    }

    return sum;
}

void task_7() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 2, 5, 4,
                    1, 3, 6, 3,
                    3, 2, 1, 2
            },
            3, 4
    );
    assert(findSumOfMaxesOfPseudoDiagonal(m) == 20);
    freeMemMatrix(m);
}

int getMinInArea(matrix m) {
    position max = getMaxValuePos(m);
    int rowShape = max.rowIndex;
    int leftColumn = max.colIndex;
    int rightColumn = max.colIndex;
    int min = m.values[max.rowIndex][max.colIndex];
    while (rowShape > 0) {
        rowShape--;
        if (leftColumn > 0)
            leftColumn--;
        if (rightColumn < m.nCols)
            rightColumn++;
        for (int i = leftColumn; i < rightColumn; i++) {
            if (m.values[rowShape][i] < min)
                min = m.values[rowShape][i];
        }
    }
    return min;
}

void task_8() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 1, 5, 4,
                    7, 2, 6, 8,
                    11, 10, 13, 9
            },
            3, 4
    );
    assert(getMinInArea(m) == 1);
    freeMemMatrix(m);
}

float getDistance(const int *a, int n) {
    float distance = 0;
    for (int i = 0; i < n; i++) {
        distance += (float) a[i] * (float) a[i];
    }

    return sqrtf(distance);
}

void insertionSortRowsMatrixByRowCriteriaF(matrix m, float (*criteria)(const int *, int)) {
    float *a = (float *) malloc(sizeof(float) * m.nRows);
    for (int i = 0; i < m.nRows; i++) {
        a[i] = criteria(m.values[i], m.nCols);
    }
    for (int i = 1; i < m.nRows; i++) {
        int iRead = i;
        while (a[iRead - 1] > a[iRead] && iRead > 0) {
            swap((int *) &a[iRead - 1], (int *) &a[iRead]);
            swapRows(m, iRead - 1, iRead);
            iRead--;
        }
    }
}

void sortByDistances(matrix m) {
    insertionSortRowsMatrixByRowCriteriaF(m, getDistance);
}

void task_9() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    0, 0, 0, 0,
                    5, 4, 2, 3,
                    1, 1, 2, 3
            },
            3, 4
    );
    matrix answerM = createMatrixFromArray(
            (int[]) {
                    0, 0, 0, 0,
                    1, 1, 2, 3,
                    5, 4, 2, 3
            },
            3, 4
    );
    sortByDistances(m);
    assert(areTwoMatricesEqual(m, answerM));
    freeMemMatrix(m);
    freeMemMatrix(answerM);
}

int cmp_long_long(const void *pa, const void *pb) {
    int arg1 = *(const int *) pa;
    int arg2 = *(const int *) pb;
    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;

    return 0;
}

int countNUnique(long long *a, int n) {
    int nUnique = 1;
    int iRead = 1;
    while (iRead < n) {
        if (a[iRead] > a[iRead - 1])
            nUnique++;
        iRead++;
    }
    return nUnique;
}

int countEqClassesByRowsSum(matrix m) {
    long long *eqClasses = (long long *) malloc(sizeof(long long) * m.nRows);
    for (int i = 0; i < m.nRows; i++) {
        eqClasses[i] = getSum(m.values[i], m.nCols);
    }
    qsort(eqClasses, m.nRows, sizeof(long long), cmp_long_long);
    int nUniqueClasses = countNUnique(eqClasses, m.nRows);

    return nUniqueClasses;
}

void task_10() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    7, 1,
                    2, 7,
                    5, 4,
                    4, 3,
                    1, 6,
                    8, 0
            },
            6, 2
    );
    assert(countEqClassesByRowsSum(m) == 3);
    freeMemMatrix(m);
}

int getNSpecialElement(matrix m) {
    int nSpecialElements = 0;
    for (int j = 0; j < m.nCols; j++) {
        int sum = 0;
        for (int iSum = 0; iSum < m.nRows; iSum++)
            sum += m.values[iSum][j];
        for (int i = 0; i < m.nRows; i++) {
            if (m.values[i][j] > sum - m.values[i][j])
                nSpecialElements++;
        }
    }
    return nSpecialElements;
}

void task_11() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    3, 5, 5, 4,
                    2, 3, 6, 7,
                    12, 2, 1, 2
            },
            3, 4
    );
    assert(getNSpecialElement(m) == 2);
    freeMemMatrix(m);
}

position getLeftMin(matrix m) {
    position min = {0, 0};
    for (int i = 0; i < m.nRows; i++)
        for (int j = 0; j < m.nCols; j++)
            if (m.values[i][j] == m.values[min.rowIndex][min.colIndex] && i < min.rowIndex ||
                m.values[i][j] < m.values[min.rowIndex][min.colIndex])
                min = (position) {i, j};
    return min;
}

void swapPenultimateRow(matrix m, int n) {
    position min = getLeftMin(m);
    int *columnForSwap = malloc(sizeof(int) * m.nRows);
    for (int i = 0; i < m.nRows; i++) {
        columnForSwap[i] = m.values[i][min.colIndex];
    }
    for (int j = 0; j < m.nCols; j++) {
        m.values[n][j] = columnForSwap[j];
    }
}

void task_12() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 1
            },
            3, 3
    );
    matrix answerM = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    1, 4, 7,
                    7, 8, 1
            },
            3, 3
    );
    swapPenultimateRow(m, m.nRows - 2);
    assert(areTwoMatricesEqual(m, answerM));
    freeMemMatrix(m);
    freeMemMatrix(answerM);
}

bool isNonDescendingSorted(int *a, int n) {
    for (int i = 1; i < n; i++)
        if (a[i - 1] > a[i])
            return false;
    return true;
}

bool hasAllNonDescendingRows(matrix m) {
    for (int i = 0; i < m.nRows; i++)
        if (!isNonDescendingSorted(m.values[i], m.nCols))
            return false;
    return true;
}

int countNonDescendingRowsMatrices(matrix *ms, int nMatrix) {
    int nNonDescendingRowsMatrices = 0;
    for (int i = 0; i < nMatrix; i++)
        if (hasAllNonDescendingRows(ms[i]))
            nNonDescendingRowsMatrices++;
    return nNonDescendingRowsMatrices;
}

void task_13() {
    matrix *arrayMatrix = createArrayOfMatrixFromArray(
            (int[]) {
                    7, 1,
                    1, 1,

                    1, 6,
                    2, 2,

                    5, 4,
                    2, 3,

                    1, 3,
                    7, 9
            },
            4, 2, 2
    );
    assert(countNonDescendingRowsMatrices(arrayMatrix, 4) == 2);
    freeMemMatrices(arrayMatrix, 4);
}

int countValues(const int *a, int n, int value) {
    int valueTracker = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == value)
            valueTracker++;
    }
    return valueTracker;
}

int countZeroRows(matrix m) {
    int nZeroRows = 0;
    for (int i = 0; i < m.nRows; i++) {
        if (countValues(m.values[i], m.nCols, 0) == m.nCols)
            nZeroRows++;
    }
    return nZeroRows;
}

void test_countZeroRows_commonCase() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    0, 0,
                    2, 0,
                    5, 1,
                    0, 3,
                    0, 0,
                    8, 3
            },
            6, 2
    );
    assert(countZeroRows(m) == 2);
    freeMemMatrix(m);
}

void printMatrixWithMaxZeroRows(matrix *ms, int nMatrix) {
    int *matrixZeroRows = malloc(sizeof(int) * nMatrix);
    int maxZeroRows = 0;
    for (int i = 0; i < nMatrix; i++) {
        matrixZeroRows[i] = countZeroRows(ms[i]);
        maxZeroRows = max(maxZeroRows, matrixZeroRows[i]);
    }
    for (int i = 0; i < nMatrix; i++) {
        if (matrixZeroRows[i] == maxZeroRows)
            outputMatrix(ms[i]);
    }
    free(matrixZeroRows);
}

void task_14() {
    matrix *arrayMatrix = createArrayOfMatrixFromArray(
            (int[]) {
                    0, 1,
                    1, 0,
                    0, 0,

                    1, 1,
                    2, 1,
                    1, 1,

                    0, 0,
                    0, 0,
                    4, 7,

                    0, 0,
                    0, 1,
                    0, 0,

                    0, 1,
                    0, 2,
                    0, 3
            },
            5, 3, 2
    );
    test_countZeroRows_commonCase();
    // printMatrixWithMaxZeroRows(arrayMatrix, 5);     print true answer at task.
    freeMemMatrices(arrayMatrix, 5);
}

int getNorm(matrix m) {
    position minElem = getMinValuePos(m);
    position maxElem = getMaxValuePos(m);
    return max(abs(m.values[minElem.rowIndex][minElem.colIndex]), m.values[maxElem.rowIndex][maxElem.colIndex]);
}

void printMatrixWithMinNorm(matrix *ms, int nMatrix) {
    int minNorm = INT_MAX;
    int *matrixMinNorm = malloc(sizeof(int) * nMatrix);
    for (int i = 0; i < nMatrix; i++) {
        matrixMinNorm[i] = getNorm(ms[i]);
        minNorm = minNorm > matrixMinNorm[i] ? matrixMinNorm[i] : minNorm;
    }

    for (int i = 0; i < nMatrix; i++) {
        if (matrixMinNorm[i] == minNorm)
            outputMatrix(ms[i]);
    }
}

void task_15() {
    matrix *arrayMatrix = createArrayOfMatrixFromArray(
            (int[]) {
                    0, 1,
                    -1, 0,

                    2, 2,
                    2, -1,

                    0, 0,
                    4, 7,

                    0, 0,
                    0, 1,

                    0, 1,
                    0, 2
            },
            5, 2, 2
    );
    // printMatrixWithMinNorm(arrayMatrix, 5);
    freeMemMatrices(arrayMatrix, 5);
}

int min2(int a, int b) {
    return a < b ? a : b;
}

int getNSpecialElement2(matrix m) {
    int nSpecElem = 0;
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < m.nCols; j++) {
            int isSpec = 1;
            int valueChecker;
            int curElem = m.values[i][j];
            for (int lIndex = 0; lIndex < j; lIndex++) {
                valueChecker = min2(curElem, m.values[i][lIndex]);
                if (valueChecker == curElem) {
                    isSpec = 0;
                    break;
                }
            }
            for (int rIndex = j + 1; rIndex < m.nCols; rIndex++) {
                valueChecker = min2(curElem, m.values[i][rIndex]);
                if (valueChecker != curElem) {
                    isSpec = 0;
                    break;
                }
            }
            if (isSpec)
                nSpecElem++;
        }
    }

    return nSpecElem;
}


void task_16() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    2, 3, 5, 5, 4,
                    6, 2, 3, 8, 14,
                    12, 12, 2, 1, 2
            },
            3, 5
    );

    assert(getNSpecialElement2(m) == 4);
    freeMemMatrix(m);
}

int main() {
    task_1();
    task_2();
    task_3();
    task_4();
    task_5();
    task_6();
    task_7();
    task_8();
    task_9();
    task_10();
    task_11();
    task_12();
    task_13();
    task_14();
    task_15();
    task_16();
    test();

    return 0;
}
