#include "helpers.h"
int no_of_qty;
FILE *database;
void main(void)
{
    database = fopen("Physical_Quantities.db", "r");

    FILE *log = start_log();
    int log_count = 1;

    // Taking input of number of physical quantities from the database file
    // Skipping lines containing schemes from the database file and scanning
    fscanf(database, "%*[^/]%*[^:]:%d", &no_of_qty);
    quantity qty[no_of_qty];

    // to load all data from database to array of structure
    load_data(qty);

    fclose(database);

    // declaring variables for input and calculation
    int physical_quantity, initial_choice, final_choice;
    double initial_value, final_value;
    char continue_flag = 'Y';

    print_line();
    printf("\n\t\t\t\t\t*****Welcome to UNIT CONVERTER*****\n\n");

    do
    {

        physical_quantity = show_menu(qty);

        char sub_menu_flag = 'Y';
        do
        {

            do
            {

                print_line();
                initial_choice = show_sub_menu(qty, physical_quantity - 1);
                if (!(initial_choice))
                {
                    continue;
                }

                printf("Enter the choice number to which you want to convert : ");
                do
                {
                    scanf("%d", &final_choice);
                    if(final_choice==-1)
                    {
                        exit_greeting();
                        exit(0);
                    }
                } 
                while (((final_choice < 0) || (final_choice > (qty[physical_quantity - 1].no_of_units)) && (printf("Invalid choice please enter valid choice : "))));
                
                if ((final_choice))
                {
                    print_line();
                }

            } while (((!(initial_choice)) || (!(final_choice))) && (physical_quantity = show_menu(qty)));

            char same = 'Y';
            do
            {
                printf("Enter the value : ");
                scanf("%lf", &initial_value);

                double base_converter_multiple = qty[physical_quantity - 1].qty_units[initial_choice - 1].unit_to_base_multiple;
                double base_converter_constant = qty[physical_quantity - 1].qty_units[initial_choice - 1].unit_to_base_constant;

                double final_converter_multiple = qty[physical_quantity - 1].qty_units[final_choice - 1].unit_to_base_multiple;
                double final_converter_constant = qty[physical_quantity - 1].qty_units[final_choice - 1].unit_to_base_constant;

                double base_value = ((initial_value) * (base_converter_multiple)) + (base_converter_constant);
                double final_value = ((base_value) - (final_converter_constant)) / (final_converter_multiple);

                char initial_unit_name[NAME_LEN], final_unit_name[NAME_LEN];

                strcpy(initial_unit_name, qty[physical_quantity - 1].qty_units[initial_choice - 1].unit_name);
                strcpy(final_unit_name, qty[physical_quantity - 1].qty_units[final_choice - 1].unit_name);

                printf("Here is your conversion...\n");
                printf("%lf %s = %lf %s\n", initial_value, initial_unit_name, final_value, final_unit_name);

                fprintf(log, "\t%3d.)  %lf %s = %lf %s\n", log_count++, initial_value, initial_unit_name, final_value, final_unit_name);

                printf("Enter 'Y' to again convert %s to %s, otherwise enter 'N' : ", initial_unit_name, final_unit_name);
                scanf("\n%c", &same);
                print_line();
            } while ((same == 'Y') || (same == 'y'));

            printf("Enter 'Y' to again convert in %s Physical Quantity, otherwise enter 'N' : ", qty[physical_quantity - 1].qty_name);
            scanf("\n%c", &sub_menu_flag);
            if (sub_menu_flag != 'Y' && sub_menu_flag != 'y')
            {
                print_line();
            }
        } while ((sub_menu_flag == 'Y') || (sub_menu_flag == 'y'));
        printf("Do you wish to continue on UNIT CONVERTER ?\nEnter 'Y' to continue, otherwise enter 'N' : ");
        scanf("\n%c", &continue_flag);

    } while ((continue_flag == 'Y') || (continue_flag == 'y'));

    exit_greeting();

    fclose(log);
}
