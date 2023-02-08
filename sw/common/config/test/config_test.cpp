#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <fstream>

#include "config_if.h"

#define CONFIG_PATH "test.cfg"

class ConfigTest : public ::testing::Test
{
    public:

    protected:

    virtual void SetUp()
    {
        std::ofstream configFile(CONFIG_PATH);
        configFile<<"key={type, value}"<<std::endl; /* Good pattern? */
        configFile<<"#I am a comment"<<std::endl;
        configFile<<"#   I am also a comment"<<std::endl;
    }

    virtual void TearDown()
    {
        std::remove(CONFIG_PATH);
    }
};

TEST_F(ConfigTest, TestInstantiateConfig)
{
    auto configFile {std::ifstream(CONFIG_PATH)};
    rebootbot::config::ConfigIf configIf(configFile);
}