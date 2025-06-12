#include "../includes/vector.hpp"
#include "../includes/matrix.hpp"
#include "../includes/utils.hpp"
#include <cassert>

void test_rank_full_rank_square() {
    std::cout << "Testing rank of full rank square matrix..." << std::endl;
    
    Matrix<f32> m({
        {1, 2, 3},
        {0, 1, 4},
        {5, 6, 0}
    });
    
    size_t rank = m.rank();
    std::cout << "Rank: " << rank << std::endl;
    assert(rank == 3);
    std::cout << "Test passed!" << std::endl;
}

void test_rank_deficient_matrix() {
    std::cout << "Testing rank of rank-deficient matrix..." << std::endl;
    
    Matrix<f32> m({
        {1, 2, 3},
        {2, 4, 6},  // linearly dependent with row 1
        {5, 6, 0}
    });
    
    size_t rank = m.rank();
    std::cout << "Rank: " << rank << std::endl;
    assert(rank == 2);
    std::cout << "Test passed!" << std::endl;
}

void test_rank_zero_matrix() {
    std::cout << "Testing rank of zero matrix..." << std::endl;
    
    Matrix<f32> m({
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    });
    
    size_t rank = m.rank();
    std::cout << "Rank: " << rank << std::endl;
    assert(rank == 0);
    std::cout << "Test passed!" << std::endl;
}

void test_rank_non_square_full() {
    std::cout << "Testing rank of non-square matrix with full rank..." << std::endl;
    
    Matrix<f32> m({
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    });
    
    size_t rank = m.rank();
    std::cout << "Rank: " << rank << std::endl;
    assert(rank == 2);  // Only 2 rows are linearly independent
    std::cout << "Test passed!" << std::endl;
}

void test_rank_identity() {
    std::cout << "Testing rank of identity matrix..." << std::endl;
    
    Matrix<f32> m({
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    });
    
    size_t rank = m.rank();
    std::cout << "Rank: " << rank << std::endl;
    assert(rank == 3);
    std::cout << "Test passed!" << std::endl;
}

void test_rank_with_rounding_errors() {
    std::cout << "Testing rank with potential rounding errors..." << std::endl;
    
    Matrix<f32> m({
        {1, 2, 3},
        {1 + 1e-10f, 2, 3},  // Almost linearly dependent with row 1
        {4, 5, 6}
    });
    
    size_t rank = m.rank();
    std::cout << "Rank: " << rank << std::endl;
    // Should handle near-zero values correctly
    assert(rank == 2);
    std::cout << "Test passed!" << std::endl;
}

int main() {
    std::cout << "Running tests for rank method...\n" << std::endl;
    
    test_rank_full_rank_square();
    std::cout << std::endl;
    
    test_rank_deficient_matrix();
    std::cout << std::endl;
    
    test_rank_zero_matrix();
    std::cout << std::endl;
    
    test_rank_non_square_full();
    std::cout << std::endl;
    
    test_rank_identity();
    std::cout << std::endl;
    
    test_rank_with_rounding_errors();
    std::cout << std::endl;
    
    std::cout << "✅ All unit tests passed!\n";
    
    return 0;
}
