#pragma once

namespace IMEX
{
	class ISerializable
	{
	public:

		virtual ~ISerializable() {};

		virtual void ShowToConsole() = 0;
		virtual void SaveToFile() = 0;
		virtual void ReadFromFile() = 0;
	};
}
