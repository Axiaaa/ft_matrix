#include "../includes/vector.hpp"
#include "../includes/matrix.hpp"
#include "../includes/utils.hpp"
#include <vector>
#include <cassert>
#include <cmath>
#include <iostream>

bool vectorsEqual(const Vector<f32>& v1, const Vector<f32>& v2, f32 epsilon = 1e-6) {
    if (v1.getSize() != v2.getSize()) return false;
    for (size_t i = 0; i < v1.getSize(); i++) {
        if (std::fabs(v1[i] - v2[i]) > epsilon) return false;
    }
    return true;
}

void test_linear_combination_basis_vectors() {
    Vector<f32> e1({1, 0, 0});
    Vector<f32> e2({0, 1, 0});
    Vector<f32> e3({0, 0, 1});
    
    Vector<f32> result = linear_combination(
        std::vector<Vector<f32>>{e1, e2, e3},
        {10.f, -2.f, 0.5f}
    );
    
    Vector<f32> expected({10.f, -2.f, 0.5f});
    assert(vectorsEqual(result, expected));
    std::cout << "Test linear combination with basis vectors passed.\n";
}

void test_linear_combination_arbitrary_vectors() {
    Vector<f32> v1({1, 2, 3});
    Vector<f32> v2({0, 10, -100});
    
    Vector<f32> result = linear_combination(
        std::vector<Vector<f32>>{v1, v2},
        {10.f, -2.f}
    );
    
    // Expected: 10*v1 + (-2)*v2 = [10, 20, 30] + [0, -20, 200] = [10, 0, 230]
    Vector<f32> expected({10.f, 0.f, 230.f});
    assert(vectorsEqual(result, expected));
    std::cout << "Test linear combination with arbitrary vectors passed.\n";
}

int main() {
    test_linear_combination_basis_vectors();
    test_linear_combination_arbitrary_vectors();
    
    std::cout << "✅ All unit tests passed!\n";
    return 0;
}