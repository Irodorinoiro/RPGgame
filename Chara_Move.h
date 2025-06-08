#pragma once
#include"Dxlib.h"
#include "core.h"
#include <algorithm>
#include <mutex>

class CharaMove
{
private:
	int m_walk_counter = 0;            // �J�E���g
    bool m_is_right_dir = false;        // �E�������ǂ���
    bool m_is_up_dir = false;           // ��������ǂ���

public:
    int raw_moved_x = 0, raw_moved_y = 0;   //chara_move �ł���
    int player_speed;                   // ���@�̑��x
    int x;                          // ���@��X-���W
    int y;                          // ���@��Y-���W
    int c_titleM;
    int bright = 255;
    bool is_side = false;            // �w�i�̒[�����ɂ��邩

    /// <summary>
    /// ���@�𓮂����֐�
    /// </summary>
    void Move(const int front1, const int front2, const int front3,
        const int migi1, const int migi2, const int migi3,
        const int back1, const int back2, const int back3);

    /// <summary>
    /// �^�C�g����movie�Đ���p
    /// </summary>
    /// <param name="g"></param>
    void TitleMovie(int g);

    void FeedOut(int bright);
};

