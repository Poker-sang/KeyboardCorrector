#pragma once
namespace KeyboardCorrector 
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace Collections;
	using namespace Windows;
	using namespace Controls;
	using namespace System::Data;
	using namespace Drawing;

	/// <summary>
	/// MainWindow 摘要
	/// </summary>
	public ref class MainWindow sealed : public Window
	{
	public:
		MainWindow()
		{
			_keyBoardLayoutNames->Add(L"QWERTY键盘");
			_keyBoardLayoutNames->Add(L"德沃夏克键盘");

			InitializeComponent();
		}

		~MainWindow() {	}

	private:
		/// <summary>
		/// 开启挂钩
		/// </summary>
		void ApplyClicked(Object^ sender, RoutedEventArgs^ e)
		{
			static auto flag = false;
			static HHOOK hook = nullptr;
			flag = !flag;
			if (flag)
			{
				hook = WindowsImport::SetWindowsHookExW(WH_KEYBOARD_LL, &KeyboardProc, GetModuleHandle(nullptr), NULL);
				WindowState = Windows::WindowState::Minimized;
				_applyButton->Content = L"关闭";
			}
			else
			{
				_applyButton->Content = L"开启";
				if (hook != nullptr)
					WindowImport::UnhookWindowsHookEx(hook);
			}
		}
		/// <summary>
		/// 添加键盘布局
		/// </summary>
		void AddClicked(Object^ sender, RoutedEventArgs^ e)
		{
#undef new
			const auto newLayout = new BYTE[KeysCount]();
#define new gcnew
			for (auto i = 0; i < KeysCount; ++i)
				newLayout[i] = safe_cast<Int32>(_keys[i]->Tag);
			KeyboardLayoutList.push_back(newLayout);
			_keyBoardLayoutNames->Add(L"新键盘" + (_keyBoardLayoutNames->Count - 1));
			_comboBox->SelectedIndex = _keyBoardLayoutNames->Count - 1;

		}
		/// <summary>
		/// 删除键盘布局
		/// </summary>
		void DeleteClicked(Object^ sender, RoutedEventArgs^ e)
		{
			if (KeyboardLayoutIndex == 0)
				MessageBox::Show(L"无法删除" + _keyBoardLayoutNames[KeyboardLayoutIndex], L"提示", MessageBoxButton::OK, MessageBoxImage::Information);
			else if(MessageBoxResult::Yes == MessageBox::Show(L"是否删除" + _keyBoardLayoutNames[KeyboardLayoutIndex], L"警告", MessageBoxButton::YesNo, MessageBoxImage::Warning, MessageBoxResult::No))
			{
				KeyboardLayoutList.erase(KeyboardLayoutList.begin() + KeyboardLayoutIndex);
				_keyBoardLayoutNames->RemoveAt(KeyboardLayoutIndex);
			}
		}
		/// <summary>
		/// 上次被点击的按键
		/// </summary>
		Button^ _lastSelectedButton;
#pragma region 原来的按钮样式
		Windows::Media::Brush^ _originalBackground;
		Windows::Media::Brush^ _originalBorderBrush;
#pragma endregion
#pragma region 被选中的按钮样式
		Windows::Media::Brush^ _selectedBackground = new Windows::Media::SolidColorBrush(Windows::Media::Color::FromRgb(190, 230, 253));
		Windows::Media::Brush^ _selectedBorderBrush = new Windows::Media::SolidColorBrush(Windows::Media::Color::FromRgb(60, 127, 177));
#pragma endregion
		/// <summary>
		/// 按键两两交换
		/// </summary>
		void KeyClicked(Object^ sender, RoutedEventArgs^ e)
		{
			auto button = safe_cast<Button^>(sender);

			if (Equals(_lastSelectedButton, nullptr))
			{
				button->Background = _selectedBackground;
				button->BorderBrush = _selectedBorderBrush;
				_lastSelectedButton = button;
				return;
			}
			else if (!Equals(_lastSelectedButton, button))
			{
				auto temp = button->Content;
				button->Content = _lastSelectedButton->Content;
				_lastSelectedButton->Content = temp;
				auto temp2 = button->Tag;
				button->Tag = _lastSelectedButton->Tag;
				_lastSelectedButton->Tag = temp2;
			}
			_lastSelectedButton->Background = _originalBackground;
			_lastSelectedButton->BorderBrush = _originalBorderBrush;
			_lastSelectedButton = nullptr;			
		}

		/// <summary>
		/// 选择已有布局方案
		/// </summary>
		void SelectionChanged(Object^ sender, SelectionChangedEventArgs^ e)
		{
			if (safe_cast<ComboBox^>(sender)->SelectedIndex < 0)
			{
				safe_cast<ComboBox^>(sender)->SelectedIndex = 0;
				return;
			}
			KeyboardLayoutIndex = safe_cast<ComboBox^>(sender)->SelectedIndex;
			for (auto i = 0; i < KeysCount; ++i)
			{
				_keys[i]->Tag = static_cast<Int32>(KeyboardLayoutList[KeyboardLayoutIndex][i]);
				switch (KeyboardLayoutList[KeyboardLayoutIndex][i])
				{
				case _11:_keys[i]->Content = L"` ~";	break;
				case _12:_keys[i]->Content = L"- _";	break;
				case _13:_keys[i]->Content = L"= +";	break;
				case _21:_keys[i]->Content = L"[ {";	break;
				case _22:_keys[i]->Content = L"] }";	break;
				case _23:_keys[i]->Content = L"\\ |";	break;
				case _31:_keys[i]->Content = L"; :";	break;
				case _32:_keys[i]->Content = L"' \"";	break;
				case _41:_keys[i]->Content = L", <";	break;
				case _42:_keys[i]->Content = L". >";	break;
				case _43:_keys[i]->Content = L"/ ?";	break;
				default:_keys[i]->Content = static_cast<wchar_t>(KeyboardLayoutList[KeyboardLayoutIndex][i]);
				}
			}
		}

		/// <summary>
		/// 所有键盘的ViewModel
		/// </summary>
		ObjectModel::ObservableCollection<String^>^ _keyBoardLayoutNames = new ObjectModel::ObservableCollection<String^>();

#pragma region 控件
		DockPanel^	_root			= new DockPanel();

		DockPanel^	_dockPanel		= new DockPanel();
		Button^		_applyButton	= new Button();
		ComboBox^	_comboBox		= new ComboBox();
		Button^		_deleteButton	= new Button();
		Button^		_addButton		= new Button();

		StackPanel^	_stackPanel1	= new StackPanel();
		StackPanel^	_stackPanel2	= new StackPanel();
		StackPanel^	_stackPanel3	= new StackPanel();
		StackPanel^	_stackPanel4	= new StackPanel();

		array<Button^>^ _keys		= new array<Button^>(KeysCount);
		array<Button^>^ _otherKeys	= new array<Button^>(6);
#pragma endregion

		/// <summary>
		/// 加载窗口
		/// </summary>
		void InitializeComponent()
		{
			Width = 550;
			Height = 240;
			Title = L"KeyboardCorrector";
			ResizeMode = Windows::ResizeMode::CanMinimize;
			Content = _root;
			InitializeControls();
		}

		/// <summary>
		/// 加载控件
		/// </summary>
		void InitializeControls()
		{
			_root->Margin = Thickness(10);
			_root->Children->Add(_stackPanel4);
			_root->Children->Add(_stackPanel3);
			_root->Children->Add(_stackPanel2);
			_root->Children->Add(_stackPanel1);
			_root->Children->Add(_dockPanel);			
			{
				_dockPanel->Margin = Thickness(0, 0, 0, 10);
				_dockPanel->Height = 30;
				_dockPanel->Children->Add(_applyButton);
				_dockPanel->Children->Add(_comboBox);
				_dockPanel->Children->Add(_deleteButton);
				_dockPanel->Children->Add(_addButton);
				_dockPanel->Children->Add(new Shapes::Rectangle);
				{
					DockPanel::SetDock(_applyButton, Dock::Left);
					_applyButton->Width = 70;
					_applyButton->Content = L"开启";
					_applyButton->Click += new RoutedEventHandler(this, &MainWindow::ApplyClicked);
					_originalBackground = _applyButton->Background;
					_originalBorderBrush = _applyButton->BorderBrush;

					DockPanel::SetDock(_comboBox, Dock::Right);
					_comboBox->VerticalContentAlignment = Windows::VerticalAlignment::Center;
					_comboBox->HorizontalContentAlignment = Windows::HorizontalAlignment::Center;
					_comboBox->Width = 130;
					_comboBox->ItemsSource = _keyBoardLayoutNames;
					_comboBox->SelectedIndex = -1;
					_comboBox->SelectionChanged += new SelectionChangedEventHandler(this, &MainWindow::SelectionChanged);
					auto b = new Windows::Data::Binding();
					b->Source = _keyBoardLayoutNames;
					b->Mode = Windows::Data::BindingMode::OneWay;
					SetBinding(_comboBox->ItemsSourceProperty, b);

					DockPanel::SetDock(_deleteButton, Dock::Right);
					_deleteButton->Width = 70;
					_deleteButton->Content = L"删除此布局";
					_deleteButton->Click += new RoutedEventHandler(this, &MainWindow::DeleteClicked);
					_deleteButton->Margin = Thickness(10, 0, 10, 0);

					DockPanel::SetDock(_addButton, Dock::Right);
					_addButton->Width = 70;
					_addButton->Content = L"保存此布局";
					_addButton->Click += new RoutedEventHandler(this, &MainWindow::AddClicked);
				}
				constexpr auto size = 30;
				constexpr auto padding = 5;
				for (auto i = 0; i < KeysCount; ++i)
				{
					_keys[i] = new Button();
					_keys[i]->Height = size;
					_keys[i]->Width = size;
					_keys[i]->Margin = Thickness(padding, 0, 0, 0);
					_keys[i]->Click += new RoutedEventHandler(this, &MainWindow::KeyClicked);
				}
				_keys[0]->Margin = Thickness(0, 0, 0, 0);
				_keys[25]->Width = 1.5 * size;
				for (auto i = 0; i < 6; ++i)
				{
					_otherKeys[i] = new Button();
					_otherKeys[i]->IsEnabled = false;
					_otherKeys[i]->Height = size;
				}
				_otherKeys[0]->Margin = Thickness(padding, 0, 0, 0);
				_otherKeys[0]->Width = 2 * size;
				_otherKeys[0]->Content = L"←";
				_otherKeys[1]->Width = 1.5 * size;
				_otherKeys[1]->Content = L"Tab";
				_otherKeys[2]->Width = 2 * size;
				_otherKeys[2]->Content = L"CapsLock";
				_otherKeys[3]->Margin = Thickness(padding, 0, 0, 0);
				_otherKeys[3]->Width = 2 * size + padding;
				_otherKeys[3]->Content = L"Enter";
				_otherKeys[4]->Width = 2.5 * size;
				_otherKeys[4]->Content = L"Shift";
				_otherKeys[5]->Margin = Thickness(padding, 0, 0, 0);
				_otherKeys[5]->Width = 2.5 * size + 2 * padding;
				_otherKeys[5]->Content = L"Shift";

				DockPanel::SetDock(_stackPanel1, Dock::Bottom);
				_stackPanel1->Orientation = Orientation::Horizontal;
				_stackPanel1->Margin= Thickness(0, 0, 0, padding);
				for (auto i = 0; i < 13; ++i)
					_stackPanel1->Children->Add(_keys[i]);
				_stackPanel1->Children->Add(_otherKeys[0]);

				DockPanel::SetDock(_stackPanel2, Dock::Bottom);
				_stackPanel2->Orientation = Orientation::Horizontal;
				_stackPanel2->Margin = Thickness(0, 0, 0, padding);
				_stackPanel2->Children->Add(_otherKeys[1]);
				for (auto i = 0; i < 13; ++i)
					_stackPanel2->Children->Add(_keys[i + 13]);

				DockPanel::SetDock(_stackPanel3, Dock::Bottom);
				_stackPanel3->Orientation = Orientation::Horizontal;
				_stackPanel3->Margin = Thickness(0, 0, 0, padding);
				_stackPanel3->Children->Add(_otherKeys[2]);
				for (auto i = 0; i < 11; ++i)
					_stackPanel3->Children->Add(_keys[i + 26]);
				_stackPanel3->Children->Add(_otherKeys[3]);

				DockPanel::SetDock(_stackPanel4, Dock::Bottom);
				_stackPanel4->Orientation = Orientation::Horizontal;
				_stackPanel4->Children->Add(_otherKeys[4]);
				for (auto i = 0; i < 10; ++i)
					_stackPanel4->Children->Add(_keys[i + 37]);
				_stackPanel4->Children->Add(_otherKeys[5]);
			}
			_comboBox->SelectedIndex = 0;
		}
	};
}
