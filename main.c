#include <stdio.h>
#include <stdlib.h>

#include "hrdina.h"

void stvor_hrdinu(struct hrdina* h) {
    printf("Jak se jmenujes, hrdino?\n");
    scanf("%254s", h->jmeno);
    h->HP=100;
    h->energie=100;
    h->XP=0;
    h->level=0;
    h->sila=10 + (random() % 11);
    h->stesti=10 + (random() % 11);
}

void zemri(struct hrdina *h);

int main(int argc, char** argv) {
    struct hrdina h;
    
    stvor_hrdinu(&h);
    zemri(&h);
    printf("Hrdina %s, stats %d/%d/%d/%d/%d/%d\n", h.jmeno, h.HP, h.energie, h.XP, h.level, h.sila, h.stesti);
}
