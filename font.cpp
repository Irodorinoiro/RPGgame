#include "font.h"

void Font::GothicFont()
{
	LPCSTR font_path = "DotGothic16.ttf";
	if (AddFontResourceEx(font_path, FR_PRIVATE, NULL) > 0) {
	}
	else {
		// �t�H���g�Ǎ��G���[����
		MessageBox(NULL, "�t�H���g�Ǎ����s", "", MB_OK);
	}
	SetFontSize(36);
	ChangeFont("DotGothic16", DX_CHARSET_DEFAULT);
	DrawString(10, 240, "���̕����̓t�H���g�ł��B", GetColor(255, 255, 255));

	if (RemoveFontResourceEx(font_path, FR_PRIVATE, NULL)) {
	}
	else {
		MessageBox(NULL, "remove failure", "", MB_OK);
	}
}