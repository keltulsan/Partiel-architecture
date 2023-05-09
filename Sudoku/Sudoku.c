#include <stdio.h>
#include <stdlib.h>


typedef struct Case
{
	char number;
}Case;



Case** createGrid();
void initGrid();
void displayGrid();
void askPosition();
char askNumber();



int main()
{
	int nbLigne = 9;
	int nbColonne = 9;
	int victory = 0;
	Case** grid = createGrid(nbLigne, nbColonne);

	initGrid(grid, nbLigne, nbColonne);
	displayGrid(grid, nbLigne, nbColonne);
	while (victory == 0)
	{
		askPosition(grid, nbLigne, nbColonne);
		displayGrid(grid, nbLigne, nbColonne);
	}
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
	Case** odefault = {'X'};
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

void askPosition(Case** grid, int nbLigne, int nbColonne)
{
	int i = 0;
	int j = 0;
	printf("Ou voulez vous placer votre prochian nombre ?  ligne/colonne : \n");
	scanf_s("%d/%d", i, j);
	if (i < 1 || i > nbLigne)
	{
		printf("La ligne selectionnee est incorecte : \n");
		scanf_s("%d/", i);
	}
	else if (j < 1 || j >nbColonne)
	{
		printf("La colonne selectionnee est incorecte : \n");
		scanf_s("%d/", j);
	}

	grid[i-1][j-1].number = askNumber(grid, nbLigne, nbColonne);

}

char askNumber(Case** grid, int nbLigne, int nbColonne)
{
	int number = 1;
	printf("Quel nombre voulez vous placer ? entre 1 et 9 : \n");
	scanf_s("%c", number);
	if (number != '1' && number != '2'&& number != '3'&& number != '4'&& number != '5'&& number != '6'&& number != '7'&& number != '8'&& number != '9')
	{
		printf("La nombre selectionne est incorecte : \n");
		scanf_s("%c/", number);
	}
	return number;
}

/*int verifNumbers(Case** grid, int nbLigne, int nbColonne, int* victory)
{
	char tab = malloc(sizeof(char) * 9);
	int notIn = 1;
	for (int i = 0; i < nbLigne; i++)
	{
		for (int j = 0; j < nbColonne; j++)
		{
			for (int el = 0; el < 9; el++)
			{
				if (tab[el] == grid[i][j].number)
				{
					notIn = 0;
				}
			}
			if (notIn == 1)
			{

			}
		}
	*/


