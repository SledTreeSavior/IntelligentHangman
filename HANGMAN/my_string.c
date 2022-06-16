#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "generic.h"
#include "my_string.h"

MY_STRING my_string_init_default() {

    My_string *pString = ( My_string * ) malloc( sizeof( My_string ) ) ;
    
    if ( pString != NULL ) {

        pString -> capacity = 7 ;
        pString -> size = 0 ;
        pString -> data = ( char * ) malloc( pString -> capacity ) ;

        if ( pString -> data == NULL ) {

            free( pString ) ;
            pString = NULL ;

        }

        return pString ;

    }

    return NULL ;
        
}

void my_string_destroy( Item *pItem ) {

    My_string *pString = ( My_string * ) *pItem ;
    free(pString->data) ;
    free( pString ) ;
    *pItem = NULL ;
    
}

MY_STRING my_string_init_c_string( const char *c_string ) {

    My_string *pString = ( My_string * ) malloc( sizeof( My_string ) ) ;
    int i, n = 0 ;
    
    if ( pString != NULL ) {

        for( i = 0; c_string[i] != '\0'; i++ ) n++ ;
        
        pString -> size = n ;
        pString -> capacity = ++n ; 
        pString -> data = ( char * ) malloc( n ) ;

        if ( pString -> data == NULL ) {

            free( pString ) ;
            pString = NULL ;

        } else {

            for ( i = 0; c_string[i] != '\0'; i++ ) pString -> data[i] = c_string[i] ;
            
        }

        return pString ;

    }

    return NULL ;

}

int my_string_get_capacity( MY_STRING hMy_string ) {

    return ( ( My_string * ) hMy_string ) -> capacity ;
    
}

int my_string_get_size( MY_STRING hMy_string ) {

    return ( ( My_string * ) hMy_string ) -> size ;

}

int my_string_compare( MY_STRING hLeft_string, MY_STRING hRight_string ) {

    My_string *pLeft_string = ( My_string * ) hLeft_string ;
    My_string *pRight_string = ( My_string * ) hRight_string ;
    int i ;

    for ( i = 0; i < pLeft_string -> size && i < pRight_string -> size; i++ ) {
        
        if ( pLeft_string -> data[i] < pRight_string -> data[i] ) {
            
            return -1 ;
            //break;
        } else if ( pLeft_string -> data[i] > pRight_string -> data[i] ) {
            
            return 1 ;
            // break
        }

    }

    return 0 ;
    
}

Status my_string_extraction( MY_STRING hMy_string, FILE *fp ) {

    My_string *pString = ( My_string * ) hMy_string ;
    char c ;

    pString -> size = 0 ;
    c = fgetc( fp ) ;

    while ( c == EOF || isspace( c ) ) {

        if ( c == EOF ) return FAILURE ;

        c = fgetc( fp ) ;

    }

    while ( c != EOF && !( isspace( c ) ) ) {

        my_string_push_back( hMy_string, c ) ;
        
        c = fgetc( fp ) ;


    }

    if ( c != EOF ) ungetc( c, fp ) ;

    return SUCCESS ;

}

Status my_string_insertion( MY_STRING hMy_string, FILE *fp ) {

    My_string *pString = hMy_string ;
    int i ;
 
    for ( i = 0; i < pString -> size; i++ ) fputc( pString -> data[i], fp ) ;
    
    return SUCCESS ;

}

Status my_string_push_back( MY_STRING hMy_string, char item ) {
    
    My_string *pString = ( My_string * ) hMy_string ;
    char *new_data ;
    
    if ( pString -> size >= pString -> capacity - 1 ) {

        new_data = ( char * ) realloc( pString -> data, pString -> capacity * 2 ) ;

        if ( new_data == NULL ) return FAILURE ;

        pString -> capacity *= 2 ;
        pString -> data = new_data ;

    }

    pString -> data[( pString -> size )++] = item ;
    my_string_c_str( hMy_string ) ;
    
    return SUCCESS ;
    
}

Status my_string_pop_back( MY_STRING hMy_string ) {
    
    My_string *pString = ( My_string * ) hMy_string ;
    
    if ( pString -> size <= 0 ) return FAILURE ;

    pString -> size-- ;

    return SUCCESS ;
    
}

char *my_string_at( MY_STRING hMy_string, int index) {
    
    My_string *pString = ( My_string * ) hMy_string ;
    
    if ( index >= 0 && index <= pString -> size ) return &( pString -> data[index] ) ; ;
    
    return NULL ;
    
}

char *my_string_c_str( MY_STRING hMy_string ) {
    
    My_string *pString = ( My_string * ) hMy_string ;
    
    pString -> data[pString -> size] = '\0' ;
    //my_string_push_back
    
    return pString -> data ;
    
}

Status my_string_concat( MY_STRING hResult, MY_STRING hAppend ) {
    
    My_string *phAppend = ( My_string * ) hAppend ;
    int i ;
    
    for ( i = 0; i < phAppend -> size; i++ )
        if ( !( my_string_push_back( hResult, phAppend -> data[i] ) ) ) return FAILURE ;

    return SUCCESS ;
    
}

Boolean my_string_empty( MY_STRING hMy_string ) {
    
    if ( ( ( My_string * ) hMy_string ) -> size == 0 ) return TRUE ;

    return FALSE ;
    
}

void my_string_assignment( Item *pLeft, Item Right ) {

    My_string *pMy_string_left = ( My_string *) *pLeft ;
    My_string *pMy_string_right = ( My_string *) Right ;
    int i ;
    const char *temp ;

    temp = my_string_c_str( ( MY_STRING ) Right ) ;
    
    if ( pMy_string_left == NULL ) {
    
        pMy_string_left = my_string_init_c_string( temp ) ;
    
    } else {

        pMy_string_left -> size = 0 ;
        
        for (i = 0; i < pMy_string_right->size + 1; i++) {
        
            my_string_push_back( pMy_string_left, pMy_string_right -> data[i] ) ;
        
        }

    }

    *pLeft = pMy_string_left ;
    
}

Status get_word_key_value( MY_STRING current_word_family, MY_STRING new_key, MY_STRING word, char guess ) {
    int i;
    while(!my_string_empty(new_key))
        my_string_pop_back(new_key);
    for(i = 0; i < my_string_get_size(word); i++)
        if(!my_string_push_back(new_key, *my_string_at(word, i) == guess ? guess : *my_string_at(current_word_family, i)))
            return FAILURE;
    return SUCCESS;   
}
