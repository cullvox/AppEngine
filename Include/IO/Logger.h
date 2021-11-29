#pragma once

namespace AE
{

class Logger
{
public:
    Logger(const FString& path);
    ~Logger();

public:
    static void LogInfo(const FString& functionName, unsigned int line, const FString& message);
    static void LogWarning(const FString& functionName, unsigned int line, const FString& message);

    void LogInfo();
    void LogWarning();
    void LogError();
};

}