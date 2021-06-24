#include <Windows.h> 

#define IsKeyPressed(nVirtKey) ((GetKeyState(nVirtKey) & (1<<(sizeof(SHORT)*8-1))) != 0)
#define IsKeyNotPressed(nVirtKey) ((GetKeyState(nVirtKey) & (1<<(sizeof(SHORT)*8-1))) == 0)
#define KBE(index) keybd_event(newKey[index], 0, 0x0000, 1 << 24)

#define _11 VK_OEM_3
#define _12 VK_OEM_MINUS
#define _13 VK_OEM_PLUS
#define _21 VK_OEM_4
#define _22 VK_OEM_6
#define _23 VK_OEM_5
#define _31 VK_OEM_1
#define _32 VK_OEM_7
#define _41 VK_OEM_COMMA
#define _42 VK_OEM_PERIOD
#define _43 VK_OEM_2

static HHOOK keyboardHook = nullptr;

BYTE newKey[47]{
	_11,'1','2','3','4','5','6','7','8','9','0',_12,_13,
	'Q','W','E','R','T','Y','U','I','O','P',_21,_22,_23,
	'A','S','D','F','G','H','J','K','L',_31,_32,
	'Z','X','C','V','B','N','M',_41,_42,_43
};

inline void installDvorakKB()
{
	newKey[0] = _11;
	newKey[1] = '1';
	newKey[2] = '2';
	newKey[3] = '3';
	newKey[4] = '4';
	newKey[5] = '5';
	newKey[6] = '6';
	newKey[7] = '7';
	newKey[8] = '8';
	newKey[9] = '9';
	newKey[10] = '0';
	newKey[11] = _21;
	newKey[12] = _22;

	newKey[13] = _32;
	newKey[14] = _41;
	newKey[15] = _42;
	newKey[16] = 'P';
	newKey[17] = 'Y';
	newKey[18] = 'F';
	newKey[19] = 'G';
	newKey[20] = 'C';
	newKey[21] = 'R';
	newKey[22] = 'L';
	newKey[23] = _43;
	newKey[24] = _13;
	newKey[25] = _23;

	newKey[26] = 'A';
	newKey[27] = 'O';
	newKey[28] = 'E';
	newKey[29] = 'U';
	newKey[30] = 'I';
	newKey[31] = 'D';
	newKey[32] = 'H';
	newKey[33] = 'T';
	newKey[34] = 'N';
	newKey[35] = 'S';
	newKey[36] = _22;

	newKey[37] = _21;
	newKey[38] = 'Q';
	newKey[39] = 'J';
	newKey[40] = 'K';
	newKey[41] = 'X';
	newKey[42] = 'B';
	newKey[43] = 'M';
	newKey[44] = 'W';
	newKey[45] = 'V';
	newKey[46] = 'Z';
}

LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	auto* p = reinterpret_cast<PKBDLLHOOKSTRUCT>(lParam);
	bool tempFlag = false;
	if (wParam == WM_KEYDOWN)
	{
		if (IsKeyPressed(VK_CONTROL) && IsKeyPressed(VK_SHIFT) && IsKeyPressed('Q'))
			PostQuitMessage(0);
		else if (p->dwExtraInfo != 1 << 24 &&
			IsKeyNotPressed(VK_CONTROL) &&
			IsKeyNotPressed(VK_LWIN) &&
			IsKeyNotPressed(VK_RWIN) &&
			IsKeyNotPressed(VK_MENU) &&
			IsKeyNotPressed(VK_TAB)) {
			tempFlag = true;
			switch (p->vkCode)
			{
			case _11:KBE(0); break;
			case '1':KBE(1); break;
			case '2':KBE(2); break;
			case '3':KBE(3); break;
			case '4':KBE(4); break;
			case '5':KBE(5); break;
			case '6':KBE(6); break;
			case '7':KBE(7); break;
			case '8':KBE(8); break;
			case '9':KBE(9); break;
			case '0':KBE(10); break;
			case _12:KBE(11); break;
			case _13:KBE(12); break;

			case 'Q':KBE(13); break;
			case 'W':KBE(14); break;
			case 'E':KBE(15); break;
			case 'T':KBE(17); break;
			case 'Y':KBE(18); break;
			case 'U':KBE(19); break;
			case 'I':KBE(20); break;
			case 'O':KBE(21); break;
			case 'P':KBE(22); break;
			case _21:KBE(23); break;
			case _22:KBE(24); break;
			case _23:KBE(25); break;

			case 'A':KBE(26); break;
			case 'S':KBE(27); break;
			case 'D':KBE(28); break;
			case 'F':KBE(29); break;
			case 'G':KBE(30); break;
			case 'H':KBE(31); break;
			case 'J':KBE(32); break;
			case 'K':KBE(33); break;
			case 'L':KBE(34); break;
			case _31:KBE(35); break;
			case _32:KBE(36); break;

			case 'Z':KBE(37); break;
			case 'X':KBE(38); break;
			case 'C':KBE(39); break;
			case 'V':KBE(40); break;
			case 'B':KBE(41); break;
			case 'N':KBE(42); break;
			case 'M':KBE(43); break;
			case _41:KBE(44); break;
			case _42:KBE(45); break;
			case _43:KBE(46); break;
			default:
				tempFlag = false;
				break;
			}
		}
	}
	if (tempFlag)
		return 1;
	return CallNextHookEx(keyboardHook, nCode, wParam, lParam);
}

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPreINstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	//安装键盘钩子
	installDvorakKB();
	keyboardHook = SetWindowsHookEx(WH_KEYBOARD_LL, &KeyboardProc, hInstance, NULL);
	if (keyboardHook == nullptr)
		return 1;
	//进行事件循环
	MSG msg;
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}