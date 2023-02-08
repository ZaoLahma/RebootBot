#include "config_if.h"
#include "config.h"

#include <fstream>
#include <memory>

namespace rebootbot
{
    namespace config
    {
        /* Static initializations */
        const ConfigValue ConfigIf::INVALID_CONFIG_VALUE = "INVALID_CONFIG_VALUE";

        /* "The rest" */
        ConfigIf::ConfigIf(const std::ifstream& configFile) : m_ConfigImpl {std::make_unique<Config>(configFile)}
        {
        }

        ConfigValue ConfigIf::getConfigValue(const std::string& configId) const
        {
            return m_ConfigImpl->getConfigValue(configId);
        }
    }
}