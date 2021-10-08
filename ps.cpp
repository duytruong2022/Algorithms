#include<stdio.h>
#include<conio.h>
#include<math.h>

struct ps {
    int tu;
    int mau;
};

int ucln (int a, int b) {
    int i;
    for (i = a/2; i > 1; i++) {
        if ((a % i == 0) && (b % i == 0))
            return i;
    }
    return 1;
}

void rutgon (ps a) {
    int uc = ucln (a.tu, a.mau);
    a.mau = a.mau / uc;
    a.tu = a.tu / uc;
}

ps sosanh (ps a, ps b) {
    double he;
    he = (a.tu/a.mau) - (b.tu/b.mau);
    if (he >= 0) 
        return a;
    else
        return b; 
}

void print (ps a) {
    printf ("%d/%d", a.tu, a.mau);
}

int main () {
    
}