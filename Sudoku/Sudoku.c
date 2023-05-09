#include <stdio.h>
#include <stdlib.h>


typedef struct Case
{
	char number;
}Case;



Case** createGrid();
void initGrid();
void displayGrid();



int main()
{
	int nbLigne = 9;
	int nbColonne = 9;
	Case** grid = createGrid(nbLigne, nbColonne);

	initGrid(grid, nbLigne, nbColonne);
	displayGrid(grid, nbLigne, nbColonne);
}

Case** createGrid(int nbLigne, int nbColonne)
{
	Case** Sudoku = (Case**)malloc(sizeof(Case*) * nbLigne);
	for (int i = 0; i < nbColonne ; i++)
	{
		Sudoku[i] = (Case*)malloc(sizeof(Case) * nbColonne);
	}
	return Sudoku;
}

void initGrid(Case** grid, int nbLigne, int nbColonne)
{
	Case** odefault = {'0'};
	for (int i = 0; i < nbLigne; i++)
	{
		for (int j = 0; j < nbColonne; j++)
		{
			grid[i][j].number = odefault;
		}
	}
}

void displayGrid(Case** grid, int nbLigne, int nbColonne)
{
	for (int i = 0; i < nbLigne; i++)
	{
		for (int j = 0; j < nbColonne; j++)
		{
			printf("%c ", grid[i][j].number);
		}
		printf("\n");
	}
	printf("\n");
}
