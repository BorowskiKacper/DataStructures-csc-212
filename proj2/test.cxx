#include "sequence2.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using namespace main_savitch_4;

int main()
{
    sequence t(1);
    // cout << t.current() << '\n';
    t.insert(2);
    cout << t.current() << '\n';
    t.insert(4);
    cout << t.current() << '\n';
    for (int i = 2; i < 6; i++)
    {
        t.insert(i);
        t.advance();
    }

    t.start();
    cout << "Print sequence" << '\n';
    while (t.is_item())
    {
        cout << t.current() << ", ";
        t.advance();
    }
    cout << '\n';

    t.start();
    cout << "attach(8) at beginning" << '\n';
    t.attach(8);
    t.start();

    cout << "Print sequence" << '\n';
    while (t.is_item())
    {
        cout << t.current() << ", ";
        t.advance();
    }
    cout << '\n';
}