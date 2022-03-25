/*
** EPITECH PROJECT, 2021
** B-NWP-400-MAR-4-1-myftp-franck.minassian
** File description:
** CWD
*/

#include "../../include/ftp.h"

void CWD(char *cmd, client_t *client)
{
    char *path = reduce_cmd(cmd, 3);

    if (client->co == false) {
        send_signal(client, 530, "You must be login");
        return;
    }
    if (path == NULL) {
        send_signal(client, 999, "The repository doesn't exist");
        return;
    }
    if (chdir(path) == 0)
        send_signal(client, 250, "Directory update");
    else
        send_signal(client, 999, "Can't update the directory");
    free(path);
}