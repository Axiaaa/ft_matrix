#pragma once

#include <climits>
#include <cmath>
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
        // Vector(K value, size_t size) {
        //     _data = std::vector<K>(size, value);
        // };
        Vector(const Vector<K>& other) : _data(other._data) {}
        ~Vector() {}
        
    
        // Getters and Setters
        
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
        void add(Vector<K> const &v) 
        {
            if (this->_data.size() != v.getSize()) {
                throw std::invalid_argument("The vectors must have the same size.");
            }
            for (size_t i = 0; i < this->_data.size(); i++) {
                this->_data[i] += v[i];
            }
        } 

        Vector<K>& operator+=(const Vector<K>& v)
        {
            if (this->_data.size() != v.getSize()) {
                throw std::invalid_argument("The vectors must have the same size.");
            }
            for (size_t i = 0; i < this->_data.size(); i++) {
                this->_data[i] += v[i];
            }
            return *this;
        }

        /*
        * @brief Subs a vector to the current vector
        * @param v The vector to sub
        */
        void sub(Vector<K> const &v)
        {
            if (this->_data.size() != v.getSize()) {
                throw std::invalid_argument("The vectors must have the same size.");
            }
            for (size_t i = 0; i < this->_data.size(); i++) {
                this->_data[i] -= v._data[i];
            }
        }

        Vector<K>& operator-=(const Vector<K>& v)
        {
            if (this->_data.size() != v.getSize()) {
                throw std::invalid_argument("The vectors must have the same size.");
            }
            for (size_t i = 0; i < this->_data.size(); i++) {
                this->_data[i] -= v._data[i];
            }
            return *this;
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

        Vector<K>& operator*=(const K& scalar)
        {
            for (size_t i = 0; i < this->_data.size(); i++) {
                this->_data[i] *= scalar;
            }
            return *this;
        }


        /*========================= EX 01 =========================*/
        /*
        * Methods for the vector class based on the ex01 instructions.
        * Pure functions are at the bottom of the file, after the class definition.
        */  

        //No class methods for this one.

        /*========================= EX 02 =========================*/
        /*
        * Methods for the vector class based on the ex02 instructions.
        * Pure functions are at the bottom of the file, after the class definition.
        */  

        //No class methods for this one.

        /*========================= EX 03 =========================*/
        /*
        * Methods for the vector class based on the ex03 instructions.
        * Pure functions are at the bottom of the file, after the class definition.
        */  

        K dot(const Vector<K>& v)
        {
            if (this->getSize() != v.getSize())
                throw std::invalid_argument("The vectors must have the same size.");

            Vector<K> tmp(v * (*this));
            K res = 0;
            for (size_t i = 0; i < this->getSize(); ++i)
                res += tmp[i];
            return res;
        }
    
        /*========================= EX 04 =========================*/
        /*
        * Methods for the vector class based on the ex04 instructions.
        * Pure functions are at the bottom of the file, after the class definition.
        */  

        /**
        * @brief Return the biggest value of the vector.
        *
        * @return K The biggest value.
        */
        K max()
        {
            K max_val = this[0];
            for (size_t i = 0; i < this->getSize(); ++i)
                this[i] > max_val ? max_val = this[i] : max_val;
            return max_val;
        }

        /**
        * @brief Computes the infinity norm (maximum norm) of the vector.
        * 
        * @note The infinity norm of a vector is the absolute value of the largest element
        * in the vector.
        * 
        * @return The infinity norm of the vector.
        */
        K norm_inf()
        {
            return this->max();
        }

        /**
        * @brief Computes the 1-norm of the vector.
        * 
        * @note The 1-norm of a vector is the sum of the absolute values of all its elements.
        * 
        * @return The 1-norm of the vector.
        */
        K norm_1()
        {
            K res = this[0];
            for (size_t i = 0; i < this->getSize(); ++i)
                res += this[i];
            return res;
        }

        /**
        * @brief Computes the Euclidean norm (L2 norm) of the vector.
        * 
        * @note The Euclidean norm of a vector is the square root of the sum of the squares
        * of its elements, which corresponds to the Euclidean distance between the vector
        * and the origin in an n-dimensional space.
        * 
        * @return The Euclidean norm of the vector (0 if the vector is zero).
        */
        K norm()
        {
            K res = dot(this, this);
            return res > 0 ? sqrt(res) : 0;
        }

        /**
        * @brief Calculate the magnitude (length) of the vector.
        * 
        * @note Calculating the magnitude of a vector is useful in various mathematical and physical applications,
        * such as determining the distance between two points, normalizing vectors, and calculating scalar projections.
        * 
        * @return The magnitude of the vector.
        */
        K mag()
        {
            return (dot(this, this));
        }

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
        result.append(v[i] + u[i]);
    return result;
}

template <typename K>
Vector<K> operator+(Vector<K> const &v, Vector<K> const &u)
{
    if (u.getSize() != v.getSize()) {
        throw std::invalid_argument("The vectors must have the same size.");
    }
    Vector<K> result;
    for (size_t i = 0; i < v.getSize(); i++)
        result.append(v[i] + u[i]);
    return result;
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
        result.append(v[i] - u[i]);
    return  result;
}

template <typename K>
Vector<K> operator-(Vector<K> const &v, Vector<K> const &u)
{
    if (u.getSize() != v.getSize()) {
        throw std::invalid_argument("The vectors must have the same size.");
    }
    Vector<K> result;
    for (size_t i = 0; i < v.getSize(); i++)
        result.append(v[i] - u[i]);
    return result;
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
        result.append(v[i] * scalar);
    return result;
}

template<typename K>
Vector<K> operator*(const Vector<K>& v, const K& scalar) {
    Vector<K> result;
    for (size_t i = 0; i < v.getSize(); i++) {
        result.append(v[i] * scalar);
    }
    return result;
}

template<typename K>
Vector<K> operator*(const K& scalar, const Vector<K>& v) {
    Vector<K> result;
    for (size_t i = 0; i < v.getSize(); i++) {
        result.append(v[i] * scalar);
    }
    return result;
}

template<typename K>
Vector<K> operator*(const Vector<K>& v, const Vector<K>& u)
{
    if (u.getSize() != v.getSize()) {
        throw std::invalid_argument("The vectors must have the same size.");
    }
    Vector<K> result(v);
    for (size_t i = 0; i < v.getSize(); ++i)
        result[i] *= u[i];
    return result;
}

template<typename K>
bool operator==(const Vector<K>& v, const Vector<K>& u) {
    if (u.getSize() != v.getSize()) {
        throw std::invalid_argument("The vectors must have the same size.");
    }
    for (size_t i = 0; i < v.getSize(); i++) {
        if (v[i] != u[i])
            return false;
    }
    return true;
}

template<typename K>
K dot(const Vector<K>& v, const Vector<K>& u)
{
    if (u.getSize() != v.getSize())
        throw std::invalid_argument("The vectors must have the same size.");

    Vector<K> tmp(v * u);
    K res = 0;
    for (size_t i = 0; i < u.getSize(); ++i)
        res += tmp[i];
    return res;
}

template<typename K>
K norm_inf(const Vector<K>& v)
{
    return v.max();
}

template<typename K>
K norm_1(const Vector<K>& v)
{
    K res = v[0];
    for (size_t i = 0; i < this->getSize(); ++i)
        res += this[i];
    return res;
}

template<typename K>
K norm(const Vector<K>& v)
{
    K res = dot(v, v);
    return res > 0 ? sqrt(res) : 0;
}