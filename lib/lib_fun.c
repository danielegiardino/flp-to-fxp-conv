#include "lib_fun.h"
#include <math.h>
#include <stdlib.h>

// Function definition: Converts a floating-point number to a fixed-point representation.
void flp_to_fxp(float x, uint8_t Wl, uint8_t Fl, uint8_t y[])
{
  float x_int = (x >= 0) ? floorf(x) : -floorf(fabs(x)); // Integer part: Get the integer part of x.
  float x_frac = fabs(x) - fabs(x_int);                   // Fractional part: Get the fractional part of x.

  float x_max = pow(2, Wl - 1) - 1 - pow(2, -Fl); // Max value: Calculate the maximum representable value.
  float x_min = -pow(2, Wl - 1) + pow(2, -Fl);    // Min value: Calculate the minimum representable value.

  // Saturation logic: Handle values outside the representable range.
  if (x >= x_max)
  {
    y[Wl - 1] = 0; // Set the sign bit to 0 (positive).
    for (size_t i = 1; i < Wl; i++)
      y[Wl - 1 - i] = 1; // Set all other bits to 1 (maximum positive value).
    return;
  }
  if (x <= x_min)
  {
    y[Wl - 1] = 1; // Set the sign bit to 1 (negative).
    for (size_t i = 1; i < Wl; i++)
      y[Wl - 1 - i] = 0; // Set all other bits to 0 (minimum negative value).
    return;
  }
  if (x==0) //if x is zero, set all bits to zero
  {
    for (size_t i = 0; i < Wl; i++)
      y[i] = 0;
    return;
  }

  // Binary conversion for the integer part.
  for (size_t i = Fl; i < Wl && fabs(x_int) > 0.50; i++)
  {
    float x_rem = fabs(fmod(floorf(x_int), 2)); // Get the remainder when divided by 2.
    if (x_rem == 1.0)
      y[i] = 1; // Set the bit to 1 if the remainder is 1.
    else
      y[i] = 0; // Set the bit to 0 if the remainder is 0.
    y[i] = (x < 0) ? (y[i] ^ 1) : y[i]; // Apply two's complement if negative.
    x_int /= 2; // Divide by 2 for the next bit.
  }

  // Binary conversion for the fractional part.
  x_frac *= 2; // Multiply by 2 to get the next bit.
  for (size_t i = 0; i < Fl && fabs(x_frac) > 0.50; i++)
  {
    float x_rem = fabs(fmod(floorf(x_frac), 2)); // Get the remainder when divided by 2.
    if (x_rem == 1.0)
      y[Fl-i] = 1; // Set the bit to 1 if the remainder is 1.
    else
      y[i] = 0; // Set the bit to 0 if the remainder is 0.
    x_frac *= 2; // Multiply by 2 for the next bit.
  }

  // Rounding: Round the fixed-point representation.
  if (fmod(floorf(x_frac), 2) == 1.0) //if the next bit after the last fractional bit is 1, round up
    for (size_t i = 0; i < Fl + 2; i++)
    {
      if (y[i] == 0)
      {
        y[i] = y[i] ^ 1; // Flip the bit to 1.
        break; // Stop after the first bit flip.
      }
      else
        y[i] = y[i] ^ 1; // Flip the bit to 0 and continue.
    }
}