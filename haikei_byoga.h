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
	/// ”wŒi‰æ‘œ‚ğ“Ç‚İ‚ŞŠÖ”
	/// </summary>
	void read();

	/// <summary>
	/// textƒtƒ@ƒCƒ‹‚ğ“Ç‚İæ‚é
	/// </summary>
	void TextRead();

	/// <summary>
	/// ”wŒi‰æ‘œ‚ğo—Í‚·‚é
	/// </summary>
	void Out();
	
	struct
	{
		int Typ[MAP_MAX_X][MAP_MAX_Y];

		std::vector <std::vector<int>> Typ_Exp;
	}Blo;
};