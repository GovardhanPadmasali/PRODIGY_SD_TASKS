#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEMPERATURE_SCALES_SIZE 3

typedef struct {
    char* name;
    char symbol;
} TemperatureScale;

TemperatureScale TEMPERATURE_SCALES[TEMPERATURE_SCALES_SIZE] = {
    {"Celsius", 'C'},
    {"Fahrenheit", 'F'},
    {"Kelvin", 'K'}
};

double convert_temperature(double value, char input_scale, char output_scale) {
    if (input_scale == 'C') {
        if (output_scale == 'F') {
            return value * 1.8 + 32;
        } else if (output_scale == 'K') {
            return value + 273.15;
        } else {
            return value;
        }
    } else if (input_scale == 'F') {
        if (output_scale == 'C') {
            return (value - 32) / 1.8;
        } else if (output_scale == 'K') {
            return (value + 459.67) * 5 / 9;
        } else {
            return value;
        }
    } else if (input_scale == 'K') {
        if (output_scale == 'C') {
            return value - 273.15;
        } else if (output_scale == 'F') {
            return value * 9 / 5 - 459.67;
        } else {
            return value;
        }
    } else {
        return value;
    }
}

int main() {
    double value;
    char input_scale, output_scale;

    while (1) {
        // Prompt the user for input
        printf("Enter the input temperature value:\n");
        scanf("%lf", &value);
        printf("Enter the input temperature scale (C, F, or K)\n(Input are case sensitive):\n");
        scanf(" %c", &input_scale);
        printf("Enter the output temperature scale (C, F, or K)\n(Input are case sensitive):\n");
        scanf(" %c", &output_scale);

        // Convert the temperature and print the result
        double result = convert_temperature(value, input_scale, output_scale);
        printf("%.2f %c = %.2f %c\n", value, input_scale, result, output_scale);

        // Prompt the user to continue or quit
        printf("Enter q to quit, or any other key to continue:\n");
        char choice[2];
        scanf(" %s", choice);
        if (strcmp(choice, "q") == 0) {
            break;
        }
    }

    return 0;
}

