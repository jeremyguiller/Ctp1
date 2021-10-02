//
// Created by jeremy on 02/10/2021.
//

#ifndef UNTITLED_FONCTIONS_H
#define UNTITLED_FONCTIONS_H
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
#define INT_SIZE 8
char *dectobin_v3(unsigned int val){
    int i = INT_SIZE-1;
    unsigned int a = val;
    char *res = malloc(INT_SIZE);
    res[INT_SIZE]="\0";
    while(i>=0){
        res[i] =(a & 1)+48;
        i--;
        a>>= 1;
    }
    return res;
}


#endif //UNTITLED_FONCTIONS_H
