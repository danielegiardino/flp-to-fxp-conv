// main.c
#include <stdio.h>    // Standard input/output library.
#include <stdint.h>   // Standard integer types library.
#include <stdlib.h>   // Standard library functions (e.g., atoi, atof).
#include <math.h>     // Math library (e.g., pow, roundf).
#include "lib/lib_fun.h" // Include the fixed-point conversion library.
#include "lib_config.h"    // Include the configuration parsing library.

int main(int argc, char const *argv[]) {
    // Parse command-line arguments using the lib_config library.
    Config config = parse_config(argc, argv);

    // Check if the help flag is set.
    if (config.help) {
        // Print the help message and exit.
        print_help();
        return 0; // Exit the program.
    }

    // Extract configuration parameters from the parsed configuration.
    float x = config.x; // Floating-point number to convert.
    size_t Wl = config.Wl; // Word length (total number of bits).
    size_t Fl = config.Fl; // Fractional length (number of bits for fractional part).

    // Print the configuration parameters.
    printf("----------------------------------------------------------------\n");
    printf("x=%f | Wl=%zu | Fl=%zu\n", x, Wl, Fl);
    printf("----------------------------------------------------------------\n");

    // Output bits: Array to store the fixed-point representation.
    uint8_t y[Wl];

    // Initialize the output array based on the sign of x.
    for (size_t i = 0; i < Wl; i++) {
        // If x is negative and in the integer part, initialize to 1.
        if (x < 0 && i >= Fl) {
            y[i] = 1;
        } else {
            // Otherwise, initialize to 0.
            y[i] = 0;
        }
    }

    // Convert the floating-point number to fixed-point using the lib_fun library.
    flp_to_fxp(x, Wl, Fl, y);

    // Reference calculation: Calculate the expected fixed-point value for comparison.
    int64_t r = roundf(x * pow(2, Fl));

    // Print the reference fixed-point representation.
    printf("Reference:  ");
    for (size_t i = 0; i < Wl; i++) {
        // Extract the i-th bit from the reference value.
        int64_t b = ((uint64_t)r >> (Wl - 1 - i)) & ((uint64_t)1);
        printf("%li", b); // Print the extracted bit.

        // Insert a comma between the integer and fractional parts.
        if (i == (Fl - 1) && Fl != 0 && Wl > Fl) {
            printf(",");
        }
    }
    printf("\n");

    // Print the calculated fixed-point representation.
    printf("Calculated: ");
    for (size_t i = 0; i < Wl; i++) {
        printf("%i", y[Wl - 1 - i]); // Print the calculated bit.

        // Insert a comma between the integer and fractional parts.
        if (i == (Wl - Fl - 1) && Fl != 0 && Wl > Fl) {
            printf(".");
        }
    }
    printf("\n");

    // Print a separator line.
    printf("----------------------------------------------------------------\n");

    return 0; // Indicate successful program execution.
}