/*
 *
 * Macro for calling original libeasytech functions.
 * To call the original version of a function from libeasytech.so,
 * declare it using def_easytech(function_name),
 * then call it using easytech(function_name)(args)
 *
 * */

#ifndef EASYMOD_EASYTECH_H
#define EASYMOD_EASYTECH_H

#define easytech(func) func##_ptr
#define def_easytech(func) extern typeof(&func) func##_ptr;

#define __easytech(func) #func"_ptr"

#endif //EASYMOD_EASYTECH_H
