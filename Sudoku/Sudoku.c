#include <stdio.h>
#include <stdlib.h>

void createGrid();



typedef struct Case
{
	int number;
}Case;


int main()
{
	int nbLigne = 9;
	int nbColonne = 9;
	createGrid(nbLigne, nbColonne);
}

void createGrid(int nbLigne, int nbColonne)
{
	Case** Sudoku = (Case**)malloc(sizeof(Case*) * nbLigne);
	for (int i = 0; i < nbColonne; i++)
	{
		Sudoku[i] = (Case*)malloc(sizeof(Case) * nbColonne);
	}
} 
