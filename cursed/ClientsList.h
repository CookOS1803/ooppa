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

	public:

		ClientsList();

		void ShowToConsole() override;
		void SaveToFile() override;
		void ReadFromFile() override;

	};
}

