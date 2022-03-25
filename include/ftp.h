/*
** EPITECH PROJECT, 2021
** B-NWP-400-MAR-4-1-myftp-franck.minassian
** File description:
** ftp
*/

#ifndef FTP_H_
#define FTP_H_

#include <sys/types.h>
#include <dirent.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#define BUFF_SIZE 200

typedef struct serv {
    char *path;
    int port;
    int socket;
    socklen_t len;
    struct sockaddr_in addr;
}serv_t;

typedef struct client_t {
    int cport;
    int csock;
    socklen_t clen;
    struct sockaddr_in caddr;
    char *path;
    bool user;
    bool co;
}client_t;


// fct.c
void help(void);
bool check_nbr(char *str);
char *reduce_cmd(char *cmd, int size);
int my_strlen(char *c);

// connexion.c
int connexion(char **av, serv_t *serv);

// loop.c
int loop(serv_t *serv);
void send_signal(client_t *client, int code, char *msg);

// switch_cmd.c
int check_cmd(char *cmd, client_t *client);
void do_cmd(int check, char *cmd, client_t *client);

// COMMANDE //

// HELP.c
void HELP(client_t *client);

// USER.c
void USER(char *cmd, client_t *client);

// PASS.c
void PASS(char *cmd, client_t *cleint);

// NOOP.c
void NOOP(char *cmd, client_t *client);

// CDUP.c
void CDUP(client_t *client);

// PWD.c
void PWD(char *cmd, client_t *client);

// DELE.c
void DELE(char *cmd, client_t *client);

// CWD.c
void CWD(char *cmd, client_t *client);

// LIST.c
void LIST(char *cmd, client_t *client);

#endif /* !FTP_H_ */
