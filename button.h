#pragma once

#include "DxLib.h"
#include "core.h"

/// <summary>
/// �{�^���𐧌䂷��N���X
/// </summary>
class Button
{
private:
	char m_key_buf[KEY_BUF];
	char m_old_key_buf[KEY_BUF] = { 0 };

	char* m_text;
	int m_font_size;
	int m_order;
	int m_cursor;
	int m_num_button;
	int m_x;
	int m_y;
	int diff_x = -50;
	int diff_y = -5;

	bool is_to_right = true;

	unsigned int m_arrow_img;
public:
	/// <summary>
	/// �J�[�\���̈ʒu��ݒ肷��֐�
	/// </summary>
	/// <param name="Cursor">�J�[�\���̈ʒu</param>
	void SetCursor(const int cursor);

	/// <summary>
	/// �{�^���̑�����ݒ肷��֐�
	/// </summary>
	/// <param name="Cursor">�{�^���̑���</param>
	void SetButtonNumber(const int num_button);

	/// <summary>
	/// �{�^�������ԖڂȂ̂���ݒ肷��֐�
	/// </summary>
	/// <param name="n">����</param>
	void SetOrder(const int n);

	/// <summary>
	/// �{�^���ɕ\�����镶�����ݒ肷��֐�
	/// </summary>
	/// <param name="text">�\����������������</param>
	/// <param name="font_size">�t�H���g�T�C�Y</param>
	void Text(const char* text, const int font_size);

	/// <summary>
	/// �{�^���̕`��
	/// </summary>
	/// <param name="X">X���W</param>
	/// <param name="Y">Y���W</param>
	void Draw(const int x, const int y);

	/// <summary>
	/// �{�^���������ꂽ���ǂ����𔻒肷��֐�
	/// </summary>
	/// <returns>�{�^���������ꂽ��true�C�����łȂ����false</returns>
	bool IsPushed();

	/// <summary>
	/// ���̉摜��ǂݍ���
	/// </summary>
	/// <param name="">�t�@�C���p�X</param>
	void LoadArrowImage(const char* file_path);

	/// <summary>
	/// ���̕`��
	/// </summary>
	void DrawArrow();

	void FontDraw(int size, int x, int y, const char* sentence);
};
