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

	};
}

