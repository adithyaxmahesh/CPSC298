#include <iostream>

class CUltimateMachine {
public:
    CUltimateMachine() : m_bState(false) {
        std::cout << "CUltimateMachine constructor (ctor) called" << std::endl;
    }

    ~CUltimateMachine() {
        std::cout << "CUltimateMachine destructor (dtor) called" << std::endl;
    }

    void displayState() {
        if (m_bState) {
            std::cout << "Ultimate Machine is ON" << std::endl;
        } else {
            std::cout << "Ultimate Machine is OFF" << std::endl;
        }
    }

    void turnOn() {
        m_bState = true;
        displayState();
        turnOff(); // Turning the machine off immediately after it turns on
    }

private:
    void turnOff() {
        m_bState = false;
        displayState();
    }

    bool m_bState; // true(ON), false(OFF)
};

int main() {
    CUltimateMachine machine;
    machine.turnOn();

    return 0;
}
