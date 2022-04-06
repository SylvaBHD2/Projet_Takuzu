//
// Created by lucas on 06/04/2022.
//
#include <stdio.h>
#include "P3.h"

void gen_mat(num) {
    if (num == 1) {
        int T[3][3];
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                T[i][j] = 0;
                printf("%d \n", T[i][j]);
            }
        }
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                printf("%d", T[i][j]);
            }
            printf("\n");
        }
    }
}