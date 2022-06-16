#include <stdio.h>
#include <stdlib.h>
#include "unit_test.h"
int main(int argc, char* argv[])
{
 Status (*tests[])(char*, int) =
 {
 test_init_default_returns_nonNULL,
 test_get_size_on_init_default_returns_0,
 test_kyle_savoie_get_capacity_on_init_default_returns_nonZero,
 test_kyle_savoie_my_string_push_back_increases_size,
 test_kyle_savoie_my_string_push_back_increases_capacity,
 test_kyle_savoie_my_string_pop_back_decreases_size,
 test_kyle_savoie_my_string_empty_returns_false,
 test_kyle_savoie_my_string_destroy_returns_NULL,
 test_kyle_savoie_my_string_compare_returns_zero,
 test_kyle_savoie_my_string_at_returns_value,
 test_kyle_savoie_my_string_insertion_writes,
 test_kyle_savoie_my_string_compare_left_string_larger,
 test_kyle_savoie_my_string_at_returns_NULL,
 test_kyle_savoie_my_string_compare_returns_greater_than_zero,
 test_kyle_savoie_my_string_concat_with_NULL_strings_returns_NULL
 };

 int number_of_functions = sizeof(tests) / sizeof(tests[0]);
 int i;
 char buffer[500];
 int success_count = 0;
 int failure_count = 0;

 for(i=0; i<number_of_functions; i++)
 {
 	if(tests[i](buffer, 500) == FAILURE)
	{
		 printf("FAILED: Test %d failed miserably\n", i);
		 printf("\t%s\n", buffer);
		 failure_count++;
	}
       	else
	 {
		 success_count++;
	 }
 }

 printf("Total number of tests: %d\n", number_of_functions);
 printf("%d/%d Pass, %d/%d Failure\n", success_count,
 number_of_functions, failure_count, number_of_functions);
 return 0;
}
