/*
				HANGMAN 
HINT:VECTOR DE FRECVENTA NEXT TIME 
*/

#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <time.h>

#define DEX 5
#define NUMARCARAC 20


void generareIndicii(char* cuvant,int frec[]){

	int pozitii[NUMARCARAC];
	int contor=0;

	srand((unsigned int)time(0));
	int nrIndicii = rand() % (strlen(cuvant) / 2); //numar de hinturi


	//Pentru fiecare hint trebuie sa generam o pozitie random in cuvant
	for (int i = 0; i < nrIndicii; i++)
		pozitii[contor++] = rand() % ((strlen(cuvant) - 1));

	for (int j = 0; j < contor; j++)
		frec[pozitii[j]] = 0;
	
	
}


void desenare_sperietoare(int* flag){	
	
	
	switch (*flag)
	{
	case 0:{
			   system("cls");
			   printf(
				   "\t\t -----\n"
				   "\t\t |   |\n"
				   "\t\t | \n"
				   "\t\t | \n"
				   "\t\t | \n"
				   "\t\t | \n"
				   "\t\t | \n"
				   "\t\t | \n"
				   "\t\t _ \n");
			   printf("\n\n\n"); 
			   break; }
	case 1:{
			   system("cls");
			   printf(
				   "\t\t -----\n"
				   "\t\t |   |\n"
				   "\t\t |  ooo\n"
				   "\t\t |  ooo\n"
				   "\t\t | \n"
				   "\t\t | \n"
				   "\t\t | \n"
				   "\t\t | \n"
				   "\t\t _ \n");
			   printf("\n\n\n"); 
			   break; }
	case 2:{
			   system("cls");
			   printf(
				   "\t\t -----\n"
				   "\t\t |   |\n"
				   "\t\t |  ooo\n"
				   "\t\t |  ooo\n"
				   "\t\t |   |\n"
				   "\t\t |-------\n"
				   "\t\t | \n"
				   "\t\t | \n"
				   "\t\t _ \n");
			   printf("\n\n\n");
			   break; }
	case 3:{
			   system("cls");
			   printf(
				   "\t\t -----\n"
				   "\t\t |   |\n"
				   "\t\t |  ooo\n"
				   "\t\t |  ooo\n"
				   "\t\t |   |\n"
				   "\t\t |-------\n"
				   "\t\t |   |\n"
				   "\t\t |-------\n"
				   "\t\t _ \n");
			   printf("\n\n\n");
			   break; }
	default: 
		break;
	}

}



int main(){
	int noLives = 0;
	char litera;
	char* p;
	int posCuv = 0;
	char tempChar = '*';
	//UN DICTIONAR STATIC

	//cuvinte
	char words[DEX][20] = {
		"berbec",
		"dart",
		"abecedar",
		"suc",  
		"cantec"};


						
	srand((unsigned int)time(0));
	posCuv = rand() % DEX;     /*   GENERAM UN CUVANT ALEATOR DIN DICTIONAR */
		
	char* vect = (char*)malloc((strlen(words[posCuv]) + 1)*sizeof(char));
	strcpy(vect, words[posCuv]);
	
	int* frec = (int*)malloc(sizeof(int)*strlen(words[posCuv]));
	for (int j = 0; j < strlen(words[posCuv]); j++)
		*(frec + j) = 1;


	//functie care genereaza indicii
	//generareIndicii(vect, frec);  -> nu merge pentru ca trebuie sa scot din vectorul de frecventa
	
	while (noLives < 4){

		/* AICI TREBUIE PUSE 3 FLAGURI  0 pentru inceput 1 pentru gresit */
		int i;
		int m;


		desenare_sperietoare(&noLives);
		/* CONDITION STOP*/
		if (noLives == 3){
			printf("\n ATI PIERDUT \n");
			_sleep(2000);
			exit(EXIT_SUCCESS);
		}
		
		for (m = 0; m < strlen(vect); m++)
		if (tempChar == vect[m] && frec[m] == 1){
			frec[m] = 0;
			break;
		}

		

		//functie de afisare
		for (m = 0; m < strlen(vect) ;m++)
		if (frec[m] == 1)
			printf(" _ ");
		else
			printf(" %c ", vect[m]);


		if ((strlen(words[posCuv])) == 0){
			printf("\nAti ghicit!!!");
			break;
		}

		else{
			
			printf("\nIntroduceti o litera ");
			scanf(" %c", &litera);

			//cautare litera in cuvant
			for (i = 0; i < strlen(words[posCuv]); i++)
			if (words[posCuv][i] == litera){
				tempChar = words[posCuv][i];
				break;
			}

			//daca i atinge lungime sir inseamna ca nu e in sir
			if (i == strlen(words[posCuv])){
				++noLives;  //crestem 
				printf("\nGresit\n");
				_sleep(1000);
			}

			else{
					//cred ca cu vector de frecventa ar fii fost mai oke si nu ar fii trebuit sa stergem nimic :(( 
				for (int j = i; j < strlen(words[posCuv]) - 1; j++){
					words[posCuv][j] = words[posCuv][j + 1];
				}

				words[posCuv][strlen(words[posCuv]) - 1] = '\0';  //terminare sir


			}
		}
	}


}