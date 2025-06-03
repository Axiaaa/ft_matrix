#include "matrix.hpp"
#include "vector.hpp"

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
Vector<K> LinearTransformation(const Vector<K>& u, const Matrix<K>& M)
{
    if (u.getSize() != M.getCols())
        throw std::invalid_argument("The vector size doesn't match the matrix column count.");

    Vector<K> result = Vector<K>();

    for (auto i = 0; i < M.getRows(); i++) {
        K sum = 0;
        for (auto j = 0; j < M.getCols(); j++) {
            sum += M[i][j] * u[j];
        }
        result.append(sum);
    }
    return result;
}


/**
* @brief Computes the composition (matrix multiplication) of two matrices.
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
Matrix<K> SolveComposition(Matrix<K> A, Matrix<K> B) {

    if (A.getCols() != B.getRows())
        throw std::invalid_argument("The matrix sizes don't match.");

    Matrix<K> result = Matrix<K>();

    for (auto i = 0; i < A.getRows(); i++) {
        for (auto j = 0; j < B.getCols(); j++) {
            K sum = 0;
            for (auto k = 0; k < A.getCols(); k++) {
                sum += A[i][k] * B[k][j];
            }
            result[i].push_back(sum);
        }
    }
    return result;
}

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

template <typename K>
Vector<K> lerp(const Vector<K> &v, const Vector<K> &u, const f32 &t)
{
    return (1 - t) * v + t * u;
}

template <typename K>
K lerp(const K &a, const K &b, const f32 &t)
{
    return (1 - t) * a + t * b;
}

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

template <typename K>
K angle_cos(const Vector<K>& v, const Vector<K>& u)
{
    return (dot(v, u) / (norm(v) * norm(u)));
}

template<typename K>
Vector<K> normalize(const Vector<K>& v)
{
    Vector<K> res = v * (1 / norm(v));
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
    for (size_t i = 0; i < v.getSize(); ++i)
        res += v[i];
    return res;
}

template<typename K>
K norm(const Vector<K>& v)
{
    K res = dot(v, v);
    return res > 0 ? sqrt(res) : 0;
}