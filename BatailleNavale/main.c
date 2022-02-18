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
    int characterEater; // Variable qui va supprimer touts les caractères dans la variable playerChoice sauf le premier

    // Afficher le menu tant que le premier caractère taper n'est pas 0, 1, 2 ou 3
    do {
        // Présennter les options au joueur
        cyanColor();
        printf("\n\n  Welcome to Battleship!\n\n");
        resetColor();
        printf("  Chose an option:\n");
        printf("    0 - Quit\n");
        printf("    1 - Play\n");
        printf("    2 - Rules\n");
        printf("    3 - Best Scores\n\n");
        printf("  Choice:");
        // Récupération du choix du joueur
        scanf("%c", &playerChoice);

        // Supprimer touts les caractères de la variable playerChoice sauf le premier
        while((characterEater = getchar()) != '\n' && characterEater != EOF);

        // Nettoyer l'interface
        system("cls");

        if(playerChoice < '0' || playerChoice > '3'){
            yellowColor();
            printf("\n  PLEASE CHOOSE AN AVAILABLE OPTION!\n\n");
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
    printf("\n\n  In this game I have secretly placed 5 warships in a grid:\n");
    printf("    - A Carrier, which occupies 5 spaces\n");
    printf("    - A Battleship, which occupies 4 spaces\n");
    printf("    - A Cruiser, which occupies 3 spaces\n");
    printf("    - A Submarine, which occupies 3 spaces\n");
    printf("    - A Destroyer, which occupies 2 spaces\n\n");
    printf("  Your goal is to guess where they are by shooting at coordinates (a letter and a number).\n");
    printf("  Boats will always be placed vertically or horizontally, but never diagonally!\n");
    printf("  Once you shot on all the boat's different spaces, that boat is destroyed!\n");
    printf("  Once all the boats are destroyed, you win!\n");
    printf("  The less shots you use, the better your score is!\n\n");
    printf("  Possible events:\n");
    printf("    - ' ' = Nothing happened yet\n");
    printf("    - 'O' = Miss\n");
    printf("    - 'X' = Shot\n");
    printf("    - '#' = Destroyed boat space\n\n\n");
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

int askCoordinates(boolean letterOrNumber){
    int place;

    if (letterOrNumber == 0) {
        printf("\n\n  Choose a collumn:");
        scanf("%d", &place);
    }else{
        printf("\n  Choose a line:");
        scanf("%d", &place);
    }

    return place;
}

int main() {
    fullscreen();

    // Commande pour les accents et caractères spéciaux
    SetConsoleOutputCP(65001);

    // Préparation des variables
    char choice;
    int boats[LINES][COLUMNS] = {{0,0,0,0,0,0,0,0,2,0},{0,0,3,0,0,0,0,0,2,0},{0,0,3,0,0,0,0,0,0,0},{0,0,3,0,0,0,4,0,0,0},{0,0,0,0,0,0,4,0,0,0},{0,0,0,0,0,0,4,0,0,0},{0,0,0,0,0,0,4,0,0,0},{0,0,0,0,0,0,0,0,0,0},{5,5,5,5,5,0,0,0,0,0},{0,0,0,0,0,0,6,6,6,0}};
    int coordinates;
    boolean collumnOrLine;

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
                collumnOrLine = 0;
                grid();
                coordinates = askCoordinates(collumnOrLine);
                collumnOrLine = 1;
                coordinates = askCoordinates(collumnOrLine);
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