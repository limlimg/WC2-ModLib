#ifndef EASYMOD_ASMCODE_H
#define EASYMOD_ASMCODE_H

#define ASMCODE_BIND \
"SUB SP, SP, #0xA0\n\t"\
"STP D7, D6, [SP, #0x0]\n\t"\
"STP D5, D4, [SP, #0x10]\n\t"\
"STP D3, D2, [SP, #0x20]\n\t"\
"STP D1, D0, [SP, #0x30]\n\t"\
"STP X7, X6, [SP, #0x40]\n\t"\
"STP X5, X4, [SP, #0x50]\n\t"\
"STP X3, X2, [SP, #0x60]\n\t"\
"STP X1, X0, [SP, #0x70]\n\t"\
"STP X16, X17, [SP, #0x80]\n\t"\
"STP X29, X30, [SP, #0x90]\n\t"\
"ADD x29, SP, #0x90\n\t"\
"add x0, x16, x17\n\t"\
"bl bind_address\n\t"\
"LDP X29, X30, [SP, #0x90]\n\t"\
"LDP X16, X17, [SP, #0x80]\n\t"\
"LDP X1, X0, [SP, #0x70]\n\t"\
"LDP X3, X2, [SP, #0x60]\n\t"\
"LDP X5, X4, [SP, #0x50]\n\t"\
"LDP X7, X6, [SP, #0x40]\n\t"\
"LDP D1, D0, [SP, #0x30]\n\t"\
"LDP D3, D2, [SP, #0x20]\n\t"\
"LDP D5, D4, [SP, #0x10]\n\t"\
"LDP D7, D6, [SP, #0x0]\n\t"\
"ADD SP, SP, #0xA0\n\t"\
"ldr x8, [x16, x17]\n\t"\
"br x8\n\t"

#define ASMCODE_PLT(name) \
"adr x16, #16\n\t"\
"ldr x17, [x16]\n\t"\
"ldr x8, [x16, x17]\n\t"\
"br x8\n\t"\
".quad "sptr(name)" - ."

#define ASMCODE_THN(name, offset) \
"sub x0, x0, #"#offset"\n\t"\
"b _Z"#name"\n\t"

#endif //EASYMOD_ASMCODE_H
