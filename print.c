 #include<stdio.h>
#include<stdlib.h>
#include<string.h>if
#include"fil.h"



int main()
{
    int choix ;
    int elem;
    myfile f2;
    f2.arriere=f2.avant=0;
    f2.taille=0;
    char nomfile[30];
    char x[20];


    printf("\n\n");
    printf("\t\t****************************************************************\n");
    printf("\t\t*                             MENU                             *\n");
    printf("\t\t****************************************************************\n");
    printf("\t\t*                                                              *\n");
    printf("\t\t*         1. Demande d'impression d'un fichier                 *\n");
    printf("\t\t*         2. Impression d'un fichier                           *\n");
    printf("\t\t*         3. Nombre de taches en cours d�impression            *\n");
    printf("\t\t*         4. Listes tri�e des taches en cours d�impression     *\n");
    printf("\t\t*         5. Reinitialisation les demandes d'impression        *\n");
    printf("\t\t*         6. Quitter le menu                                   *\n");
    printf("\t\t*                                                              *\n");
    printf("\t\t****************************************************************\n\n");
    printf("\t\t ====>> Veuillez saisir votre choix:  \n");
    scanf("%d",&choix);

    switch(choix)
    {
    case 1:
        printf("inserer l'elemnt � imprimer ");
        gets(f2.file[f2.avant]);
        emfiler(&f2,f2.file[f2.avant]);
        f2.taille++;
        break;

    case 2:
        if(!est_vide(f2))
        {
            defiler(&f2);
            f2.taille--;
        }
        else
        {
            printf("la file d'attente est vide");
        }
        break;
    case 3:
        printf("Le nombre de taches en cours d'impression est %d",&f2.taille);
        break;
    case 4 :

         for(int i=0;i<f2.taille;i++)
         {
            for(int j=0;j<f2.taille;j++)
            {
                if(strcmp(f2.file[i],f2.file[j])<0)
                {
                    nomfile[20] = f2.file[i];
                    f2.file[i]=f2.file[j];
                    f2.file[j] = nomfile;
                }
            }
         }
         for(int i=0;i<f2.taille;i++)
         {
             printf("%s",f2.file[i]);
         }
         break;
    case 5 :
        while(!(est_vide(f2)))
        {
            x[20]=defiler(&f2);
        }
        printf("la file a �t� r�initialis�");
        break;
    case 6 :
        printf("vous avez quitter le file d'attente");
        return 0;
    }
}


