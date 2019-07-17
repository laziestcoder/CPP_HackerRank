#include<bits/stdc++.h>
#include<stdio.h>
#include<iostream>

void update(int *a,int *b) {
    int c, d;
    c = (*a) + (*b);
    d = (*a) - (*b);
    d = abs(d);
    //printf("%d %d\n",c,d);

    *a = c;
    *b = d;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;

    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}

/**
Judges Solution

Problem Tester's code:

#include <cstdio>
#include <cstdlib>

void update(int *a,int *b) {
    int temp = *a;
    *a = *a + *b;
    *b = abs(temp - *b);

}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;

    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}

*/
