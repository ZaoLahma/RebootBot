#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "scheduler_if.h"

class ScedulerTest : public ::testing::Test
{
    public:

    protected:

    virtual void SetUp()
    {
    }

    virtual void TearDown()
    {
    }
};

TEST_F(ScedulerTest, TestInstantiateScheduler)
{
    rebootbot::scheduler::SchedulerIf scheduler;
}