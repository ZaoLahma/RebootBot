#pragma once

#include <string>

enum class ConfigValueTypesEnum
{
    STRING   = 0,
    INTEGER  = 1,
    UNKNOWN  = 2
};

class ConfigValueStringUtils
{
    public:
    static std::string toString(const ConfigValueTypesEnum value)
    {
        std::string retVal = "UNKNOWN";

        switch (value)
        {
            case ConfigValueTypesEnum::STRING:
            retVal = "string";
            break;
            case ConfigValueTypesEnum::INTEGER:
            retVal = "integer";
            break;

            default:
            break;
        }

        return retVal;
    }

    static ConfigValueTypesEnum fromString(const std::string& value)
    {
        ConfigValueTypesEnum retVal = ConfigValueTypesEnum::UNKNOWN;

        if ("string" == value)
        {
            retVal = ConfigValueTypesEnum::STRING;
        }
        else if ("integer" == value)
        {
            retVal = ConfigValueTypesEnum::INTEGER;
        }

        return retVal;
    }
};