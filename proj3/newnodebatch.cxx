// FILE: newlink.cxx
// An interactive test program for the four new functions of the
// expanded linked list toolkit.
#include <cctype>     // Provides toupper
#include <iostream>   // Provides cout and cin
#include <cstdlib>    // Provides EXIT_SUCCESS and size_t
#include "newnode2.h"   // With node::valuetype defined as double
using namespace std;
using namespace csc212_proj2;

typedef double value_type;

const size_t MANY_TESTS = 4;
const int POINTS[MANY_TESTS+1] = {
    60,  // Total points for all tests.
     15,  // Test 1 points
     15,  // Test 2 points
     15,  // Test 3 points
     15  // Test 4 points
};

const char DESCRIPTION[MANY_TESTS+1][256] = {
    "Testing four additional functions for the Linked List Toolbox",
	"Testing list_occurrences",
    "Testing list_tail_attach",
    "Testing list_tail_remove",
    "Testing list_copy_front",
};

int test1()
{
	size_t len=3;
	value_type entry=100;
	node<value_type>* test=NULL;
	for(size_t i=0;i<len;i++)
	{
		list_head_insert(test,(i+1)*0.1);
		list_tail_attach(test,entry);
	}
	if(list_occurrences(test,entry)==len)
		return POINTS[1];
	else
		return 0;
}

int test2()
{
	size_t len=10;
	node<value_type>* test=NULL;
	for(size_t i=0;i<len;i++)
		list_tail_attach(test,(i+1)*0.1);
	if(list_length(test)==len)
		return POINTS[2];
	else
		return 0;
}

int test3()
{
	size_t len=10;
	node<value_type>* test=NULL;
	for(size_t i=0;i<len;i++)
		list_tail_attach(test,(i+1)*0.1);
	for(size_t i=0;i<len;i++)
		list_tail_remove(test);
	if(list_length(test)==0)
		return POINTS[3];
	else
	{
		return 0;
	}
}

int test4()
{
	size_t len=10;
	node<value_type>* test=NULL;
	for(size_t i=0;i<len;i++)
		list_head_insert(test,(i+1)*0.1);
	for(size_t i=0;i<len;i++)
	{
		node<value_type> *p=list_copy_front(test,i+1);
		if (list_length(p) != (i + 1))
		{
			return 0;
		}

	}
	return POINTS[4];
}


int run_a_test(int number, const char message[], int test_function( ), int max)
{
    int result;

    cout << endl << "START OF TEST " << number << ":" << endl;
    cout << message << " (" << max << " points)." << endl;
    result = test_function( );
    if (result > 0)
    {
        cout << "Test " << number << " got " << result << " points";
        cout << " out of a possible " << max << "." << endl;
    }
    else
        cout << "Test " << number << " failed." << endl;
    cout << "END OF TEST " << number << "." << endl << endl;

    return result;
}

int main( )
{

   int sum = 0;


    cout << "Running " << DESCRIPTION[0] << endl;

    sum += run_a_test(1, DESCRIPTION[1], test1, POINTS[1]);
    sum += run_a_test(2, DESCRIPTION[2], test2, POINTS[2]);
    sum += run_a_test(3, DESCRIPTION[3], test3, POINTS[3]);
    sum += run_a_test(4, DESCRIPTION[4], test4, POINTS[4]);

	cout << "If you submit this sequence to Dora now, you will have\n";
    cout << sum << " poi	nts out of the " << POINTS[0];
    cout << " points from this test program.\n";

    return EXIT_SUCCESS;
}
