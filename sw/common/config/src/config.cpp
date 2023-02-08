#include "config.h"

namespace rebootbot
{
    namespace config
    {
        ConfigValue Config::getConfigValue(const std::string& configId) const
        {
            if (m_ConfigValues.end() != m_ConfigValues.find(configId))
            {
                return m_ConfigValues.at(configId);
            }

            return ConfigIf::INVALID_CONFIG_VALUE;
        }
    }
}