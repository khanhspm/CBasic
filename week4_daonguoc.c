#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack{
    int top;
    unsigned c;
    char* s;
};
struct Stack* Init(unsigned c){
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->c = c;
    stack->top = -1;
    stack->s = (char*) malloc(stack->c * sizeof(struct Stack));
    return stack;
};

int empty(struct Stack* stack){
    return stack->top == -1;
}

int full(struct Stack* stack){
    return stack->top == stack->c - 1;
}

void push(struct Stack* stack, char x){
    if(full(stack)) return;
    stack->s[++stack->top] = x;
}

char pop(struct Stack* stack){
    if(empty(stack)) printf("stack under flow\n");
    return stack->s[stack->top--];
}

void reverse(char a[]){
    int n = strlen(a);
    struct Stack* stack = Init(n);
    int i;
    for(i = 0; i < n; i++){
        push(stack, a[i]);
    }
    for(i = 0; i < n; i++){
        a[i] = pop(stack);
    }
}

int main(){
    char a[1000];
    printf("Nhap chuoi: ");
    fflush(stdin);
    gets(a);
    reverse(a);
    printf("Chuoi sau khi dao la: %s", a);
    return 0;
}