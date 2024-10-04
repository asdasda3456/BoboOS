#include "../../intf/print.h"
#include <stdint.h>

const static size_t NUM_COLS = 80;
const static size_t NUM_ROWS = 25;

struct Char {
    uint8_t character;
    uint8_t color;
};

struct Char* buffer = (struct Char*) 0xb8000;
size_t col = 0;
size_t row = 0;
uint8_t color = PRINT_COLOR_WHITE | PRINT_COLOR_BLACK << 4; //default printing color

void clear_row(size_t row) {
    struct Char empty = { 
        .character = ' ', 
        .color = color 
    };

    for (size_t c = 0; c < NUM_COLS; c++) {
        buffer[c + NUM_COLS * row] = empty;
    }
}

void clear() {
    for (size_t r = 0; r < NUM_ROWS; r++) {
        clear_row(r);
    }
    col = 0; // reset column to 0
    row = 0; // reset row to 0
}

void newline() {
    col = 0;

    if (row < NUM_ROWS - 1) {
        row++;
        return;
    }

    for (size_t row = 1; row < NUM_ROWS; row++) {
        for (size_t col = 0; col < NUM_COLS; col++) {
            struct Char character = buffer[col + NUM_COLS * row];
            buffer[col + NUM_COLS * (row - 1)] = character;
        }
    }

    clear_row(NUM_COLS - 1);
}

void print_char(char character) {
    if (character == '\n') {
        newline();
        return;
    }

    if (col > NUM_COLS) {
        newline();
    }

    buffer[col + NUM_COLS * row] = (struct Char) {
        character: (uint8_t) character,
        color: color,
    };

    col++;
}

void print_str(char* str) {
    for (size_t i = 0; 1; i++) {
        char character = (uint8_t) str[i];

        if (character == '\0') {
            return;
        }

        print_char(character);
    }
}

void print_int(int integer) {
    if (integer < 0) {
        print_char('-'); 
        integer = -integer; 
    }

    char buffer[12]; 
    size_t index = 0;

    if (integer == 0) {
        print_char('0');
        return;
    }

    while (integer > 0) {
        buffer[index++] = (integer % 10) + '0'; 
        integer /= 10; 
    }

    for (size_t i = index; i > 0; i--) {
        print_char(buffer[i - 1]); 
    }
}

void print_float(float value) {
    if (value < 0) {
        print_char('-'); 
        value = -value; 
    }

    int integerPart = (int)value; 
    float decimalPart = value - integerPart; 

    char buffer[20];
    size_t index = 0;

    if (integerPart == 0) {
        print_char('0');
    } else {
        while (integerPart > 0) {
            buffer[index++] = (integerPart % 10) + '0'; 
            integerPart /= 10; 
        }
        for (size_t i = index; i > 0; i--) {
            print_char(buffer[i - 1]); 
        }
    }

    print_char('.');

    decimalPart *= 1000000; 
    int decimalInt = (int)decimalPart; 

    for (int i = 0; i < 3; i++) { 
        buffer[i] = (decimalInt % 10) + '0'; 
        decimalInt /= 10; 
    }

    for (int i = 5; i >= 0; i--) { 
        print_char(buffer[i]);
    }
}

void print_set_color(uint8_t foreground, uint8_t background) {
    color = foreground + (background << 4);
}