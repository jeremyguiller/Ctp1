#include <stdio.h>
#include <assert.h>
#include <string.h>
#include<math.h>
#include <malloc.h>
void strreverse(unsigned char *str)
{
    int i;
    int j;
    unsigned char a;
    unsigned len = strlen((const char *)str);
    for (i = 0, j = len - 1; i < j; i++, j--)
    {
        a = str[i];
        str[i] = str[j];
        str[j] = a;
    }
}
//exercice 1
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
//exercice 2
int hexatodec(char *val)
{
    int res = 0, exp = 1, taille= strlen(val);
    char *laValeur;

    for(int i = taille - 1; i >= 0; i--){
        laValeur = val[i];
        if(laValeur >= '0' && laValeur <= '9'){
            res += (val[i] - 48) * exp;
            exp *= 16;
        }
        else if(laValeur >= 'A' && laValeur <= 'F'){
                res += (val[i] - 55) * exp;
                exp *= 16;
        }
    }
    return res;
}
//exercice 3
char *dectohexa(unsigned int val){
    int i = 0;
    char *resultat = malloc(50) ;
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
        i++;
    }
    resultat[i]="\0";
    strreverse(resultat);
    return resultat;
}
//exercice 4
char *dectobin_v1(unsigned int val){
    char *resultat = malloc(8);
    int octect = 128, foo;
    for(int i = 0; i < 8; i++){
        foo =val - octect;
        if (foo >= 0){
            val = val - octect;
            octect /= 2;
            resultat[i] = '1';
        }
        else{
            octect /= 2;
            resultat[i] = '0';
        }
    }
    resultat[8] = "\0";
    return resultat;
}

//exercice 5
char *dectobin_v2(unsigned int val){
    int i = 0;
    char *resultat = malloc(50) ;
    unsigned int a = val;
    char b = 0;
    while (a!=0){
        b = (a%2)+48;
        resultat[i]=b;
        a/=2;
        i++;
    }
    resultat[i]="\0";
    strreverse(resultat);
    return resultat;
}

//exercice 6


int main() {
    char a[] = "10000001"; // expected 129
    char b[] = "FF"; // expected 255
    int d = 250;
    printf("%s\n",dectobin_v1(d));
    printf("%d\n", hexatodec(b));
    int v = bintodec(a);
    unsigned int c = 0xaaff;
    char *test = dectohexa(c);
    printf("%s",test);
    assert(!strcmp(test, "AAFF"));
    assert(v==129);
}
