#include "BST.h"
#include "funny.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10

void keyMIN( node *root)
{if(root==NULL)
	{printf("\nBrak wezlow");
	return;	
	}
node *search;
search=root;
while(search->left!=NULL)
	search=search->left;
printf("%s ",search->person.surname);
return;
	

}

void keyMAX( node * root)
{if(root==NULL)	
	{printf("\nBrak wezlow");
	return;	
	}
node *search=root;
while(search->right!=NULL)
	search=search->right;

printf("%s ",search->person.surname);
return;

}


void inOrder(node * root)
{
if(root!=NULL)
	{
	inOrder(root->left);
	wypisz(root);
	inOrder(root->right);
	}
}


int countNode(node * root, int *sum)
{
if(root!=NULL)
	{
	countNode(root->left,sum);
	(*sum)++;
	countNode(root->right,sum);
	}
return (*sum);
}

void wypisz(node *root)
{ printf("%10s",root->person.surname);
putchar(' ');
printf("%10s",root->person.name);
putchar(' ');
printf("%10ld",root->person.number);
putchar('\n');
	
return;
}

int height(node *root)
{if(root==NULL)
	return 0;
if(root->left == NULL && root->right == NULL)
	return 1;
int left=1, right=1;

if(root->left!=NULL)
	left=height(root->left);
if(root->right!=NULL)
	right=height(root->right);

if(left>right)
	return left+1;
else
	return right+1;
	
	
}


void simulation(node *root)
{unsigned int hill=0,nodes=0,logic=0;char mill;

printf("Ksiazka telefoniczna - wyswietli sie menu, poruszaj sie zgodnie ze wskazówkami\nNacisnij cokolwiek\n");
getchar();
system("clear");

while(2)
	{
	
	printf("Menu:\n1.Dodaj rekord\n2.Wyswietl wysokosc drzewa\n");
	printf("3.Wyswietl liczbe wezlow\n4.Wyswietl minimalny klucz\n");
	printf("5.Wyswietl maksymalny klucz\n6.Wyswietl wszystkie pozycje zgodnie z porządkiem alfabetycznym\n");
	printf("(Klucz w tym przypadku to nazwisko)\n");
	printf("Wpisanie indeksu, innego niż podane powoduje zakończenie działania programu\n");
	printf("Podaj numer:   "); scanf("%d",&logic);
	system("clear");
	switch(logic)
		{
		case 1:
			{insert(&root);	
			printf("\nPomyślnie dodano rekord\n");
			break;
			}
		case 2:
			{hill=height(root);
			printf("\nWysokosc drzewa to: %3d\n",hill);
			break;
			}
		case 3:
			{nodes=countNode(root,&nodes);
			printf("\nLiczba wezlow: %3d\n",nodes);
			nodes=0;
			break;
			}
		case 4:
			{printf("\nMinimalny klucz to: ");
			keyMIN(root);
			break;
			}
		case 5:
			{printf("\nMaksymalny klucz to: ");
			keyMAX(root);
			break;
			}
		case 6:
			{printf("%10s%10s%10s\n","Nazwisko:","Imię:","Numer:");
			inOrder(root);
			break;
			}
		default:
			{
			goto finish;
			
			break;
			}
		}
	
	putchar('\n');
		
		
	}
finish:

{
system("clear");
printf("Nie ma takiego rekordu, KONIEC PROGRAMU\nNaciśnij cokolwiek");		
getchar();
}
}

