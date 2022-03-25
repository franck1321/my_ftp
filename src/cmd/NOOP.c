/*
** EPITECH PROJECT, 2021
** B-NWP-400-MAR-4-1-myftp-franck.minassian
** File description:
** NOOP
*/

#include "../../include/ftp.h"

void NOOP(char *cmd, client_t *client)
{
    char *arg = reduce_cmd(cmd, 4);

    if (arg == NULL && client->co == true) {
        send_signal(client, 200, "Good Command");
    } else {
        send_signal(client, 530, "Not logged");
    }
}