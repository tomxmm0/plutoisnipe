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
			typedef void(__cdecl* Scr_PlayerDamage_t)(int* self, int* attacker, int* target, int damage, int dflags, int mod, game::weapon weapon, bool alt, game::vec3 point, game::vec3 dir, int hit_location, int time_offset);
			std::uintptr_t Scr_PlayerDamage_addr = 0x527B90;

			void Scr_PlayerDamage_hk(int* self, int* attacker, int* target, int damage, int dflags, int mod, game::weapon weapon, bool alt, game::vec3 point, game::vec3 dir, int hit_location, int time_offset)
			{
				if (!game::is_allowed(weapon) || mod == 8)
				{
					damage = 0;
				} 

				return reinterpret_cast<Scr_PlayerDamage_t>(Scr_PlayerDamage_addr)(
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

			typedef void(__cdecl* G_RunFrame_t)(int level_time);
			std::uintptr_t G_RunFrame_addr = 0x50CB70;

			void G_RunFrame_hk(int level_time)
			{
				anti_hardscope::get()->iterate();
				return reinterpret_cast<G_RunFrame_t>(G_RunFrame_addr)(level_time);
			}
		}

		void initialize()
		{
			hook_manager::get()->hook(&functions::Scr_PlayerDamage_addr, functions::Scr_PlayerDamage_hk);
			hook_manager::get()->hook(&functions::G_RunFrame_addr, &functions::G_RunFrame_hk);
		}

		void shutdown()
		{
			hook_manager::get()->unhook_all();
		}
	}
}
