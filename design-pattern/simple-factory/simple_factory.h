#ifndef SIMPLE_FACTORY_H
#define SIMPLE_FACTORY_H

class Operation {
public:
    virtual double get_result() const = 0;

    void set_number_first(double number) {
        _number_first = number;
    }

    void set_number_second(double number) {
        _number_second = number;
    }

protected:
    double _number_first;
    double _number_second;
};

class OperationAdd : public Operation {
public:
    double get_result() const override {
        return _number_first + _number_second;
    }
};

class OperationSub : public Operation {
public:
    double get_result() const override {
        return _number_first - _number_second;
    }
};

class OperationFactory {
public:
    static Operation* create_operation(const char operation);
};

#endif