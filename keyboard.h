#pragma once

#include "DxLib.h"
#include "core.h"

class Keyboard
{
private:
	char m_key_buf[KEY_BUF];
	char m_old_key_buf[KEY_BUF] = { 0 };
	int m_num_button;
public:
	void SetIndexNum(const int n);

	/// <summary>
	/// �L�[�̏�Ԃ��擾
	/// </summary>
	void GetKeyState();

	/// <summary>
	/// �L�[�̏�Ԃ�ۑ�
	/// </summary>
	void SaveKeyState();

	/// <summary>
	/// �J�[�\���𓮂���
	/// </summary>
	/// <param name="cursor">�J�[�\���ʒu</param>
	void MoveCursor(int& cursor);
};

