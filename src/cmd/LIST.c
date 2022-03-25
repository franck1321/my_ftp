/*
** EPITECH PROJECT, 2021
** B-NWP-400-MAR-4-1-myftp-franck.minassian
** File description:
** LIST
*/

#include "../../include/ftp.h"

void print_file(char *path, client_t *client)
{
    DIR *dir;

    if (path == NULL) {
        path = malloc(sizeof(char) * BUFF_SIZE);
        getcwd(path, BUFF_SIZE);
    }
    dir = opendir(path);
    if (dir == NULL)
        send_signal(client, 999, "The repository doesn't exist");
    else {
        send_signal(client, 150, "Open repo to read file");
        send_signal(client, 226, "Close repo");
    }
}

void LIST(char *cmd, client_t *client)
{
    if (client->co == false) {
        send_signal(client, 530, "You must be connected to do that command");
        return;
    } 
    cmd = reduce_cmd(cmd, 4);
    print_file(cmd, client);
    free(cmd);
}