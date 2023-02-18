#include "helpers.h"
int no_of_qty;
FILE *database;
void main(void)
{
    //Taking input of number of physical quantities from the database file

    //Skipping lines containing schemes from the database file and scanning
    database=fopen("Physical_Quantities.db", "r");
    fscanf(database, "%*[^/]%*[^:]:%d", &no_of_qty);
    quantity qty[no_of_qty];

    load_data(qty);

    //declaring variables for input and calculation
    int physical_quantity, initial_choice, final_choice;
    double initial_value, final_value;
    char continue_flag;
    
    do
    {
        do
        {
            physical_quantity = show_menu(qty);
            initial_choice = show_sub_menu(qty, physical_quantity-1);
        } while (!initial_choice);

        printf("Enter the choice number to which you want to convert : ");
        scanf("%d", &final_choice);
        printf("\nEnter the value : ");
        scanf("%lf\n", &initial_value);


        double base_converter_multiple = qty[physical_quantity - 1].qty_units[initial_choice - 1].unit_to_base_multiple;
        double base_converter_constant = qty[physical_quantity - 1].qty_units[initial_choice - 1].unit_to_base_constant;

        double final_converter_multiple = qty[physical_quantity - 1].qty_units[final_choice - 1].unit_to_base_multiple;
        double final_converter_constant = qty[physical_quantity - 1].qty_units[final_choice - 1].unit_to_base_constant;

        double base_value = ((initial_value) * (base_converter_multiple)) + (base_converter_constant) ;
        double final_value = ((base_value) - (final_converter_constant)) / (final_converter_multiple) ;

        char initial_unit_name[NAME_LEN], final_unit_name[NAME_LEN];

        strcpy(initial_unit_name, qty[physical_quantity - 1].qty_units[initial_choice - 1].unit_name);
        strcpy(final_unit_name, qty[physical_quantity - 1].qty_units[final_choice - 1].unit_name);

        printf("%lf %s = %lf %s\n", initial_value, initial_unit_name, final_value, final_unit_name);

        printf("Do you wish to convert another physical quantity?\nEnter 'Y' to continue, otherwise enter 'N' : ");
        scanf("%c", &continue_flag);

    } while ((continue_flag == 'Y') || (continue_flag == 'y'));
}
