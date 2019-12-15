#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct Fraction
{
    int num, den;
};
 
//TODO Zabezpieczenie przed dzieleniem przez 0, i wyswietlanie u?amk?w niew?a?ciwych
struct Fraction sum(struct Fraction x, struct Fraction y)
{
    // a / b + c / d = (a * d + c * b) / ( b * d )
    struct Fraction z;
    int a = x.num;
    int b = x.den;
 
    int c = y.num;
    int d = y.den;
 
    z.num = a * d + c * b;
    z.den = b * d;
 
    return z;
}
 
struct Fraction diff(struct Fraction x, struct Fraction y)
{
    // a / b - c / d = (a * d - c * b) / ( b * d )
    struct Fraction z;
 
    int a = x.num;
    int b = x.den;
 
    int c = y.num;
    int d = y.den;
 
    z.num = a * d - c * b;
    z.den = b * d;
 
    return z;
}
struct Fraction mul(struct Fraction x, struct Fraction y)
{
    // a / b * c / d = (a * c)/(b * d)
    struct Fraction z;
    int a = x.num;
    int b = x.den;
 
    int c = y.num;
    int d = y.den;
 
    z.num = a * c;
    z.den = b * d;
 
    return z;
}
struct Fraction div2(struct Fraction x, struct Fraction y)
{
    //(a/b)/(c/d) = (a * d) / (b * c)
    struct Fraction z;
    int a = x.num;
    int b = x.den;
 
    int c = y.num;
    int d = y.den;
 
    z.num = a * d;
    z.den = c * b;
 
    return z;
}
void printFraction(struct Fraction x){
    if (x.den == 0){
        printf("Nie można dzielić przez zero!");
    }
    else if (x.num == 0) {
        printf("%d \n", x.num);
    }

    else if (abs(x.num) == abs(x.den)) {
        printf("%d \n", 1);
    }
    else if (x.num < 0 && x.den < 0)
    {   
        int calych = x.num / x.den;
        int reszta = x.num % x.den;
        x.num = abs(reszta);
        if(x.num == 0){
            printf("%d \n",calych);
        }
        else printf("%d i %d/%d \n",abs(calych), abs(x.num), abs(x.den));
    }
    else if (x.num > 0 && x.den < 0)
    {   
        int calych = x.num / x.den;
        int reszta = x.num % x.den;
        x.num = abs(reszta);
        if(x.num == 0){
            printf("%d \n",calych);
        }
        else printf("%d i %d/%d \n",calych, abs(x.num), abs(x.den));
    }

    else if (abs(x.num) > abs(x.den))
    {   
        int calych = x.num / x.den;
        int reszta = x.num % x.den;
        x.num = abs(reszta);
        if(x.num == 0){
            printf("%d \n",calych);
        }
        else printf("%d i %d/%d \n",calych, x.num, x.den);
    }
    

    else{
            printf("%d/%d \n", x.num, x.den);
        }
    
	
}
/*
       0    1    2     3     index
s -> ['9']['3']['a']['\0']  
     |    |    |    |        pointer
     s    s+1  s+2  s+3
*/
// TODO wyswietlanie ujemnych liczb
int isNumber(const char* s){
    if(*s == '\0') return 0;
    while(*s){
        if (isdigit(*s) || *s == '-'){
            s++;
        }
        else{
            return 0;
        }
        
    }
    return 1;
}
 
/*
 
       i         i'        j'        j
       0    1    2     3   4     5    6    7
s -> [' '][' ']['a']['l']['a'][' '][' ']['\0']
       k
       
*/
char* trim(char* s){
   
    int i = 0;
    int j = strlen(s) - 1;
    int k = 0;
    while(isspace(s[i]) && i <= j){
        i++;
    }
    while(isspace(s[j]) && j >= 0){
        j--;
    }
    while(i <= j ){
        s[k++] = s[i++];
    }
    s[k] = '\0';
    return s;
}
 
/*
       0     1   2    3     index
s -> ['3']['/']['5]['\0']
     |      |
     s     slash               
                            pointer
*/
int getFraction(struct Fraction* x, char* s){
    int n = strlen(s);
    char* slash = strchr(s, '/');
    int index = slash - s;
    char before[n];
    char after[n];
   
    trim(s);
    if (!slash && !isNumber(s)) return 0;
    if(!slash){
        x -> num = atoi(s);
        x -> den = 1;
        return 1;
    }
   
    strncpy(before, s, index);
    before[index] = '\0';
    strcpy(after, slash + 1);
   
    trim(before);
    trim(after);
   
 
   
    if(isNumber(before) && isNumber(after)){
        if(*after == '0'){
        printf("Nie wolno dzielić przez 0");
        return 0;
        }
        x -> num = atoi(before);
        x -> den = atoi(after);
        return 1;
    }
    return 0;
   
}
int main()
{
    /*
    char* x = "3";
    if(!getFraction(&ulamek, x))
    printf("To nie jest ulamek\n");
    else{
        printf("To jest ulamek\n");
        printFraction(ulamek);
    }*/
    struct Fraction ulamek;
    char linia[80+1];
   
    do{
        printf(" a/b = ");
        fgets(linia, 81, stdin);
    }
    while(!getFraction(&ulamek, linia));
    printFraction(ulamek);
   
    /*  char s[10] = " ala ";
    printf("%s\n", s);
    trim(s);
    printf("%s\n", s, '$');
   
    struct Fraction a, b;
    printf("Podaj dwa ulamki, kazda liczbe z nich oddziel spacja\n");
    scanf("%d%d%d%d", &a.num, &a.den, &b.num, &b.den);
    printf("Ułamek nr 1: ");
    printFraction(a);
    printf("Ułamek nr 2: ");
    printFraction(b);
    printf("Suma = ");
    printFraction(sum(a, b));
    printf("Roznica = ");
    printFraction(diff(a, b));
    printf("Mnozenie = ");
    printFraction(mul(a, b));
    printf("Dzielenie = ");
    printFraction(div(a, b));
    return 0;*/
   
}