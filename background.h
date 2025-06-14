#pragma once

#include "DxLib.h"
#include "core.h"
#include "Chara_Move.h"
#include <algorithm>
#include <cmath>

/// <summary>
/// 背景に関係するクラス
/// </summary>
class Background
{
public:
	int item_x = 0;
	int item_y = 0;
	int test_x, test_y;
	int count = 0;
	int count1 = 0;

	/// <summary>
	/// タイトル背景の描画
	/// </summary>
	void Title();

	void Main_haikei();

	/// <summary>
	/// キャラクター情報の時の背景の描画
	/// </summary>
	void CharaInfo();

	/// <summary>
	/// 1F の背景出力．プレイヤーの移動に合わせて背景移動する
	/// </summary>
	/// <param name="pic">大きな背景</param>
	void back_1F(const int pic);

	void  wall_draw(const int pic);

	/// <summary>
	/// 当たり判定なしの画像配置
	/// </summary>
	/// <param name="x">初期 x 座標</param>
	/// <param name="y">初期 y 座標</param>
	/// <param name="pic">画像</param>
	void putTile_no_hit_judge(int x, int y, int pic);
};