#include <stdio.h>

int remainder11(int divider, int denominator) {
    if (!denominator) {
        printf("ZeroDivisionError: integer division or modulo by zero");
        return 0;
    }
    if (denominator == -1 || denominator == 1) {
        return 0;
    }
    else {
        if (divider > 0 && denominator > 0) {
            while (divider >= denominator) {
                divider -= denominator;
            }
            return divider;
        }
        if (divider < 0 && denominator > 0) {
            while (divider < 0) {
                divider += denominator;
            }
            return divider;
        }
        if (divider < 0 && denominator < 0) {
            while (divider <= denominator) {
                divider -= denominator;
            }
            return divider;
        }
        if (divider > 0 && denominator < 0) {
            while (divider>0) {
                divider += denominator;
            }
            return divider;
        }
    }
}