#include "../includes/vector.hpp"
#include "../includes/matrix.hpp"
#include "../includes/utils.hpp"
#include <iostream>
#include <cassert>
#include <cmath>

// Utility function to check if float values are almost equal
bool almostEqual(float a, float b, float epsilon = 0.000001f) {
    return std::fabs(a - b) <= epsilon;
}

// Test scalar lerp
void test_scalar_lerp() {
    std::cout << "Testing scalar lerp..." << std::endl;
    
    assert(lerp(0, 1, 0) == 0);
    assert(lerp(0, 1, 1) == 1);
    assert(almostEqual(lerp(0.0f, 1.0f, 0.5f), 0.5f));
    assert(almostEqual(lerp(21.0f, 42.0f, 0.3f), 27.3f));
    assert(almostEqual(lerp(21.0f, 42.0f, -0.3f), 14.7f));
    
    // Additional tests
    assert(almostEqual(lerp(10.0f, 20.0f, 0.75f), 17.5f));
    assert(almostEqual(lerp(-5.0f, 5.0f, 0.5f), 0.0f));
    assert(almostEqual(lerp(100.0f, 200.0f, 1.5f), 250.0f)); // Extrapolation
    
    std::cout << "Scalar lerp tests PASSED" << std::endl;
}

// Test vector lerp
void test_vector_lerp() {
    std::cout << "Testing vector lerp..." << std::endl;
    
    Vector<f32> e1({2, 1});
    Vector<f32> e2({4, 2});
    
    Vector<f32> result1 = lerp(e1, e2, 0.0f);
    assert(almostEqual(result1[0], 2.0f) && almostEqual(result1[1], 1.0f));
    
    Vector<f32> result2 = lerp(e1, e2, 0.3f);
    assert(almostEqual(result2[0], 2.6f) && almostEqual(result2[1], 1.3f));
    
    Vector<f32> result3 = lerp(e1, e2, 1.0f);
    assert(almostEqual(result3[0], 4.0f) && almostEqual(result3[1], 2.0f));
    
    // Additional tests
    Vector<f32> v1({0, 0, 0});
    Vector<f32> v2({10, 20, 30});
    Vector<f32> result4 = lerp(v1, v2, 0.5f);
    assert(almostEqual(result4[0], 5.0f) && almostEqual(result4[1], 10.0f) && almostEqual(result4[2], 15.0f));
    
    std::cout << "Vector lerp tests PASSED" << std::endl;
}

// Test matrix lerp
void test_matrix_lerp() {
    std::cout << "Testing matrix lerp..." << std::endl;
    
    Matrix<f32> m1({{2, 1}, {3, 4}});
    Matrix<f32> m2({{20, 10}, {30, 40}});
    
    Matrix<f32> result1 = lerp(m1, m2, 0.5f);
    assert(almostEqual(result1[0][0], 11.0f) && almostEqual(result1[0][1], 5.5f) &&
           almostEqual(result1[1][0], 16.5f) && almostEqual(result1[1][1], 22.0f));
    
    Matrix<f32> result2 = lerp(m1, m2, 0.0f);
    assert(almostEqual(result2[0][0], 2.0f) && almostEqual(result2[0][1], 1.0f) &&
           almostEqual(result2[1][0], 3.0f) && almostEqual(result2[1][1], 4.0f));
    
    Matrix<f32> result3 = lerp(m1, m2, 1.0f);
    assert(almostEqual(result3[0][0], 20.0f) && almostEqual(result3[0][1], 10.0f) &&
           almostEqual(result3[1][0], 30.0f) && almostEqual(result3[1][1], 40.0f));
    
    // Additional test
    Matrix<f32> result4 = lerp(m1, m2, 0.25f);
    assert(almostEqual(result4[0][0], 6.5f) && almostEqual(result4[0][1], 3.25f) &&
           almostEqual(result4[1][0], 9.75f) && almostEqual(result4[1][1], 13.0f));
    
    std::cout << "Matrix lerp tests PASSED" << std::endl;
}

int main() {
    
    test_scalar_lerp();
    test_vector_lerp();
    test_matrix_lerp();
    
    std::cout << "✅ All unit tests passed!\n";
    return 0;
}