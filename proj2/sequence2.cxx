// Kacper Borowski kborows000@citymail.cuny.edu
// FILE sequence.h
// CLASS IMPLEMENTED: sequence (see sequence.h for documentation)

#include <cstdlib> // Provides size_t
#include "sequence2.h"
#include <algorithm> // Provides std::copy
#include <cassert>   // Provised assert

// REMOVE THESE MAYBE
#include <iostream>
using std::copy;
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

    sequence::sequence(const sequence &source)
    {
        data = new value_type[source.capacity];
        capacity = source.capacity;
        used = source.used;
        copy(source.data, source.data + source.used, data);
    }
    sequence::~sequence()
    {
        delete[] data;
    }
    // // MODIFICATION MEMBER FUNCTIONS
    // void resize(size_type new_capacity);
    void sequence::start()
    {
        current_index = 0;
    }
    void sequence::advance()
    {
        assert(is_item());

        current_index++;
    }
    void insert(const value_type &entry);
    void attach(const value_type &entry);
    void remove_current();
    void sequence::operator=(const sequence &source)
    {
        if (&source == this)
        {
            return;
        }

        if (capacity != source.capacity)
        {
            delete[] data;
            capacity = source.capacity;
            data = new value_type[source.capacity];
        }

        used = source.used;
        copy(source.data, source.data + source.used, data);
    }
    // CONSTANT MEMBER FUNCTIONS
    sequence::size_type sequence::size() const
    {
        return used;
    }
    bool sequence::is_item() const
    {
        return current_index < used;
    }
    sequence::value_type sequence::current() const
    {
        assert(is_item());

        return data[current_index];
    }

}
