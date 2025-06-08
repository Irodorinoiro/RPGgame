#pragma once

#include "DxLib.h"
#include "core.h"
#include "Chara_Move.h"
#include <algorithm>
#include <cmath>

/// <summary>
/// ”wŒi‚ÉŠÖŒW‚·‚éƒNƒ‰ƒX
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
	/// ƒ^ƒCƒgƒ‹”wŒi‚Ì•`‰æ
	/// </summary>
	void Title();

	void Main_haikei();

	/// <summary>
	/// ƒLƒƒƒ‰ƒNƒ^[î•ñ‚Ì‚Ì”wŒi‚Ì•`‰æ
	/// </summary>
	void CharaInfo();

	/// <summary>
	/// 1F ‚Ì”wŒio—ÍDƒvƒŒƒCƒ„[‚ÌˆÚ“®‚É‡‚í‚¹‚Ä”wŒiˆÚ“®‚·‚é
	/// </summary>
	/// <param name="pic">‘å‚«‚È”wŒi</param>
	void back_1F(const int pic);

	void  wall_draw(const int pic);

	/// <summary>
	/// “–‚½‚è”»’è‚È‚µ‚Ì‰æ‘œ”z’u
	/// </summary>
	/// <param name="x">‰Šú x À•W</param>
	/// <param name="y">‰Šú y À•W</param>
	/// <param name="pic">‰æ‘œ</param>
	void putTile_no_hit_judge(int x, int y, int pic);
};