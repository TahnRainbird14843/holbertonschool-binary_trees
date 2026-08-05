## Memory Visualising for stack_example.c
# Entering depth 0

Here we enter main and immediately call walk_stack(0, 3) which calls dump_frame("enter", 0).

| variable  | function call  | location | value  | Address | 
|-----------|----------------|----------|--------|---------|
| marker | walk_stack (depth 0) | stack | 0 | 0x7ffc009458c4 |
| local_int | dump_frame | stack | 100 | 0x7ffc00945874 |
| p_local | dump_frame | stack | 0x7ffc00945874 | unknown |
| local_buf[0] | dump_frame | stack | 'A' | local_buf = 0x7ffc00945880 |

We then exit dump_frame which ends the lifetime of the variables it created, and return to walk_stack(0, 3).

# Entering depth 1

Here we call walk_stack(1, 3) which calls dump_frame("enter", 1).

| variable  | function call  | location | value  | Address |
|-----------|----------------|----------|--------|---------|
| marker | walk_stack (depth 1) | stack | 10 | 0x7ffc00945894 |
| local_int | dump_frame | stack | 101 | 0x7ffc00945844 |
| p_local | dump_frame | stack | 0x7ffc00945844 | unknown |
| local_buf[0] | dump_frame | stack | 'B' | local_buf = 0x7ffc00945850 |

We then exit dump_frame which ends the lifetime of the variables it created, and return to walk_stack(1, 3).


# Entering depth 2

Here we call walk_stack(2, 3) which calls dump_frame("enter", 2).

| variable  | function call  | location | value  | Address |
|-----------|----------------|----------|--------|---------|
| marker | walk_stack (depth 2) | stack | 20 | 0x7ffc00945864 |
| local_int | dump_frame | stack | 102 | 0x7ffc00945814 |
| p_local | dump_frame | stack | 0x7ffc00945814 | unknown |
| local_buf[0] | dump_frame | stack | 'C' | local_buf = 0x7ffc00945820 |

We then exit dump_frame which ends the lifetime of the variables it created, and return to walk_stack(2, 3).


# Entering depth 3

Here we call walk_stack(3, 3) which calls dump_frame("enter", 3).

| variable  | function call  | location | value  | Address |
|-----------|----------------|----------|--------|---------|
| marker | walk_stack (depth 3) | stack | 30 | 0x7ffc00945834 |
| local_int | dump_frame | stack | 103 | 0x7ffc009457e4 |
| p_local | dump_frame | stack | 0x7ffc009457e4 | unknown |
| local_buf[0] | dump_frame | stack | 'D' | local_buf = 0x7ffc009457f0 |

We then exit dump_frame which ends the lifetime of the variables it created, and return to walk_stack(3, 3).
This ends the recursive steps, and we proceed to exit from each stage.


# Exiting depth 3

Before exiting walk_stack(3, 3) we call dump_frame("exit", 3).

| variable  | function call  | location | value  | Address |
|-----------|----------------|----------|--------|---------|
| marker | walk_stack (depth 3) | stack | 30 | 0x7ffc00945834 |
| local_int | dump_frame | stack | 103 | 0x7ffc009457e4 |
| p_local | dump_frame | stack | 0x7ffc009457e4 | unknown |
| local_buf[0] | dump_frame | stack | 'D' | local_buf = 0x7ffc009457f0 |

We then exit dump_frame which ends the lifetime of the variables it created, and exit walk_stack(3, 3) which 
ends the lifetime of the marker variable at depth 3. We return to walk_stack(2, 3).


# Exiting depth 2

before exiting walk_stack(2, 3) we call dump_frame("exit", 2).

| variable  | function call  | location | value  | Address |
|-----------|----------------|----------|--------|---------|
| marker | walk_stack (depth 0) | stack | 20 | 0x7ffc00945864 |
| local_int | dump_frame | stack | 102 | 0x7ffc00945814 |
| p_local | dump_frame | stack | 0x7ffc00945814 | unknown |
| local_buf[0] | dump_frame | stack | 'C' | local_buf = 0x7ffc00945820 |

We then exit dump_frame which ends the lifetime of the variables it created, and exit walk_stack(2, 3) which
ends the lifetime of the marker variable at depth 2. We return to walk_stack(1, 3).


# Exiting depth 1

before exiting walk_stack(1, 3) we call dump_frame("exit", 1).

| variable  | function call  | location | value  | Address |
|-----------|----------------|----------|--------|---------|
| marker | walk_stack (depth 0) | stack | 10 | 0x7ffc00945894 |
| local_int | dump_frame | stack | 101 | 0x7ffc00945844 |
| p_local | dump_frame | stack | 0x7ffc00945844 | unknown |
| local_buf[0] | dump_frame | stack | 'B' | local_buf = 0x7ffc00945850 |

We then exit dump_frame which ends the lifetime of the variables it created, and exit walk_stack(1, 3) which
ends the lifetime of the markeer variable at depth 1. We return to walk_stack(0, 3).


# Exiting depth 0

Before exiting walk_stack(0, 3) we call dump_frame("exit", 0).

| variable  | function call  | location | value  | Address |
|-----------|----------------|----------|--------|---------|
| marker | walk_stack (depth 0) | stack | 0 | 0x7ffc009458c4 |
| local_int | dump_frame | stack | 100 | 0x7ffc00945874 |
| p_local | dump_frame | stack | 0x7ffc00945874 | unknown |
| local_buf[0] | dump_frame | stack | 'A' | local_buf = 0x7ffc00945880 |

We then exit dump_frame which ends the lifetime of the variables it created, and exit walk_stack(0, 3) which
ends the lifetime of the marker variable at depth 0. We return to main which returns 0, and the program completes.


## Memory Visualising for aliasing_example.c

#Before calling make_numbers(n)

We initialise null-pointers a and b which are stored on the stack and call make_numbers(5).

#Inside make_numbers(5)

This functions mallocs memory from the heap and stores the address of this memory in the variable arr. arr itself is located on the stack, 
but points to memory that has been allocated on the heap. Specifically, this points to the first value of the array {0, 11, 22, 33, 44}.
The address of this array is returned.

#After make_numbers(5)

We now store the address of the array created in make_numbers(5) in the variables a and b. Thus a and b are pointers stored in the
stack which point to memory which has been alloated on the heap. In this case they both contain the address 0x55b112b686b0.
a is then freed, which makes the memory stored on the heap invalid and replaces the array stored in the heap with garbage values.
However, this is now a dangling pointer since b still contains the address of this memory. The program demostrates that we can
still read and write to the address in b, despite that memory in the heap being invalid. 

We sample the garbage data b[2] = -1889944790 and we write b[3] = 1234.

The program then returns 0 and ends.
