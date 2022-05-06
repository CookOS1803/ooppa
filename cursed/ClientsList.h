#pragma once
#include <vector>
#include <memory>
#include <functional>
#include "ISerializable.h"
#include "ClientInfo.h"
#include "List.h"

namespace IMEX
{
	class ClientsList : public List<ClientInfo, std::string>, public ISerializable
	{
		std::string folderName;
		std::string infoFileName;

	public:

		ClientsList();

		void SetFolderName(std::string_view folderName);
		void SetInfoFileName(std::string_view infoFileName);

		void ShowToConsole() override;
		void SaveToFile() override;
		void ReadFromFile() override;

		static bool ByLoginAscendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2);
		static bool ByLoginDescendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2);
		static bool ByNameAscendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2);
		static bool ByNameDescendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2);
		static bool ByLegalEntityAscendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2);
		static bool ByLegalEntityDescendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2);
		static bool ByCountryAscendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2);
		static bool ByCountryDescendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2);
	};
}

