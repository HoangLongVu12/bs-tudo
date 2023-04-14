#include <stdio.h>
#include <stdlib.h>

float p = 0.00001;  // precision

float heron(float x, float a) {
    float a0 = (a + x / a) / 2;

    if (a0 * a0 - x < p)
        return a0;
    else
        return heron(x, a0);
}

float bs_sqrt(float x) {
    return heron(x, 1);
}

int main(int argc, char* argv[]) {
    if (argc == 1) {
        printf("Fehler: Keine Parameter angegeben\n");
        return -1;
    } else if (argc != 2) {
        printf("Fehler: Zu viele Parameter angegeben\n");
        return -1;
    }

    char* endptr;
    float x;

    x = strtod(argv[1], &endptr);

    if (endptr == argv[1] || *endptr != '\0') {
        printf("Fehler: Eingabe ist keine Zahl\n");
        return 1;
    }

    if (x < 0) {
        printf("Fehler: Negative Zahl als Parameter angegeben\n");
        return -1;
    }

    float res = bs_sqrt(x);

    printf("Die Quadratwurzel von %.0f ist %.4f\n", x, res);
    return 0;
}