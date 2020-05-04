#pragma once

namespace plutoisnipe
{
	class anti_hardscope
	{
	public:
		static anti_hardscope* get();
		anti_hardscope();
		
		void iterate();
	private:
		std::unordered_map<int, int> adscycles_;
	};
}
