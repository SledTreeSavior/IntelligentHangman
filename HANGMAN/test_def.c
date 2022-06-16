#include <stdio.h>
#include <string.h>
#include "unit_test.h"

Status test_init_default_returns_nonNULL(char* buffer, int length)
{
	MY_STRING hString = NULL;

	hString = my_string_init_default();

	if(hString == NULL)
	{
		my_string_destroy(&hString);
		strncpy(buffer, "test_init_default_returns_nonNULL\n"
				"my_string_init_default returns NULL", length);
		return FAILURE;
	}
	else
	{
		my_string_destroy(&hString);
		strncpy(buffer, "\ttest_init_default_returns_nonNULL\n", length);
		return SUCCESS;
	}
}

Status test_get_size_on_init_default_returns_0(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;

	hString = my_string_init_default();

	if(my_string_get_size(hString) != 0)
	{
		status = FAILURE;
		printf("Expected a size of 0 but got %d\n", my_string_get_size(hString));
		strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
				"did not receive 0 from get_size after init_default\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_get_size_on_init_default_returns_0\n"
				, length);
	}

	my_string_destroy(&hString);
	return status;
}

Status test_kyle_savoie_get_capacity_on_init_default_returns_nonZero(char* buffer, int length)
{
	MY_STRING hString = NULL;
	Status status;

	hString = my_string_init_default();

	if (my_string_get_capacity(hString) == 0)
	{
		status = FAILURE;
		printf("Capacity must be greater than zero, but capacity equals %d\n", my_string_get_size(hString));
		strncpy(buffer, "test_kyle_savoie_get_capcity_on_init_default_returns_nonZero\n"
			"Received 0 from get_capacity after init_default\n", length);
	}
	else
	{
		status = SUCCESS;
		strncpy(buffer, "test_kyle_savoie_get_capacity_on_init_default_returns_nonZero\n", length);
	}
	my_string_destroy(&hString);
	return status;
}

Status test_kyle_savoie_my_string_push_back_increases_size(char* buffer, int length)
{
	
  MY_STRING hString = NULL ;
  Status status ;

  hString = my_string_init_c_string( "evil hangman" ) ;

  if (my_string_push_back(hString, '.'))
  {
    status = SUCCESS;
    strncpy( buffer, "test_kyle_savoie_my_string_push_back_increases_size\n", length ) ;
  } 
  else
  {
    status = FAILURE;
    strncpy( buffer, "test_kyle_savoie_push_back_increases_size\n"
              "my_string_push_back does not increase size\n", length );
  }
  my_string_destroy( &hString ) ;
  return status ;
}

Status test_kyle_savoie_my_string_push_back_increases_capacity(char* buffer, int length)
{
	MY_STRING hMy_string = NULL;
	Status status;
	int capacity;

	hMy_string = my_string_init_c_string("evil hangman");
	capacity = my_string_get_capacity(hMy_string);

	my_string_push_back(hMy_string, ' ');

	if (my_string_get_capacity(hMy_string) < capacity)
	{
		strncpy(buffer, "test_kyle_savoie_my_string_push_back_increases_capacity\n"
				"my_string_push_back doesn't return the correct capacity", length);
		return FAILURE;
	}
	else
	{
		status = SUCCESS;
		strncpy( buffer, "test_kyle_savoie_my_string_push_back_increases_capacity\n", length ) ;
	}
	my_string_destroy(&hMy_string);
	return status;
}

Status test_kyle_savoie_my_string_pop_back_decreases_size(char* buffer, int length)
{
	MY_STRING hMy_string = NULL;
	Status status;
	int size_before, size_after;

	hMy_string = my_string_init_c_string("evilhangma");
	size_before = my_string_get_size(hMy_string);
	
	my_string_pop_back(hMy_string);
	size_after = my_string_get_size(hMy_string);

	if (size_before <= size_after)
	{
		my_string_destroy(&hMy_string);
		strncpy(buffer, "test_kyle_savoie_my_string_pop_back_decreases_size\n"
			"my_string_push_back doesn't return the correct size", length);
		return FAILURE;
	}
	else
	{
		status = SUCCESS;
		strncpy( buffer, "test_kyle_savoie_my_string_pop_back_decreases_size\n", length ) ;
	}
	my_string_destroy(&hMy_string);
	return status;
}

Status test_kyle_savoie_my_string_empty_returns_false(char* buffer, int length)
{
	MY_STRING hMy_string = NULL;
	Status status;

	hMy_string = my_string_init_c_string("evil hangman");

 	if (my_string_empty(hMy_string) == TRUE)
 	{ 
 		my_string_destroy(&hMy_string);
 		strncpy(buffer, "test_kyle_savoie_my_string_empty_returns_false\n"
 		"my_string_empty returns empty when the string isn't empty", length);
 	return FAILURE;
 	}
 	else {
 		status = SUCCESS;
		strncpy( buffer, "test_kyle_savoie_my_string_empty_returns_false\n", length ) ;
 	}
 	my_string_destroy(&hMy_string);
 	return status;
}

Status test_kyle_savoie_my_string_destroy_returns_NULL(char* buffer, int length)
{
	MY_STRING hMy_string = NULL;
	Status status;

	hMy_string = my_string_init_c_string("evil hangman");

	my_string_destroy(&hMy_string);

 	if (hMy_string == NULL)
 	{
 		status = SUCCESS;
		strncpy( buffer, "test_kyle_savoie_my_string_destroy_returns_NULL\n", length ) ;

 	}
 	else {
 		status = FAILURE;
 		strncpy(buffer, "test_kyle_savoie_my_string_destroy_returns_NULL\n"
 		"my_string_destroy doesn't return NULL after the string is destroyed", length);
 	}
 	return status;
}

Status test_kyle_savoie_my_string_compare_returns_zero(char* buffer, int length)
{
	MY_STRING string1 = NULL;
	MY_STRING string2 = NULL;
	Status status;

	string1 = my_string_init_c_string("test");
	string2 = my_string_init_c_string("test");

	if (my_string_compare(string1, string2) == 0)
	{
		status = SUCCESS;
		strncpy( buffer, "test_kyle_savoie_my_string_compare_returns_zero\n", length ) ;
	}
	else
	{
		status = FAILURE;
		strncpy(buffer, "test_kyle_savoie_my_string_compare_returns_zero\n"
			"my_string_compare doesn't return zero when both strings are equal", length);
	}
	my_string_destroy(&string1);
	my_string_destroy(&string2);
	return status;
}

Status test_kyle_savoie_my_string_at_returns_value(char* buffer, int length)
{
	MY_STRING hMy_string = NULL;
	Status status;
	char *c;

	hMy_string = my_string_init_c_string("temp");
	c = my_string_at(hMy_string, 0);

	if (*c == 't')
	{
		status = SUCCESS;
		strncpy( buffer, "test_kyle_savoie_my_string_at_returns_value\n", length ) ;
	}
	else if (c == NULL)
	{
		status = FAILURE;
		strncpy(buffer, "test_kyle_savoie_my_string_at_returns_value\n"
			"my_string_at returns NULL when it shouldn't", length);
	}
	else
	{
		status = FAILURE;
		strncpy(buffer, "test_kyle_savoie_my_string_at_returns_value\n"
			"my_string_at returns the wrong char*", length);
	}
	my_string_destroy(&hMy_string);
	return status;
}

Status test_kyle_savoie_my_string_insertion_writes(char* buffer, int length)
{
	MY_STRING hMy_string = NULL;
	Status status;
	FILE *fp;

	hMy_string = my_string_init_c_string("evil hangman");
	fp = fopen("test.txt", "w");

	if (fp == NULL)
	{
		status = FAILURE;
		strncpy(buffer, "test_kyle_savoie_my_string_insertions_writes\n"
			"my_string_insertion couldn't open the file", length);
	}
	else if (my_string_insertion(hMy_string, fp))
	{
		status = SUCCESS;
		strncpy( buffer, "test_my_string_insertion_writes\n", length ) ;
	}
	else
	{
		status = FAILURE;
		strncpy(buffer, "test_kyle_savoie_my_string_insertion_writes"
			"my_string_insertion could not insert the c string", length);
	}
	my_string_destroy(&hMy_string);
	fclose(fp);
	return status;
}

Status test_kyle_savoie_my_string_compare_left_string_larger(char* buffer, int length)
{
	MY_STRING string1 = NULL;
	MY_STRING string2 = NULL;
	Status status;

	string1 = my_string_init_c_string("bigger");
	string2 = my_string_init_c_string("small");

	if (my_string_compare(string1, string2) >= 0)
	{
		status = FAILURE;
		strncpy(buffer, "test_kyle_savoie_my_string_compare_left_string_larger\n"
			"my_string_compare returned the wrong answer", length);
	}
	else
	{
		status = SUCCESS;
		strncpy( buffer, "test_kyle_savoie_my_string_compare_left_string_larger\n", length ) ;
	}
	my_string_destroy(&string1);
	my_string_destroy(&string2);
	return status;
}	

Status test_kyle_savoie_my_string_at_returns_NULL(char* buffer, int length)
{
	MY_STRING hMy_string = NULL;
	Status status;

	hMy_string = my_string_init_c_string("hi");

	if (my_string_at(hMy_string, 3) == NULL)
	{
		status = SUCCESS;
		strncpy( buffer, "test_kyle_savoie_my_string_at_returns_NULL\n", length ) ;
	}
	else
	{
		status = FAILURE;
		strncpy(buffer, "test_kyle_savoie_my_string_at_returns_NULL\n"
			"my_string_at doesn't return NULL when out of bounds", length);
	}
	my_string_destroy(&hMy_string);
	return status;
}

Status test_kyle_savoie_my_string_compare_returns_greater_than_zero(char* buffer, int length)
{
	MY_STRING hLeft_string = NULL;
  	MY_STRING hRight_string = NULL;
  	Status status;

  	hLeft_string = my_string_init_c_string( "evil" );
  	hRight_string = my_string_init_c_string( "hangman" );

  	if ( my_string_compare( hLeft_string, hRight_string ) < 0 )
       	{
    		status = SUCCESS ;
    		strncpy( buffer, "test_kyle_savoie_compare_returns_greater_than_zero\n", length ) ;
  	} 
	else
       	{
   		status = FAILURE ;
    		strncpy( buffer, "test_kyle_savoie_compare_returns_greater_than_zerro\n"
             		"my_string_compare returned a value less than or equal to zero\n", length ) ;
       	}
  my_string_destroy( &hLeft_string );
  my_string_destroy( &hRight_string );
  return status;
}

Status test_kyle_savoie_my_string_concat_with_NULL_strings_returns_NULL(char* buffer, int length)
{
	MY_STRING string1 = NULL;
	MY_STRING string2 = NULL;
	Status status;

	string1 = my_string_init_c_string("evil");
	string2 = my_string_init_c_string("hangman");

	if (my_string_concat(string1, string2) == FAILURE)
	{
		status = FAILURE;
		strncpy(buffer, "test_kyle_savoie_my_string_concat_with_NULL_strings_returns_NULL\n"
			"my_string_concat displays a non NULL string when it should be NULL", length);
	}
	else
	{
		status = SUCCESS;
		strncpy( buffer, "test_kyle_savoie_my_string_concat_with_NULL_strings_returns_NULL\n", length ) ;
	}
	my_string_destroy(&string1);
	my_string_destroy(&string2);
	return status;
}
