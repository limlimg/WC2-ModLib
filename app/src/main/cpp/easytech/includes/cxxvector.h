#ifndef EASYMOD_CXXVECTOR_H
#define EASYMOD_CXXVECTOR_H

#ifdef __cplusplus

#include <vector>
#include <cstddef>

template<class T>
struct vector {
    void *_M_start;
    void *_M_finish;
    void *_M_end_of_storage;

    size_t size() {
        return ((std::vector<T> *) this)->size();
    }

    T &operator[](size_t i) {
        return ((std::vector<T> *) this)->operator[](i);
    }

    void push_back(T &e) {
        ((std::vector<T> *) this)->push_back(e);
    }
};

#define vector(type) vector<type>
#else
struct vector {
    void *_M_start;
    void *_M_finish;
    void *_M_end_of_storage;
};
#define vector(type) struct vector
#endif

#endif //EASYMOD_CXXVECTOR_H
