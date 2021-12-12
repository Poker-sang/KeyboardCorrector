// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.210806.1

#pragma once
#ifndef WINRT_Microsoft_UI_Xaml_Interop_2_H
#define WINRT_Microsoft_UI_Xaml_Interop_2_H
#include "winrt/impl/Microsoft.UI.Xaml.Interop.1.h"
WINRT_EXPORT namespace winrt::Microsoft::UI::Xaml::Interop
{
    struct BindableVectorChangedEventHandler : Windows::Foundation::IUnknown
    {
        BindableVectorChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
        BindableVectorChangedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : Windows::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> BindableVectorChangedEventHandler(L lambda);
        template <typename F> BindableVectorChangedEventHandler(F* function);
        template <typename O, typename M> BindableVectorChangedEventHandler(O* object, M method);
        template <typename O, typename M> BindableVectorChangedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> BindableVectorChangedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(winrt::Microsoft::UI::Xaml::Interop::IBindableObservableVector const& vector, winrt::Windows::Foundation::IInspectable const& e) const;
    };
    struct NotifyCollectionChangedEventHandler : Windows::Foundation::IUnknown
    {
        NotifyCollectionChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
        NotifyCollectionChangedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : Windows::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> NotifyCollectionChangedEventHandler(L lambda);
        template <typename F> NotifyCollectionChangedEventHandler(F* function);
        template <typename O, typename M> NotifyCollectionChangedEventHandler(O* object, M method);
        template <typename O, typename M> NotifyCollectionChangedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> NotifyCollectionChangedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Interop::NotifyCollectionChangedEventArgs const& e) const;
    };
    struct __declspec(empty_bases) NotifyCollectionChangedEventArgs : winrt::Microsoft::UI::Xaml::Interop::INotifyCollectionChangedEventArgs
    {
        NotifyCollectionChangedEventArgs(std::nullptr_t) noexcept {}
        NotifyCollectionChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : winrt::Microsoft::UI::Xaml::Interop::INotifyCollectionChangedEventArgs(ptr, take_ownership_from_abi) {}
        NotifyCollectionChangedEventArgs(winrt::Microsoft::UI::Xaml::Interop::NotifyCollectionChangedAction const& action, winrt::Microsoft::UI::Xaml::Interop::IBindableVector const& newItems, winrt::Microsoft::UI::Xaml::Interop::IBindableVector const& oldItems, int32_t newIndex, int32_t oldIndex);
    };
}
#endif
