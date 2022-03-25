/*
** EPITECH PROJECT, 2021
** B-NWP-400-MAR-4-1-myftp-franck.minassian
** File description:
** fct
*/

#include "../include/ftp.h"

void help(void)
{
    printf("USAGE: ./myftp port path\n\t");
    printf("port is the port number on which the server socket listens\n\t");
    printf("path is the path to the home directory for the Anonymous user\n");
}

bool check_nbr(char *str)
{
    if (str == NULL) return (false);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (false);
    }
    return (true);
}

char *reduce_cmd(char *cmd, int size)
{
    int max, i = 0;
    char *new;
    
    max = size == 4 ? 5 : 4; 
    for (int i = 0; i != max; i++, *cmd++);
    for (int i = 0; cmd[i] == ' '; i++, i--, *cmd++);
    max = 0;
    while ((cmd[max] && cmd[max] != '\0') && ((cmd[max] >= 'a' && cmd[max] <= 'z') || (cmd[max] >= 'A' && cmd[max] <= 'Z')))
        max++;
    if (max == 0)
        return (NULL);
    new = malloc(sizeof(char) * (max + 1));
    if (new == NULL) return (NULL);
    for (; i != max; i++)
        new[i] = cmd[i];
    cmd[i] = '\0';
    return (new);
}

int my_strlen(char *c)
{
    int i = 0;

    while (c[i] && (c[i] != '\0' || c[i]  != '\n' || c[i] == '\r')) i++;
    return (i);
}