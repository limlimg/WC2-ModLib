#ifndef EASYMOD_CXXNEW_H
#define EASYMOD_CXXNEW_H

#include <malloc.h>

#ifndef __cplusplus
#define new(type) (type *)malloc(sizeof(type))
#define newix(type, size) (type *)malloc(sizeof(type) * size)
#endif

#endif //EASYMOD_CXXNEW_H
