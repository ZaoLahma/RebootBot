#include "config.h"
#include "config_if.h"
#include "config_value_types_enum.h"

#include <fstream>
#include <string>
#include <regex>

namespace rebootbot
{
    namespace config
    {
        ConfigIf::Config::Config(std::ifstream& configFile)
        {
            /* Match pattern key={type, value} */
            std::regex configRegex {"(\\w+)\\s*=\\s*\\{(\\w+),\\s*(.*)\\}\\s*"};

            std::string line;
            while (std::getline(configFile, line))
            {
                if (!('#' == line.at(0)))
                {
                    std::smatch regexMatch;
                    std::regex_search(line, regexMatch, configRegex);

                    if (regexMatch.size() == 4u)
                    {
                        const std::string key = regexMatch[1u];
                        const std::string typeStr = regexMatch[2u];
                        const std::string valueStr = regexMatch[3u];

                        ConfigValueTypesEnum type = ConfigValueStringUtils::fromString(typeStr);

                        switch (type)
                        {
                            case ConfigValueTypesEnum::STRING:
                            m_ConfigValues[key] = valueStr;
                            break;
                            case ConfigValueTypesEnum::INTEGER:
                            m_ConfigValues[key] = std::stoi(valueStr);
                            break;
                            default:
                            break;
                        }
                    }
                }
            }
        }

        ConfigValue ConfigIf::Config::getConfigValue(const std::string& configId) const
        {
            if (m_ConfigValues.end() != m_ConfigValues.find(configId))
            {
                return m_ConfigValues.at(configId);
            }

            return ConfigIf::INVALID_CONFIG_VALUE;
        }
    }
}