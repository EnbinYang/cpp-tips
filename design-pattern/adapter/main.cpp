#include "play_adapter.h"

int main() {
    Player* james = new Forwards("James");
    james->attack();
    Player* curry = new Guards("Curry");
    curry->attack();

    Player* yao_ming = new Translator("Yao Ming");
    yao_ming->attack();
    yao_ming->defense();

    return 0;
}