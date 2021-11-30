#pragma once

#include <string>

#include "Macro.h"

namespace AE
{

class FLogger
{
public:
    FLogger(const std::string& path);
    ~FLogger();

public:
    static void LogInfo(const std::string& functionName, unsigned int line, const std::string& message);
    static void LogWarning(const std::string& functionName, unsigned int line, const std::string& message);
    static void LogError(const std::string& functionName, unsigned int line, const std::string& message);
};

#define LOG_INFO(message) FLogger::LogInfo(AE_FUNCTION_NAME, AE_LINE, message)
#define LOG_WARNING(message) FLogger::LogWarning(AE_FUNCTION_NAME, AE_LINE, message)
#define LOG_ERROR(message) FLogger::LogError(AE_FUNCTION_NAME, AE_LINE, message)

}