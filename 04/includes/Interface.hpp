#pragma once

#include <string>

class Interface
{
    Interface() = default;
    ~Interface() = default;

public:
    void run(const std::string&);

    static Interface& get_instance();
};