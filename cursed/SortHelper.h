#pragma once
#include <string>

namespace IMEX
{
	class SortHelper
	{
	public:
	
		static bool CompareStrings(std::string_view first, std::string_view second);
	};
}

