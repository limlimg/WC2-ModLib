/*
 *
 * Macro for explicitly calling original libeasytech functions.
 * To call the original version of a function from libeasytech.so,
 * declare it using def_easytech(function_name),
 * then call it using easytech(function_name)(args)
 *
 * */

#ifndef EASYMOD_EASYTECH_H
#define EASYMOD_EASYTECH_H

#define easytech(func) easytech_##func##_
#ifdef __cplusplus
#define def_easytech(func) extern "C" typeof(func) easytech(func);
#else
#define def_easytech(func) typeof(func) easytech(func);
#endif

#endif //EASYMOD_EASYTECH_H
