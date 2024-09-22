#include "unique_ptr.hpp"

template <typename T>
unique_ptr<T>::unique_ptr(T* ptr)
    : m_ptr{ptr}
{}

template <typename T>
unique_ptr<T>::unique_ptr(unique_ptr<T>&& other) noexcept 
    : m_ptr{std::exchange(other.m_ptr, nullptr)}
{}

template <typename T>
unique_ptr<T>& unique_ptr<T>::operator=(unique_ptr<T>&& other) noexcept {
    if(this != &other) {
        delete m_ptr;
        m_ptr = std::exchange(other.m_ptr, nullptr);
    }
    return *this;
}

template <typename T>
T* unique_ptr<T>::release() noexcept {
    T* temp = m_ptr;
    m_ptr = nullptr;
    return temp;
}

template <typename T>
void unique_ptr<T>::reset(T *ptr) noexcept {
    delete m_ptr;
    m_ptr = nullptr;
}

template <typename T>
void unique_ptr<T>::swap(unique_ptr<T>& other ) noexcept {
    std::swap(m_ptr, other.m_ptr);
}

template <typename T>
T* unique_ptr<T>::get() const noexcept 
{
    return m_ptr;
}

template <typename T>
T* unique_ptr<T>::operator->() const noexcept {
    return m_ptr;
}

template <typename T>
T& unique_ptr<T>::operator*() const noexcept {
    return *m_ptr;
}

template <typename T>
unique_ptr<T>::~unique_ptr() {
    delete m_ptr;
}