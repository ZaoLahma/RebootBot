#include "log.h"

#include <memory>

namespace rebootbot
{
    namespace logging
    {
        std::shared_ptr<Log> Log::s_Instance {std::make_shared<Log>()};

        Log::Log()
        {

        }

        std::shared_ptr<Log> Log::getApi()
        {
            return s_Instance;
        }

        zlog::ZLog& Log::getLogger()
        {
            return getApi()->m_Logger;
        }
    }
}