#ifndef EASYMOD_CXXLIST_H
#define EASYMOD_CXXLIST_H

#ifdef __cplusplus

#include <list>

template<class T>
struct list {
    void *_M_next;
    void *_M_prev;

    bool empty() {
        return ((std::list<T> *) this)->empty();
    }

    void push_back(T &e) {
        ((std::list<T> *) this)->push_back(e);
    }
};

#define list(type) list<type>
#else
struct list {
    void *_M_next;
    void *_M_prev;
};
#define list(type) struct list
#endif

#endif //EASYMOD_CXXLIST_H
