#ifndef EASYMOD_CXXMAP_H
#define EASYMOD_CXXMAP_H

#ifdef __cplusplus

#include <cstddef>
#include <map>

template<class key, class value>
struct map {
    bool (*_M_key_compare)(key *, key *);

    bool _M_color;
    void *_M_parent;
    void *_M_left;
    void *_M_right;
    size_t _M_node_count;
};

#define map(key, value) map<key, value>
#else

#include <stddef.h>
#include <stdbool.h>

struct map {
    bool (*_M_key_compare)(void *, void *);

    bool _M_color;
    void *_M_parent;
    void *_M_left;
    void *_M_right;
    size_t _M_node_count;
};

#define map(key, value) struct map
#endif

#endif //EASYMOD_CXXMAP_H
