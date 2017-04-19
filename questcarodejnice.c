#include <stdio.h>



void carodejnice(struct hrdina *h){
	int odpoved = 0;	
	printf("Šel jsi k čarodejnici a ta ti řekla,že pokud chceš získat zkušennosti, musíš jí 	   pomoct."\n);
	printf("Poslala tě do lesa nasbírat takové modré kytky. Objevila se ale před tebou jáma. Nešlo ji obejít, ani přeskočit." \n);
	printf("1)Odejít pryč a vzdát tak úkol \n 2)Ručkovat po větvích \n 3) Zkusit najít něco co by ti pomohlo dostat se přes jámu"\n);
	scanf("%d", &odpoved);
	if(odpoved == 1){exit(0);}else{
	if(odpoved == 2){printf("Podařilo se ti přeručkovat na druhou stranu.");}else{
	if(odpoved == 3){printf("Nic jsi nenašel. xD")};
	}
	}

}
