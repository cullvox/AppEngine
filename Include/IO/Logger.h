#pragma once

class Logger
{
public:
    Logger(const String& path);
    ~Logger();

public:
    void LogInfo();
    void LogWarning();
    void LogError();

};