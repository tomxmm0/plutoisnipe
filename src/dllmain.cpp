#include "stdinc.hpp"
#include "plutoisnipe.hpp"

int __stdcall DllMain(HMODULE hmodule, DWORD ul_reason_for_call, void* lpReserved)
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
		std::thread(plutoisnipe::initialize, hmodule).detach();
	}
	else if (ul_reason_for_call == DLL_PROCESS_DETACH)
	{
		plutoisnipe::shutdown();
	}

	return 1;
}
