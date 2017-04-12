#include <stdio.h>
#include <stdlib.h>

#include "hrdina.h"

void chytit_kone(struct hrdina *h) {
	int action = 0;
	int stesti=10 + (random() % 11);
	printf ("potkas divokeho kone. Ches utect(1) nebo ho zkrotit(2)?\n");
	scanf ("%d", &action);
	if (action == 2) {
		printf ("nemel jsi dneska stesti\n [ztratil jsi stesti]\n");
		stesti -= 1;
	}
}
		
