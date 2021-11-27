#pragma once

namespace AE
{

class Logger
{
public:
    Logger(const String& path);
    ~Logger();

public:
    static void LogInfo(const String& functionName, unsigned int line, const String& message);

    void LogInfo();
    void LogWarning();
    void LogError();
};

}