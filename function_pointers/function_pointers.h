#include <stddef.h>

#ifndef FUNCTION_POINTERS_H
#define FUNCTION_POINTERS_H

int print_name(char *name, void (*f)(char *));
int array_iterator(int *array, size_t size, void (*action)(int));
int int_index(int *array, int size, int (*cmp)(int));

#endif
