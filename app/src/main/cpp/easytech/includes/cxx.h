#ifndef EASYMOD_CXX_H
#define EASYMOD_CXX_H

#ifdef __cplusplus
#define __BEGIN_DECLS extern "C" {
#define __END_DECLS }
#else
#define __BEGIN_DECLS
#define __END_DECLS
#endif

#ifdef __cplusplus
#define __sub_struct(name, base_name) struct name: base_name {
#define __sub2_struct(name, base_name, base2_name) struct name: base_name, base2_name {
#else
#define __sub_struct(name, base_name) struct name { __base_##base_name
#define __sub2_struct(name, base_name, base2_name) struct name { __base_##base_name __base_##base2_name
#endif
#define __end_struct };

#endif //EASYMOD_CXX_H
