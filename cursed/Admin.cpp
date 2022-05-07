#include "Admin.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include "UserInput.h"

using namespace IMEX;

Admin::Admin() : User()
{
}

Admin::Admin(std::string_view login, const std::string& password)
    : User(login, password)
{
}

auto Admin::GetFolderName() -> std::string
{
    return ADMINS_FOLDER;
}


auto Admin::GetCredentialsFileName() -> std::string
{
    return GetFolderName() + login + CRED_FILE_EXT;
}

void Admin::UserMenu()
{
    products.SetFileName(PROD_FILE_NAME);
    products.ReadFromFile();
    clients.SetFolderName(CLIENTS_FOLDER);
    clients.SetInfoFileName(INFO_FILE_NAME);
    clients.ReadFromFile();
    operations.SetFolderName(CLIENTS_FOLDER);
    operations.SetOperationsFileName(OPER_FILE_NAME);
    operations.ReadFromFile();

    int choice;

    while (true)
    {
        INPUT
        (
            std::cout
            << "1. Работа с клиентами\n"
            << "2. Работа с операциями\n"
            << "3. Работа с складом\n"
            << "4. Работа с администраторами\n"
            << "0. Выход\n",
            choice
        );

        switch (choice)
        {
        case 1:
            ClientsMenu();
            break;
        case 2:
            OperationsMenu();
            break;
        case 3:
            StorageMenu();
            break;
        case 4:
            AdminsMenu();
            break;
        case 0:
            return;
        }
    }
}

void Admin::ClientsMenu()
{
    int choice;
    
    while (true)
    {
        INPUT
        (
            std::cout
            << "1. Показать всех клиентов\n"
            << "2. Показать операции клиента\n"
            << "3. Отсортировать список клиентов\n"
            << "4. Применить фильтры поиска\n"
            << "0. Назад\n",
            choice
        );

        switch (choice)
        {
        case 1:
            clients.ShowToConsole();
            break;
        case 2:
            ShowClientTask();
            break;
        case 3:
            SortClientsMenu();
            break;
        case 4:
            FilterClientsMenu();
            break;
        case 0:
            return;
        }
    }
}

void Admin::ShowClientTask()
{
    std::string input;

    input = StringInput("Введите логин клиента: ");

    try
    {
        auto c = clients.GetElement(input);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << "\n\n";
        return;
    }

    IndividualOperationList l;
    l.SetOperationsFileName(CLIENTS_FOLDER + input + "\\" + OPER_FILE_NAME);
    l.ReadFromFile();
    l.ShowToConsole();
}

void Admin::SortClientsMenu()
{
    int choice, order;

    while (true)
    {
        INPUT
        (
            std::cout
            << "1. Сортировать по логину\n"
            << "2. Сортировать по имени\n"
            << "3. Сортировать по юридическому лицу\n"
            << "4. Сортировать по стране\n"
            << "5. Сортировать по телефону\n"
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
                clients.Sort(ClientsList::ByLoginAscendingly);
            else
                clients.Sort(ClientsList::ByLoginDescendingly);

            break;
        case 2:
            if (order == 1)
                clients.Sort(ClientsList::ByNameAscendingly);
            else
                clients.Sort(ClientsList::ByNameDescendingly);

            break;
        case 3:
            if (order == 1)
                clients.Sort(ClientsList::ByLegalEntityAscendingly);
            else
                clients.Sort(ClientsList::ByLegalEntityDescendingly);

            break;
        case 4:
            if (order == 1)
                clients.Sort(ClientsList::ByCountryAscendingly);
            else
                clients.Sort(ClientsList::ByCountryDescendingly);

            break;
        case 5:
            if (order == 1)
                clients.Sort(ClientsList::ByPhoneAscendingly);
            else
                clients.Sort(ClientsList::ByPhoneDescendingly);

            break;
        case 0:
            return;
        }
    }
}

void Admin::FilterClientsMenu()
{
    int choice;
    std::string s;

    while (true)
    {
        INPUT
        (
            std::cout
            << "1. Фильтровать по логину\n"
            << "2. Фильтровать по имени\n"
            << "3. Фильтровать по юридическому лицу\n"
            << "4. Фильтровать по стране\n"
            << "5. Фильтровать по телефону\n"
            << "6. Убрать фильтры\n"
            << "0. Назад\n",
            choice
        );

        if (choice != 0 and choice != 6)
        {
            std::cout << "Введите строку фильтр: ";
            std::getline(std::cin, s);
        }

        switch (choice)
        {
        case 1:
            clients.SetLoginFilter(s);

            break;
        case 2:
            clients.SetNameFilter(s);

            break;
        case 3:
            clients.SetLegalEntityFilter(s);

            break;
        case 4:
            clients.SetCountryFilter(s);

            break;
        case 5:
            clients.SetPhoneFilter(s);

            break;
        case 6:
            clients.ClearFilters();

            break;
        case 0:
            return;
        }
    }
}

void Admin::OperationsMenu()
{
    int choice;

    while (true)
    {
        INPUT
        (
            std::cout
            << "1. Показать операции\n"
            << "2. Отсортировать список операций\n"
            << "3. Применить фильтры поиска\n"
            << "4. Рассмотреть операцию\n"
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
            FilterOperationsMenu();
            break;
        case 4:
            HandleOperationTask();
            break;
        case 0:
            return;
        }
    }
}

void Admin::SortOperationsMenu()
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
            << "6. Сортировать по логину клиента\n"
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
                operations.Sort(OperationList::ByIDAscendingly);
            else
                operations.Sort(OperationList::ByIDDescendingly);

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
        case 6:
            if (order == 1)
                operations.Sort(OperationList::ByClientLoginAscendingly);
            else
                operations.Sort(OperationList::ByClientLoginDescendingly);

            break;
        case 0:
            return;
        }
    }
}

void Admin::FilterOperationsMenu()
{
    int choice, bound;
    std::string s;

    while (true)
    {
        INPUT_CONDITION
        (
            std::cout
            << "1. Фильтровать по типу\n"
            << "2. Фильтровать по статусу\n"
            << "3. Фильтровать по идентификационному номеру операции\n"
            << "4. Фильтровать по идентификационному номеру товара\n"
            << "5. Фильтровать по количеству товара\n"
            << "6. Фильтровать по логину клиента\n"
            << "7. Убрать все фильтры\n"
            << "0. Назад\n",
            choice,
            choice >= 0 and choice <= 7
        );

        if (choice != 0 and choice >= 3 and choice <= 5)
        {
            INPUT_CONDITION
            (
                std::cout
                << "1. Добавить минимум\n"
                << "2. Добавить максимум\n",
                bound,
                bound == 1 or bound == 2
            );
        }

        switch (choice)
        {
        case 1:
            INPUT_CONDITION
            (
                std::cout
                << "1. Импорт\n"
                << "2. Экспорт\n",
                choice,
                choice == 1 or choice == 2
            );

            if (choice == 1)
                operations.SetTypeFilter(Operation::Type::IMPORT);
            else
                operations.SetTypeFilter(Operation::Type::EXPORT);

            break;
        case 2:
            INPUT_CONDITION
            (
                std::cout
                << "1. Рассматривается\n"
                << "2. Отклонено\n"
                << "3. Одобрено\n",
                choice,
                choice >= 1 and choice <= 3
            );

            switch (choice)
            {
            case 1:
                operations.SetStatusFilter(Operation::Status::PENDING);
                break;
            case 2:
                operations.SetStatusFilter(Operation::Status::REJECTED);
                break;
            case 3:
                operations.SetStatusFilter(Operation::Status::APPROVED);
                break;
            }

            break;
        case 3:
            if (bound == 1)
            {
                INPUT
                (
                    std::cout << "Введите минимум: ",
                    choice
                );

                operations.SetIDFilterMin(choice);
            }
            else
            {
                INPUT
                (
                    std::cout << "Введите максимум: ",
                    choice
                );

                operations.SetIDFilterMax(choice);
            }

            break;
        case 4:
            if (bound == 1)
            {
                INPUT
                (
                    std::cout << "Введите минимум: ",
                    choice
                );

                operations.SetProductIDFilterMin(choice);
            }
            else
            {
                INPUT
                (
                    std::cout << "Введите максимум: ",
                    choice
                );

                operations.SetProductIDFilterMax(choice);
            }

            break;
        case 5:
            if (bound == 1)
            {
                INPUT
                (
                    std::cout << "Введите минимум: ",
                    choice
                );

                operations.SetProductAmountFilterMin(choice);
            }
            else
            {
                INPUT
                (
                    std::cout << "Введите максимум: ",
                    choice
                );

                operations.SetProductAmountFilterMax(choice);
            }

            break;
        case 6:
            std::cout << "Введите строку-фильтр: ";
            std::getline(std::cin, s);

            operations.SetClientLoginFilter(s);

            break;
        case 7:
            products.ClearFilters();

            break;
        case 0:
            return;
        }
    }
}

void Admin::HandleOperationTask()
{
    int choice;

    INPUT
    (
        std::cout << "Введите идентификационный номер операции\n",
        choice
    );

    std::shared_ptr<Operation> o;

    try
    {
        o = operations.GetElement(choice);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << "\n\n";
        return;
    }

    if (o->GetStatus() != Operation::Status::PENDING)
    {
        std::cout << "Эта операция уже рассмотрена\n\n";
        return;
    }

    INPUT_CONDITION
    (
        std::cout
        << "1. Одобрить\n"
        << "2. Отклонить\n",
        choice,
        choice == 1 or choice == 2
    );

    if (choice == 1)
        o->SetStatus(Operation::Status::APPROVED);
    else
        o->SetStatus(Operation::Status::REJECTED);

    operations.SaveToFile();        
}

void Admin::StorageMenu()
{
    int choice;

    while (true)
    {
        INPUT
        (
            std::cout
            << "1. Просмотреть склад\n"
            << "2. Добавить продукт\n"
            << "3. Отсортировать список продуктов\n"
            << "4. Применить фильтры поиска\n"
            << "5. Удалить продукт\n"
            << "6. Изменить продукт\n"
            << "0. Назад\n",
            choice
        );

        switch (choice)
        {
        case 1:
            products.ShowToConsole();
            break;
        case 2:
            AddProductTask();
            break;
        case 3:
            SortStorageMenu();
            break;
        case 4:
            FilterStorageMenu();
            break;
        case 5:
            DeleteProductTask();
            break;
        case 6:
            ChangeProductTask();
            break;
        case 0:
            return;
        }
    }
}

void Admin::AddProductTask()
{
    Product tempProduct;
    std::string input;
    int choice;

    input = StringInput("Введите название продукта: ");
    tempProduct.SetName(input);

    input = StringInput("Введите категорию продукта: ");
    tempProduct.SetCategory(input);

    INPUT_CONDITION
    (
        std::cout << "Введите количество: ",
        choice,
        choice >= 0
    );

    tempProduct.SetAmount(choice);

    INPUT_CONDITION
    (
        std::cout << "Введите цену за штуку: ",
        choice,
        choice >= 0
    );

    tempProduct.SetUnitPrice(choice);

    products.CalculateNewID(tempProduct);

    products.Add(tempProduct);

    products.SaveToFile();
}

void Admin::SortStorageMenu()
{
    int choice, order;

    while (true)
    {
        INPUT
        (
            std::cout
            << "1. Сортировать по идентификационному номеру\n"
            << "2. Сортировать по имени\n"
            << "3. Сортировать по категории\n"
            << "4. Сортировать по количеству\n"
            << "5. Сортировать по цене за штуку\n"
            << "6. Сортировать по стоимости\n"
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
                products.Sort(ProductList::ByIDAscendingly);
            else
                products.Sort(ProductList::ByIDDescendingly);

            break;
        case 2:
            if (order == 1)
                products.Sort(ProductList::ByNameAscendingly);
            else
                products.Sort(ProductList::ByNameDescendingly);

            break;
        case 3:
            if (order == 1)
                products.Sort(ProductList::ByCategoryAscendingly);
            else
                products.Sort(ProductList::ByCategoryDescendingly);

            break;
        case 4:
            if (order == 1)
                products.Sort(ProductList::ByAmountAscendingly);
            else
                products.Sort(ProductList::ByAmountDescendingly);

            break;
        case 5:
            if (order == 1)
                products.Sort(ProductList::ByUnitPriceAscendingly);
            else
                products.Sort(ProductList::ByUnitPriceDescendingly);

            break;
        case 6:
            if (order == 1)
                products.Sort(ProductList::ByTotalPriceAscendingly);
            else
                products.Sort(ProductList::ByTotalPriceDescendingly);

            break;
        case 0:
            return;
        }
    }
}

void Admin::FilterStorageMenu()
{
    int choice, bound;
    std::string s;

    while (true)
    {
        INPUT_CONDITION
        (
            std::cout
            << "1. Фильтровать по имени\n"
            << "2. Фильтровать по категории\n"
            << "3. Фильтровать по идентификационному номеру\n"
            << "4. Фильтровать по количеству\n"
            << "5. Фильтровать по цене за штуку\n"
            << "6. Фильтровать по стоимости\n"
            << "7. Убрать все фильтры\n"
            << "0. Назад\n",
            choice,
            choice >= 0 and choice <= 7
        );

        if (choice != 0)
        {
            if (choice >= 3 and choice <= 6)
            {
                INPUT_CONDITION
                (
                    std::cout
                    << "1. Добавить минимум\n"
                    << "2. Добавить максимум\n",
                    bound,
                    bound == 1 or bound == 2
                );
            }
            else if (choice != 7)
            {
                std::cout << "Введите строку-фильтр: ";
                std::getline(std::cin, s);
            }
        }

        switch (choice)
        {
        case 1:
            products.SetNameFilter(s);

            break;
        case 2:
            products.SetCategoryFilter(s);

            break;
        case 3:
            if (bound == 1)
            {
                INPUT
                (
                    std::cout << "Введите минимум: ",
                    choice
                );

                products.SetIDFilterMin(choice);
            }
            else
            {
                INPUT
                (
                    std::cout << "Введите максимум: ",
                    choice
                );

                products.SetIDFilterMax(choice);
            }

            break;

        case 4:
            if (bound == 1)
            {
                INPUT
                (
                    std::cout << "Введите минимум: ",
                    choice
                );

                products.SetAmountFilterMin(choice);
            }
            else
            {
                INPUT
                (
                    std::cout << "Введите максимум: ",
                    choice
                );

                products.SetAmountFilterMax(choice);
            }

            break;
        case 5:
            if (bound == 1)
            {
                INPUT
                (
                    std::cout << "Введите минимум: ",
                    choice
                );

                products.SetUnitPriceFilterMin(choice);
            }
            else
            {
                INPUT
                (
                    std::cout << "Введите максимум: ",
                    choice
                );

                products.SetUnitPriceFilterMax(choice);
            }

            break;
        case 6:
            if (bound == 1)
            {
                INPUT
                (
                    std::cout << "Введите минимум: ",
                    choice
                );

                products.SetTotalPriceFilterMin(choice);
            }
            else
            {
                INPUT
                (
                    std::cout << "Введите максимум: ",
                    choice
                );

                products.SetTotalPriceFilterMax(choice);
            }

            break;
        case 7:
            products.ClearFilters();

            break;
        case 0:
            return;
        }
    }
}

void Admin::DeleteProductTask()
{
    int ID;

    INPUT
    (
        std::cout << "Введите идентификационный номер продукта\n",
        ID
    );


    if (!products.Contains(ID))
    {
        std::cout << "Такого продукта нет\n\n";
        return;
    }

    products.Remove(ID);

    products.SaveToFile();
}

void Admin::ChangeProductTask()
{
    int ID;

    INPUT
    (
        std::cout << "Введите идентификационный номер продукта\n",
        ID
    );

    try
    {
        auto tempProduct = products.GetElement(ID);
        ChangeProductMenu(tempProduct);
        products.SaveToFile();
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl << std::endl;
    }
}

void Admin::ChangeProductMenu(std::shared_ptr<Product> product)
{
    int choice;
    std::string input;

    while (true)
    {
        INPUT
        (
            std::cout
            << "1. Изменить название\n"
            << "2. Изменить категорию\n"
            << "3. Изменить количество\n"
            << "4. Изменить цену за штуку\n"
            << "0. Назад\n",
            choice
        );

        switch (choice)
        {
        case 1:
            input = StringInput("Введите новое название продукта: ");

            product->SetName(input);
            break;
        case 2:
            input = StringInput("Введите новую категорию продукта: ");

            product->SetCategory(input);
            break;
        case 3:
            INPUT_CONDITION
            (
                std::cout << "Введите количество: ",
                choice,
                choice >= 0
            );

            product->SetAmount(choice);
            break;
        case 4:
            INPUT_CONDITION
            (
                std::cout << "Введите новую цену за штуку: ",
                choice,
                choice >= 0
            );

            product->SetUnitPrice(choice);
            break;
        case 0:
            return;
        }
    }
}

void Admin::AdminsMenu()
{
    int choice;

    while (true)
    {
        INPUT
        (
            std::cout
            << "1. Добавить администратора\n"
            << "2. Удалить администратора\n"
            << "0. Назад\n",
            choice
        );

        switch (choice)
        {
        case 1:
            AddAdminTask();
            break;
        case 2:
            RemoveAdminTask();
            break;
        case 0:
            return;
        }
    }
}

void Admin::AddAdminTask()
{
    std::string newLogin, newPassword;
    std::filesystem::path path{ ADMINS_FOLDER };
    
    newLogin = StringInput("Введите логин: ");

    for (auto const& dir_entry : std::filesystem::directory_iterator{ path })
    {
        if (newLogin == dir_entry.path().stem().string())
        {
            std::cout << "Логин занят";
            return;
        }
    }

    newPassword = MakePassword(StringInput("Введите пароль: "));

    std::ofstream file;
    file.open(ADMINS_FOLDER + newLogin + CRED_FILE_EXT);

    file << newLogin << " " << newPassword << "\n";

    file.close();
}

void Admin::RemoveAdminTask()
{
    std::string newLogin;
    std::filesystem::path path{ ADMINS_FOLDER };

    newLogin = StringInput("Введите логин: ");

    for (auto const& dir_entry : std::filesystem::directory_iterator{ path })
    {
        if (newLogin == dir_entry.path().stem().string())
        {
            std::filesystem::remove(dir_entry.path());
            return;
        }
    }

    std::cout << "Такого администратора нет\n\n";
}
