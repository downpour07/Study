#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char name[17][7] = {
	{"000"},
	{"°­ÅÂ¾ç"},
	{"±èÈ£¼±"},
	{"³ë½ÂÁØ"},
	{"¹Ú¿¹ºó"},
	{"¼­µ¿ºó"},
	{"¾È½Â¹Î"},
	{"¾çÀ±È£"},
	{"À¯Áö¿ì"},
	{"ÀÌ°­Èñ"},
	{"ÀÌ±Ý±Ô"},
	{"ÀÌÀÇÁø"},
	{"ÀÌÅÂ±Ô"},
	{"Â÷Àººñ"},
	{"ÃÖÀ¯ÁØ"},
	{"ÃÖÈñ¿µ"},
	{"ÇÑ°ÇÈñ"}
};

int name_cnt[17] = { 0 };
int index[5][5] = { 0 };

void draw_teaching()
{
	printf("                       ------------------------------\n");
	printf("                      |             ±³Å¹             |\n");
	printf("                       ------------------------------\n");
	printf("\n");
	printf("\n");
}

void draw_table()
{
	printf("   --------------  --------------          --------------  -------------- \n");
	printf("  |              ||              |        |              ||              |\n");
	printf("  |    %s    ||    %s    |        |    %s    ||    %s    |\n", name[index[1][1]], name[index[1][2]], name[index[1][3]], name[index[1][4]]);
	printf("  |              ||              |        |              ||              |\n");
	printf("   --------------  --------------          --------------  -------------- \n");
	printf("   --------------  --------------          --------------  -------------- \n");
	printf("  |              ||              |        |              ||              |\n");
	printf("  |    %s    ||    %s    |        |    %s    ||    %s    |\n", name[index[2][1]], name[index[2][2]], name[index[2][3]], name[index[2][4]]);
	printf("  |              ||              |        |              ||              |\n");
	printf("   --------------  --------------          --------------  -------------- \n");
	printf("\n");
	printf("\n");
	printf("   --------------  --------------          --------------  -------------- \n");
	printf("  |              ||              |        |              ||              |\n");
	printf("  |    %s    ||    %s    |        |    %s    ||    %s    |\n", name[index[3][1]], name[index[3][2]], name[index[3][3]], name[index[3][4]]);
	printf("  |              ||              |        |              ||              |\n");
	printf("   --------------  --------------          --------------  -------------- \n");
	printf("   --------------  --------------          --------------  -------------- \n");
	printf("  |              ||              |        |              ||              |\n");
	printf("  |    %s    ||    %s    |        |    %s    ||    %s    |\n", name[index[4][1]], name[index[4][2]], name[index[4][3]], name[index[4][4]]);
	printf("  |              ||              |        |              ||              |\n");
	printf("   --------------  --------------          --------------  -------------- \n");
}

int main()
{
	draw_teaching();
	srand(time(NULL));
	for (int j = 1; j <= 4; j++)
	{
		for (int i = 1; i <= 4; i++)
		{
			index[j][i] = rand() % 16 + 1;
			if (name_cnt[index[j][i]] == 0)
			{
				name_cnt[index[j][i]]++;
			}
			else
			{
				i--;
			}
		}
	}
	draw_table();
	return 0;
}