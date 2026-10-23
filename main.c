
#include <stdio.h>

#define TAILLE 3

char grille[TAILLE][TAILLE];

// 1. Initialise avec des cases vides
void initialiser_grille() {
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            grille[i][j] = ' ';
        }
    }
}

// 2. Affiche la grille
void afficher_grille() {
    printf("\n");
    for (int i = 0; i < TAILLE; i++) {
        printf(" %c | %c | %c \n", grille[i][0], grille[i][1], grille[i][2]);
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

// 3. Verifie s'il y a un gagnant
char verifier_gagnant() {
    // lignes
    for (int i = 0; i < TAILLE; i++) {
        if (grille[i][0] != ' ' && grille[i][0] == grille[i][1] && grille[i][1] == grille[i][2])
            return grille[i][0];
    }
    // colonnes
    for (int i = 0; i < TAILLE; i++) {
        if (grille[0][i] != ' ' && grille[0][i] == grille[1][i] && grille[1][i] == grille[2][i])
            return grille[0][i];
    }
    // diagonales
    if (grille[0][0] != ' ' && grille[0][0] == grille[1][1] && grille[1][1] == grille[2][2])
        return grille[0][0];
    if (grille[0][2] != ' ' && grille[0][2] == grille[1][1] && grille[1][1] == grille[2][0])
        return grille[0][2];

    return ' '; // pas encore de gagnant
}

// 4. Verifie si match nul
int grille_pleine() {
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            if (grille[i][j] == ' ') return 0; // reste une place
        }
    }
    return 1; // pleine
}

int main() {
    int ligne, col;
    char joueur = 'X';
    char gagnant = ' ';

    initialiser_grille();

    printf("=== JEU MORPION ===\n");
    printf("Joueur 1 = X | Joueur 2 = O\n");

    while (1) {
        afficher_grille();
        printf("Joueur %c (ligne col): ", joueur);
        scanf("%d %d", &ligne, &col);

        // case invalide
        if (ligne < 0 || ligne > 2 || col < 0 || col > 2 || grille[ligne][col] != ' ') {
            printf("Coup invalide, rejouez !\n");
            continue;
        }

        grille[ligne][col] = joueur;

        gagnant = verifier_gagnant();
        if (gagnant != ' ') {
            afficher_grille();
            printf("Bravo ! Joueur %c a gagne !\n", gagnant);
            break;
        }
        if (grille_pleine()) {
            afficher_grille();
            printf("Match nul !\n");
            break;
        }

        // changer de joueur
        joueur = (joueur == 'X') ? 'O' : 'X';
    }
    return 0;
}
