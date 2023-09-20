#include <iostream>

using namespace std;

class User {
private:
    std::string _name;
    std::string _id;
};

class Department {
private:
    std::string _name;
    std::string _id;
};

class IUser {
public:
    virtual void insert(User* user) = 0;
    virtual User* get_user(int id) = 0;
};

class IDepartment {
public:
    virtual void insert(Department* dept) = 0;
    virtual Department* get_department(int id) = 0;
};

class SqlserverUser : public IUser {
    void insert(User* user) override;
    User* get_user(int id) override;
};

class SqlserverDepartment : public IDepartment {
    void insert(Department* dept) override;
    Department* get_department(int id) override;
};

class AccessUser : public IUser {
    void insert(User* user) override;
    User* get_user(int id) override;
};

class AccessDepartment : public IDepartment {
    void insert(Department* dept) override;
    Department* get_department(int id) override;
};

class IFactory {
public:
    virtual IUser* create_user() = 0;
    virtual IDepartment* create_department() = 0;
};

class SqlserverFactory : public IFactory {
    SqlserverUser* create_user() override;
    SqlserverDepartment* create_department() override;
};

class AccessFactory : public IFactory {
    AccessUser* create_user() override;
    AccessDepartment* create_department() override;
};