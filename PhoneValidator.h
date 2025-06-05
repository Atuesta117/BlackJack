#pragma once
#include <string>

class PhoneValidator {
public:
    PhoneValidator(const std::string& apiKey);
    bool esNumeroValido(std::string& numero );
private:
    std::string apiKey;
};


