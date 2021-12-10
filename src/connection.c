/*
** EPITECH PROJECT, 2019
** connection
** File description:
** oui
*/

#include "../include/my.h"

void start_connection(int socket, fd_set *first, fd_set *second, node_t *node)
{
    int client = 0;

    for (int tmp = 0; tmp < FD_SETSIZE; tmp += 1) {
        if (!FD_ISSET(tmp, second))
            continue;
        else if (tmp == socket) {
            client = new_joueur(socket, node);
            if (client == CRASH_ERROR)
                sigint_function(socket);
            FD_SET(client, first);
            write(client, "220\n", 4);
        } else {
            if (user_entry(tmp, node->node, node->d) == USER_EXIT)
                FD_CLR(tmp, first);
        }
    }
}

void sigint_function(int socket)
{
    close(socket);
    my_printf("Exiting...\n");
    exit(0);
}

int new_joueur(int socket, node_t *node)
{
    struct sockaddr_in client_s;
    socklen_t len = sizeof(client_s);
    int a = 0;

    a = accept(socket, (struct sockaddr *)&client_s, &len);
    if (a == -1)
        return (-1);
    else if (handle_list(node, a) == -1)
        return (CRASH_ERROR);
    return (a);
}