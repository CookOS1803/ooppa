#include "ClientsList.h"
#include <iomanip>
#include <iostream>
#include <filesystem>
#include <fstream>
#include "SortHelper.h"

using namespace IMEX;

ClientsList::ClientsList()
{
}

void ClientsList::SetFolderName(std::string_view folderName)
{
	this->folderName = folderName;
}

void ClientsList::SetInfoFileName(std::string_view infoFileName)
{
	this->infoFileName = infoFileName;
}

bool IMEX::ClientsList::DoesMatchFilters(const std::shared_ptr<ClientInfo>& e) const
{
	return nameFilter(e->GetName()) and legalEntityFilter(e->GetLegalEntity()) and countryFilter(e->GetCountry())
		and phoneFilter(e->GetPhone()) and loginFilter(e->GetLogin());
}

void IMEX::ClientsList::SetNameFilter(std::string_view s)
{
	nameFilter.SetSubstring(s);
	ApplyFilters();
}

void IMEX::ClientsList::SetLegalEntityFilter(std::string_view s)
{
	legalEntityFilter.SetSubstring(s);
	ApplyFilters();
}

void IMEX::ClientsList::SetCountryFilter(std::string_view s)
{
	countryFilter.SetSubstring(s);
	ApplyFilters();
}

void IMEX::ClientsList::SetPhoneFilter(std::string_view s)
{
	phoneFilter.SetSubstring(s);
	ApplyFilters();
}

void IMEX::ClientsList::SetLoginFilter(std::string_view s)
{
	loginFilter.SetSubstring(s);
	ApplyFilters();
}

void IMEX::ClientsList::ClearFilters()
{
	nameFilter.Clear();
	legalEntityFilter.Clear();
	countryFilter.Clear();
	phoneFilter.Clear();
	loginFilter.Clear();

	ApplyFilters();
}

void ClientsList::ShowToConsole()
{
	std::cout << std::left;

	std::cout
		<< std::setw(30) << "Имя" << std::setw(30) << "Юридическое лицо"
		<< std::setw(30) << "Страна" << std::setw(30) << "Телефон"
		<< std::setw(30) << "Логин" << std::endl;

	for (const auto& client : copiedElements)
	{
		std::cout
			<< std::setw(30) << client->GetName() << std::setw(30) << client->GetLegalEntity()
			<< std::setw(30) << client->GetCountry() << std::setw(30) << client->GetPhone()
			<< std::setw(30) << client->GetLogin() << std::endl;
	}
}

void ClientsList::SaveToFile()
{
}

void ClientsList::ReadFromFile()
{
	std::filesystem::path path {folderName};

	for (auto const& dir_entry : std::filesystem::directory_iterator { path })
	{
		auto newElement = std::make_shared<ClientInfo>();

		std::string login = dir_entry.path().stem().string();
		newElement->SetLogin(login);
		newElement->SetFileName(folderName + login + "\\" + infoFileName);
		newElement->ReadFromFile();

		originalElements[login] = newElement;
		copiedElements.push_back(newElement);
	}
}

bool ClientsList::ByLoginAscendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2)
{
	return SortHelper::CompareStrings(c1->GetLogin(), c2->GetLogin());
}

bool ClientsList::ByLoginDescendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2)
{
	return !ByLoginAscendingly(c1, c2);
}

bool ClientsList::ByNameAscendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2)
{
	return SortHelper::CompareStrings(c1->GetName(), c2->GetName());
}

bool ClientsList::ByNameDescendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2)
{
	return !ByNameAscendingly(c1, c2);
}

bool ClientsList::ByLegalEntityAscendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2)
{
	return SortHelper::CompareStrings(c1->GetLegalEntity(), c2->GetLegalEntity());
}

bool ClientsList::ByLegalEntityDescendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2)
{
	return !ByLegalEntityAscendingly(c1, c2);
}

bool ClientsList::ByCountryAscendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2)
{
	return SortHelper::CompareStrings(c1->GetCountry(), c2->GetCountry());
}

bool ClientsList::ByCountryDescendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2)
{
	return !ByCountryAscendingly(c1, c2);
}

bool IMEX::ClientsList::ByPhoneAscendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2)
{
	return SortHelper::CompareStrings(c1->GetPhone(), c2->GetPhone());
}

bool IMEX::ClientsList::ByPhoneDescendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2)
{
	return !ByPhoneAscendingly(c1, c2);
}
