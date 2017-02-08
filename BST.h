#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 10

#ifndef BSTH
#define BSTH

typedef struct DANE
	{ 
	char name[SIZE];
	char surname[SIZE];
	long int number;         // zeby kazdy byl zerem???
	}data;

typedef struct NODE
	{
	struct NODE *left;
	struct NODE *right;
	data person;
	}node;

void insert(node **);
#endif
