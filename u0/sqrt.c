#include <stdio.h>

float p = 0.00001;  // precision

float heron(float x, float a) {
    float a0 = (a + x / a) / 2;

    printf("Adresse von a0 ist %p, von p ist %p\n", (void*)&a0, (void*)&p);

    if (a0 * a0 - x < p)
        return a0;
    else
        return heron(x, a0);
}

float bs_sqrt(float x) {
    return heron(x, 1);
}

int main() {
    float x = 100;
    float res = bs_sqrt(x);

    printf("Die Quadratwurzel von %.0f ist %.4f\n", x, res);
    return 0;
}