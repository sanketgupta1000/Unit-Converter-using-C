
//******function for showing sub menu*******

#include "helpers.h"
extern int no_of_qty;
extern FILE * database;
int show_menu(quantity *qty)
{
    int physical_quantity, i;
    printf("Here is a list of Physical Quantities :\n");
    for (i = 0; i < no_of_qty; i++)
    {
        printf("\t%s : %d", qty[i].qty_name, i + 1);
        if (i % 2)
        {
            printf("\n");
        }
    }
    printf("\n");
    scanf("%d", &physical_quantity);
    return physical_quantity;
}

int show_sub_menu(quantity *qty , int choice)
{
    int i,initial_choice;

    printf("\tBack : 0\n");    
    //******for print the sub menu containing list of units*******
    for(i=0;i<(((qty+choice)->no_of_units)-1);i+=2)
    {
        printf("\t\t%s : %d\t%s :  %d\n", (qty[choice].qty_units[i].unit_name), i+1, (qty[choice].qty_units[i+1].unit_name), i+2);
    }
    if(((qty+choice)->no_of_units) % 2 )
    {
        printf("\t\t%s : %d\n",(qty[choice].qty_units[i].unit_name), i+1);
    }
        
    printf("Enter the choice number from which you want to convert : ");

    //to scan initial choice
    scanf("%d\n",&initial_choice);
    
    //returning the initial choice
    return initial_choice;
}


//to print horizontal line
void print_line(void)
{
    //for center alignment
    printf("\t");
    
    //for printing line 
    for(int i=0; i < 80 ; i++)
    {
        printf("-");
    }
    printf("\n");
}


void load_data(quantity *qty)
{
	int i=0,j=0;
	for(i=0; i < no_of_qty ; i++)
	{
		//for scanning physical quantity's name and number of units of that quantity
		fscanf(database, "%*[^|]| %[^|]%d", qty[i].qty_name, &qty[i].no_of_units);
		
		for(j=0; j < qty[i].no_of_units ; j++)
		{
			//for scanning unit's name and multiple and constants related to that unit 
			fscanf(database, "%*[^|]| %[^|]%lf%lf",qty[i].qty_units[j].unit_name, &qty[i].qty_units[j].unit_to_base_multiple, &qty[i].qty_units[j].unit_to_base_constant);
		}
	}
}
