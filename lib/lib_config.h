// lib_config.h
#ifndef LIB_CONFIG_H
#define LIB_CONFIG_H

#include <stdint.h>
#include <stdio.h>

// Structure to hold configuration parameters.
typedef struct {
    float x;
    size_t Wl;
    size_t Fl;
    int help; // Added help flag
} Config;

// Function to parse command-line arguments and populate the Config structure.
// Returns a Config structure with parsed parameters or default values.
Config parse_config(int argc, char const *argv[]);

// Function to print help message
void print_help();

#endif // LIB_CONFIG_H