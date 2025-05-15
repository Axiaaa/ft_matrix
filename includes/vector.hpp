#pragma once

#include <cstddef>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <iostream>

using f32 = float; // 32-bit floating point to match the subjet

template <typename K>
class Matrix;

template <typename K>
class Vector {

    private :
        std::vector<K> _data;

    public:
        //Constructors & Desctructors
        Vector() : _data() {}
        Vector(std::vector<K> data) : _data(data) {}
        ~Vector() {}
        
    
        // Getters and Setters
        
        K getData(size_t index) const { return this->_data[index]; }
        size_t getSize() const { return this->_data.size(); }
        void append(K value) { this->_data.push_back(value); }

        // Methods
        void print() const {
        
            std::cout << "[ ";
            for (size_t i = 0; i < this->_data.size(); i++)
                if (i == this->_data.size() - 1)
                    std::cout << this->_data[i];
                else
                    std::cout << this->_data[i] << ", ";
            std::cout << " ] " << std::endl;
        }

        Matrix<K> toMatrix(size_t rows, size_t cols) const { return Matrix<K>(this->_data, rows, cols); }


        K& operator[](std::size_t index)
        {
            if (index >= getSize())
                throw std::out_of_range("Vector index out of range.");
            return _data[index];
        }

        const K& operator[](std::size_t index) const
        {
            if (index >= getSize())
                throw std::out_of_range("Vector index out of range.");
            return _data[index];
        }

        std::ofstream &operator<<(std::ofstream &os) const
        {
            os << "[ ";
            for (size_t i = 0; i < this->_data.size(); i++)
                if (i == this->_data.size() - 1)
                    os << this->_data[i];
                else
                    os << this->_data[i] << ", ";
            os << " ] ";
            return os;
        }
        

        /*========================= EX 00 =========================*/
        /*
        * Methods for the vector class based on the ex00 instructions.
        * Pure functions are at the bottom of the file, after the class definition.
        */
        
        
        /*
        * @brief Adds a vector to the current vector
        * @param v The vector to add
        */
        void add(Vector<K> const &v) {
            if (this->_data.size() != v.getSize()) {
                throw std::invalid_argument("The vectors must have the same size.");
            }
            for (size_t i = 0; i < this->_data.size(); i++) {
                this->_data[i] += v.getData(i);
            }
        }

        /*
        * @brief Subs a vector to the current vector
        * @param v The vector to sub
        */
        void sub(Vector<K> const &v) {
            if (this->_data.size() != v.getSize()) {
                throw std::invalid_argument("The vectors must have the same size.");
            }
            for (size_t i = 0; i < this->_data.size(); i++) {
                this->_data[i] -= v.getData(i);
            }
        }

        /**
        * @brief Scale the current vector to a Scalar
        * @param scalar The variable to scale the vector to
        */
        void scl(K const &scalar)
        {
            for (size_t i = 0; i < this->_data.size(); i++) {
                this->_data[i] *= scalar;
            }
        }

        /*========================= EX 01 =========================*/
        /*
        * Methods for the vector class based on the ex01 instructions.
        * Pure functions are at the bottom of the file, after the class definition.
        */  

        //No class methods for this one.


    };
    
    
    /**
    * @brief Adds 2 vectors and returns the result
    * @param v The first vector
    * @param u The second vector
    */
    template <typename K>
    Vector<K> add(Vector<K> const &v, Vector<K> const &u)
    {
        if (u.getSize() != v.getSize()) {
            throw std::invalid_argument("The vectors must have the same size.");
        }
        Vector<K> result;
        for (size_t i = 0; i < v.getSize(); i++)
        result.append(v.getData(i) + u.getData(i));
    return  result;
}

/**
* @brief Sums 2 vectors and returns the result
* @param v The first vector
* @param u The second vector
*/
template <typename K>
Vector<K> sub(Vector<K> const &v, Vector<K> const &u)
{
    if (u.getSize() != v.getSize()) {
        throw std::invalid_argument("The vectors must have the same size.");
    }
    Vector<K> result;
    for (size_t i = 0; i < v.getSize(); i++)
    result.append(v.getData(i) - u.getData(i));
return  result;
}

/**
* @brief Scale a vector on a Scalar and returns the result
* @param v The vector to scale
* @param scalar The Scalar
*/
template <typename K>
Vector<K> scl(Vector<K> const &v, K scalar)
{
    Vector<K> result;
    for (size_t i = 0; i < v.getSize(); i++)
        result.append(v.getData(i) * scalar);
    return result;
}

