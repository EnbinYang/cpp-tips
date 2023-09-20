#include "simple_factory.h"

Operation* OperationFactory::create_operation(const char operation) {
    Operation* op;

    switch (operation) {
    case '+':
        op = new OperationAdd();
        break;
    case '-':
        op = new OperationSub();
        break;
    }
    
    return op;
}