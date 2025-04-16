#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

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

// Stock initial pour chaque type
int stock[] = {
    2, 3, 5, 5, 10, 10, 10,
    10, 10, 10, 20,
    30, 30, 30
};

void AfficherStock() {
    printf("\n--- État actuel de la caisse ---\n");
    for (int i = 0; i < sizeof(stock)/sizeof(stock[0]); i++) {
        printf("%s : %d\n", etiquettes[i], stock[i]);
    }
}

bool Calcul_monnaie(double monnaie) {
    int reste = (int)(monnaie * 100 + 0.5);
    int tempStock[14];

    for (int i = 0; i < 14; i++) tempStock[i] = stock[i];

    printf("\n--- Détail de la monnaie à rendre ---\n");

    for (int i = 0; i < 14; i++) {
        int nb = reste / valeurs[i];
        if (nb > 0) {
            if (tempStock[i] >= nb) {
                tempStock[i] -= nb;
                printf("%s x %d\n", etiquettes[i], nb);
                reste %= valeurs[i];
            } else {
                reste -= tempStock[i] * valeurs[i];
                printf("%s x %d (stock insuffisant)\n", etiquettes[i], tempStock[i]);
                tempStock[i] = 0;
            }
        }
    }

    if (reste > 0) {
        printf("Impossible de rendre la monnaie exacte. Reste : %d centimes\n", reste);
        return false;
    }

    // Appliquer la mise à jour du stock réel
    for (int i = 0; i < 14; i++) {
        stock[i] = tempStock[i];
    }

    return true;
}

bool Peut_rendre_monnaie(double monnaie) {
    int reste = (int)(monnaie * 100 + 0.5);
    for (int i = 0; i < 14; i++) {
        int maxPossible = stock[i] < (reste / valeurs[i]) ? stock[i] : (reste / valeurs[i]);
        reste -= maxPossible * valeurs[i];
    }
    return reste == 0;
}

void RechargerCaisse() {
    int recharge[] = {
        2, 3, 5, 5, 10, 10, 10,
        10, 10, 10, 20,
        30, 30, 30
    };
    for (int i = 0; i < 14; i++) {
        stock[i] += recharge[i];
    }
    printf("Caisse rechargée avec succès !\n");
}

int main() {
    srand(time(0));

    char choix;
    bool continuer = true;

    while (continuer) {
        double montantAPayer = 50.0 + (double)rand() / RAND_MAX * 450.0;
        montantAPayer = (int)(montantAPayer * 10) / 10.0;

        double paiementClient = 0.0;
        bool paiementValide = false;

        printf("\nMontant à payer: Rs%.1f\n", montantAPayer);

        while (!paiementValide) {
            printf("Veuillez entrer votre paiement (Rs): ");
            scanf("%lf", &paiementClient);

            if (paiementClient < montantAPayer) {
                printf("Paiement insuffisant! Il manque Rs%.1f\n", montantAPayer - paiementClient);
            } else {
                paiementValide = true;

                if (paiementClient > montantAPayer) {
                    double monnaie = paiementClient - montantAPayer;

                    if (Peut_rendre_monnaie(monnaie)) {
                        printf("Merci! Voici votre monnaie: Rs%.1f\n", monnaie);
                        Calcul_monnaie(monnaie);
                    } else {
                        printf("Désolé, impossible de rendre la monnaie exacte avec l'état actuel de la caisse.\n");

                        printf("Souhaitez-vous (R)echarger la caisse ou (F)ermer ? ");
                        scanf(" %c", &choix);

                        if (choix == 'R' || choix == 'r') {
                            RechargerCaisse();
                        } else {
                            continuer = false;
                        }
                    }
                } else {
                    printf("Merci! Paiement exact.\n");
                }
            }
        }

        AfficherStock();
    }

    printf("Caisse fermée. À bientôt !\n");
    return 0;
}

#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>






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
































	




















	
	








   






















        




