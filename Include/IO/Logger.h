#pragma once

namespace AE
{

class Logger
{
public:
    Logger(const SString& path);
    ~Logger();

public:
    static void LogInfo(const SString& functionName, unsigned int line, const SString& message);

    void LogInfo();
    void LogWarning();
    void LogError();
};

}