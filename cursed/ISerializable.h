#pragma once
#include <string>

namespace IMEX
{
	class ISerializable
	{
	public:

		virtual void ShowToConsole() = 0;
		virtual void SaveToFile(const std::string& fileName) = 0;
		virtual void ReadFromFile(const std::string& fileName) = 0;
	};
}
