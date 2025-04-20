# 42 Push Swap

This project is about sorting data using two stacks and a limited set of operations. It introduces key algorithmic concepts — **time and space complexity**, **stack manipulation**, and **sorting algorithms** — and serves as a solid exercise in data structure logic and writing efficient, constraint-driven code.

## Status

- ✅ Validated: 04.12.2024.
- 🎓 Grade: 125/100.
- 🚦 Compliant with [42 Norm](#note) rules.

## Performance

I highly recommend this [tester](https://github.com/SimonCROS/push_swap_tester) to calculate the average, best-case, and worst-case performance of your `push_swap` (it's in French, but quite self-explanatory).

My algorithm sorts:

> - **3 numbers** with a maximum of *2 moves*,
> - **4 numbers** with a maximum of *6 moves*,
> - **5 numbers** with a maximum of *10 moves*,
> - **100 numbers** with a maximum of *670 moves*,
> - **500 numbers** with a maximum of *4950 moves*.

A visual example of sorting 500 random values (this is the [visualiser](https://github.com/o-reo/push_swap_visualizer) I used):

![push_swap_visualiser.gif](https://github.com/nkhamichonak/push_swap/blob/main/push_swap_visualiser.gif)

## Project Description

### Requirements

`push_swap` takes an unsorted list of integers as input, either passed as separate command-line arguments or as a single string of space-separated numbers. The goal is to sort these integers in ascending order using only two stacks, named A and B, and a limited set of allowed operations — all while aiming for the smallest number of moves possible.

Each executed move must be printed to STDOUT, followed by a newline (`\n`). After execution, stack A should be fully sorted, and stack B must be empty.

The allowed operations are:

| Command | Description |
|--------|-------------|
| `sa`   | Swap the first two elements at the top of stack **a**. |
| `sb`   | Swap the first two elements at the top of stack **b**. |
| `ss`   | `sa` and `sb` at the same time. |
| `pa`   | Push the top element of stack **b** onto stack **a**. |
| `pb`   | Push the top element of stack **a** onto stack **b**. |
| `ra`   | Rotate stack **a** upwards by one. The first element becomes the last. |
| `rb`   | Rotate stack **b** upwards by one. The first element becomes the last. |
| `rr`   | `ra` and `rb` at the same time. |
| `rra`  | Reverse rotate stack **a**. The last element becomes the first. |
| `rrb`  | Reverse rotate stack **b**. The last element becomes the first. |
| `rrr`  | `rra` and `rrb` at the same time. |

Example output:

```
./push_swap 394 0 -11 8
ra
sa
pb
pa
```

### Approach

My approach is a hybrid strategy combining **manual sorting for small cases**, **divide-and-conquer principles**, and a **greedy cost-optimised reinsertion** for larger datasets.

Step-by-step breakdown:

#### 1. Indexing the input

I begin by indexing all numbers — mapping each value to its zero-based rank in the sorted sequence (e.g. smallest becomes 0, next smallest 1, etc.).
→ This is similar to **coordinate compression** and helps normalise the data for easier comparisons and chunking.

#### 2. Mini sort for small inputs (≤5 elements)

- For up to 3 elements, I use hardcoded conditionals to sort in minimal moves.

- For 4 or 5 elements, I push the smallest values to stack B, sort the rest in A, then reinsert them in the correct position.

#### 3. Median-based partitioning for larger inputs

- I compute the median of the indexed list and start pushing values from stack A to stack B:

	- Elements below the median go to the bottom of stack B.

	- Elements above the median go to the top.

- This results in two logical chunks in stack B — a rough separation similar to the initial partitioning step in **quicksort** (though the follow-up logic is different).

- Once only the 5 highest values remain in A, I sort them with mini_sort.

#### 4. Cost-based reinsertion from stack B

- For each element in stack B, I calculate the number of operations needed to insert it in the correct position in A.

- I pick the cheapest move (i.e. the one requiring the fewest total instructions) and execute it - similar to a **greedy algorithm**.

- After each insertion, I recalculate the costs for the remaining elements.

#### 5. Final alignment

Once stack B is empty, I rotate stack A to bring the smallest element to the top (if needed).

## Usage

### Main part

Run `make` or `make all` to compile all the files and run the executable `./push_swap` followed by a random number of integers:
```
./push_swap 394 77 -8 0 15
```
To verify the output, you can pipe it into the official 42 checker (choose the correct version for your OS):
```
ARG="394 77 -8 0 15"; ./push_swap $ARG | ./checker_mac $ARG
```
or
```
ARG="394 77 -8 0 15"; ./push_swap $ARG | ./checker_linux $ARG
```

### Bonus part:

The bonus part implements a program called `checker`.

`checker` reads a list of integers and a series of operations from standard input (STDIN), then simulates those operations on two stacks. At the end, it checks if **stack A is sorted in ascending order** and **stack B is empty**.

- If the stacks are correctly sorted: prints `OK`
- If not: prints `KO`
- If it encounters an invalid operation: prints `Error`

Run `make bonus` to compile the checker and use it in the same way you would the default 42 checkers:
```
ARG="394 77 -8 0 15"; ./push_swap $ARG | ./checker $ARG
```

### Constraints


<a id="note"></a>

> 🛠️ **Note:**
> 42 project requirements that impact structure and readability:
> - Functions must be no longer than 25 lines.
> - A file may contain a maximum of 5 functions.
> - `for`, `do..while`, `switch`, ternary operators, and VLAs are forbidden.
> - Standard C library functions are not allowed (unless a few specific ones are explicitly permitted for a project).
> - Variables cannot be declared and assigned in the same line.

⚠️ P.S. Don't copy, learn!

Made by: nkhamich@student.codam.nl | LinkedIn: [nkhamichonak](https://www.linkedin.com/in/nkhamichonak/)
