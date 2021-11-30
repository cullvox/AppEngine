#include "stdio.h"

#include "IO/Logger.h"

FLogger::FLogger(const FString& path)
{

}

FLogger::~FLogger()
{

}

void FLogger::LogInfo(const FString& functionName, unsigned int line, const FString& message)
{

	FString log;
	log .Append("[ INFO, ")
		.Append(functionName)
		.Append(", line (")
		.Append(FString::ToString(line))
		.Append(") ] |")
		.Append(message)
		.Append("\n");

	printf("%s", log);

}

void FLogger::LogWarning(const FString& functionName, unsigned int line, const FString& message)
{

	FString log;
	log .Append("[ WARN, ")
		.Append(functionName)
		.Append(", line (")
		.Append(FString::ToString(line))
		.Append(") ] |")
		.Append(message)
		.Append("\n");

	printf("%s", log);

}

void FLogger::LogError(const FString& functionName, unsigned int line, const FString& message)
{

	FString log;
	log .Append("[ EROR, ")
		.Append(functionName)
		.Append(", line (")
		.Append(FString::ToString(line))
		.Append(") ] |")
		.Append(message)
		.Append("\n");

	printf("%s", log);

}