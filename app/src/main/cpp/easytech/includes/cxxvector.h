#ifndef EASYMOD_CXXVECTOR_H
#define EASYMOD_CXXVECTOR_H

#ifdef __cplusplus
#include <vector>
#else

#include <stddef.h>
#include <stdbool.h>

#endif

#define _ZSt6vector(type_name) struct _ZSt6vectorI##type_name##SaI##type_name##EE
#define def__ZSt6vector(type, type_name) _ZSt6vector(type_name) {\
    type *_M_start;\
    type *_M_finish;\
    type *_M_end_of_storage;\
};\
def__ZNSt6vector4sizeE(type, type_name)\
def__ZNSt6vectorixE(type, type_name)\
def__ZNSt6vector9push_backE(type, type_name)

#define _ZNSt6vector4sizeE(type_name) _ZNSt6vectorI##type_name##SaI##type_name##EE4sizeE
#ifndef __cplusplus
#define def__ZNSt6vector4sizeE(type, type_name) size_t _ZNSt6vector4sizeE(type_name)(_ZSt6vector(type_name) *self);
#else
#define def__ZNSt6vector4sizeE(type, type_name) inline size_t _ZNSt6vector4sizeE(type_name)(_ZSt6vector(type_name) *self) {\
    return ((std::vector<type> *)self)->size();\
}
#endif

#define _ZNSt6vectorixE(type_name) _ZNSt6vectorI##type_name##SaI##type_name##EEixE
#ifndef __cplusplus
#define def__ZNSt6vectorixE(type, type_name) type *_ZNSt6vectorixE(type_name)(_ZSt6vector(type_name) *self, size_t i);
#else
#define def__ZNSt6vectorixE(type, type_name) __attribute__ ((visibility("hidden"))) type &_ZNSt6vectorixE(type_name)(_ZSt6vector(type_name) *self, size_t i) {\
    return ((std::vector<type> *)self)->operator[](i);\
}
#endif

#define _ZNSt6vector9push_backE(type_name) _ZNSt6vectorI##type_name##SaI##type_name##EE9push_backE
#ifndef __cplusplus
#define def__ZNSt6vector9push_backE(type, type_name) void _ZNSt6vector9push_backE(type_name)(_ZSt6vector(type_name) *self, type *e);
#else
#define def__ZNSt6vector9push_backE(type, type_name) __attribute__ ((visibility("hidden"))) void _ZNSt6vector9push_backE(type_name)(_ZSt6vector(type_name) *self, type &e) {\
    ((std::vector<type> *)self)->push_back(e);\
}
#endif

#endif //EASYMOD_CXXVECTOR_H
