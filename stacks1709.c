#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20

struct ArrStack
{
    int first;
    int n;
    int *arr;
};


struct ArrStack *Create(){
    struct ArrStack *s=malloc(sizeof(struct ArrStack));
    if (!s) return NULL;
    s->n=MAXSIZE;
    s->first=-1;
    s->arr=malloc(s->n *sizeof(int));
    if(!s->arr) return NULL;
    return s;
}

int isEmpty(struct ArrStack *s){
    return (s->first==-1);
}


int isFull(struct ArrStack *s){
    return (s->first == s->n - 1);
}

void push(struct ArrStack *s, int val ){
    if (isFull(s)) printf("Stack is full");
    else {
        s->arr[++s->first]=val;
        printf("%d pushed to stack\n", val);
    }
}

int pop(struct ArrStack *s){
    if (isEmpty(s)) {
        printf("Stack is Empty");
        return -1;
    }
    else {
        return (s->arr[s->first--]);
    }

}

int peek(struct ArrStack* s)
{
	if (isEmpty(s))
		return -1;
	return s->arr[s->first];
}

int count(struct ArrStack *s)
{
    
    return s->first+1;
}



int main(){
    struct ArrStack* s = Create(MAXSIZE);
    push(s,4);
    push(s,9);
    push(s,7);
    count(s);
    printf("%d",peek(s));//peak
    printf("\n%d",count(s));//counting no of elements in a stack
   
    return 0;
}
