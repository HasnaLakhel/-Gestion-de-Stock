#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct Livre {
    int id;
    int Prix;
    char Titre[50];
    char Auteur[50];
    int Quantite;
};

int nLivres = 10;  
struct Livre AllLivre[500] = {
    {1, 19, "C Programming", "Dennis Ritchie", 10},
    {2, 29, "Learn Python", "Guido van Rossum", 5},
    {3, 15, "Java for Beginners", "James Gosling", 8},
    {4, 25, "JavaScript Essentials", "Brendan Eich", 12},
    {5, 17, "Effective C++", "Scott Meyers", 7},
    {6, 20, "Design Patterns", "Erich Gamma", 6},
    {7, 12, "Data Structures", "Mark Allen Weiss", 10},
    {8, 225, "Clean Code", "Robert C. Martin", 4},
    {9, 180, "Operating Systems", "Andrew S. Tanenbaum", 9},
    {10, 300, "Artificial Intelligence", "Stuart Russell", 3}
};

char valide_Titre(char Titre[50] ){
    for (int  i = 0 ; Titre[i] !='\0'; i++)
    {
        if (!isalpha(Titre[i]) && Titre[i] != ' '){
            return 0;
        }
    }
    return 1;
}
char valide_Auteur(char Auteur[50] ){
    for (int  i = 0 ; Auteur[i] !='\0'; i++) {
        if (!isalpha(Auteur[i]) && Auteur[i] != ' '){
            return 0;
        }     
    }
    return 1;
}

int valide_Prix(int  Prix ){
    if (Prix < 0){
        return 0;
    }
    return 1;
}
int valide_Quantite(int Quantite){
        if (Quantite >= 100){
            return 0;
        }    
    return 1;
}


void Ajouter() {
    struct Livre Livre_info;
    if (nLivres >= 500) {
        printf("Stock plein, impossible d'ajouter plus de livres.\n");
    } else {
        do
        {
            printf("Entrez le titre du livre : ");
            scanf(" %s", Livre_info.Titre);
            if (!valide_Titre(Livre_info.Titre)){
                printf("le titre  nom invalide\n");}
        } while (!valide_Titre(Livre_info.Titre));
         do{
            printf("Entrez Auteur du livre : ");
            scanf(" %s", Livre_info.Auteur);
            if (!valide_Auteur( Livre_info.Auteur)){
                printf(" l'auteur nom invalide\n");}
        } while (!valide_Auteur( Livre_info.Auteur));
        do
        {
            printf("Entrez le prix du livre : ");
            scanf("%d", &Livre_info.Prix);
            if (!valide_Prix(Livre_info.Prix )){
                printf("prix invalide");
            }
        } while (!valide_Prix(Livre_info.Prix ));
        do
        {
            printf("Entrez la quantité en stock : ");
            scanf("%d", &Livre_info.Quantite);
            if (!valide_Quantite(Livre_info.Quantite)){
                printf("Quantite invalide");
            }
        } while (!valide_Quantite(Livre_info.Quantite));
        


        int maxId = 0;
        for (int i = 0; i < nLivres; i++) {
            if (AllLivre[i].id > maxId) {
                maxId = AllLivre[i].id;
            }
        }
        Livre_info.id = maxId + 1;
        AllLivre[nLivres++] = Livre_info;
        printf("Livre ajouté avec succès.\n");
    }
}

void Afficher() {
    if (nLivres == 0) {
        printf("Aucun livre disponible.\n");
    } else {
        for (int i = 0; i < nLivres; i++) {
            printf("\n---------- livre n=%d------------------\n",i+1);
            printf("ID: %d, Titre: %s, Auteur: %s\n",
                   AllLivre[i].id, AllLivre[i].Titre, AllLivre[i].Auteur);
            printf(" Prix: %.df, Quantité: %d\n",AllLivre[i].Prix, AllLivre[i].Quantite);
        }
    }
}

void Rechercher() {
    int id_Recherche;
    printf("Entrez le id du livre à rechercher : ");
    scanf(" %d", &id_Recherche);
    int trouve = 0;
    for (int i = 0; i < nLivres; i++) {
        if(AllLivre[i].id == id_Recherche)   {
            printf("ID: %d, Titre: %s, Auteur: %s\n",
                   AllLivre[i].id, AllLivre[i].Titre, AllLivre[i].Auteur);
            printf(" Prix: %.d, Quantité: %d\n",AllLivre[i].Prix, AllLivre[i].Quantite);
            trouve = 1;
            break;
        }
    }
    if (!trouve) {
        printf("Livre non trouvé.\n");
    }
}

void Modifier() {
    int id_Recherche;
    int newQuantite;
    printf("Entrez le titre du livre à modifier : ");
    scanf(" %d", &id_Recherche);
    printf("Entrez la nouvelle quantité : ");
    scanf("%d", &newQuantite);
    int trouve = 0;
    for (int i = 0; i < nLivres; i++) {
        if (AllLivre[i].id == id_Recherche){
            AllLivre[i].Quantite = newQuantite;
            printf("Quantité mise à jour pour ID: %d, Titre: %s, Auteur: %s, Prix: %.d, Quantité: %d\n",
                   AllLivre[i].id, AllLivre[i].Titre, AllLivre[i].Auteur, 
                   AllLivre[i].Prix, newQuantite);
            trouve = 1;
            break;
        }
    }
    if (!trouve) {
        printf("Livre non trouvé.\n");
    }
}

void Supprimer() {
    struct Livre Livre_info;
    int id_Supprimer;
    printf("Entrez le id du livre à supprimer : ");
    scanf(" %d", &id_Supprimer);
    int trouve = 0;
    for (int i = 0; i < nLivres; i++) {
        if (AllLivre[i].id == id_Supprimer)  {
            trouve = 1;
            for (int j = i; j < nLivres - 1; j++) {
                AllLivre[j] = AllLivre[j + 1];
            }
            nLivres--;
            printf("Livre supprimé avec succès.\n");
            break;
        }
    }
    if (!trouve) {
        printf("Livre non trouvé.\n");
    }
}

void AfficherTotal() {
    if (nLivres == 0) {
        printf("Aucun livre en stock.\n");
    } else {
        int total = 0;
        for (int i = 0; i < nLivres; i++) {
            total += AllLivre[i].Quantite;
        }
        printf("Nombre total de livres en stock : %d\n", total);
    }
}

int main() {
    int choix;
    do {printf("\n--------------------------------------------\n");
        printf("Menu de gestion de la librairie :\n");
        printf("1. Ajouter un livre au stock\n");
        printf("2. Afficher tous les livres disponibles\n");
        printf("3. Rechercher un livre par son titre\n");
        printf("4. Mettre à jour la quantité d'un livre\n");
        printf("5. Supprimer un livre du stock\n");
        printf("6. Afficher le nombre total de livres en stock\n");
        printf("Entrez votre choix (0 pour quitter) : ");
        printf("\n--------------------------------------------\n");

        scanf("%d", &choix);

        switch (choix) {
            case 1: Ajouter(); break;
            case 2: Afficher(); break;
            case 3: Rechercher(); break;
            case 4: Modifier(); break;
            case 5: Supprimer(); break;
            case 6: AfficherTotal(); break;
            case 0: printf("Au revoir!\n"); break;
            default: printf("Choix invalide. Veuillez réessayer.\n"); break;
        }
    } while (choix != 0);
    return 0;
}
