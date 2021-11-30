#include <iostream>

#include "fmt/format.h"

#include "IO/Logger.h"

FLogger::FLogger(const FString& path)
{
}

FLogger::~FLogger()
{
}

void FLogger::LogGeneral(const std::string& category, const std::string& functionName, unsigned int line, const std::string& message)
{
	fmt::printf("[ %s, %s, line (%i) ] | %s\n", category, functionName, line, message);
}

void FLogger::LogInfo(const std::string& functionName, unsigned int line, const std::string& message)
{
	FLogger::LogGeneral("INFO", functionName, line, message);
}

void FLogger::LogWarning(const FString& functionName, unsigned int line, const FString& message)
{
	FLogger::LogGeneral("WARN", functionName, line, message);
}

void FLogger::LogError(const FString& functionName, unsigned int line, const FString& message)
{
	FLogger::LogGeneral("ERRO", functionName, line, message);
}