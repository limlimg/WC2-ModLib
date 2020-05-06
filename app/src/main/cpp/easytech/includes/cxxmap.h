#ifndef EASYMOD_CXXMAP_H
#define EASYMOD_CXXMAP_H

#ifdef __cplusplus
#include <map>
#else

#include <stddef.h>
#include <stdbool.h>

#endif

#define _ZSt4pair(type1_name, type2_name) struct _ZSt4pairI##type1_name##type2_name##E
#define _ZNSt3map8iteratorE(key_name, value_name) struct _ZNSt3mapI##key_name##value_name##St4lessI##key_name##ESaISt4pairIK##key_name##value_name##EEE8iteratorE
#define _ZSt3map(key_name, value_name) struct _ZSt3mapI##key_name##value_name##St4lessI##key_name##ESaISt4pairIK##key_name##value_name##EEE
#define def__ZSt3map(key, key_name, value, value_name) _ZSt4pair(key_name, value_name) {\
    key first;\
    value second;\
};\
_ZNSt3map8iteratorE(key_name, value_name) {\
    bool (*_M_key_compare)(key *, key *);\
    bool _M_color;\
    _ZNSt3map8iteratorE(key_name, value_name) *_M_parent;\
    _ZNSt3map8iteratorE(key_name, value_name) *_M_left;\
    _ZNSt3map8iteratorE(key_name, value_name) *_M_right;\
    size_t _M_node_count;\
    _ZSt4pair(key_name, value_name) _M_value_field;\
};\
_ZSt3map(key_name, value_name) {\
    bool (*_M_key_compare)(key *, key *);\
    bool _M_color;\
    _ZNSt3map8iteratorE(key_name, value_name) *_M_parent;\
    _ZNSt3map8iteratorE(key_name, value_name) *_M_left;\
    _ZNSt3map8iteratorE(key_name, value_name) *_M_right;\
    size_t _M_node_count;\
};

#endif //EASYMOD_CXXMAP_H
