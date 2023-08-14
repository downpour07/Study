#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <ctime>
using namespace std;
constexpr auto Y_dino = 12;
constexpr auto Y_tree = 20;
constexpr auto X_tree = 45;

void SetConsoleView()
{
	system("mode con:cols=100 lines=25");
	system("title Google Dinosaurs.");
}

void GotoXY(int x, int y)
{
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

int GetKeyDown()
{
	if (_kbhit() != 0)
	{
		return _getch();
	}
	return 0;
}

void DrawDino(int Y)
{
	GotoXY(0, Y);
	static bool legFlag = true;
	printf("        ******* \n");
	printf("       ** ******\n");
	printf("       *********\n");
	printf("*      ***      \n");
	printf("**     *******  \n");
	printf("***   *****     \n");
	printf(" **  ********** \n");
	printf(" ***********    \n");
	printf("   *********    \n");
	printf("     ******     \n");
	if (legFlag)
	{
		printf("     *    ***    \n");
		printf("     **          ");
		legFlag = false;
	}
	else
	{
		printf("     ***  *     \n");
		printf("          **    ");
		legFlag = true;
	}
}

void DrawTree(int X)
{
	GotoXY(X, Y_tree);
	printf("****");
	GotoXY(X, Y_tree + 1);
	printf(" ** ");
	GotoXY(X, Y_tree + 2);
	printf(" ** ");
	GotoXY(X, Y_tree + 3);
	printf(" ** ");
	GotoXY(X, Y_tree + 4);
	printf(" ** ");
}

void DrawGameOver(const int score)
{
	system("cls");
	int x = 18;
	int y = 8;
	GotoXY(x, y);
	printf("===========================");
	GotoXY(x, y + 1);
	printf("=====G A M E O V E R=====");
	GotoXY(x, y + 2);
	printf("===========================");
	GotoXY(x, y + 5);
	printf("SCORE : %d", score);

	printf("\n\n\n\n\n\n\n\n\n\n");
	system("pause");
}

bool isCollision(const int X, const int Y)
{
	GotoXY(0, 0);
	printf("treeX : %d, dinoY : %d", X, Y);
	if (X <= 8 && X >= 4 && Y > 8)
	{
		return true;
	}
	return false;
}

int main()
{
	SetConsoleView();

	while (true)
	{
		bool isJumping = false;
		bool isBottom = true;
		const int gravity = 3;

		int dinoY = Y_dino;
		int treeX = X_tree;

		int score = 0;
		clock_t start, curr;
		start = clock();

		while (true)
		{
			if (isCollision(treeX, dinoY))
			{
				break;
			}
			if (GetKeyDown() == ' ' && isBottom)
			{
				isJumping = true;
				isBottom = false;
			}
			if (isJumping)
			{
				dinoY -= gravity;
			}
			else
			{
				dinoY += gravity;
			}

			if (dinoY >= Y_dino)
			{
				dinoY = Y_dino;
				isBottom = true;
			}
			treeX -= 2;
			if (treeX <= 0)
			{
				treeX = X_tree;
			}

			if (dinoY <= 3)
			{
				isJumping = false;
			}
			DrawDino(dinoY);
			DrawTree(treeX);

			curr = clock();
			if (((curr - start) / CLOCKS_PER_SEC) >= 1)
			{
				score++;
				start = clock();
			}
			Sleep(60);
			system("cls");
			GotoXY(22, 0);
			printf("Score : %d ", score);
		}
		DrawGameOver(score);
	}
	return 0;
}