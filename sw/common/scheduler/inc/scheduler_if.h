#pragma once

#include <memory>

namespace rebootbot
{
    namespace scheduler
    {
        class SchedulerIf
        {
            public:
            SchedulerIf();
            ~SchedulerIf();

            protected:

            private:
            class Scheduler;
            std::unique_ptr<Scheduler> m_SchedulerImpl;
        };
    }
}