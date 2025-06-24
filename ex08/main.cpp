#include "../includes/vector.hpp"
#include "../includes/matrix.hpp"
#include "../includes/utils.hpp"
#include <iostream>
#include <cassert>

void test_identity_matrix() {
    Matrix<f32> identity({
        {1, 0, 0},
        {0, 1, 0 },
        {0, 1, 1}
    });
    assert(identity.trace() == 3.0f);
    std::cout << "Identity matrix trace test passed" << std::endl;
}

void test_diagonal_matrix() {
    Matrix<f32> diagonal({
        {-2, 0, 0},
        {0, -23, 0},
        {0, 0, 4}
    });
    assert(diagonal.trace() == -21.0f);
    std::cout << "Diagonal matrix trace test passed" << std::endl;
}

void test_square_matrices() {
    Matrix<f32> m1({
        {2, -5, 0},
        {4, 3, 7},
        {-2, 3, 4}
    });
    assert(m1.trace() == 9.0f);
    
    Matrix<f32> m2({
        {-2, -8, 4},
        {1, -23, 3},
        {0, 6, 4}
    });
    assert(m2.trace() == -21.0f);
    
    std::cout << "Square matrices trace tests passed" << std::endl;
}

void test_various_sizes() {
    Matrix<f32> m2x2({
        {5, 2},
        {3, 7}
    });
    assert(m2x2.trace() == 12.0f);
    
    Matrix<f32> m4x4({
        {1, 0, 0, 0},
        {0, 2, 0, 0},
        {0, 0, 3, 0},
        {0, 0, 0, 4}
    });
    assert(m4x4.trace() == 10.0f);
    
    std::cout << "Different size matrices trace tests passed" << std::endl;
}

int main() {
    test_identity_matrix();
    test_diagonal_matrix();
    test_square_matrices();
    test_various_sizes();
    
    std::cout << "✅ All unit tests passed!\n";
    return 0;
}