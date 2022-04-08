#pragma once

namespace IMEX
{
	class ISerializable
	{
	public:

		virtual void SaveToFile() = 0;
		virtual void ReadFromFile() = 0;
	};
}
