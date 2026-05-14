#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

/*
** =========================================================
** Tests:linked list API (t_list / ft_lst*)
** =========================================================
*/

static int  s_pass = 0;
static int  s_fail = 0;

#define CHECK(expr) \
    do { \
        if (expr) { printf("  [PASS] %s\n", #expr); s_pass++; } \
        else      { printf("  [FAIL] %s  (line %d)\n", #expr, __LINE__); s_fail++; } \
    } while (0)

/* ── Helpers ─────────────────────────────────────────── */

static int *new_int(int value)
{
    int *p;

    p = (int *)malloc(sizeof(int));
    if (!p)
        return (NULL);
    *p = value;
    return (p);
}

static int  g_del_calls = 0;

static void del_int(void *ptr)
{
    g_del_calls++;
    free(ptr);
}

static void iter_add_one(void *content)
{
    int *p;

    p = (int *)content;
    if (p)
        *p += 1;
}

static void *map_double(void *content)
{
    int *src;
    int *dst;

    src = (int *)content;
    if (!src)
        return (NULL);
    dst = new_int((*src) * 2);
    return (dst);
}

/* ── ft_lstnew ───────────────────────────────────────── */

static void test_lstnew(void)
{
    int    *v;
    t_list *n;

    printf("--- ft_lstnew ---\n");
    v = new_int(42);
    CHECK(v != NULL);
    n = ft_lstnew(v);
    CHECK(n != NULL);
    CHECK(n->content == v);
    CHECK(n->next == NULL);
    ft_lstdelone(n, del_int);
}

/* ── ft_lstadd_front / ft_lstsize / ft_lstlast ──────── */

static void test_add_front_size_last(void)
{
    t_list *lst;
    t_list *n1;
    t_list *n2;
    t_list *n3;

    printf("--- ft_lstadd_front / ft_lstsize / ft_lstlast ---\n");
    lst = NULL;
    n1 = ft_lstnew(new_int(1));
    n2 = ft_lstnew(new_int(2));
    n3 = ft_lstnew(new_int(3));

    CHECK(n1 != NULL && n2 != NULL && n3 != NULL);
    ft_lstadd_front(&lst, n1); /* [1] */
    ft_lstadd_front(&lst, n2); /* [2, 1] */
    ft_lstadd_front(&lst, n3); /* [3, 2, 1] */

    CHECK(ft_lstsize(lst) == 3);
    CHECK(*(int *)lst->content == 3);
    CHECK(*(int *)ft_lstlast(lst)->content == 1);
    CHECK(ft_lstlast(NULL) == NULL);

    ft_lstclear(&lst, del_int);
    CHECK(lst == NULL);
}

/* ── ft_lstadd_back ──────────────────────────────────── */

static void test_add_back(void)
{
    t_list *lst;
    t_list *n1;
    t_list *n2;
    t_list *n3;

    printf("--- ft_lstadd_back ---\n");
    lst = NULL;
    n1 = ft_lstnew(new_int(10));
    n2 = ft_lstnew(new_int(20));
    n3 = ft_lstnew(new_int(30));

    CHECK(n1 != NULL && n2 != NULL && n3 != NULL);
    ft_lstadd_back(&lst, n1); /* [10] */
    ft_lstadd_back(&lst, n2); /* [10, 20] */
    ft_lstadd_back(&lst, n3); /* [10, 20, 30] */

    CHECK(ft_lstsize(lst) == 3);
    CHECK(*(int *)lst->content == 10);
    CHECK(*(int *)ft_lstlast(lst)->content == 30);

    ft_lstclear(&lst, del_int);
    CHECK(lst == NULL);
}

/* ── ft_lstdelone / ft_lstclear ─────────────────────── */

static void test_delone_clear(void)
{
    t_list *lst;
    t_list *n;

    printf("--- ft_lstdelone / ft_lstclear ---\n");
    g_del_calls = 0;

    n = ft_lstnew(new_int(99));
    CHECK(n != NULL);
    ft_lstdelone(n, del_int);
    CHECK(g_del_calls == 1);

    lst = NULL;
    ft_lstadd_back(&lst, ft_lstnew(new_int(1)));
    ft_lstadd_back(&lst, ft_lstnew(new_int(2)));
    ft_lstadd_back(&lst, ft_lstnew(new_int(3)));
    CHECK(ft_lstsize(lst) == 3);

    ft_lstclear(&lst, del_int);
    CHECK(lst == NULL);
    CHECK(g_del_calls == 4);
}

/* ── ft_lstiter ──────────────────────────────────────── */

static void test_iter(void)
{
    t_list *lst;

    printf("--- ft_lstiter ---\n");
    lst = NULL;
    ft_lstadd_back(&lst, ft_lstnew(new_int(1)));
    ft_lstadd_back(&lst, ft_lstnew(new_int(2)));
    ft_lstadd_back(&lst, ft_lstnew(new_int(3)));

    ft_lstiter(lst, iter_add_one); /* [2, 3, 4] */

    CHECK(*(int *)lst->content == 2);
    CHECK(*(int *)lst->next->content == 3);
    CHECK(*(int *)lst->next->next->content == 4);

    ft_lstclear(&lst, del_int);
}

/* ── ft_lstmap ───────────────────────────────────────── */

static void test_map(void)
{
    t_list *src;
    t_list *dst;

    printf("--- ft_lstmap ---\n");
    src = NULL;
    ft_lstadd_back(&src, ft_lstnew(new_int(2)));
    ft_lstadd_back(&src, ft_lstnew(new_int(4)));
    ft_lstadd_back(&src, ft_lstnew(new_int(6)));

    dst = ft_lstmap(src, map_double, del_int);
    CHECK(dst != NULL);
    CHECK(ft_lstsize(dst) == 3);

    CHECK(*(int *)src->content == 2);
    CHECK(*(int *)src->next->content == 4);
    CHECK(*(int *)src->next->next->content == 6);

    CHECK(*(int *)dst->content == 4);
    CHECK(*(int *)dst->next->content == 8);
    CHECK(*(int *)dst->next->next->content == 12);

    ft_lstclear(&src, del_int);
    ft_lstclear(&dst, del_int);
}

int main(void)
{
    printf("========================================\n");
    printf("  libft — 42 bonus t_list tests\n");
    printf("========================================\n");
    test_lstnew();
    test_add_front_size_last();
    test_add_back();
    test_delone_clear();
    test_iter();
    test_map();
    printf("----------------------------------------\n");
    printf("  Results: %d passed, %d failed\n", s_pass, s_fail);
    printf("========================================\n");
    return (s_fail > 0 ? 1 : 0);
}
