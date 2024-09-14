#pragma once

#include <sstream>
#include <stdexcept>

template <typename T, size_t N>
class Array {
    protected:
        T _data[N];

    public:

        /*
         * Constructor for Array.
         * TODO Implement list-initialization.
         */
//       Array();

        /*
         * Destructor for Array.
         */
//      ~Array();

        /*
         * Return element at index. Is Constant.
         */
        const T& operator [](size_t pos) const;

        /*
         * Access element at index.
         */

        T& operator [](size_t pos) ;

        /*
         *  Returns count of elements in the array.
         */
        size_t size() const;

        /*
         *  Returns Max size of the array.
         */
        size_t max_size() const;

        /*
         * Getting element at position with bounds checking.
         */
        const T& at(size_t pos) const;

        /*
         * Setting element at position with bonuds checking.
         */
        T& at(size_t pos) ;

        /*
         * Returns string of elements contained within array.
         */
        std::string to_string() const;
};

// template <typename T, size_t N>
// Array<T,N>::Array() {}

// template <typename T, size_t N>
// Array<T,N>::~Array() = default;

template <typename T, size_t N>
const T & Array<T,N>::operator[](size_t pos) const {
    return _data[pos];
}

template <typename T, size_t N>
T & Array<T,N>::operator[](size_t pos) {
    return _data[pos];
}

template <typename T, size_t N>
size_t Array<T, N>::size() const { return N ; }

template <typename T, size_t N>
size_t Array<T, N>::max_size() const { return N ; }

template <typename T, size_t N>
const T& Array<T, N>::at(size_t pos) const {
   if ( pos >= N )
       throw std::out_of_range("Parameter was out of bounds.");
    return _data[pos];
}

template <typename T, size_t N>
T& Array<T, N>::at(size_t pos) {
    if ( pos < 0 || pos >= N)
        throw std::out_of_range("Parameter was out of bounds.");
    return _data[pos];
}

template <typename T, size_t N>
std::string Array<T, N>::to_string() const {
   std::ostringstream oss;

   for(int i = 0; i < N; i++) {
       oss << _data[i];
       if (i < N - 1)
           oss << ',';
   }

   return oss.str();
}
