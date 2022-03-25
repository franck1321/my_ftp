/*
** EPITECH PROJECT, 2021
** B-NWP-400-MAR-4-1-myftp-franck.minassian
** File description:
** DELE
*/

#include "../../include/ftp.h"

void DELE(char *cmd, client_t *client)
{
    char *path = reduce_cmd(cmd, 4);

    if (client->co == false) {
        send_signal(client, 530, "You must be connected to do that command");
        return;
    }
    if (strlen(path) <= 1) {
        send_signal(client, 501, "syntax error");
        return;
    }
    if (remove(path) == 0)
        send_signal(client, 250, "File deleted");
    else
        send_signal(client, 550, "File don't found");
    free(path);
}