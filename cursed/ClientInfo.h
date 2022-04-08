#pragma once
#include "ISerializable.h"
#include <string>

namespace IMEX
{
	class ClientInfo : public ISerializable
	{
		std::string name = "*";
		std::string country = "*";
		std::string phone = "*";

		std::string fileName;

	public:

		ClientInfo();
		ClientInfo(std::string_view name, std::string_view country, std::string_view phone);

		auto GetName() -> std::string_view;
		auto GetCountry() -> std::string_view;
		auto GetPhone() -> std::string_view;

		void SetName(std::string_view name);
		void SetCountry(std::string_view country);
		void SetPhone(std::string_view phone);
		void SetFileName(std::string_view fileName);

		void ShowToConsole() override;
		void SaveToFile() override;
		void ReadFromFile() override;
	};
}

