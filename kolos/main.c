#include <stdio.h>
#include <stdlib.h>

/*
r0  r1
|---|
0   1   2   3   4   5   6    indeksy
1   1   2   3   5   8   13   wartości
|   |---|
pom r0  r1
*/
int fibo3(int n){
    int r0=1;
    int r1=1;
    int pom;

    if(n == 0) return r0;
    if(n == 1) return r1;

    int i;

    for(i=2;i<n-2;i++){
        pom = r0;
        r0=r1;
        r1=r0+pom;
    }
    return r1;
}
/*
*   fibo1(4) = 5
    r0 = 1
    r1 = 1

    4 == 0 false
    4 == 1 false

    i = 2
    2 <= 4 pom = 1
           r0 = 1
           r1 = 1 + 1 = 2  i = 3

    3 <= 4 pom = 1
           r0 = 2
           r1 = 2 + 1 = 3  i = 4

    4 <= 4 pom = 2
           r0 = 3
           r1 = 3 + 2 = 5  i = 5

    5 <= 4 false

    return r1 = 5
*/

/*
r0  r1  r2
|---|---|
0   1   2   3   4   5   6    indeksy
1   1   2   3   5   8   13   wartości
|---|---|
r0  r1  r2
*/
int fibo2(int n){
    int r0=1;
    int r1=1;
    int r2=2;

    if(n == 0) return r0;
    if(n == 1) return r1;
    if(n == 2) return r2;

    int i;
//	for(i=3;i<=n;i++){
    for(i=0;i<n-2;i++){
        r0=r1;
        r1=r2;
        r2=r0+r1;
    }
    return r2;
}
/*
*   fibo1(4) = 5
    r0 = 1
    r1 = 1
    r2 = 2

    4 == 0 false
    4 == 1 false
    4 == 2 false

    i = 3
    3 <= 4 r0 = 1
           r1 = 2
           r2 = 2 + 1 = 3  i = 4

    4 <= 4 r0 = 2
           r1 = 3
           r2 = 3 + 2 = 5  i = 5

    5 <= 4 false

    return r2 = 5
*/

/*
f(1) = 1
f(2) = 1
f(3) = f(n-1) + f(n-2)

0 1 2 3 4 5 6
1 1 2 3 5 8 13
 */
int fibo1(int n){
    if(n==0 || n==1) return 1;
    return fibo1(n-1)+fibo1(n-2);
}
/*
*  fibo1(4) = 5
   return fibo2(3) + fibo (2) = 3 + fibo7(2) = 3 + 2 = 5
*  fibo2(3) = 3
   return fibo3(2) + fibo (1) = 2 + fibo6(1) = 2 + 1 = 3
*  fibo3(2) =  2
   return fibo4(1) + fibo (0) = 1 + fibo5(0) = 1 + 1 = 2
*  fibo4(1) = 1
   return 1
*  fibo5(0) = 1
   return 1
*  fibo6(1) = 1
   return 1
*  fibo7(2) =
   return fibo8(1) + fibo (0) = 1 + fibo9(0) = 1 + 1 = 2
*  fibo8(1) = 1
   return 1
*  fibo9(0) = 1
   return 1
*/

int main(int argc, char *argv[]) {

    int n = 5;
    printf("fibo(%d) = %d", n, fibo2(n));

    return 0;
}