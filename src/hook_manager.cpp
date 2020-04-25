#include "stdinc.hpp"
#include "hook_manager.hpp"

namespace plutoisnipe
{
	namespace hook
	{
		hook_manager* hook_manager::get()
		{
			static hook_manager instance;
			return &instance;
		}

		void hook_manager::hook(std::uintptr_t* address, void* function)
		{
			hook(&reinterpret_cast<void*&>(*address), function);
		}

		void hook_manager::hook(void** address, void* function)
		{
#ifdef DEBUG
			PRINT("Hook: %p -> %p", *address, function);
#endif

			DetourTransactionBegin();
			DetourUpdateThread(GetCurrentThread());

			DetourAttach(address, function);

			DetourTransactionCommit();

			hooks_.emplace(address, function);
		}

		void hook_manager::unhook(void** address)
		{
#ifdef DEBUG
			PRINT("Unhook: %p", *address);
#endif
			auto iter = std::find_if(hooks_.begin(), hooks_.end(), [address](const std::pair<void**, void*>& hook) {
				return *address == *hook.first;
			});

			if (iter != hooks_.end())
			{
				DetourTransactionBegin();
				DetourUpdateThread(GetCurrentThread());

				DetourDetach(iter->first, iter->second);

				DetourTransactionCommit();
				hooks_.erase(iter);
			}
		}

		void hook_manager::unhook_all()
		{
			DetourTransactionBegin();
			DetourUpdateThread(GetCurrentThread());

			for (const auto& hook : hooks_)
			{
#ifdef DEBUG
				PRINT("Unhook: %p", hook.first);
#endif

				DetourDetach(hook.first, hook.second);
			}

			DetourTransactionCommit();
			hooks_.clear();
		}
	}
}
