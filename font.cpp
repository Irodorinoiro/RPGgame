#include "font.h"

void Font::GothicFont()
{
	LPCSTR font_path = "DotGothic16.ttf";
	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0) {
	}
	else {
		// フォント読込エラー処理
		MessageBox(NULL, "フォント読込失敗", "", MB_OK);
	}
	SetFontSize(36);
	ChangeFont("DotGothic16", DX_CHARSET_DEFAULT);
	DrawString(10, 240, "この文字はフォントです。", GetColor(255, 255, 255));

	if (RemoveFontResourceEx(font_path, FR_PRIVATE, NULL)) {
	}
	else {
		MessageBox(NULL, "remove failure", "", MB_OK);
	}
}