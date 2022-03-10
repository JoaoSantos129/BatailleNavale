/**
 * Auteur:      João Carvalho Santos
 * Date:        09.03.22
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
 * Changer la couleur de touts les prochains caractères en rouge
 */
void redColor() {
    printf("\033[0;31m");
}

/**
 * Changer la couleur de touts les prochains caractères en vert
 */
void greenColor() {
    printf("\033[0;32m");
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
void start() {
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
           "                                           ╚═════╝╩     ╩    ╩        ╩    ╚═════╚════╝╚═════╝╩      ╩╚═══╩═══╝╩\n\n\n");

    // Demander au joueur d'appuyer sur une touche pour continuer
    printf("\n  ");
    system("pause");
    // Nettoyer l'interface
    system("cls");
}

/**
 * Affiche le menu et demande au joueur ce qu'il veut faire
 * @return Ce que le joueur veut faire: 0 = quitter, 1 = jouer, 2 = regles du jeu, 3 affichher les scores
 */
char menu() {
    // Préparation des variables
    char playerChoice;

    // Afficher le menu tant que le premier caractère taper n'est pas 0, 1, 2 ou 3
    do {
        // Présennter les options au joueur
        cyanColor();
        printf("\n\n  Bienvenue à Battleship!\n\n");
        resetColor();
        printf("  Choisi une option:\n");
        printf("    0 - Quitter\n");
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

        if (playerChoice < '0' || playerChoice > '3') {
            yellowColor();
            printf("\n  CHOISIS UNE OPTION VALABLE!\n\n");
            resetColor();
        }
    } while (playerChoice < '0' || playerChoice > '3');
    // Retourné le choix du joueur
    return playerChoice;
}

/**
 * Affichage des règles du jeu
 */
void rules() {
    printf("\n\n  Dans ce jeu j'ai secètement placé 5 bateaux de guerre dans une grille:\n");
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
    printf("    - '");
    cyanColor();
    printf("O");
    resetColor();
    printf("' = Tu as raté ton tir\n");
    printf("    - '");
    yellowColor();
    printf("X");
    resetColor();
    printf("' = Tu as tiré sur un bateau\n");
    printf("    - '");
    redColor();
    printf("#");
    resetColor();
    printf("' = Cette case fait partie d'un bateau détruit\n\n\n");
    system("pause");
    system("cls");
}

/**
 * Force le programme à se mettre en plein écran
 */
void fullscreen() {
    keybd_event(VK_MENU, 0x38, 0, 0);
    keybd_event(VK_RETURN, 0x1c, 0, 0);
    keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
    keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
}

/**
 * Demande une colonne à l'utilisateur
 * @return la colonne
 */
char askColumn() {
    char column;

    // Faire tant que le choix n'est pas entre A et J ou a et j
    do {
        // Demander la colonne à l'utilisateur
        printf("  Choisi une colonne:");
        scanf("%c", &column);
        // Vider le buffer
        fflush(stdin);
        // Avertir l'utilisateur si le choix n'est pas entre A et J ou a et j
        if (column < 65 || (column > 74 && column < 97) || column > 106) {
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
int askLine() {
    int line;

    // Faire tant que le choix n'est pas entre 1 et 10
    do {
        // Demander la ligne à l'utilisateur
        printf("  Choisi une ligne:");
        scanf("%d", &line);
        fflush(stdin);
        // Avertir l'utilisateur si le choix n'est pas entre 1 et 10
        if (line > 10 || line < 1) {
            yellowColor();
            printf("\n  CHOISIS UNE OPTION VALABLE!\n\n");
            resetColor();
        }
    } while (line > 10 || line < 1);

    line = line - 1;

    return line;
}

/**
 * Transforme la lettre de la colonne choisi en numéro
 * @param column
 * @return Le numéro de la colonne
 */
int columnNumber(char column) {
    int numbColumn = 0;

    // Transormer la lettre en numéro si elle est majuscule
    if (column >= 'A' && column <= 'Z') {
        numbColumn = column - 'A';
        // Transormer la lettre en numéro si elle est minuscule
    } else if (column >= 'a' && column <= 'z') {
        numbColumn = column - 'a';
    }

    return numbColumn;
}

/**
 * Tirer sur la cordonée choisi si l'utilisateur n'a pas encore tiré
 * @param column
 * @param line
 * @param boatsLocations
 * @return O si raté, 10 si cooronée répétée ou la premiere lettre du numero de cases du bateaux touché
 */
int shoot(int column, int line, char boatsLocations[LINES][COLUMNS]) {
    int event;

    switch (boatsLocations[line][column]) {
        // Si dans la coordonnée choisi il y a un "2", alors touché le bateau
        case '2':
            event = 2;
            boatsLocations[line][column] = 'd';

            break;

            // Si dans la coordonnée choisi il y a un "3", alors touché le premier bateau de 3 cases
        case '3':
            event = 3;
            boatsLocations[line][column] = 't';

            break;

            // Si dans la coordonnée choisi il y a un "6", alors touché le deuxième bateau de 3 cases
        case '6':
            event = 6;
            boatsLocations[line][column] = 's';

            break;

            // Si dans la coordonnée choisi il y a un "4", alors touché le bateau de 4 cases
        case '4':
            event = 4;
            boatsLocations[line][column] = 'q';

            break;

            // Si dans la coordonnée choisi il y a un "5", alors touché le bateau de 5 cases
        case '5':
            event = 5;
            boatsLocations[line][column] = 'c';

            break;

            // Si dans la coordonnée choisi il y a un "0", alors plouf
        case '0':
            event = 0;
            boatsLocations[line][column] = 'O';

            break;

            // Si l'utilisateur choisi ici, ne pas tiré, coordonnée répétée
        default:
            redColor();
            printf("\n  Tu as déjà tiré ici!\n");
            resetColor();
            printf("\n  ");
            system("pause");
            event = 10;

            break;

    }

    return event;
}

/**
 * Affiche un "O" si le tire a raté, un "X" si le tire a touché un bateau et affiche des "#" si un bateaux a été détruit
 * @param boatsLocations
 */
void changeGrid(char boatsLocations[LINES][COLUMNS]) {

    // Afficher l'entête de la grille
    printf("\n\n    ╔═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╦═════╗\n"
           "    ║     ║  A  ║  B  ║  C  ║  D  ║  E  ║  F  ║  G  ║  H  ║  I  ║  J  ║\n"
           "    ╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣");

    // Vérifier toutes les lignes
    for (int i = 0; i < LINES; i++) {
        printf("\n    ║ %2d  ║", i + 1);
        // Vérifier toutes les colonnes
        for (int j = 0; j < COLUMNS; j++) {
            if (boatsLocations[i][j] == 'd' || boatsLocations[i][j] == 't' || boatsLocations[i][j] == 's' ||
                boatsLocations[i][j] == 'q' || boatsLocations[i][j] == 'c') {
                // Afficher un "X" si le bateau a été touché
                yellowColor();
                printf("  X  ");
                resetColor();
                printf("║");
            } else if (boatsLocations[i][j] == 'D' || boatsLocations[i][j] == 'T' || boatsLocations[i][j] == 'S' ||
                       boatsLocations[i][j] == 'Q' || boatsLocations[i][j] == 'C') {
                // Afficher un "#" si le bateau est détruit
                redColor();
                printf("  #  ");
                resetColor();
                printf("║");
            } else if (boatsLocations[i][j] == 'O') {
                // Afficher un "O" si le tire ne touche rien
                cyanColor();
                printf("  O  ");
                resetColor();
                printf("║");
            } else {
                // Ne rien afficher si l'utilisateur n'as pas encore tiré ici
                printf("     ║");
            }
        }
        if (i < LINES - 1) {
            printf("\n    ╠═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╬═════╣");
        }
    }

    printf("\n    ╚═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╩═════╝\n\n");
}

/**
 * Calule le score et l'affiche en vert si il est en dessus de 66, en jaune s'il est entre 66 et 34 ou en rouge s'il est en dessous de 34
 * @param points
 * @return le score
 */
int totalScore(int points) {
    // Règle de trois pour calculer le score
    points = (points - 17) * 100 / 83;
    printf("\n\n  Score: ");
    if (points > 66) {
        // Afficher en vert si en dessus de 66
        greenColor();
        printf("%d\n", points);
    } else if (points > 33) {
        // Afficher en jaune si en dessus de 33 mais en dessous de 67
        yellowColor();
        printf("%d\n", points);
    } else {
        // Afficher en  si en dessous de 34
        redColor();
        printf("%d\n", points);
    }
    resetColor();

    return points;
}

/**
 * Affiche la fin du jeu
 * @param boatsLocation
 * @param points
 */
void victory(char boatsLocation[LINES][COLUMNS], int points) {
    // Nettoyer l'interface
    system("cls");
    // Afficher la grille
    changeGrid(boatsLocation);
    greenColor();
    printf("\n  VICTOIRE!");
    resetColor();
    totalScore(points);
    printf("\n  ");
    system("pause");
    system("cls");
}

int main() {
    fullscreen();

    // Commande pour les accents et caractères spéciaux
    SetConsoleOutputCP(65001);

    // Préparation des variables
    char choice = 'p';
    int coordinatesLine;
    char coordinatesColumn;
    int coordinatesColumnNumber;

    start();

    // Tourner le jeu tant que choice est différent de 0
    while (choice != '0') {
        // Initialisation du tableau avec les bateaux
        char boats[LINES][COLUMNS] = {{'0', '0', '0', '0', '0', '0', '0', '0', '2', '0'},
                                      {'0', '0', '3', '0', '0', '0', '0', '0', '2', '0'},
                                      {'0', '0', '3', '0', '0', '0', '0', '0', '0', '0'},
                                      {'0', '0', '3', '0', '0', '0', '4', '0', '0', '0'},
                                      {'0', '0', '0', '0', '0', '0', '4', '0', '0', '0'},
                                      {'0', '0', '0', '0', '0', '0', '4', '0', '0', '0'},
                                      {'0', '0', '0', '0', '0', '0', '4', '0', '0', '0'},
                                      {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
                                      {'5', '5', '5', '5', '5', '0', '0', '0', '0', '0'},
                                      {'0', '0', '0', '0', '0', '0', '6', '6', '6', '0'}};

        int boat2 = 2;
        int boat3 = 3;
        int boat6 = 3;
        int boat4 = 4;
        int boat5 = 5;
        int events;
        int score = 100;
        int destroyedBoats = 0;
        int boatsAlive;

        choice = menu();

        // Directionner le joueur chez la fonction choisi
        switch (choice) {

            // Jouer
            case '1':
                while (destroyedBoats < 5) {
                    // Demander à l'utilisateur la coordonée tant que'elle n'est pas une coordonée répétée
                    do {
                        // Calculer combien de bateaux il en reste
                        boatsAlive = 5 - destroyedBoats;
                        // Nettoyer l'interface
                        system("cls");
                        // Afficher le nombre de bateaux restants au joueur
                        printf("\n  Bateaux restants : %d", boatsAlive);
                        totalScore(score);
                        changeGrid(boats);
                        coordinatesColumn = askColumn();
                        coordinatesLine = askLine();
                        coordinatesColumnNumber = columnNumber(coordinatesColumn);
                        events = shoot(coordinatesColumnNumber, coordinatesLine, boats);
                    } while (events == 10);

                    // Vérifier si un bateau a coulé
                    switch (events) {
                        // Le bateau de 2 cases a été touché
                        case 2:
                            boat2 = boat2 - 1;
                            printf("\n  Touché");
                            if (boat2 == 0) {
                                printf(" coulé\n");
                                destroyedBoats++;
                                // Remplacer toutes les lettres du bateaux touchés par des lettres majuscules
                                for (int i = 0; i < LINES; i++) {
                                    for (int j = 0; j < COLUMNS; j++) {
                                        if (boats[i][j] == 'd') {
                                            boats[i][j] = 'D';
                                        }
                                    }
                                }
                            }

                            break;

                            // Le premier bateau de 3 cases a été touché
                        case 3:
                            boat3 = boat3 - 1;
                            printf("\n  Touché");
                            if (boat3 == 0) {
                                printf(" coulé\n");
                                destroyedBoats++;
                                // Remplacer toutes les lettres du bateaux touchés par des lettres majuscules
                                for (int i = 0; i < LINES; i++) {
                                    for (int j = 0; j < COLUMNS; j++) {
                                        if (boats[i][j] == 't') {
                                            boats[i][j] = 'T';
                                        }
                                    }
                                }
                            }

                            break;

                            // Le deuxième bateau de 3 cases a été touché
                        case 6:
                            boat6 = boat6 - 1;
                            printf("\n  Touché");
                            if (boat6 == 0) {
                                printf(" coulé\n");
                                destroyedBoats++;
                                // Remplacer toutes les lettres du bateaux touchés par des lettres majuscules
                                for (int i = 0; i < LINES; i++) {
                                    for (int j = 0; j < COLUMNS; j++) {
                                        if (boats[i][j] == 's') {
                                            boats[i][j] = 'S';
                                        }
                                    }
                                }
                            }

                            break;

                            // Le bateau de 4 cases a été touché
                        case 4:
                            boat4 = boat4 - 1;
                            printf("\n  Touché");
                            if (boat4 == 0) {
                                printf(" coulé\n");
                                destroyedBoats++;
                                // Remplacer toutes les lettres du bateaux touchés par des lettres majuscules
                                for (int i = 0; i < LINES; i++) {
                                    for (int j = 0; j < COLUMNS; j++) {
                                        if (boats[i][j] == 'q') {
                                            boats[i][j] = 'Q';
                                        }
                                    }
                                }
                            }

                            break;

                            // Le bateau de 2 cases a été touché
                        case 5:
                            boat5 = boat5 - 1;
                            printf("\n  Touché ");
                            if (boat5 == 0) {
                                printf(" coulé\n");
                                destroyedBoats++;
                                // Remplacer toutes les lettres du bateaux touchés par des lettres majuscules
                                for (int i = 0; i < LINES; i++) {
                                    for (int j = 0; j < COLUMNS; j++) {
                                        if (boats[i][j] == 'c') {
                                            boats[i][j] = 'C';
                                        }
                                    }
                                }
                            }

                            break;

                            // L'utilisateur n'a pas touché un bateau
                        default:
                            printf("\n  Plouf\n");
                            // Réduire le score
                            score--;

                            break;
                    }
                    printf("\n\n  ");
                    system("pause");
                }
                victory(boats, score);

                break;

                // Afficher les règles du jeu
            case '2':
                rules();

                break;

                // Afficher les scores
            case '3':
                printf("\n  Pas encore disponible\n");
                printf("\n  ");
                system("pause");
                // Nettoyer l'interface
                system("cls");

                break;
        }
    }
    return 0;
}