#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
    char data;
    struct stack* next;
};
struct stack *top = NULL;
void push(char c) {
    struct stack* newNode = (struct stack*)malloc(sizeof(struct stack));
    newNode ->data = c;
    newNode ->next = top;
    top = newNode;
}


char pop() {
    if (top == NULL) {
        return '\0';   
    }
    struct stack* temp = top;
    char c = temp->data;
    top = top->next;
    free(temp);
    return c;
}

    
int Matching(char* s) {
    top = NULL; 
    for (int i = 0; s[i] != '\0'; i++) {
        char c = s[i];
        if (c == '(' || c == '{' || c == '[') {
            push(c);
        } else {
           char t = pop(c);
            if ((c == ')' && pop(c) != '(') ||
                (c == '}' && pop(c) != '{') ||
                (c == ']' && pop(c) != '[')) {
                return 0;
            }
        }
    }
    return top == NULL;
}

int main(){
    char s[100];
    printf("Enter the string: ");
    scanf("%s", s);

    if (Matching(s))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");
    return 0;
}
