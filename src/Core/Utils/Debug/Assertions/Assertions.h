#ifndef ASSERTIONS_CLASS_H
#define ASSERTIONS_CLASS_H

#include <cstdio>
#include <iostream>
#include <ostream>
#include <windows.h>

#define CHECK(expression, message) \
Assertions::Assertions::Check(expression, message, __FILE__, __LINE__);

#define CHECK_MSG_LENGTH 256

namespace Assertions
{
    class Assertions
    {
    public:
        Assertions() = delete;

        static void Check(bool t_expr, const char* t_expr_str, const char* file, int line)
        {
            CheckImpl(t_expr, t_expr_str, file, line);
        }

    private:
        static void CheckImpl(bool t_expr, const char* t_expr_str, const char* file, int line)
        {
            if (!t_expr)
            {
                std::string errMsg = FormatAssertMessage(t_expr_str, file, line);

                { // if windows
                    std::wstring wide_str(errMsg.begin(), errMsg.end());
                    MessageBox(NULL, wide_str.c_str(), L"Assertion failed!", MB_OK);
                    exit(EXIT_FAILURE);
                }
            }
        }

        static std::string FormatAssertMessage(const char* t_expr_str, const char* file, int line)
        {
            char msg[CHECK_MSG_LENGTH];
            snprintf(msg, CHECK_MSG_LENGTH, "Assertion failed: %s\nFile: %s, Line: %d", t_expr_str, file, line);
            return std::string(msg);
        }
    };
}
#endif
