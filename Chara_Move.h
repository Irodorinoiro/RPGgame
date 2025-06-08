#pragma once
#include"Dxlib.h"
#include "core.h"
#include <algorithm>
#include <mutex>

class CharaMove
{
private:
	int m_walk_counter = 0;            // カウント
    bool m_is_right_dir = false;        // 右向きかどうか
    bool m_is_up_dir = false;           // 上向きかどうか

public:
    int raw_moved_x = 0, raw_moved_y = 0;   //chara_move でつかう
    int player_speed;                   // 自機の速度
    int x;                          // 自機のX-座標
    int y;                          // 自機のY-座標
    int c_titleM;
    int bright = 255;
    bool is_side = false;            // 背景の端っこにいるか

    /// <summary>
    /// 自機を動かす関数
    /// </summary>
    void Move(const int front1, const int front2, const int front3,
        const int migi1, const int migi2, const int migi3,
        const int back1, const int back2, const int back3);

    /// <summary>
    /// タイトルのmovie再生専用
    /// </summary>
    /// <param name="g"></param>
    void TitleMovie(int g);

    void FeedOut(int bright);
};

