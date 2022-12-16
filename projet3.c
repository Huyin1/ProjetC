#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<errno.h>

typedef struct tm date;

typedef struct produit
{
  char nom[64];
  double prix_unit;
  int stocks;
}produit;

typedef struct item_panier
{
  int idProd;  //le numero de produit
  double quantite;  //la quantite
  struct item_panier *suivant;  //le pointeur vers l'élément suivant de la liste
}item_panier;

typedef struct panier
{
  item_panier *head;  //la tete de la liste chainee
  date *date_ticket;  //la date de passage du panier
  double total;  //le prix total du panier
  int ticketid;  //le numero de ticket(repart de 0 chaque jour)
  int clientid;  //le numero de client
}panier;

typedef struct liste_produit
{
  int n;
  produit *p_liste_produit;
}liste_produit;

int Menu_(void);
int Menu_Caissier(void);
int Menu_Gerant(void);
void Menu_Panier(liste_produit *liste_produit1);
int Manipuler_Panier(void);
void Charger_Produites_EnStock(liste_produit *liste_produit1);
void Save_Produites_EnStock(const liste_produit *liste_produit1);
void Afficher_Produits_EnStock(const liste_produit *liste_produit1);
void Modifier_Produites_EnStock(liste_produit *liste_produit1);
void Add_Produites_EnStock(liste_produit *liste_produit1);
void Save_Panier_en_Compte(const panier *p_panier);
void Panier_Init(panier *liste_panier1);
int DemanderId_client(void);
void Panier_Free(panier *liste_panier1);
int Panier_Length(const panier *p_panier);
void Panier_Print(const panier *p_panier);
void Get_Time(date **pDateticket);
void Add_Panier(panier *p_panier,liste_produit*liste_produit1);
void Add_Front_Panier(liste_produit*liste_produit1,panier *p_panier,int id_Item2,double quantite2);
int Trouver_Item_Dans_Panier(const panier *p_panier,int id_Item);
void Afficher_Compte(void);
int Get_Ticketid(const panier*p_panier2);
double Trouver_Prix_Produit(const liste_produit *liste_produit1,int idprod);


void Add_Millieu_Panier(panier *p_panier);
void Delet_Panier(panier *p_panier);








int main(void)
{
  
  liste_produit list1;
  list1.n=6;
  list1.p_liste_produit=malloc(list1.n*sizeof(produit));
  strcpy(list1.p_liste_produit[0].nom,"Banane");
  strcpy(list1.p_liste_produit[1].nom,"Poire");
  strcpy(list1.p_liste_produit[2].nom,"Kro x12");
  strcpy(list1.p_liste_produit[3].nom,"Gigondas");
  strcpy(list1.p_liste_produit[4].nom,"Miels");
  strcpy(list1.p_liste_produit[5].nom,"Pain");
  list1.p_liste_produit[0].prix_unit=3.00;
  list1.p_liste_produit[1].prix_unit=3.40;
  list1.p_liste_produit[2].prix_unit=9.90;
  list1.p_liste_produit[3].prix_unit=14.00;
  list1.p_liste_produit[4].prix_unit=2.67;
  list1.p_liste_produit[5].prix_unit=6.66;
  list1.p_liste_produit[0].stocks=176;
  list1.p_liste_produit[1].stocks=127;
  list1.p_liste_produit[2].stocks=194;
  list1.p_liste_produit[3].stocks=305;
  list1.p_liste_produit[4].stocks=256;
  list1.p_liste_produit[5].stocks=106;

  //Quand Ouvrir Ce Programme,Il Faut D'abord Charger Les Produits En Stock Dans Un Liste De Produits Avec Un Tableau Produits
  liste_produit listnouveau;
  Charger_Produites_EnStock(&listnouveau);

  int end0 = 0;
  while(!end0)
  {
    switch(Menu_())
    {
      case 1:{
        int end1=0;
              while(!end1)
              {
                  switch(Menu_Caissier())
                {
                  case 1:
                          printf("\n");
                          printf("Vous Avez Choisi De Demarrer Un Nouveau Ticket\n");
                          Menu_Panier(&listnouveau);
                          break;
                  case 2:{
                    printf("\n");
                    printf("Vous Avez Choisi De Sortir De Mode Caissier\n");
                    end1=1;
                    break;
                  }
                          
                }
              }
              break;
      }
      case 2:{
        int end2=0;
              while(!end2)
              {
                  switch(Menu_Gerant())
                  {
                    case 1:
                          Afficher_Produits_EnStock(&listnouveau);
                          break;
                    case 2:
                          Modifier_Produites_EnStock(&listnouveau);
                          break;
                    case 3:
                          Add_Produites_EnStock(&listnouveau);
                          break;
                    case 4:
                          Afficher_Compte();
                          break;
                    case 5:{
                      end2 = 1;
                      printf("\n");
                      printf("Vous Avez Choisi De Sortir De Mode Gerant\n");
                      break;
                    }
                          
                  }
              }
              break;
      }
              

      case 3:
                printf("\n");
                printf("********************************************************************************");
                printf("\n");
                printf("*******************************    AU REVOIR    ********************************");
                printf("\n");
                printf("*****************************    À LA PROCHAIN    ******************************");
                printf("\n");
                printf("********************************************************************************");
                printf("\n");
                end0 = 1;
                break;
    }
  }

  return 0;
}



/*C'est pour afficher la première menu*/
int Menu_(void)
{
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("********************************************************************************");
  printf("\n");
  printf("*******************************    BIENVENUE    ********************************");
  printf("\n");
  printf("******************************   SUPER_MARCHE    *******************************");
  printf("\n");
  printf("********************************************************************************");
  printf("\n");
  printf("-----  Choisissez : (1)Caissier ou (2)Gerant ou (3)Quitter le programme   ------");
  printf("\n");
  char choice[512];
  scanf("%s",choice);
  int get_choice=atoi(choice);
  if (get_choice !=1 && get_choice !=2 && get_choice !=3){
    printf("%d\n",get_choice);
    printf("mal entre\n");
    return 0;
  }
  switch(get_choice)
  {
    case 1:
          printf("Vous Avez Choisi %d , Pour Entrer La Mode Caissier!\n",get_choice);
          break;
    case 2:
          printf("Vous Avez Choisi %d , Pour Entrer La Mode Gerant!\n",get_choice);
          break;
  }
  return get_choice;
}


/*C'est pour afficher la deuxième menu*/
int Menu_Caissier(void)
{
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("--------------------------------------------------------------------------------");
  printf("\n");
  printf("------------------------------    Mode CAISSE   --------------------------------");
  printf("\n");
  printf("*****************************    À  SUPER_MARCHE   *****************************");
  printf("\n");
  printf("--------------------------------------------------------------------------------");
  printf("\n");
  printf("(1) Pour Demarrer Un Nouveau Ticket\n");
  printf("(2) Pour Revenir Au Menu Principal\n");
  char choice[512];
  scanf("%s",choice);
  int get_choice=atoi(choice);
  if (get_choice !=1 && get_choice !=2){
    printf("%d\n",get_choice);
    printf("mal entre\n");
    //fflush(stdin);
    return 0;
  }
  switch(get_choice)
  {
    case 1:
          printf("Vous Avez Choisi %d , Pour Demarrer Un Nouveau Ticket\n",get_choice);
          break;
    case 2:
          printf("Vous Avez Choisi %d , Pour Revenir Au Menu Principal\n",get_choice);
          break;
  }
  return get_choice;
}


/*C'est pour afficher la troisième menu*/
int Menu_Gerant(void)
{
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("--------------------------------------------------------------------------------");
  printf("\n");
  printf("------------------------------    Mode GERANT    -------------------------------");
  printf("\n");
  printf("*****************************   À  SUPER_MARCHE   ******************************");
  printf("\n");
  printf("--------------------------------------------------------------------------------");
  printf("\n");
  printf("(1) Voir la liste des produits en stocks\n");
  printf("(2) Modifier un produit\n");
  printf("(3) Ajouter nouveau produite catalogue\n");
  printf("(4) Afficher la compte\n");
  printf("(5) Quitter le mode Gerant\n");
  char choice[512];
  scanf("%s",choice);
  int get_choice=atoi(choice);
  if (get_choice !=1 && get_choice !=2 && get_choice !=3 && get_choice !=4 && get_choice !=5){
    printf("%d\n",get_choice);
    printf("mal entre\n");
    return 0;
  }
  switch(get_choice)
  {
    case 1:
          printf("Vous Avez Choisi %d , Pour Voir la liste des produits en stocks\n",get_choice);
          break;
    case 2:
          printf("Vous Avez Choisi %d , Pour Modifier un produit\n",get_choice);
          break;
    case 3:
          printf("Vous Avez Choisi %d , Pour Ajouter nouveau produite catalogue\n",get_choice);
          break;
    case 4:
          printf("Vous Avez Choisi %d , Pour Afficher la compte\n",get_choice);
          break;
    case 5:
          printf("Vous Avez Choisi %d , Pour Quitter le mode Gerant\n",get_choice);
          break;
  }
  return get_choice;
}


/*C'est pour entrer dans la mode panier*/
void Menu_Panier(liste_produit *liste_produit1)
{
  printf("\n");
  printf("\n");
  printf("\n");
  printf("\n");
  printf("--------------------------------------------------------------------------------");
  printf("\n");
  printf("-----------------------------   Nouveau Panier   -------------------------------");
  printf("\n");
  printf("*****************************   À  SUPER_MARCHE   ******************************");
  printf("\n");
  printf("--------------------------------------------------------------------------------");
  printf("\n");
  int flag=0;
  /* Quand entrer dans la menu_panier,il faut tout d'abord avoir une liste "panier" */
  panier paniernouveau;
  //panier *panier1=(panier*)malloc(sizeof(panier));
  Panier_Init(&paniernouveau);
  while(!flag)
  {
    switch(Manipuler_Panier())
    {
      case 1:
              printf("Entrer Succed!\n");
              Panier_Print(&paniernouveau);
              break;
      case 2:
              printf("Entrer Succed!\n");
              Add_Panier(&paniernouveau,liste_produit1);
              break;
      case 3:
              printf("Entrer Succed!\n");
              break;
      case 4:
              printf("Entrer Succed!\n");
              Save_Panier_en_Compte(&paniernouveau);
              break;
      case 5:
              printf("Entrer Succed!\n");
              break;
      case 6:{
              flag=1;
              printf("\n");
              printf("Vous Avez Choisi De Revenir Au Menu De Caissier\n");
              break;
      }
    }
  }
  Panier_Free(&paniernouveau);
}


/*Le Menu pour manipuler le Panier*/
int Manipuler_Panier(void)
{
  printf("CHOISIR:------------------------------------------------------------------------\n");
  printf("-----------------------(1) Afficher le panier en cours--------------------------\n");
  printf("------------------(2) Ajouter le produit dans le panier-------------------------\n");
  printf("--------------------(3) Supprimer le produit du panier--------------------------\n");
  printf("----------------------(4) Finir commande ET Réserver----------------------------\n");
  printf("-------------------(5) Finir commande SANS Réserver-----------------------------\n");
  printf("--------------------(6) Revenir Au Menu De Caissier-----------------------------\n");
  printf("--------------------------------------------------------------------------------\n");
  char choice[512];
  scanf("%s",choice);
  int get_choice=atoi(choice);
  if (get_choice !=1 && get_choice !=2 && get_choice !=3 && get_choice !=4 && get_choice !=5 && get_choice !=6){
    printf("%d\n",get_choice);
    printf("mal entre\n");
    return 0;
  }
  switch(get_choice)
  {
    case 1:
          printf("Vous Avez Choisi %d , Pour Afficher le panier en cours\n",get_choice);
          break;
    case 2:
          printf("Vous Avez Choisi %d , Pour Ajouter le produit dans le panier\n",get_choice);
          break;
    case 3:
          printf("Vous Avez Choisi %d , Pour Supprimer le produit du panier\n",get_choice);
          break;
    case 4:
          printf("Vous Avez Choisi %d , Pour Finir commande ET Réserver\n",get_choice);
          break;
    case 5:
          printf("Vous Avez Choisi %d , Pour Finir commande SANS Réserver\n",get_choice);
          break;
    case 6:
          printf("Vous Avez Choisi %d , Pour Revenir Au Menu De Caissier\n",get_choice);
          break;
  }
  return get_choice;
}


/*Quand ouvrir le programme,C'est pour charger le fichier du stock_binaire dans une structure liste_produit avec un tableu des produits*/
void Charger_Produites_EnStock(liste_produit *liste_produit1)
{

  FILE *f=fopen("Stocks_Produit.bin","rb");
  if(f == NULL)
  {
    perror("Open Failed!\n");
    exit(1);
  }
  fseek(f,0,SEEK_END);
  long Lsize=ftell(f);
  printf("the size of whole fichier is %ld\n",Lsize);
  printf("the size of whole fichier is %lu\n",sizeof(produit));
  rewind(f);
  int nombre=Lsize/sizeof(produit);
  printf("the number of whole fichier is %d\n",nombre);
  liste_produit1->n=nombre;
  liste_produit1->p_liste_produit=malloc(sizeof(produit)*nombre);
  if(liste_produit1->p_liste_produit==NULL)
  {
    printf("C'est Erreur");
    exit(1);
  }
  fread(liste_produit1->p_liste_produit,sizeof(produit),nombre,f);
  rewind(f);
  fclose(f);
}


/*Quand fermer le programme,C'est pour save un tableau des produits dans le fichier du stock_binaire */
void Save_Produites_EnStock(const liste_produit *liste_produit1)
{
   FILE *f=fopen("Stocks_Produit.bin","wb");
    if(f == NULL)
    {
      perror("Open Failed!\n");
      exit(1);
    }
    fwrite(liste_produit1->p_liste_produit,sizeof(produit),liste_produit1->n,f);
    rewind(f);
    fclose(f);
}



/*C'est pour afficher la liste de produit en stock*/
void Afficher_Produits_EnStock(const liste_produit *liste_produit1)
{
  printf("--------------------------  %d PRODUITS AU CATALOGUE  ---------------------------",(liste_produit1->n));
  printf("\n");
  for(int i=0;i<liste_produit1->n;i++)
  {
    printf("id%5d%25s  Prix Unit :%20f  Stocks :%5d",i,liste_produit1->p_liste_produit[i].nom,liste_produit1->p_liste_produit[i].prix_unit,liste_produit1->p_liste_produit[i].stocks);
    printf("\n");
  }
}



/*C'est pour modifier la liste de produit en stock*/
void Modifier_Produites_EnStock(liste_produit *liste_produit1)
{
    printf("\n");
    printf("Saisissez l'id du produit :\n");
    int get_choice;
    scanf("%d",&get_choice);
    if( get_choice<0 || get_choice>(liste_produit1->n-1))
    {
      printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!    ERREUR SAISIE    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
      printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!    ERREUR SAISIE    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
      printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!    ERREUR SAISIE    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
      printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!    ERREUR SAISIE    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    }
    else
    {
      printf("\n");
      printf("Vous Avez Choisi De Modifier Produit:\n");
      printf("\n");
      printf("id%5d%25s  Prix Unit :%20f  Stocks :%5d",get_choice,liste_produit1->p_liste_produit[get_choice].nom,liste_produit1->p_liste_produit[get_choice].prix_unit,liste_produit1->p_liste_produit[get_choice].stocks);
      printf("\n");
      printf("Renommez le produit :");
      char new_name[64];
      scanf("%s",new_name);
      strcpy(liste_produit1->p_liste_produit[get_choice].nom,new_name);
      printf("Donner Le Nouveau Prix De Produit: ");
      double new_prix;
      scanf("%lf",&new_prix);
      liste_produit1->p_liste_produit[get_choice].prix_unit=new_prix;
      printf("Donner Le Nouveau Stocks :");
      int new_stocks;
      scanf("%d",&new_stocks);
      liste_produit1->p_liste_produit[get_choice].stocks=new_stocks;
      printf("\n");
      printf("SUCCED-----------------------------------------!\n");
    }
}


/*C'est pour ajouter la nouvelle produit dans la liste de produit en stock*/
void Add_Produites_EnStock(liste_produit *liste_produit1)
{
    (liste_produit1->n)=(liste_produit1->n)+1;
    produit *temp=(produit *)realloc(liste_produit1->p_liste_produit,sizeof(produit)*((liste_produit1->n)));
    if(temp==NULL)
    {
      printf("%s\n",strerror(errno));
    }
    liste_produit1->p_liste_produit=temp;
    char new_name[64];
    double new_prix=0;
    int new_stocks;
    printf("\n");
    printf("Maintenant Vous Modifier Le %d(id):-------------\n",liste_produit1->n);
    printf("Nommez Le Produit SVP:\n");
    scanf("%s",new_name);
    strcpy(liste_produit1->p_liste_produit[(liste_produit1->n)-1].nom,new_name);
    printf("Donner Le Nouveau Prix De Produit: ");
    scanf("%lf",&new_prix);
    liste_produit1->p_liste_produit[(liste_produit1->n)-1].prix_unit=new_prix;
    printf("Donner Le Nouveau Stocks :");
    scanf("%d",&new_stocks);
    printf("%d\n",new_stocks);
    liste_produit1->p_liste_produit[(liste_produit1->n)-1].stocks=new_stocks;
    printf("%d\n",liste_produit1->p_liste_produit[(liste_produit1->n)-1].stocks);
}


/*C'est pour save un nouveau panier dans le fichier compte*/
void Save_Panier_en_Compte(const panier *p_panier)
{
      //On Utilise 'a' Pour Rajouter Nouveau Ticket Dans Le Fichier Compte_Ticket.csv
      FILE *compte=fopen("Compte_Ticket.csv","a");
      if(compte==NULL)
      {
        fprintf(stderr,"fopen()failed.\n");
        exit(EXIT_FAILURE);
      }
      int length;
      fseek(compte,0,SEEK_END);
      length=ftell(compte);
      if(length<5)
      {
        fprintf(compte,"DATE,TICKET_ID,CLIENT_ID,TOTAL\n");
        fprintf(compte,"%d/%d/%d,%d,%d,%f\n",p_panier->date_ticket->tm_year+1900,p_panier->date_ticket->tm_mon+1,p_panier->date_ticket->tm_mday,p_panier->ticketid,p_panier->clientid,p_panier->total);
      }
      else
      {
        fprintf(compte,"%d/%d/%d,%d,%d,%f\n",p_panier->date_ticket->tm_year+1900,p_panier->date_ticket->tm_mon+1,p_panier->date_ticket->tm_mday,p_panier->ticketid,p_panier->clientid,p_panier->total);
      }
      fclose(compte);
}


/*C'est pour initisliser un nouveau panier au début*/
void Panier_Init(panier *p_panier)
{
  int clientid_now=DemanderId_client();
  printf("On va Commencer SHOPPING pour (VIP)ID:%d\n",clientid_now);
  p_panier->head=NULL;
  Get_Time(&(p_panier->date_ticket));
  p_panier->total=0.0;
  p_panier->ticketid=Get_Ticketid(p_panier);
  p_panier->clientid=clientid_now;
}



/*C'est pour demander l'id de client*/
int DemanderId_client(void)
{
  printf("\n");
  printf("Si C'est Un VIP_ClIENT? Si il(elle) est VIP, Taper L'Id de ce client!\n");
  printf("Si Non, Taper -1\n");
  int id_client;
  scanf("%d",&id_client);
  // C'est pour manger le signe \n après entrer le numéro de client.
  getchar();
  return id_client;
}



/*Quand sorter la manipulation du panier,il fuat Free la liste de panier*/
void Panier_Free(panier *p_panier)
{
      item_panier *node;
      while(p_panier->head!=NULL)
      {
          node=p_panier->head;
          p_panier->head=node->suivant;
          free(node);
      }
}


/*C'est pour savoir que les nombres de item_panier dans le panier*/
int Panier_Length(const panier *p_panier)
{
  item_panier *node;
  int nombre=0;
  for(node=p_panier->head;node!=NULL;node=node->suivant)
  {
      nombre++;
  }
  return nombre;
}



void Panier_Print(const panier *p_panier)
{

  item_panier *node;
  int length=Panier_Length(p_panier);
  printf("----------------------------        %d/%d/%d         ----------------------------\n",p_panier->date_ticket->tm_year+1900,p_panier->date_ticket->tm_mon+1,p_panier->date_ticket->tm_mday);
  printf("----------------------------  %d PRODUITS AU PANIER  ----------------------------\n",length);
  for(node=p_panier->head;node!=NULL;node=node->suivant)
  {
    printf("Id:%8d       Quantité:%8f",node->idProd,node->quantite);
    printf("\n");
  }
}



void Get_Time(date **pDateticket)
{
  time_t nowtime;
  nowtime =time(NULL);
  *pDateticket=localtime(&nowtime);
}

void Add_Panier(panier *p_panier,liste_produit*liste_produit1)
{
  int id_Item;
  double quantite1;
  printf("\n");
  printf("********************************************************************************");
  printf("\n");
  printf("ENTRER L'ID DE PRODUIT: ");
  scanf("%d",&id_Item);
  printf("\n%d\n",id_Item);
  //C'est aussi pour manger le '\n' dans stdin
  getchar();
  printf("\n");
  printf("ENTRER LA QUANTITÉ DE CE PRODUIT: ");
  scanf("%lf",&quantite1);
  printf("\n%lf\n",quantite1);
  //c'est aussi pour manger le '\n' dans stdin
  getchar();
  int flag=Trouver_Item_Dans_Panier(p_panier,id_Item);
  printf("%d\n",flag);
  if(flag==0)
  {
    Add_Front_Panier(liste_produit1,p_panier,id_Item,quantite1);
  }


}



void Add_Front_Panier(liste_produit*liste_produit1,panier *p_panier,int id_Item2,double quantite2)
{
  item_panier *node=(item_panier *)malloc(sizeof(item_panier));
  node->idProd=id_Item2;
  node->quantite=quantite2;
  node->suivant=p_panier->head;
  p_panier->head=node;
  double prix=Trouver_Prix_Produit(liste_produit1,id_Item2);
  p_panier->total=p_panier->total+(prix*quantite2);
}



/*void Add_Millieu_Panier(panier *p_panier,int id_Item,double quantites)
{

}*/



int Trouver_Item_Dans_Panier(const panier *p_panier,int id_Item)
{
    item_panier *node=NULL;
    for(node=p_panier->head;(node) != NULL;node=node->suivant)
    {
      if(node->idProd == id_Item)
      {
        return 1;
      }
    }
    return 0;
}




/*Dans le mode Gérant,il y a une fonction pour afficher tous les comptes */
void Afficher_Compte(void)
{
      FILE *compte=fopen("Compte_Ticket.csv","r");
      if(compte==NULL)
      {
        fprintf(stderr,"fopen()failed.\n");
        exit(EXIT_FAILURE);
      }
      char row[256];
      char *token;
      printf("***********************************************************************************\n");
      printf("*******************************       COMPTE      *********************************\n");
      printf("*****************************    AU SUPER_MARCHE    *******************************\n");
      printf("***********************************************************************************\n");
      while(fgets(row,256,compte) != NULL)
      {
        token=strtok(row,",");
        while(token != NULL)
        {
          printf("%10s        ",token);
          token=strtok(NULL,",");
        }
        printf("\n");
      }
      fclose(compte);
}



/*C'est pour changer le ticketid chaque nouveau jour*/
int Get_Ticketid(const panier*p_panier2)
{
    int ticketid=0;
    FILE *compte=fopen("Compte_Ticket.csv","r");
    if(compte==NULL)
    {
      fprintf(stderr,"fopen()failed.\n");
      exit(EXIT_FAILURE);
    }
    char row[256];
    char *token;
    while(fgets(row,256,compte) != NULL)
    {
      ;
    }
    token=strtok(row,",");
    char *Date=token;
    token=strtok(NULL,",");
    char *ticketID=token;

    token=strtok(Date,"/");
    char *year=token;
    //printf("%10s        \n",year);
    token=strtok(NULL,"/");
    char *month=token;
    //printf("%10s        \n",month);
    token=strtok(NULL,"/");
    char *date=token;
    //printf("%10s        \n",date);
    //printf("%d\n",p_panier2->date_ticket->tm_year);

    if(p_panier2->date_ticket->tm_year == (atoi(year)-1900))
    {
      //printf("entree\n");
      if(p_panier2->date_ticket->tm_mon == (atoi(month)-1))
      {
        if(p_panier2->date_ticket->tm_mday == atoi(date))
                ticketid=atoi(ticketID)+1;
      }
    }
    fclose(compte);
    return ticketid;
}



double Trouver_Prix_Produit(const liste_produit *liste_produit1,int idprod)
{
    return liste_produit1->p_liste_produit[idprod].prix_unit;
}