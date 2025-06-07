#include "../includes/vector.hpp"
#include "../includes/matrix.hpp"
#include "../includes/utils.hpp"
#include <iostream>
#include <cassert>
#include <cmath>

// Utility function to check if two floats are approximately equal
bool approx_equal(f32 a, f32 b, f32 epsilon = 1e-5f) {
    return std::abs(a - b) < epsilon;
}

// Test Euclidean norm
void test_norm() {
    std::cout << "Testing norm()..." << std::endl;
    
    Vector<f32> v1({1, 2, 3});
    Vector<f32> v2({-1, 6});
    Vector<f32> v3({3, 2});
    Vector<f32> v4({0, 0, 0});
    
    assert(approx_equal(norm(v1), std::sqrt(14)));
    assert(approx_equal(norm(v2), std::sqrt(37)));
    assert(approx_equal(norm(v3), std::sqrt(13)));
    assert(approx_equal(norm(v4), 0));
    
    std::cout << "norm() tests passed!" << std::endl;
}

// Test Manhattan distance (L1 norm)
void test_norm_1() {
    std::cout << "Testing norm_1()..." << std::endl;
    
    Vector<f32> v1({1, 2, 3});
    Vector<f32> v2({-1, 6});
    Vector<f32> v3({3, 2});
    Vector<f32> v4({0, 0, 0});
    
    assert(norm_1(v1) == 6);
    assert(norm_1(v2) == 7);
    assert(norm_1(v3) == 5);
    assert(norm_1(v4) == 0);
    
    std::cout << "norm_1() tests passed!" << std::endl;
}

// Test infinity norm (maximum absolute value)
void test_norm_inf() {
    std::cout << "Testing norm_inf()..." << std::endl;
    
    Vector<f32> v1({1, 2, 3});
    Vector<f32> v2({-1, 6});
    Vector<f32> v3({3, 2});
    Vector<f32> v4({0, 0, 0});
    
    assert(norm_inf(v1) == 3);
    assert(norm_inf(v2) == 6);
    assert(norm_inf(v3) == 3);
    assert(norm_inf(v4) == 0);
    
    std::cout << "norm_inf() tests passed!" << std::endl;
}

// Test normalize() function
void test_normalize_function() {
    std::cout << "Testing normalize() function..." << std::endl;
    
    Vector<f32> v1({1, 2, 3});
    Vector<f32> v2({-1, 6});
    
    Vector<f32> v1_normalized = normalize(v1);
    Vector<f32> v2_normalized = normalize(v2);
    
    // Check that the normalized vectors have unit length
    assert(approx_equal(norm(v1_normalized), 1.0f));
    assert(approx_equal(norm(v2_normalized), 1.0f));
    
    // Check that direction is preserved
    f32 v1_factor = 1.0f / norm(v1);
    assert(approx_equal(v1_normalized[0], v1[0] * v1_factor));
    assert(approx_equal(v1_normalized[1], v1[1] * v1_factor));
    assert(approx_equal(v1_normalized[2], v1[2] * v1_factor));
    
    // Test zero vector
    Vector<f32> v4({0, 0, 0});
    bool exception_caught = false;
    try {
        Vector<f32> v4_normalized = normalize(v4);
        v4.print();
    } catch (const std::exception&) {
        exception_caught = true;
    }
    assert(exception_caught);
    
    std::cout << "normalize() function tests passed!" << std::endl;
}

// Test normalize() method
void test_normalize_method() {
    std::cout << "Testing Vector::normalize() method..." << std::endl;
    
    Vector<f32> v1({1, 2, 3});
    Vector<f32> v1_original = v1;  // Copy for reference
    v1.normalize();
    
    // Check that the vector now has unit length
    assert(approx_equal(norm(v1), 1.0f));
    
    // Check that direction is preserved
    f32 factor = 1.0f / norm(v1_original);
    assert(approx_equal(v1[0], v1_original[0] * factor));
    assert(approx_equal(v1[1], v1_original[1] * factor));
    assert(approx_equal(v1[2], v1_original[2] * factor));
    
    // Test zero vector
    Vector<f32> v4({0, 0, 0});
    bool exception_caught = false;
    try {
        v4.normalize();
    } catch (const std::exception&) {
        exception_caught = true;
    }
    assert(exception_caught);
    
    std::cout << "Vector::normalize() method tests passed!" << std::endl;
}

// Test edge cases
void test_edge_cases() {
    std::cout << "Testing edge cases..." << std::endl;
    
    // Single element vector
    Vector<f32> v_single({5});
    assert(norm(v_single) == 5);
    assert(norm_1(v_single) == 5);
    assert(norm_inf(v_single) == 5);
    
    // Vector with negative values
    Vector<f32> v_neg({-3, -4});
    assert(approx_equal(norm(v_neg), 5));
    assert(norm_1(v_neg) == 7);
    assert(norm_inf(v_neg) == 4);
    
    // Normalizing already normalized vector
    Vector<f32> v_unit({1, 0, 0});
    v_unit.normalize();
    assert(approx_equal(v_unit[0], 1.0f));
    assert(approx_equal(v_unit[1], 0.0f));
    assert(approx_equal(v_unit[2], 0.0f));
    
    std::cout << "Edge case tests passed!" << std::endl;
}

int main() {
    std::cout << "===== Running Vector Norm Tests =====" << std::endl;
    
    test_norm();
    test_norm_1();
    test_norm_inf();
    test_normalize_function();
    test_normalize_method();
    test_edge_cases();
    
    std::cout << "✅ All unit tests passed!\n";
    return 0;
}