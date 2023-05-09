#include <stdio.h>
#include <stdlib.h>


typedef struct Case
{
	int number;
}Case;

Case** createGrid();


int main()
{
	int nbLigne = 9;
	int nbColonne = 9;
	createGrid(nbLigne, nbColonne);
}

Case** createGrid(int nbLigne, int nbColonne)
{
	Case** Sudoku = (Case**)malloc(sizeof(Case*) * nbLigne);
	for (int i = 0; i < nbColonne; i++)
	{
		Sudoku[i] = (Case*)malloc(sizeof(Case) * nbColonne);
	}
	return Sudoku;
}
