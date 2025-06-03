#include "../includes/vector.hpp"
#include "../includes/matrix.hpp"
#include "../includes/utils.hpp"

int main() {

    std::cout << angle_cos(
        Vector<f32>({1, 0}), 
        Vector<f32>({1, 0}
    )) << std::endl;



    std::cout << angle_cos(
        Vector<f32>({1, 0}), 
        Vector<f32>({0, 1}
    )) << std::endl;



    std::cout << angle_cos(
        Vector<f32>({-1, 1}), 
        Vector<f32>({1, -1}
    )) << std::endl;

    std::cout << angle_cos(
        Vector<f32>({2, 1}), 
        Vector<f32>({4, 2}
    )) << std::endl;

    std::cout << angle_cos(
        Vector<f32>({1, 2, 3}), 
        Vector<f32>({4, 5}
    )) << std::endl;
}