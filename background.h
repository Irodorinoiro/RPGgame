#pragma once

#include "DxLib.h"
#include "core.h"
#include "Chara_Move.h"
#include <algorithm>
#include <cmath>

/// <summary>
/// �w�i�Ɋ֌W����N���X
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
	/// �^�C�g���w�i�̕`��
	/// </summary>
	void Title();

	void Main_haikei();

	/// <summary>
	/// �L�����N�^�[���̎��̔w�i�̕`��
	/// </summary>
	void CharaInfo();

	/// <summary>
	/// 1F �̔w�i�o�́D�v���C���[�̈ړ��ɍ��킹�Ĕw�i�ړ�����
	/// </summary>
	/// <param name="pic">�傫�Ȕw�i</param>
	void back_1F(const int pic);

	void  wall_draw(const int pic);

	/// <summary>
	/// �����蔻��Ȃ��̉摜�z�u
	/// </summary>
	/// <param name="x">���� x ���W</param>
	/// <param name="y">���� y ���W</param>
	/// <param name="pic">�摜</param>
	void putTile_no_hit_judge(int x, int y, int pic);
};