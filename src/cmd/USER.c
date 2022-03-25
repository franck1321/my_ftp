/*
** EPITECH PROJECT, 2021
** B-NWP-400-MAR-4-1-myftp-franck.minassian
** File description:
** USER
*/

#include "../../include/ftp.h"

void USER(char *cmd, client_t *client)
{
    char *arg;

    if (my_strlen(cmd) <= 6)
        return;
    arg = reduce_cmd(cmd, 4);
    if (client->user == true) {
        send_signal(client, 230, "Already connected");
        return;
    }
    if (my_strlen(arg) == 0) {
        send_signal(client, 230, "Enougth parameters");
        client->user = false;
        return;
    }
    if (strcmp("Anonymous", arg) != 0) {
        send_signal(client, 331, "Bad username");
        client->user = false;
        return;
    }
    send_signal(client, 331, "User name okay, need password.");
    client->user = true;
    return;
}