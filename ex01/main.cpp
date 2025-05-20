#include "../includes/vector.hpp"
#include "../includes/matrix.hpp"
#include "../includes/utils.hpp"
#include <vector>


int main() {


    Vector<f32> e1 = Vector<f32>(
        {1, 0, 0}
    );

    Vector<f32> e2 = Vector<f32>(
        {0, 1, 0}
    );

    Vector<f32> e3 = Vector<f32>(
        {0, 0, 1}
    );

    linear_combination(
        std::vector<Vector<f32>>{e1, e2, e3},
        {10.f, -2, 0.5}
    ).print();

    Vector<f32> v1 = Vector<f32>(
        {1, 2, 3}
    );

    Vector<f32> v2 = Vector<f32>(
        {0, 10, -100}
    );

    linear_combination(
        std::vector<Vector<f32>>{v1, v2},
        {10.f, -2}
    ).print();


    return 0;
}