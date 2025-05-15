#include "../includes/vector.hpp"
#include "../includes/matrix.hpp"
#include <vector>
int main() {

    Vector<f32> vec1({1, 2, 3});
    std::cout << "Initial vec1: ";
    vec1.print();

    vec1.add(Vector<f32>({1, 2, 3}));
    std::cout << "After adding {1, 2, 3} to vec1: ";
    vec1.print();

    vec1.sub(Vector<f32>({1, 2, 3}));
    std::cout << "After subtracting {1, 2, 3} from vec1: ";
    vec1.print();

    vec1.scl(2.f);
    std::cout << "After scaling vec1 by 2: ";
    vec1.print();

    Vector<f32> vec2({1, 2, 3});
    std::cout << "Initial vec2: ";
    vec2.print();

    std::cout << "Result of adding vec1 and vec2: ";
    add(vec1, vec2).print();

    std::cout << "Result of subtracting vec2 from vec1: ";
    sub(vec1, vec2).print();

    std::cout << "Result of scaling vec2 by 2: ";
    scl(vec2, 2.f).print();

    Matrix<f32> mat1({
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}});
    std::cout << "Initial mat1: " << std::endl;
    mat1.print();

    mat1.add(Matrix<f32>({
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}}));
    std::cout << "After adding the same matrix to mat1: " << std::endl;
    mat1.print();

    mat1.sub(Matrix<f32>({
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}}));

    std::cout << "After subtracting the same matrix from mat1: " << std::endl;
    mat1.print();

    mat1.scl(2.f);
    std::cout << "After scaling mat1 by 2: " << std::endl;
    mat1.print();

    Matrix<f32> mat2({
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}});
    std::cout << "Initial mat2: " << std::endl;
    mat2.print();

    std::cout << "Result of adding mat1 and mat2: " << std::endl;
    add(mat1, mat2).print();

    std::cout << "Result of subtracting mat2 from mat1: " << std::endl;
    sub(mat1, mat2).print();

    std::cout << "Result of scaling mat2 by 2: " << std::endl;
    scl(mat2, 2.f).print();



    return 0;
}