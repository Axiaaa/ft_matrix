#include "matrix.hpp"
#include "vector.hpp"
#include <cstddef>
#include <stdexcept>
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
    K tmp = norm(v);
    if (tmp == 0)
        throw std::invalid_argument("Cannot normalise vector of 0");
    Vector<K> res = v * (1 / norm(v));
    return res;
}

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

template<typename K>
K norm_1(const Vector<K>& v)
{
    K res = std::fabs(v[0]);
    for (size_t i = 1; i < v.getSize(); ++i)
        res += std::fabs(v[i]);
    return res;
}

template<typename K>
K norm(const Vector<K>& v)
{
    K res = dot(v, v);
    return res > 0 ? sqrt(res) : 0;
}
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