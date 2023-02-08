#pragma once

#include "config_if.h"

#include <map>
#include <fstream>
#include <string>

namespace rebootbot
{
    namespace config
    {
        class Config : public ConfigIf
        {
            public:
            Config(const std::ifstream& configFile);

            ConfigValue getConfigValue(const std::string& configId) const override;

            protected:

            private:
            std::map<std::string, ConfigValue> m_ConfigValues;
        };
    }
}