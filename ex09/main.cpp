#include "../includes/vector.hpp"
#include "../includes/matrix.hpp"
#include "../includes/utils.hpp"
#include <iostream>

int main() {

    Matrix<f32> m1({
        {1, 3, 5},
        {2, 4, 6 },

    });

    auto m2 = transpose(m1);

    m2.print();
    m2.transpose();

    std::cout << "====" << std::endl;
    m2.print();
    std::cout << "====" << std::endl;
    transpose(Matrix<f32>({
        {1, 2},
        {3, 4}
    })).print();

    std::cout << "====" << std::endl;
    auto m3 = Matrix<f32>({
        {1, 2},
    });
    m3.print();
    std::cout << "====" << std::endl;
    m3.transpose();
    m3.print();
    std::cout << "====" << std::endl;
    m3.transpose();
    m3.print();
    std::cout << "====" << std::endl;
    transpose(m3).print();
    std::cout << "====" << std::endl;
    m3.transpose();
    m3.print();

}