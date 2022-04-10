#include "Client.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include "UserInput.h"

using namespace IMEX;

Client::Client() : User()
{
}

Client::Client(std::string_view login, const std::string& password)
	: User(login, password)
{
}

void Client::SetLogin(std::string_view login)
{
    User::SetLogin(login);
    info.SetLogin(login);
    info.SetFileName(GetInfoFileName());
}

auto Client::GetFolderName() -> std::string
{
	return CLIENTS_FOLDER + login + "\\";
}


auto Client::GetCredentialsFileName() -> std::string
{
    return GetFolderName() + CRED_FILE_NAME;
}

auto Client::GetInfoFileName() -> std::string
{
    return GetFolderName() + INFO_FILE_NAME;
}

void Client::RegistrationMenu()
{
    std::string input;

    std::cout << "Введите имя: ";
    std::getline(std::cin, input);
    info.SetName(input);

    std::cout << "Введите юридическое лицо: ";
    std::getline(std::cin, input);
    info.SetLegalEntity(input);

    std::cout << "Введите страну: ";
    std::getline(std::cin, input);
    info.SetCountry(input);

    std::cout << "Введите номер телефона: ";
    std::getline(std::cin, input);
    info.SetPhone(input);

    info.SetLogin(login);

    info.SaveToFile();
}

void Client::UserMenu()
{
    info.ReadFromFile();
    products.SetFileName(PROD_FILE_NAME);
    products.ReadFromFile();
    operations.SetOperationsFileName(GetFolderName() + OPER_FILE_NAME);
    operations.ReadFromFile();

    int choice;

    while (true)
    {
        INPUT
        (
            std::cout
            << "1. Показать персональную информацию\n"
            << "2. Изменить персональную информацию\n"
            << "3. Товары\n"
            << "4. Операции\n"
            << "0. Выход\n",
            choice
        );

        switch (choice)
        {
        case 1:
            info.ShowToConsole();
            break;
        case 2:
            InfoChangeMenu();
            break;
        case 3:
            StorageMenu();
            break;
        case 4:
            OperationsMenu();
            break;
        case 0:
            return;
        }
    }
}

void Client::InfoChangeMenu()
{
    int choice;
    std::string input;

    while (true)
    {
        INPUT
        (
            std::cout
            << "1. Изменить имя\n"
            << "2. Изменить страну\n"
            << "3. Изменить юридическое лицо\n"
            << "4. Изменить номер телефона\n"
            << "5. Изменить пароль\n"
            << "0. Назад\n",
            choice
        );

        switch (choice)
        {
        case 1:
            std::cout << "Введите новое имя: ";
            std::getline(std::cin, input);

            info.SetName(input);

            break;
        case 2:
            std::cout << "Введите новую страну: ";
            std::getline(std::cin, input);

            info.SetCountry(input);

            break;
        case 3:
            std::cout << "Введите новое юридическое лицо: ";
            std::getline(std::cin, input);

            info.SetLegalEntity(input);

            break;
        case 4:
            std::cout << "Введите новый номер телефона: ";
            std::getline(std::cin, input);

            info.SetPhone(input);

            break;
        case 5:
            std::cout << "Введите старый пароль: ";
            std::getline(std::cin, input);

            if (MakePassword(input) != password)
            {
                std::cout << "Введён неправильный пароль\n\n";
                break;
            }

            std::cout << "Введите новый пароль: ";
            std::getline(std::cin, input);

            password = MakePassword(input);

            SaveCredentialsToFile();

            break;
        case 0:
            return;
        }

        info.SaveToFile();
    }
}

void Client::StorageMenu()
{
    int choice;

    while (true)
    {
        INPUT
        (
            std::cout
            << "1. Просмотреть склад\n"
            << "2. Отсортировать список товаров\n"
            << "0. Выход\n",
            choice
        );

        switch (choice)
        {
        case 1:
            ShowStorageTask();
            break;
        case 2:
            SortStorageMenu();
            break;
        case 0:
            return;
        }
    }
}

void Client::ShowStorageTask()
{
    std::cout << std::left;

    std::cout
        << std::setw(30) << "Идентификационный номер" << std::setw(30) << "Наименование" << std::setw(30) << "Категория"
        << std::setw(30) << "Цена за штуку" << std::endl;

    for (const auto& product : products)
    {
        std::cout
            << std::setw(30) << product->GetID() << std::setw(30) << product->GetName() << std::setw(30) << product->GetCategory()
            << std::setw(30) << product->GetUnitPrice() << std::endl;
    }

}

void Client::SortStorageMenu()
{
    int choice, order;

    while (true)
    {
        INPUT
        (
            std::cout
            << "1. Сортировать по имени\n"
            << "2. Сортировать по категории\n"
            << "3. Сортировать по цене за штуку\n"
            << "0. Назад\n",
            choice
        );


        if (choice != 0)
        {
            INPUT_CONDITION
            (
                std::cout
                << "1. По возрастанию\n"
                << "2. По убыванию\n",
                order,
                order == 1 or order == 2
            );
        }

        switch (choice)
        {
        case 1:
            if (order == 1)
                products.Sort(ProductList::ByNameAscendingly);
            else
                products.Sort(ProductList::ByNameDescendingly);

            break;
        case 2:
            if (order == 1)
                products.Sort(ProductList::ByCategoryAscendingly);
            else
                products.Sort(ProductList::ByCategoryDescendingly);

            break;
        case 3:
            if (order == 1)
                products.Sort(ProductList::ByUnitPriceAscendingly);
            else
                products.Sort(ProductList::ByUnitPriceDescendingly);

            break;
        case 0:
            return;
        }
    }
}

void Client::OperationsMenu()
{
    int choice;

    while (true)
    {
        INPUT
        (
            std::cout
            << "1. Показать операции\n"
            << "2. Отсортировать список операций\n"
            << "3. Произвести импорт\n"
            << "4. Произвести экспорт\n"
            << "5. Отменить операцию\n"
            << "0. Назад\n",
            choice
        );

        switch (choice)
        {
        case 1:
            operations.ShowToConsole();
            break;
        case 2:
            SortOperationsMenu();
            break;
        case 3:
            MakeOperationTask(Operation::Type::IMPORT);
            break;
        case 4:
            MakeOperationTask(Operation::Type::EXPORT);
            break;
        case 5:
            CanselOperationTask();
            break;
        case 0:
            return;
        }
    }
}

void Client::SortOperationsMenu()
{
    int choice, order;

    while (true)
    {
        INPUT
        (
            std::cout
            << "1. Сортировать по идентификационному номеру операции\n"
            << "2. Сортировать по типу\n"
            << "3. Сортировать по статусу\n"
            << "4. Сортировать по идентификационному номеру товара\n"
            << "5. Сортировать по количеству товара\n"
            << "0. Назад\n",
            choice
        );


        if (choice != 0)
        {
            INPUT_CONDITION
            (
                std::cout
                << "1. По возрастанию\n"
                << "2. По убыванию\n",
                order,
                order == 1 or order == 2
            );
        }

        switch (choice)
        {
        case 1:
            if (order == 1)
                operations.Sort(IndividualOperationList::ByIDAscendingly);
            else
                operations.Sort(IndividualOperationList::ByIDDescendingly);

            break;
        case 2:
            if (order == 1)
                operations.Sort(OperationList::ByTypeAscendingly);
            else
                operations.Sort(OperationList::ByTypeDescendingly);

            break;
        case 3:
            if (order == 1)
                operations.Sort(OperationList::ByStatusAscendingly);
            else
                operations.Sort(OperationList::ByStatusDescendingly);

            break;
        case 4:
            if (order == 1)
                operations.Sort(OperationList::ByProductIDAscendingly);
            else
                operations.Sort(OperationList::ByProductIDDescendingly);

            break;
        case 5:
            if (order == 1)
                operations.Sort(OperationList::ByProductAmountAscendingly);
            else
                operations.Sort(OperationList::ByProductAmountDescendingly);

            break;
        case 0:
            return;
        }
    }
    
}

void Client::MakeOperationTask(Operation::Type type)
{
    Operation temp;
    int choice;

    INPUT
    (
        std::cout << "Введите идентификационный номер товара: ",
        choice
    );

    if (!products.Contains(choice))
    {
        std::cout << "Нет такого товара\n\n";
        return;
    }

    temp.SetProductID(choice);

    INPUT_CONDITION
    (
        std::cout << "Введите количество товара: ",
        choice,
        choice > 0
    );

    temp.SetProductAmount(choice);

    temp.SetType(type);
    temp.SetStatus(Operation::Status::PENDING);
    temp.SetClientLogin(login);

    OperationList l;
    l.SetFolderName(CLIENTS_FOLDER);
    l.SetOperationsFileName(OPER_FILE_NAME);
    l.ReadFromFile();

    temp.CalculateNewID(l);

    operations.Add(temp);

    operations.SaveToFile();
}

void Client::CanselOperationTask()
{
    int choice;

    INPUT
    (
        std::cout << "Введите идентификационный номер операции: ",
        choice
    );

    if (!operations.Contains(choice))
    {
        std::cout << "Нет такой операции\n\n";
        return;
    }

    operations.Remove(choice);

    operations.SaveToFile();
}
