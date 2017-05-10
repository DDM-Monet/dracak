#include <stdio.h> /* for printf */
#include <stdlib.h> /* for malloc */

typedef struct ns
{
  int data;
  struct ns *next;
} node;

/* add on top */
node *list_add (node **p, int i)
{
  node *n = NULL;
  if (p) {
    /* you normally don't cast a return value for malloc */
    n = malloc(sizeof(node));
    if (n) {
      n->data = i;
      n->next = *p;
      *p = n;
    }
  }
  return n;
}

/* add on bottom */
node *list_add_bottom (node **p, int i)
{
  node *n = NULL;
  if (p) {
    n = malloc(sizeof(node));
    if (n) {
      n->data = i;
      n->next = NULL;
      if (*p) {
        node *m = *p;
        while (m->next) m = m->next;
        m->next = n;
      } else {
        *p = n;
      }
    }
  }
  return n;
}

/* add on index position */
node *list_insert_at (node **p, int i, int index)
{
  node *n = NULL;
  if (p) {
    if (*p) {
      /* if *p is not empty */
      node *r = NULL;
      node *s = *p;
      int idx = 0;
      while (s) {
        if (idx == index) {
          /* insert on this position */
          n = malloc(sizeof(node));
          if (n) {
            n->data = i;
            if (r) {
              /* insert between r and r->next */
              n->next = r->next;
              r->next = n;
            } else {
              /* insert on top */
              n->next = *p;
              *p = n;
            }
          }
          return n;
        }
        idx++;
        r = s;
        s = s->next;
      }
      if (idx == index) {
        /* insert on bottom */
        n = malloc(sizeof(node));
        if (n) {
          n->data = i;
          n->next = NULL;
          r->next = n;
        }          
      }
    } else {
      /* if *p is empty */
      if (!index) {
        /* insert only on top */
        n = malloc(sizeof(node));
        if (n) {
          n->data = i;
          n->next = NULL;
          *p = n; 
        }
      }
    }
  }
  return n;
}

/* remove head */
void list_remove (node **p)
{
  if (p && *p) {
    node *n = *p;
    *p = (*p)->next;
    free(n);
  }
}

node **list_search (node **n, int i)
{
  if (n) {
    while (*n) {
      if ((*n)->data == i) return n;
      n = &(*n)->next;
    }
  }
  return NULL;
}

void list_print (node *n)
{
  if (!n) {
    printf("list is empty\n");
    return;
  }
  while (n) {
    printf("print %p %p %d\n", n, n->next, n->data);
    n = n->next;
  }
}

int main (void)
{
  node *n = NULL;

  list_add(&n, 0); /* list: 0 */
  list_print(n);
  list_add(&n, 1); /* list: 1 0 */
  list_print(n);
  list_add(&n, 2); /* list: 2 1 0 */
  list_add(&n, 3); /* list: 3 2 1 0 */
  list_add(&n, 4); /* list: 4 3 2 1 0 */
  list_print(n);

  /* insert (5) at position index 0, list: 5 4 3 2 1 0 */
  list_insert_at(&n, 5, 0);
  /* insert (25) at position index 3, list: 5 4 3 25 2 1 0 */
  list_insert_at(&n, 25, 3);
  /* insert (-1) at position index 7, list: 5 4 3 25 2 1 0 -1 */
  list_insert_at(&n, -1, 7);
  list_print(n);

  list_remove(list_search(&n, -1)); /* remove cell containing -1 */
  list_remove(list_search(&n, 25)); /* remove cell containing 25 */
  list_remove(list_search(&n, 5));  /* remove cell containing 5 */
  list_remove(&n);            /* remove first (4) */
  list_remove(&n->next);      /* remove new second (2) */
  list_remove(list_search(&n, 1)); /* remove cell containing 1 (first) */
  list_remove(&n->next);      /* remove second to last node (0) */
  list_remove(&n);            /* remove last (3) */
  list_print(n);

  return 0;
}
