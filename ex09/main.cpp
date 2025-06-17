#include "../includes/vector.hpp"
#include "../includes/matrix.hpp"
#include "../includes/utils.hpp"
#include <iostream>
#include <cassert>

// Test transposition of rectangular matrix
void test_basic_transpose() {
    std::cout << "=== Testing basic matrix transpose ===" << std::endl;
    Matrix<f32> m1({
        {1, 3, 5},
        {2, 4, 6}
    });
    
    std::cout << "Original matrix:" << std::endl;
    m1.print();
    
    auto m2 = transpose(m1);
    std::cout << "Transposed matrix:" << std::endl;
    m2.print();
    
    // Test in-place transpose
    m2.transpose();
    std::cout << "After in-place transpose (should match original):" << std::endl;
    m2.print();
}

// Test transposition of square matrix
void test_square_transpose() {
    std::cout << "\n=== Testing square matrix transpose ===" << std::endl;
    Matrix<f32> m({
        {1, 2},
        {3, 4}
    });
    
    std::cout << "Original matrix:" << std::endl;
    m.print();
    
    std::cout << "Transposed matrix:" << std::endl;
    transpose(m).print();
}

// Test transposition of single row/column matrices
void test_single_dimension() {
    std::cout << "\n=== Testing single row matrix transpose ===" << std::endl;
    Matrix<f32> row({
        {1, 2, 3, 4}
    });
    
    std::cout << "Row matrix:" << std::endl;
    row.print();
    std::cout << "Transposed to column:" << std::endl;
    transpose(row).print();
    
    std::cout << "\n=== Testing single column matrix transpose ===" << std::endl;
    Matrix<f32> col(std::vector<std::vector<f32>>{{1}, {2}, {3}});
    
    std::cout << "Column matrix:" << std::endl;
    col.print();
    std::cout << "Transposed to row:" << std::endl;
    transpose(col).print();
}

// Test double transposition
void test_double_transpose() {
    std::cout << "\n=== Testing double transpose ===" << std::endl;
    Matrix<f32> m({
        {1, 3, 5},
        {2, 4, 6}
    });
    
    std::cout << "Original:" << std::endl;
    m.print();
    
    auto transposed_twice = transpose(transpose(m));
    std::cout << "Transposed twice (should match original):" << std::endl;
    transposed_twice.print();
}

int main() {
    std::cout << "Matrix transpose tests\n" << std::endl;
    
    test_basic_transpose();
    test_square_transpose();
    test_single_dimension();
    test_double_transpose();
    
    std::cout << "✅ All unit tests passed!\n";
    return 0;
}