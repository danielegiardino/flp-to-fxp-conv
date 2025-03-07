// lib_config.c
#include "lib_config.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Config parse_config(int argc, char const *argv[]) {
    Config config;

    // Default values.
    config.x = 17.5652156f;
    config.Wl = 16;
    config.Fl = 8;
    config.help = 0; // Initialize help flag to 0 (false)

    // Parse command-line arguments.
    if (argc == 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)) {
        config.help = 1; // Set help flag to 1 (true)
    } else if (argc == 2) {
        // Only x is passed.
        config.x = atof(argv[1]);
    } else if (argc == 3) {
        // Incorrect number of parameters for Wl and Fl.
        fprintf(stderr, "WARNING: Both Wl and Fl must be provided together. Using default values.\n");
    } else if (argc == 4) {
        // Wl, Fl, and x are passed.
        config.Wl = atoi(argv[1]);
        config.Fl = atoi(argv[2]);
        config.x = atof(argv[3]);
    }

    return config;
}

void print_help() {
    printf("Usage: flp_to_fxp [Wl] [Fl] [x]\n");
    printf("  Wl: Word length (number of bits).\n");
    printf("  Fl: Fractional length (number of bits for fractional part).\n");
    printf("  x:  Floating-point number to convert.\n");
    printf("If no arguments are provided, default values are used.\n");
    printf("If only x is provided, default Wl and Fl are used.\n");
    printf("Wl and Fl must be provided together.\n");
    printf("Example:\n");
    printf("  flp_to_fxp 16 8 12.345\n");
    printf("  flp_to_fxp 12.345\n");
    printf("  flp_to_fxp \n");
    printf("  flp_to_fxp -h or flp_to_fxp --help\n");
}