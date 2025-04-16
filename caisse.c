
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

int main(){
	srand(time(0));
	
	double montantAPayer = 50.0 + (double)rand() / RAND_MAX * 450.0;
	montantAPayer = (int)(montantAPayer * 10) / 10.0;

	double paiementClient = 0.0;
	bool paiementValide = false;

	printf("Montant à payer: Rs%.1f\n", montantAPayer);




	while (!paiementValide) {
		printf("Veuillez entrer votre paiement (Rs): ");
		scanf("%lf", &paiementClient);


	if(paiementClient < montantAPayer) {
		printf("Paiement insuffisant! Il manque Rs%.1f\n", montantAPayer - paiementClient);
	} else {
		paiementValide = true;
	
	
	if (paiementClient > montantAPayer){
		printf("Merci! Voici votre monnaie: Rs%.1f\n",paiementClient - montantAPayer);
	}else {
		printf("Merci! Paiement exact.\n");
	}
	
      }

    }

	return 0;	
}	




 		


