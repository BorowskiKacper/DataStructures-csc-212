// Kacper Borowski kborows000@citymail.cuny.edu
// FILE sequence.h
// CLASS IMPLEMENTED: sequence (see sequence.h for documentation)

#include <cstdlib> // Provides size_t
#include "sequence2.h"

// REMOVE THESE MAYBE
#include <iostream>
using std::cout;

namespace main_savitch_4
{
    // CONSTRUCTORS and DESTRUCTOR
    sequence::sequence(size_type initial_capacity)
    {
        capacity = initial_capacity;
        data = new value_type[capacity];
        used = 0;
        current_index = 0;
    }
    // sequence(const sequence &source);
    // ~sequence();
    // // MODIFICATION MEMBER FUNCTIONS
    // void resize(size_type new_capacity);
    // void start();
    // void advance();
    // void insert(const value_type &entry);
    // void attach(const value_type &entry);
    // void remove_current();
    // void operator=(const sequence &source);
    // // CONSTANT MEMBER FUNCTIONS
    // size_type size() const;
    // bool is_item() const;
    // value_type current() const;

}
