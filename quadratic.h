#include <vector>

#ifndef QUADRATIC_H
#define QUADRATIC_H
// ensure to write pre and post conditions
// 1.	Pay attention to the documentation aspect of the assignment (10%): provides pre/post conditions and use namespace and Macro Guard properly. Again, use newpoint.h and newpoint.cxx listed above as references.

// Any default arguments should be specified in the .h file, not the .cxx file.

class quadratic
{
public:
    quadratic(double init_a = 0.0, double init_b = 0.0, double init_c = 0.0);
    double evaluate(double x);
    double get_a() const;
    double get_b() const;
    double get_c() const;
    void set_a(double val);
    void set_b(double val);
    void set_c(double val);
    int num_real_roots() const;
    double first_root() const;
    double second_root() const;

private:
    std::vector<double> get_roots() const;
    double a, b, c;
};

quadratic operator+(const quadratic &q1, const quadratic &q2);
// Postcondition: The return value is the quadratic expression obtained by adding q1 and q2. For example, the c coefficient of the return value is the sum of q1's coefficient and q2's coefficient

quadratic operator*(double r, const quadratic &q);
// Postcondition: The return value is the quadratic expression obtained by multiplying each of q's coefficients by the number r

#endif // QUADRATIC_H