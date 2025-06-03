#include "../includes/vector.hpp"
#include "../includes/matrix.hpp"
#include "../includes/utils.hpp"
#include <iostream>

int main() {
    std::cout << "===== Vector Norm Tests =====" << std::endl;
    
    // Test vectors
    Vector<f32> v1({1, 2, 3});
    Vector<f32> v2({-1, 6});
    Vector<f32> v3({3, 2});
    Vector<f32> v4({0, 0, 0});
    
    // Test norm() (Euclidean norm)
    std::cout << "norm() tests:" << std::endl;
    std::cout << "v1 norm: " << norm(v1) << " (expected: " << std::sqrt(14) << ")" << std::endl;
    std::cout << "v2 norm: " << norm(v2)  << " (expected: " << std::sqrt(37) << ")" << std::endl;
    std::cout << "v3 norm: " << norm(v3)  << " (expected: " << std::sqrt(13) << ")" << std::endl;
    std::cout << "v4 norm: " << norm(v4)  << " (expected: 0)" << std::endl;
    
    // Test norm_1() (Manhattan distance)
    std::cout << "\nnorm_1() tests:" << std::endl;
    std::cout << "v1 norm_1: " << norm_1(v1) << " (expected: 6)" << std::endl;
    std::cout << "v2 norm_1: " << norm_1(v2) << " (expected: 7)" << std::endl;
    std::cout << "v3 norm_1: " << norm_1(v3) << " (expected: 5)" << std::endl;
    std::cout << "v4 norm_1: " << norm_1(v4) << " (expected: 0)" << std::endl;
    
    // Test norm_inf() (Maximum absolute value)
    std::cout << "\nnorm_inf() tests:" << std::endl;
    std::cout << "v1 norm_inf: " << norm_inf(v1) << " (expected: 3)" << std::endl;
    std::cout << "v2 norm_inf: " << norm_inf(v2) << " (expected: 6)" << std::endl;
    std::cout << "v3 norm_inf: " << norm_inf(v3) << " (expected: 3)" << std::endl;
    std::cout << "v4 norm_inf: " << norm_inf(v4) << " (expected: 0)" << std::endl;
    
    // Test normalize()
    std::cout << "\nnormalize() tests:" << std::endl;
    
    // Create copies of the original vectors to preserve them
    Vector<f32> v1_copy = v1;
    std::cout << "Original v1:" << std::endl;
    v1_copy.print();
    v1_copy.normalize();  // Normalize in place
    std::cout << "Normalized v1:" << std::endl;
    v1_copy.print();
    std::cout << "Normalized v1 norm: " << norm(v1_copy) << " (expected: 1)" << std::endl;
    
    Vector<f32> v2_copy = v2;
    std::cout << "Original v2:" << std::endl;
    v2_copy.print();
    v2_copy.normalize();  // Normalize in place
    std::cout << "Normalized v2:" << std::endl;
    v2_copy.print();
    std::cout << "Normalized v2 norm: " << norm(v2_copy) << " (expected: 1)" << std::endl;
    
    // Edge case: Normalizing a zero vector
    std::cout << "\nEdge case - normalizing a zero vector:" << std::endl;
    Vector<f32> v4_copy = normalize(v4);
    std::cout << "Original v4:" << std::endl;
    v4_copy.print();
    try {
        std::cout << "Normalized v4:" << std::endl;
        v4_copy.print();
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}