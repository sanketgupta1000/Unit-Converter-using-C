/*Purpose: This file contains the preprocessor statements 
as well as the structure definitions and declarations for the Unit Converter*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_UNITS 15
#define NAME_LEN 30

//structure for unit properties

typedef struct unit_properties
{
    char unit_name[NAME_LEN];
    double unit_to_base_multiple;
    double unit_to_base_constant;
}unit;

//structure for physical quantity

typedef struct physical_quantity_properties
{
    char qty_name[NAME_LEN];
    int no_of_units;
    unit qty_units[MAX_UNITS];
}quantity;


int show_menu(quantity *);
int show_sub_menu(quantity *, int);
void print_line(void);
void load_data(quantity *);
FILE *start_log(void);
