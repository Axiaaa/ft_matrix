#include "../includes/vector.hpp"
#include "../includes/matrix.hpp"
#include "../includes/utils.hpp"

int main() {
    Vector<f32> e1 = Vector<f32>(
        {-1, 6}
    );

    Vector<f32> e2 = Vector<f32>(
        {3, 2}
    );

    std::cout << e1.dot(e2) << std::endl;
    std::cout << Vector<f32>({1 , 1}).dot(Vector<f32>({1, 1})) << std::endl;

    std::cout << dot(Vector<f32>({1 , 3}), Vector<f32>({3 , 2})) << std::endl;

}