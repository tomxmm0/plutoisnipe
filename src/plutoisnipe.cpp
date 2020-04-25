#include "stdinc.hpp"

#include "datatypes.hpp"
#include "anti_hardscope.hpp"
#include "hook.hpp"

#include "plutoisnipe.hpp"

namespace plutoisnipe
{
	void initialize(const HMODULE hmodule)
	{
		hook::initialize();
		anti_hardscope::get()->start();
		PRINT("plutoisnipe initialized.");

		bool flag = true;

		while (true)
		{
			std::this_thread::sleep_for(1s);
		}
	}

	void shutdown()
	{
		PRINT("Shutting down plutoisnipe.");
		anti_hardscope::get()->shutdown();
		hook::shutdown();
	}
}
