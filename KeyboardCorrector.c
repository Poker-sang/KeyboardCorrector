#include <Windows.h> 

// 可编辑的键总数
#define KeysCount 47

// 某些键盘上符号的虚拟键代码
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

// 键盘钩子
static HHOOK keyboardHook = NULL;


// Qwerty键盘（序号0）
BYTE QwertyKb[KeysCount] = {
	_11, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', _12, _13,
	'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', _21, _22, _23,
	'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', _31, _32,
	'Z', 'X', 'C', 'V', 'B', 'N', 'M', _41, _42, _43 };

// 德沃夏克键盘（序号1）
BYTE DvorakKb[KeysCount] = {
	_11, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', _21, _22,
	_32, _41, _42, 'P', 'Y', 'F', 'G', 'C', 'R', 'L', _43, _13, _23,
	'A', 'O', 'E', 'U', 'I', 'D', 'H', 'T', 'N', 'S', _22,
	_21, 'Q', 'J', 'K', 'X', 'B', 'M', 'W', 'V', 'Z' };

// 键盘列表
BYTE* KeyboardLayoutList[2] = { QwertyKb, DvorakKb };

// 目前选择的键盘序号
int KeyboardLayoutIndex = 1;

// 某键是否被按下
// nVirtualKey: int 需判断的键
// return: bool 发送的键对应在数组里的序号
#define IsKeyPressed(nVirtualKey) ((GetKeyState(nVirtualKey) & (1 << (sizeof(SHORT) * 8 - 1))) != 0)

// 发送键盘事件
// index: int
#define Kbe(index) keybd_event(KeyboardLayoutList[KeyboardLayoutIndex][index], 0, 0x0000, 1 << 24)

// 键盘钩子处理程序
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	const PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)lParam;
	bool handled = false;
	if (wParam == WM_KEYDOWN)
		if (p->dwExtraInfo != 1 << 24 &&
			!IsKeyPressed(VK_CONTROL) &&
			!IsKeyPressed(VK_LWIN) &&
			!IsKeyPressed(VK_RWIN) &&
			!IsKeyPressed(VK_MENU) &&
			!IsKeyPressed(VK_TAB))
			for (int i = 0; i < KeysCount; ++i)
				if (p->vkCode == QwertyKb[i])
				{
					handled = true;
					Kbe(i);
				}
	if (handled)
		return 1;
	return CallNextHookEx(keyboardHook, nCode, wParam, lParam);
}

// 主程序
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPreINstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	//安装键盘钩子
	installDvorakKB();
	keyboardHook = SetWindowsHookExW(WH_KEYBOARD_LL, &KeyboardProc, hInstance, NULL);
	if (keyboardHook == NULL)
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