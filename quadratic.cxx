// Kacper Borowski kborows000@citymail.cuny.edu
// FILE quadratic.cxx
// CLASS IMPLEMENTED: quadratic (see quadratic.h for documentation)

#include "quadratic.h"
#include <vector>
#include <cmath>
#include <iostream>
// namespace myMath
// {
quadratic::quadratic(double init_a, double init_b, double init_c)
{
    a = init_a;
    b = init_b;
    c = init_c;
};

double quadratic::evaluate(double x)
{
    return a * x * x + b * x + c;
}

double quadratic::get_a() const
{
    return a;
}
double quadratic::get_b() const
{
    return b;
}
double quadratic::get_c() const
{
    return c;
}

void quadratic::set_a(double val)
{
    a = val;
}

void quadratic::set_b(double val)
{
    b = val;
}

void quadratic::set_c(double val)
{
    c = val;
}

int quadratic::num_real_roots() const
{
    if (a == 0 && b == 0 && c == 0)
    {
        return 3;
    }
    else if ((a == 0 && b == 0 && c != 0) || (a != 0 && b * b < 4 * a * c))
    {
        return 0;
    }
    else if ((a == 0 && b != 0) || (a != 0 && b * b == 4 * a * c))
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

double quadratic::first_root() const
{
    std::vector<double> roots = get_roots();
    return roots[0];
}

double quadratic::second_root() const
{
    std::vector<double> roots = get_roots();
    if (roots.size() > 1)
    {
        return roots[1];
    }

    return roots[0];
}

std::vector<double> quadratic::get_roots() const
{
    std::vector<double> answer;
    if (a == 0 && b == 0 && c == 0)
    {
        answer.push_back(0.0);
    }
    else if (a == 0 && b != 0)
    {
        answer.push_back(-c / b);
    }
    else
    {
        double b_square = b * b;
        double ac4 = 4 * a * c;

        if (b_square == ac4)
        {
            answer.push_back(-b / (2 * a));
        }
        else if (b_square > ac4)
        {
            double left = -b / (2 * a);
            double right = (std::sqrt(b_square - ac4)) / (2 * a);
            double root1 = left - right;
            double root2 = left + right;
            answer.push_back(root1 < root2 ? root1 : root2); // smaller root
            answer.push_back(root1 < root2 ? root2 : root1); // larger root
        }
    }

    std::cout << "In get_roots() \nLooping through each root:";
    for (int i = 0; i < answer.size(); i++)
    {
        std::cout << "Index: " << i << " | Value: " << answer[i] << '\n';
    }
    std::cout << "That's all folks!\n";
    return answer;
}

quadratic operator+(const quadratic &q1, const quadratic &q2)
{
    quadratic q(q1.get_a() + q2.get_a(), q1.get_b() + q2.get_b(), q1.get_c() + q2.get_c());
    return q;
}

quadratic operator*(double r, const quadratic &q)
{
    quadratic q_new(q.get_a() * r, q.get_b() * r, q.get_c() * r);
    return q_new;
}

// }