#include "lists.h"
#include <stdlib.h>


listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
    listint_t *current;

    /*Create node*/
    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);

    new->n = number;

    /*Managing list empty or head insertion*/
    if (*head == NULL || (*head)->n >= number)
    {
        new->next = *head;
        *head = new;
        return (new);
    }

    /*Range list*/
    current = *head;
    while (current->next != NULL && current->next->n < number)
        current = current->next;
    
    /*Insertion*/
    new->next = current->next;
    current->next = new;

    return (new);	
}