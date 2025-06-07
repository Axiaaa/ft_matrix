#include "../includes/vector.hpp"
#include "../includes/matrix.hpp"
#include "../includes/utils.hpp"
#include <cassert>
#include <cmath>
#include <iostream>

// Helper function to compare floats with tolerance
bool almost_equal(f32 a, f32 b, f32 epsilon = 1e-6) {
    return std::fabs(a - b) < epsilon;
}


void test_mul_vec_global() {
    std::cout << "Testing global matrix-vector multiplication..." << std::endl;
    
    Matrix<f32> m({
        {1, -1, 2},
        {0, -3, 1}
    });
    Vector<f32> v({2, 1, 0});
    Vector<f32> expected({1, -3});
    
    Vector<f32> result = mul_vec(m, v);
    
    std::cout << "Result: \n";
    result.print();
    std::cout << "Expected: ";
    expected.print();
    
    assert(result == expected);
    std::cout << "Global matrix-vector multiplication test passed!" << std::endl;
}

void test_mul_vec_member() {
    std::cout << "Testing member matrix-vector multiplication..." << std::endl;
    
    // Test case 1
    Matrix<f32> m1({
        {1, -1, 2},
        {0, -3, 1}
    });
    Vector<f32> v1({1, -3, 0});
    Matrix<f32> expected1({
        {4},
        {9}
    });
    
    m1.mul_vec(v1);
    
    std::cout << "Result: \n";
    m1.print();
    std::cout << "Expected: \n";
    expected1.print();
    assert(m1 == expected1);
    
    // Test case 2
    Matrix<f32> m2({
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}
    });
    Vector<f32> v2({-2, 1, 0});
    Matrix<f32> expected2({
        {0},
        {-3},
        {-6},
        {-9}
    });
    
    m2.mul_vec(v2);
    
    std::cout << "Result: \n";
    m2.print();
    std::cout << "Expected: \n";
    expected2.print();
    
    assert(m2 == expected2);
    std::cout << "Member matrix-vector multiplication test passed!" << std::endl;
}

void test_mul_mat_global() {
    std::cout << "Testing global matrix-matrix multiplication..." << std::endl;
    
    Matrix<f32> m3({
        {1, 2},
        {3, 4},
        {5, 6}
    });
    Matrix<f32> m4({
        {1, 2, 3},
        {4, 5, 6}
    });
    Matrix<f32> expected({
        {9, 12, 15},
        {19, 26, 33},
        {29, 40, 51}
    });
    
    Matrix<f32> result = mul_mat(m3, m4);
    
    std::cout << "Result: \n";
    result.print();
    std::cout << "Expected: \n";
    expected.print();
    
    assert(result == expected);
    std::cout << "Global matrix-matrix multiplication test passed!" << std::endl;
}

void test_mul_mat_member() {
    std::cout << "Testing member matrix-matrix multiplication..." << std::endl;
    
    Matrix<f32> m6({
        {1, 2},
        {3, 4},
        {5, 6}
    });
    Matrix<f32> m7({
        {1, 2, 3},
        {4, 5, 6}
    });
    Matrix<f32> expected({
        {9, 12, 15},
        {19, 26, 33},
        {29, 40, 51}
    });
    
    m6.mul_mat(m7);
    
    std::cout << "Result: \n";
    m6.print();
    std::cout << "Expected: \n";
    expected.print();
    
    assert(m6 == expected);
    std::cout << "Member matrix-matrix multiplication test passed!" << std::endl;
}

int main() {
    std::cout << "Running matrix operation tests..." << std::endl;

    test_mul_vec_global();
    std::cout << "==========" << std::endl;
    
    test_mul_vec_member();
    std::cout << "==========" << std::endl;
    
    test_mul_mat_global();
    std::cout << "==========" << std::endl;
    
    test_mul_mat_member();
    std::cout << "==========" << std::endl;
    
    std::cout << "✅ All unit tests passed!\n";
    return 0;
}