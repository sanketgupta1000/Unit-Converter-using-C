# Unit-Converter-using-C
            ***User Instruction Section***
1. Compilation and Execution.
->Use the following commands to compile and execute the program:
gcc main_function.c sub_functions.c
./a.out OR ./a.exe according to the type of your OS (UNIX or Windows).

2. Converting units.
->After the execution, the main menu will be displayed, with the list of Physical Quantities. Type appropriate choice (preferrably integer) to go into the sub menu containing list of units. Type -1 to exit whenever in the main menu.
->Type appropriate choices in sub menu (preferrable integer) to select the units from which you want to convert and to which you want to convert. Type -1 to exit ot 0 to go back to main menu whenever in the sub menu.
->Next, enter the value for conversion(preferrably floating point number), and press enter to get your answer.
->Now, some user-understandable questions will be asked and you can answer each one in Y(or y) for YES, and N(or n) for NO, and from here you can navigate either to main menu, or the sub menu, or continue with the same conversion.

3. Editing Database to modify list of Physical Quantities and/or Units.
->The database is stored in Physical_Quantities.db file, with its scheme till the first '/'(frontslash).
->To add/remove a physical quantity, you need to first update the number of physical quantities, and then do the desired change.
->Similarly, in order to add or remove a unit for a physical quantity, you need to first update the number of units for that physical quantity, and then do the desired change.
->For memory related reasons, maximum number of units for a given Physical Quantity is restricted to 15.

4. Accessing log file.
->For each session (one complete execution), a log file is created in logs/ folder present in the same directory as the executable file itself.
->The naming scheme of the log file is: "YEAR-MONTH-DAY_HOUR-MINUTE-SECOND.log", where the time is of the start of execution.
