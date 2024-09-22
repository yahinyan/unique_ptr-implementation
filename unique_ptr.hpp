#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

#include <iostream>

template <typename T>
class unique_ptr {
    public:
        unique_ptr(T* ptr = nullptr);
        unique_ptr(const unique_ptr<T>& other) = delete;
        unique_ptr(unique_ptr<T>&& other) noexcept;
        unique_ptr<T>& operator=(unique_ptr<T>&& other) noexcept; 
        T* release() noexcept;
        void reset(T* ptr = nullptr) noexcept;
        void swap(unique_ptr<T>& other ) noexcept;
        T* get() const noexcept;
        T* operator->() const noexcept;
        T& operator*() const noexcept;
        ~unique_ptr();
    private:
        T* m_ptr;
};

#include "unique_ptr.cpp"
#endif // UNIQUE_PTR_H