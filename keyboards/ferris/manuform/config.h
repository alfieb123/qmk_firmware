#pragma once

#include "config_common.h"

/* key matrix size */
#define MATRIX_ROWS 8
#define MATRIX_COLS 5

// Wiring pins
#define MATRIX_ROW_PINS { D4, C6, D7, E6 }
#define MATRIX_COL_PINS { F6, F7, B1, B3, B2 }

#define SOFT_SERIAL_PIN D2
#define DIODE_DIRECTION ROW2COL
#define EE_HANDS
#define SPLIT_USB_DETECT
