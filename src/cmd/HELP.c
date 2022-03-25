/*
** EPITECH PROJECT, 2021
** B-NWP-400-MAR-4-1-myftp-franck.minassian
** File description:
** HELP
*/

#include "../../include/ftp.h"

void HELP(client_t *client)
{
    if (client->co == false) {
        send_signal(client, 530, "You must be connected to do that command");
    } else {
        send_signal(client, 214, "Help...");
    }
    return;
}