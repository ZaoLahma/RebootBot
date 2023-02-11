#pragma once
#include "zlog.h"

#include <memory>

#define STRING(x) STRING_INTERNAL(x)
#define STRING_INTERNAL(x) #x

#define FILE_LINE __FILE__ ":" STRING(__LINE__) " | "

#define LOG_ERROR(toLog, args...) logging::Log().getLogger().log(FILE_LINE toLog, args);

#ifdef DEBUG
    #define LOG_DEBUG(toLog, args...) logging::Log().getLogger().log(FILE_LINE "DEBUG - " toLog, args);
#else
    #define LOG_DEBUG(toLog, args...)
#endif

namespace rebootbot
{
    namespace logging
    {
        class Log
        {
            public:
            Log();
            zlog::ZLog& getLogger();

            protected:

            private:
            static std::shared_ptr<Log> getApi();
            static std::shared_ptr<Log> s_Instance;
            zlog::ZLog m_Logger;
        };
    }
}