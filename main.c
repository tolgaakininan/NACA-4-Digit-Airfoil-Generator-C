#include <stdio.h>
#include "generator.h"

int main() {
    int num_points = 100;
    double M, P, T ;
    int digit;
    printf("NACA 4digit profili girin: ");

    if (scanf("%d", &digit) != 1 || digit < 1000 || digit > 9999) {
        printf("Hatalı giriş! Lütfen 4 haneli bir sayı girin.\n");
        return 1;
    }

    M = digit / 1000;
    P = (digit / 100) % 10;
    T = digit % 100;
    Airfoil *airfoil = create_airfoil(num_points, M, P, T);
    
    if (!airfoil) {
        printf("Airfoil oluşturulamadı.\n");
        return 1;
    }

    airfoil->calculate_coordinates(airfoil);

    printf("x\tXu\tYu\tXl\tYl\n");
    for (int i = 0; i < airfoil->num_points; i++) {
        printf("%.4f\t%.4f\t%.4f\t%.4f\t%.4f\n",
               airfoil->x[i], airfoil->xu[i], airfoil->yu[i], airfoil->xl[i], airfoil->yl[i]);
    }

    free_airfoil(airfoil);
    return 0;
}

