#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Declaration de la strecture Etudient avec (numero,nom,prenom,date_de_naissance,departement,note_generale)
struct Etudiant {
    int numero;
    char nom[30],prenom[30],date_de_naissance[11],departement[30];
    float note_generale;
};

// Declaration de le tabeaus de strecture Etudient pour stocker les etudients
struct Etudiant etudiants[100] = {
    //Des valeur initial pour remplire le tableau
    {1,"KAWTAR","SHAIMI","30-07-2001","DEV",20},
    {2,"BADR","SLAOUI","06-10-2003","DEV",14},
    {3,"AHLAM","MEHDAOUI","06-11-2004","DEV",13.5},
    {4,"WALID","HADDOUCH","28-03-2000","MATH",18},
    {5,"ABDELAH","BADRAWI","01-10-1997","MATH",7.5},
    {6,"LEILA","SKITIWI","07-08-2005","PC",2},
    {7,"LAYALI","CHAWNI","29-12-2002","PC",14},
    {8,"FATI","ZOUZAF","16-01-2001","SVI",5},
};


//Declaration des varriable utiliser
int i,j,etudiants_c=8,id=8;
char nv_nom[30], nv_prenom[30],nv_date[11],nv_departement[30];
int nv_numero, choix;
float nv_note;

//function pour ajouter 1 ou plusieur etudients
void ajouter(int num){
    //Loop d'ajout d'etudients selon le numero souetter
    for(i=0;i<num;i++){
        //Afficher um message si l'université est plein
        if(etudiants_c>100){
            printf("L'université est plein !");
            break;
        }
        //remplisage des info
        printf("Entrez le nom: ");
        scanf("%s",etudiants[etudiants_c].nom);
        printf("Entrez le prenom: ");
        scanf("%s",etudiants[etudiants_c].prenom);
        printf("Entrez le date de naissance dans ce format(DD-MM-YYYY): ");
        scanf("%s",etudiants[etudiants_c].date_de_naissance);

        //Prendre le curr time en second
        time_t now = time(NULL);
        // Convertir le time to localtime
        struct tm *local = localtime(&now);
        // Calculer le curr year
        int current_year = local->tm_year + 1900; // tm_year is years since 1900

        int day,month,year;
        //Extract le day month year de date naissance
        sscanf(etudiants[etudiants_c].date_de_naissance,"%2d-%2d-%4d",&day, &month, &year);
        //Check si la date est valide
        if(year>current_year || month>12 || day>31 || (month == 2 && day > 29)){
            printf("La date est invalid\n");
            break;
        }
        //caculer l'age
        int age = current_year - year;
        //check si l'age est valide
        if(age < 18 || age > 30){
            printf("L'age est invalid\n");
            break;
        }

        printf("Entrez le departement: ");
        scanf("%s",etudiants[etudiants_c].departement);
        printf("Entrez le note generale: ");
        scanf("%f",&etudiants[etudiants_c].note_generale);

        if(etudiants[etudiants_c].note_generale < 0 || etudiants[etudiants_c].note_generale > 20 ){
            printf("La note est invalid\n");
            break;
        }
        //Affecter une numero unique par defaut a l'etudiant
        etudiants[etudiants_c].numero = ++id ;
        //Incrementer le compteur d'etudiants par 1
        etudiants_c++;
    }
}

//function pour afficher tout les etudients
void afficher(){
    if(etudiants_c>0){
        for(i=0;i<etudiants_c;i++){
            printf("Le numero :%d, Le nom :%s, Le prenom :%s, La date de naissance :%s, La departement :%s, La note generale:%.2f\n",etudiants[i].numero,etudiants[i].nom,etudiants[i].prenom,etudiants[i].date_de_naissance,etudiants[i].departement,etudiants[i].note_generale);
        }
    }else{
        printf("La liste d etudiants est vide !\n");
    }
}

//function pour rechercher un etudients par nom
void chercherParNom(){
    //Declarer le varriable founded pour check si l'etudient existe ou non
    int founded=0;

    if(etudiants_c>0){
        //Demander a le user d'entrer le non
        printf("Entez le nom :");
        scanf("%s",nv_nom);

        //rechercher le nom dans la list des etudients
        for(i=0;i<etudiants_c;i++){
            //si le nom est trouver afficher ler info d'etudient
            if(strcmp(nv_nom,etudiants[i].nom)==0){
                printf("Le numero :%d, Le nom :%s, Le prenom :%s, La date de naissance :%s, La departement :%s, La note generale:%.2f\n",etudiants[i].numero,etudiants[i].nom,etudiants[i].prenom,etudiants[i].date_de_naissance,etudiants[i].departement,etudiants[i].note_generale);
                founded=1;
                break;
            }
        }

        //ِAfficher un message si l'etudient n'existe pas
        if(!founded){
            printf("Aucun etudiant avec ce nom !\n");
        }

    }else{
        printf("La liste d etudiants est vide !\n");
    }
}

//function pour rechercher un ou plusieurs etudients par nom
void chercherParNom_tout_elm(){
    //Declarer le varriable founded pour check si l'etudient existe ou non
    int founded=0;

    if(etudiants_c>0){
        //Demander a le user d'entrer le non
        printf("Entez le nom :");
        scanf("%s",nv_nom);

        //rechercher le nom dans la list des etudients
        for(i=0;i<etudiants_c;i++){
            //si le nom est trouver afficher ler info d'etudient
            if(strcmp(nv_nom,etudiants[i].nom)==0){
                printf("Le numero :%d, Le nom :%s, Le prenom :%s, La date de naissance :%s, La departement :%s, La note generale:%.2f\n",etudiants[i].numero,etudiants[i].nom,etudiants[i].prenom,etudiants[i].date_de_naissance,etudiants[i].departement,etudiants[i].note_generale);
                founded=1;
            }
        }

        //ِAfficher un message si l'etudient n'existe pas
        if(!founded){
            printf("Aucun etudiant avec ce nom !\n");
        }

    }else{
        printf("La liste d etudiants est vide !\n");
    }
}

//function pour rechercher le dernier etudients par nom
void chercherParNom_dernier_elm(){
    //Declarer le varriable founded pour check si l'etudient existe ou non
    int founded=0;

    if(etudiants_c>0){
        //Demander a le user d'entrer le non
        printf("Entez le nom :");
        scanf("%s",nv_nom);

        //rechercher le nom dans la list des etudients
        for(i=etudiants_c;i>=0;i++){
            //si le nom est trouver afficher ler info d'etudient
            if(strcmp(nv_nom,etudiants[i].nom)==0){
                printf("Le numero :%d, Le nom :%s, Le prenom :%s, La date de naissance :%s, La departement :%s, La note generale:%.2f\n",etudiants[i].numero,etudiants[i].nom,etudiants[i].prenom,etudiants[i].date_de_naissance,etudiants[i].departement,etudiants[i].note_generale);
                founded=1;
                break;
            }
        }

        //ِAfficher un message si l'etudient n'existe pas
        if(!founded){
            printf("Aucun etudiant avec ce nom !\n");
        }

    }else{
        printf("La liste d etudiants est vide !\n");
    }
}

//function pour rechercher les dernier nombre etudients par nom
void chercherParNom_dernier_num_elm(){
    //Declarer le varriable founded pour check si l'etudient existe ou non
    int founded=0,founded_count=0;

    if(etudiants_c>0){
        //Demander a le user d'entrer le non
        printf("Entez le nom :");
        scanf("%s",nv_nom);

        //rechercher le nom dans la list des etudients
        for(i=etudiants_c;i>=0;i++){
            //si le nom est trouver afficher ler info d'etudient
            if(strcmp(nv_nom,etudiants[i].nom)==0){
                printf("Le numero :%d, Le nom :%s, Le prenom :%s, La date de naissance :%s, La departement :%s, La note generale:%.2f\n",etudiants[i].numero,etudiants[i].nom,etudiants[i].prenom,etudiants[i].date_de_naissance,etudiants[i].departement,etudiants[i].note_generale);
                founded=1;
                founded_count++;
                if(founded_count == 2){
                    break;
                }
            }
        }

        //ِAfficher un message si l'etudient n'existe pas
        if(!founded){
            printf("Aucun etudiant avec ce nom !\n");
        }

    }else{
        printf("La liste d etudiants est vide !\n");
    }
}

//function pour rechercher les premier nombre etudients par nom
void chercherParNom_premier_num_elm(){
    //Declarer le varriable founded pour check si l'etudient existe ou non
    int founded=0,founded_count=0;

    if(etudiants_c>0){
        //Demander a le user d'entrer le non
        printf("Entez le nom :");
        scanf("%s",nv_nom);

        //rechercher le nom dans la list des etudients
        for(i=0;i<etudiants_c;i++){
            //si le nom est trouver afficher ler info d'etudient
            if(strcmp(nv_nom,etudiants[i].nom)==0){
                printf("Le numero :%d, Le nom :%s, Le prenom :%s, La date de naissance :%s, La departement :%s, La note generale:%.2f\n",etudiants[i].numero,etudiants[i].nom,etudiants[i].prenom,etudiants[i].date_de_naissance,etudiants[i].departement,etudiants[i].note_generale);
                founded=1;
                founded_count++;
                if(founded_count == 2){
                    break;
                }
            }
        }

        //ِAfficher un message si l'etudient n'existe pas
        if(!founded){
            printf("Aucun etudiant avec ce nom !\n");
        }

    }else{
        printf("La liste d etudiants est vide !\n");
    }
}

//function pour rechercher un ou plusieurs etudients par departement
void chercherParDepart(){
    //Declarer le varriable founded pour check si l'etudient existe ou non
    int founded=0;

    if(etudiants_c>0){
        //Demander a le user d'entrer le departement
        printf("Entez la departement :");
        scanf("%s",nv_departement);

        //rechercher le departement dans la list des etudients
        for(i=0;i<etudiants_c;i++){
            //si le departement est trouver afficher ler info d'etudient
            if(strcmp(nv_departement,etudiants[i].departement)==0){
                printf("Le numero :%d, Le nom :%s, Le prenom :%s, La date de naissance :%s, La departement :%s, La note generale:%.2f\n",etudiants[i].numero,etudiants[i].nom,etudiants[i].prenom,etudiants[i].date_de_naissance,etudiants[i].departement,etudiants[i].note_generale);
                founded=1;
            }
        }
        //ِAfficher un message si l'etudient n'existe pas
        if(!founded){
            printf("Aucune departement trouvee !\n");
        }
    }else{
        printf("La liste d etudiants est vide !\n");
    }
}

//function pour rechercher un ou plusieurs etudients par departement
void chercherParDepart_tout_elm(){
    //Declarer le varriable founded pour check si l'etudient existe ou non
    int founded=0;

    if(etudiants_c>0){
        //Demander a le user d'entrer le departement
        printf("Entez la departement :");
        scanf("%s",nv_departement);

        //rechercher le departement dans la list des etudients
        for(i=0;i<etudiants_c;i++){
            //si le departement est trouver afficher ler info d'etudient
            if(strcmp(nv_departement,etudiants[i].departement)==0){
                printf("Le numero :%d, Le nom :%s, Le prenom :%s, La date de naissance :%s, La departement :%s, La note generale:%.2f\n",etudiants[i].numero,etudiants[i].nom,etudiants[i].prenom,etudiants[i].date_de_naissance,etudiants[i].departement,etudiants[i].note_generale);
                founded=1;
            }
        }

        //ِAfficher un message si l'etudient n'existe pas
        if(!founded){
            printf("Aucun etudiant avec ce nom !\n");
        }

    }else{
        printf("La liste d etudiants est vide !\n");
    }
}

//function pour rechercher le dernier etudients par departement
void chercherParDepart_dernier_elm(){
    //Declarer le varriable founded pour check si l'etudient existe ou non
    int founded=0;

    if(etudiants_c>0){
        //Demander a le user d'entrer le departement
        printf("Entez la departement :");
        scanf("%s",nv_departement);

        //rechercher le departement dans la list des etudients
        for(i=etudiants_c;i>=0;i--){
            //si le departement est trouver afficher ler info d'etudient
            if(strcmp(nv_departement,etudiants[i].departement)==0){
                printf("Le numero :%d, Le nom :%s, Le prenom :%s, La date de naissance :%s, La departement :%s, La note generale:%.2f\n",etudiants[i].numero,etudiants[i].nom,etudiants[i].prenom,etudiants[i].date_de_naissance,etudiants[i].departement,etudiants[i].note_generale);
                founded=1;
                break;
            }
        }

        //ِAfficher un message si l'etudient n'existe pas
        if(!founded){
            printf("Aucun etudiant avec ce nom !\n");
        }

    }else{
        printf("La liste d etudiants est vide !\n");
    }
}

//function pour rechercher les dernier nombre etudients par departement
void chercherParDepart_dernier_num_elm(){
    //Declarer le varriable founded pour check si l'etudient existe ou non
    int founded=0,founded_count=0;

    if(etudiants_c>0){
        //Demander a le user d'entrer le departement
        printf("Entez la departement :");
        scanf("%s",nv_departement);

        //rechercher le departement dans la list des etudients
        for(i=etudiants_c;i>=0;i--){
            //si le departement est trouver afficher ler info d'etudient
            if(strcmp(nv_departement,etudiants[i].departement)==0){
                printf("Le numero :%d, Le nom :%s, Le prenom :%s, La date de naissance :%s, La departement :%s, La note generale:%.2f\n",etudiants[i].numero,etudiants[i].nom,etudiants[i].prenom,etudiants[i].date_de_naissance,etudiants[i].departement,etudiants[i].note_generale);
                founded=1;
                founded_count++;
                if(founded_count == 2){
                    break;
                }
            }
        }

        //ِAfficher un message si l'etudient n'existe pas
        if(!founded){
            printf("Aucun etudiant avec ce nom !\n");
        }

    }else{
        printf("La liste d etudiants est vide !\n");
    }
}

//function pour rechercher les premier nombre etudients par departement
void chercherParDepart_premier_num_elm(){
    //Declarer le varriable founded pour check si l'etudient existe ou non
    int founded=0,founded_count=0;

    if(etudiants_c>0){
        //Demander a le user d'entrer le departement
        printf("Entez la departement :");
        scanf("%s",nv_departement);

        //rechercher le departement dans la list des etudients
        for(i=0;i<etudiants_c;i++){
            //si le departement est trouver afficher ler info d'etudient
            if(strcmp(nv_departement,etudiants[i].departement)==0){
                printf("Le numero :%d, Le nom :%s, Le prenom :%s, La date de naissance :%s, La departement :%s, La note generale:%.2f\n",etudiants[i].numero,etudiants[i].nom,etudiants[i].prenom,etudiants[i].date_de_naissance,etudiants[i].departement,etudiants[i].note_generale);
                founded=1;
                founded_count++;
                if(founded_count == 2){
                    break;
                }
            }
        }

        //ِAfficher un message si l'etudient n'existe pas
        if(!founded){
            printf("Aucun etudiant avec ce nom !\n");
        }

    }else{
        printf("La liste d etudiants est vide !\n");
    }
}

//function pour modifier un etudients par numero
void modifier(){
    //Declarer le varriable founded pour check si l'etudient est modifier ou non
    int updated=0;

    if(etudiants_c>0){
        //Demander a le user d'entrer le numero
        printf("Entez le numero: ");
        scanf("%d",&nv_numero);

        //Demander a le user d'entrer les nouveaux info
        printf("Entez le nouveau nom: ");
        scanf("%s",nv_nom);
        printf("Entez le nouveau prenom: ");
        scanf("%s",nv_prenom);
        printf("Entez la nouvelle date de naissance: ");
        scanf("%s",nv_date);
        printf("Entez la nouvelle departement: ");
        scanf("%s",nv_departement);
        printf("Entez la nouvelle note generale: ");
        scanf("%f",&nv_note);

        //rechercher l'etudient dans la list des etudients
        for(i=0;i<etudiants_c;i++){
            //si le l'etudient est trouver modifier les info d'etudient
            if(nv_numero==etudiants[i].numero){
                strcpy(etudiants[i].nom,nv_nom);
                strcpy(etudiants[i].prenom,nv_prenom);
                strcpy(etudiants[i].date_de_naissance,nv_date);
                strcpy(etudiants[i].departement,nv_departement);
                etudiants[i].note_generale=nv_note;
                updated=1;
                //stop si l'etudient est modifier
                break;
            }
        }

        //ِAfficher un message si l'etudient n'existe pas
        if(!updated){
            printf("Aucun etudiant avec ce numero !\n");
        }
        //ِAfficher un message modifier avec succee
        else{
            printf("Etudient modifier avec succee !\n");
        }

    }else{
        printf("La liste d etudiants est vide !");
    }
}

//function pour modifier tout les etudients par nom
void modifier_tout_elm(){
    //Declarer le varriable founded pour check si l'etudient est modifier ou non
    int updated=0;

    if(etudiants_c>0){
        //Demander a le user d'entrer le nom
        printf("Entez le nom :");
        scanf("%s",nv_nom);

        //Demander a le user d'entrer les nouveaux info
        printf("Entez le nouveau nom: ");
        scanf("%s",nv_nom);
        printf("Entez le nouveau prenom: ");
        scanf("%s",nv_prenom);
        printf("Entez la nouvelle date de naissance: ");
        scanf("%s",nv_date);
        printf("Entez la nouvelle departement: ");
        scanf("%s",nv_departement);
        printf("Entez la nouvelle note generale: ");
        scanf("%f",&nv_note);

        //rechercher l'etudient dans la list des etudients
        for(i=0;i<etudiants_c;i++){
            //si le l'etudient est trouver modifier les info d'etudient
            if(strcmp(nv_nom,etudiants[i].nom)==0){
                strcpy(etudiants[i].nom,nv_nom);
                strcpy(etudiants[i].prenom,nv_prenom);
                strcpy(etudiants[i].date_de_naissance,nv_date);
                strcpy(etudiants[i].departement,nv_departement);
                etudiants[i].note_generale=nv_note;
                updated=1;
            }
        }

        //ِAfficher un message si l'etudient n'existe pas
        if(!updated){
            printf("Aucun etudiant avec ce numero !\n");
        }
        //ِAfficher un message modifier avec succee
        else{
            printf("Etudient modifier avec succee !\n");
        }

    }else{
        printf("La liste d etudiants est vide !");
    }
}

//function pour modifier le dernier etudients par nom
void modifier_dernier_elm(){
    //Declarer le varriable founded pour check si l'etudient est modifier ou non
    int updated=0;

    if(etudiants_c>0){
        //Demander a le user d'entrer le nom
        printf("Entez le nom :");
        scanf("%s",nv_nom);

        //Demander a le user d'entrer les nouveaux info
        printf("Entez le nouveau nom: ");
        scanf("%s",nv_nom);
        printf("Entez le nouveau prenom: ");
        scanf("%s",nv_prenom);
        printf("Entez la nouvelle date de naissance: ");
        scanf("%s",nv_date);
        printf("Entez la nouvelle departement: ");
        scanf("%s",nv_departement);
        printf("Entez la nouvelle note generale: ");
        scanf("%f",&nv_note);

        //rechercher l'etudient dans la list des etudients
        for(i=etudiants_c;i>=0;i--){
            //si le l'etudient est trouver modifier les info d'etudient
            if(strcmp(nv_nom,etudiants[i].nom)==0){
                strcpy(etudiants[i].nom,nv_nom);
                strcpy(etudiants[i].prenom,nv_prenom);
                strcpy(etudiants[i].date_de_naissance,nv_date);
                strcpy(etudiants[i].departement,nv_departement);
                etudiants[i].note_generale=nv_note;
                updated=1;
                break;
            }
        }

        //ِAfficher un message si l'etudient n'existe pas
        if(!updated){
            printf("Aucun etudiant avec ce numero !\n");
        }
        //ِAfficher un message modifier avec succee
        else{
            printf("Etudient modifier avec succee !\n");
        }

    }else{
        printf("La liste d etudiants est vide !");
    }
}

//function pour modifier les dernier nombre etudients par nom
void modifier_dernier_num_elm(){
    //Declarer le varriable founded pour check si l'etudient est modifier ou non
    int updated=0,updated_count=0;

    if(etudiants_c>0){
        //Demander a le user d'entrer le nom
        printf("Entez le nom :");
        scanf("%s",nv_nom);

        //Demander a le user d'entrer les nouveaux info
        printf("Entez le nouveau nom: ");
        scanf("%s",nv_nom);
        printf("Entez le nouveau prenom: ");
        scanf("%s",nv_prenom);
        printf("Entez la nouvelle date de naissance: ");
        scanf("%s",nv_date);
        printf("Entez la nouvelle departement: ");
        scanf("%s",nv_departement);
        printf("Entez la nouvelle note generale: ");
        scanf("%f",&nv_note);

        //rechercher l'etudient dans la list des etudients
        for(i=etudiants_c;i>=0;i--){
            //si le l'etudient est trouver modifier les info d'etudient
            if(strcmp(nv_nom,etudiants[i].nom)==0){
                strcpy(etudiants[i].nom,nv_nom);
                strcpy(etudiants[i].prenom,nv_prenom);
                strcpy(etudiants[i].date_de_naissance,nv_date);
                strcpy(etudiants[i].departement,nv_departement);
                etudiants[i].note_generale=nv_note;
                updated=1;
                updated_count++;
                if(updated_count == 2){
                    break;
                }
            }
        }

        //ِAfficher un message si l'etudient n'existe pas
        if(!updated){
            printf("Aucun etudiant avec ce numero !\n");
        }
        //ِAfficher un message modifier avec succee
        else{
            printf("Etudient modifier avec succee !\n");
        }

    }else{
        printf("La liste d etudiants est vide !");
    }
}

//function pour modifier les premier nombre etudients par nom
void modifier_premier_num_elm(){
    //Declarer le varriable founded pour check si l'etudient est modifier ou non
    int updated=0,updated_count=0;

    if(etudiants_c>0){
        //Demander a le user d'entrer le nom
        printf("Entez le nom :");
        scanf("%s",nv_nom);

        //Demander a le user d'entrer les nouveaux info
        printf("Entez le nouveau nom: ");
        scanf("%s",nv_nom);
        printf("Entez le nouveau prenom: ");
        scanf("%s",nv_prenom);
        printf("Entez la nouvelle date de naissance: ");
        scanf("%s",nv_date);
        printf("Entez la nouvelle departement: ");
        scanf("%s",nv_departement);
        printf("Entez la nouvelle note generale: ");
        scanf("%f",&nv_note);

        //rechercher l'etudient dans la list des etudients
        for(i=0;i<etudiants_c;i++){
            //si le l'etudient est trouver modifier les info d'etudient
            if(strcmp(nv_nom,etudiants[i].nom)==0){
                strcpy(etudiants[i].nom,nv_nom);
                strcpy(etudiants[i].prenom,nv_prenom);
                strcpy(etudiants[i].date_de_naissance,nv_date);
                strcpy(etudiants[i].departement,nv_departement);
                etudiants[i].note_generale=nv_note;
                updated=1;
                updated_count++;
                if(updated_count == 2){
                    break;
                }
            }
        }

        //ِAfficher un message si l'etudient n'existe pas
        if(!updated){
            printf("Aucun etudiant avec ce numero !\n");
        }
        //ِAfficher un message modifier avec succee
        else{
            printf("Etudient modifier avec succee !\n");
        }

    }else{
        printf("La liste d etudiants est vide !");
    }
}

//function pour supprimer un etudients par numero
void supprimer(){
    //Declarer le varriable founded pour check si l'etudient est supprimer ou non
    int deleted=0;

    if(etudiants_c>0){
        //Demander a le user d'entrer le numero
        printf("Entez le numero :");
        scanf("%d",&nv_numero);

        //rechercher l'etudient dans la list des etudients
        for(i=0;i<etudiants_c;i++){
            //si le l'etudient est trouver supprimer le
            if(nv_numero==etudiants[i].numero){
                //Decrementer le compteur d'etudients par 1
                etudiants_c--;
                //Faire un deplacement a gauche pour supprimer l'etudient
                for(j=i;j<etudiants_c;j++){
                    strcpy(etudiants[j].nom,etudiants[j+1].nom);
                    strcpy(etudiants[j].prenom,etudiants[j+1].prenom);
                    strcpy(etudiants[j].date_de_naissance,etudiants[j+1].date_de_naissance);
                    strcpy(etudiants[j].departement,etudiants[j+1].departement);
                    etudiants[j].note_generale=etudiants[j+1].note_generale;
                    etudiants[j].numero = etudiants[j+1].numero;
               }

               deleted=1;
                break;
            }
        }

        //ِAfficher un message si l'etudient n'existe pas
        if(!deleted){
            printf("Aucun etudiant avec ce numero !\n");
        }
        //ِAfficher un message supprimer avec succee
        else{
            printf("Etudient supprimer avec succee !\n");
        }

    }else{
        printf("La liste d etudiants est vide !\n");
    }
}

//function pour supprimer tout les etudients par nom
void supprimer_tout_elm(){
    //Declarer le varriable founded pour check si l'etudient est supprimer ou non
    int deleted=0;

    if(etudiants_c>0){
        //Demander a le user d'entrer le nom
        printf("Entez le nom :");
        scanf("%s",nv_nom);

        //rechercher l'etudient dans la list des etudients
        for(i=etudiants_c;i>=0;i--){
            //si le l'etudient est trouver supprimer le
            if(strcmp(nv_nom,etudiants[i].nom)==0){
                //Decrementer le compteur d'etudients par 1
                etudiants_c--;
                //Faire un deplacement a gauche pour supprimer l'etudient
                for(j=i;j<etudiants_c;j++){
                    strcpy(etudiants[j].nom,etudiants[j+1].nom);
                    strcpy(etudiants[j].prenom,etudiants[j+1].prenom);
                    strcpy(etudiants[j].date_de_naissance,etudiants[j+1].date_de_naissance);
                    strcpy(etudiants[j].departement,etudiants[j+1].departement);
                    etudiants[j].note_generale=etudiants[j+1].note_generale;
                    etudiants[j].numero = etudiants[j+1].numero;
               }

                deleted=1;
                i--;
            }
        }

        //ِAfficher un message si l'etudient n'existe pas
        if(!deleted){
            printf("Aucun etudiant avec ce numero !\n");
        }
        //ِAfficher un message supprimer avec succee
        else{
            printf("Etudient supprimer avec succee !\n");
        }

    }else{
        printf("La liste d etudiants est vide !\n");
    }
}

//function pour supprimer le dernier etudients par nom
void supprimer_dernier_elm(){
    //Declarer le varriable founded pour check si l'etudient est supprimer ou non
    int deleted=0;

    if(etudiants_c>0){
        //Demander a le user d'entrer le nom
        printf("Entez le nom :");
        scanf("%s",nv_nom);

        //rechercher l'etudient dans la list des etudients
        for(i=etudiants_c;i>=0;i--){
            //si le l'etudient est trouver supprimer le
            if(strcmp(nv_nom,etudiants[i].nom)==0){
                //Decrementer le compteur d'etudients par 1
                etudiants_c--;
                //Faire un deplacement a gauche pour supprimer l'etudient
                for(j=i;j<etudiants_c;j++){
                    strcpy(etudiants[j].nom,etudiants[j+1].nom);
                    strcpy(etudiants[j].prenom,etudiants[j+1].prenom);
                    strcpy(etudiants[j].date_de_naissance,etudiants[j+1].date_de_naissance);
                    strcpy(etudiants[j].departement,etudiants[j+1].departement);
                    etudiants[j].note_generale=etudiants[j+1].note_generale;
                    etudiants[j].numero = etudiants[j+1].numero;
               }

               deleted=1;
                break;
            }
        }

        //ِAfficher un message si l'etudient n'existe pas
        if(!deleted){
            printf("Aucun etudiant avec ce numero !\n");
        }
        //ِAfficher un message supprimer avec succee
        else{
            printf("Etudient supprimer avec succee !\n");
        }

    }else{
        printf("La liste d etudiants est vide !\n");
    }
}

//function pour supprimer les dernier nombre etudients par nom
void supprimer_dernier_num_elm(){
    //Declarer le varriable founded pour check si l'etudient est supprimer ou non
    int deleted=0,delete_count=0;

    if(etudiants_c>0){
        //Demander a le user d'entrer le nom
        printf("Entez le nom :");
        scanf("%s",nv_nom);

        //rechercher l'etudient dans la list des etudients
        for(i=etudiants_c;i>=0;i--){
            //si le l'etudient est trouver supprimer le
            if(strcmp(nv_nom,etudiants[i].nom)==0){
                //Decrementer le compteur d'etudients par 1
                etudiants_c--;
                //Faire un deplacement a gauche pour supprimer l'etudient
                for(j=i;j<etudiants_c;j++){
                    strcpy(etudiants[j].nom,etudiants[j+1].nom);
                    strcpy(etudiants[j].prenom,etudiants[j+1].prenom);
                    strcpy(etudiants[j].date_de_naissance,etudiants[j+1].date_de_naissance);
                    strcpy(etudiants[j].departement,etudiants[j+1].departement);
                    etudiants[j].note_generale=etudiants[j+1].note_generale;
                    etudiants[j].numero = etudiants[j+1].numero;
               }

               deleted=1;
               delete_count++;
               if(delete_count == 2){
                break;
               }

               i++;
            }
        }

        //ِAfficher un message si l'etudient n'existe pas
        if(!deleted){
            printf("Aucun etudiant avec ce numero !\n");
        }
        //ِAfficher un message supprimer avec succee
        else{
            printf("Etudient supprimer avec succee !\n");
        }

    }else{
        printf("La liste d etudiants est vide !\n");
    }
}

//function pour supprimer les premier nombre etudients par nom
void supprimer_premier_num_elm(){
    //Declarer le varriable founded pour check si l'etudient est supprimer ou non
    int deleted=0,delete_count=0;

    if(etudiants_c>0){
        //Demander a le user d'entrer le nom
        printf("Entez le nom :");
        scanf("%s",nv_nom);

        //rechercher l'etudient dans la list des etudients
        for(i=etudiants_c;i>=0;i--){
            //si le l'etudient est trouver supprimer le
            if(strcmp(nv_nom,etudiants[i].nom)==0){
                //Decrementer le compteur d'etudients par 1
                etudiants_c--;
                //Faire un deplacement a gauche pour supprimer l'etudient
                for(j=i;j<etudiants_c;j++){
                    strcpy(etudiants[j].nom,etudiants[j+1].nom);
                    strcpy(etudiants[j].prenom,etudiants[j+1].prenom);
                    strcpy(etudiants[j].date_de_naissance,etudiants[j+1].date_de_naissance);
                    strcpy(etudiants[j].departement,etudiants[j+1].departement);
                    etudiants[j].note_generale=etudiants[j+1].note_generale;
                    etudiants[j].numero = etudiants[j+1].numero;
               }

               deleted=1;
               delete_count++;
               if(delete_count == 2){
                break;
               }
                i--;
            }
        }

        //ِAfficher un message si l'etudient n'existe pas
        if(!deleted){
            printf("Aucun etudiant avec ce numero !\n");
        }
        //ِAfficher un message supprimer avec succee
        else{
            printf("Etudient supprimer avec succee !\n");
        }

    }else{
        printf("La liste d etudiants est vide !\n");
    }
}

//function pour calculer le moyenne de chaque departement et le moyenne d'universite generale
void calcule_moyenne(){
    if(etudiants_c>0){

        // Declaration de la strecture Departement avec (nom,total_note_generale,numero_total_etudiants)
        struct Departement {
            char nom[30];
            float total_note_generale;
            int numero_total_etudiants;
        };

        // Declaration de le tabeaus de strecture Etudient pour stocker les etudients
        struct Departement departements[100];

        //Declaration du compteur des departement
        int departements_count = 0;

        //Boucler tout les etudient pour calculer le total_note_generale et le numero_total_etudiants pour chaque departement
        for (i = 0;i<etudiants_c;i++){
            //declarer departement_founded pour chercher le index de departement du current etudient si le departement nexist pa departement_founded = -1
            int departement_founded = -1;

            //chercher le index de departement du current etudient dans la list des departemens
            for (j = 0;j<departements_count;j++){
                //si le departement est exister departement_founded prendre leur index dans le tableau
                if(strcmp(etudiants[i].departement,departements[j].nom)==0){
                    departement_founded = j;
                    //stop aprer trouver l'index de departement
                    break;
                }
            }

            //si le departement n'exister pas dans le tableau ajouter le
            if(departement_founded == -1){
                strcpy(departements[departements_count].nom,etudiants[i].departement);
                departements[departements_count].total_note_generale = etudiants[i].note_generale;
                departements[departements_count].numero_total_etudiants = 1;
                departements_count++;
            }
            //sinon increment le total_note_generale par la note_generale de current etudient + incrementer numero_total_etudiants par 1
            else{
                departements[departement_founded].total_note_generale += etudiants[i].note_generale;
                departements[departement_founded].numero_total_etudiants++;
            }
        }

        //Declaration des varriable des calcule
        float total_moyenne_departements = 0, moyenne_universite;

        //boucler tout les departement
        for (i = 0; i < departements_count; i++) {
            //caculer le moyenne de chaque departement est le afficher
            float moyenne_departement = departements[i].total_note_generale / departements[i].numero_total_etudiants;
            printf("Departement: %s, Moyenne Departement: %.2f\n", departements[i].nom, moyenne_departement);

            //caculer la somme des moyennes des departements
            total_moyenne_departements += moyenne_departement;
        }

        //caculer le moyenne d'universite generale et le afficher
        moyenne_universite = total_moyenne_departements / departements_count;
        printf("Moyenne D'Universite Generale est: %.2f\n", moyenne_universite);

    }else{
        printf("La liste d etudiants est vide !\n");
    }
}

//function pour trier les etudients par ordre alphabetique des nom dw A -> Z
void tri_par_nom_a_z(){
    if(etudiants_c > 0){

        //Declaration de variable temporere de type struct Etudian pour le etuliser dans l'echenge des valeurs
        struct Etudiant temp;

        //Boucler tout les etudients
        for(i = 0 ; i < etudiants_c - 1 ; i++){
            //Declarer le var min pour stocker le index de min valeur
            int min = i;

            //Boucler tout les etudients pour comparer leur nom avec le nom d'etudient de index min
            for(j = i + 1 ; j < etudiants_c ; j++){
                //Si la soustractin de ASCII code de l'etudient de index min et l'etudient de index j est > 0
                //Cette a dire l'etudient de index j est < a l'etudient de index min
                if(strcmp(etudiants[min].nom,etudiants[j].nom) > 0){
                    //dans cette cas affecter l'index j a le var min
                    min = j;
                }
           }
            //Dans le fin echanger la valeur d'etudient de index min par la valeur d'etudient de index i a l'aide de var temp
            temp = etudiants[min];
            etudiants[min] = etudiants[i];
            etudiants[i] = temp;
       }

        //Appeler la function afficher pour afficher les etudients trier
       afficher();

    }else{
        printf("No contact dans le carnet \n");
    }

}

//function pour trier les etudients par ordre alphabetique des nom de Z -> A
void tri_par_nom_z_a(){
    if(etudiants_c > 0){

        //Declaration de variable temporere de type struct Etudian pour le etuliser dans l'echenge des valeurs
        struct Etudiant temp;

        //Boucler tout les etudients
        for(i = 0 ; i < etudiants_c - 1 ; i++){
            //Declarer le var max pour stocker le index de max valeur
            int max = i;

            //Boucler tout les etudients pour comparer leur nom avec le nom d'etudient de index max
            for(j = i + 1 ; j < etudiants_c ; j++){
                //Si la soustractin de ASCII code de l'etudient de index max et l'etudient de index j est < 0
                //Cette a dire l'etudient de index j est > a l'etudient de index max
                if(strcmp(etudiants[max].nom,etudiants[j].nom) < 0){
                    //dans cette cas affecter l'index j a le var max
                    max = j;
                }
           }
            //Dans le fin echanger la valeur d'etudient de index max par la valeur d'etudient de index i a l'aide de var temp
            temp = etudiants[max];
            etudiants[max] = etudiants[i];
            etudiants[i] = temp;
       }

        //Appeler la function afficher pour afficher les etudients trier
       afficher();

    }else{
        printf("No contact dans le carnet \n");
    }

}

//function pour trier les etudients par la note_generale desc
void tri_par_note_desc(){
    if(etudiants_c > 0){

        //Declaration de variable temporere de type struct Etudian pour le etuliser dans l'echenge des valeurs
        struct Etudiant temp;

        //Boucler tout les etudients
        for(i = 0 ; i < etudiants_c - 1 ; i++){
            //Declarer le var max pour stocker le index de max valeur
            int max = i;

            //Boucler tout les etudients pour comparer leur note_generale avec la note_generale d'etudient de index max
            for(j = i + 1 ; j < etudiants_c ; j++){
                //si la note_generale de l'index max est < a la note d'index j
                if(etudiants[max].note_generale < etudiants[j].note_generale){
                    //dans cette cas affecter l'index j a le var max
                    max = j;
                }
           }
           //Dans le fin echanger la valeur d'etudient de index max par la valeur d'etudient de index i a l'aide de var temp
            temp = etudiants[max];
            etudiants[max] = etudiants[i];
            etudiants[i] = temp;
       }

       //Appeler la function afficher pour afficher les etudients trier
       afficher();

    }else{
        printf("No contact dans le carnet \n");
    }

}

//function pour trier les etudients par la note_generale asc
void tri_par_note_asc(){
    if(etudiants_c > 0){

        //Declaration de variable temporere de type struct Etudian pour le etuliser dans l'echenge des valeurs
        struct Etudiant temp;

        //Boucler tout les etudients
        for(i = 0 ; i < etudiants_c - 1 ; i++){
            //Declarer le var min pour stocker le index de min valeur
            int min = i;

            //Boucler tout les etudients pour comparer leur note_generale avec la note_generale d'etudient de index min
            for(j = i + 1 ; j < etudiants_c ; j++){
                //si la note_generale de l'index min est > a la note d'index j
                if(etudiants[min].note_generale > etudiants[j].note_generale){
                    //dans cette cas affecter l'index j a le var min
                    min = j;
                }
           }
           //Dans le fin echanger la valeur d'etudient de index min par la valeur d'etudient de index i a l'aide de var temp
            temp = etudiants[min];
            etudiants[min] = etudiants[i];
            etudiants[i] = temp;
       }

       //Appeler la function afficher pour afficher les etudients trier
       afficher();

    }else{
        printf("No contact dans le carnet \n");
    }

}

//function pour trier les etudients par reussite
void tri_par_reussite_desc(){
    if(etudiants_c > 0){

        //Declaration de variable temporere de type struct Etudian pour le etuliser dans l'echenge des valeurs
        struct Etudiant temp;

        //Boucler tout les etudients
        for(i = 0 ; i < etudiants_c - 1 ; i++){
            //Declarer le var max pour stocker le index de max valeur
            int max = i;

            //Boucler tout les etudients pour comparer leur note_generale avec la note_generale d'etudient de index max
            for(j = i + 1 ; j < etudiants_c ; j++){
                //si la note_generale de l'index max est < a la note d'index j
                if(etudiants[max].note_generale < etudiants[j].note_generale){
                    //dans cette cas affecter l'index j a le var max
                    max = j;
                }
           }
           //Dans le fin echanger la valeur d'etudient de index max par la valeur d'etudient de index i a l'aide de var temp
            temp = etudiants[max];
            etudiants[max] = etudiants[i];
            etudiants[i] = temp;
       }

       //Boucler tout les etudients
       for(i=0;i<etudiants_c;i++){
            //stop le boucle
            if(etudiants[i].note_generale < 10){
                break;
            }
            //Afficher seulement les etudient avec note_generale >= 10 trier par leur note_generale
            printf("Le numero :%d, Le nom :%s, Le prenom :%s, La date de naissance :%s, La departement :%s, La note generale:%.2f\n",etudiants[i].numero,etudiants[i].nom,etudiants[i].prenom,etudiants[i].date_de_naissance,etudiants[i].departement,etudiants[i].note_generale);
        }

    }else{
        printf("No contact dans le carnet \n");
    }

}

//function pour trier les etudients par reussite
void tri_par_reussite_asc(){
    if(etudiants_c > 0){

         //Declaration de variable temporere de type struct Etudian pour le etuliser dans l'echenge des valeurs
        struct Etudiant temp;

        //Boucler tout les etudients
        for(i = 0 ; i < etudiants_c - 1 ; i++){
            //Declarer le var min pour stocker le index de min valeur
            int min = i;

            //Boucler tout les etudients pour comparer leur note_generale avec la note_generale d'etudient de index min
            for(j = i + 1 ; j < etudiants_c ; j++){
                //si la note_generale de l'index min est > a la note d'index j
                if(etudiants[min].note_generale > etudiants[j].note_generale){
                    //dans cette cas affecter l'index j a le var min
                    min = j;
                }
           }
           //Dans le fin echanger la valeur d'etudient de index min par la valeur d'etudient de index i a l'aide de var temp
            temp = etudiants[min];
            etudiants[min] = etudiants[i];
            etudiants[i] = temp;
       }

       //Boucler tout les etudients
       for(i=0;i<etudiants_c;i++){
            //stop le boucle
            if(etudiants[i].note_generale < 10){
                //Skip le curr etudient pour affiche seulement les etudient avec note_generale >= 10
                continue;
            }
            //Afficher seulement les etudient avec note_generale >= 10 trier par leur note_generale
            printf("Le numero :%d, Le nom :%s, Le prenom :%s, La date de naissance :%s, La departement :%s, La note generale:%.2f\n",etudiants[i].numero,etudiants[i].nom,etudiants[i].prenom,etudiants[i].date_de_naissance,etudiants[i].departement,etudiants[i].note_generale);
        }

    }else{
        printf("No contact dans le carnet \n");
    }

}

//function afficher le nombre total etudiants
void nombre_total_etudiants(){
    printf("Nombre total d'etudiants est: %d\n",etudiants_c);
}

//function afficher le nombre total etudiants de chaque departement
void nombre_total_etudiants_par_departement(){
    if(etudiants_c>0){

        // Declaration de la strecture Departement avec (nom,numero_total_etudiants)
        struct Departement {
            char nom[30];
            int num_etudiants;
        };

        // Declaration de le tabeaus de strecture Etudient pour stocker les etudients
        struct Departement departements[100];

        //Declaration du compteur des departement
        int departements_count = 0;

        //Boucler tout les etudient pour calculer le numero_total_etudiants pour chaque departement
        for (i = 0;i<etudiants_c;i++){
            //declarer departement_founded pour chercher le index de departement du current etudient si le departement nexist pa departement_founded = -1
            int departement_founded = -1;

            //chercher le index de departement du current etudient dans la list des departemens
            for (j = 0;j<departements_count;j++){
                //si le departement est exister departement_founded prendre leur index dans le tableau
                if(strcmp(etudiants[i].departement,departements[j].nom)==0){
                    departement_founded = j;
                    //stop aprer trouver l'index de departement
                    break;
                }
            }

            //si le departement n'exister pas dans le tableau ajouter le
            if(departement_founded == -1){
                strcpy(departements[departements_count].nom,etudiants[i].departement);
                departements[departements_count].num_etudiants = 1;
                departements_count++;
            }
            //sinon incrementer numero_total_etudiants par 1
            else{
                departements[departement_founded].num_etudiants++;
            }
        }

        //Afficher chaque departement est sont nombre total d'etudiants
        for (i = 0; i < departements_count; i++) {
            printf("Deparetment: %s, Nombre total d'etudiants: %d\n", departements[i].nom, departements[i].num_etudiants);
        }

    }else{
        printf("La liste d etudiants est vide !\n");
    }
}

//functoin qui affiche a list des etudients par raport a un seuil donner
void etudiants_par_seuil(){

    if(etudiants_c>0){

        float seuil;
        //Demander a le user de entrer le seuil
        printf("Entrez le seuil: ");
        scanf("%f",&seuil);

        //Boucler tout les etudient
        for(i=0;i<etudiants_c;i++){
            //Afficher seulement les etudients avec une note_generale >= seuil
            if(etudiants[i].note_generale >= seuil){
                printf("Le numero :%d, Le nom :%s, Le prenom :%s, La date de naissance :%s, La departement :%s, La note generale:%.2f\n",etudiants[i].numero,etudiants[i].nom,etudiants[i].prenom,etudiants[i].date_de_naissance,etudiants[i].departement,etudiants[i].note_generale);
            }
        }

    }else{
        printf("La liste d etudiants est vide !\n");
    }


}

//function qui affiche les meilleur trois etudients
void meilleures_etudiants(){

    if(etudiants_c > 0){

        //Declaration de variable temporere de type struct Etudian pour le etuliser dans l'echenge des valeurs
        struct Etudiant temp;

        //Boucler tout les etudients
        for(i = 0 ; i < etudiants_c - 1 ; i++){
            //Declarer le var max pour stocker le index de max valeur
            int max = i;

            //Boucler tout les etudients pour comparer leur note_generale avec la note_generale d'etudient de index max
            for(j = i + 1 ; j < etudiants_c ; j++){
                //si la note_generale de l'index max est < a la note d'index j
                if(etudiants[max].note_generale < etudiants[j].note_generale){
                    //dans cette cas affecter l'index j a le var max
                    max = j;
                }
           }
           //Dans le fin echanger la valeur d'etudient de index max par la valeur d'etudient de index i a l'aide de var temp
            temp = etudiants[max];
            etudiants[max] = etudiants[i];
            etudiants[i] = temp;
       }
        //Afficher seulement les trois premier etudients
       for(i=0;i<3;i++){
            printf("Le numero :%d, Le nom :%s, Le prenom :%s, La date de naissance :%s, La departement :%s, La note generale:%.2f\n",etudiants[i].numero,etudiants[i].nom,etudiants[i].prenom,etudiants[i].date_de_naissance,etudiants[i].departement,etudiants[i].note_generale);
        }

    }else{
        printf("No contact dans le carnet \n");
    }

}

//function afficher le nombre total des etudiants reussi de chaque departement
void nombre_total_etudiants_reussi_par_departement(){
    if(etudiants_c>0){

        // Declaration de la strecture Departement avec (nom,numero_total_etudiants)
        struct Departement {
            char nom[30];
            int num_etudiants;
        };

        // Declaration de le tabeaus de strecture Etudient pour stocker les etudients
        struct Departement departements[100];

        //Declaration du compteur des departement
        int departements_count = 0;

        //Boucler seulement les etudient reussit pour calculer le numero_total_etudiants pour chaque departement
        for (i = 0;i<etudiants_c;i++){

            //declarer departement_founded pour chercher le index de departement du current etudient si le departement nexist pa departement_founded = -1
            int departement_founded = -1;
            //chercher le index de departement du current etudient dans la list des departemens
            for (j = 0;j<departements_count;j++){
                //si le departement est exister departement_founded prendre leur index dans le tableau
                if(strcmp(etudiants[i].departement,departements[j].nom)==0){
                    departement_founded = j;
                    //stop aprer trouver l'index de departement
                    break;
                }
            }

            //si le departement n'exister pas dans le tableau ajouter le
            if(departement_founded == -1){
                strcpy(departements[departements_count].nom,etudiants[i].departement);
                //si etudient est reussit initial num_etudiants par 1
                if(etudiants[i].note_generale >= 10){
                    departements[departements_count].num_etudiants = 1;
                }
                //sinon initial num_etudiants par 0
                else{
                    departements[departements_count].num_etudiants = 0;
                }
                departements_count++;
            }
            //sinon incrementer numero_total_etudiants par 1
            else{
                //si etudient est reussit incrementer num_etudiants par 1
                if(etudiants[i].note_generale >= 10){
                    departements[departement_founded].num_etudiants++;
                }
            }
        }

        //Afficher chaque departement est sont nombre total d'etudiants
        for (i = 0; i < departements_count; i++) {
            printf("Deparetment: %s, Nombre total d'etudiants: %d\n", departements[i].nom, departements[i].num_etudiants);
        }

    }else{
        printf("La liste d etudiants est vide !\n");
    }
}

int main()
{
    int isInt;
    while(1){

        //Afficher la menu principale
        printf("\nTapez 1 pour ajouter un etudiant.\n");
        printf("Tapez 2 pour afficher un etudiant.\n");
        printf("Tapez 3 pour rechercher un etudiant.\n");
        printf("Tapez 4 pour modifier un etudiant.\n");
        printf("Tapez 5 pour supprimer un etudiant.\n");
        printf("Tapez 6 pour calculer la moyenne generale.\n");
        printf("Tapez 7 pour tri des etudiants.\n");
        printf("Tapez 8 pour les statistiques.\n");
        printf("Tapez 9 pour quitter.\n");

        //Prendre le choix
        printf("\n<< Ajoutez votre choix >> : ");
        isInt = scanf("%d",&choix);
        //Check si le choix entrer est un numero
        if(!isInt){
            //Si le choix est un character ou un string supprimer tout les character entrer
            while(getchar() != '\n'){};
            //Affiche un message d'err
            printf("\nEntrer un nombre !\n");
            //Skip le switch et affiche le menu principale again
            continue;
        }
        switch(choix){
            case 1:{
                //Afficher la menu d'ajout
                int ajouter_choix;
                printf("\nTapez 1 ajouter un etudiant .\n");
                printf("Tapez 2 ajouter plusieur etudiant .\n");
                printf("\n<< Ajoutez votre choix >> .");

                //Prendre le choix d'ajout
                isInt = scanf("%d",&ajouter_choix);
                //Check si le choix entrer est un numero
                if(!isInt){
                    //Si le choix est un character ou un string supprimer tout les character entrer
                    while(getchar() != '\n'){};
                    //Affiche un message d'err
                    printf("\nEntrer un nombre !\n");
                    //Skip le switch et affiche le menu principale again
                    continue;
                }
                switch(ajouter_choix){
                    //Appler la function ajouter avec 1 pour ajouter un etudient
                    case 1: ajouter(1);break;
                    case 2: {
                        //Prendre le numero des etudients a ajouter
                        int num;
                        printf("Entrer le numero des etudients: ");
                        scanf("%d",&num);
                        //Appler la function ajouter avec e num  des etudients a ajouter
                        ajouter(num);
                        break;
                    }
                    //Afficher option invalid si l'option n'exist pas
                    default : printf("Option invalid\n");
                }
                break;
            }
            //Appler la function afficher pour afficher tout les etudients
            case 2: afficher();break;
            case 3:{
                int recherche_choix;
                //Afficher la menu de recherche
                printf("\nTapez 1 pour rechercher un etudiant par son nom .\n");
                printf("Tapez 2 pour rechercher un etudiant par le nom de departement .\n");
                //Prendre le choix de recherche
                printf("\n<< Ajoutez votre choix >> .");
                isInt = scanf("%d",&recherche_choix);
                //Check si le choix entrer est un numero
                if(!isInt){
                    //Si le choix est un character ou un string supprimer tout les character entrer
                    while(getchar() != '\n'){};
                    //Affiche un message d'err
                    printf("\nEntrer un nombre !\n");
                    //Skip le switch et affiche le menu principale again
                    continue;
                }
                switch(recherche_choix){
                    //Appler la function chercherParNom
                    case 1: chercherParNom();break;
                    //Appler la function chercherParDepart
                    case 2: chercherParDepart();break;
                    //Afficher option invalid si l'option n'exist pas
                    default : printf("Option invalid\n");
                }
                break;
            }
            //Appler la function modifier
            case 4: modifier();break;
            //Appler la function supprimer
            case 5: supprimer();break;
            //Appler la function calcule_moyenne
            case 6: calcule_moyenne();break;
            case 7: {
                //Afficher la menu de tri
                int tri_choix;
                printf("\nTapez 1 pour tri en ordre alphabetique de nom .\n");
                printf("Tapez 2 pour tri par note generale .\n");
                printf("Tapez 3 pour tri par reussite .\n");
                //Prendre le choix de tri
                printf("\n<< Ajoutez votre choix >> .");
                isInt = scanf("%d",&tri_choix);
                //Check si le choix entrer est un numero
                if(!isInt){
                    //Si le choix est un character ou un string supprimer tout les character entrer
                    while(getchar() != '\n'){};
                    //Affiche un message d'err
                    printf("\nEntrer un nombre !\n");
                    //Skip le switch et affiche le menu principale again
                    continue;
                }

                switch(tri_choix){
                    //Appler la function tri_par_nom
                    case 1: tri_par_nom_a_z();break;
                    //Appler la function tri_par_note
                    case 2: tri_par_note_desc();break;
                    //Appler la function tri_par_reussite
                    case 3: tri_par_reussite_desc();break;
                    //Afficher option invalid si l'option n'exist pas
                    default : printf("Option invalid\n");
                }
                break;
            }
            case 8: {
                //Afficher la menu de statistiques
                int statistiques_choix;
                printf("\nTapez 1 pour afficher nombre total d'etudiants .\n");
                printf("Tapez 2 pour afficher nombre total d'etudiants par departement .\n");
                printf("Tapez 3 pour afficher les etudiants par raport a un seuil .\n");
                printf("Tapez 4 pour afficher les trois meilleures etudiants .\n");
                printf("Tapez 5 pour afficher nombre total d'etudiants reussi par departement .\n");
                //Prendre le choix de statistiques
                printf("\n<< Ajoutez votre choix >> .");
                isInt = scanf("%d",&statistiques_choix);
                //Check si le choix entrer est un numero
                if(!isInt){
                    //Si le choix est un character ou un string supprimer tout les character entrer
                    while(getchar() != '\n'){};
                    //Affiche un message d'err
                    printf("\nEntrer un nombre !\n");
                    //Skip le switch et affiche le menu principale again
                    continue;
                }

                switch(statistiques_choix){
                    //Appler la function nombre_total_etudiants
                    case 1: nombre_total_etudiants();break;
                    //Appler la function nombre_total_etudiants_par_departement
                    case 2: nombre_total_etudiants_par_departement();break;
                    //Appler la function etudiants_par_seuil
                    case 3: etudiants_par_seuil();break;
                    //Appler la function meilleures_etudiants
                    case 4: meilleures_etudiants();break;
                    //Appler la function nombre_total_etudiants_reussi_par_departement
                    case 5: nombre_total_etudiants_reussi_par_departement();break;
                    //Afficher option invalid si l'option n'exist pas
                    default : printf("Option invalid\n");
                }
                break;
            }
            //Arreter le programme
            case 9: printf("Programme arreter\n");exit(0);
            //Afficher option invalid si l'option n'exist pas
            default : printf("Option invalid\n");
        }
    }
    return 0;
}
