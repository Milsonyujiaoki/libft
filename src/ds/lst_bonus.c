#include "libft.h"
#include <stdlib.h>

/*
** =========================================================
** linked list (t_list) — implementation
** =========================================================
*/

t_list  *ft_lstnew(void *content)
{
    t_list *node;

    node = (t_list *)malloc(sizeof(t_list));
    if (!node)
        return (NULL);
    node->content = content;
    node->next = NULL;
    return (node);
}

void    ft_lstadd_front(t_list **lst, t_list *new_node)
{
    if (!lst || !new_node)
        return ;
    new_node->next = *lst;
    *lst = new_node;
}

int ft_lstsize(t_list *lst)
{
    int size;

    size = 0;
    while (lst)
    {
        size++;
        lst = lst->next;
    }
    return (size);
}

t_list  *ft_lstlast(t_list *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next)
        lst = lst->next;
    return (lst);
}

void    ft_lstadd_back(t_list **lst, t_list *new_node)
{
    t_list *last;

    if (!lst || !new_node)
        return ;
    if (!*lst)
    {
        *lst = new_node;
        return ;
    }
    last = ft_lstlast(*lst);
    last->next = new_node;
}

void    ft_lstdelone(t_list *lst, void (*del)(void *))
{
    if (!lst)
        return ;
    if (del)
        del(lst->content);
    free(lst);
}

void    ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list *next;

    if (!lst)
        return ;
    while (*lst)
    {
        next = (*lst)->next;
        ft_lstdelone(*lst, del);
        *lst = next;
    }
}

void    ft_lstiter(t_list *lst, void (*f)(void *))
{
    if (!f)
        return ;
    while (lst)
    {
        f(lst->content);
        lst = lst->next;
    }
}

t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *new_list;
    t_list *node;
    void   *mapped;

    if (!f)
        return (NULL);
    new_list = NULL;
    while (lst)
    {
        mapped = f(lst->content);
        node = ft_lstnew(mapped);
        if (!node)
        {
            if (del)
                del(mapped);
            ft_lstclear(&new_list, del);
            return (NULL);
        }
        ft_lstadd_back(&new_list, node);
        lst = lst->next;
    }
    return (new_list);
}
