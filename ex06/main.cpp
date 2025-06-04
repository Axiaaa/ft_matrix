#include "../includes/vector.hpp"
#include "../includes/matrix.hpp"
#include "../includes/utils.hpp"

int main() {

    cross_product(
        Vector<f32>({0, 0, 1}), 
        Vector<f32>({1, 0, 0}
    )).print();

    cross_product(
        Vector<f32>({1, 2, 3}), 
        Vector<f32>({4, 5, 6}
    )).print();

    cross_product(
        Vector<f32>({4, 2, -3}), 
        Vector<f32>({-2, -5, 16}
    )).print();


}