#include "libft.h"

/*
** =========================================================
**  linked list (s_list) — implementation
** =========================================================
*/

t_list  *ft_lstnew(void *content);
void    ft_lstadd_front(t_list **lst, t_list *new_node);
int     ft_lstsize(t_list *lst);
t_list  *ft_lstlast(t_list *lst);
void    ft_lstadd_back(t_list **lst, t_list *new_node);
void    ft_lstdelone(t_list *lst, void (*del)(void *));
void    ft_lstclear(t_list **lst, void (*del)(void *));
void    ft_lstiter(t_list *lst, void (*f)(void *));
t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));