#ifndef SORT_H
#define SORT_H

/* STANDARD LIBARIES  */
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/* STRUCTURE DEFINATION  */
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* FUNCTION PROTOTYPES  */
void print_list(const listint_t *);
void print_array(const int *, size_t);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **);
void selection_sort(int *, size_t);
int partition(int *array, int start, int end, size_t size);
void quick_sort(int *array, size_t size);
void quicksort(int *array, int start, int end, size_t size);
void shell_sort(int *array, size_t size);
void counting_sort(int *array, size_t size);
int max(int *array, size_t size);
void cocktail_sort_list(listint_t **);

#endif /*end #ifndef SORT_H */
