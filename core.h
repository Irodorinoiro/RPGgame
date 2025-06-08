#pragma once
#include "DxLib.h"

#define TITLE_TEXT "�����Ƃ�"
#define WIDTH_X 1275
#define WIDTH_Y 714
//#define WIDTH_X_HALF 640
//#define WIDTH_Y_HALF 360
#define TITLEFONTSIZE 25
#define KEY_BUF 256

// �Q�[����� ( switch ���Ŏg�� )
#define GAME_END -1
#define OPENING 0
#define TITLE 1
#define MODE_SELECT 2
#define EXTRA 3
#define SCENE1 4
#define SCENE2 5

//�F
#define LIGHT_BLUE 0, 255, 200
#define WHITE 255, 255, 255
#define BLACK 0, 0, 0
#define PINK 240, 180, 240
#define ENJI 180, 50, 125
#define BLUE 40,39,50
#define DARK_BLUE 35, 35, 45

// �}�b�v����
#define CELL 55 // �w�i�摜��ӂ̒���
#define MAP_CELL_HORIZONTAL 60 / 2 // �������}�b�v�̑傫�� (�Е�)
#define MAP_CELL_VERTICAL 30 / 2 // �c�����}�b�v�̑傫�� (�Е�)


//�摜����
#define HANA_SIZE 0.20 // hana �̉摜�䗦
#define PLAYER_X CELL * 12	//hana �̏����ʒu
#define PLAYER_Y CELL * 7	//hana �̏����ʒu

#define MAX_X WIDTH_X / CELL

#define MAP_MAX_X MAX_X + 10
#define MAP_MAX_Y 14

/// <summary>
/// FPS�𐧌䂷��֐�
/// </summary>
/// <param name="fps">FPS</param>
void FPS(const int fps);