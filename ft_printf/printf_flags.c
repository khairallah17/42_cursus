#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char    *next_pad(char *s, char *flag)
{
    while(1)
        if(*(s++) == *flag)
            return (s);
    return (NULL);
}

char *check_padding(char *s, char *pad, int *number)
{
    int     i = 0;
    char    *t;
    int     s_len = strlen(s);
    
    t = (char *)malloc(sizeof(char) * 10);
    if(*s == '-' || *s == ' ' || *s == '0')
    {
        *pad = *s;
        s = next_pad(s, pad);
        for(int i = 0 ; i < s_len ; i++)
        {
            if ((*s != '\0') && (*s >= '0' && *s <= '9'))
                t[i] = *s;
            else
            {
                t[i] = '\0';
                *(++pad) = '\0';
                *number = atoi(t);
                return (s);
            }
            s++;
        }
    }

    return (0);
}

int main()
{
    char    *pad;
    pad = (char *)malloc(sizeof(char) * 10);
    int padding; 
    char *t = check_padding("010d", pad, &padding);
    int number = padding;
    padding -= 2;
    int i;

    i = 0;
    while(i < padding)
    {
        if(pad[0] == '-')
            printf("space ");
        if(pad[0] == '0')
            printf("0");
        i++;
    }
    return 0;
}