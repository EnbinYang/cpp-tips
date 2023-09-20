#include <iostream>

#include "abstract_factory.h"

using namespace std;

int main() {
    User* user = new User();
    Department* dept = new Department();

    IFactory* factory = new SqlserverFactory();

    IUser* i_user = factory->create_user();
    i_user->insert(user);
    i_user->get_user(10);

    IDepartment* i_dept = factory->create_department();
    i_dept->insert(dept);
    i_dept->get_department(10);

    return 0;
}