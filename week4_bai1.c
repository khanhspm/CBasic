#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Diachi{
    char ten[100];
    char sdt[20];
    char email[100];
};
typedef struct Diachi diachi;

struct Address{
    diachi data;
    struct Address* next;
};
typedef struct Address address;


