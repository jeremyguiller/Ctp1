#include <stdio.h>
#include <assert.h>
#include <string.h>
#include<math.h>
#include <malloc.h>


int bintodec(char *val){
    int resultat = 0;
    for (int i = 0 ; i<strlen(val);i++){
        int c = *(val+i);
        int d = strlen(val)-(i+1);
        if (c == 49){
            resultat=resultat+(1<<d);
        }
    }
    return resultat;
}
char *dectohexa(unsigned int val){
    int i = 1;
    char *resultat = malloc(i+1) ;
    unsigned int a = val;
    char b = 0;
    while (a!=0){
        if (a%16<10){
            b = (a%16)+48;
            resultat[i]=b;
        }
        else{
            b = (a%16)+55;
            resultat[i]=b;
        }
        a=a/16;
        i--;
    }
    return resultat;
}



int main() {
    char a[] = "10000001"; // expected 129
    int v = bintodec(a);
    unsigned int c = 254;
    char *test = dectohexa(c);
    printf("%c",test[0]);
    printf("%c",test[1]);
    assert(v==129);
}
