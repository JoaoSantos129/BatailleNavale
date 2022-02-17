/**
 * Auteur:      João Carvalho Santos
 * Date:        16.02.22
 * Titre:       Bataille Navale
 * Description: Jeu Bataille Navale avec 5 bateaux, le joueur doit découvrir et détruire les 5 bateaux avec le minimum de coups
 */

#include <stdio.h>
#include <windows.h>

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
 * @return Ce que le joueur veut faire
 */
char menu(){
    // Préparation des variables
    char playerChoice;
    int characterEater; // Variable qui va supprimer touts les caractères dans la variable playerChoice sauf le premier

    // Afficher le menu tant que le premier caractère taper n'est pas 0, 1, 2 ou 3
    do {
        // Présennter les options au joueur
        printf("\n\nWelcome to Battleship!\n\n");
        printf("Chose an option:\n");
        printf(" 0 - Quit\n");
        printf(" 1 - Play\n");
        printf(" 2 - Rules\n");
        printf(" 3 - Best Scores\n\n");
        printf("Choice:");
        // Récupération du choix du joueur
        scanf("%c", &playerChoice);

        // Supprimer touts les caractères de la variable playerChoice sauf le premier
        while((characterEater = getchar()) != '\n' && characterEater != EOF);
        // Nettoyer l'interface
        system("cls");
    }while(playerChoice < '0' || playerChoice > '3');
    // Retourné le choix du joueur
    return playerChoice;
}

int main() {
    // Commande pour les accents et caractères spéciaux
    SetConsoleOutputCP(65001);

    // Préparation des variables
    char choice = 0;

    start();

    choice = menu();

    return 0;
}