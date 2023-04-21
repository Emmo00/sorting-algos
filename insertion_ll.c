#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

void swap(listint_t *x, listint_t *y, listint_t **head)
{
    x->next = y->next;
    if (y->next != NULL)
        y->next->prev = x;
    y->next = x;
    y->prev = x->prev;
    if (x->prev != NULL)
        x->prev->next = y;
    else
        *head = y;
    x->prev = y;
}

void insertion_sort_list(listint_t **head)
{
    listint_t *node, *tmp, *t, *tm;
    node = (*head)->next;
    while (node != NULL)
    {
        tmp = node;
        if (node)
            tm = node->next;
        //printf("%d - \n", node->prev->n);
        while (tmp->n < tmp->prev->n && tmp->prev != NULL)
        {
            //printf("%d - %d\n", tmp->n, tmp->prev->n);
            t = tmp;
            swap(tmp->prev, tmp, head);
            print_list(*head);
            printf("hello %d ---\n", t->n);
            tmp = t;
        }
        printf("end - while\n");
        node = tm;
    }
    printf("end - sort\n");
}

/**
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
listint_t *create_listint(const int *array, size_t size)
{
    listint_t *list;
    listint_t *node;
    int *tmp;

    list = NULL;
    while (size--)
    {
        node = malloc(sizeof(*node));
        if (!node)
            return (NULL);
        tmp = (int *)&node->n;
        *tmp = array[size];
        node->next = list;
        node->prev = NULL;
        list = node;
        if (list->next)
            list->next->prev = list;
    }
    return (list);
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    listint_t *list;
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    list = create_listint(array, n);
    if (!list)
        return (1);
    print_list(list);
    printf("\n");
    insertion_sort_list(&list);
    printf("\n");
    print_list(list);
    return (0);
}