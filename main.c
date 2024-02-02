#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    const int MIN = 1;
    int max, mode, level, nombreMystere, number;
    char rejouer ;

    /* Boucle principale, permettant � l'utilisateur d'entrer des � l'�cran et ensuite comparer son entrer avec le nombre
     mystere apr�s comparaison on affichera le r�sultat(s'il a gagn� ou pas). Une nouvelle fonctionnalit� � �t� ajout� au programme
     permettant aux joueurs de choisir un mode de jeu sp�cifique */

     do{
         int boolean = 1, compteur = 0 ;



         // Menu pour le mode de joueur ( 1 ou 2 joueur )
         printf("           ***** MENU MODE *****\n");
         printf("1. Mode 1 joueur \n");
         printf("2. Mode 2 joueur \n");
         printf("Choisi le mode de jeu : ");
         scanf("%d", &mode);
         printf("\n");

         switch(mode){
             case 1:

                 // Second menu pour plusieurs niveaux de difficult� pour le mode 1 joueur
                 printf("           ***** Niveau de difficulte *****\n");
                 printf("1. Easy (entre 1 et 100)\n");
                 printf("2. Medium (entre 1 et 1000\n");
                 printf("3. Expert (entre 1 et 10000\n");
                 printf("Quel niveau ? ");
                 scanf("%d", &level);
                 printf("\n");

                 switch(level){
                    case 1:
                        max = 100;
                        break;
                    case 2:
                        max = 1000;
                        break;
                    case 3:
                        max = 10000;
                        break;

                 }

                // G�n�ration d'un nombre al�atoire
                srand(time(NULL));
                nombreMystere = (rand() % (max - MIN + 1)) + MIN;
                break;

             case 2:
                printf("Joueur 1 ! Le nombre mystere: ");
                scanf("%d", &nombreMystere);
                printf("\n");
                break;
             default:
                printf("Votre entrer est invalide ! Veuillez choisir le mode (1 ou 2) !\n");
                continue;

         }

         printf("            ***** DEBUT DU JEU *****\n");

         do{
                printf("Quel est le nombre ? ");

                /* for(int i = 0; sizeof(number); i++)
                {
                    if(!isdigit(number % 10 + 'O'))
                    {
                        printf("Veuillez entrer que des nombres please !\n");
                        boolean = 0;
                        break;
                    }
                    number /= 10;
                } Fonctionne � condition que nous rajouttons une nouvelle condition if avant la ligne 95 permettant de v�rifier
                l'�tat de la variable boolean avant commencer la comparaison entre nombre entrer par l'utilisateur et le nombre myst�re.
                Attention ! Il est imp�ratif d'inclure la biblioth�quue ctype.h tout en haut du programme hors du main() */

                if(scanf("%d", &number) != 1) // Si vous utilisez la methode qui se trouve commentaire veuillez mettre celui-ci en commentaire, par contre je conseille vivement celle que j'utilise.
                {
                    printf("Veuillez entrer que des nombres please !\n");
                    while(getchar() != '\n');
                        continue;
                }

                if(number > nombreMystere)
                    printf("C'est moins ! \n");
                else if(number < nombreMystere)
                    printf("C'est plus ! \n");
                else
                {
                    printf("Bravo, vous avez trouve le nombre mystere !\n");
                    printf("Vous avez trouve le nombre mystere en %d coups \n\n", (compteur + 1));


                    boolean = 0;
                }
                compteur++;


         }while(boolean);

         // Nouvelle fonctionnalit� qui donnera la possibilit� au joueur de faire plusieurs partie de jeu
                 printf("Voulez-vous jouer une nouvelle partie ? (o/n) ");
                 scanf("%s", &rejouer);
                 printf("\n");

     }while(rejouer == 'o' || rejouer == 'O');
     printf("Bye a la prochaine !!!");
     printf("\n\n");

     return 0;

}
