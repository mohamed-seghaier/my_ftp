/*
** EPITECH PROJECT, 2019
** other.C
** File description:
** other
*/

#include "../include/my.h"

int others_commands(int socket, char **tab, client_t *client, char *d)
{
    if (client->log == 0) {
        write(socket, "530 Login with USER and PASS.\n", 30);
        return (-1);
    }
    else if (parse_all_commands(socket, tab, client, d) > 0)
        return (1);
    else {
        write(socket, "500 Unknown command.\n", 21);
        return (-1);
    }
    return (0);
}

int check_user(int socket, char *str, client_t *client, int opt)
{
    if (opt == 0) {
        if (!str || str[0] == 0) {
            write(socket, "530 Permission denied.\n", 23);
            return (-1);
        }
        write(socket, "331 Specify the password.\n", 26);
        client->id_client = strdup(str);
    }
    else {
        if (client->id_client == NULL) {
            write(socket, "503 Login with USER first.\n", 27);
            return (-1);
        }
        else if (strcompar(client->id_client, "Anonymous") != 1) {
            write(socket, "530 Bad login.\n", 15);
            free(client->id_client);
            return (-1);
        }
        write(socket, "230 Logged in.\n", 15);
    }
    return (0);
}

int start(int socket, char **tab, client_t *list, client_t *client, char *d)
{
    if (!client) {
        return (-1);
    }
    else if (strcompar(tab[0], "QUIT") == 1) {
        delete_element(list, client);
        write(socket, "221 Goodbye.\n", 13);
        close(socket);
        return (USER_EXIT);
    }
    else {
        if (strcompar(tab[0], "USER") == 1)
            return (check_user(socket, tab[1], client, 0));
        else if (strcompar(tab[0], "PASS") == 1)
            return (check_user(socket, tab[1], client, 1));
        else {
            others_commands(socket, tab, client, d);
        }
    }
    return (0);
}

int user_entry(int socket, client_t *list, char *d)
{
    char **tab = NULL;
    char buff[RD_SIZE];
    int r = 0;

    r = read(socket, buff, RD_SIZE);
    if (r == -1) {
        perror("read()");
        return (-1);
    }
    buff[r] = 0;
    tab = my_str_to_array(buff, " \r\n");
    if (!tab[0])
        return (-1);
    r = start(socket, tab, list, get_client(list, socket), d);
    if (r < 0)
        return (r);
    get_client(list, socket)->log = 1;
    return (0);
}

int create_socket(char **argv, struct sockaddr_in *addr_serv)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    int a = 0;

    if (sock == -1) {
        perror("socket()");
        return (sock);
    }
    addr_serv->sin_family = AF_INET;
    addr_serv->sin_addr.s_addr = htonl(INADDR_ANY);
    addr_serv->sin_port = htons(my_strlen(argv[1]));
    a = bind(sock, (struct sockaddr *)addr_serv, sizeof(*addr_serv));
    if (a == -1) {
        perror("bind()");
        return (a);
    }
    a = listen(sock, 222);
    if (a == -1) {
        perror("bind()");
        return (a);
    }
    return (sock);
}