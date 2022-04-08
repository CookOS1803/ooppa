#include "ClientInfo.h"
#include <iostream>
#include <fstream>

using namespace IMEX;

ClientInfo::ClientInfo()
{
}

ClientInfo::ClientInfo(std::string_view name, std::string_view country, std::string_view phone)
	: name(name), country(country), phone(phone)
{
}

auto ClientInfo::GetName() -> std::string_view
{
	return name;
}

auto ClientInfo::GetCountry() -> std::string_view
{
	return country;
}

auto IMEX::ClientInfo::GetPhone() -> std::string_view
{
	return phone;
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

void ClientInfo::SetFileName(std::string_view fileName)
{
	this->fileName = fileName;
}

void ClientInfo::ShowToConsole()
{
	std::cout
		<< "Имя: " << name << std::endl
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
	std::getline(in, country);
	std::getline(in, phone);

	in.close();
}