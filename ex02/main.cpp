#include "../includes/vector.hpp"
#include "../includes/matrix.hpp"
#include "../includes/utils.hpp"

int main() {

    std::cout << "\nScalars lerp\n\n";

    std::cout << lerp(0, 1, 0) << std::endl;
    std::cout << lerp(0, 1, 1) << std::endl;
    std::cout << lerp(0., 1., 0.5) << std::endl;
    std::cout << lerp(21., 42., 0.3) << std::endl;
    std::cout << lerp(21., 42., -0.3) << std::endl;

    std::cout << "\nVectors lerp\n\n";

    Vector<f32> e1 = Vector<f32>(
        {2, 1}
    );

    Vector<f32> e2 = Vector<f32>(
        {4, 2}
    );

    lerp(e1, e2, 0.).print();
    lerp(e1, e2, 0.3).print();
    lerp(e1, e2, 1.).print();

    std::cout << "\nMatrices lerp\n\n";

    Matrix<f32> m1({
        {2, 1 },
        {3, 4}});

    Matrix<f32> m2({
        {20, 10 },
        {30, 40}});

    lerp(m1, m2, 0.5).print();
    lerp(m1, m2, 0).print();
    lerp(m1, m2, 1).print();

    return 0;
}