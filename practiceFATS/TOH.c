#include <stdio.h>

void towerOfHenoi(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    towerOfHenoi(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    towerOfHenoi(n - 1, aux, to, from);
}
int main(){
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    towerOfHenoi(n, 'A', 'C', 'B');
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a stack
struct Stack {
    unsigned capacity;
    int top;
    int *array;
};

// Function to create a stack of given capacity
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to check if a stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int item) {
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    return stack->array[stack->top--];
}

// Function to perform the Tower of Hanoi algorithm
void towerOfHanoi(int numDisks, struct Stack* source, struct Stack* auxiliary, struct Stack* destination) {
    if (numDisks == 1) {
        int disk = pop(source);
        push(destination, disk);
        printf("Move disk %d from peg %c to peg %c\n", disk, 'A' + source->array[0], 'A' + destination->array[0]);
        return;
    }
    towerOfHanoi(numDisks - 1, source, destination, auxiliary);
    int disk = pop(source);
    push(destination, disk);
    printf("Move disk %d from peg %c to peg %c\n", disk, 'A' + source->array[0], 'A' + destination->array[0]);
    towerOfHanoi(numDisks - 1, auxiliary, source, destination);
}

int main() {
    int numDisks;
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);
    
    struct Stack* source = createStack(numDisks);
    struct Stack* auxiliary = createStack(numDisks);
    struct Stack* destination = createStack(numDisks);
    
    for (int i = numDisks; i >= 1; i--) {
        push(source, i);
    }
    
    printf("Tower of Hanoi solution:\n");
    towerOfHanoi(numDisks, source, auxiliary, destination);
    
    free(source->array);
    free(auxiliary->array);
    free(destination->array);
    free(source);
    free(auxiliary);
    free(destination);
    
    return 0;
}
