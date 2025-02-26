//
// Created by 이채호 on 25. 2. 27.
//

#include <gtest/gtest.h>
#include <StringUtil/StringUtil.h>
TEST(StringUtilTest, DecimalToHexStringTest)
{
    EXPECT_EQ(StringUtil::DecimalToHexString(0), "0");
    EXPECT_EQ(StringUtil::DecimalToHexString(9), "9");
    EXPECT_EQ(StringUtil::DecimalToHexString(10), "a");
    EXPECT_EQ(StringUtil::DecimalToHexString(15), "f");
    EXPECT_EQ(StringUtil::DecimalToHexString(16), "10");
    EXPECT_EQ(StringUtil::DecimalToHexString(255), "ff");
    EXPECT_EQ(StringUtil::DecimalToHexString(256), "100");
    EXPECT_EQ(StringUtil::DecimalToHexString(4095), "fff");
    EXPECT_EQ(StringUtil::DecimalToHexString(65535), "ffff");
    EXPECT_EQ(StringUtil::DecimalToHexString(-1), "ffffffff");
    // Assuming it handles unsigned integers or two's complement representation
}
