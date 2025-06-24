#pragma once

#include <fstream>
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
        std::vector<K> toStd() { return this->_data; }

        K& operator[](std::size_t index)
        {
            return _data.at(index);
        }
        
        const K& operator[](std::size_t index) const
        {
            return _data.at(index);
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
        
        
        /**
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

        /**
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

        /**
         * @brief Calculates the dot product of this vector with another vector.
         * 
         * The dot product is a scalar value that is equal to the sum of the products of
         * the corresponding components of the two vectors.
         * 
         * @param v The vector to calculate the dot product with.
         * @return K The scalar dot product result.
         * @throws std::invalid_argument If the vectors have different sizes.
         */
        K dot(const Vector<K>& v)
        {
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
        K max() const
        {
            if (this->getSize() == 0)
                throw std::runtime_error("Cannot find maximum of an empty vector");
            K max_val = (*this)[0];
            for (size_t i = 1; i < this->getSize(); ++i)
                if ((*this)[i] > max_val)
                    max_val = (*this)[i];
            return max_val;
        }

        /**
         * @brief Calculates the squared magnitude (length) of the vector
         * 
         * This method returns the dot product of the vector with itself, which
         * is equivalent to the sum of squares of all vector components.
         * 
         * @return The squared magnitude of the vector as type K
         * 
         * @note Using squared magnitude is more efficient than calculating the 
         * actual magnitude when only comparing vector lengths, as it avoids the
         * computationally expensive square root operation. For example, to determine
         * if vector A is longer than vector B, comparing A.mag2() > B.mag2() is
         * more efficient than comparing A.mag() > B.mag().
         */
        K mag2() const
        {
            return (dot(this, this));
        }

        /**
         * @brief Normalize the vector.
         * 
         * @return void
         */
        void normalize()
        {
            K tmp = norm(*this);
            if (tmp == 0)
                throw std::invalid_argument("Cannot normalise vector of 0");
            this->scl(1 / tmp);
        }


       
        /*========================= EX 06 =========================*/
        /*
        * Methods for the vector class based on the ex03 instructions.
        * Pure functions are at the bottom of the file, after the class definition.
        */   

        /**
        * @brief Computes the cross product of two 3D vectors.
        * 
        * The cross product is a binary operation on two vectors in three-dimensional space
        * that results in another vector perpendicular to both of the input vectors.
        * 
        * @tparam K The type of elements stored in the vectors
        * @param v First 3D vector
        * @param u Second 3D vector
        * @return Vector<K> The cross product v × u
        * @throws std::invalid_argument If either vector is not 3-dimensional
        */
        void cross_product(const Vector<K>& u)
        {
            if (this->getSize() != 3 || u.getSize() != 3)
                throw std::invalid_argument("The vectors have to be 3 Dimensions");
            std::vector<K> res({
                (*this)[1] * u[2] - (*this)[2] * u[1],
                (*this)[2] * u[0] - (*this)[0] * u[2],
                (*this)[0] * u[1] - (*this)[1] * u[0]
            });
            this->_data = res;
        }


        //No class methods for the rest of the project
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

/**
 * @brief Computes the dot product of two vectors.
 * 
 * The dot product is calculated as the sum of the products of the corresponding elements
 * of the two vectors.
 * 
 * @param v First vector
 * @param u Second vector
 * @return The dot product of the two vectors
 * @throws std::invalid_argument If the vectors do not have the same size
 */
template<typename K>
K dot(const Vector<K>& v, const Vector<K>& u)
{
    Vector<K> tmp(v * u);
    K res = 0;
    for (size_t i = 0; i < u.getSize(); ++i)
        res += tmp[i];
    return res;
}




