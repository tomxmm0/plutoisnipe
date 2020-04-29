#pragma once

namespace plutoisnipe
{
	namespace game
	{
		typedef void(__cdecl* PM_ExitAimDownSight_t)(player_state* ps);
		extern std::uintptr_t PM_ExitAimDownSight_addr;

		typedef void(__cdecl* SV_GameSendServerCommand_t)(const int cnum, const int type, const char* text);
		extern std::uintptr_t SV_GameSendServerCommand_addr;

		typedef void(__cdecl* Scr_PlayerDamage_t)(int* self, int* attacker, int* target, int damage, int dflags, int mod, weapon weapon, bool alt, vec3 point, vec3 dir, int hit_location, int time_offset);
		extern std::uintptr_t Scr_PlayerDamage_addr;

		void PlayerCmd_AllowAds(gentity* ent, const bool allow);
		float PlayerCmd_PlayerAds(gentity* ent);
		bool PlayerCmd_adsButtonPressed(gentity* ent);

		void say_to(int num, const char* msg);

		extern std::initializer_list<const char*> allowed;
		bool is_allowed(const game::weapon weapon); 
	}
}
