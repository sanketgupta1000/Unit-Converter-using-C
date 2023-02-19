
//******function for showing sub menu*******

#include "helpers.h"
extern int no_of_qty;
extern FILE * database;
int show_menu(quantity *qty)
{
    print_line();
    int physical_quantity, i;
    printf("Here is the list of Physical Quantities...\n");
    for (i = 0 ; i < (no_of_qty-1) ; i+=2)
    {
        printf("\t\t%-*s : %d\t\t\t\t%-*s : %d\n", NAME_LEN-20 , qty[i].qty_name, i + 1, NAME_LEN-20, qty[i+1].qty_name, i+2);
    }
    if(no_of_qty%2)
    {
        printf("\t\t%-*s : %d\n",NAME_LEN-20, qty[i].qty_name, i+1);
    }
    printf("Enter chioce number of Physical Quantity you want to convert : ");
    
    //for invalid number
    // int flag=1;
    do
    {
        scanf("%d",&physical_quantity);
    }
    while(((physical_quantity<1) || (physical_quantity>no_of_qty)) && printf("Invalid choice please enter valid choice : "));
    return physical_quantity;
}

int show_sub_menu(quantity *qty , int choice)
{
    int i,initial_choice;

    printf("\n\t\t\t\t\t****Welcome to %s CONVERSION****\n\n",qty[choice].qty_name);
    print_line();

    printf("\tBack : 0\n");    
    //******for print the sub menu containing list of units*******
    for(i=0;i<((qty[choice].no_of_units)-1);i+=2)
    {
        printf("\t\t%-*s : %d\t\t%-*s :  %d\n", NAME_LEN, (qty[choice].qty_units[i].unit_name), i+1, NAME_LEN, (qty[choice].qty_units[i+1].unit_name), i+2);
    }
    if((qty[choice].no_of_units) % 2 )
    {
        printf("\t\t%-*s : %d\n",NAME_LEN, (qty[choice].qty_units[i].unit_name), i+1);
    }
        
    printf("Enter the choice number from which you want to convert : ");

    //to scan initial choice and checking invalid number
    do 
    {
        scanf("%d",&initial_choice);
    }
    while(((initial_choice<0) || (initial_choice>(qty[choice].no_of_units))) && (printf("Invalid choice please enter valid choice : ")));


    //returning the initial choice
    return initial_choice;
}


//to print horizontal line
void print_line(void)
{
    // for center alignment
    // printf("\t");
    
    //for printing line 
    for(int i=0; i < 115 ; i++)
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
		fscanf(database, "%*[^|]| %[^|]| %d %*[^\n] ", qty[i].qty_name, &qty[i].no_of_units);
		
		for(j=0; j < qty[i].no_of_units ; j++)
		{
			//for scanning unit's name and multiple and constants related to that unit 
			fscanf(database, "%*[^|]| %[^|]| %lf | %lf%*[^\n]",qty[i].qty_units[j].unit_name, &qty[i].qty_units[j].unit_to_base_multiple, &qty[i].qty_units[j].unit_to_base_constant);
		}
	}
}

FILE * start_log(void)
{
    time_t current_time;
    struct tm *local_time;
    char time_string[50];

    // Get current time
    current_time = time(NULL);

    // Convert current time to local time
    local_time = localtime(&current_time);

    // Format the date and time string
    strftime(time_string, sizeof(time_string), "%Y-%m-%d_%H-%M-%S.log", local_time);

    char path[30] = "./logs/";

    strcat(path,time_string);
    FILE *p=fopen(path,"a");

    if(p== NULL)
    {
        printf("Error in creating log file...");
        exit(1);
    }
    return p;
}
