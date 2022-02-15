#include "libs/data_structures/matrix/matrix.h"
#include <assert.h>

void test_getMemMatrix() {
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
}

void test_getMemArrayOfMatrices() {
    matrix *m = getMemArrayOfMatrices(3, 2, 2);
    assert(m != 0);
    assert(m[0].nRows == 2);
    assert(m[0].nCols == 2);
    assert(m[1].nRows == 2);
    assert(m[1].nCols == 2);
    assert(m[2].nRows == 2);
    assert(m[2].nCols == 2);
    assert(m[0].values != m[1].values != m[2].values != 0);
}

void test_swapRows1() {
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

    assert(m.values[0][1] == m2.values[0][1]);
    assert(m.values[0][2] == m2.values[0][2]);
    assert(m.values[0][3] == m2.values[0][3]);
}

void test_swapRows2() {
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
    assert(m.values[0][3] == m2.values[0][3]);
}

void test_swapRows() {
    test_swapRows1();
    test_swapRows2();
}

void test_swapColumns1() {
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
}

void test_swapColumns2() {
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
}

void test_swapColumns() {
    test_swapColumns1();
    test_swapColumns2();
}

//void test_insertionSortRowsMatrixByRowCriteria() {
//    matrix m = createMatrixFromArray(
//            (int[]) {
//                    0, 2, 3,
//                    4, 0, 0,
//                    7, 8, 9
//            },
//            3, 3
//    );
//    matrix m2 = createMatrixFromArray(
//            (int[]) {
//                    4, 0, 0,
//                    0, 2, 3,
//                    7, 8, 9
//            },
//            3, 3
//    );
//    insertionSortRowsMatrixByRowCriteria(m, countZeros);
//    outputMatrix(m);
//    assert(areTwoMatricesEqual(m, m2));
//}

void test_isSquareMatrix1() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9
            },
            3, 3
    );
    assert(isSquareMatrix(m));
}

void test_isSquareMatrix2() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1
            },
            1, 1
    );
    assert(isSquareMatrix(m));
}

void test_isSquareMatrix() {
    test_isSquareMatrix1();
    test_isSquareMatrix2();
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
}

void test_isEMatrix1() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 0, 0,
                    0, 1, 0,
                    0, 0, 1
            },
            3, 3
    );
    assert(isEMatrix(m));
}

void test_isEMatrix2() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1,
            },
            1, 1
    );
    assert(isEMatrix(m));
}

void test_isEMatrix() {
    test_isEMatrix1();
    test_isEMatrix2();
}

void test_isSymmetricMatrix1() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 42, 9,
                    42, 1, 5,
                    9, 5, 42
            },
            3, 3
    );
    assert(isSymmetricMatrix(m));
}

void test_isSymmetricMatrix2() {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1,
            },
            1, 1
    );
    assert(isSymmetricMatrix(m));
}

void test_isSymmetricMatrix() {
    test_isSymmetricMatrix1();
    test_isSymmetricMatrix2();
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
}

void test() {
    test_getMemMatrix();
    test_getMemArrayOfMatrices();
    test_swapRows();
    test_swapColumns();
//    test_insertionSortRowsMatrixByRowCriteria();
    test_isSquareMatrix();
    test_areTwoMatricesEqual();
    test_isEMatrix();
    test_isSymmetricMatrix();
    test_transposeSquareMatrix();
    test_getMinValuePos();
    test_getMaxValuePos();
}

///////// 2 часть //////////

void task_1 () {
    matrix m = createMatrixFromArray(
            (int[]) {
                    1, 2, 3,
                    4, 5, 6,
                    7, 8, 9
            },
            3, 3
    );
    position min = getMinValuePos(m);
    position max= getMaxValuePos(m);
    swapRows(m, min.rowIndex, max.rowIndex);
//    outputMatrix(m);
}

int main() {
    task_1();
    test();

    return 0;
}
