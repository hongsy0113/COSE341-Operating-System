#include <unistd.h>
#include <stdio.h>

#define my_stack_push 335
#define my_stack_pop 336
// define system call number

int main() {
 int a, b, c, i, pop; // variable pop is to store return value of my_stack_Pop
 a = 1; b = 2; c = 3;

//push 1, 2, 3 to stack
 syscall(my_stack_push, a);
 printf("Push: %d\n", a);

 syscall(my_stack_push, b);
 printf("Push: %d\n", b);

 syscall(my_stack_push, c);
 printf("Push: %d\n", c);


//pop 3 times

for (i=0; i<3; i++){
 pop = syscall(my_stack_pop);
 printf("pop: %d\n", pop);
}




 return 0;
}
