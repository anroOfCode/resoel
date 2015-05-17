#include <base.h>
#include <gtest.h>
#include <Terminal\Console.h>

TEST(BasicAllocTests, AllocConsoleCalledOnce) {
    ReSoel::Win32FrontEnd::FreeConsole();

    ASSERT_EQ(ReSoel::Win32FrontEnd::AllocConsole(), TRUE);
    ASSERT_EQ(ReSoel::Win32FrontEnd::AllocConsole(), FALSE);
    ASSERT_EQ(GetLastError(), ERROR_ACCESS_DENIED);
}

TEST(BasicAllocTests, AllocFreeAlloc) {
    ReSoel::Win32FrontEnd::FreeConsole();

    ASSERT_EQ(ReSoel::Win32FrontEnd::FreeConsole(), FALSE);
    ASSERT_EQ(GetLastError(), ERROR_INVALID_PARAMETER);
    ASSERT_EQ(ReSoel::Win32FrontEnd::AllocConsole(), TRUE);
    ASSERT_EQ(ReSoel::Win32FrontEnd::FreeConsole(), TRUE);
    ASSERT_EQ(ReSoel::Win32FrontEnd::FreeConsole(), FALSE);
    ASSERT_EQ(GetLastError(), ERROR_INVALID_PARAMETER);
    ASSERT_EQ(ReSoel::Win32FrontEnd::AllocConsole(), TRUE);
    ASSERT_EQ(ReSoel::Win32FrontEnd::FreeConsole(), TRUE);
}

TEST(BasicAllocTests, AttachConsole) {
    ReSoel::Win32FrontEnd::FreeConsole();
    ASSERT_EQ(ReSoel::Win32FrontEnd::AttachConsole(ATTACH_PARENT_PROCESS), TRUE);
    ASSERT_EQ(ReSoel::Win32FrontEnd::FreeConsole(), TRUE);

    ASSERT_EQ(ReSoel::Win32FrontEnd::AttachConsole(1234), FALSE);
    ASSERT_EQ(GetLastError(), ERROR_GEN_FAILURE);
    ASSERT_EQ(ReSoel::Win32FrontEnd::FreeConsole(), FALSE);
    ASSERT_EQ(GetLastError(), ERROR_INVALID_PARAMETER);
}


