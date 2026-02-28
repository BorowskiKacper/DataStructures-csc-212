#include <vector>
#include <iostream>

#ifndef QUADRATIC_H
#define QUADRATIC_H

namespace my_math
{
    // Forward declarations to enable use of I/O friend functions
    class quadratic;

    std::ostream &operator<<(std::ostream &outs, const quadratic &q);
    // Precondition: None
    // Postcondition: Prints the quadratic expression to the output stream.

    std::istream &operator>>(std::istream &ins, quadratic &q);
    // Precondition: None
    // Postcondition: Reads three double values from input and sets them as coefficients (a, b, and c) of q.

    class quadratic
    {
    public:
        quadratic(double init_a = 0.0, double init_b = 0.0, double init_c = 0.0);
        // Postcondition: A quadratic object is created with coefficients a, b, and c initialized to init_a, init_b, and init_c respectively.

        double evaluate(double x) const;
        // Postcondition: The quadratic expression is evaluated at x. Returns ax^2 + bx + c.

        double get_a() const;
        double get_b() const;
        double get_c() const;
        // Postcondition (for get_x functions): Returns the value of the respective coefficient x (i.e. a, b, or c).

        void set_a(double val);
        void set_b(double val);
        void set_c(double val);
        // Postcondition (for set_x functions): Updates the value of the respective coefficient (i.e. a, b, or c) to val.

        int getNumRoots() const;
        // Postcondition: Returns the number of real roots in the quadratic expression. Returns 0, 1, 2, or 3 (where 3 signifies an infinite number of real roots).

        double getRoot1() const;
        // Precondition: The quadratic expression has at least one real root.
        // Postcondition: If there are two real roots, then this function returns the smaller of the two roots. If every value of x is a real root, then this function returns 0.0.

        double getRoot2() const;
        // Precondition: The quadratic expression has at least one real root.
        // Postcondition: If there are two real roots, then this function returns the larger of the two roots. If every value of x is a real root, then this function returns 0.0.

        // Friend functions for I/O
        friend std::ostream &operator<<(std::ostream &outs, const quadratic &q);
        friend std::istream &operator>>(std::istream &ins, quadratic &q);

    private:
        std::vector<double> getRoots() const;
        // Postcondition: Returns a sorted vector containing the real roots of the quadratic equation. If there are no real roots, the vector is empty.

        double a, b, c;
    };

    quadratic operator+(const quadratic &q1, const quadratic &q2);
    // Postcondition: The return value is the quadratic expression obtained by adding q1 and q2. (e.g. the c coefficient of the return value is the sum of q1's c coefficient and q2's c coefficient)

    quadratic operator*(double r, const quadratic &q);
    // Postcondition: The return value is the quadratic expression obtained by multiplying each of q's coefficients by the number r.

    bool operator==(const quadratic &q1, const quadratic &q2);
    // Postcondition: Returns true if both quadratic objects contain identical coefficients.

    bool operator!=(const quadratic &q1, const quadratic &q2);
    // Postcondition: Returns false if both quadratic objects contain identical coefficients.

}

#endif // QUADRATIC_H