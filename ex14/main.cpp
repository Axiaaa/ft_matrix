#include "../includes/vector.hpp"
#include "../includes/matrix.hpp"
#include "../includes/utils.hpp"
#include <cassert>
#include <exception>
#include <fstream>
#include <stdexcept>

const std::string filename = "proj";
// export WINIT_UNIX_BACKEND=x11 RUST_BACKTRACE=full


int main(int ac, char **av) {
    try {
        if (ac != 5)
        {
            throw std::invalid_argument("The program is waiting for 4 args such as fov, ratio, near, far");
        }

        auto matproj = projection(atof(av[1]), atof(av[2]), atof(av[3]), atof(av[4]));
        std::ofstream proj(filename, std::ios::out);
        if (proj.is_open())
        {
            for (size_t col = 0; col < matproj.getCols(); ++col)
            {
                for (size_t row = 0; row < matproj.getRows(); ++row)
                {
                    proj << matproj[col][row];
                    if (row != 3)
                        proj << ", ";
                }
                proj << "\n";
            }
        }        
    }
    catch (std::exception &e)
    {
        std::cout << "Caught exception : " << e.what() << std::endl;
    }
    
}