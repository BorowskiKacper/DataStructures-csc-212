#include <iostream>
#include "newnode2.h"

// print linked list
template <class Item>
std::ostream &operator<<(std::ostream &outs, csc212_proj2::node<Item> *head_ptr)
{
    if (head_ptr == nullptr)
        return outs;

    csc212_proj2::node<Item> *cursor = head_ptr;
    outs << cursor->data();
    cursor = cursor->link();
    while (cursor != nullptr)
    {
        outs << " -> " << cursor->data();
        cursor = cursor->link();
    }
    return outs;
}

int main()
{
    csc212_proj2::node<double> *first = nullptr;
    double arr_first[6] = {0.5, 0.2, 0.1, 0.8, 1.0, 3.5};

    for (int i = 0; i < 6; i++)
    {
        csc212_proj2::list_tail_attach(first, arr_first[i]);
    }

    std::cout << "First Linked List: " << first << std::endl;

    csc212_proj2::list_head_remove(first);
    csc212_proj2::list_tail_remove(first);
    std::cout << "First Linked List after removal: " << first << std::endl;

    csc212_proj2::node<int> *second = nullptr;
    int arr_second[6] = {3, 2, 5, 2, 4, 2};

    for (int i = 0; i < 6; i++)
    {
        csc212_proj2::list_head_insert(second, arr_second[i]);
    }

    std::cout << "Second Linked List: " << second << std::endl;
    std::cout << "list_occurrences(second, 2): " << csc212_proj2::list_occurrences(second, 2) << std::endl;

    csc212_proj2::node<int> *third = csc212_proj2::list_copy_front(second, 4);
    std::cout << "Third Linked List: " << third << std::endl;

    size_t first_len = csc212_proj2::list_length(first);
    size_t third_len = csc212_proj2::list_length(third);
    if (first_len != third_len)
    {
        std::cout << "Error: lists have different lengths" << std::endl;
    }
    else
    {
        double sum_of_products = 0;
        csc212_proj2::node<double> *first_cursor = first;
        csc212_proj2::node<int> *third_cursor = third;
        for (size_t i = 0; i < first_len; i++)
        {
            sum_of_products += first_cursor->data() * third_cursor->data();
            first_cursor = first_cursor->link();
            third_cursor = third_cursor->link();
        }

        std::cout << "Sum of Products: " << "\n("
                  << first << ")\t*\t("
                  << third << ")\t=\t"
                  << sum_of_products << std::endl;
    }
}