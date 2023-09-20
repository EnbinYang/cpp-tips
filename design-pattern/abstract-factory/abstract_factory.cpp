#include <iostream>

#include "abstract_factory.h"

using namespace std;

void SqlserverUser::insert(User* user) {
    std::cout << "Insert a record to Table User in SQL Server" << std::endl;
}

User* SqlserverUser::get_user(int id) {
    std::cout << "Get a record from Table User by ID in SQL Server" << std::endl;
    return nullptr;
}

void AccessUser::insert(User* user) {
    std::cout << "Insert a record to Table User in Access" << std::endl;
}

User* AccessUser::get_user(int id) {
    std::cout << "Get a record from Table User by ID in Access" << std::endl;
    return nullptr;
}

void SqlserverDepartment::insert(Department* dept) {
    std::cout << "Insert a record to Table Department in SQL Server" << std::endl;
}

Department* SqlserverDepartment::get_department(int id) {
    std::cout << "Get a record from Table Department by ID in SQL Server" << std::endl;
    return nullptr;
}

void AccessDepartment::insert(Department* dept) {
    std::cout << "Insert a record to Table Department in Access" << std::endl;
}

Department* AccessDepartment::get_department(int id) {
    std::cout << "Get a record from Table Department by ID in Access" << std::endl;
    return nullptr;
}

SqlserverUser* SqlserverFactory::create_user() {
    return new SqlserverUser();
}

SqlserverDepartment* SqlserverFactory::create_department() {
    return new SqlserverDepartment();
}

AccessUser* AccessFactory::create_user() {
    return new AccessUser();
}

AccessDepartment* AccessFactory::create_department() {
    return new AccessDepartment();
}