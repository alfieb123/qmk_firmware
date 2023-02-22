#pragma once

#include "config_common.h"

#define MATRIX_ROWS 12
#define MATRIX_COLUMNS 5

// Wiring pins
#define MATRIX_ROW_PINS { D4, C6, D7, E6, B4, B5 }
#define MATRIX_COL_PINS { F6, F7, B1, B3, B2 }

#define DIODE_DIRECTION COL2ROW
// #define DIODE_DIRECTION ROW2COL

#define EE_HANDS
#define SPLIT_USB_DETECT
