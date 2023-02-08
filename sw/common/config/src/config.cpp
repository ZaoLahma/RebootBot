#include "config.h"
#include "config_if.h"

#include <fstream>
#include <string>
#include <iostream>
#include <regex>

namespace rebootbot
{
    namespace config
    {
        ConfigIf::Config::Config(std::ifstream& configFile)
        {
            /* Match pattern key={type, value} */
            std::regex configRegex {"(\\w+)\\s*=\\s*\\{(\\w+),\\s*(\\w+)\\}\\s*"};

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
                        const std::string type = regexMatch[2u];
                        const std::string value = regexMatch[3u];

                        std::cout<<key<<std::endl;
                        std::cout<<type<<std::endl;
                        std::cout<<value<<std::endl;

                        /* TODO Parse the extracted config payload (type & value) and insert at m_ConfigValues[key] */
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