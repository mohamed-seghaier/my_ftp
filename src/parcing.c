/*
** EPITECH PROJECT, 2019
** parcing
** File description:
** oui
*/

#include "../include/my.h"

int surparcer(int socket, char **tab, client_t *client)
{
    if (strcompar(tab[0], "RETR") == 1) {
        if (client->opt == PASSIV)
            write(socket, "550 Can't open file.\n", 25);
        else
            write(socket, "425 PASV or PORT must be selected.\n", 35);
        return (1);
    }
    else if (strcompar(tab[0], "DELE") == 1) {
        write(socket, "550 Permission denied.\n", 23);
        return (1);
    }
    tab = tab;
    if (strcompar(tab[0], "LIST") == 1) {
        write(socket, "425 PASV or PORT must be selected.\n", 35);
        return (1);
    }
    else if (strcompar(tab[0], "CDUP") == 1) {
        write(socket, "250 Directory changed.\n", 23);
        return (1);
    }
    return (0);
}

int more_parcing(int socket, char **tab, client_t *client, char *str)
{
    if (strcompar(tab[0], "PASV") == 1) {
        client->opt = PASSIV;
        write(socket, "227 PASSIV MODE OK.\n", 20);
        return (1);
    }
    else if (strcompar(tab[0], "PORT") == 1) {
        write(socket, "500 Illegal PORT command.\n", 26);
        client->opt = ACTIV;
        return (1);
    }
    tab = tab;
    if (strcompar(tab[0], "PWD") == 1) {
        dprintf(socket, "257 \"%s\"\n", str);
        return (1);
    }
    else if (strcompar(tab[0], "STOR") == 1) {
        write(socket, "550 Permission denied.\n", 23);
        return (1);
    }
    else
        return (surparcer(socket, tab, client));
}

int parse_all_commands(int socket, char **tab, client_t *client, char *d)
{
    if (strcompar(tab[0], "HELP") == 1) {
        write(socket, "214-Availables commands are:\n", 29);
        write(socket, "\tUSER PASS CWD CDUP QUIT DELE PWD\n", 34);
        write(socket, "\tPASV PORT HELP NOOP RETR STOR LIST\n", 36);
        write(socket, "214 Help OK.\n", 13);
        return (1);
    }
    else if (strcompar(tab[0], "NOOP") == 1) {
        write(socket, "220 NOOP OK.\n", 13);
        return (1);
    }
    else {
        return (more_parcing(socket, tab, client, d));
    }
    return (0);

}