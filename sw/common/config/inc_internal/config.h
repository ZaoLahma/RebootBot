#pragma once

#include "config_if.h"

#include <map>
#include <fstream>
#include <string>

namespace rebootbot
{
    namespace config
    {
        class ConfigIf::Config
        {
            public:
            Config(std::ifstream& configFile);

            ConfigValue getConfigValue(const std::string& configId) const;

            protected:

            private:
            std::map<std::string, ConfigValue> m_ConfigValues;
        };
    }
}