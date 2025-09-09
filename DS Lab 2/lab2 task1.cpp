#include <iostream>
using namespace std;

class DynamicMatrix {
private:
    int **matrix;
    int rows, cols;

public:
    //Constructor
    DynamicMatrix(int r, int c) {
        rows = r;
        cols = c;
        allocateMemory();
    }

    //Allocate memory
    void allocateMemory() {
        matrix = new int*[rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new int[cols];
            for (int j = 0; j < cols; j++)
                //Start at 0
                matrix[i][j] = 0;
        }
    }

    //Resizing
    void resize(int newRows, int newCols, int initValue = 0) {
        int **newMatrix = new int*[newRows]; //Fix: int* -> int**
        for (int i = 0; i < newRows; i++) {
            newMatrix[i] = new int[newCols];
            for (int j = 0; j < newCols; j++) {
                if (i < rows && j < cols)
                    //old
                    newMatrix[i][j] = matrix[i][j];
                else
                    //new
                    newMatrix[i][j] = initValue;
            }
        }

        //Delete
        for (int i = 0; i < rows; i++)
            delete[] matrix[i];
        delete[] matrix;

        //Update
        matrix = newMatrix;
        rows = newRows;
        cols = newCols;
    }

    //Transpose
    void transpose() {
        int **newMatrix = new int*[cols]; //Fix: int* -> int**
        for (int i = 0; i < cols; i++) {
            newMatrix[i] = new int[rows];
            for (int j = 0; j < rows; j++)
                newMatrix[i][j] = matrix[j][i];
        }

        //Delete again
        for (int i = 0; i < rows; i++)
            delete[] matrix[i];
        delete[] matrix;

        //Swap rows and cols
        int temp = rows;
        rows = cols;
        cols = temp;
        matrix = newMatrix;
    }

    //Add 2 to each odd index
    void addTwoToOddIndex() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (i % 2 == 1 || j % 2 == 1) {
                    matrix[i][j] += 2;
                }
            }
        }
    }

    //Print matrix
    void print() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    //Destructor
    ~DynamicMatrix() {
        for (int i = 0; i < rows; i++)
            delete[] matrix[i];
        delete[] matrix;
    }
};

//Start main
int main() {
    DynamicMatrix mat(2, 3);

    cout << "Initial Matrix:" << endl;
    mat.print();

    mat.resize(3, 4, 5);
    cout << "After Resize (3x4 with new values = 5):" << endl;
    mat.print();

    mat.transpose();
    cout << "After Transpose:" << endl;
    mat.print();

    mat.addTwoToOddIndex();
    cout << "After Adding 2 to Odd Indices:" << endl;
    mat.print();

    return 0;
}
