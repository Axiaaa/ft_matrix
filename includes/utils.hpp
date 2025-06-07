#include "matrix.hpp"
#include "vector.hpp"
#include <cmath>

/**
 * @brief Computes the linear combination of vectors
 * 
 * This function calculates a linear combination of vectors where each vector is 
 * multiplied by its corresponding coefficient: result = c₁·v₁ + c₂·v₂ + ... + cₙ·vₙ
 * 
 * @tparam K The type of elements in the vectors and coefficients
 * @param u Vector of vectors to be combined
 * @param coefs Vector of coefficients to multiply each vector by
 * @return Vector<K> The resulting vector from the linear combination
 * @throws std::invalid_argument if the number of vectors doesn't match the number of coefficients
 * 
 * @note Both input vectors must have the same size
 */
template <typename K>
Vector<K> linear_combination(std::vector<Vector<K>> const &u, std::vector<K> coefs)
{
    if (u.size() != coefs.size())
        throw std::invalid_argument("The number of vectors and coefficients doesn't match !");
    Vector<K> result = Vector<K>(u[0] * coefs[0]);
    for (size_t i = 1; i < u.size(); i++)
        result += (u[i] * coefs[i]);
    return result;
}

/**
 * @brief Performs linear interpolation between two vectors
 * 
 * Calculates a point on the straight line between vectors v and u based on parameter t.
 * The formula used is: (1 - t) * v + t * u
 * 
 * @tparam K The type of elements in the vectors
 * @param v The starting vector (when t=0)
 * @param u The ending vector (when t=1)
 * @param t The interpolation factor between 0 and 1
 * @return Vector<K> The interpolated vector
 */
template <typename K>
Vector<K> lerp(const Vector<K> &v, const Vector<K> &u, const f32 &t)
{
    return (1 - t) * v + t * u;
}

/**
 * @brief Performs linear interpolation between two values.
 * 
 * Computes a value between 'a' and 'b' based on the interpolation factor 't'.
 * When t = 0, the result equals 'a'. When t = 1, the result equals 'b'.
 * For values of t between 0 and 1, the result is a proportional mix of 'a' and 'b'.
 * 
 * @tparam K The type of values to interpolate between
 * @param a The start value
 * @param b The end value
 * @param t The interpolation factor, typically in range [0,1]
 * @return K The interpolated value: (1-t)*a + t*b
 */
template <typename K>
K lerp(const K &a, const K &b, const f32 &t)
{
    return (1 - t) * a + t * b;
}

/**
 * @brief Performs linear interpolation between two matrices.
 * 
 * This function computes a linear interpolation between matrices M and N using parameter t,
 * according to the formula: result = (1-t)*M + t*N
 * 
 * @tparam K The data type of the matrix elements
 * @param M The first matrix (corresponds to t=0)
 * @param N The second matrix (corresponds to t=1)
 * @param t The interpolation parameter in range [0,1]
 * 
 * @return Matrix<K> The interpolated matrix
 * @throws std::invalid_argument If the dimensions of M and N do not match
 * 
 * @note When t=0, the result is M; when t=1, the result is N; for values in between,
 *       the result is a weighted average of M and N.
 */
template <typename K>
Matrix<K> lerp(const Matrix<K> &M, const Matrix<K> &N, const f32 &t)
{
    if (M.getRows() != N.getRows() || M.getCols() != N.getCols()) {
        throw std::invalid_argument("The matrices must have the same size.");
    }
    Matrix<K> result = scl(M, (1 - t));
    result.add(scl(N, t));
    return result;
}


/**
 * @brief Calculates the cosine of the angle between two vectors.
 * 
 * Uses the formula: cos(θ) = (v·u)/(|v|·|u|), where:
 * - v·u is the dot product of vectors v and u
 * - |v| and |u| are the norms of vectors v and u respectively
 * 
 * @tparam K Numeric type used for calculation
 * @param v The first vector
 * @param u The second vector
 * @return K The cosine of the angle between vectors v and u
 * @throw std::invalid_argument If either vector has zero norm
 */
template <typename K>
K angle_cos(const Vector<K>& v, const Vector<K>& u)
{
    K v_norm = norm(v);
    K u_norm = norm(u);
    if (u_norm == 0 || v_norm == 0)
        throw std::invalid_argument("Cannot computes cosinus for 0 vector");
    return (dot(v, u) / (norm(v) * norm(u)));
}

/**
 * @brief Normalizes a vector (converts it to a unit vector with the same direction)
 * 
 * Computes a new vector that has the same direction as the input vector but with a length of 1.
 * This is done by dividing each component of the input vector by its norm (magnitude).
 * 
 * @tparam K The numeric type of the vector components
 * @param v The vector to normalize
 * @return Vector<K> A new vector with the same direction as v but with unit length
 * @throws std::invalid_argument If the input vector has zero magnitude (can't be normalized)
 */
template<typename K>
Vector<K> normalize(const Vector<K>& v)
{
    K tmp = norm(v);
    if (tmp == 0)
        throw std::invalid_argument("Cannot normalise vector of 0");
    Vector<K> res = v * (1 / norm(v));
    return res;
}

/**
 * @brief Calculates the infinity norm (maximum norm) of a vector.
 * 
 * The infinity norm is defined as the maximum absolute value of the vector's components:
 * ||v||_∞ = max(|v₁|, |v₂|, ..., |vₙ|)
 * 
 * @tparam K The numeric type of the vector elements
 * @param v The vector whose infinity norm will be calculated
 * @return K The infinity norm value
 * @throws std::runtime_error If the input vector is empty
 */
template<typename K>
K norm_inf(const Vector<K>& v)
{
    if (v.getSize() == 0)
        throw std::runtime_error("Cannot find maximum of an empty vector");
    K max_val = std::fabs(v[0]);
    for (size_t i = 1; i < v.getSize(); ++i)
        if (std::fabs(v[i]) > max_val)
            max_val = std::fabs(v[i]);
    return max_val;
}

/**
 * @brief Calculate the L1 norm (Manhattan distance) of a vector.
 * 
 * The L1 norm is the sum of the absolute values of the vector's components:
 * ||v||₁ = |v₁| + |v₂| + ... + |vₙ|
 * 
 * @tparam K The numeric data type of the vector components
 * @param v The input vector whose L1 norm will be calculated
 * @return K The L1 norm of the vector as a value of type K
 */
template<typename K>
K norm_1(const Vector<K>& v)
{
    K res = std::fabs(v[0]);
    for (size_t i = 1; i < v.getSize(); ++i)
        res += std::fabs(v[i]);
    return res;
}

/**
 * @brief Calculates the Euclidean norm (magnitude) of a vector
 * 
 * This function computes the L2 norm of the vector, which is defined as the 
 * square root of the sum of the squared components of the vector.
 * Mathematically: ||v|| = √(v·v) = √(v₁² + v₂² + ... + vₙ²)
 * 
 * @tparam K The numeric type used for the vector components
 * @param v The vector whose norm is to be calculated
 * @return K The Euclidean norm of the vector, or 0 if the dot product is not positive
 */
template<typename K>
K norm(const Vector<K>& v)
{
    K res = dot(v, v);
    return res > 0 ? sqrt(res) : 0;
}

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
template<typename K>
Vector<K> cross_product(const Vector<K>& v, const Vector<K>& u)
{
    if (v.getSize() != 3 || u.getSize() != 3)
        throw std::invalid_argument("The vectors have to be 3 Dimensions");
    Vector<K> res({
        v[1] * u[2] - v[2] * u[1],
        v[2] * u[0] - v[0] * u[2],
        v[0] * u[1] - v[1] * u[0]
    });
    return res;
}

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
template<typename K>
K trace(const Matrix<K>& A)
{
    K sum = 0;
    for (size_t i = 0; i < A.getCols(); ++i) {
        for (size_t j = 0; j < A.getRows(); ++j)
            if (i == j)
                sum += A[i][j];
    }
    return sum;
}