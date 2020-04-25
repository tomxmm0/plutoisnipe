#pragma once

namespace plutoisnipe
{
	class anti_hardscope
	{
	public:
		static anti_hardscope* get();
		anti_hardscope();
		
		void start();
		void shutdown();
	private:
		std::thread thread_;
		std::unordered_map<int, int> adscycles_;

		bool active_;
	};
}
