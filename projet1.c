#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<errno.h>


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
  //tm *date_ticket;  //la date de passage du panier
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
int Menu_Gerant(void);
int Menu_Caissier(void);
void Charger_Produites_EnStock(liste_produit *liste_produit1);
void Save_Produites_EnStock(const liste_produit *liste_produit1);
void Add_Produites_EnStock(liste_produit *liste_produit1);
void Modifier_Produites_EnStock(liste_produit *liste_produit1);
void Afficher_Produits_EnStock(const liste_produit *liste_produit1);
void Panier_Init(panier *liste_panier1);
void Add_Panier(panier *lite_panier1);
void Delet_Panier(panier *liste_panier1);


/*void Panier_Init(panier *liste_panier1)
{
  liste_panier
}*/
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
  list1.p_liste_produit[1].stocks=11;
  list1.p_liste_produit[2].stocks=104;
  list1.p_liste_produit[3].stocks=52;
  list1.p_liste_produit[4].stocks=33;
  list1.p_liste_produit[5].stocks=600;

  //Afficher_Produits_EnStock(&list1);
  liste_produit list2;
  Charger_Produites_EnStock(&list2);
  Afficher_Produits_EnStock(&list2);








  int end0 = 0;
  while(!end0)
  {
    switch(Menu_())
    {
      case 1:
              int end1=0;
              while(!end1)
              {
                 switch(Menu_Caissier())
                 {
                   case 1:
                          break;
                   case 2:
                          printf("\n");
                          printf("you choose exit the mode_caissier\n");
                          end1=1;
                          break;
                 }
              }

              break;
      case 2:
              int end2=0;
              while(!end2)
              {
                  switch(Menu_Gerant())
                  {
                   case 1:
                          Afficher_Produits_EnStock(&list2);
                          break;
                   case 2:
                          Modifier_Produites_EnStock(&list2);
                          break;
                   case 3:
                          Add_Produites_EnStock(&list2);
                          break;
                   case 4:
                          break;
                   case 5:
                          end2 = 1;
                          printf("\n");
                          printf("you choose exit the mode_gerant\n");
                          break;
                  }
              }
              break;
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
  Save_Produites_EnStock(&list2);
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
  char choice[50];
  int get_choice;
  fgets(choice,50,stdin);
  get_choice=atoi(choice);
  switch(get_choice)
  {
    case 1:
          printf("Vous Avez Choisi %d , Pour Entrer La Mode Caissier!\n");
          break;
    case 2:
          printf("Vous Avez Choisi %d , Pour Entrer La Mode Gerant!\n");
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
  char choice[50];
  int get_choice;
  fgets(choice,50,stdin);
  get_choice=atoi(choice);
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
  printf("*****************************    À  SUPER_MARCHE   *****************************");
  printf("\n");
  printf("--------------------------------------------------------------------------------");
  printf("\n");
  printf("(1) Voir la liste des produits en stocks\n");
  printf("(2) Modifier un produit\n");
  printf("(3) Ajouter nouveau produite catalogue\n");
  printf("(4) Afficher la compte\n");
  printf("(5) Quitter le mode Gerant\n");
  char choice[50];
  int get_choice;
  fgets(choice,50,stdin);
  get_choice=atoi(choice);
  return get_choice;
}



/*Quand ouvrir le programme,C'est pour charger le fichier du stock_binaire dans une structure liste_produit avec un tableu des produits*/
void Charger_Produites_EnStock(liste_produit *liste_produit1)
{

  FILE *f=fopen("stocks.bin","rb");
  if(f == NULL)
  {
    perror("Open Failed!\n");
    exit(1);
  }
  fseek(f,0,SEEK_END);
  long Lsize=ftell(f);
  printf("the size of whole fichier is %ld\n",Lsize);
  printf("the size of whole fichier is %d\n",sizeof(produit));
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



void Save_Produites_EnStock(const liste_produit *liste_produit1)
{
   FILE *f=fopen("stocks.bin","wb");
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
      gets(new_name);
      //scanf("%s",new_name);
      strcpy(liste_produit1->p_liste_produit[get_choice].nom,new_name);
      printf("Donner Le Nouveau Prix De Produit: ");
      double new_prix;
      scanf(" %f",&new_prix);
      liste_produit1->p_liste_produit[get_choice].prix_unit=new_prix;
      printf("Donner Le Nouveau Stocks :");
      int new_stocks;
      scanf("%d",&new_stocks);
      liste_produit1->p_liste_produit[get_choice].stocks=new_stocks;
      printf("\n");
      printf("SUCCED-----------------------------------------!\n");
    }
}




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
   scanf("%f",&new_prix);
   liste_produit1->p_liste_produit[(liste_produit1->n)-1].prix_unit=new_prix;
   printf("Donner Le Nouveau Stocks :");
   scanf("%d",&new_stocks);
   printf("%d\n",new_stocks);
   liste_produit1->p_liste_produit[(liste_produit1->n)-1].stocks=new_stocks;
   printf("%d\n",liste_produit1->p_liste_produit[(liste_produit1->n)-1].stocks);
}
