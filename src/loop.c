/*
** EPITECH PROJECT, 2021
** B-NWP-400-MAR-4-1-myftp-franck.minassian
** File description:
** loop
*/

#include "../include/ftp.h"

void send_signal(client_t *client, int code, char *msg)
{
    char *cmd = malloc(3 * my_strlen(msg) + 5);

    if (code == 999)
        snprintf(cmd, 3 * my_strlen(msg) + 5, "xxx %s\r\n", msg);
    else
        snprintf(cmd, 3 * my_strlen(msg) + 10, "%d %s\r\n", code, msg);
    write(client->csock, cmd, my_strlen(cmd));
    free(cmd);
}

client_t *init_client(serv_t *serv, int sock_client, struct sockaddr_in addr)
{
    client_t *client = malloc(sizeof(client_t));

    if (client == NULL)
        return (NULL);
    client->cport = serv->port;
    client->csock = sock_client;
    client->clen = sizeof(client->caddr);
    client->caddr = addr;
    client->user = false;
    client->co = false;
    send_signal(client, 220, "Client connected");
    return (client);
}

int loop2(serv_t *serv, int sock_client, struct sockaddr_in addr)
{
    char *cmd;
    client_t *client = init_client(serv, sock_client, addr);

    if (client == NULL) return (84);
    while (1) {
        cmd = malloc(sizeof(char) * BUFF_SIZE);
        read(client->csock, cmd, BUFF_SIZE);
        // cmd = supp_char(cmd);
        if (check_cmd(cmd, client) == -1) {
            send_signal(client, 221, "Client deconected");
            break;
        }
        free(cmd);
    }
    free(client);
    close(client->csock);
    return (0);
}

int loop(serv_t *serv)
{
    struct sockaddr_in addr;
    pid_t fils;
    socklen_t slen = sizeof(addr);
    int client;

    while (1) {
        client = accept(serv->socket, (struct sockaddr *)&addr, &slen);
        if (client != -1) {
            fils = fork();
            if (fils == 0) {
                loop2(serv, client, addr);
                close(serv->socket);
                exit(0);
            } else 
                close(client);
        }
    }
    return (0);
}