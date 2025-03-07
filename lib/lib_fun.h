#ifndef LIB_FUN_H
#define LIB_FUN_H

#include <stdint.h>

// Function prototype: Converts a floating-point number to a fixed-point representation.
// Parameters:
//   x: The floating-point number to convert.
//   Wl: The total word length (number of bits) of the fixed-point representation.
//   Fl: The fractional length (number of bits) of the fixed-point representation.
//   y: An array of uint8_t to store the fixed-point representation (output).
void flp_to_fxp(float x, uint8_t Wl, uint8_t Fl, uint8_t y[]);

#endif // LIB_FUN_H