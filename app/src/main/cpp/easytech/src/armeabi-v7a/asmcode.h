#ifndef EASYMOD_ASMCODE_H
#define EASYMOD_ASMCODE_H

#include "easytech.h"

#define ASMCODE_BIND \
"push {r0-r3,r12,lr}\n\t"\
"mov r0, r12\n\t"\
"bl bind_address\n\t"\
"pop {r0-r3,r12,lr}\n\t"\
"ldr pc, [r12]\n\t"

#define ASMCODE_PLT(name) \
"ldr r12, [pc, #8]\n\t"\
"add r12, pc\n\t"\
"ldr pc, [r12]\n\t"\
".align 2\n\t"\
".long "__easytech(name)" - (. -4)\n\t"

#define ASMCODE_THN(name, offset) \
"sub r0, #"#offset"\n\t"\
"b _Z"#name"\n\t"

#endif //EASYMOD_ASMCODE_H
