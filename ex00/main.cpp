#include "../includes/vector.hpp"
#include "../includes/matrix.hpp"
#include <cassert>
#include <iostream>

void test_vector_operators() {
    std::cout << "=== Running Vector<f32> unit tests ===\n";

    Vector<f32> v1({1, 2, 3});
    Vector<f32> v2({1, 2, 3});

    std::cout << "Initial v1: ";
    v1.print();
    std::cout << "Initial v2: ";
    v2.print();

    // Test +
    Vector<f32> add_result = v1 + v2;
    std::cout << "v1 + v2 = ";
    add_result.print();
    assert(add_result == Vector<f32>({2, 4, 6}));

    // Test -
    Vector<f32> sub_result = v1 - v2;
    std::cout << "v1 - v2 = ";
    sub_result.print();
    assert(sub_result == Vector<f32>({0, 0, 0}));

    // Test *
    Vector<f32> scl_result = v1 * 2.f;
    std::cout << "v1 * 2 = ";
    scl_result.print();
    assert(scl_result == Vector<f32>({2, 4, 6}));

    // Test *=
    v1 *= 2.f;
    std::cout << "v1 after *= 2 = ";
    v1.print();
    assert(v1 == Vector<f32>({2, 4, 6}));

    // Test +=
    v1 += Vector<f32>({1, 1, 1});
    std::cout << "v1 after += {1,1,1} = ";
    v1.print();
    assert(v1 == Vector<f32>({3, 5, 7}));

    // Test -=
    v1 -= Vector<f32>({1, 1, 1});
    std::cout << "v1 after -= {1,1,1} = ";
    v1.print();
    assert(v1 == Vector<f32>({2, 4, 6}));

    // Test ==
    std::cout << "Comparing v1 == {2, 4, 6} : ";
    if (v1 == Vector<f32>({2, 4, 6})) {
        std::cout << "True\n";
    } else {
        std::cout << "False\n";
        assert(false);  // fail
    }

    // Test comparaison erreur (taille différente)
    try {
        Vector<f32> v_invalid({1, 2});
        std::cout << "Comparing v1 with invalid vector (size mismatch): ";
        bool result = (v1 == v_invalid); // devrait throw
        std::cout << "result = " << result << "\n";
        assert(false); // si pas throw, fail
    } catch (const std::invalid_argument& e) {
        std::cout << "Caught expected exception: " << e.what() << "\n";
    }

    std::cout << "[OK] All vector tests passed!\n\n";
}

void test_vector_methods() {
    std::cout << "=== Running Vector<f32> tests using methods ===\n";

    Vector<f32> v1({1, 2, 3});
    std::cout << "Initial v1: ";
    v1.print();

    // Test add()
    v1.add(Vector<f32>({1, 2, 3}));
    std::cout << "After v1.add({1, 2, 3}): ";
    v1.print();
    assert(v1 == Vector<f32>({2, 4, 6}));

    // Test sub()
    v1.sub(Vector<f32>({1, 1, 1}));
    std::cout << "After v1.sub({1, 1, 1}): ";
    v1.print();
    assert(v1 == Vector<f32>({1, 3, 5}));

    // Test scl()
    v1.scl(2.f);
    std::cout << "After v1.scl(2): ";
    v1.print();
    assert(v1 == Vector<f32>({2, 6, 10}));

    std::cout << "[OK] Vector<f32> method-based tests passed!\n\n";
}

void test_vector_functions() {
    std::cout << "=== Running Vector<f32> tests on free functions ===\n";

    Vector<f32> v1({1, 2, 3});
    Vector<f32> v2({1, 2, 3});

    std::cout << "v1: ";
    v1.print();
    std::cout << "v2: ";
    v2.print();

    // Test add(v1, v2)
    Vector<f32> add_result = add(v1, v2);
    std::cout << "add(v1, v2) = ";
    add_result.print();
    assert(add_result == Vector<f32>({2, 4, 6}));

    // Test sub(v1, v2)
    Vector<f32> sub_result = sub(v1, v2);
    std::cout << "sub(v1, v2) = ";
    sub_result.print();
    assert(sub_result == Vector<f32>({0, 0, 0}));

    // Test scl(v1, 2.f)
    Vector<f32> scl_result = scl(v1, 2.f);
    std::cout << "scl(v1, 2.f) = ";
    scl_result.print();
    assert(scl_result == Vector<f32>({2, 4, 6}));

    std::cout << "[OK] Vector free functions tests passed!\n\n";
}

void test_matrix_operators() {
    Matrix<f32> m1({
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    });
    Matrix<f32> m2({
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    });

    // Test add
    Matrix<f32> add_result = m1 + m2;
    Matrix<f32> expected_add({
        {2, 4, 6},
        {8, 10, 12},
        {14, 16, 18}
    });
    assert(add_result == expected_add);

    // Test sub
    Matrix<f32> sub_result = m1 - m2;
    Matrix<f32> expected_sub({
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    });
    assert(sub_result == expected_sub);

    // Test scl
    Matrix<f32> scl_result = m1 * 2.f;
    Matrix<f32> expected_scl({
        {2, 4, 6},
        {8, 10, 12},
        {14, 16, 18}
    });
    assert(scl_result == expected_scl);

    // Test *=
    m1 *= 2.f;
    assert(m1 == expected_scl);

    std::cout << "[OK] Matrix tests passed.\n";
}

void test_matrix_methods() {
    std::cout << "=== Running Matrix<f32> tests using methods ===\n";

    Matrix<f32> m1({
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    });
    std::cout << "Initial m1:\n";
    m1.print();

    // Test add()
    m1.add(Matrix<f32>({
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    }));
    std::cout << "After m1.add(1s):\n";
    m1.print();
    assert(m1 == Matrix<f32>({
        {2, 3, 4},
        {5, 6, 7},
        {8, 9, 10}
    }));

    // Test sub()
    m1.sub(Matrix<f32>({
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    }));
    std::cout << "After m1.sub(1s):\n";
    m1.print();
    assert(m1 == Matrix<f32>({
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    }));

    // Test scl()
    m1.scl(2.f);
    std::cout << "After m1.scl(2):\n";
    m1.print();
    assert(m1 == Matrix<f32>({
        {2, 4, 6},
        {8, 10, 12},
        {14, 16, 18}
    }));

    std::cout << "[OK] Matrix<f32> method-based tests passed!\n\n";
}

void matrix_test_functions() {
    std::cout << "=== Running Matrix<f32> tests on free functions ===\n";

    Matrix<f32> m1({
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    });

    Matrix<f32> m2({
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    });

    std::cout << "m1:\n";
    m1.print();
    std::cout << "m2:\n";
    m2.print();

    // Test add(m1, m2)
    Matrix<f32> add_result = add(m1, m2);
    std::cout << "add(m1, m2):\n";
    add_result.print();
    assert(add_result == Matrix<f32>({
        {2, 4, 6},
        {8, 10, 12},
        {14, 16, 18}
    }));

    // Test sub(m1, m2)
    Matrix<f32> sub_result = sub(m1, m2);
    std::cout << "sub(m1, m2):\n";
    sub_result.print();
    assert(sub_result == Matrix<f32>({
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    }));

    // Test scl(m1, 2.f)
    Matrix<f32> scl_result = scl(m1, 2.f);
    std::cout << "scl(m1, 2.f):\n";
    scl_result.print();
    assert(scl_result == Matrix<f32>({
        {2, 4, 6},
        {8, 10, 12},
        {14, 16, 18}
    }));

    std::cout << "[OK] Matrix free functions tests passed!\n\n";
}



int main() {
    test_vector_operators();
    test_vector_methods();
    test_vector_functions();

    test_matrix_operators();
    test_matrix_methods();
    matrix_test_functions();

    std::cout << "✅ All unit tests passed!\n";
    return 0;
}
