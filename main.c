#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <setjmp.h>
#include <windows.h>
#include <ctype.h>
#include <dos.h>
#include <time.h>

void gotoxy(int x, int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);

}

struct cars
{	int n_car;
	char marque[30];
	char modele[30];
	int anne;
}t[25];

struct client
{
    int n_client;
    char nom[30];
    char prenom[30];
    char gin[10];
    char addresse[100];
    char tele[50];

}a[100];

struct donnes{
    char date[50];
    float price;
    int dure;

}b[100];

FILE*fcars;
FILE*fclients;
FILE*ffacture;
int i=0;

/*-------------------------------------------------  remplissage ----------------------------------------------------------------------*/
void remplissageCars()
{

if((	fcars=fopen("cars.txt","a"))==NULL)

fcars=fopen("cars.txt","w");

	system("cls");
	//ouverture du fichier 'ftest'(nom iterne) qui a une liaison avec le fichier 'C:\mac.txt'(nom externe)//

	//en mode 'w'(write:ecriture)

        gotoxy(16,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 LOCATION HOMIES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

	printf("\n\n\t\t\xDB\xDB\xDB\xDB\xB2 Nombre de voiture : ");scanf("%d",&t[i].n_car);
	while(t[i].n_car!=0)
	{
		printf("\n\t\t\xDB\xDB\xDB\xDB\xB2 Marque : ");scanf("%s",t[i].marque);
		printf("\n\t\t\xDB\xDB\xDB\xDB\xB2 Modele : ");scanf("%s",t[i].modele);
		printf("\n\t\t\xDB\xDB\xDB\xDB\xB2 L Anne : ");scanf("%d",&t[i].anne);

		SEEK_END;
		fwrite(&t[i],sizeof(t[i]),1,fcars);	i++;
		//instruction d'ecriture sur le fichier'ftest'
		printf("\n\t\t\xDB\xDB\xDB\xDB\xB2 Nombre de voiture : ");scanf("%d",&t[i].n_car);
	}
	//fermeture du fichier'ftest'
	fclose(fcars);
}

void remplissageClient()
{

if((	fclients=fopen("fclients.txt","a"))==NULL)

fclients=fopen("fclients.txt","w");

	system("cls");
	//ouverture du fichier 'ftest'(nom iterne) qui a une liaison avec le fichier 'C:\mac.txt'(nom externe)//

	//en mode 'w'(write:ecriture)

        gotoxy(16,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 LOCATION HOMIES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

	printf("\n\n\t\t\xDB\xDB\xDB\xDB\xB2 Nombre de client : ");scanf("%d",&a[i].n_client);
	while(a[i].n_client!=0)
	{
		printf("\n\t\t\xDB\xDB\xDB\xDB\xB2 Enter Nom : ");scanf("%s",a[i].nom);
		printf("\n\t\t\xDB\xDB\xDB\xDB\xB2 Enter Prenom : ");scanf("%s",a[i].prenom);
		printf("\n\t\t\xDB\xDB\xDB\xDB\xB2 Enter GIN : ");scanf("%s",a[i].gin);
		printf("\n\t\t\xDB\xDB\xDB\xDB\xB2 Enter Addresse : ");scanf("%s",a[i].addresse);
		printf("\n\t\t\xDB\xDB\xDB\xDB\xB2 Enter Telephone : ");scanf("%d",&a[i].tele);

		SEEK_END;
		fwrite(&a[i],sizeof(a[i]),1,fclients);	i++;
		//instruction d'ecriture sur le fichier'ftest'
		printf("\n\t\t\xDB\xDB\xDB\xDB\xB2 Nombre de client : ");scanf("%d",&a[i].n_client);
	}
	//fermeture du fichier'ftest'
	fclose(fclients);
}

/*-------------------------------------------------  affichage  ----------------------------------------------------------------------*/
void affichageCars()
{	int i=0;int j;
	//ouverture du fichier 'ftest' en mode 'r'(read:lecture)
	fcars=fopen("cars.txt","r");system("cls");
	while(!feof(fcars))
	{
		fread(&t[i],sizeof(t[i]),1,fcars);i++;
	}
	fclose(fcars);
		for(j=0;j<i-1;j++)
	{
        printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 LOCATION HOMIES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		printf("\n\n\t\t\xDB\xDB\xDB\xDB\xB2 Nombre de voiture : %d\n",t[j].n_car);
		printf("\n\t\t\xDB\xDB\xDB\xDB\xB2 Marque : %s\n",t[j].marque);
		printf("\n\t\t\xDB\xDB\xDB\xDB\xB2 Modele : %s\n",t[j].modele);
		printf("\n\t\t\xDB\xDB\xDB\xDB\xB2 L Anne : %d\n",t[j].anne);
	}
	system("pause");
}

void affichageClient()
{	int i=0;int j;
	//ouverture du fichier 'ftest' en mode 'r'(read:lecture)
	fclients=fopen("fclients.txt","r");system("cls");
	while(!feof(fclients))
	{
		fread(&a[i],sizeof(a[i]),1,fclients);i++;
	}
	fclose(fclients);
		for(j=0;j<i-1;j++)
	{
        printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 LOCATION HOMIES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		printf("\n\n\t\t\xDB\xDB\xDB\xDB\xB2 Nombre de Client : %d\n",a[j].n_client);
		printf("\n\t\t\xDB\xDB\xDB\xDB\xB2 Nom : %s\n",a[j].nom);
		printf("\n\t\t\xDB\xDB\xDB\xDB\xB2 Prenom : %s\n",a[j].prenom);
        printf("\n\t\t\xDB\xDB\xDB\xDB\xB2 GIN : %s\n",a[j].gin);
		printf("\n\t\t\xDB\xDB\xDB\xDB\xB2 Addresse : %s\n",a[j].addresse);
		printf("\n\t\t\xDB\xDB\xDB\xDB\xB2 Telephone : %d\n",&a[j].tele);


	}
	system("pause");
}

/*-------------------------------------------------  supprimer ----------------------------------------------------------------------*/
void supprimerCars()
{	int i=0;int j,num,v=0,l;
	//ouverture du fichier 'ftest' en mode 'r'(read:lecture)
	fcars=fopen("cars.txt","r");system("cls");
	while(!feof(fcars))
	{
		fread(&t[i],sizeof(t[i]),1,fcars);i++;
	}
	fclose(fcars);
	        gotoxy(16,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 LOCATION HOMIES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	printf("\n\t\t\xDB\xDB\xDB\xDB\xB2 Nombre de voiture :");scanf("%d",&num);
		for(j=0;j<i-1;j++)
	{
		if(num==t[j].n_car)
		{
		v=1;l=j;
		}


	}
	if(v==1) {
		for(j=l;j<i-2;j++)
	{


		t[j]=t[j+1];


	}

		fcars=fopen("cars.txt","w");
		for(j=0;j<i-2;j++)
	{
		fwrite(&t[j],sizeof(t[j]),1,fcars);

	}
	   fclose(fcars);
}
else {
	printf("\n\t\t\xDB\xDB\xDB\xDB\xB2 n'existe pas !!!!!!");
}
system("pause");
}

void supprimerClient()
{	int i=0;int j,num,v=0,l;
	//ouverture du fichier 'ftest' en mode 'r'(read:lecture)
	fclients=fopen("fclients.txt","r");system("cls");
	while(!feof(fclients))
	{
		fread(&a[i],sizeof(a[i]),1,fclients);i++;
	}
	fclose(fclients);
	        gotoxy(16,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 LOCATION HOMIES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	printf("\n\n\t\t\xDB\xDB\xDB\xDB\xB2 Nombre de client : ");scanf("%d",&num);
		for(j=0;j<i-1;j++)
	{
		if(num==a[j].n_client)
		{
		v=1;l=j;
		}


	}
	if(v==1) {
		for(j=l;j<i-2;j++)
	{


		a[j]=a[j+1];


	}

		fclients=fopen("fclients.txt","w");
		for(j=0;j<i-2;j++)
	{
		fwrite(&a[j],sizeof(a[j]),1,fclients);

	}
	   fclose(fclients);
}
else {
	printf("\n\t\t\xDB\xDB\xDB\xDB\xB2 n'existe pas !!!!!!");
}
system("pause");
}

/*-------------------------------------------------  rechercher ----------------------------------------------------------------------*/
void rechercherCars()
{	int i=0;int j,num,v=0;
	//ouverture du fichier 'ftest' en mode 'r'(read:lecture)
	fcars=fopen("cars.txt","r");system("cls");
	while(!feof(fcars))
	{
		fread(&t[i],sizeof(t[i]),1,fcars);i++;
	}
	fclose(fcars);
	        gotoxy(16,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 LOCATION HOMIES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	printf("\n\n\t\t\xDB\xDB\xDB\xDB\xB2 Nombre de voiture : ");scanf("%d",&num);
		for(j=0;j<i-1;j++)
	{
		if(num==t[j].n_car)
		{
			v=1;
		printf("\n\t\t\xDB\xDB\xDB\xDB\xB2 Marque : %s %s",t[j].marque,t[j].modele);
		}
		for(i=0;i<=2;i++)
                 {
                   printf("\n");
                      }

	}


	if(v==0) {printf("\n\t\t\xDB\xDB\xDB\xDB\xB2 n'existe pas !!!!!!");}
	system("pause");

}

void rechercherClient()
{	int i=0;int j,num,v=0;
	//ouverture du fichier 'ftest' en mode 'r'(read:lecture)
	fclients=fopen("fclients.txt","r");system("cls");
	while(!feof(fclients))
	{
		fread(&a[i],sizeof(a[i]),1,fclients);i++;
	}
	fclose(fclients);
	        gotoxy(16,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 LOCATION HOMIES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	printf("\n\n\t\t\xDB\xDB\xDB\xDB\xB2 Nombre de Client : ");scanf("%d",&num);
		for(j=0;j<i-1;j++)
	{
		if(num==a[j].n_client)
		{
			v=1;
		printf("\n\t\t\xDB\xDB\xDB\xDB\xB2 Full Name : %s %s",a[j].nom,a[j].prenom);
		}
		for(i=0;i<=2;i++)
                 {
                   printf("\n");
                      }

	}


	if(v==0) {printf("\n\t\t\xDB\xDB\xDB\xDB\xB2 n'existe pas !!!!!!");}
	system("pause");

}

void modifierCars()
{	int i=0;int j,num,v=0;
	//ouverture du fichier 'ftest' en mode 'r'(read:lecture)
	fcars=fopen("cars.txt","r");system("cls");
	while(!feof(fcars))
	{
		fread(&t[i],sizeof(t[i]),1,fcars);i++;
	}
	fclose(fcars);
	printf("Nombre de Voiture : ");scanf("%d",&num);
		for(j=0;j<i-1;j++)
	{
		if(num==t[j].n_car)
		{
		//printf("N_machine : %d\n",t[j].n_machine);
		printf("novelle marque : ");scanf("%s",t[j].marque);v=1;}


	}
	if(v==1) {

		fcars=fopen("cars.txt","w");
		for(j=0;j<i-1;j++)
	{
		fwrite(&t[j],sizeof(t[j]),1,fcars);

	}
	   fclose(fcars);
}
}


/*-------------------------------------------------  main  ----------------------------------------------------------------------*/
void billheader(){
    int i;
        printf("\n\n");
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Bill \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            printf("\n------------------------------------------");
            printf("\n Date: %s",b[i].date);
            printf("\n Invoice To: %s", a[i].nom);
            printf("\n");
            printf("------------------------------------------\n");
            printf(" Car Marque\t");
            printf("Dure/j\t\t");
            printf(" Total\t");
            printf("\n------------------------------------------");
            printf("\n\n");
}

void Billbody(){

              int i;

        printf(" %s %s\t", t[i].marque,t[i].modele);
            printf(" %d\t\t", b[i].dure);
            printf("%.2f DH\t", b[i].dure * b[i].price);
            printf("\n");


}

void billfooter(float total){

        printf("\n");

            float dis = 0.1 * total;
            float netTotal = total-dis;
            float tva = 0.09*netTotal;
            float dva = 2*tva;
            printf("-------------------------------------------\n");
            printf(" Sub total\t\t\t%.2f DH", total);
            printf("\n Discount -10%s\t\t\t%.2f DH","%",dis);
            printf("\n ------\t\t\t\t------");
            printf("\n Net Total\t\t\t%.2f DH", netTotal);
            printf("\n TVA +9%s\t\t\t%.2f DH","%",tva);
            printf("\n DVA +9%s\t\t\t%.2f DH","%",dva);
            printf("\n------------------------------------------");
            printf("\n Grand Total\t\t\t%.2f DH", netTotal+tva+dva);
            printf("\n------------------------------------------");
      //      printf("\n La date de reture : %s%d", ,);
       //     printf("\n------------------------------------------");



}

int main(int argc, char *argv[]) {
	//ftest=fopen("C:gggg.txt","w");
	int a;
	int i;
	float total;
    char save = 'y' ,contFlage ='y';
    time_t now = time(0);

    struct cars ca;
    struct client cl;
    struct donnes dn;

while(contFlage == 'y')
	{
		system("cls");
        gotoxy(20,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 LOCATION HOMIES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        gotoxy(20,5);
    printf("\xDB\xDB\xDB\xDB\xB2 1. Add Cars   ");
        gotoxy(20,7);
    printf("\xDB\xDB\xDB\xDB\xB2 2. Delete Cars");
        gotoxy(20,9);
    printf("\xDB\xDB\xDB\xDB\xB2 3. Search For Cars");
        gotoxy(20,11);
    printf("\xDB\xDB\xDB\xDB\xB2 4. View car list");
        gotoxy(20,13);
    printf("\xDB\xDB\xDB\xDB\xB2 5. Edit car list");
        gotoxy(20,15);
    printf("\xDB\xDB\xDB\xDB\xB2 6. Add Client");
        gotoxy(20,17);
    printf("\xDB\xDB\xDB\xDB\xB2 7. Delete Client");
        gotoxy(20,19);
    printf("\xDB\xDB\xDB\xDB\xB2 8. View clients list");
        gotoxy(20,21);
    printf("\xDB\xDB\xDB\xDB\xB2 9. Generate the bill");
        gotoxy(20,23);
    printf("\xDB\xDB\xDB\xDB\xB2 10. Show all the bills");
        gotoxy(20,25);
    printf("\xDB\xDB\xDB\xDB\xB2 11. Close Application");
        gotoxy(20,27);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        gotoxy(20,29);
    printf("Enter your choice: ");
    scanf("%d",&a);

        fgetc(stdin);
		switch(a)

		{
			case 1 : remplissageCars();break;
			case 2 : supprimerCars();break;
			case 3 : rechercherCars();break;
			case 4 : affichageCars();break;
			case 5 : modifierCars();break;
			case 6 : remplissageClient();break;
            case 7 : supprimerClient();break;
            case 8 : affichageClient();break;
            case 9 :
    system("cls");
    gotoxy(20,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 LOCATION HOMIES \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    rechercherClient();
    strcpy(b[i].date,ctime(&now));
    rechercherCars();
    gotoxy(16,9);
    printf("\xDB\xDB\xDB\xDB\xB2 Please enter how many day the car will be out: ");
    scanf("%d", &b[i].dure);
    gotoxy(16,11);
    printf("\xDB\xDB\xDB\xDB\xB2 Please enter the unit price : ");
    scanf("%f", &b[i].price);

    billheader();

    Billbody();

    total = b[i].dure * b[i].price;

    billfooter(total);

    printf("\n Do you want to save the bill [y/n]:");
    scanf("%s",&save);

    if(save == 'y'){
        ffacture = fopen("ffacture.txt","a+");
		fwrite(&ca,sizeof(struct cars),1,ffacture);
		fwrite(&cl,sizeof(struct client),1,ffacture);
		fwrite(&dn,sizeof(struct donnes),1,ffacture);
        if(fwrite != 0)
            printf("\nSuccessfully saved");
        else printf("\n Error saving");
        fclose(ffacture);

                        }
                        break;
            case 10:
                system("cls");
                ffacture = fopen("ffacture.txt","r");
                printf("\n your bills list");
                while
                    (fread(&ca,sizeof(struct cars),1,ffacture) && fread(&cl,sizeof(struct client),1,ffacture) && fread(&dn,sizeof(struct donnes),1,ffacture))
                     billheader();

                     Billbody();

                     total = b[i].dure * b[i].price;

                     billfooter(total);
                     fclose(ffacture);
                break;

         case 11:
     gotoxy(20,29);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Bye Bye! \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    exit(0);
         break;

         default:
     gotoxy(20,29);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Sorry Invalid Option \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

         break;
             }

    printf("\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t\ Do you want to get back to the menu [y/n]? :");
    printf("\n\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    scanf("\n\n\t\t\%s", &contFlage);
    }


	while(a!=a);



	return 0;
}
