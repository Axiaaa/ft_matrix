#include "../includes/vector.hpp"
#include "../includes/matrix.hpp"
#include <iostream>
#include <vector>

int main() {


    std::vector<f32> Vec = {
        1, 2, 3, 4, 5, 6, 7, 8, 9,
    };

    
    
    std::vector<std::vector<f32>> Mat = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    
    Vector<f32> VecObj(Vec);
    std::cout << "Original Vector:" << std::endl;
    VecObj.print();
    std::cout << "Vector element at index 2 for : " << VecObj[2] << std::endl;
    std::cout << "Vector size: " << VecObj.getSize() << std::endl;

    Matrix<f32> MatObj(Mat);
    std::cout << "Original Matrix:" << std::endl;
    MatObj.print();
    std::cout << "Matrix element at index 1, 2: " << MatObj[1][2] << std::endl;

        
    Matrix<f32> MatObj2 = VecObj.toMatrix(3, 2);
    std::cout << "Converted Vector to Matrix (3x2):" << std::endl;
    MatObj2.print();
    Vector<f32> VecObj2 = MatObj2.toVector();
    std::cout << "Converted Matrix back to Vector:" << std::endl;
    VecObj2.print();


    return 0;

}
