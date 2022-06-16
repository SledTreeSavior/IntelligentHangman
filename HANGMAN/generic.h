#ifndef GENERIC_H
#define GENERIC_H

typedef void* Item;

typedef struct generic_vector {
	
	void(*assignment) (Item *pLeft, Item Right);
	void(*destroy) (Item *pItem);
	int size;
	int capacity;
	Item *data;
} Generic_vector;

typedef enum status { FAILURE, SUCCESS } Status ;
typedef enum boolean { FALSE, TRUE } Boolean ;

#endif
