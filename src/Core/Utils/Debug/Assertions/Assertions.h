#ifndef ASSERTIONS_CLASS_H
#define ASSERTIONS_CLASS_H

#include <cstdio>
#include <iostream>
#include <ostream>
#include "./../../../Data/String.h"

#if PLATFORM_WINDOWS
#include <windows.h>
#endif

#define CHECK(expression, message) \
Assertions::Assertions::Check(expression, message, __FILE__, __LINE__);

#define CHECK_MSG_LENGTH 256

namespace Assertions
{
    class Assertions
    {
    public:
        Assertions() = delete;

        static void Check(bool t_expr, const core::String& t_expr_str, const core::String& file, int line)
        {
            CheckImpl(t_expr, t_expr_str, file, line);
        }

    private:
        static void CheckImpl(bool t_expr, const core::String& t_expr_str, const core::String& file, int line)
        {
            if (!t_expr)
            {
                core::String errMsg = FormatAssertMessage(t_expr_str, file, line);

                #if PLATFORM_WINDOWS
                {
                    MessageBox(NULL, std::wstring(errMsg.Begin(), errMsg.End()).c_str(), L"Assertion failed!", MB_OK);
                    exit(EXIT_FAILURE);
                }
                #endif
            }
        }

        static core::String FormatAssertMessage(const core::String& t_expr_str, const core::String& file, int line)
        {
            char msg[CHECK_MSG_LENGTH];
            snprintf(msg, CHECK_MSG_LENGTH, "Assertion failed: %s\nFile: %s, Line: %d", t_expr_str.GetData(), file.GetData(), line);
            return core::String(msg);
        }
    };
}
#endif
