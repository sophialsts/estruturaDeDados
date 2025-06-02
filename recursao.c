#include <stdio.h>

int fact(int n) {
    if(n==0) return 1; 
    return(n*fact(n-1));
}

int main() {

    int total = 4;

    total = fact(total);

    printf("%d", total);

    return 0;
}