#ifndef EASYMOD_ASMCODE_H
#define EASYMOD_ASMCODE_H

#include "easytech.h"

#define ASMCODE_BIND \
"push %ecx\n\t"\
"call bind_address\n\t"\
"pop %ecx\n\t"\
"jmp *(%ecx)\n\t"

#define ASMCODE_PLT(name) \
"call .+5\n\t"\
"pop %ecx\n\t"\
"lea 8(%ecx), %ecx\n\t"\
"addl (%ecx), %ecx\n\t"\
"jmp *(%ecx)\n\t"\
".long "__easytech(name)" - ."

#define ASMCODE_THN(name, offset) \
"sub $"#offset", 4(%esp)\n\t"\
"jmp _Z"#name"\n\t"

#endif //EASYMOD_ASMCODE_H
