#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <DxLib.h>
#include "core.h"

class TextInclude
{
private:
    int m_count = 0;                                              // 
    std::map<int, std::vector<std::string>> m_serifus;            // 
    std::map<int, std::vector<int>> m_str_length;                  // 
public:
    /// <summary>
    /// セリフの txt ファイルを読み込む
    /// </summary>
    /// <param name="file_path">ファイルパス</param>
    /// <param name="num">セリフ番号</param>
    void Load(const char* file_path, const int num);

    /// <summary>
    /// セリフを描画する
    /// </summary>
    /// <param name="num">セリフ番号</param>
    /// <param name="line_num">セリフの行</param>
    /// <param name="X">表示する X 座標</param>
    /// <param name="Y">表示する Y 座標</param>
    void Draw(const int num, const int line_num, const int X, const int Y);
};



