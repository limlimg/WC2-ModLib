#include <stddef.h>
#include <dlfcn.h>
#include "asmcode.h"

static void bind() {
    asm(ASMCODE_BIND);
}

typedef struct {
    void *ptr;
    size_t offset;
} bind_info;

#define plt(name, offset) \
__attribute__((weak)) __attribute__((visibility("protected"))) void name() {\
    asm(ASMCODE_PLT(name));\
}\
\
__attribute__((visibility("hidden"))) bind_info easytech(name) = {&bind, offset};

#define Thn(name, offset) \
__attribute__((weak)) __attribute__((visibility("protected"))) void _ZThn##offset##_##name() {\
    asm(ASMCODE_THN(name, offset));\
}

#define base(name, base_offset)\
__attribute__((used)) static void bind_address(bind_info *info) {\
    static void *BaseAddress = NULL;\
    if(BaseAddress == NULL)\
        BaseAddress = dlsym(dlopen("libeasytech.so", RTLD_NOLOAD), #name) - base_offset;\
    info->ptr = BaseAddress + info->offset;\
}

#define bss(name, size) __attribute__((weak)) __attribute__((visibility("protected"))) char name[size];

#include "bind_table.h"
