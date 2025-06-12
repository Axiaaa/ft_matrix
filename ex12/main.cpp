#include "../includes/vector.hpp"
#include "../includes/matrix.hpp"
#include "../includes/utils.hpp"
#include <cassert>

// Helper function to check if two matrices are approximately equal
bool matrices_approximately_equal(const Matrix<f32>& m1, const Matrix<f32>& m2, float epsilon = 1e-5f) {
    if (m1.getRows() != m2.getRows() || m1.getCols() != m2.getCols())
        return false;
    
    for (size_t i = 0; i < m1.getRows(); i++) {
        for (size_t j = 0; j < m1.getCols(); j++) {
            if (std::abs(m1[i][j] - m2[i][j]) > epsilon)
                return false;
        }
    }
    return true;
}

// Helper function to create an identity matrix
Matrix<f32> create_identity(size_t n) {
    std::vector<std::vector<f32>> data;
    for (size_t i = 0; i < n; i++) {
        std::vector<f32> row(n, 0.0f);
        row[i] = 1.0f;
        data.push_back(row);
    }
    return Matrix<f32>{data};
}

void test_basic_inverse() {
    std::cout << "Testing basic matrix inverse..." << std::endl;
    
    Matrix<f32> m1({
        {8, 5, -2},
        {4, 7, 20},
        {7, 6, 1},
    });
    
    Matrix<f32> inverse_m1 = inverse(m1);
    
    // The product of a matrix and its inverse should be the identity matrix
    Matrix<f32> result = m1;
    result.mul_mat(inverse_m1);
    
    Matrix<f32> identity = create_identity(3);
    
    assert(matrices_approximately_equal(result, identity));
    std::cout << "Basic inverse test passed!" << std::endl;
}

void test_2x2_inverse() {
    std::cout << "Testing 2x2 matrix inverse..." << std::endl;
    
    Matrix<f32> m({
        {4, 7},
        {2, 6}
    });
    
    Matrix<f32> inverse_m = inverse(m);
    
    // Expected inverse for this matrix
    Matrix<f32> expected_inverse({
        {0.6f, -0.7f},
        {-0.2f, 0.4f}
    });
    
    assert(matrices_approximately_equal(inverse_m, expected_inverse));
    
    // Verify A * A^(-1) = I
    Matrix<f32> result = m;
    result.mul_mat(inverse_m);
    assert(matrices_approximately_equal(result, create_identity(2)));
    
    std::cout << "2x2 inverse test passed!" << std::endl;
}

void test_4x4_inverse() {
    std::cout << "Testing 4x4 matrix inverse..." << std::endl;
    
    Matrix<f32> m({
        {1, 0, 2, -1},
        {3, 0, 0, 5},
        {2, 1, 4, -3},
        {1, 0, 5, 0}
    });
    
    Matrix<f32> inverse_m = inverse(m);
    
    // Verify A * A^(-1) = I
    Matrix<f32> result = m;
    result.mul_mat(inverse_m);
    assert(matrices_approximately_equal(result, create_identity(4)));
    
    // Verify A^(-1) * A = I
    Matrix<f32> result2 = inverse_m;
    result2.mul_mat(m);
    assert(matrices_approximately_equal(result2, create_identity(4)));
    
    std::cout << "4x4 inverse test passed!" << std::endl;
}

void test_symmetric_matrix_inverse() {
    std::cout << "Testing symmetric matrix inverse..." << std::endl;
    
    Matrix<f32> m({
        {2, 1, 3},
        {1, 5, 2},
        {3, 2, 9}
    });
    
    Matrix<f32> inverse_m = inverse(m);
    
    // Verify A * A^(-1) = I
    Matrix<f32> result = m;
    result.mul_mat(inverse_m);
    assert(matrices_approximately_equal(result, create_identity(3)));
    
    std::cout << "Symmetric matrix inverse test passed!" << std::endl;
}

void test_inverse_properties() {
    std::cout << "Testing inverse matrix properties..." << std::endl;
    
    // Test that (A^(-1))^(-1) = A
    Matrix<f32> m({
        {3, 1, 2},
        {2, 5, 3},
        {1, 2, 4}
    });
    
    Matrix<f32> inverse_m = inverse(m);
    Matrix<f32> inverse_inverse_m = inverse(inverse_m);
    
    assert(matrices_approximately_equal(m, inverse_inverse_m));
    
    // Test that (AB)^(-1) = B^(-1) * A^(-1)
    Matrix<f32> a({
        {2, 1},
        {3, 4}
    });
    
    Matrix<f32> b({
        {1, 2},
        {3, 1}
    });
    
    // Calculate AB
    Matrix<f32> ab = a;
    ab.mul_mat(b);
    
    // Get (AB)^(-1)
    Matrix<f32> ab_inv = inverse(ab);
    
    // Calculate B^(-1)
    Matrix<f32> b_inv = inverse(b);
    
    // Calculate A^(-1)
    Matrix<f32> a_inv = inverse(a);
    
    // Calculate B^(-1) * A^(-1)
    Matrix<f32> b_inv_a_inv = b_inv;
    b_inv_a_inv.mul_mat(a_inv);
    
    assert(matrices_approximately_equal(ab_inv, b_inv_a_inv));
    
    std::cout << "Inverse properties tests passed!" << std::endl;
}

void test_methods()
{
    Matrix<f32> a({
        {2, 1},
        {3, 4}
    });

    auto b = inverse(a);
    a.inverse();

    assert(matrices_approximately_equal(a, b));

}

int main() {
    test_basic_inverse();
    test_2x2_inverse();
    test_4x4_inverse();
    test_symmetric_matrix_inverse();
    test_inverse_properties();
    test_methods();
    
    std::cout << "✅ All unit tests passed!" << std::endl;

    return 0;
}