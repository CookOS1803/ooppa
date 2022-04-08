#pragma once
#include <string>

namespace IMEX
{
	class ISerializable
	{
	public:

		virtual void ShowToConsole() = 0;
		virtual void SaveToFile() = 0;
		virtual void ReadFromFile() = 0;
	};
}
