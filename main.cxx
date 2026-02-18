#include <iostream>
#include "quadratic.h"
using namespace std;
// using namespace myMath;

int main()
{
    quadratic q1(1, 6, 8.75);
    cout << q1.get_a() << endl;
    cout << q1.get_b() << endl;
    cout << q1.get_c() << endl;

    cout << q1.num_real_roots() << endl;

    cout << q1.first_root() << endl;
    cout << q1.second_root() << endl;

    // q1.set_a(0.5);
    // q1.set_b(1.6);
    // q1.set_c(2.3);
    // cout << q1.get_a() << endl;
    // cout << q1.get_b() << endl;
    // cout << q1.get_c() << endl;

    // quadratic q2(1, 2.5, 5.4);
    // cout << q2.get_a() << endl;
    // cout << q2.get_b() << endl;
    // cout << q2.get_c() << endl;

    // quadratic q_add = q1+q2;
    // cout << q_add.get_a() << endl;
    // cout << q_add.get_b() << endl;
    // cout << q_add.get_c() << endl;

    // quadratic q_mult = 21*q1;
    // cout << q_mult.get_a() << endl;
    // cout << q_mult.get_b() << endl;
    // cout << q_mult.get_c() << endl;

    // cout << q_mult.evaluate(0) << endl;
    // cout << q_mult.evaluate(2) << endl;

    return 0;
}