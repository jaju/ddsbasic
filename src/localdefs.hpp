#pragma once

#ifdef __cplusplus
#  define BEGIN_C_DECLS extern "C" {
#  define END_C_DECLS   }
#  define BEGIN_NAMESPACE(x) namespace x {
#  define END_NAMESPACE(x) }
#  define USING_NAMESPACE(x) using namespace x
#  define safe_delete(x) if (x) { delete x; x = 0; }
#else /* !__cplusplus */
#  define BEGIN_C_DECLS
#  define END_C_DECLS
#  define BEGIN_NAMESPACE(x)
#  define END_NAMESPACE(x)
#  define USING_NAMESPACE(x)
#endif /* __cplusplus */
