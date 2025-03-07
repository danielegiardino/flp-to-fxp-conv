# Floating-Point to Fixed-Point Converter (flp_to_fxp_conv)

This repository contains a C program that converts floating-point numbers to fixed-point representations. It provides a flexible way to specify the word length and fractional length of the fixed-point output.

## Overview

Fixed-point arithmetic is often used in embedded systems and digital signal processing (DSP) applications where floating-point operations are too computationally expensive or power-consuming. This program helps in converting floating-point values to their equivalent fixed-point representations, which can then be used in such applications.

## Features

- **Flexible Configuration:**
    - You can specify the word length (`Wl`) and fractional length (`Fl`) of the fixed-point representation.
    - The program handles signed fixed-point numbers.
- **Saturation Logic:**
    - Implements saturation logic to handle floating-point values that are outside the representable range of the fixed-point format.
- **Rounding:**
    - Performs rounding to the nearest representable fixed-point value.
- **Command-Line Arguments:**
    - Allows specifying the floating-point number (`x`), word length (`Wl`), and fractional length (`Fl`) through command-line arguments.
    - Displays a help message when the `-h` or `--help` flag is used.
- **Clear Output:**
    - Prints both the calculated fixed-point representation and a reference fixed-point representation for easy comparison.
    - Inserts a comma to clearly separate the integer and fractional parts of the fixed-point output.
- **Library based code:**
    - The code is divided into libraries, making it more organized and reusable.

## Usage

### Prerequisites

- A C compiler (e.g., GCC)
- CMake (for building the project)

### Compilation

1.**Clone the repository:**

```bash
git clone [repository_url]
cd flp_to_fxp_conv
```

2. **Create a build directory:**

```bash
mkdir build
cd build
```

3. **Run CMake:**

```bash
cmake ..
```

4. **Build the project:**

```bash
make
```

5. **Run the executable:**

```bash
./flp_to_fxp_conv
```

### Command-Line Arguments

-  `./flp_to_fxp_conv`: Runs the program with default values (`x = 17.5652156`, `Wl = 16`, `Fl = 8`).
-  `./flp_to_fxp_conv <x>`: Runs the program with the specified floating-point number `x` and default `Wl` and `Fl`.
-  `./flp_to_fxp_conv <Wl> <Fl> <x>`: Runs the program with the specified word length `Wl`, fractional length `Fl`, and floating-point number `x`.
-  `./flp_to_fxp_conv -h` or `./flp_to_fxp_conv --help`: Displays the help message.

### Example

```bash
./flp_to_fxp_conv 16 8 12.345
```