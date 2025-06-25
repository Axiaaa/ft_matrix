#include "../includes/vector.hpp"
#include "../includes/matrix.hpp"
#include "../includes/utils.hpp"
#include <iostream>
#include <cassert>
#include <cmath>
#include <ostream>

// Helper function to check if two floating point values are approximately equal
bool approx_equal(f32 a, f32 b, f32 epsilon = 1e-5f) {
    return std::fabs(a - b) < epsilon;
}

// Helper function to check if a matrix is in proper row echelon form
bool is_row_echelon(const Matrix<f32>& m) {
    int last_lead_col = -1;
    
    for (size_t i = 0; i < m.getRows(); ++i) {
        bool all_zeros = true;
        int lead_col = -1;
        
        // Find the leading entry in this row
        for (size_t j = 0; j < m.getCols(); ++j) {
            if (!approx_equal(m[i][j], 0.0f)) {
                all_zeros = false;
                lead_col = j;
                break;
            }
        }
        
        if (all_zeros) {
            continue;
        }
        
        // Leading entry should be to the right of the previous row's leading entry
        if (lead_col <= last_lead_col) {
            return false;
        }
        
        // Leading entry should be 1
        if (!approx_equal(m[i][lead_col], 1.0f)) {
            return false;
        }
        
        last_lead_col = lead_col;
    }
    
    return true;
}

void test_example_matrix() {
    std::cout << "Testing the example matrix..." << std::endl;
    
    Matrix<f32> m({
        {8, 5, -2, 4, 28},
        {4., 2.5, 20., 4., -4.},
        {8., 5., 1., 4., 17.}
    });
    
    Matrix<f32> result = row_echelon(m);
    std::cout << "Row echelon form:" << std::endl;
    result.print();
    
    assert(is_row_echelon(result));
    std::cout << "Test passed!" << std::endl;
}

void test_identity_matrix() {
    std::cout << "Testing identity matrix..." << std::endl;
    
    Matrix<f32> identity({
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    });
    
    Matrix<f32> result = row_echelon(identity);
    result.print();
    
    assert(is_row_echelon(result));
    std::cout << "Test passed!" << std::endl;
}

void test_zero_matrix() {
    std::cout << "Testing zero matrix..." << std::endl;
    
    Matrix<f32> zero({
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    });
    
    Matrix<f32> result = row_echelon(zero);
    result.print();
    
    assert(is_row_echelon(result));
    std::cout << "Test passed!" << std::endl;
}

void test_non_square_matrix() {
    std::cout << "Testing non-square matrix..." << std::endl;
    
    Matrix<f32> m({
        {2, 4, 6, 8},
        {1, 3, 5, 7}
    });
    
    Matrix<f32> result = row_echelon(m);
    result.print();
    
    assert(is_row_echelon(result));
    std::cout << "Test passed!" << std::endl;
}

void test_specific_known_case() {
    std::cout << "Testing matrix with known row echelon form..." << std::endl;
    
    Matrix<f32> m({
        {1, 3, 1},
        {2, 7, 3},
        {1, 5, 3}
    });
    
    Matrix<f32> result = row_echelon(m);
    result.print();
    
    assert(is_row_echelon(result));
    std::cout << "Test passed!" << std::endl;
}

void test_method() {
    std::cout << "Testing matrix with decimal values..." << std::endl;
    
    Matrix<f32> m({
        {1.5, 2.3, 3.7},
        {4.1, 5.9, 6.2},
        {7.8, 8.4, 9.0}
    });
    m.row_echelon();
    m.print();
    assert(is_row_echelon(m));
    std::cout << "Test passed!" << std::endl;
}

int main() {
    std::cout << "Running tests for row_echelon_form function...\n" << std::endl;
    
    test_example_matrix();
    std::cout << std::endl;
    
    test_identity_matrix();
    std::cout << std::endl;
    
    test_zero_matrix();
    std::cout << std::endl;
    
    test_non_square_matrix();
    std::cout << std::endl;
    
    test_specific_known_case();
    std::cout << std::endl;
    
    test_method();
    std::cout << std::endl;
    std::cout << "✅ All unit tests passed!\n";
    
    return 0;
}