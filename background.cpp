#include "background.h"

void Background::Title()
{
	DrawBox(0, 0, WIDTH_X, WIDTH_Y, GetColor(WHITE), TRUE);
}

void Background::Main_haikei()
{
	DrawBox(0, 0, WIDTH_X, WIDTH_Y, GetColor(BLUE), TRUE);
}

void Background::CharaInfo()
{
	DrawBox(0, 0, WIDTH_X, WIDTH_Y, GetColor(WHITE), TRUE);
	DrawBox(0, 0, WIDTH_X, 30, GetColor(DARK_BLUE), TRUE);
	DrawBox(0, 690, WIDTH_X, 720, GetColor(DARK_BLUE), TRUE);
}

void Background::back_1F(const int pic)
{
	if (CheckHitKey(KEY_INPUT_RIGHT)) // 右ボタンを押したら背景を左に動かす
	{
		item_x -= 5;
		item_x = std::clamp(item_x, -1 * CELL * (MAP_CELL_HORIZONTAL - 1) + 32, (MAP_CELL_HORIZONTAL) * CELL - 8);
	}
	if (CheckHitKey(KEY_INPUT_LEFT)) // 左ボタンを押したら
	{
		item_x += 5;
		item_x = std::clamp(item_x, -1 * CELL * (MAP_CELL_HORIZONTAL - 1) + 32, MAP_CELL_HORIZONTAL * CELL - 8);
	}
	if (CheckHitKey(KEY_INPUT_UP)) // 上ボタンを押したら
	{
		item_y += 5;
		item_y = std::clamp(item_y, -1 * (CELL + 3) * (MAP_CELL_VERTICAL), MAP_CELL_VERTICAL * (CELL + 1) + 60);
	}
	if (CheckHitKey(KEY_INPUT_DOWN)) // 下ボタンを押したら
	{
		item_y -= 5;
		item_y = std::clamp(item_y, -1 * (CELL) * (MAP_CELL_VERTICAL) + 123, MAP_CELL_VERTICAL * (CELL + 1) + 60);
	}

	test_x = (item_x - count * CELL) % (CELL);
	test_y = (item_y - count1 * CELL) % (CELL);
	if (CheckHitKey(KEY_INPUT_LEFT) && test_x >= CELL)
	{
		++count;
	}
	else if (CheckHitKey(KEY_INPUT_UP) && test_y >= CELL)
	{
		++count1;
	}
	// 背景描画
	DrawGraph(test_x - CELL, test_y - CELL, pic, TRUE);

	// 黒背景描画
	if (item_y >= CELL * (MAP_CELL_HORIZONTAL - 21))	// 上移動
	{
		DrawBox(0, 0, WIDTH_X, item_y - CELL * (MAP_CELL_HORIZONTAL - 21), GetColor(BLACK), TRUE);
	}
	else if (item_y <= CELL * (-1 * (MAP_CELL_HORIZONTAL - 22) + 10))	// 下移動
	{
		DrawBox(0, WIDTH_Y + item_y + CELL * (MAP_CELL_HORIZONTAL - 22) - 5, WIDTH_X, WIDTH_Y, GetColor(BLACK), TRUE);
	}
}

void  Background::wall_draw(const int pic)
{
	// 壁描画
	if (item_y >= CELL * (MAP_CELL_HORIZONTAL - 21))
	{
		DrawGraph(test_x - CELL, item_y - CELL * (MAP_CELL_HORIZONTAL - 21) - CELL * 3, pic, FALSE);
	}

	// 黒背景描画

	if (item_x >= CELL * (MAP_CELL_HORIZONTAL - 12))	// 左移動
	{
		DrawBox(0, 0, item_x - CELL * (MAP_CELL_HORIZONTAL - 12), WIDTH_Y, GetColor(BLACK), TRUE);
	}
	else if (item_x <= CELL * (-1 * (MAP_CELL_HORIZONTAL - 13) + 14))	// 右移動
	{
		DrawBox(WIDTH_X + item_x + CELL * (MAP_CELL_HORIZONTAL - 13) - 14, 0, WIDTH_X, WIDTH_Y, GetColor(BLACK), TRUE);
	}
}

void Background::putTile_no_hit_judge(int x, int y, int pic)
{
	DrawGraph(x + item_x, y + item_y, pic, TRUE);
}

void kakou(const int pic)
{
	SetDrawBlendMode(DX_BLENDMODE_ADD, 255);
	DrawGraph(0, 0, pic, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}
