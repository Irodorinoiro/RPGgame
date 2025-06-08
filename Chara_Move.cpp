#include "chara_move.h"

void CharaMove::Move(const int front1, const int front2, const int front3,
    const int migi1, const int migi2, const int migi3,
    const int back1, const int back2, const int back3)
{
    if (CheckHitKey(KEY_INPUT_X))
    {
        player_speed = 7;
    }
    else
    {
        player_speed = 5;
    }

    if (CheckHitKey(KEY_INPUT_RIGHT)) // 右ボタンを押したら
    {
        if (is_side)
        {
            raw_moved_x = x + player_speed;
        }
        m_is_right_dir = true;
        m_is_up_dir = false;
        x = raw_moved_x;
    }
    if (CheckHitKey(KEY_INPUT_LEFT)) // 左ボタンを押したら
    {
        if (is_side)
        {
            raw_moved_x = x - player_speed;
        }
        m_is_right_dir = false;
        m_is_up_dir = true;
        
        x = raw_moved_x;
    }
    if (CheckHitKey(KEY_INPUT_UP)) // 上ボタンを押したら
    {
        if (is_side)
        {
            raw_moved_y = y - player_speed;
        }
        m_is_right_dir = true;
        m_is_up_dir = true;
        y = raw_moved_y;
    }
    if (CheckHitKey(KEY_INPUT_DOWN)) // 下ボタンを押したら
    {
        if (is_side)
        {
            raw_moved_y = y + player_speed;
        }
        m_is_right_dir = false;
        m_is_up_dir = false;
        y = raw_moved_y;
    }

    // 走り動作
    if ((CheckHitKey(KEY_INPUT_LEFT) or CheckHitKey(KEY_INPUT_RIGHT) or CheckHitKey(KEY_INPUT_UP) or CheckHitKey(KEY_INPUT_DOWN)) && CheckHitKey(KEY_INPUT_X))
    {
        if (m_walk_counter > 20)
        {
            m_walk_counter = 0;
        }
        ++m_walk_counter;
        if (0 <= m_walk_counter && m_walk_counter <= 5 or 10 < m_walk_counter && m_walk_counter <= 15)
        {
            if ((m_is_right_dir) && (m_is_up_dir))      // 正面
            {
                DrawExtendGraph(raw_moved_x, raw_moved_y, raw_moved_x + 300 * HANA_SIZE, raw_moved_y + 324 * HANA_SIZE, back1, TRUE);
            }
            else if ((!m_is_right_dir) && (!m_is_up_dir))   // 下
            {
                DrawExtendGraph(raw_moved_x, raw_moved_y, raw_moved_x + 300 * HANA_SIZE, raw_moved_y + 324 * HANA_SIZE, front1, TRUE);
            }
            else if ((!m_is_right_dir) && m_is_up_dir)   // 右
            {
                DrawExtendGraph(raw_moved_x, raw_moved_y, raw_moved_x + 300 * HANA_SIZE, raw_moved_y + 324 * HANA_SIZE, migi1, TRUE);
            }
            else if (m_is_right_dir && (!m_is_up_dir))   // 左
            {
                DrawExtendGraph(raw_moved_x + 300 * HANA_SIZE, raw_moved_y, raw_moved_x, raw_moved_y + 324 * HANA_SIZE, migi1, TRUE);
            }
        }
        else if (5 < m_walk_counter && m_walk_counter <= 10)
        {
            if ((m_is_right_dir) && (m_is_up_dir))
            {
                DrawExtendGraph(raw_moved_x, raw_moved_y, raw_moved_x + 300 * HANA_SIZE, raw_moved_y + 324 * HANA_SIZE, back2, TRUE);
            }
            else if ((!m_is_right_dir) && (!m_is_up_dir))   // 下
            {
                DrawExtendGraph(raw_moved_x, raw_moved_y, raw_moved_x + 300 * HANA_SIZE, raw_moved_y + 324 * HANA_SIZE, front2, TRUE);
            }
            else if ((!m_is_right_dir) && m_is_up_dir)
            {
                DrawExtendGraph(raw_moved_x, raw_moved_y, raw_moved_x + 300 * HANA_SIZE, raw_moved_y + 324 * HANA_SIZE, migi2, TRUE);
            }
            else if (m_is_right_dir && (!m_is_up_dir))
            {
                DrawExtendGraph(raw_moved_x + 300 * HANA_SIZE, raw_moved_y, raw_moved_x, raw_moved_y + 324 * HANA_SIZE, migi2, TRUE);
            }
        }
        else if (15 < m_walk_counter && m_walk_counter <= 20)
        {
            if ((m_is_right_dir) && (m_is_up_dir))
            {
                DrawExtendGraph(raw_moved_x, raw_moved_y, raw_moved_x + 300 * HANA_SIZE, raw_moved_y + 324 * HANA_SIZE, back3, TRUE);
            }
            else if ((!m_is_right_dir) && (!m_is_up_dir))   // 下
            {
                DrawExtendGraph(raw_moved_x, raw_moved_y, raw_moved_x + 300 * HANA_SIZE, raw_moved_y + 324 * HANA_SIZE, front3, TRUE);
            }
            else if ((!m_is_right_dir) && (m_is_up_dir))
            {
                DrawExtendGraph(raw_moved_x, raw_moved_y, raw_moved_x + 300 * HANA_SIZE, raw_moved_y + 324 * HANA_SIZE, migi3, TRUE);
            }
            else if (m_is_right_dir && (!m_is_up_dir))
            {
                DrawExtendGraph(raw_moved_x + 300 * HANA_SIZE, raw_moved_y, raw_moved_x, raw_moved_y + 324 * HANA_SIZE, migi3, TRUE);
            }
        }
        // カウンターの初期化
        if (m_walk_counter == 20)
        {
            m_walk_counter = 0;
        }
    }

    // 歩いているときの動作
    else if (CheckHitKey(KEY_INPUT_RIGHT) or CheckHitKey(KEY_INPUT_LEFT) or CheckHitKey(KEY_INPUT_UP) or CheckHitKey(KEY_INPUT_DOWN))
    {
        ++m_walk_counter;
        if (0 <= m_walk_counter && m_walk_counter <= 10 or 20 < m_walk_counter && m_walk_counter <= 30)
        {
            if ((m_is_right_dir) && (m_is_up_dir))      // 正面
            {
                DrawExtendGraph(raw_moved_x, raw_moved_y, raw_moved_x + 300 * HANA_SIZE, raw_moved_y + 324 * HANA_SIZE, back1, TRUE);
            }
            else if ((!m_is_right_dir) && (!m_is_up_dir))   // 下
            {
                DrawExtendGraph(raw_moved_x, raw_moved_y, raw_moved_x + 300 * HANA_SIZE, raw_moved_y + 324 * HANA_SIZE, front1, TRUE);
            }
            else if ((!m_is_right_dir) && m_is_up_dir)   // 右
            {
                DrawExtendGraph(raw_moved_x, raw_moved_y, raw_moved_x + 300 * HANA_SIZE, raw_moved_y + 324 * HANA_SIZE, migi1, TRUE);
            }
            else if (m_is_right_dir && (!m_is_up_dir))   // 左
            {
                DrawExtendGraph(raw_moved_x + 300 * HANA_SIZE, raw_moved_y, raw_moved_x, raw_moved_y + 324 * HANA_SIZE, migi1, TRUE);
            }
        }
        else if (10 < m_walk_counter && m_walk_counter <= 20)
        {
            if ((m_is_right_dir) && (m_is_up_dir))
            {
                DrawExtendGraph(raw_moved_x, raw_moved_y, raw_moved_x + 300 * HANA_SIZE, raw_moved_y + 324 * HANA_SIZE, back2, TRUE);
            }
            else if ((!m_is_right_dir) && (!m_is_up_dir))   // 下
            {
                DrawExtendGraph(raw_moved_x, raw_moved_y, raw_moved_x + 300 * HANA_SIZE, raw_moved_y + 324 * HANA_SIZE, front2, TRUE);
            }
            else if ((!m_is_right_dir) && m_is_up_dir)
            {
                DrawExtendGraph(raw_moved_x, raw_moved_y, raw_moved_x + 300 * HANA_SIZE, raw_moved_y + 324 * HANA_SIZE, migi2, TRUE);
            }
            else if (m_is_right_dir && (!m_is_up_dir))
            {
                DrawExtendGraph(raw_moved_x + 300 * HANA_SIZE, raw_moved_y, raw_moved_x, raw_moved_y + 324 * HANA_SIZE, migi2, TRUE);
            }
        }
        else if (30 < m_walk_counter && m_walk_counter <= 40)
        {
            if ((m_is_right_dir) && (m_is_up_dir))
            {
                DrawExtendGraph(raw_moved_x, raw_moved_y, raw_moved_x + 300 * HANA_SIZE, raw_moved_y + 324 * HANA_SIZE, back3, TRUE);
            }
            else if ((!m_is_right_dir) && (!m_is_up_dir))   // 下
            {
                DrawExtendGraph(raw_moved_x, raw_moved_y, raw_moved_x + 300 * HANA_SIZE, raw_moved_y + 324 * HANA_SIZE, front3, TRUE);
            }
            else if ((!m_is_right_dir) && (m_is_up_dir))
            {
                DrawExtendGraph(raw_moved_x, raw_moved_y, raw_moved_x + 300 * HANA_SIZE, raw_moved_y + 324 * HANA_SIZE, migi3, TRUE);
            }
            else if (m_is_right_dir && (!m_is_up_dir))
            {
                DrawExtendGraph(raw_moved_x + 300 * HANA_SIZE, raw_moved_y, raw_moved_x, raw_moved_y + 324 * HANA_SIZE, migi3, TRUE);
            }
        }
        // カウンターの初期化
        if (m_walk_counter == 40)
        {
            m_walk_counter = 0;
        }
    }
    else
    {
        if ((m_is_right_dir) && (m_is_up_dir))      // 正面
        {
            DrawExtendGraph(raw_moved_x, raw_moved_y, raw_moved_x + 300 * HANA_SIZE, raw_moved_y + 324 * HANA_SIZE, back1, TRUE);
        }
        else if ((!m_is_right_dir) && (!m_is_up_dir))   // 下
        {
            DrawExtendGraph(raw_moved_x, raw_moved_y, raw_moved_x + 300 * HANA_SIZE, raw_moved_y + 324 * HANA_SIZE, front1, TRUE);
        }
        else if ((!m_is_right_dir) && (m_is_up_dir))   // 右
        {
            DrawExtendGraph(raw_moved_x, raw_moved_y, raw_moved_x + 300 * HANA_SIZE, raw_moved_y + 324 * HANA_SIZE, migi1, TRUE);
        }
        else if (m_is_right_dir && (!m_is_up_dir))   // 左
        {
            DrawExtendGraph(raw_moved_x + 300 * HANA_SIZE, raw_moved_y, raw_moved_x, raw_moved_y + 324 * HANA_SIZE, migi1, TRUE);
        }
    }
    x = std::clamp(raw_moved_x, 50, WIDTH_X - 120);
    y = std::clamp(raw_moved_y, 50, WIDTH_Y - 120);
}


void CharaMove::TitleMovie(int g)
{
        PlayMovieToGraph(g);
        DrawExtendGraph(0, 0, 1280, 720, g, FALSE);
        WaitTimer(60);
}

void CharaMove::FeedOut(int bright)
{
    SetDrawBright(bright, bright, bright);
}