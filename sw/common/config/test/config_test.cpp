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
        configFile<<"anIntTestKey={integer, 32}"<<std::endl;
        configFile<<"#I am a comment"<<std::endl;
        configFile<<"#   I am also a comment"<<std::endl;
        configFile<<"aStringTestKey={string, SomeValueHere}"<<std::endl;
        configFile<<"aStringTestKeyWithSpace={string, SomeValueHere With spaces!}"<<std::endl;
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

TEST_F(ConfigTest, TestGetValue)
{
    auto configFile {std::ifstream(CONFIG_PATH)};
    rebootbot::config::ConfigIf configIf(configFile);

    auto intValue = configIf.getConfigValue("anIntTestKey");
    auto stringValue = configIf.getConfigValue("aStringTestKey");
    auto stringValueWithSpace = configIf.getConfigValue("aStringTestKeyWithSpace");
    auto invalidValue = configIf.getConfigValue("aNonExistingKey");

    EXPECT_EQ(32, std::get<int32_t>(intValue));
    EXPECT_EQ("SomeValueHere", std::get<std::string>(stringValue));
    EXPECT_EQ("SomeValueHere With spaces!", std::get<std::string>(stringValueWithSpace));
    EXPECT_EQ(rebootbot::config::ConfigIf::INVALID_CONFIG_VALUE, invalidValue);
}