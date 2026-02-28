#include <iostream>
#include "quadratic.h"
using namespace std;
using namespace my_math;

int main()
{
    cout << "======ROOT CASES======" << endl;

    // Case 1: a, b, and c are all zero. Every value of x is a real root.
    // Expected output for getNumRoots is 3.
    quadratic q_case1(0, 0, 0);
    cout << "Case 1 (Infinite roots): " << q_case1 << endl;
    cout << "q_case1.getNumRoots(): " << q_case1.getNumRoots() << endl;
    cout << "q_case1.getRoot1(): " << q_case1.getRoot1() << endl;

    // Case 3: a is zero, and b is nonzero. One real root (x = -c/b).
    quadratic q_case3(0, 2, -4);
    cout << "Case 3 (1 root): " << q_case3 << endl;
    cout << "q_case3.getNumRoots(): " << q_case3.getNumRoots() << endl;
    cout << "q_case3.getRoot1(): " << q_case3.getRoot1() << endl;

    // Case 6: a is nonzero, and b^2 > 4ac. Two real roots.
    // Expected to return the smaller root for getRoot1() and larger for getRoot2().
    quadratic q_case6(1, 0, -4);
    cout << "Case 6 (2 roots): " << q_case6 << endl;
    cout << "q_case6.getNumRoots(): " << q_case6.getNumRoots() << endl;
    cout << "q_case6.getRoot1(): " << q_case6.getRoot1() << endl;
    cout << "q_case6.getRoot2(): " << q_case6.getRoot2() << endl
         << endl;

    cout << "======FUNCTION CALLING======" << endl;

    cout << "Enter 3 numbers (a, b, c) as coefficients of q1: ";
    quadratic q1;
    cin >> q1;

    cout << "q1.get_a(): " << q1.get_a() << endl;
    cout << "q1.get_b(): " << q1.get_b() << endl;
    cout << "q1.get_c(): " << q1.get_c() << endl;

    cout << "q1.getNumRoots(): " << q1.getNumRoots() << endl;

    cout << "q1.getRoot1(): " << q1.getRoot1() << endl;
    cout << "q1.getRoot2(): " << q1.getRoot2() << endl;
    cout << "q1.evaluate(2): " << q1.evaluate(2) << endl;
    cout << "q1: " << q1 << endl;

    quadratic q2(0, 0, 0);
    cout << "quadratic q2(0, 0, 0); " << endl;
    q2.set_a(0.5);
    cout << "q2.set_a(0.5);" << endl;
    q2.set_b(1.6);
    cout << "q2.set_b(1.6);" << endl;
    q2.set_c(2.3);
    cout << "q2.set_c(2.3);" << endl;
    cout << "q2.get_a(): " << q2.get_a() << endl;
    cout << "q2.get_b(): " << q2.get_b() << endl;
    cout << "q2.get_c(): " << q2.get_c() << endl
         << endl;

    cout << "======OPERATOR OVERLOADING======" << endl;
    cout << "q1 == q2: " << (q1 == q2) << '\n';
    cout << "q1 != q2: " << (q1 != q2) << '\n';

    cout << "q1 + q2: " << q1 + q2 << endl;
    cout << "21*q2: " << 21 * q2 << endl;

    return 0;
}