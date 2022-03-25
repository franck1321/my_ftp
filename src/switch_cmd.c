/*
** EPITECH PROJECT, 2021
** B-NWP-400-MAR-4-1-myftp-franck.minassian
** File description:
** switch_cmd
*/

#include "../include/ftp.h"


void do_cmd(int check, char *cmd, client_t *client)
{
    switch (check) {
        case 1:
            USER(cmd, client);
            break;
        case 2:
            PASS(cmd, client);
            break;
        case 3:
            CWD(cmd, client);
            break;
        case 4:
            CDUP(client);
            break;
        case 9:
            LIST(cmd, client);
            break;
        case 10:
            DELE(cmd, client);
            break;
        case 11:
            PWD(cmd, client);
            break;
        case 12:
            HELP(client);
            break;
        case 5:
            NOOP(cmd, client);
    }
    return;
}

int check_cmd(char *cmd, client_t *client)
{
    char *index = malloc(sizeof(char) * 5);
    int check = 0;

    if (my_strlen(cmd) < 3) return (84);
    if (cmd == NULL) {
        send_signal(client, 500, "Invalid command");
        return (84);
    }
    index = strncpy(index, cmd, 4);
    strcmp(index, "USER") == 0 ? check = 1: 0;
    strcmp(index, "PASS") == 0 ? check = 2: 0;
    strcmp(index, "CWD ") == 0 || strcmp(index, "CWD\n") == 0? check = 3: 0;
    strcmp(index, "CDUP") == 0 ? check = 4: 0;
    strcmp(index, "LIST") == 0 ? check = 9: 0;
    strcmp(index, "DELE") == 0 ? check = 10: 0;
    if (strcmp(index, "PWD ") == 0 || strcmp(index, "PWD") == 0) check = 11;
    strcmp(index, "NOOP") == 0 ? check = 5: 0;
    strcmp(index, "HELP") == 0 ? check = 12: 0;
    if (strcmp(index, "QUIT") == 0) return (-1);
    check != 0 ? do_cmd(check, cmd, client) : 
    send_signal(client, 500, "Invalid command");
    free(index);
    return (0);
}