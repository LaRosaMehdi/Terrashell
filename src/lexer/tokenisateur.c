#include "../../include/include.h"


//write a function that takes a string and returns a list of tokens (t_type)

//t_token is an enum with the following values: PIPE, REDIR, WORD, SPACE, END

//the list should be a list of t_list, where each t_list contains a t_token and a char*

//the list should be terminated by a t_list with type END

//the list should be freed by the caller

t_token *init_type(int token, char *value)
{
    t_token *type;

    type = malloc(sizeof(t_token));
    if (!type)
    {
        printf("malloc error\n");
        exit(-84);
    }
    type->value = value;
    type->t_type = token;

    return (type);
}

t_token *tokenizateur(t_list *list)
{
    while(list)
    {
        if (ft_strcmp(list->content, "|") == 0)
        {
            printf("pipe\n");
            return (init_type(PIPE, list->content));
        }
        else if (ft_strcmp(list->content, ">") == 0)
        {
            printf("redir\n");
            return (init_type(REDIR, list->content));
        }
        else if (ft_strcmp(list->content, "<") == 0)
        {
            printf("rredir\n");
            return (init_type(REDIR, list->content));
        }
        else if (ft_strcmp(list->content, " ") == 0)
        {
            printf("quote\n");
            return (init_type(QUOTE, list->content));
        }
        else if (ft_strcmp(list->content, ";") == 0)
        {
            printf("point virgule\n");
            return (init_type(END, list->content));
        }
        else
        {
            printf("word\n");
            printf("content: %s\n", list->content);
            return (init_type(WORD, list->content));
        }
    }
    return (NULL);
}
