#pragma once
#include "IndividualOperationList.h"

namespace IMEX
{
	class OperationList : public IndividualOperationList
	{
		std::string folderName;

	public:

		OperationList();

		void SetFolderName(std::string_view folderName);

		void ShowToConsole() override;
		void SaveToFile() override;
		void ReadFromFile() override;
	};
}

