#include "../includes/vector.hpp"
#include "../includes/matrix.hpp"
#include "../includes/utils.hpp"
#include <iostream>
#include <cassert>
#include <sys/types.h>


void test_2x2_determinants() {
    std::cout << "Testing 2x2 determinants..." << std::endl;
    
    // Zero determinant case
    Matrix<f32> zero_det({
        {1, -1},
        {-1, 1}
    });
    assert(zero_det.determinant() == 0.0f);
    
    // Negative determinant
    Matrix<f32> neg_det({
        {3, 7},
        {1, -4}
    });
    assert(neg_det.determinant() == -19.0);
    
    // Positive determinant
    Matrix<f32> pos_det({
        {4, 2},
        {3, 8}
    });
    assert(pos_det.determinant() == 26.0f);
    
    // Identity matrix
    Matrix<f32> identity({
        {1, 0},
        {0, 1}
    });
    assert(identity.determinant() == 1.0f);
    
    std::cout << "2x2 determinant tests passed!" << std::endl;
}

void test_3x3_determinants() {
    std::cout << "Testing 3x3 determinants..." << std::endl;
    
    // Standard case
    Matrix<f32> std_mat({
        {8, 5, -2},
        {4, 7, 20},
        {7, 6, 1}
    });
    assert(std_mat.determinant() == -174.0f);
    
    // Identity matrix
    Matrix<f32> identity({
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    });
    assert(identity.determinant() == 1.0f);
    
    // Zero row
    Matrix<f32> zero_row({
        {1, 2, 3},
        {0, 0, 0},
        {4, 5, 6}
    });
    assert(zero_row.determinant() == 0.0f);
    
    // Zero column
    Matrix<f32> zero_col({
        {1, 0, 3},
        {4, 0, 6},
        {7, 0, 9}
    });
    assert(zero_col.determinant() == 0.0f);
    
    // Upper triangular
    Matrix<f32> upper_tri({
        {3, 4, 5},
        {0, 2, 7},
        {0, 0, 1}
    });
    assert(upper_tri.determinant() == 6.0f); // 3 * 2 * 1
    
    // Lower triangular
    Matrix<f32> lower_tri({
        {3, 0, 0},
        {4, 2, 0},
        {5, 7, 1}
    });
    assert(lower_tri.determinant() == 6.0f); // 3 * 2 * 1
    
    std::cout << "3x3 determinant tests passed!" << std::endl;
}

void test_4x4_determinants() {
    std::cout << "Testing 4x4 determinants..." << std::endl;
    
    // Standard case
    Matrix<f32> std_mat({
        {8, 5, -2, 4},
        {4, 2.5, 20, 4},
        {8, 5, 1, 4},
        {28, -4, 17, 1}
    });
    assert(std_mat.determinant() == 1032);
    
    // Identity matrix
    Matrix<f32> identity({
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    });
    assert(identity.determinant() == 1.0f);
    
    // Diagonal matrix
    Matrix<f32> diagonal({
        {3, 0, 0, 0},
        {0, -2, 0, 0},
        {0, 0, 5, 0},
        {0, 0, 0, -1}
    });
    assert(diagonal.determinant() == 30.0f); // 3 * -2 * 5 * -1
    
    // Matrix with repeated rows (should have determinant = 0)
    Matrix<f32> repeated_rows({
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {1, 2, 3, 4},
        {9, 10, 11, 12}
    });
    assert(repeated_rows.determinant() == 0.0f);
    
    std::cout << "4x4 determinant tests passed!" << std::endl;
}

void test_special_cases() {
    std::cout << "Testing special cases..." << std::endl;
    
    // 1x1 matrix
    Matrix<f32> single({
        {5}
    });
    assert(single.determinant() == 5.0f);
    
    // Scalar matrices
    Matrix<f32> scalar3x3({
        {4, 0, 0},
        {0, 4, 0},
        {0, 0, 4}
    });
    assert(scalar3x3.determinant() == 64.0f); // 4³
    
    // Permutation matrix
    Matrix<f32> perm({
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 0}
    });
    assert(perm.determinant() == 1.0f);
    
    std::cout << "Special case tests passed!" << std::endl;
}


int main() {
    test_2x2_determinants();
    test_3x3_determinants();
    test_4x4_determinants();
    test_special_cases();
    
    std::cout << "✅ All unit tests passed!\n";
    return 0;
}