#include "Headers.h"
#include "State.h"
#include "Init.h"
#include "Ready.h"
#include "Is_working.h"

bool Init::start(Navigator* navigator) {
    std::cout << "Start of initialize a Navigator" << std::endl;
    return true;
}

bool Init::stop(Navigator* navigator) {
    std::cout << "Initialize of Navigator is successes" << std::endl;
    navigator->changeStateTo(new Ready);
    return true;
}

bool Ready::start(Navigator* navigator) {
    std::cout << "Navigator is Ready" << std::endl;
    navigator->changeStateTo(new Is_working);
    return true;
}

bool Ready::stop(Navigator* navigator) {
    std::cout << "Navigator is not Ready" << std::endl;
    return false;
}

bool Is_working::start(Navigator* navigator) {
    std::cout << "Start of working is successes" << std::endl;
    return true;
}

bool Is_working::stop(Navigator* navigator) {
    std::cout << "Working of Navigator is successes" << std::endl;
    std::cout << "Stop of working..." << std::endl;
    navigator->changeStateTo(new Ready);
    return true;
}
