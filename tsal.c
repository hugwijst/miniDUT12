/**
 * TSAL driver.
 *
 * The tsal is connected to pin A4?
 */
#include "tsal.h"

#include <stdbool.h>

#include <avr/io.h>

#include "timer.h"

#define PIN_NUM 4

bool _is_tsal_on = false;

void tsal_init(void) {
    DDRA |= (1 << PIN_NUM);
}

void tsal_on(void) {
    _is_tsal_on = true;
}

void tsal_off(void) {
    _is_tsal_on = false;
}

void tsal_run(void) {
    if(_is_tsal_on && (time_ms() / 200) % 2 == 0) {
        // enable TSAL LED
        PORTA |= (1 << PIN_NUM);
    } else {
        // disable TSAL LED
        PORTA &= ~(1 << PIN_NUM);
    }
}
