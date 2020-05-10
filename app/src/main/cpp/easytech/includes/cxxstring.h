#ifndef EASYMOD_CXXSTRING_H
#define EASYMOD_CXXSTRING_H

#ifdef __cplusplus

#include <string>

struct string {
    char *_M_p;
};
#else
struct string {
    char *_M_p;
};
#define string struct string
#endif

#endif //EASYMOD_CXXSTRING_H
