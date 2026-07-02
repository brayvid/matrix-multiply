#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Helper function to print matrices
void printMatrix(const vector<vector<double>>& matrix, const string& name) {
    cout << "\n" << name << " = \n";
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            cout << matrix[i][j];
            if (j < matrix[0].size() - 1) {
                cout << "\t";
            }
        }
        cout << "\n";
    }
}

int main() {
    int ra, ca, rb, cb;
    cout << "Matrix multiplication:\n\n";

    // Cleaned up input validation
    while (true) {
        cout << "Enter # rows and cols for matrix A (e.g., 2 3): ";
        cin >> ra >> ca;
        cout << "Enter # rows and cols for matrix B (e.g., 3 2): ";
        cin >> rb >> cb;

        if (ra > 0 && ca > 0 && rb > 0 && cb > 0 && ca == rb) {
            break; // Inputs are valid, break the loop
        }
        cout << "\nError: Dimensions must be > 0, and Columns of A must equal Rows of B!\n\n";
    }
    cout << "\n";

    // Initialize dynamically sized vectors
    vector<vector<double>> a(ra, vector<double>(ca));
    vector<vector<double>> b(rb, vector<double>(cb));
    vector<vector<double>> c(ra, vector<double>(cb, 0.0)); // Initialize C with zeros

    // Input Matrix A
    for (int i = 0; i < ra; ++i) {
        for (int j = 0; j < ca; ++j) {
            cout << "Enter element (" << i + 1 << ", " << j + 1 << ") of matrix A: ";
            cin >> a[i][j];
        }
    }
    printMatrix(a, "A");

    // Input Matrix B
    for (int i = 0; i < rb; ++i) {
        for (int j = 0; j < cb; ++j) {
            cout << "Enter element (" << i + 1 << ", " << j + 1 << ") of matrix B: ";
            cin >> b[i][j];
        }
    }
    printMatrix(b, "B");

    // OPTIMIZATION: i, k, j loop order is significantly faster due to CPU Cache Locality.
    for (int i = 0; i < ra; ++i) {
        for (int k = 0; k < ca; ++k) {
            for (int j = 0; j < cb; ++j) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    // Apply floating-point precision fix (using fast literal 1e-8 instead of pow)
    for (int i = 0; i < ra; ++i) {
        for (int j = 0; j < cb; ++j) {
            if (abs(c[i][j]) < 1e-8) {
                c[i][j] = 0;
            }
        }
    }

    // Output Result
    printMatrix(c, "A*B");
    cout << endl;

    return 0;
}