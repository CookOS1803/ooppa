#pragma once
#include "ISerializable.h"
#include <string>

namespace IMEX
{
	class ClientInfo : public ISerializable
	{
		std::string login;
		std::string name = "*";
		std::string legalEntity;
		std::string country = "*";
		std::string phone = "*";

		std::string fileName;

	public:

		ClientInfo();
		ClientInfo(std::string login, std::string_view name, std::string legalEntity, std::string_view country, std::string_view phone);

		auto GetLogin() const -> std::string_view;
		auto GetName() const -> std::string_view;
		auto GetLegalEntity() const -> std::string_view;
		auto GetCountry() const -> std::string_view;
		auto GetPhone() const -> std::string_view;

		void SetLogin(std::string_view login);
		void SetName(std::string_view name);
		void SetLegalEntity(std::string_view legalEntity);
		void SetCountry(std::string_view country);
		void SetPhone(std::string_view phone);
		void SetFileName(std::string_view fileName);

		void ShowToConsole() override;
		void SaveToFile() override;
		void ReadFromFile() override;
	};
}

