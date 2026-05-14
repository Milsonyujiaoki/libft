#ifndef LIBFT_DS_LIST_H
# define LIBFT_DS_LIST_H

# include "../core/types.h"
# include "../core/defs.h"

/*
** =========================================================
** Singly Linked List
**
** Characteristics:
**   - O(1) push_front, pop_front
**   - O(n) push_back, get, insert_at, remove_at
**   - O(1) size (tracked)
**   - O(n) extra memory from node allocations (pointer overhead)
**
** Ownership:
**   The list stores void * pointers and does NOT own them by
**   default.  Use ft_list_destroy_deep() with a destructor to
**   free the pointed-to data.
** =========================================================
*/

typedef struct s_list_node
{
    void               *data;
    struct s_list_node *next;
}   t_list_node;

typedef struct s_list
{
    t_list_node *head;
    t_usize      size;
}   t_list;

/*
** ──── Lifecycle ────────────────────────────────────────── */

t_list      *ft_list_create(void);
void         ft_list_destroy(t_list *list);
void         ft_list_destroy_deep(t_list *list, t_free_fn free_fn);

/*
** ──── Insertion ────────────────────────────────────────── */

t_ft_status  ft_list_push_front(t_list *list, void *data);
t_ft_status  ft_list_push_back(t_list *list, void *data);
t_ft_status  ft_list_insert_at(t_list *list, t_usize index, void *data);

/*
** ──── Removal ──────────────────────────────────────────── */

/* Removes and returns the front element's data pointer. */
void        *ft_list_pop_front(t_list *list);

/* Removes and returns the element at index.  Caller owns the data. */
void        *ft_list_remove_at(t_list *list, t_usize index);

/*
** ──── Access ───────────────────────────────────────────── */

void        *ft_list_front(const t_list *list);
void        *ft_list_get(const t_list *list, t_usize index);

/*
** ──── Query ────────────────────────────────────────────── */

t_usize      ft_list_size(const t_list *list);
t_bool       ft_list_empty(const t_list *list);

/*
** ──── Traversal ────────────────────────────────────────── */

void         ft_list_foreach(t_list *list, t_visit_fn fn, void *ctx);

/*
** ──── Search ───────────────────────────────────────────── */

/* Returns the first node whose data satisfies pred, or NULL. */
t_list_node *ft_list_find(const t_list *list, t_pred_fn pred,
                const void *ctx);

/*
** ──── Mutation ─────────────────────────────────────────── */

void         ft_list_reverse(t_list *list);

#endif /* LIBFT_DS_LIST_H */
