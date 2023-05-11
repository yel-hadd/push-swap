# push-swap
Push_swap is a project that involves sorting a stack of numbers using a set of instructions. The project is written in C and can be compiled with a Makefile.
## Preview
https://github.com/yel-hadd/push-swap/assets/82560247/011cf0e5-a675-4a88-8692-67ffbe61a4c0
## Allowed Instructions
* sa : swap the first two elements at the top of stack a.
* sb : swap the first two elements at the top of stack b.
* ss : sa and sb at the same time.
* pa : take the first element at the top of b and put it at the top of a.
* pb : take the first element at the top of a and put it at the top of b.
* ra : rotate a - shift up all elements of stack a by 1. The last element becomes the first one.
* rb : rotate b - shift up all elements of stack b by 1. The last element becomes the first one.
* rr : ra and rb at the same time.
* rra : reverse rotate a - shift down all elements of stack a by 1. The first element becomes the last one.
* rrb : reverse rotate b - shift down all elements of stack b by 1. The first element becomes the last one.
* rrr : rra and rrb at the same time.
## Usage
To use push_swap, clone the repository and compile it with the following commands:
```bash
$ git clone https://github.com/yel-hadd/push-swap
$ cd push-swap
$ make
```
Then, you can sort a stack of numbers by running the following command:
```bash
$ ./push_swap [numbers]
```
where [numbers] is a list of numbers to be sorted.
## Output
The program outputs the series of instructions required to sort the stack.



