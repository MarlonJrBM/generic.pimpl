#pragma once

#include <memory>

template <typename T>
class pimpl {
  public:
    pimpl();

    template <typename... Args>
    pimpl(Args&&... args);

    T* operator->();
    T& operator*();

  private:
    std::unique_ptr<T> _impl;
};

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