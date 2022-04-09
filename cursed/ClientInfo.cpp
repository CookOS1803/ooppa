#include "ClientInfo.h"
#include <iostream>
#include <fstream>

using namespace IMEX;

ClientInfo::ClientInfo()
{
}


ClientInfo::ClientInfo(std::string login, std::string_view name, std::string legalEntity, std::string_view country, std::string_view phone)
	: login(login), name(name), legalEntity(legalEntity), country(country), phone(phone)
{
}

auto ClientInfo::GetLogin() const -> std::string_view
{
	return login;
}

auto ClientInfo::GetName() const -> std::string_view
{
	return name;
}

auto ClientInfo::GetLegalEntity() const -> std::string_view
{
	return legalEntity;
}

auto ClientInfo::GetCountry() const -> std::string_view
{
	return country;
}

auto ClientInfo::GetPhone() const -> std::string_view
{
	return phone;
}

void ClientInfo::SetLogin(std::string_view login)
{
	this->login = login;
}

void ClientInfo::SetName(std::string_view name)
{
	this->name = name;
}

void ClientInfo::SetCountry(std::string_view country)
{
	this->country = country;
}

void ClientInfo::SetPhone(std::string_view phone)
{
	this->phone = phone;
}

void ClientInfo::SetLegalEntity(std::string_view legalEntity)
{
	this->legalEntity = legalEntity;
}

void ClientInfo::SetFileName(std::string_view fileName)
{
	this->fileName = fileName;
}

void ClientInfo::ShowToConsole()
{
	std::cout
		<< "Имя: " << name << std::endl
		<< "Юридическое лицо: " << legalEntity << std::endl
		<< "Страна: " << country << std::endl
		<< "Телефон: " << phone << std::endl
		<< std::endl;
}


void ClientInfo::SaveToFile()
{
	std::ofstream out;

	out.open(fileName);

	out.write(name.c_str(), name.size());
	out << "\n";
	out.write(legalEntity.c_str(), legalEntity.size());
	out << "\n";
	out.write(country.c_str(), country.size());
	out << "\n";
	out.write(phone.c_str(), phone.size());
	out << "\n";

	out.close();
}

void ClientInfo::ReadFromFile()
{
	std::ifstream in;

	in.open(fileName);

	std::getline(in, name);
	std::getline(in, legalEntity);
	std::getline(in, country);
	std::getline(in, phone);

	in.close();
}