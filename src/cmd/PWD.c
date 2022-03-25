/*
** EPITECH PROJECT, 2021
** B-NWP-400-MAR-4-1-myftp-franck.minassian
** File description:
** PWD
*/

#include "../../include/ftp.h"

void PWD(char *cmd, client_t *client)
{
    char *path = malloc(sizeof(char) * BUFF_SIZE);
    char *msg = NULL;

    if (client->co == false) {
        send_signal(client, 230, "You must be connected to do that command");
        return;
    }
    for (int i = 3; cmd[i]; i++) {
        if (cmd[i] != ' ') {
            send_signal(client, 999, "Invalid command pwd");
            return;
        }
    }
    getcwd(path, BUFF_SIZE);
    msg = malloc(sizeof(char) * my_strlen(path));
    snprintf(msg, my_strlen(path) + my_strlen(path) + 1, "%s", path);
    client->path = path;
    send_signal(client, 257, msg);
    free(path);
    free(msg);
}