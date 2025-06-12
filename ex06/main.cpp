#include "../includes/vector.hpp"
#include "../includes/matrix.hpp"
#include "../includes/utils.hpp"
#include <cassert>
#include <cmath>
#include <iostream>

// Helper function to compare vectors with a small epsilon for floating point comparison
bool vector_equals(const Vector<f32>& v1, const Vector<f32>& v2, float epsilon = 1e-5) {
    if (v1.getSize() != v2.getSize())
        return false;
    
    for (size_t i = 0; i < v1.getSize(); i++) {
        if (std::abs(v1[i] - v2[i]) > epsilon)
            return false;
    }
    return true;
}

void test_cross_product() {
    std::cout << "Testing cross product..." << std::endl;

    // Test case 1: {0, 0, 1} × {1, 0, 0} = {0, 1, 0}
    Vector<f32> v1_1({0, 0, 1});
    Vector<f32> v1_2({1, 0, 0});
    Vector<f32> expected1({0, 1, 0});
    Vector<f32> result1 = cross_product(v1_1, v1_2);
    assert(vector_equals(result1, expected1));
    std::cout << "Test case 1 passed!" << std::endl;

    // Test case 2: {1, 2, 3} × {4, 5, 6} = {-3, 6, -3}
    Vector<f32> v2_1({1, 2, 3});
    Vector<f32> v2_2({4, 5, 6});
    Vector<f32> expected2({-3, 6, -3});
    Vector<f32> result2 = cross_product(v2_1, v2_2);
    assert(vector_equals(result2, expected2));
    std::cout << "Test case 2 passed!" << std::endl;

    // Test case 3: {4, 2, -3} × {-2, -5, 16} = {17, -58, -16}
    Vector<f32> v3_1({4, 2, -3});
    Vector<f32> v3_2({-2, -5, 16});
    Vector<f32> expected3({17, -58, -16});
    Vector<f32> result3 = cross_product(v3_1, v3_2);
    assert(vector_equals(result3, expected3));
    std::cout << "Test case 3 passed!" << std::endl;

    // Additional properties of cross product
    // 1. Anti-commutativity: v1 × v2 = -(v2 × v1)
    Vector<f32> a({1, 2, 3});
    Vector<f32> b({4, 5, 6});
    Vector<f32> a_cross_b = cross_product(a, b);
    Vector<f32> b_cross_a = cross_product(b, a);
    Vector<f32> neg_b_cross_a({-b_cross_a[0], -b_cross_a[1], -b_cross_a[2]});
    assert(vector_equals(a_cross_b, neg_b_cross_a));
    std::cout << "Anti-commutativity property verified!" << std::endl;
}

void test_method() {
    std::cout << "Testing cross product..." << std::endl;

    // Test case 1: {0, 0, 1} × {1, 0, 0} = {0, 1, 0}
    Vector<f32> v1({0, 0, 1});
    Vector<f32> expected1({0, 1, 0});
    v1.cross_product(Vector<f32>({1, 0, 0}));
    assert(vector_equals(v1, expected1));
    std::cout << "Method Test case 1 passed!" << std::endl;

    // Test case 2: {1, 2, 3} × {4, 5, 6} = {-3, 6, -3}
    Vector<f32> v2({1, 2, 3});
    Vector<f32> expected2({-3, 6, -3});
    v2.cross_product(Vector<f32>({4, 5, 6}));
    assert(vector_equals(v2, expected2));
    std::cout << "Method test case 1 passed!" << std::endl;
    }
int main() {
    test_cross_product();
    test_method();
    std::cout << "✅ All unit tests passed!\n";
    return 0;
}