#pragma once

namespace plutoisnipe
{
	namespace game
	{
		typedef void(__cdecl* PM_ExitAimDownSight_t)(player_state* ps);
		extern PM_ExitAimDownSight_t PM_ExitAimDownSight;

		typedef void(__cdecl* SV_GameSendServerCommand_t)(const int cnum, const int type, const char* text);
		extern SV_GameSendServerCommand_t SV_GameSendServerCommand;

		void PlayerCmd_AllowAds(gentity* ent, const bool allow);
		float PlayerCmd_PlayerAds(gentity* ent);
		bool PlayerCmd_adsButtonPressed(gentity* ent);

		void say_to(int num, const char* msg);

		extern std::initializer_list<const char*> allowed;
		bool is_allowed(const game::weapon weapon); 
	}
}
