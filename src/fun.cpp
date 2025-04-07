// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>
#include <cmath>

unsigned int faStr1(const char *str) {
    unsigned int count = 0;

    while (*str) {
        while (*str == ' ') {
            str++;
        }
        if (*str == '\0') break;

        bool has_digit = false;
        const char* start = str;

        while (*str != ' ' && *str != '\0') {
            if (isdigit(*str)) {
                has_digit = true;
            }
            str++;
        }

        if (!has_digit) {
            count++;
        }
    }

    return count;
}

unsigned int faStr2(const char *str) {
    unsigned int count = 0;

    while (*str) {
        while (*str == ' ') {
            str++;
        }
        if (*str == '\0') break;

        bool valid = true;
        const char* current = str;

        if (*current < 'A' || *current > 'Z') {
            valid = false;
        }

        current++;

        while (*current != ' ' && *current != '\0') {
            if (*current < 'a' || *current > 'z') {
                valid = false;
            }
            current++;
        }

        if (valid) {
            count++;
        }

        str = current;
    }

    return count;
}

unsigned int faStr3(const char *str) {
    unsigned int word_count = 0;
    unsigned int total_length = 0;

    while (*str) {
        while (*str == ' ') {
            str++;
        }
        if (*str == '\0') break;

        const char* start = str;
        while (*str != ' ' && *str != '\0') {
            str++;
        }

        word_count++;
        total_length += str - start;
    }

    if (word_count == 0) {
        return 0;
    }

    double average = static_cast<double>(total_length) / word_count;
    return static_cast<unsigned int>(average + 0.5);
}
