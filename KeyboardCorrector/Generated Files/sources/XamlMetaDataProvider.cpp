#include "pch.h"
#include "XamlMetaDataProvider.h"
#include "XamlMetaDataProvider.g.cpp"

// Note: Remove this static_assert after copying these generated source files to your project.
// This assertion exists to avoid compiling these generated source files directly.
static_assert(false, "Do not compile generated C++/WinRT source files directly");

namespace winrt::KeyboardCorrector::implementation
{
    winrt::Microsoft::UI::Xaml::Markup::IXamlType XamlMetaDataProvider::GetXamlType(winrt::Windows::UI::Xaml::Interop::TypeName const& type)
    {
        throw hresult_not_implemented();
    }
    winrt::Microsoft::UI::Xaml::Markup::IXamlType XamlMetaDataProvider::GetXamlType(hstring const& fullName)
    {
        throw hresult_not_implemented();
    }
    com_array<winrt::Microsoft::UI::Xaml::Markup::XmlnsDefinition> XamlMetaDataProvider::GetXmlnsDefinitions()
    {
        throw hresult_not_implemented();
    }
}
