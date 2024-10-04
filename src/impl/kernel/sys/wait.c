#include "wait.h"
#include "stdint.h"

void wait() {
    for (i32 c = 0; c < 10000000; c++) {
        asm volatile("nop");
    }
}