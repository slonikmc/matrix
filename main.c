#include "libs/data_structures/matrix/matrix.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

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
    for (int i = 0; i < m.nRows; i++) {
        for (int j = 0; j < i; j++) {
            swap(&m.values[i][j], &m.values[j][i]);
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
    long long *a = (long long *) malloc(sizeof(int) * m.nRows);
    for (int i = 0; i < m.nRows; i++) {
        a[i] = getSum(m.values[i], m.nCols);
    }
    if (isUnique(a, m.nRows))
        transposeIfMatrixHasNotEqualSumOfRows(m);
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
//    if (isMutuallyInverseMatrices(m1, m2))
//        printf("isMutuallyInverseMatrices");
//    else
//        printf("isNotMutuallyInverseMatrices");
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
    long long res = findSumOfMaxesOfPseudoDiagonal(m);

//    Выводит 20
//    printf("%lld", res);

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

//    printf("%d", getMinInArea(m);
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
    test();

    return 0;
}
