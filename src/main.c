/*
** EPITECH PROJECT, 2021
** B-NWP-400-MAR-4-1-myftp-franck.minassian
** File description:
** main
*/

#include "../include/ftp.h"

int main(int ac, char **av)
{
    serv_t *serv = malloc(sizeof(serv_t));
    int loo = 0;

    if (av[1] && (strcmp("-h", av[1]) == 0 || strcmp("--help", av[1]) == 0)) {
        help();
        return (0);
    }
    if (ac != 3) {
        help();
        return (84);
    }
    if (connexion(av, serv) == 84)
        return (84);
    loo = loop(serv);
    if (loo == 84)
        return (84);
    if (loo == -1) {
        close(serv->socket);
        free(serv);
        return (0);
    }
    free(serv);
    return (0);
}