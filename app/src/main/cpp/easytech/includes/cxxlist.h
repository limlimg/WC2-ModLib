#ifndef EASYMOD_CXXLIST_H
#define EASYMOD_CXXLIST_H

#ifdef __cplusplus
#include <list>
#else

#include <stddef.h>
#include <stdbool.h>

#endif

#define _ZNSt4list8iteratorE(type_name) struct _ZNSt4listI##type_name##SaI##type_name##EE8iteratorE
#define _ZSt4list(type_name) struct _ZSt4listI##type_name##SaI##type_name##EE
#define def__ZSt4list(type, type_name) _ZNSt4list8iteratorE(type_name) {\
    _ZNSt4list8iteratorE(type_name) *_M_next;\
    _ZNSt4list8iteratorE(type_name) *_M_prev;\
    type _M_data;\
};\
_ZSt4list(type_name) {\
    _ZNSt4list8iteratorE(type_name) *_M_next;\
    _ZNSt4list8iteratorE(type_name) *_M_prev;\
};\
def__ZNSt4list5emptyE(type, type_name)\
def__ZNSt4list9push_backE(type, type_name)

#define _ZNSt4list5emptyE(type_name) _ZNSt4listI##type_name##SaI##type_name##EE5emptyE
#ifndef __cplusplus
#define def__ZNSt4list5emptyE(type, type_name)
#else
#define def__ZNSt4list5emptyE(type, type_name) static inline bool _ZNSt4list5emptyE(type_name)(_ZSt4list(type_name) *self) {\
    return ((std::list<type> *)self)->empty();\
}
#endif

#define _ZNSt4list9push_backE(type_name) _ZNSt4listI##type_name##SaI##type_name##EE9push_backE
#ifndef __cplusplus
#define def__ZNSt4list9push_backE(type, type_name)
#else
#define def__ZNSt4list9push_backE(type, type_name) static inline void _ZNSt4list9push_backE(type_name)(_ZSt4list(type_name) *self, type &e) {\
    ((std::list<type> *)self)->push_back(e);\
}
#endif

#endif //EASYMOD_CXXLIST_H
