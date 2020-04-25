#pragma once

namespace plutoisnipe
{
	namespace game
	{
		using vec3 = float[3];

		struct weapon
		{
			unsigned int weapon_data;
		};

		struct weapon_complete_def
		{
			const char* name;
		};

		struct player_state
		{
			char unk1[0x370];
			int current_weapon;
			int weapon_flags;
			float f_weapon_pos_frac;
		};

		struct gclient
		{
			player_state ps;
		};

		struct shared_entity
		{
			char unk1[0x58];
			gclient* client;
			char unk2[0x118];
		};

		struct entity_state
		{
			char unk1[0x4];
			int type;
			char unk2[0xF8];
		};

		struct gentity
		{
			entity_state state;
			shared_entity shared;
		};
	}
}
