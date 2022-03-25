/*
** EPITECH PROJECT, 2021
** B-NWP-400-MAR-4-1-myftp-franck.minassian
** File description:
** connecxion
*/

#include "../include/ftp.h"

int connexion(char **av, serv_t *serv)
{
    int i = 0;

    if (check_nbr(av[1]) == false)
        return (84);
    serv->port = atoi(av[1]);
    serv->addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv->addr.sin_family = AF_INET;
    serv->addr.sin_port = htons(serv->port);
    if ((serv->socket = socket(serv->addr.sin_family, SOCK_STREAM, 0)) == -1)
        return (84);
    if (bind(serv->socket, (struct sockaddr *)&serv->addr, 
    sizeof(serv->addr)) == -1) {
        printf("bind(): can't bind\n");
        return (84);
    }
    if (setsockopt(serv->socket, SOL_SOCKET, SO_REUSEADDR, &i, sizeof(int)) == -1)
        return (84);
    if (listen(serv->socket, 10) == -1)
        return (84);
    return (0);
}