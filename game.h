#pragma once

#include "DxLib.h"

#include "core.h"
#include "button.h"
#include "background.h"
#include "keyboard.h"
#include "Chara_Move.h"
#include "haikei_byoga.h"

/// <summary>
/// オープニング画面の描画
/// </summary>
/// <returns>状態</returns>
int Opening();

/// <summary>
/// タイトルを制御する関数
/// </summary>
/// <returns>状態</returns>
int Title();

/// <summary>
/// モード選択画面を制御する関数
/// </summary>
/// <returns>状態</returns>
int ModeSelect();

/// <summary>
/// エキストラを制御する関数
/// </summary>
/// <returns>状態</returns>
int Extra();

/// <summary>
/// 1F を制御する関数
/// </summary>
/// <returns>状態</returns>
int Scene1();

/// <summary>
/// 廊下を制御する関数
/// </summary>
/// <returns>状態</returns>
int Scene2();