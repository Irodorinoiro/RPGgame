#include "DxLib.h"

#include "core.h"
#include "button.h"
#include "game.h"

int WINAPI WinMain(HINSTANCE hinstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(FALSE);

	if (DxLib_Init() == -1)
	{
		return -1;
	}
	
	ChangeWindowMode(TRUE);
	SetGraphMode(WIDTH_X, WIDTH_Y, 32);
	SetWindowSize(WIDTH_X, WIDTH_Y);
	SetDrawScreen(DX_SCREEN_BACK);
	SetMainWindowText(TITLE_TEXT);

	int game_state = TITLE;

	while (ProcessMessage() == 0)
	{
		switch (game_state)
		{
		case OPENING:
			game_state = Opening();
			break;

		// タイトル画面（初期画面）
		case TITLE:
			game_state = Title();
			break;

		case MODE_SELECT:
			game_state = ModeSelect();
			break;

		case EXTRA:
			game_state = Extra();
			break;

		case SCENE1:
			game_state = Scene1();
			break;

		case SCENE2:
			game_state = Scene2();
			break;

		case GAME_END:
			DxLib_End();
			return 0;
		}
	}

	DxLib_End();
	return 0;
}