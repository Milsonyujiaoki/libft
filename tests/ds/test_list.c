#include <stdio.h>
#include "libft.h"

/*
** =========================================================
** Tests: t_slist (custom singly linked list)
** =========================================================
*/

static int  s_pass = 0;
static int  s_fail = 0;

#define CHECK(expr) \
    do { \
        if (expr) { printf("  [PASS] %s\n", #expr); s_pass++; } \
        else      { printf("  [FAIL] %s  (line %d)\n", #expr, __LINE__); s_fail++; } \
    } while (0)

/* ── Lifecycle ───────────────────────────────────────── */
static void test_list_create(void)
{
    t_slist *l;

    printf("--- ft_list_create ---\n");
    l = ft_list_create();
    CHECK(l != NULL);
    CHECK(ft_list_empty(l) == true);
    CHECK(ft_list_size(l) == 0);
    ft_list_destroy(l);
}

/* ── push_front / push_back ──────────────────────────── */
static void test_list_push(void)
{
    t_slist *l;
    int      a = 1, b = 2, c = 3;

    printf("--- ft_list_push_front / push_back ---\n");
    l = ft_list_create();
    ft_list_push_back(l, &a);
    ft_list_push_back(l, &b);
    ft_list_push_back(l, &c);
    CHECK(ft_list_size(l) == 3);
    CHECK(*(int *)ft_list_front(l) == 1);
    CHECK(*(int *)ft_list_get(l, 2) == 3);

    ft_list_push_front(l, &c);
    CHECK(*(int *)ft_list_front(l) == 3);
    CHECK(ft_list_size(l) == 4);
    ft_list_destroy(l);
}

/* ── pop_front / remove_at ───────────────────────────── */
static void test_list_remove(void)
{
    t_slist *l;
    int      a = 10, b = 20, c = 30;
    int     *p;

    printf("--- ft_list_pop_front / remove_at ---\n");
    l = ft_list_create();
    ft_list_push_back(l, &a);
    ft_list_push_back(l, &b);
    ft_list_push_back(l, &c);

    p = (int *)ft_list_pop_front(l);
    CHECK(*p == 10);
    CHECK(ft_list_size(l) == 2);

    p = (int *)ft_list_remove_at(l, 0);
    CHECK(*p == 20);
    CHECK(ft_list_size(l) == 1);

    CHECK(ft_list_remove_at(l, 99) == NULL);
    ft_list_destroy(l);
}

/* ── reverse ─────────────────────────────────────────── */
static void test_list_reverse(void)
{
    t_slist *l;
    int      a = 1, b = 2, c = 3;

    printf("--- ft_list_reverse ---\n");
    l = ft_list_create();
    ft_list_push_back(l, &a);
    ft_list_push_back(l, &b);
    ft_list_push_back(l, &c);
    ft_list_reverse(l);
    CHECK(*(int *)ft_list_get(l, 0) == 3);
    CHECK(*(int *)ft_list_get(l, 1) == 2);
    CHECK(*(int *)ft_list_get(l, 2) == 1);
    ft_list_destroy(l);
}

/* ── find ────────────────────────────────────────────── */
static t_bool pred_is_20(const void *elem, const void *ctx)
{
    (void)ctx;
    return (*(const int *)elem == 20);
}

static void test_list_find(void)
{
    t_slist      *l;
    t_slist_node *node;
    int          a = 10, b = 20, c = 30;

    printf("--- ft_list_find ---\n");
    l = ft_list_create();
    ft_list_push_back(l, &a);
    ft_list_push_back(l, &b);
    ft_list_push_back(l, &c);
    node = ft_list_find(l, pred_is_20, NULL);
    CHECK(node != NULL);
    CHECK(*(int *)node->data == 20);
    ft_list_destroy(l);
}

/* ── foreach sum ─────────────────────────────────────── */
static void add_to_sum(void *elem, void *ctx)
{
    *(int *)ctx += *(int *)elem;
}

static void test_list_foreach(void)
{
    t_slist *l;
    int      a = 5, b = 10, c = 15;
    int      sum;

    printf("--- ft_list_foreach ---\n");
    l = ft_list_create();
    ft_list_push_back(l, &a);
    ft_list_push_back(l, &b);
    ft_list_push_back(l, &c);
    sum = 0;
    ft_list_foreach(l, add_to_sum, &sum);
    CHECK(sum == 30);
    ft_list_destroy(l);
}

int main(void)
{
    printf("========================================\n");
    printf("  libft — t_slist tests\n");
    printf("========================================\n");
    test_list_create();
    test_list_push();
    test_list_remove();
    test_list_reverse();
    test_list_find();
    test_list_foreach();
    printf("----------------------------------------\n");
    printf("  Results: %d passed, %d failed\n", s_pass, s_fail);
    printf("========================================\n");
    return (s_fail > 0 ? 1 : 0);
}
