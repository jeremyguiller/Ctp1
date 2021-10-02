#include <stdio.h>
#include <assert.h>
#include <string.h>
#include<math.h>
#include <malloc.h>
#include "fonctions.h"


int main() {
    char a[] = "10000001"; // expected 129
    char b[] = "FE"; // expected 254
    unsigned int c = 0xaaff;
    unsigned int d = 254;
    int exo1 = bintodec(a);
    int exo2 = hexatodec(b);
    char *exo3 = dectohexa(c);
    char *exo4 = dectobin_v1(d);
    char *exo5 = dectobin_v2(d);
    char *exo6 = dectobin_v3(d);
    char *exo7 = dectohexa_v2(c);
    assert(exo1==129); //exercice 1
    assert(exo2==254); //exercice 2
    assert(!strcmp(exo3, "AAFF"));//exercice 3
    assert(!strcmp(exo4, "11111110"));//exercice 4
    assert(!strcmp(exo5, "11111110"));//exercice 5
    assert(!strcmp(exo6, "11111110"));//exercice 6
    assert(!strcmp(exo7, "0000AAFF"));//exercice 7

}
