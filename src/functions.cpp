#include "stdinc.hpp"

#include "datatypes.hpp"
#include "global.hpp"
#include "functions.hpp"

namespace plutoisnipe
{
	namespace game
	{
		std::uintptr_t PM_ExitAimDownSight_addr = 0x428050;
		std::uintptr_t SV_GameSendServerCommand_addr = 0x573220;
		std::uintptr_t Scr_PlayerDamage_addr = 0x527B90;

		void PlayerCmd_AllowAds(gentity* ent, const bool allow)
		{
			if (allow)
			{
				ent->shared.client->ps.weapon_flags &= 0xFFFFFFDF;
			}
			else
			{
				ent->shared.client->ps.weapon_flags |= 0x20u;
				reinterpret_cast<PM_ExitAimDownSight_t>(PM_ExitAimDownSight_addr)(&ent->shared.client->ps);
			}
		}

		float PlayerCmd_PlayerAds(gentity* ent)
		{
			return ent->shared.client->ps.f_weapon_pos_frac;
		}

		bool PlayerCmd_adsButtonPressed(gentity* ent)
		{
			auto ps = reinterpret_cast<int>(&ent->shared.client->ps);
			auto button = *reinterpret_cast<int*>(ps + 13796) | *reinterpret_cast<int*>(ps + 13784);

			return (button & 0x800) != 0;
		}

		void say_to(gentity* ent, const char* msg)
		{
			auto num = ent - entities;
			char text[64];

			sprintf_s(text, "%c \"%s\"", 84, msg);

			reinterpret_cast<SV_GameSendServerCommand_t>(SV_GameSendServerCommand_addr)(num, 0, text);
		}

		std::initializer_list<const char*> allowed = {
			"iw5_l96a1_mp",
			"iw5_rsass_mp",
			"iw5_msr_mp",
			"iw5_barrett_mp",
			"iw5_dragunov_mp",
			"iw5_as50_mp",
			"iw5_cheytac_mp",
			"throwingknife_mp"
		};

		bool is_allowed(const game::weapon weapon)
		{
			auto name = game::weapon_complete_defs[weapon.weapon_data & 0xFF]->name;

			for (const auto& weapon : allowed)
			{
				if (strcmp(name, weapon) == 0)
				{
					return true;
				}
			}

			return false;
		}
	}
}
