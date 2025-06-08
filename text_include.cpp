#include "Text_include.h"

void TextInclude::Load(const char* file_path, const int num)
{
    char text[1000];
    int file_handle = FileRead_open(file_path);

    while (FileRead_eof(file_handle) == 0)
    {
        FileRead_gets(text, sizeof(text), file_handle);
        m_serifus[num].emplace_back(text);
        m_str_length[num].emplace_back(0);
    }

    FileRead_close(file_handle);
}

void TextInclude::Draw(const int num, const int line_num, const int X, const int Y)
{
    int j, k, char_length;
    char text[1000];

    ++m_count;
    if (m_count >= 20)
    {
        m_count = 0;
    }

    if (m_count == 0)
    {
        m_str_length[num][line_num] += 2;
        if (m_str_length[num][line_num] > strlen(m_serifus[num][line_num].c_str()))
        {
            m_str_length[num][line_num] = strlen(m_serifus[num][line_num].c_str());
        }
    }

    // �������ꕶ�����\��
    for (j = 0; j <= m_str_length[num][line_num]; j += 2)
    {
        for (k = 0; k < j; ++k)
        {
            text[k] = m_serifus[num][line_num].c_str()[k];
        }
        text[j] = '\0';
    }
    DrawFormatString(X, Y, GetColor(BLACK), "%s", text);
}
