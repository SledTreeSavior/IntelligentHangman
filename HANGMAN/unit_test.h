#ifndef UNIT_TEST_H
#define UNIT_TEST_H
#include "my_string.h"

Status test_init_default_returns_nonNULL(char* buffer, int length); //test 1
Status test_get_size_on_init_default_returns_0(char* buffer, int length); //test 2
Status test_kyle_savoie_get_capacity_on_init_default_returns_nonZero(char* buffer, int length);//test 3
Status test_kyle_savoie_my_string_push_back_increases_size(char* buffer, int length); //test 4
Status test_kyle_savoie_my_string_push_back_increases_capacity(char* buffer, int length); //test 5
Status test_kyle_savoie_my_string_pop_back_decreases_size(char* buffer, int length); //test 6
Status test_kyle_savoie_my_string_empty_returns_false(char* buffer, int length); //test 7
Status test_kyle_savoie_my_string_destroy_returns_NULL(char* buffer, int length); //test 8
Status test_kyle_savoie_my_string_compare_returns_zero(char* buffer, int length); //test 9
Status test_kyle_savoie_my_string_at_returns_value(char* buffer, int length); //test 10
Status test_kyle_savoie_my_string_insertion_writes(char* buffer, int length); //test 11
Status test_kyle_savoie_my_string_compare_left_string_larger(char* buffer, int length); //test 12
Status test_kyle_savoie_my_string_at_returns_NULL(char* buffer, int length); //test 13
Status test_kyle_savoie_my_string_compare_returns_greater_than_zero(char* buffer, int length); //test 14
Status test_kyle_savoie_my_string_concat_with_NULL_strings_returns_NULL(char* buffer, int length); //test 15


#endif
