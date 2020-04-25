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

		sizeof(game::gclient);

		bool flag = true;

		while (flag)
		{
			auto input = ""s;
			std::getline(std::cin, input);

			if (!input.empty())
			{
				if (input == "quit")
				{
					flag = false;
				}
			}
		}

		FreeLibrary(hmodule);
	}

	void shutdown()
	{
		PRINT("Shutting down plutoisnipe.");
		anti_hardscope::get()->shutdown();
		hook::shutdown();
	}
}
