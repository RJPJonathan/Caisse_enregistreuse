
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

void Calcul_monnaie(double monnaie) {
    int valeurs[] = {
        200000, 100000, 50000, 20000, 10000, 5000, 2500,
  	2000, 1000, 500, 100, 50, 20, 5                  
    };
    const char *etiquettes[] = {
        "Billet Rs2000", "Billet Rs1000", "Billet Rs500", "Billet Rs200",
        "Billet Rs100", "Billet Rs50", "Billet Rs25",
        "Pièce Rs20", "Pièce Rs10", "Pièce Rs5", "Pièce Rs1",
        "Pièce 50 sous", "Pièce 20 sous", "Pièce 5 sous"
    };

    int reste = (int)(monnaie * 100 + 0.5);  

    printf("\n--- Détail de la monnaie à rendre ---\n");

    for (int i = 0; i < sizeof(valeurs)/sizeof(valeurs[0]); i++) {
        int nb = reste / valeurs[i];
        if (nb > 0) {
            printf("%s x %d\n", etiquettes[i], nb);
            reste %= valeurs[i];
        }
    }

    if (reste > 0) {
        printf("Reste non traité : %d centimes\n", reste);
    }
    return 0;
}

int main() {
    srand(time(0));

    double montantAPayer = 50.0 + (double)rand() / RAND_MAX * 450.0;
    montantAPayer = (int)(montantAPayer * 10) / 10.0;

    double paiementClient = 0.0;
    bool paiementValide = false;

    printf("Montant à payer: Rs%.1f\n", montantAPayer);

    while (!paiementValide) {
        printf("Veuillez entrer votre paiement (Rs): ");
        scanf("%lf", &paiementClient);

        if (paiementClient < montantAPayer) {
            printf("Paiement insuffisant! Il manque Rs%.1f\n", montantAPayer - paiementClient);
        } else {
            paiementValide = true;

            if (paiementClient > montantAPayer) {
                double monnaie = paiementClient - montantAPayer;
                printf("Merci! Voici votre monnaie: Rs%.1f\n", monnaie);
                Calcul_monnaie(monnaie);
            } else {
                printf("Merci! Paiement exact.\n");
            }
        }
    }

    return 0;
}
































	




















	
	








   






















        




