#include "../../intf/print.h"
#include "sys/wait.h"
#include "sys/stdint.h"
#include "sys/os.h"

void kernel_main() 
{
    int testvalue = 3;
    float floatvalue = 6.5;

    clear();
    print_str(OS " " OSVER "\n");

    print_str("Test integer printing\n");
    print_int(testvalue);

    print_str("Test floating point printing\n");
    print_float(floatvalue);

    newline();
}

void kernel_early()
{
    clear();
    print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);

    print_str("Kernel is loaded\n");
    print_char(SUCCESS);
    newline();
    print_str(STATUS_OK_STR);

    kernel_main();
}