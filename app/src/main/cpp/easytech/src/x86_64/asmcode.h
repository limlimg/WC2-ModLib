#ifndef EASYMOD_ASMCODE_H
#define EASYMOD_ASMCODE_H

#define ASMCODE_BIND \
"push %rax\n\t"\
"push %rdi\n\t"\
"push %rsi\n\t"\
"push %rdx\n\t"\
"push %rcx\n\t"\
"push %r8\n\t"\
"push %r9\n\t"\
"subq $0x48, %rsp\n\t"\
"movsd %xmm7, 0x40(%rsp)\n\t"\
"movsd %xmm6, 0x38(%rsp)\n\t"\
"movsd %xmm5, 0x30(%rsp)\n\t"\
"movsd %xmm4, 0x28(%rsp)\n\t"\
"movsd %xmm3, 0x20(%rsp)\n\t"\
"movsd %xmm2, 0x18(%rsp)\n\t"\
"movsd %xmm1, 0x10(%rsp)\n\t"\
"movsd %xmm0, 0x8(%rsp)\n\t"\
"mov %rax, %rdi\n\t"\
"call bind_address\n\t"\
"movsd 0x8(%rsp), %xmm0\n\t"\
"movsd 0x10(%rsp), %xmm1\n\t"\
"movsd 0x18(%rsp), %xmm2\n\t"\
"movsd 0x20(%rsp), %xmm3\n\t"\
"movsd 0x28(%rsp), %xmm4\n\t"\
"movsd 0x30(%rsp), %xmm5\n\t"\
"movsd 0x38(%rsp), %xmm6\n\t"\
"movsd 0x40(%rsp), %xmm7\n\t"\
"addq $0x48, %rsp\n\t"\
"pop %r9\n\t"\
"pop %r8\n\t"\
"pop %rcx\n\t"\
"pop %rdx\n\t"\
"pop %rsi\n\t"\
"pop %rdi\n\t"\
"pop %rax\n\t"\
"jmp *(%rax)\n\t"

#define ASMCODE_PLT(name) \
"lea 5(%rip), %rax\n\t"\
"addq (%rax), %rax\n\t"\
"jmp *(%rax)\n\t"\
".quad "sptr(name)" - ."

#define ASMCODE_THN(name, offset) \
"sub $"#offset", %rdi\n\t"\
"jmp _Z"#name"\n\t"

#endif //EASYMOD_ASMCODE_H
