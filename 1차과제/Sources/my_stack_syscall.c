#include <linux/syscalls.h>
#include <linux/kernel.h>
#include <linux/linkage.h>

#define MAXSIZE 500

int stack[MAXSIZE];
int top = -1;


SYSCALL_DEFINE1(oslab_push, int, a){
	int i=0;
	int d=0;
// if stack is full, print "overflow"
	if (top>= MAXSIZE-1) {
		printk("stack overflow\n");	
	}
	else {
// check whether the value is already in the array
		for(i=0; i<=top; i++){
			if(stack[i] == a) {
				printk("overlap value\n");
				d +=1;
				break;			
			}
		}
// variable 'd' will be still zero, when there is no same value in the array
// then keep doing Push
		if (d == 0){	
			top +=1;
			stack[top] = a; //insert value at the top of the stack
		}
	}

//kernel mesg	
	printk(KERN_INFO "[System call] oslab_push(): Push\n");
	printk("Stack Top-------------\n");
	for (i= top ; i>=0 ; i--){
		printk("%d\n", stack[i]);	
	}
	printk("Stack Bottom----------\n");
}


SYSCALL_DEFINE0(oslab_pop){
	int result= -100;  // initialized value -100 means that pop was failed.
	int i;
// if stack is empty, print "underflow"
	if (top<0) {
		printk("stack underflow\n");
	}
	else {
		result = stack[top]; //return the top value of the stack
		top-=1; // the top value has been removed
	}

//kernel mesg
	printk(KERN_INFO "[System call] oslab_pop(): Pop\n");
	printk("Stack Top-------------\n");
	for (i= top ; i>=0 ; i--){
		printk("%d\n", stack[i]);	
	}
	printk("Stack Bottom----------\n");

// if stack is empty, return -100. Else return the top value. 
	return result;  
}
