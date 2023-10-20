#ifndef PLAY_ADAPTER_H
#define PLAY_ADAPTER_H

#include <string>

class Player {
public:
    Player() = default;

    explicit Player(std::string name) : _name(name) {}

    virtual void attack() = 0;

    virtual void defense() = 0;

protected:
    std::string _name;
};

class Forwards : public Player {
public:
    explicit Forwards(const std::string& name) : Player(name) {}

    void attack() override;

    void defense() override;
};

class Center : public Player {
public:
    explicit Center(const std::string& name) : Player(name) {}

    void attack() override;

    void defense() override;
};

class Guards : public Player {
public:
    explicit Guards(const std::string& name) : Player(name) {}

    void attack() override;

    void defense() override;
};

class ForeignCenter {
public:
    void set_name(const std::string& name);

    std::string get_name();

    void cn_attack();

    void cn_defense();

private:
    std::string _name;
};

class Translator : public Player {
public:
    explicit Translator(const std::string& name);

    void attack() override;

    void defense() override;

private:
    ForeignCenter _foreign_center;
};

#endif // PLAY_ADAPTER_H