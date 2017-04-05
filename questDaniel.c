#include <stdio.h>
#include <stdlib.h>

#include "hrdina.h"

void hybat(struct hrdina *h) {
	int volba = 0;
	int stesti=10 + (random() % 11);
	printf ("potkas divokeho kone. Ches utect(1) nebo ho zkrotit(2)?");
	scanf (" %d", &volba);
	if (volba = 2){
		printf ("nemel jsi dneska stesti\n [ztratil jsi stesti]");
		stesti= stesti - 1;
		}
	exit(0);
}
		
