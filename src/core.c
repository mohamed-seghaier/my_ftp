/*
** EPITECH PROJECT, 2019
** core.c
** File description:
** oui
*/

#include "../include/my.h"

client_t *new_element(int client)
{
    client_t *element = malloc(sizeof(*element));

    if (element == NULL)
        return (element);
    element->next = NULL;
    element->id_client = NULL;
    element->pwd_client = NULL;
    element->id = client;
    element->log = 0;
    element->opt = 0;
    return (element);
}

int new_element_a(client_t *list, int client)
{
    client_t *element = malloc(sizeof(*element));
    client_t *move = list;

    if (!element)
        return (-1);
    element->id_client = NULL;
    element->pwd_client = NULL;
    element->next = NULL;
    element->id = client;
    element->log = 0;
    element->opt = 0;
    while (move->next != NULL) {
        move = move->next;
    }
    move->next = element;
    return (1);
}

int delete_element(client_t *list, client_t *client)
{
    client_t *move = list;

    if (client->id_client != NULL || client->pwd_client != NULL) {
        if (client->id_client != NULL)
            free(client->id_client);
        if (client->pwd_client != NULL)
            free(client->pwd_client);
    }
    if (client->next) {
        for (; move && move->id != client->id; move = move->next);
        move->next = move->next->next;
        free(client);
    }
    else {
        for (; move->next; move = move->next);
        move->next = NULL;
        free(client);
    }
    return (0);
}

client_t *get_client(client_t *list, int client)
{
    client_t *move = list;

    for (; move; move = move->next) {
        if (move->id == client) {
            return (move);
        }
    }
    return (NULL);
}

int handle_list(node_t *list, int client)
{
    if (!list || !list->node) {
        list->node = new_element(client);
        if (!list->node)
            return (-1);
    }
    else
        return (new_element_a(list->node, client));
    return (1);
}