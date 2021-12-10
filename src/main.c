/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** oui
*/

#include "../include/my.h"

int main(int argc, char **argv)
{
    struct sockaddr_in serv_addr;
    node_t node;
    int i = 0;
    int socket = 0;

    if ((i = errorer(argc, argv)) == 1 || (i = errorer(argc, argv)) == -1)
        return (i);
    if ((socket = create_socket(argv, &serv_addr)) == -1)
        return (-1);
    return (i = serveur(argv, socket, &serv_addr, &node));
}

int serveur(char **argv, int socket, struct sockaddr_in *sock, node_t *node)
{
    fd_set first;
    fd_set second;
    struct timeval time;

    node->node = NULL;
    node->d = argv[1];
    sock = sock;
    signal(SIGINT, sigint_function);
    FD_ZERO(&first);
    FD_SET(socket, &first);
    time.tv_sec = 15;
    for (int tmp = 0; "Dali";) {
        second = first;
        tmp = select(FD_SETSIZE, &second, NULL, NULL, &time);
        if (tmp == -1)
            perror("select()");
        else 
            start_connection(socket, &first, &second, node);
    }
    return (0);
}

int errorer(int argc, char **argv)
{
    DIR *dir;

        if (argc == 3) {
        for (int i = 0; argv[1][i]; i++) {
            if (argv[1][i] < '0' || argv[1][i] > '9')
                return (-1);
        }
        dir = opendir(argv[2]);
        if (!dir)
            return (-1);
        closedir(dir);
    }
    else
        return (print_help(argc, argv));
    return (0);
}

int print_help(int argc, char **argv)
{
    if (argc <= 1 || argc >= 3)
        return (-1);
    else if (argc == 2 || strcompar(argv[1], "-help") == 1) {
        my_printf("USAGE: %s port path\n", argv[1]);
        my_printf("\tport is the port number on which the server socket ");
        my_printf("listens\n");
        my_printf("\tpath is the path to the home directory for the Anonymous ");
        my_printf("user\n");
    }
    return (0);
}