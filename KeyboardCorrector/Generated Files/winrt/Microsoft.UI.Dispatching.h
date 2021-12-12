// WARNING: Please don't edit this file. It was generated by C++/WinRT v2.0.210806.1

#pragma once
#ifndef WINRT_Microsoft_UI_Dispatching_H
#define WINRT_Microsoft_UI_Dispatching_H
#include "winrt/base.h"
static_assert(winrt::check_version(CPPWINRT_VERSION, "2.0.210806.1"), "Mismatched C++/WinRT headers.");
#define CPPWINRT_VERSION "2.0.210806.1"
#include "winrt/Microsoft.UI.h"
#include "winrt/impl/Windows.Foundation.2.h"
#include "winrt/impl/Microsoft.UI.Dispatching.2.h"
namespace winrt::impl
{
    template <typename D> WINRT_IMPL_AUTO(winrt::Microsoft::UI::Dispatching::DispatcherQueueTimer) consume_Microsoft_UI_Dispatching_IDispatcherQueue<D>::CreateTimer() const
    {
        void* result{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Microsoft::UI::Dispatching::IDispatcherQueue)->CreateTimer(&result));
        return winrt::Microsoft::UI::Dispatching::DispatcherQueueTimer{ result, take_ownership_from_abi };
    }
    template <typename D> WINRT_IMPL_AUTO(bool) consume_Microsoft_UI_Dispatching_IDispatcherQueue<D>::TryEnqueue(winrt::Microsoft::UI::Dispatching::DispatcherQueueHandler const& callback) const
    {
        bool result{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Microsoft::UI::Dispatching::IDispatcherQueue)->TryEnqueue(*(void**)(&callback), &result));
        return result;
    }
    template <typename D> WINRT_IMPL_AUTO(bool) consume_Microsoft_UI_Dispatching_IDispatcherQueue<D>::TryEnqueue(winrt::Microsoft::UI::Dispatching::DispatcherQueuePriority const& priority, winrt::Microsoft::UI::Dispatching::DispatcherQueueHandler const& callback) const
    {
        bool result{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Microsoft::UI::Dispatching::IDispatcherQueue)->TryEnqueueWithPriority(static_cast<int32_t>(priority), *(void**)(&callback), &result));
        return result;
    }
    template <typename D> WINRT_IMPL_AUTO(winrt::event_token) consume_Microsoft_UI_Dispatching_IDispatcherQueue<D>::ShutdownStarting(winrt::Windows::Foundation::TypedEventHandler<winrt::Microsoft::UI::Dispatching::DispatcherQueue, winrt::Microsoft::UI::Dispatching::DispatcherQueueShutdownStartingEventArgs> const& handler) const
    {
        winrt::event_token token{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Microsoft::UI::Dispatching::IDispatcherQueue)->add_ShutdownStarting(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Microsoft_UI_Dispatching_IDispatcherQueue<D>::ShutdownStarting_revoker consume_Microsoft_UI_Dispatching_IDispatcherQueue<D>::ShutdownStarting(auto_revoke_t, winrt::Windows::Foundation::TypedEventHandler<winrt::Microsoft::UI::Dispatching::DispatcherQueue, winrt::Microsoft::UI::Dispatching::DispatcherQueueShutdownStartingEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, ShutdownStarting_revoker>(this, ShutdownStarting(handler));
    }
    template <typename D> WINRT_IMPL_AUTO(void) consume_Microsoft_UI_Dispatching_IDispatcherQueue<D>::ShutdownStarting(winrt::event_token const& token) const noexcept
    {
        WINRT_VERIFY_(0, WINRT_IMPL_SHIM(winrt::Microsoft::UI::Dispatching::IDispatcherQueue)->remove_ShutdownStarting(impl::bind_in(token)));
    }
    template <typename D> WINRT_IMPL_AUTO(winrt::event_token) consume_Microsoft_UI_Dispatching_IDispatcherQueue<D>::ShutdownCompleted(winrt::Windows::Foundation::TypedEventHandler<winrt::Microsoft::UI::Dispatching::DispatcherQueue, winrt::Windows::Foundation::IInspectable> const& handler) const
    {
        winrt::event_token token{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Microsoft::UI::Dispatching::IDispatcherQueue)->add_ShutdownCompleted(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Microsoft_UI_Dispatching_IDispatcherQueue<D>::ShutdownCompleted_revoker consume_Microsoft_UI_Dispatching_IDispatcherQueue<D>::ShutdownCompleted(auto_revoke_t, winrt::Windows::Foundation::TypedEventHandler<winrt::Microsoft::UI::Dispatching::DispatcherQueue, winrt::Windows::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, ShutdownCompleted_revoker>(this, ShutdownCompleted(handler));
    }
    template <typename D> WINRT_IMPL_AUTO(void) consume_Microsoft_UI_Dispatching_IDispatcherQueue<D>::ShutdownCompleted(winrt::event_token const& token) const noexcept
    {
        WINRT_VERIFY_(0, WINRT_IMPL_SHIM(winrt::Microsoft::UI::Dispatching::IDispatcherQueue)->remove_ShutdownCompleted(impl::bind_in(token)));
    }
    template <typename D> WINRT_IMPL_AUTO(bool) consume_Microsoft_UI_Dispatching_IDispatcherQueue2<D>::HasThreadAccess() const
    {
        bool value{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Microsoft::UI::Dispatching::IDispatcherQueue2)->get_HasThreadAccess(&value));
        return value;
    }
    template <typename D> WINRT_IMPL_AUTO(winrt::Microsoft::UI::Dispatching::DispatcherQueue) consume_Microsoft_UI_Dispatching_IDispatcherQueueController<D>::DispatcherQueue() const
    {
        void* value{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Microsoft::UI::Dispatching::IDispatcherQueueController)->get_DispatcherQueue(&value));
        return winrt::Microsoft::UI::Dispatching::DispatcherQueue{ value, take_ownership_from_abi };
    }
    template <typename D> WINRT_IMPL_AUTO(winrt::Windows::Foundation::IAsyncAction) consume_Microsoft_UI_Dispatching_IDispatcherQueueController<D>::ShutdownQueueAsync() const
    {
        void* operation{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Microsoft::UI::Dispatching::IDispatcherQueueController)->ShutdownQueueAsync(&operation));
        return winrt::Windows::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> WINRT_IMPL_AUTO(winrt::Microsoft::UI::Dispatching::DispatcherQueueController) consume_Microsoft_UI_Dispatching_IDispatcherQueueControllerStatics<D>::CreateOnDedicatedThread() const
    {
        void* result{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Microsoft::UI::Dispatching::IDispatcherQueueControllerStatics)->CreateOnDedicatedThread(&result));
        return winrt::Microsoft::UI::Dispatching::DispatcherQueueController{ result, take_ownership_from_abi };
    }
    template <typename D> WINRT_IMPL_AUTO(winrt::Microsoft::UI::Dispatching::DispatcherQueueController) consume_Microsoft_UI_Dispatching_IDispatcherQueueControllerStatics<D>::CreateOnCurrentThread() const
    {
        void* result{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Microsoft::UI::Dispatching::IDispatcherQueueControllerStatics)->CreateOnCurrentThread(&result));
        return winrt::Microsoft::UI::Dispatching::DispatcherQueueController{ result, take_ownership_from_abi };
    }
    template <typename D> WINRT_IMPL_AUTO(winrt::Windows::Foundation::Deferral) consume_Microsoft_UI_Dispatching_IDispatcherQueueShutdownStartingEventArgs<D>::GetDeferral() const
    {
        void* result{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Microsoft::UI::Dispatching::IDispatcherQueueShutdownStartingEventArgs)->GetDeferral(&result));
        return winrt::Windows::Foundation::Deferral{ result, take_ownership_from_abi };
    }
    template <typename D> WINRT_IMPL_AUTO(winrt::Microsoft::UI::Dispatching::DispatcherQueue) consume_Microsoft_UI_Dispatching_IDispatcherQueueStatics<D>::GetForCurrentThread() const
    {
        void* result{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Microsoft::UI::Dispatching::IDispatcherQueueStatics)->GetForCurrentThread(&result));
        return winrt::Microsoft::UI::Dispatching::DispatcherQueue{ result, take_ownership_from_abi };
    }
    template <typename D> WINRT_IMPL_AUTO(winrt::Windows::Foundation::TimeSpan) consume_Microsoft_UI_Dispatching_IDispatcherQueueTimer<D>::Interval() const
    {
        winrt::Windows::Foundation::TimeSpan value{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Microsoft::UI::Dispatching::IDispatcherQueueTimer)->get_Interval(put_abi(value)));
        return value;
    }
    template <typename D> WINRT_IMPL_AUTO(void) consume_Microsoft_UI_Dispatching_IDispatcherQueueTimer<D>::Interval(winrt::Windows::Foundation::TimeSpan const& value) const
    {
        check_hresult(WINRT_IMPL_SHIM(winrt::Microsoft::UI::Dispatching::IDispatcherQueueTimer)->put_Interval(impl::bind_in(value)));
    }
    template <typename D> WINRT_IMPL_AUTO(bool) consume_Microsoft_UI_Dispatching_IDispatcherQueueTimer<D>::IsRunning() const
    {
        bool value{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Microsoft::UI::Dispatching::IDispatcherQueueTimer)->get_IsRunning(&value));
        return value;
    }
    template <typename D> WINRT_IMPL_AUTO(bool) consume_Microsoft_UI_Dispatching_IDispatcherQueueTimer<D>::IsRepeating() const
    {
        bool value{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Microsoft::UI::Dispatching::IDispatcherQueueTimer)->get_IsRepeating(&value));
        return value;
    }
    template <typename D> WINRT_IMPL_AUTO(void) consume_Microsoft_UI_Dispatching_IDispatcherQueueTimer<D>::IsRepeating(bool value) const
    {
        check_hresult(WINRT_IMPL_SHIM(winrt::Microsoft::UI::Dispatching::IDispatcherQueueTimer)->put_IsRepeating(value));
    }
    template <typename D> WINRT_IMPL_AUTO(void) consume_Microsoft_UI_Dispatching_IDispatcherQueueTimer<D>::Start() const
    {
        check_hresult(WINRT_IMPL_SHIM(winrt::Microsoft::UI::Dispatching::IDispatcherQueueTimer)->Start());
    }
    template <typename D> WINRT_IMPL_AUTO(void) consume_Microsoft_UI_Dispatching_IDispatcherQueueTimer<D>::Stop() const
    {
        check_hresult(WINRT_IMPL_SHIM(winrt::Microsoft::UI::Dispatching::IDispatcherQueueTimer)->Stop());
    }
    template <typename D> WINRT_IMPL_AUTO(winrt::event_token) consume_Microsoft_UI_Dispatching_IDispatcherQueueTimer<D>::Tick(winrt::Windows::Foundation::TypedEventHandler<winrt::Microsoft::UI::Dispatching::DispatcherQueueTimer, winrt::Windows::Foundation::IInspectable> const& handler) const
    {
        winrt::event_token token{};
        check_hresult(WINRT_IMPL_SHIM(winrt::Microsoft::UI::Dispatching::IDispatcherQueueTimer)->add_Tick(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Microsoft_UI_Dispatching_IDispatcherQueueTimer<D>::Tick_revoker consume_Microsoft_UI_Dispatching_IDispatcherQueueTimer<D>::Tick(auto_revoke_t, winrt::Windows::Foundation::TypedEventHandler<winrt::Microsoft::UI::Dispatching::DispatcherQueueTimer, winrt::Windows::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, Tick_revoker>(this, Tick(handler));
    }
    template <typename D> WINRT_IMPL_AUTO(void) consume_Microsoft_UI_Dispatching_IDispatcherQueueTimer<D>::Tick(winrt::event_token const& token) const noexcept
    {
        WINRT_VERIFY_(0, WINRT_IMPL_SHIM(winrt::Microsoft::UI::Dispatching::IDispatcherQueueTimer)->remove_Tick(impl::bind_in(token)));
    }
    template <typename H> struct delegate<winrt::Microsoft::UI::Dispatching::DispatcherQueueHandler, H> final : implements_delegate<winrt::Microsoft::UI::Dispatching::DispatcherQueueHandler, H>
    {
        delegate(H&& handler) : implements_delegate<winrt::Microsoft::UI::Dispatching::DispatcherQueueHandler, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke() noexcept final try
        {
            (*this)();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef WINRT_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, winrt::Microsoft::UI::Dispatching::IDispatcherQueue> : produce_base<D, winrt::Microsoft::UI::Dispatching::IDispatcherQueue>
    {
        int32_t __stdcall CreateTimer(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<winrt::Microsoft::UI::Dispatching::DispatcherQueueTimer>(this->shim().CreateTimer());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryEnqueue(void* callback, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().TryEnqueue(*reinterpret_cast<winrt::Microsoft::UI::Dispatching::DispatcherQueueHandler const*>(&callback)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryEnqueueWithPriority(int32_t priority, void* callback, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().TryEnqueue(*reinterpret_cast<winrt::Microsoft::UI::Dispatching::DispatcherQueuePriority const*>(&priority), *reinterpret_cast<winrt::Microsoft::UI::Dispatching::DispatcherQueueHandler const*>(&callback)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_ShutdownStarting(void* handler, winrt::event_token* token) noexcept final try
        {
            zero_abi<winrt::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<winrt::event_token>(this->shim().ShutdownStarting(*reinterpret_cast<winrt::Windows::Foundation::TypedEventHandler<winrt::Microsoft::UI::Dispatching::DispatcherQueue, winrt::Microsoft::UI::Dispatching::DispatcherQueueShutdownStartingEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ShutdownStarting(winrt::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShutdownStarting(*reinterpret_cast<winrt::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_ShutdownCompleted(void* handler, winrt::event_token* token) noexcept final try
        {
            zero_abi<winrt::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<winrt::event_token>(this->shim().ShutdownCompleted(*reinterpret_cast<winrt::Windows::Foundation::TypedEventHandler<winrt::Microsoft::UI::Dispatching::DispatcherQueue, winrt::Windows::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ShutdownCompleted(winrt::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShutdownCompleted(*reinterpret_cast<winrt::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef WINRT_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, winrt::Microsoft::UI::Dispatching::IDispatcherQueue2> : produce_base<D, winrt::Microsoft::UI::Dispatching::IDispatcherQueue2>
    {
        int32_t __stdcall get_HasThreadAccess(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().HasThreadAccess());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef WINRT_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, winrt::Microsoft::UI::Dispatching::IDispatcherQueueController> : produce_base<D, winrt::Microsoft::UI::Dispatching::IDispatcherQueueController>
    {
        int32_t __stdcall get_DispatcherQueue(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<winrt::Microsoft::UI::Dispatching::DispatcherQueue>(this->shim().DispatcherQueue());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShutdownQueueAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<winrt::Windows::Foundation::IAsyncAction>(this->shim().ShutdownQueueAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef WINRT_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, winrt::Microsoft::UI::Dispatching::IDispatcherQueueControllerStatics> : produce_base<D, winrt::Microsoft::UI::Dispatching::IDispatcherQueueControllerStatics>
    {
        int32_t __stdcall CreateOnDedicatedThread(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<winrt::Microsoft::UI::Dispatching::DispatcherQueueController>(this->shim().CreateOnDedicatedThread());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateOnCurrentThread(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<winrt::Microsoft::UI::Dispatching::DispatcherQueueController>(this->shim().CreateOnCurrentThread());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef WINRT_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, winrt::Microsoft::UI::Dispatching::IDispatcherQueueShutdownStartingEventArgs> : produce_base<D, winrt::Microsoft::UI::Dispatching::IDispatcherQueueShutdownStartingEventArgs>
    {
        int32_t __stdcall GetDeferral(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<winrt::Windows::Foundation::Deferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef WINRT_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, winrt::Microsoft::UI::Dispatching::IDispatcherQueueStatics> : produce_base<D, winrt::Microsoft::UI::Dispatching::IDispatcherQueueStatics>
    {
        int32_t __stdcall GetForCurrentThread(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<winrt::Microsoft::UI::Dispatching::DispatcherQueue>(this->shim().GetForCurrentThread());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef WINRT_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, winrt::Microsoft::UI::Dispatching::IDispatcherQueueTimer> : produce_base<D, winrt::Microsoft::UI::Dispatching::IDispatcherQueueTimer>
    {
        int32_t __stdcall get_Interval(int64_t* value) noexcept final try
        {
            zero_abi<winrt::Windows::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<winrt::Windows::Foundation::TimeSpan>(this->shim().Interval());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Interval(int64_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Interval(*reinterpret_cast<winrt::Windows::Foundation::TimeSpan const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsRunning(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsRunning());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsRepeating(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsRepeating());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsRepeating(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsRepeating(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Start() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Start();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Stop() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stop();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_Tick(void* handler, winrt::event_token* token) noexcept final try
        {
            zero_abi<winrt::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<winrt::event_token>(this->shim().Tick(*reinterpret_cast<winrt::Windows::Foundation::TypedEventHandler<winrt::Microsoft::UI::Dispatching::DispatcherQueueTimer, winrt::Windows::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Tick(winrt::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Tick(*reinterpret_cast<winrt::event_token const*>(&token));
            return 0;
        }
    };
#endif
}
WINRT_EXPORT namespace winrt::Microsoft::UI::Dispatching
{
    inline auto DispatcherQueue::GetForCurrentThread()
    {
        return impl::call_factory_cast<winrt::Microsoft::UI::Dispatching::DispatcherQueue(*)(IDispatcherQueueStatics const&), DispatcherQueue, IDispatcherQueueStatics>([](IDispatcherQueueStatics const& f) { return f.GetForCurrentThread(); });
    }
    inline auto DispatcherQueueController::CreateOnDedicatedThread()
    {
        return impl::call_factory_cast<winrt::Microsoft::UI::Dispatching::DispatcherQueueController(*)(IDispatcherQueueControllerStatics const&), DispatcherQueueController, IDispatcherQueueControllerStatics>([](IDispatcherQueueControllerStatics const& f) { return f.CreateOnDedicatedThread(); });
    }
    inline auto DispatcherQueueController::CreateOnCurrentThread()
    {
        return impl::call_factory_cast<winrt::Microsoft::UI::Dispatching::DispatcherQueueController(*)(IDispatcherQueueControllerStatics const&), DispatcherQueueController, IDispatcherQueueControllerStatics>([](IDispatcherQueueControllerStatics const& f) { return f.CreateOnCurrentThread(); });
    }
    template <typename L> DispatcherQueueHandler::DispatcherQueueHandler(L handler) :
        DispatcherQueueHandler(impl::make_delegate<DispatcherQueueHandler>(std::forward<L>(handler)))
    {
    }
    template <typename F> DispatcherQueueHandler::DispatcherQueueHandler(F* handler) :
        DispatcherQueueHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename O, typename M> DispatcherQueueHandler::DispatcherQueueHandler(O* object, M method) :
        DispatcherQueueHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename O, typename M> DispatcherQueueHandler::DispatcherQueueHandler(com_ptr<O>&& object, M method) :
        DispatcherQueueHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename O, typename M> DispatcherQueueHandler::DispatcherQueueHandler(weak_ref<O>&& object, M method) :
        DispatcherQueueHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    inline auto DispatcherQueueHandler::operator()() const
    {
        check_hresult((*(impl::abi_t<DispatcherQueueHandler>**)this)->Invoke());
    }
}
namespace std
{
#ifndef WINRT_LEAN_AND_MEAN
    template<> struct hash<winrt::Microsoft::UI::Dispatching::IDispatcherQueue> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Microsoft::UI::Dispatching::IDispatcherQueue2> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Microsoft::UI::Dispatching::IDispatcherQueueController> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Microsoft::UI::Dispatching::IDispatcherQueueControllerStatics> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Microsoft::UI::Dispatching::IDispatcherQueueShutdownStartingEventArgs> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Microsoft::UI::Dispatching::IDispatcherQueueStatics> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Microsoft::UI::Dispatching::IDispatcherQueueTimer> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Microsoft::UI::Dispatching::DispatcherQueue> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Microsoft::UI::Dispatching::DispatcherQueueController> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Microsoft::UI::Dispatching::DispatcherQueueShutdownStartingEventArgs> : winrt::impl::hash_base {};
    template<> struct hash<winrt::Microsoft::UI::Dispatching::DispatcherQueueTimer> : winrt::impl::hash_base {};
#endif
}
#endif
