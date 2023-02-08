#pragma once

#include <cstdint>
#include <variant>
#include <string>
#include <fstream>
#include <memory>

namespace rebootbot
{
    namespace config
    {
        using ConfigValue = std::variant<uint32_t, int32_t, std::string>;

        class Config;
        
        class ConfigIf
        {
            public:
            static const ConfigValue INVALID_CONFIG_VALUE;

            ConfigIf(const std::ifstream& configFile);
            virtual ~ConfigIf() = default;

            virtual ConfigValue getConfigValue(const std::string& configId) const;

            protected:

            private:
            std::unique_ptr<Config> m_ConfigImpl;
        };
    }
}