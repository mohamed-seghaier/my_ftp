/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** header
*/

#ifndef MY_H_
#define MY_H_

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <signal.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <sys/socket.h>

//MACCRON

#define RD_SIZE 512
#define CRASH_ERROR -12
#define USER_EXIT -20
#define PASSIV 38
#define ACTIV 69


// ELEMENT

typedef struct client_s {
    char *id_client;
    char *pwd_client;
    char *str;
    struct client_s *next;
    int id;
    int log;
    int opt;
    int tmp;
} client_t;

// LIST

typedef struct node_s {
    client_t *node;
    char *d;
} node_t;

// PRINT

void my_putnbr(int);
void my_putstr(char *);
void my_putchar(char);
void my_sputchar(char);
void my_sputstr(char *);

void flag_d(va_list);
void flag_s(va_list);
void flag_c(va_list);

void my_ptab(int, va_list);
void my_printf(char *, ...);
int checkflag(char);


// SRC

client_t *get_client(client_t *, int);
client_t *new_element(int);
int new_element_a(client_t *, int);
int delete_element(client_t *, client_t *);
int handle_list(node_t *, int);

int main(int, char **);
int serveur(char **, int, struct sockaddr_in *sock, node_t *);
int errorer(int, char **);
int print_help(int, char **);

char **my_strtab(char *, char);
char **my_strtabtwo(char *, char);
char *remplitab(char *, char *, int, char);
int my_eolen(char *, char);

int strcompar(char *, char *);
char *my_superstrcpy(char *);
int my_strlen(char *);

int new_joueur(int, node_t *);
void sigint_function(int);
void start_connection(int, fd_set*, fd_set *, node_t *);

int surparcer(int, char **, client_t *);
int more_parcing(int, char **, client_t *, char *);
int parse_all_commands(int, char **, client_t *, char *);

int others_commands(int, char **, client_t *, char *);
int check_user(int, char *, client_t *, int);
int start(int, char **, client_t *, client_t *, char *);
int user_entry(int, client_t *, char *);
int create_socket(char **, struct sockaddr_in *);

static int my_check(char *, char);
static int count_line(char *, char *);
static char *my_cut_str(char *, char *);
char **my_str_to_array(char *, char *);

#endif /* !MY_H_ */
