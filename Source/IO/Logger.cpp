#include <iostream>

#include "fmt/format.h"

#include "IO/Logger.h"

namespace AE
{

FLogger::FLogger(const std::string& path)
{
}

FLogger::~FLogger()
{
}

void FLogger::LogGeneral(const std::string& category, const std::string& functionName, unsigned int line, const std::string& message)
{
	fmt::print("[ %s, %s, line (%i) ] | %s\n", category, functionName, line, message);
}

void FLogger::LogInfo(const std::string& functionName, unsigned int line, const std::string& message)
{
	FLogger::LogGeneral("INFO", functionName, line, message);
}

void FLogger::LogWarning(const std::string& functionName, unsigned int line, const std::string& message)
{
	FLogger::LogGeneral("WARN", functionName, line, message);
}

void FLogger::LogError(const std::string& functionName, unsigned int line, const std::string& message)
{
	FLogger::LogGeneral("ERRO", functionName, line, message);
}

}