/**
 * Auteur:      João Carvalho Santos
 * Date:        16.02.22
 * Titre:       Bataille Navale
 * Description: Jeu Bataille Navale avec 5 bateaux, le joueur doit découvrir et détruire les 5 bateaux avec le minimum de coups
 */

#include <stdio.h>
#include <windows.h>

#define LINES 10
#define COLUMNS 10

/**
 * Changer la couleur de touts les prochains caractères en bleu clair
 */
void cyanColor() {
    printf("\033[0;36m");
}

/**
 * Changer la couleur de touts les prochains caractères en jaune
 */
void yellowColor() {
        printf("\033[0;33m");
}

/**
 * Remettre par défaut la couleur des caractères
 */
void resetColor() {
    printf("\033[0m");
}

/**
 * Affichage du début du jeu
 */
void start(){
    // Afficher des dessins de bateaux au lancement du jeu
    printf("\n\n"
           "                                                .\n"
           "                              .                 |\n"
           "                              +                 |\n"
           "                     .        |                *+W+-*\n"
           "        .           +y        +W+              . H                 .\n"
           "     .  +y            |I.   y  |               ! H= .           .  ^                                                           )___(\n"
           "     !   \\     .     |H '. /   |  ___.        .! H  !   +--.--y !  V                                                    _______/__/_\n"
           "     !    \\     \\  +=|H|=='.=+ | |====\\   _  '_H_H__H_. H_/=  J !  !                                           ___     /===========|   ___\n"
           "   . !     \\'    VVV_HHH_/__'._H |  E  \\_|=|_|========|_|==|____H. ! _______.                 ____       __   [\\\\\\]___/____________|__[///]   __\n"
           "   I-H_I=I=HH_==_|I_IIIII_I_I_=HH|======.I-I-I-=======-I=I=I=I_=H|=H'===I=I/                  \\   \\_____[\\\\]__/___________________________\\__[//]___\n"
           "   \\                                                                      ,                    \\                                                    |\n"
           "    |                                                                    /                      \\                                                   |\n"
           "    .___________________________________________________________________'                        \\__________________________________________________/\n"
           "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n\n\n");

    // Afficher un titre dessin du mot Battleship au lancement du jeu
    printf("                                           ╔════╗ ╔═════╗╔═══╦═══╗╔═══╦═══╗╔     ╔════╗╔═════╗╦      ╦╔═══╦═══╗╔═════╗\n"
           "                                           ║    ║ ║     ║    ║        ║    ║     ║     ║      ║      ║    ║    ║     ║\n"
           "                                           ║    ║ ║     ║    ║        ║    ║     ║     ║      ║      ║    ║    ║     ║\n"
           "                                           ╠════╩╗╠═════╣    ║        ║    ║     ╠══   ╚═════╗╠══════╣    ║    ╠═════╝\n"
           "                                           ║     ║║     ║    ║        ║    ║     ║           ║║      ║    ║    ║\n"
           "                                           ║     ║║     ║    ║        ║    ║     ║           ║║      ║    ║    ║\n"
           "                                           ╚═════╝╩     ╩    ╩        ╩    ╚═════╚════╝╚═════╝╩      ╩╚═══╩═══╝╩\n\n\n\n");

    // Demander au joueur d'appuyer sur une touche pour continuer
    system("pause");
    // Nettoyer l'interface
    system("cls");
}

/**
 * Affiche le menu et demande au joueur ce qu'il veut faire
 * @return Ce que le joueur veut faire: 0 = quitter, 1 = jouer, 2 = regles du jeu, 3 affichher les scores
 */
char menu(){
    // Préparation des variables
    char playerChoice;

    // Afficher le menu tant que le premier caractère taper n'est pas 0, 1, 2 ou 3
    do {
        // Présennter les options au joueur
        cyanColor();
        printf("\n\n  Bienvenue à Battleship!\n\n");
        resetColor();
        printf("  Choisi une option:\n");
        printf("    0 - Quitté\n");
        printf("    1 - Jouer\n");
        printf("    2 - Règles du jeu\n");
        printf("    3 - Scores\n\n");
        printf("  Choix:");
        // Récupération du choix du joueur
        scanf("%c", &playerChoice);
        // Vider le buffer
        fflush(stdin);
        // Nettoyer l'interface
        system("cls");

        if(playerChoice < '0' || playerChoice > '3'){
            yellowColor();
            printf("\n  CHOISIS UNE OPTION VALABLE!\n\n");
            resetColor();
        }
    }while(playerChoice < '0' || playerChoice > '3');
    // Retourné le choix du joueur
    return playerChoice;
}

/**
 * Affichage des règles du jeu
 */
void rules(){
    printf("\n\n  Dans ce jeu j'ai secrétement placé 5 bateaux de guerre dans une grille:\n");
    printf("    - Un porte-avions, qui occupe 5 places\n");
    printf("    - Un croiseur, qui occupe 4 places\n");
    printf("    - Deux contre-torpilleurs, qui occupent 3 places\n");
    printf("    - Un torpilleur, qui occupe 2 places\n\n");
    printf("  Ton but est de découvrir et détruir touts mes bateaux en tirant sur des coordonées (une lettre et un numéro).\n");
    printf("  Les bateaux seront placés en vertical ou en horizontal, mais jamais en diagonal!\n");
    printf("  Une fois que toutes les différentes cases d'un bateaux sont touchés, le bateaux sera détruit!\n");
    printf("  Une fois que touts les bateaux sont détruits, tu gagne!\n");
    printf("  Le moins de fois tu tirs, le mieux sera ton score!\n\n");
    printf("  Dans les cases de la grille, tu trouvera:\n");
    printf("    - ' ' = Rien ne s'est passé pour l'instant\n");
    printf("    - 'O' = Tu as raté ton tir\n");
    printf("    - 'X' = Tu as tiré sur un bateau\n");
    printf("    - '#' = Cette case fait partie d'un bateau détruit\n\n\n");
    system("pause");
    system("cls");
}

/**
 * Affiche la grille
 */
void grid(){
    printf("\n\n    ╔═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╗\n"
           "    ║     ║  A  ║  B  ║  C  ║  D  ║  E  ║  F  ║  G  ║  H  ║  I  ║  J  ║\n"
           "    ╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣\n");

    for (int i = 1; i < LINES; i++) {
        printf("    ║  %d  ║     ║     ║     ║     ║     ║     ║     ║     ║     ║     ║\n"
               "    ╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣\n", i);
    }

    printf("    ║ 10  ║     ║     ║     ║     ║     ║     ║     ║     ║     ║     ║\n"
           "    ╚═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╝\n\n");
}

/**
 * Force le programme à se mettre en plein écran
 */
void fullscreen()
{
    keybd_event(VK_MENU,0x38,0,0);
    keybd_event(VK_RETURN,0x1c,0,0);
    keybd_event(VK_RETURN,0x1c,KEYEVENTF_KEYUP,0);
    keybd_event(VK_MENU,0x38,KEYEVENTF_KEYUP,0);
}

/**
 * Demande une colonne à l'utilisateur
 * @return la colonne
 */
char askColumn(){
    char column;

    // Faire tant que le choix n'est pas entre A et J ou a et j
    do {
        // Demander la colonne à l'utilisateur
        printf("  Choisi une colonne:");
        scanf("%c", &column);
        // Vider le buffer
        fflush(stdin);
        // Avertir l'utilisateur si le choix n'est pas entre A et J ou a et j
        if (column < 65 || (column > 74 && column < 97) || column > 106){
            yellowColor();
            printf("\n  CHOISIS UNE OPTION VALABLE!\n\n");
            resetColor();
        }
    } while (column < 65 || (column > 74 && column < 97) || column > 106);

    return column;
}

/**
 * Demande une ligne à l'utilisateur
 * @return la ligne
 */
int askLine(){
    int line;

    // Faire tant que le choix n'est pas entre 1 et 10
    do {
        // Demander la ligne à l'utilisateur
        printf("  Choisi une ligne:");
        scanf("%d", &line);
        fflush(stdin);
        // Avertir l'utilisateur si le choix n'est pas entre 1 et 10
        if (line > 10 || line < 1){
            yellowColor();
            printf("\n  CHOISIS UNE OPTION VALABLE!\n\n");
            resetColor();
        }
    } while (line > 10 || line < 1);

    return line;
}

int columnNumber(){

}
int main() {
    fullscreen();

    // Commande pour les accents et caractères spéciaux
    SetConsoleOutputCP(65001);

    // Préparation des variables
    char choice;
    int boats[LINES][COLUMNS] = {{0,0,0,0,0,0,0,0,2,0},{0,0,3,0,0,0,0,0,2,0},{0,0,3,0,0,0,0,0,0,0},{0,0,3,0,0,0,4,0,0,0},{0,0,0,0,0,0,4,0,0,0},{0,0,0,0,0,0,4,0,0,0},{0,0,0,0,0,0,4,0,0,0},{0,0,0,0,0,0,0,0,0,0},{5,5,5,5,5,0,0,0,0,0},{0,0,0,0,0,0,6,6,6,0}};
    int coordinatesLine;
    char coordinatesColumn;
    int coordinatesColumnNumber;

    start();

    // Boucle infini. Tourner le jeu tant que choice est différent de 0
    for(;;) {
        choice = menu();

        // Directionner le joueur chez la fonction choiosi
        switch (choice) {
            // Quitter le jeu
            case '0':
                return 0;

            // Jouer
            case '1':
                grid();
                coordinatesColumn = askColumn();
                coordinatesLine = askLine();
                coordinatesColumnNumber = columnNumber();
                system("pause");

                break;

            // Afficher les règles du jeu
            case '2':
                rules();

                break;

            // Afficher les scores
            default:
                //printf("Pas encore disponible\n");
                for (int i = 0; i < LINES; i++) {
                    for (int j = 0; j < COLUMNS; j++) {
                        printf("%d", boats[i][j]);
                    }
                    printf("\n");
                }

                system("\npause");

                break;
        }
    }
}