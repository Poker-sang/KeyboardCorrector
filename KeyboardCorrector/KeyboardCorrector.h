#pragma once
#include <vector>
#include <Windows.h>

namespace WindowImport
{
	using namespace System::Runtime::InteropServices;
#define DLL_IMPORT [DllImport("user32", CharSet = CharSet::Ansi)] extern
	DLL_IMPORT void keybd_event(BYTE bVk, BYTE bScan, DWORD dwFlags, ULONG_PTR dwExtraInfo);
	DLL_IMPORT SHORT GetKeyState(int nVirtKey);
	DLL_IMPORT LRESULT CallNextHookEx(HHOOK hhk, int nCode, WPARAM wParam, LPARAM lParam);
	DLL_IMPORT HHOOK SetWindowsHookExW(int idHook, HOOKPROC lpfn, HINSTANCE hmod, DWORD dwThreadId);
	DLL_IMPORT BOOL UnhookWindowsHookEx(HHOOK hhk);
}

/// <summary>
/// �ɱ༭�ļ�����
/// </summary>
constexpr auto KeysCount = 47;

#pragma region ĳЩ�����Ϸ��ŵ����������
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

/// <summary>
/// ���̹���
/// </summary>
static HHOOK KeyboardHook = nullptr;

/// <summary>
/// Qwerty���̣����0��
/// </summary>
BYTE QwertyKb[KeysCount] = {
	_11, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', _12, _13,
	'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', _21, _22, _23,
	'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', _31, _32,
	'Z', 'X', 'C', 'V', 'B', 'N', 'M', _41, _42, _43 };

/// <summary>
/// �����Ŀ˼��̣����1��
/// </summary>
BYTE DvorakKb[KeysCount] = {
	_11, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', _21, _22,
	_32, _41, _42, 'P', 'Y', 'F', 'G', 'C', 'R', 'L', _43, _13, _23,
	'A', 'O', 'E', 'U', 'I', 'D', 'H', 'T', 'N', 'S', _22,
	_21, 'Q', 'J', 'K', 'X', 'B', 'M', 'W', 'V', 'Z' };
std::vector<BYTE*> KeyboardLayoutList{ QwertyKb, DvorakKb };

/// <summary>
/// Ŀǰѡ��ļ������
/// </summary>
auto KeyboardLayoutIndex = 0;

/// <summary>
/// ĳ���Ƿ񱻰���
/// </summary>
///	<param name="nVirtualKey">���жϵļ�</param>
inline auto IsKeyPressed(const int nVirtualKey) { return (WindowImport::GetKeyState(nVirtualKey) & (1 << (sizeof(SHORT) * 8 - 1))) != 0; }

/// <summary>
/// ���ͼ����¼� 
/// </summary>
///	<param name="index">���͵ļ���Ӧ������������</param>
inline auto Kbe(const int index) { WindowImport::keybd_event(KeyboardLayoutList[KeyboardLayoutIndex][index], 0, 0x0000, 1 << 24); }

/// <summary>
/// ���̹��Ӵ������
/// </summary>
inline LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	const auto p = reinterpret_cast<PKBDLLHOOKSTRUCT>(lParam);
	auto handled = false;
	if (wParam == WM_KEYDOWN)
		if (p->dwExtraInfo != 1 << 24 &&
			!IsKeyPressed(VK_CONTROL) &&
			!IsKeyPressed(VK_LWIN) &&
			!IsKeyPressed(VK_RWIN) &&
			!IsKeyPressed(VK_MENU) &&
			!IsKeyPressed(VK_TAB))
			for (auto i = 0; i < KeysCount; ++i)
				if (p->vkCode == QwertyKb[i])
				{
					handled = true;
					Kbe(i);
				}
	if (handled)
		return 1;
	return WindowImport::CallNextHookEx(KeyboardHook, nCode, wParam, lParam);
}