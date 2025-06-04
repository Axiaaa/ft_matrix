#include "../includes/vector.hpp"
#include "../includes/matrix.hpp"
#include "../includes/utils.hpp"

int main() {

    Matrix<f32> m1({
        {1, -1, 2},
        {0, -3, 1 }
    });

    Vector<f32> e = mul_vec(m1, Vector<f32>({2, 1, 0}));
    e.print();
    
    std::cout << "==========" << std::endl;
    m1.mul_vec(Vector<f32>({2, 1, 0}));
    m1.print();
    std::cout << "==========" << std::endl;

    Matrix<f32> m2({
        {1, 2, 3},
        {4, 5 ,6},
        {7, 8, 9},
        {10, 11, 12}
   });

   m2.mul_vec(Vector<f32>({-2, 1, 0}));
   m2.print();

   std::cout << "==========" << std::endl;

    Matrix<f32> m3({
        {1, 2},
        {3, 4},
        {5, 6 }
    });

    Matrix<f32> m4({
        {1, 2, 3},
        {4, 5, 6}
    });

    Matrix<f32> m5 = mul_mat(m4, m3);
    m5.print();

    std::cout << "==========" << std::endl;

    Matrix<f32> m6({
        {1, 2},
        {3, 4},
        {5, 6 }
    });

    Matrix<f32> m7({
        {1, 2, 3},
        {4, 5, 6}
    });

    m6.mul_mat(m7);
    m6.print();

}