#include "thread_local_destructor.h"
#include <iostream>
extern "C" void on_thread_exit(destructor_function_t destructor, void* destructor_data)
{
	struct Destructor {
		destructor_function_t func;
		void* data;
		~Destructor() noexcept
		{
			func(data);
		}
	};
	thread_local Destructor d{destructor, destructor_data};
}