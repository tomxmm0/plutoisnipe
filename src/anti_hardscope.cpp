#include "stdinc.hpp"

#include "datatypes.hpp"
#include "global.hpp"
#include "functions.hpp"
#include "anti_hardscope.hpp"

namespace plutoisnipe
{
	anti_hardscope* anti_hardscope::get()
	{
		static anti_hardscope instance;
		return &instance;
	}

	anti_hardscope::anti_hardscope()
	{
		for (int i = 0; i < 0x400; i++)
		{
			adscycles_.emplace(i, 0);
		}
	}

	void anti_hardscope::iterate()
	{
		for (int i = 0; i < 0x400; i++)
		{
			auto entity = &game::entities[i];

			if (entity->state.type == 1)
			{
				auto ads = game::PlayerCmd_PlayerAds(entity);
				auto iter = adscycles_.find(i);

				if (iter != adscycles_.end() && game::is_allowed({ static_cast<unsigned int>(entity->shared.client->ps.current_weapon) }))
				{
					if (ads == 1.f)
					{
						++iter->second;
					}
					else
					{
						iter->second = 0;
					}

					if (iter->second == 8)
					{
						game::PlayerCmd_AllowAds(entity, false);
						game::say_to(i, "Hardscoping is not allowed.");
					}

					if (ads == 0.f && !game::PlayerCmd_adsButtonPressed(entity))
					{
						game::PlayerCmd_AllowAds(entity, true);
					}
				}

			}
		}
	}
}
