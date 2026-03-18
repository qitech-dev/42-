*This project has been created as part
of the 42 curriculum by qijin*

## Description

**Push_swap** is an algorithmic project at 42. The primary goal is to sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed, you have to manipulate various sorting algorithms and choose the most appropriate solution for optimized data sorting.

The project consists of two stacks, **Stack A** and **Stack B**. StackA contains a random list of un duplicated numbers, and Stack B is empty. The objective is to sort the numbers in Stack A in ascending order.

**Technical Overview:**

In this specific implementation, I use a **circular doubly linked list** to represent the stacks, which allows for efficient `rotate` and `reverse rotate` operations. For the sorting logic, I implemented the **Turk Algorithm**(Mechanical Turk). It works by calculating the **cheapest** node to push from Stack A to Stack B, continually keeping Stack B sorted in descending order, and finally pushing everything back to Stack A in the correct ascending order.

## Instruction

### Compilation

To compile the project, simply run `make` in the root in the root directory. This will compile the sourcex files and generate the `push_swap` executable.

```bash
make
./push_swap + numbers
```

if you want use `checker_linux`:

```
ARG="2 3 ... 8 9"; ./push_swap $ARG | ./checker_linux $ARG
```

there are also two commands to generate 100 random numbers

```
ARG=$(ruby -e "puts (1..100).to_a.shuffle.join(' ')"); ./push_swap $ARG

ARG=$(shuf -i 1-1000 -n 100 | tr '\n' ' '); ./push_swap $ARG | ./checker_linux $ARG
```

## Resources

### Document

I studied Turk_Algorithm at [Push_Swap Turk algorithm explained in 6 steps](https://pure-forest.medium.com/push-swap-turk-algorithm-explained-in-6-steps-4c6650a458c0).

### AI use

I used AI to ask for explaining the Turk_Algorithm and the circular doubly linked list.
