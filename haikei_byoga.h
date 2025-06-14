#pragma once

#include <vector>
#include "DxLib.h"
#include "core.h"

class HaikeiByoga
{
private:
	void initTypExp(const int x_size, const int y_size);

public:
	int x, y;
	int floor;
	int wall_1F;
	int Kake_1F;
	int Naname_1F;

	/// <summary>
	/// 背景画像を読み込む関数
	/// </summary>
	void read();

	/// <summary>
	/// textファイルを読み取る
	/// </summary>
	void TextRead();

	/// <summary>
	/// 背景画像を出力する
	/// </summary>
	void Out();
	
	struct
	{
		int Typ[MAP_MAX_X][MAP_MAX_Y];

		std::vector <std::vector<int>> Typ_Exp;
	}Blo;
};