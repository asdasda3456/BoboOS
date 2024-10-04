#include "../../intf/print.h"
#include "sys/wait.h"
#include "sys/stdint.h"
#include "sys/os.h"

void kernel_load_succes()
{
    print_str("Kernel is loaded...");
    wait();
    print_int(SUCCESS);
    wait();
    newline();
    wait();
    print_str(STATUS_OK_STR);
    newline();
    wait();
}

void kernel_main() 
{
    int testvalue = 3;
    clear();
    print_str(OS " " OSVER "\n");

    print_str("Test integer printing\n");
    print_int(testvalue);

    newline();
}

void kernel_early()
{
    clear();
    print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);

    kernel_load_succes();

    kernel_main();
}