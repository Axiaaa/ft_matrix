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

        Matrix() : _data() {}

        Matrix(const Matrix<K>& other) : _data(other._data) {}
        
        explicit Matrix(std::vector<std::vector<K>> data)
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
        explicit Matrix(std::vector<K> data, size_t rows, size_t cols) {
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
            return _data.at(row);
        }

        const std::vector<K>& operator[](std::size_t row) const
        {
            return _data.at(row);
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
        
        //No class methods for this one.

        /*========================= EX 04 =========================*/
        /*
        * Methods for the vector class based on the ex04 instructions.
        * Pure functions are at the bottom of the file, after the class definition.
        */

        /*========================= EX 05 =========================*/
        /*
        * Methods for the vector class based on the ex05 instructions.
        * Pure functions are at the bottom of the file, after the class definition.
        */

        //No class methods for this one.

        /*========================= EX 06 =========================*/
        /*
        * Methods for the vector class based on the ex06 instructions.
        * Pure functions are at the bottom of the file, after the class definition.
        */

        //No class methods for this one.
        
        /*========================= EX 07 =========================*/
        /*
        * Methods for the vector class based on the ex06 instructions.
        * Pure functions are at the bottom of the file, after the class definition.
        */

        void mul_vec(const Vector<K>& u)
        {
            if (u.getSize() != this->getCols())
                throw std::invalid_argument("The vector size doesn't match the matrix column count.");
            
            Vector<K> result;

            for (size_t i = 0; i < this->getRows(); i++) {
                K sum = 0;
                for (size_t j = 0; j < this->getCols(); j++) {
                    sum += (*this)[i][j] * u[j];
                }
                    result.append(sum);
                    
            }
            this->_data.clear();
            for (size_t i = 0; i < result.getSize(); i++) {
                this->_data.push_back({result[i]});
            }
        }
    

        void mul_mat(Matrix<K> const &A)
        {
            if (this->getCols() != A.getRows())
                throw std::invalid_argument("The matrix sizes don't match.");

            std::vector<std::vector<K>> result;

            for (size_t i = 0; i < this->getRows(); i++) {
                std::vector<K> row;
                for (size_t j = 0; j < A.getCols(); j++) {
                    K sum = K();
                    for (size_t k = 0; k < this->getCols(); k++) {
                        sum += (*this)[i][k] * A[k][j];
                    }
                    row.push_back(sum);
                }
                result.push_back(row);
            }
            
            _data = result;
        }

        /*========================= EX 08 =========================*/
        /*
        * Methods for the vector class based on the ex06 instructions.
        * Pure functions are at the bottom of the file, after the class definition.
        */
        
        /**
        * @brief Computes the trace of a matrix.
        * 
        * The trace of a matrix is the sum of the elements on its main diagonal
        * (the elements where the row index equals the column index).
        * 
        * @tparam K The data type of the matrix elements.
        * @param A The input matrix for which to compute the trace.
        * @return K The trace of the input matrix (sum of diagonal elements).
        */
        K trace()
        {
            if (this->getCols() != this->getRows())
                throw std::invalid_argument("Matrix must be square for trace computation");
            K sum = 0;
            for (size_t i = 0; i < this->getCols(); ++i) {
                sum += (*this)[i][i];
            }
            return sum;
        }


        /*========================= EX 09 =========================*/
        /*
        * Methods for the vector class based on the ex06 instructions.
        * Pure functions are at the bottom of the file, after the class definition.
        */

        void transpose()
        {
            std::vector<std::vector<K>> transposed_data;
            
            if (this->_data.empty()) {
                return;
            }
            
            for (size_t j = 0; j < this->getCols(); j++) {
                std::vector<K> new_row;
                for (size_t i = 0; i < this->getRows(); i++) {
                    new_row.push_back((*this)[i][j]);
                }
                transposed_data.push_back(new_row);
            }
            this->_data = transposed_data;
        }

        /*========================= EX 10 =========================*/
        /*
        * Methods for the vector class based on the ex06 instructions.
        * Pure functions are at the bottom of the file, after the class definition.
        */


        /**
        * @brief Transforms a matrix into its row echelon form
        * 
        * This function applies elementary row operations to convert the input matrix
        * into row echelon form (REF). In row echelon form:
        * - All zero rows are at the bottom
        * - The leading coefficient (pivot) of each non-zero row appears to the right of
        *   the leading coefficient of the row above it
        * - All elements in a column below a leading coefficient are zeros
        * - The leading coefficient in each row is 1
        * 
        * If I want to put a zero inside L2 I will have to use the following formula : 
        * L2 ← L2 − k × L1
        * 
        * For exemple : 
        * L1 = [2, 4, -2]
        * L2 = [4, 9, -3]
        * L2 = L2 − 2 × L1 = [4,9,−3] − 2 × [2,4,−2] = [4,9,−3] − [4,8,−4] = [0,1,1]
        * 
        * Also in case k = -1 
        * L2 ← L2 − (-1) × L1 == L2 + 1 × L1 == L2 + L1
        * 
        * @tparam K The data type of the matrix elements
        * @param A The input matrix to be transformed
        */
        void row_echelon()
        {
            Matrix<K> result(*this);
            size_t rows = result.getRows();
            size_t cols = result.getCols();
            
            size_t pc = 0; // pivot column
            
            for (size_t i = 0; i < rows; ++i) {
                if (pc >= cols)
                    break;
                    
                // Find the first row with non-zero entry in pivot column
                size_t pr = i; // pivot row
                while (pr < rows && std::abs(result[pr][pc]) < K(1e-10))
                    ++pr;
                    
                // If no pivot found, move to next column
                if (pr == rows) {
                    ++pc, --i;
                    continue;
                }
                
                // Swap rows if necessary
                if (pr != i) {
                    for (size_t j = 0; j < cols; ++j) {
                        K tmp = result[i][j];
                        result[i][j] = result[pr][j];
                        result[pr][j] = tmp;
                    }
                }
                
                // Scale the pivot row to make pivot = 1
                K pv = result[i][pc];
                if (std::abs(pv) > K(1e-10)) {
                    for (size_t j = 0; j < cols; ++j)
                        result[i][j] /= pv;
                }
                
                // Eliminate other rows
                for (size_t r = 0; r < rows; ++r) {
                    if (r != i) {
                        K f = result[r][pc];
                        for (size_t j = 0; j < cols; ++j)
                            result[r][j] -= f * result[i][j];
                    }
                }
                ++pc;
            }
            this->_data = result._data;
        }


        /*========================= EX 11 =========================*/
        /*
        * Methods for the Matrix class based on the ex11 instructions.
        * Pure functions are at the bottom of the file, after the class definition.
        */

        /**
         * @brief Calculates the determinant of the matrix
         * 
         * This method computes the determinant of the matrix based on its dimensions:
         * - For 1x1 matrices: Returns the single element value
         * - For 2x2, 3x3, and 4x4 matrices: Uses specialized determinant algorithms
         * 
         * @return K The calculated determinant value
         * @throws std::invalid_argument If the matrix dimensions are not 1x1, 2x2, 3x3, or 4x4
         */
        K determinant()
        {
            if (this->getCols() == 1 && this->getRows() == 1)
                return (*this)[0][0];
            if (this->getCols() == 2 && this->getRows() == 2)
                return det2(*this);
            else if (this->getCols() == 3 && this->getRows() == 3)
                return det3(*this);
            else if (this->getCols() == 4 && this->getRows() == 4)
                return det4(*this);
            else
                throw std::invalid_argument("Cannot get matrix's determinant");
        }

        /*========================= EX 12 =========================*/
        /*
        * Methods for the Matrix class based on the ex12 instructions.
        * Pure functions are at the bottom of the file, after the class definition.
        */

        /**
        * @brief Computes the inverse of this matrix using Gaussian elimination with pivoting.
        * 
        * This method transforms the current matrix into its inverse by performing Gaussian elimination
        * with partial pivoting to improve numerical stability. It creates an augmented matrix
        * with the identity matrix and transforms the original matrix to identity while
        * simultaneously transforming the identity to the inverse.
        * 
        * @throws std::invalid_argument If this matrix is not square
        * @throws std::runtime_error If the matrix is singular and cannot be inverted
        * 
        * @note The method uses a tolerance of 1e-10 to determine if the matrix is singular
        * @time_complexity O(n³) where n is the dimension of the square matrix
        * @space_complexity O(n²) for the working matrices
        */
        void inverse()
        {
            if (this->getCols() != this->getRows())
                throw std::invalid_argument("Matrix must be square");

            size_t n = this->getRows();
            
            Matrix<K> mat(*this);
            Matrix<K> result(*this);
            for (size_t col = 0; col < n; ++col) {
                for (size_t row = 0; row < n; ++row) {
                    result[col][row] = (col == row) ? 1 : 0;
                }
            }
            
            for (size_t i = 0; i < n; ++i) {
                size_t max_row = i;
                for (size_t row = i + 1; row < n; ++row) {
                    if (std::abs(mat[i][row]) > std::abs(mat[i][max_row])) {
                        max_row = row;
                    }
                }
                
                if (max_row != i) {
                    for (size_t col = 0; col < n; ++col) {
                        std::swap(mat[col][i], mat[col][max_row]);
                        std::swap(result[col][i], result[col][max_row]);
                    }
                }
                
                if (std::abs(mat[i][i]) < 1e-10) {
                    throw std::runtime_error("Matrix is singular and cannot be inverted");
                }
                
                K pivot = mat[i][i];
                for (size_t col = 0; col < n; ++col) {
                    mat[col][i] /= pivot;
                    result[col][i] /= pivot;
                }
                
                for (size_t row = 0; row < n; ++row) {
                    if (row != i) {
                        K factor = mat[i][row];
                        for (size_t col = 0; col < n; ++col) {
                            mat[col][row] -= factor * mat[col][i];
                            result[col][row] -= factor * result[col][i];
                        }
                    }
                }
            }
            this->_data = result._data;
        }

        /*========================= EX 13 =========================*/
        /*
        * Methods for the Matrix class based on the ex13 instructions.
        * Pure functions are at the bottom of the file, after the class definition.
        */

        /**
        * @brief Computes the rank of the matrix.
        * 
        * This function returns the rank of the matrix, which is the number 
        * of linearly independent rows (or columns). It creates a temporary 
        * copy of the matrix, transforms it into row echelon form, and then 
        * counts the number of non-zero pivots along the main diagonal.
        * 
        * @tparam K The type of the elements in the matrix (e.g., int, float, double).
        * 
        * @return K The rank of the matrix.
        */
        K rank()
        {
            K rank = 0; 
            Matrix<K> tmp(*this);
            tmp.row_echelon();
            for (size_t col = 0; col < tmp.getCols(); ++col)
            {
                for (size_t row = 0; row < tmp.getRows(); ++row)
                {
                    if (col == row && std::abs(tmp[col][row]) > K(0e5))
                        rank++;
                }
            }
            return rank;
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
        throw std::invalid_argument("The matrix must have the same size.");
    }
    for (size_t i = 0; i < M.getRows(); i++) {
        for (size_t j = 0; j < M.getCols(); j++) {
            if (M[i] != N[i])
                return false;
        }
    }
    return true;
}


/**
* @brief Computes the linear transformation of a vector by a matrix.
* 
* @tparam K The data type of the vector and matrix elements.
* @param u The vector to be transformed.
* @param M The matrix representing the linear transformation.
* @return Vector<K> The resulting vector after applying the transformation.
* 
* @throws std::invalid_argument If the size of the vector does not match the 
*         number of columns in the matrix, as the transformation is undefined 
*         in this case.
*/
template <typename K>
Vector<K> mul_vec(const Matrix<K>& M, const Vector<K>& u)
{
    if (u.getSize() != M.getCols())
        throw std::invalid_argument("The vector size doesn't match the matrix column count.");

    Vector<K> result;

    for (size_t i = 0; i < M.getRows(); i++) {
        K sum = 0;
        for (size_t j = 0; j < M.getCols(); j++) {
            sum += M[i][j] * u[j];
        }
        result.append(sum);
    }
    return result;
}


/**
* @brief Computes the matrix multiplication of two matrices.
* 
* @tparam K The data type of the matrix elements.
* @param A The first matrix in the multiplication (left-hand side).
* @param B The second matrix in the multiplication (right-hand side).
* @return Matrix<K> The resulting matrix after multiplying A and B.
* 
* @throws std::invalid_argument If the number of columns in A does not match 
*         the number of rows in B, as matrix multiplication is undefined 
*         in this case.
*/
template <typename K>
Matrix<K> mul_mat(Matrix<K> A, Matrix<K> B) {

    if (A.getCols() != B.getRows())
        throw std::invalid_argument("The matrix sizes don't match.");

    Matrix<K> result;

    for (size_t i = 0; i < A.getRows(); i++) {
        Vector<K> row;
        for (size_t j = 0; j < B.getCols(); j++) {
            K sum = 0;
            for (size_t k = 0; k < A.getCols(); k++) {
                sum += A[i][k] * B[k][j];
            }
            row.append(sum);
        }
        result.append(row);
    }
    return result;
}

/**
 * @brief Computes the transpose of a matrix
 * 
 * Creates a new matrix where rows become columns and columns become rows.
 * For a matrix A of size m×n, the transpose will be of size n×m such that
 * the element at position (i,j) in the original matrix is at position (j,i)
 * in the transposed matrix.
 * 
 * @tparam K Type of elements in the matrix
 * @param A The input matrix to transpose
 * @return Matrix<K> The transposed matrix
 * 
 * @note Time complexity: O(rows * cols)
 *       Space complexity: O(rows * cols)
 */
template <typename K>
Matrix<K> transpose(const Matrix<K>& A)
{
    std::vector<std::vector<K>> transposed_data;
    
    for (size_t j = 0; j < A.getCols(); j++) {
        std::vector<K> new_row;
        for (size_t i = 0; i < A.getRows(); i++) {
            new_row.push_back(A[i][j]);
        }
        transposed_data.push_back(new_row);
    }
    return Matrix<K>(transposed_data);
}


/**
 * @brief Computes the inverse of a square matrix using Gaussian elimination with pivoting.
 * 
 * This function calculates the inverse of matrix A by performing Gaussian elimination
 * with partial pivoting to improve numerical stability. It creates an augmented matrix
 * with the identity matrix and transforms the original matrix to identity while
 * simultaneously transforming the identity to the inverse.
 * 
 * @tparam K The element type of the matrix (must support arithmetic operations)
 * @param A The input matrix to invert (must be square)
 * @return Matrix<K> The inverted matrix
 * @throws std::invalid_argument If the input matrix is not square
 * @throws std::runtime_error If the matrix is singular and cannot be inverted
 * 
 * @note The function uses a tolerance of 1e-10 to determine if the matrix is singular
 * @time_complexity O(n³) where n is the dimension of the square matrix
 * @space_complexity O(n²) for the result and working matrices
 */
template< typename K> 
Matrix<K> inverse(const Matrix<K>& A)
{
    if (A.getCols() != A.getRows())
        throw std::invalid_argument("Matrix must be square");

    size_t n = A.getRows();
    
    Matrix<K> mat(A);
    Matrix<K> result(A);
    for (size_t col = 0; col < n; ++col) {
        for (size_t row = 0; row < n; ++row) {
            result[col][row] = (col == row) ? 1 : 0;
        }
    }
    
    for (size_t i = 0; i < n; ++i) {
        size_t max_row = i;
        for (size_t row = i + 1; row < n; ++row) {
            if (std::abs(mat[i][row]) > std::abs(mat[i][max_row])) {
                max_row = row;
            }
        }
        
        if (max_row != i) {
            for (size_t col = 0; col < n; ++col) {
                std::swap(mat[col][i], mat[col][max_row]);
                std::swap(result[col][i], result[col][max_row]);
            }
        }
        
        if (std::abs(mat[i][i]) < 1e-10) {
            throw std::runtime_error("Matrix is singular and cannot be inverted");
        }
        
        K pivot = mat[i][i];
        for (size_t col = 0; col < n; ++col) {
            mat[col][i] /= pivot;
            result[col][i] /= pivot;
        }
        
        for (size_t row = 0; row < n; ++row) {
            if (row != i) {
                K factor = mat[i][row];
                for (size_t col = 0; col < n; ++col) {
                    mat[col][row] -= factor * mat[col][i];
                    result[col][row] -= factor * result[col][i];
                }
            }
        }
    }
    return result;
}