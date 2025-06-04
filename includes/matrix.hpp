#pragma once

#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <vector>

template <typename K>
class Vector;

template <typename K>
class Matrix {

    private :
        std::vector<std::vector<K>> _data;

    public:
        //Constructors & Desctructors

        Matrix() : _data() {}

        Matrix(std::vector<std::vector<K>> data)
        {
            if (data.empty()) {
                return;
            }
            _data.resize(data.size());
            for (size_t i = 0; i < data.size(); ++i) {
                _data[i].resize(data[i].size());
                for (size_t j = 0; j < data[i].size(); ++j) {
                    _data[i][j] = data[i][j];
                }
            }
        }
        
        //Constructor used to convert a Vector to a Matrix for the 
        Matrix(std::vector<K> data, size_t rows, size_t cols) {
            if (rows == 0 || cols == 0) {
                throw std::invalid_argument("The number of rows and columns must be greater than 0.");
            }
            if (data.size() < rows * cols) {
                throw std::invalid_argument("The provided vector does not have enough elements for the specified rows and columns.");
            }
            for (size_t i = 0; i < rows; i++) {
                std::vector<K> row;
                for (size_t j = 0; j < cols; j++) {
                    row.push_back(data[i * cols + j]);
                }
                this->_data.push_back(row);
            }
        }
        
        ~Matrix() {}
        
        // Getters and Setters

        size_t getRows() const { return this->_data.size(); }
        size_t getCols() const { return this->_data[0].size(); }

        void append(Vector<K> value) {
            if (this->_data.empty()) {
                std::vector<K> newRow;
                for (size_t i = 0; i < value.getSize(); ++i) {
                    newRow.push_back(value[i]);
                }
                this->_data.push_back(newRow);
            } else {
                if (value.getSize() != this->getCols()) {
                    throw std::invalid_argument("Vector size must match matrix column count for append operation.");
                }
                
                std::vector<K> newRow;
                for (size_t i = 0; i < value.getSize(); ++i) {
                    newRow.push_back(value[i]);
                }
                this->_data.push_back(newRow);
            }
        }

        // Methods

        /**
        * @brief Prints the matrix to the console
        * @note
        */
        void print() const {
            for (size_t i = 0; i < this->getRows(); ++i)
            {
                std::cout << "[ ";
                for (size_t j = 0; j < this->getCols(); ++j)
                {
                    std::cout << _data[i][j];
                    if (j != this->getCols() - 1)
                        std::cout << ", ";
                }
                std::cout << " ]\n";
            }
        }

        Vector<K> toVector() const {
            std::vector<K> data;
            for (size_t i = 0; i < this->_data.size(); i++) {
                for (size_t j = 0; j < this->_data[i].size(); j++) {
                    data.push_back(this->_data[i][j]);
                }
            }
            return Vector<K>(data);
        }
        
        std::vector<K>& operator[](std::size_t row)
        {
            if (row >= getRows())
                throw std::out_of_range("Matrix row index out of range.");
            return _data[row];
        }

        const std::vector<K>& operator[](std::size_t row) const
        {
            if (row >= getRows())
                throw std::out_of_range("Matrix row index out of range.");
            return _data[row];
        }


        /*========================= EX 00 =========================*/
        /*
        * Methods for the matrix class based on the ex00 instructions.
        * Pure functions are at the bottom of the file, after the class definition.
        */
        
        
        /**
        * @brief Adds a matrix to the current matrix
        * @param v The matrix to add
        */
        void add(Matrix<K> const &M)
        {
            if (this->_data.size() != M.getRows() || this->_data[0].size() != M.getCols()) {
                throw std::invalid_argument("The matrixs must have the same size.");
            }
            for (size_t i = 0; i < this->_data.size(); i++) {
                for (size_t j = 0; j < this->_data[i].size(); j++) {
                    this->_data[i][j] += M[i][j];
                }
            }
        }

        Matrix<K> operator+=(Matrix<K> const &A)
        {
            if (this->_data.size() != A.getRows() || this->_data[0].size() != A.getCols()) {
                throw std::invalid_argument("The matrixs must have the same size.");
            }
            for (size_t i = 0; i < this->_data.size(); i++) {
                for (size_t j = 0; j < this->_data[i].size(); j++) {
                    this->_data[i][j] += A[i][j];
                }
            }
            return *this;
        }

        /**
        * @brief Subs a matrix to the current matrix
        * @param v The matrix to sub
        */
        void sub(Matrix<K> const &M) {
            if (this->_data.size() != M.getRows() || this->_data[0].size() != M.getCols()) {
                throw std::invalid_argument("The matrixs must have the same size.");
            }
            for (size_t i = 0; i < this->_data.size(); i++) {
                for (size_t j = 0; j < this->_data[i].size(); j++) {
                    this->_data[i][j] -= M[i][j];
                }
            }
        }


        Matrix<K> operator-=(Matrix<K> const &A)
        {
            if (this->_data.size() != A.getRows() || this->_data[0].size() != A.getCols()) {
                throw std::invalid_argument("The matrixs must have the same size.");
            }
            for (size_t i = 0; i < this->_data.size(); i++) {
                for (size_t j = 0; j < this->_data[i].size(); j++) {
                    this->_data[i][j] -= A[i][j];
                }
            }
            return *this;
        }

        /**
        * @brief Scale the current matrix to a Scalar
        * @param scalar The variable to scale the matrix to
        */
        void scl(K const &scalar)
        {
            for (size_t i = 0; i < this->_data.size(); i++) {
                for (size_t j = 0; j < this->_data[i].size(); j++) {
                    this->_data[i][j] *= scalar;
                }
            }
        }

        Matrix<K> operator*=(K const &scalar)
        {
            for (size_t i = 0; i < this->_data.size(); i++) {
                for (size_t j = 0; j < this->_data[i].size(); j++) {
                    this->_data[i][j] *= scalar;
                }
            }
            return *this;
        }

        void mul_vec(const Vector<K>& u)
        {
            if (u.getSize() != this->getCols())
                throw std::invalid_argument("The vector size doesn't match the matrix column count.");
            
            std::vector<K> result(this->getRows(), K());
        
            for (size_t i = 0; i < this->getRows(); i++) {
                for (size_t j = 0; j < this->getCols(); j++) {
                    result[i] += (*this)[i][j] * u[j];
                }
            }
            this->_data.clear();
            for (size_t i = 0; i < result.size(); i++) {
                this->_data.push_back({result[i]});
            }
        }

    void mul_mat(Matrix<K> const &A) {
        if (A.getCols() != this->getRows())
         throw std::invalid_argument("The matrix sizes don't match.");

        std::vector<std::vector<K>> result;

        for (size_t i = 0; i < A.getRows(); i++) {
         std::vector<K> row;
         for (size_t j = 0; j < this->getCols(); j++) {
             K sum = K();
             for (size_t k = 0; k < A.getCols(); k++) {
              sum += A[i][k] * (*this)[k][j];
             }
             row.push_back(sum);
         }
         result.push_back(row);
        }
        
        _data = result;
    }
};


/**
* @brief Adds a matrix to the current matrix
* @param v The matrix to add
*/
template <typename K>
Matrix<K> add(Matrix<K> const &M, Matrix<K> const &N) {
    if (M.getRows() != N.getRows() || M.getCols() != N.getCols()) {
        throw std::invalid_argument("The matrixs must have the same size.");
    }
    std::vector<std::vector<K>> data;
    for (size_t i = 0; i < M.getRows(); i++) {
        std::vector<K> row;
        for (size_t j = 0; j < M.getCols(); j++) {
            row.push_back(M[i][j] + N[i][j]);
        }
        data.push_back(row);
    }
    return Matrix<K>(data);
}

template <typename K>
Matrix<K> operator+(Matrix<K> const &M, Matrix<K> const &N) {
    if (M.getRows() != N.getRows() || M.getCols() != N.getCols()) {
        throw std::invalid_argument("The matrixs must have the same size.");
    }
    std::vector<std::vector<K>> data;
    for (size_t i = 0; i < M.getRows(); i++) {
        std::vector<K> row;
        for (size_t j = 0; j < M.getCols(); j++) {
            row.push_back(M[i][j] + N[i][j]);
        }
        data.push_back(row);
    }
    return Matrix<K>(data);
}

/**
* @brief Subs a matrix to the current matrix
* @param v The matrix to sub
*/
template <typename K>
Matrix<K> sub(Matrix<K> const &M, Matrix<K> const &N) {
    if (M.getRows() != N.getRows() || M.getCols() != N.getCols()) {
        throw std::invalid_argument("The matrixs must have the same size.");
    }
    std::vector<std::vector<K>> data;
    for (size_t i = 0; i < M.getRows(); i++) {
        std::vector<K> row;
        for (size_t j = 0; j < M.getCols(); j++) {
            row.push_back(M[i][j] - N[i][j]);
        }
        data.push_back(row);
    }
    return Matrix<K>(data);
}

template <typename K>
Matrix<K> operator-(Matrix<K> const &M, Matrix<K> const &N) {
    if (M.getRows() != N.getRows() || M.getCols() != N.getCols()) {
        throw std::invalid_argument("The matrixs must have the same size.");
    }
    std::vector<std::vector<K>> data;
    for (size_t i = 0; i < M.getRows(); i++) {
        std::vector<K> row;
        for (size_t j = 0; j < M.getCols(); j++) {
            row.push_back(M[i][j] - N[i][j]);
        }
        data.push_back(row);
    }
    return Matrix<K>(data);
}

/**
* @brief Scale the current matrix to a Scalar
* @param scalar The variable to scale the matrix to
*/
template <typename K>
Matrix<K> scl(Matrix<K> const &M, K const &scalar)
{
    std::vector<std::vector<K>> data;
    for (size_t i = 0; i < M.getRows(); i++) {
        std::vector<K> row;
        for (size_t j = 0; j < M.getCols(); j++) {
            row.push_back(M[i][j] * scalar);
        }
        data.push_back(row);
    }
    return Matrix<K>(data);
}

template <typename K>
Matrix<K> operator*(Matrix<K> const &M, K const &scalar)
{
    std::vector<std::vector<K>> data;
    for (size_t i = 0; i < M.getRows(); i++) {
        std::vector<K> row;
        for (size_t j = 0; j < M.getCols(); j++) {
            row.push_back(M[i][j] * scalar);
        }
        data.push_back(row);
    }
    return Matrix<K>(data);
}

template <typename K>
Matrix<K> operator*(K const &scalar, Matrix<K> const &M)
{
    std::vector<std::vector<K>> data;
    for (size_t i = 0; i < M.getRows(); i++) {
        std::vector<K> row;
        for (size_t j = 0; j < M.getCols(); j++) {
            row.push_back(M[i][j] * scalar);
        }
        data.push_back(row);
    }
    return Matrix<K>(data);
}


template <typename K>
bool operator==(Matrix<K> const &M, Matrix<K> const &N) {
    if (M.getRows() != N.getRows() || M.getCols() != N.getCols()) {
        throw std::invalid_argument("The matrixs must have the same size.");
    }
    for (size_t i = 0; i < M.getRows(); i++) {
        for (size_t j = 0; j < M.getCols(); j++) {
            if (M[i] != N[i])
                return false;
        }
    }
    return true;
}