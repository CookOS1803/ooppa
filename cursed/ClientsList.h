#pragma once
#include "ISerializable.h"
#include "ClientInfo.h"
#include "List.h"
#include "Filter.h"

namespace IMEX
{
	class ClientsList : public List<ClientInfo, std::string>, public ISerializable
	{
		std::string folderName;
		std::string infoFileName;

		StringFilter nameFilter;
		StringFilter legalEntityFilter;
		StringFilter countryFilter;
		StringFilter phoneFilter;
		StringFilter loginFilter;

	public:

		ClientsList();

		void SetFolderName(std::string_view folderName);
		void SetInfoFileName(std::string_view infoFileName);

		bool DoesMatchFilters(const std::shared_ptr<ClientInfo>& e) const override;

		void SetNameFilter(std::string_view s);
		void SetLegalEntityFilter(std::string_view s);
		void SetCountryFilter(std::string_view s);
		void SetPhoneFilter(std::string_view s);
		void SetLoginFilter(std::string_view s);

		void ClearFilters();

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
		static bool ByPhoneAscendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2);
		static bool ByPhoneDescendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2);
	};
}

