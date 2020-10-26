#include <stdlib.h>

#ifdef __cplusplus
using destructor_function_t = void(*)(void*) noexcept;
#else
typedef void(*destructor_function_t)(void*);
#endif

#ifdef __cplusplus
extern "C"
#endif
void on_thread_exit(destructor_function_t, void* destructor_data);