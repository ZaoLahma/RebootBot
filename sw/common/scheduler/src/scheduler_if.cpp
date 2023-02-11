#include "scheduler_if.h"
#include "scheduler.h"

#include <memory>

namespace rebootbot
{
    namespace scheduler
    {
        SchedulerIf::SchedulerIf() : m_SchedulerImpl {std::make_unique<Scheduler>()}
        {

        }

        SchedulerIf::~SchedulerIf()
        {
            m_SchedulerImpl = nullptr;
        }
    }
}