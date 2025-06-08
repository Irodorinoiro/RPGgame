#include "haikei_byoga.h"

void HaikeiByoga::initTypExp(const int x_size = MAP_MAX_X, const int y_size = MAP_MAX_Y)
{
	Blo.Typ_Exp.resize(x_size);
	for(int i = 0; i < x_size; ++i)
	{
		Blo.Typ_Exp[i].resize(y_size);
	}
}

void HaikeiByoga::read()
{
	floor = LoadGraph("gazo_gamedx/floor_tile.png");
	wall_1F = LoadGraph("gazo_gamedx/wall_cell.png");
}

void HaikeiByoga::TextRead()
{
	FILE* fp_stage_1F;
	errno_t error;

	//テキストファイルの読み取り
	error = fopen_s(&fp_stage_1F, "gazo_gamedx/1F_hospital.txt", "r");
	if (error != 0)
	{
		printf("ファイルを開けませんでした");
	}
	else
	{
		for (y = 0; y < MAP_MAX_Y; ++y)
		{
			for (x = 0; x < MAP_MAX_X; ++x)
			{
				fscanf_s(fp_stage_1F, "%d", &Blo.Typ[x][y]);
			}
		}
		fclose(fp_stage_1F);
	}
}

void HaikeiByoga::Out()
{
	int pic = 0;
	for (x = 0; x < MAP_MAX_X; ++x)
	{
		for (y = 0; y < MAP_MAX_Y; ++y)
		{
			if (Blo.Typ[x][y] == 0)
			{
				continue;
			}
			if (Blo.Typ[x][y] == 1)
			{
				//DrawBox(CELL * x, CELL * y, CELL * x + CELL, CELL * y + CELL, GetColor(WHITE), TRUE);
				DrawGraph(CELL * x + CELL * 3, CELL * y, wall_1F, FALSE);
			}
			if (Blo.Typ[x][y] == 2)
			{
				//DrawBox(CELL * x, CELL * y, CELL * x + CELL, CELL * y + CELL, GetColor(BLACK), TRUE);
				DrawGraph(CELL * x + CELL * 3, CELL * y, floor, FALSE);
			}
			// DrawFormatString(CELL * x, CELL * y, GetColor(WHITE), "%d", Blo.Typ[x][y]);
		}
	}
}