#pragma once
#include "ISerializable.h"

namespace IMEX
{
	class Operation : public ISerializable
	{

		
	public:

		enum class Type
		{
			IMPORT,
			EXPORT
		};

		enum class Status
		{
			PENDING,
			REJECTED,
			APPROVED
		};

		void ShowToConsole() override;
		void SaveToFile() override;
		void ReadFromFile() override;
	};

}

