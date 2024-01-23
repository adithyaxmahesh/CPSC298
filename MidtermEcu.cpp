#include <iostream>

class EngineControlUnit {
private:
    bool autoJackActive;
    bool gripTiresActive;
    bool infraRedLightsActive;

public:
    EngineControlUnit() : autoJackActive(false), gripTiresActive(false), infraRedLightsActive(false) {
        std::cout << "ECU Initialized" << std::endl;
    }

    ~EngineControlUnit() {
        std::cout << "ECU Shutting Down" << std::endl;
    }

    void activateFunctionA() {
        if (!gripTiresActive) {
            autoJackActive = true;
            std::cout << "Auto-jack activated" << std::endl;
        } else {
            std::cout << "Cannot activate Auto-jack while Grip Tires are active" << std::endl;
        }
    }

    void activateFunctionB() {
        if (!autoJackActive) {
            gripTiresActive = true;
            std::cout << "Grip Tires activated" << std::endl;
        } else {
            std::cout << "Grip Tires activated with Auto-jack" << std::endl;
        }
    }

    void activateFunctionE() {
        infraRedLightsActive = true;
        std::cout << "Infra-Red Lights activated" << std::endl;
    }
};

int main() {
    EngineControlUnit ecu;
    ecu.activateFunctionA(); 
    ecu.activateFunctionB();
    ecu.activateFunctionE();

    return 0;
}
