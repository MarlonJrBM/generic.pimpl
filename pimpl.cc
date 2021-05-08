#include "pimpl.hh"

template <typename T>
pimpl<T>::pimpl() : _impl(std::make_unique<T>()) {}

template <typename T>
template <typename... Args>
pimpl<T>::pimpl(Args&&... args) : _impl(std::make_unique<T>(std::forward<Args>(args)...)) {}

template <typename T>
T* pimpl<T>::operator->() {
    return _impl.get();
}

template <typename T>
T& pimpl<T>::operator*() {
    return *_impl.get();
}