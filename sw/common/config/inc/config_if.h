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

        class ConfigIf
        {
            public:
            static const ConfigValue INVALID_CONFIG_VALUE;

            ConfigIf() = delete;
            ConfigIf(std::ifstream& configFile);
            ~ConfigIf();

            ConfigValue getConfigValue(const std::string& configId) const;

            protected:

            private:
            class Config;
            std::unique_ptr<Config> m_ConfigImpl;
        };
    }
}