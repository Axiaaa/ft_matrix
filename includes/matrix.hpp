#pragma once

#include <cstddef>
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
        Matrix(std::vector<std::vector<K>> data) : _data(data) {}
        
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

        // Methods

        /**
        * @brief Prints the matrix to the console
        * @note
        */
        void print() const {
            size_t rows = getRows();
            size_t cols = getCols();
            for (size_t j = 0; j < cols; j++) {
            std::cout << "[ ";
            for (size_t i = 0; i < rows; i++) {
                if (i == rows - 1)
                std::cout << this->_data[i][j];
                else
                std::cout << this->_data[i][j] << ", ";
            }
            std::cout << " ]" << std::endl;
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
        void add(Matrix<K> const &M) {
            if (this->_data.size() != M.getRows() || this->_data[0].size() != M.getCols()) {
                throw std::invalid_argument("The matrixs must have the same size.");
            }
            for (size_t i = 0; i < this->_data.size(); i++) {
                for (size_t j = 0; j < this->_data[i].size(); j++) {
                    this->_data[i][j] += M[i][j];
                }
            }
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