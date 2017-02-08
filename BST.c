#include "BST.h"
#include "funny.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10


void insert(node **root)
{	node *newnode; data *newdata; node *currentNode;
	newnode=(node*)malloc(sizeof(node));
	if(newnode==NULL)
		{
		printf("/nBlad alokacji/n");	
		free(newnode);
		newnode=NULL;
		return;
		}
	newnode->left=NULL;				//trzeba nullowac wartosc left 
	newnode->right=NULL;				// i right

	newdata=(data*)malloc(sizeof(data));
	if(newdata==NULL)
		{
		printf("/nBlad alokacji/n");	
		free(newdata);
		newdata=NULL;
		return;
		}
	long int numer;
	printf("\nPodaj imie: "); scanf("%s",newdata->name);//printf(" %s",newdata->name);
	printf("\nPodaj nazwisko: "); scanf("%s",newdata->surname); //printf(" %s", newdata->surname);    
        printf("\nPodaj numer: "); scanf("%ld", &newdata->number); //printf("%ld",newdata->number);
	
	newnode->person=(*newdata);
	


	currentNode=*root;	
        
	if((*root)==NULL)
		{*root=newnode;
		
		return;	

		}
	
	char napis[10]="siema";
	do
	{ if(strcmp ( currentNode->person.surname, newnode->person.surname ) > 0) 
		{
			if(currentNode->left==NULL)
				{currentNode->left=newnode;
				return;
				}
			else 
				{currentNode=currentNode->left;
				}
		}
	  if(strcmp ( currentNode->person.surname , newnode->person.surname ) < 0)	//porownanie napisow
		
		{   
			if(currentNode->right == NULL)		//  wpisywanie tych danych
				{currentNode->right=newnode;
				return;
				
				}
			else
				{currentNode=currentNode->right;
				}
		}
	}

	while( currentNode!=NULL );
	return;
}

