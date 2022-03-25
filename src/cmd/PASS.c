/*
** EPITECH PROJECT, 2021
** B-NWP-400-MAR-4-1-myftp-franck.minassian
** File description:
** PASS
*/

#include "../../include/ftp.h"

void PASS(char *cmd, client_t *client)
{
    int len = my_strlen(cmd);

    if (client->co == true) {
        send_signal(client, 230, "Already connected");
        return;
    }
    if (client->user == false) {
        send_signal(client, 503, "You must make USER before PASS");
        return;
    }
    for(int i = 4; i != len;) {
        if (cmd[i] == ' ' || cmd[i] == '\r' || cmd[i] == '\n')
            i++;
        else {
            send_signal(client, 430, "Bad Password");
            client->co = false;
            return;
        }   
    }
    send_signal(client, 230, "Good password Connexted");
    client->co = true;
    return;
}