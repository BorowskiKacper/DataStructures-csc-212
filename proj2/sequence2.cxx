// Kacper Borowski kborows000@citymail.cuny.edu
// FILE sequence.h
// CLASS IMPLEMENTED: sequence (see sequence.h for documentation)

#include <cstdlib> // Provides size_t
#include "sequence2.h"
#include <algorithm> // Provides std::copy
#include <cassert>   // Provides assert

using std::copy;

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
        current_index = source.current_index;
    }

    sequence::~sequence()
    {
        delete[] data;
    }

    // MODIFICATION MEMBER FUNCTIONS
    void sequence::resize(size_type new_capacity)
    {
        if (new_capacity == capacity)
        {
            return;
        }

        capacity = new_capacity > used ? new_capacity : used;

        sequence::value_type *new_data = new sequence::value_type[capacity];
        copy(data, data + used, new_data);
        delete[] data;
        data = new_data;
    }

    void sequence::start()
    {
        current_index = 0;
    }

    void sequence::advance()
    {
        assert(is_item());

        current_index++;
    }

    void sequence::insert(const value_type &entry)
    {
        // Double capacity or set it to 8 if it runs out.
        if (used >= capacity)
        {
            if (capacity <= 0)
            {
                resize(8);
            }
            else
            {
                resize(capacity * 2);
            }
        }

        if (!is_item())
        {
            current_index = 0;
        }
        for (size_type i = used; i > current_index; i--)
        {
            data[i] = data[i - 1];
        }
        data[current_index] = entry;
        used++;
    }

    void sequence::attach(const sequence::value_type &entry)
    {
        // Double capacity or set it to 8 if it runs out.
        if (used >= capacity)
        {
            if (capacity <= 0)
            {
                resize(8);
            }
            else
            {
                resize(capacity * 2);
            }
        }

        if (is_item())
        {
            for (size_type i = used; i > current_index; i--)
            {
                data[i] = data[i - 1];
            }
            data[++current_index] = entry;
        }
        else
        {
            data[used] = entry;
        }
        used++;
    }

    void sequence::remove_current()
    {
        assert(is_item());

        for (size_type i = current_index + 1; i < used; i++)
        {
            data[i - 1] = data[i];
        }
        used--;
    }

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
        current_index = source.current_index;
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
