#include "ClientsList.h"
#include <iomanip>
#include <iostream>
#include <filesystem>
#include <fstream>

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
		originalElements.emplace_back(std::make_shared<ClientInfo>());

		std::string login = dir_entry.path().stem().string();
		originalElements.back()->SetLogin(login);
		originalElements.back()->SetFileName(folderName + login + "\\" + infoFileName);
		originalElements.back()->ReadFromFile();

		copiedElements.push_back(originalElements.back());
	}
}

bool ClientsList::ByLoginAscendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2)
{
	return c1->GetLogin()[0] < c2->GetLogin()[0];
}

bool ClientsList::ByLoginDescendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2)
{
	return c1->GetLogin()[0] > c2->GetLogin()[0];
}

bool ClientsList::ByNameAscendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2)
{
	return c1->GetName()[0] < c2->GetName()[0];
}

bool ClientsList::ByNameDescendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2)
{
	return c1->GetName()[0] > c2->GetName()[0];
}

bool ClientsList::ByLegalEntityAscendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2)
{
	return c1->GetLegalEntity()[0] < c2->GetLegalEntity()[0];
}

bool ClientsList::ByLegalEntityDescendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2)
{
	return c1->GetLegalEntity()[0] > c2->GetLegalEntity()[0];
}

bool ClientsList::ByCountryAscendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2)
{
	return c1->GetCountry()[0] < c2->GetCountry()[0];
}

bool ClientsList::ByCountryDescendingly(const std::shared_ptr<ClientInfo>& c1, const std::shared_ptr<ClientInfo>& c2)
{
	return c1->GetCountry()[0] > c2->GetCountry()[0];
}
