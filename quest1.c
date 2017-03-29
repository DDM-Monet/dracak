#include <stdio.h>
#include <stdlib.h>

#include "hrdina.h"

void zemri(struct hrdina *h) {
    int volba=0;
    printf("Chces zemrit?\n");
    printf(" 1 - ANO\n");
    printf(" 2 - NE\n");
    scanf("%d", &volba);
    if(volba != 2) {
        h->HP = -1;
    }
}
