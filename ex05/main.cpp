#include <iostream>
#include <cassert>
#include <cmath>
#include "../includes/vector.hpp"
#include "../includes/matrix.hpp"
#include "../includes/utils.hpp"

// Helper function to check if two floating point values are approximately equal
bool approxEqual(float a, float b, float epsilon = 1e-5f) {
    return std::abs(a - b) < epsilon;
}

void testAngleCos() {
    // Test case 1: Identical vectors - cosine should be 1
    assert(approxEqual(angle_cos(Vector<f32>({1, 0}), Vector<f32>({1, 0})), 1.0f));
    
    // Test case 2: Perpendicular vectors - cosine should be 0
    assert(approxEqual(angle_cos(Vector<f32>({1, 0}), Vector<f32>({0, 1})), 0.0f));
    
    // Test case 3: Opposite vectors - cosine should be -1
    assert(approxEqual(angle_cos(Vector<f32>({-1, 1}), Vector<f32>({1, -1})), -1.0f));
    
    // Test case 4: Parallel vectors with different magnitudes - cosine should be 1
    assert(approxEqual(angle_cos(Vector<f32>({2, 1}), Vector<f32>({4, 2})), 1.0f));
    
    // Test case 5: Vectors of different dimensions - should throw an exception or handle gracefully
    // This depends on how your angle_cos function is implemented to handle errors
    
    // Additional test cases
    // 45-degree angle
    assert(approxEqual(angle_cos(Vector<f32>({1, 0}), Vector<f32>({1, 1})), 1.0f / std::sqrt(2.0f)));
    
    // 60-degree angle
    assert(approxEqual(angle_cos(Vector<f32>({1, 0}), Vector<f32>({0.5f, std::sqrt(3.0f)/2})), 0.5f));
    
    // Zero vector tests (should be handled based on your implementation)
    try {
        float result1 = angle_cos(Vector<f32>({0, 0}), Vector<f32>({1, 0}));
        float result2 = angle_cos(Vector<f32>({1, 0}), Vector<f32>({0, 0}));

        assert(std::isnan(result1) || std::isinf(result1));
        assert(std::isnan(result2) || std::isinf(result2));
        std::cout << "Zero vector test results: " << result1 << ", " << result2 << std::endl;
    } catch (const std::exception& e) {
        
        std::cout << "Expected exception caught for zero vector: " << e.what() << std::endl;
    }
}

int main() {
    std::cout << "Running angle_cos tests..." << std::endl;
    testAngleCos();
    std::cout << "✅ All unit tests passed!\n";
    
    return 0;
}