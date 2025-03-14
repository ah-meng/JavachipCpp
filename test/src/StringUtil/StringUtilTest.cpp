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


TEST(StringUtilTest, FormatByteSizeTest) {
    // Valid cases
    EXPECT_EQ(StringUtil::FormatByteSize(1024), "1.0 KB"); // Default decimal places (1)
    EXPECT_EQ(StringUtil::FormatByteSize(1536), "1.5 KB"); // Value with default decimal places
    EXPECT_EQ(StringUtil::FormatByteSize(1048576, 0), "1 MB"); // Custom decimal places
    EXPECT_EQ(StringUtil::FormatByteSize(1048576, 2), "1.00 MB"); // Custom decimal places
    EXPECT_EQ(StringUtil::FormatByteSize(1073741824, 3), "1.000 GB"); // Custom decimal places
    EXPECT_EQ(StringUtil::FormatByteSize(0), "0.0 byte"); // Zero value
    EXPECT_EQ(StringUtil::FormatByteSize(123456789, 1), "117.7 MB"); // Arbitrary value

    // Edge cases
    EXPECT_EQ(StringUtil::FormatByteSize(1), "1.0 byte"); // Minimal value
    EXPECT_EQ(StringUtil::FormatByteSize(999), "999.0 byte"); // Below 1 KB boundary

    // Invalid cases
    EXPECT_THROW(StringUtil::FormatByteSize(-1), std::invalid_argument); // Negative value
    EXPECT_THROW(StringUtil::FormatByteSize(-1024), std::invalid_argument); // Negative value at larger scale

    // Invalid precision
    EXPECT_THROW(StringUtil::FormatByteSize(1024, -1), std::invalid_argument); // Negative precision
    EXPECT_THROW(StringUtil::FormatByteSize(1024, -5), std::invalid_argument); // Arbitrary negative precision
}


TEST(StringUtilTest, TrimTest) {
    // Valid cases
    EXPECT_EQ(StringUtil::Trim("   hello   "), "hello"); // Leading and trailing spaces
    EXPECT_EQ(StringUtil::Trim("\t hello\t "), "hello"); // Leading and trailing tabs
    EXPECT_EQ(StringUtil::Trim("   hello world   "), "hello world"); // Multiple words with spaces
    EXPECT_EQ(StringUtil::Trim(""), ""); // Empty string
    EXPECT_EQ(StringUtil::Trim("   "), ""); // Only spaces
    EXPECT_EQ(StringUtil::Trim("\t   \t"), ""); // Only spaces and tabs

    // Edge cases
    EXPECT_EQ(StringUtil::Trim("hello"), "hello"); // No leading or trailing whitespace
    EXPECT_EQ(StringUtil::Trim("   hello"), "hello"); // Only leading whitespace
    EXPECT_EQ(StringUtil::Trim("hello   "), "hello"); // Only trailing whitespace
    EXPECT_EQ(StringUtil::Trim("\nhello\n"), "hello"); // Newline characters trimmed

    // Mixed whitespace
    EXPECT_EQ(StringUtil::Trim(" \n\t hello \n\t "), "hello"); // Mixed leading and trailing whitespace
}