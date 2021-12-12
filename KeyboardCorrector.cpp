#include <Windows.h> 

inline auto IsKeyPressed(const int nVirtualKey) { return (GetKeyState(nVirtualKey) & (1 << (sizeof(SHORT) * 8 - 1))) != 0; }

inline auto Kbe(const int index) { keybd_event(KeyboardLayoutList[KeyboardLayoutIndex][index], 0, 0x0000, 1 << 24); }

#pragma region 某些键盘上符号的虚拟键代码
constexpr auto _11 = VK_OEM_3;
constexpr auto _12 = VK_OEM_MINUS;
constexpr auto _13 = VK_OEM_PLUS;
constexpr auto _21 = VK_OEM_4;
constexpr auto _22 = VK_OEM_6;
constexpr auto _23 = VK_OEM_5;
constexpr auto _31 = VK_OEM_1;
constexpr auto _32 = VK_OEM_7;
constexpr auto _41 = VK_OEM_COMMA;
constexpr auto _42 = VK_OEM_PERIOD;
constexpr auto _43 = VK_OEM_2;
#pragma endregion

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
	auto p = reinterpret_cast<PKBDLLHOOKSTRUCT>(lParam);
	bool tempFlag = false;
	if (wParam == WM_KEYDOWN)
	{
		if (IsKeyPressed(VK_CONTROL) && IsKeyPressed(VK_SHIFT) && IsKeyPressed('Q'))
		{
			if(keyboardHook != nullptr)
				UnhookWindowsHookEx(keyboardHook);
			PostQuitMessage(0);
		}
		else if (p->dwExtraInfo != 1 << 24 &&
			!IsKeyPressed(VK_CONTROL) &&
			!IsKeyPressed(VK_LWIN) &&
			!IsKeyPressed(VK_RWIN) &&
			!IsKeyPressed(VK_MENU) &&
			!IsKeyPressed(VK_TAB)) {
			tempFlag = true;
			switch (p->vkCode)
			{
			case _11:Kbe(0); break;
			case '1':Kbe(1); break;
			case '2':Kbe(2); break;
			case '3':Kbe(3); break;
			case '4':Kbe(4); break;
			case '5':Kbe(5); break;
			case '6':Kbe(6); break;
			case '7':Kbe(7); break;
			case '8':Kbe(8); break;
			case '9':Kbe(9); break;
			case '0':Kbe(10); break;
			case _12:Kbe(11); break;
			case _13:Kbe(12); break;

			case 'Q':Kbe(13); break;
			case 'W':Kbe(14); break;
			case 'E':Kbe(15); break;
			case 'T':Kbe(17); break;
			case 'Y':Kbe(18); break;
			case 'U':Kbe(19); break;
			case 'I':Kbe(20); break;
			case 'O':Kbe(21); break;
			case 'P':Kbe(22); break;
			case _21:Kbe(23); break;
			case _22:Kbe(24); break;
			case _23:Kbe(25); break;

			case 'A':Kbe(26); break;
			case 'S':Kbe(27); break;
			case 'D':Kbe(28); break;
			case 'F':Kbe(29); break;
			case 'G':Kbe(30); break;
			case 'H':Kbe(31); break;
			case 'J':Kbe(32); break;
			case 'K':Kbe(33); break;
			case 'L':Kbe(34); break;
			case _31:Kbe(35); break;
			case _32:Kbe(36); break;

			case 'Z':Kbe(37); break;
			case 'X':Kbe(38); break;
			case 'C':Kbe(39); break;
			case 'V':Kbe(40); break;
			case 'B':Kbe(41); break;
			case 'N':Kbe(42); break;
			case 'M':Kbe(43); break;
			case _41:Kbe(44); break;
			case _42:Kbe(45); break;
			case _43:Kbe(46); break;
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
	keyboardHook = SetWindowsHookExW(WH_KEYBOARD_LL, &KeyboardProc, hInstance, NULL);
	if (keyboardHook == nullptr)
		return 1;
	//进行事件循环
	MSG msg;
	while (GetMessageA(&msg, nullptr, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessageA(&msg);
	}
	return msg.wParam;
}