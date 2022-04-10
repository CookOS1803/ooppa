#pragma once
#include <vector>
#include <memory>
#include "ISerializable.h"
#include "ClientInfo.h"

namespace IMEX
{
	class ClientsList : public ISerializable
	{
		std::vector<std::shared_ptr<ClientInfo>> originalClients;
		std::vector<std::shared_ptr<ClientInfo>> copiedClients;

		std::string folderName;
		std::string infoFileName;

	public:

		ClientsList();

		void SetFolderName(std::string_view folderName);
		void SetInfoFileName(std::string_view infoFileName);

		void ShowToConsole() override;
		void SaveToFile() override;
		void ReadFromFile() override;

	};
}

