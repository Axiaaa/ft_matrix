#include <iostream>
#include <cassert>
#include "../includes/vector.hpp"
#include "../includes/matrix.hpp"
#include "../includes/utils.hpp"

// Test Vector initialization and dot product method
void test_vector_dot_product() {
    std::cout << "Testing Vector dot product method..." << std::endl;
    
    // Test case 1: From the original main
    Vector<f32> e1({-1, 6});
    Vector<f32> e2({3, 2});
    f32 result1 = e1.dot(e2);
    f32 expected1 = (-1 * 3) + (6 * 2); // = 9
    assert(result1 == expected1);
    std::cout << "Test case 1 passed: " << result1 << " == " << expected1 << std::endl;
    
    // Test case 2: From the original main
    f32 result2 = Vector<f32>({1, 1}).dot(Vector<f32>({1, 1}));
    f32 expected2 = 2;
    assert(result2 == expected2);
    std::cout << "Test case 2 passed: " << result2 << " == " << expected2 << std::endl;
    
    // Additional test cases
    Vector<f32> v1({2, 3, 4});
    Vector<f32> v2({5, 6, 7});
    f32 result3 = v1.dot(v2);
    f32 expected3 = (2 * 5) + (3 * 6) + (4 * 7); // = 10 + 18 + 28 = 56
    assert(result3 == expected3);
    std::cout << "Test case 3 passed: " << result3 << " == " << expected3 << std::endl;
}

// Test standalone dot function
void test_standalone_dot_function() {
    std::cout << "\nTesting standalone dot function..." << std::endl;
    
    // Test case 1: From the original main
    f32 result1 = dot(Vector<f32>({1, 3}), Vector<f32>({3, 2}));
    f32 expected1 = (1 * 3) + (3 * 2); // = 3 + 6 = 9
    assert(result1 == expected1);
    std::cout << "Test case 1 passed: " << result1 << " == " << expected1 << std::endl;
    
    // Additional test cases
    Vector<f32> v1({-2, 5, 1});
    Vector<f32> v2({3, -1, 4});
    f32 result2 = dot(v1, v2);
    f32 expected2 = (-2 * 3) + (5 * -1) + (1 * 4); // = -6 - 5 + 4 = -7
    assert(result2 == expected2);
    std::cout << "Test case 2 passed: " << result2 << " == " << expected2 << std::endl;
}

// Test zero vector dot product
void test_zero_vector() {
    std::cout << "\nTesting zero vector dot products..." << std::endl;
    
    Vector<f32> zero({0, 0, 0});
    Vector<f32> v1({5, -3, 2});
    
    f32 result = zero.dot(v1);
    assert(result == 0);
    std::cout << "Zero vector dot product test passed: " << result << " == 0" << std::endl;
}

int main() {
    std::cout << "Running Vector dot product tests...\n" << std::endl;
    
    test_vector_dot_product();
    test_standalone_dot_function();
    test_zero_vector();
    
    std::cout << "✅ All unit tests passed!\n";
    return 0;
}