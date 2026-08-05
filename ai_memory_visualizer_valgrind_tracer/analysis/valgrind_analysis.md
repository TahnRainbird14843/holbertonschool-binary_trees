## Valgrind Memory Analysis

#heap_example.c

Valgrind run with flag --leak-check=full

| Valgrind Warning | Classification of Error | Memory Object Involved | Cause of Error |
|------------------|-------------------------|------------------------|----------------|
| 6 bytes in 1 blocks are definitely lost in loss record 1 of 1 | Memory Leak | variable p->name |
When creating the struct person, memory was alloc'ed for the struct, as well as for the name variable
p->name. the function person_free_partial on frees the struct p without freeing p->name first, causing
a memory leak. This occurs because the program has still reserved memory in the heap, but no pointers
remain to this memory since they are removed on program termination. |



#aliasing_example.c

Valgrind run with no flags

| Valgrind Warning | Classification of Error | Memory Object Involved | Cause of Error |
|------------------|-------------------------|------------------------|----------------|
| Invalid read of size 4: Address 0x4a8c488 is 8 bytes inside a block of size 20 free'd |
Use-after-free | Variable b pointing to the heap | Both a and b point to memory which was allocated
on the heap. a was free'd making the memory invalid, but b still points there. This caused a
use-after-free when b[2] was read. |

This lead to the following further errors:
- Invalid write of size 4: Address 0x4a8c48c is 12 bytes inside a block of size 20 free'd
- Invalid read of size 4: Address 0x4a8c48c is 12 bytes inside a block of size 20 free'd

These were caused by the program writing b[3]=1234 and reading b[3] respectively.
