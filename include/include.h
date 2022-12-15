#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include "../lib/libft/libft.h"
# include "../lib/gnl/get_next_line.h"

typedef struct s_env
{
	char	*name;
	char	*content;
}
t_env;

// structure liste chainée classique


// enum struct
typedef struct s_token
{ 
	enum s_type
	{
		PIPE,
		REDIR,
		WORD,
		QUOTE,
		END
	} t_type;
	char *value;
} t_token;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

//------------------------------------utils.c------------------------------------
t_list	*ft_lstnew(void *content);
t_list *ft_lstadd(t_list **alst, t_list *new);
int ft_strlen(const char *s);
char *ft_strchr(const char *s, int c);
char *ft_strsub(char const *s, unsigned int start, size_t len);
void ft_putstr(char *str);
int	ft_strcmp(char *s1, char *s2);
char **ft_split (char *str);
void afftab(char **tab);
void afflist(t_list *list, char *name);
t_token *init_type(int token, char *value);
t_token *tokenizateur(t_list *list);
//------------------------------------- main.c -------------------------------------
t_env *get_env(char **env);
t_list *lexer(t_list *str);
int main(int ac, char **av, char **env);

#endif