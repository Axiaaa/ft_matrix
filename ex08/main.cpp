#include "../includes/vector.hpp"
#include "../includes/matrix.hpp"
#include "../includes/utils.hpp"
#include <ostream>

int main() {

    Matrix<f32> m1({
        {1, 0},
        {0, 1 }
    });

    std::cout << trace(m1) << std::endl;

    std::cout << trace(Matrix<f32>({
        {2, -5, 0},
        {4, 3, 7},
        {-2, 3, 4}
    })) << std::endl;

    std::cout << trace(Matrix<f32>({
        {-2, -8, 4},
        {1, -23, 3},
        {0, 6, 4}
    })) << std::endl;

        std::cout << trace(Matrix<f32>({
        {-2, 0, 0},
        {0, -23, 0},
        {0, 0, 4}
    })) << std::endl;
}