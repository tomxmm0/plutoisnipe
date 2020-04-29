#include "stdinc.hpp"

#include "hook_manager.hpp"
#include "datatypes.hpp"
#include "global.hpp"
#include "functions.hpp"
#include "anti_hardscope.hpp"

#include "hook.hpp"

namespace plutoisnipe
{
	namespace hook
	{
		namespace functions
		{
			void Scr_PlayerDamage_hk(int* self, int* attacker, int* target, int damage, int dflags, int mod, game::weapon weapon, bool alt, game::vec3 point, game::vec3 dir, int hit_location, int time_offset)
			{
				if (!game::is_allowed(weapon) || mod == 8)
				{
					damage = 0;
				} 

				return reinterpret_cast<game::Scr_PlayerDamage_t>(game::Scr_PlayerDamage_addr)(
					self,
					attacker,
					target,
					damage,
					dflags,
					mod,
					weapon,
					alt,
					point,
					dir,
					hit_location,
					time_offset
				);
			}
		}

		void initialize()
		{
			hook_manager::get()->hook(&game::Scr_PlayerDamage_addr, functions::Scr_PlayerDamage_hk);
		}

		void shutdown()
		{
			hook_manager::get()->unhook_all();
		}
	}
}
