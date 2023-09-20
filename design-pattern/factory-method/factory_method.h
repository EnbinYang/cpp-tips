#ifndef FACTORY_METHOD_H
#define FACTORY_METHOD_H

class LeiFeng {
public:
    LeiFeng() {};
    void sweep();
    void wash();
    void buy_rice();
};

class ILeiFeng {
public:
    ILeiFeng() {};
    virtual LeiFeng* create_leifeng() const = 0;
};

class Undergradute : public LeiFeng {};

class Volunteer : public LeiFeng {};

class UndergraduteLeiFeng : public ILeiFeng {
public:
    UndergraduteLeiFeng() {};
    LeiFeng* create_leifeng() const override {
        return new Undergradute();
    }
};

class VolunteerLeiFeng : public ILeiFeng {
public:
    VolunteerLeiFeng() {};
    LeiFeng* create_leifeng() const override {
        return new Volunteer();
    }
};

#endif