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
	/// �w�i�摜��ǂݍ��ފ֐�
	/// </summary>
	void read();

	/// <summary>
	/// text�t�@�C����ǂݎ��
	/// </summary>
	void TextRead();

	/// <summary>
	/// �w�i�摜���o�͂���
	/// </summary>
	void Out();
	
	struct
	{
		int Typ[MAP_MAX_X][MAP_MAX_Y];

		std::vector <std::vector<int>> Typ_Exp;
	}Blo;
};