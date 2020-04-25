#pragma once

namespace plutoisnipe
{
	namespace hook
	{
		class hook_manager
		{
		public:
			static hook_manager* get();

			void hook(std::uintptr_t* address, void* function);
			void hook(void** address, void* function);
			void unhook(void** address);

			void unhook_all();
		private:
			std::unordered_map<void**, void*> hooks_;
		};
	}
}
