#pragma once
#include "ary.h"
#include <exception>
#include <stdexcept>

template <typename T, size_t N>
class UnsortedArray : public Array<T, N> {
    private:    
        size_t _size = 0;
    public:

        /*
         * Inserts new value into Array.
         */
        void insert(const T& new_value);

        /*
         * Removes value at index and shits all elements to the left.
         */
        void remove(size_t pos);

        /*
         * Attempts to find value in the array.
         * TODO Implement Method
         */
        T& find();

        /*
         * Returns total of elements in the array.
         */
        size_t size() const;
};

template<typename T, size_t N>
void UnsortedArray<T, N>::insert(const T& new_value) {
    if (_size >= this->max_size())
        throw std::runtime_error("Array is full.");
    else {
        this->_data[_size] = new_value;
        ++_size;
    }
}

template<typename T, size_t N>
void UnsortedArray<T, N>::remove(size_t pos) {
    if(pos >= _size)
        throw std::out_of_range("Index out of bounds.");
       
    for(size_t i = pos; i < _size - 1; ++i)
        this->_data[pos] = this->_data[i + 1];

    // Clearing the last element.
    this->_data[_size - 1] = T();

    --_size;
}

template<typename T, size_t N>
size_t UnsortedArray<T, N>::size() const {
    return _size;
}
