/*
** EPITECH PROJECT, 2021
** B-NWP-400-MAR-4-1-myftp-franck.minassian
** File description:
** CDUP
*/

#include "../../include/ftp.h"

void CDUP(client_t *client)
{
    if (client->co == false) {
        send_signal(client, 530, "You must be connected to do that command");
        return;
    }
    if (chdir("../") == -1)
        send_signal(client, 550, "Can't back");
    else
        send_signal(client, 250, "The directory was update");
}