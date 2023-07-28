#pragma once

// cpp
#include <iostream>
#include <stdexcept>
#include <filesystem>
#include <map>

// plog
#include <plog/Initializers/RollingFileInitializer.h>
#include <plog/Initializers/ConsoleInitializer.h>
#include <plog/Log.h>

// Constants declaration
namespace ugly
{
	static const std::string ENGINE_NAME = "UglyEngine";
	static const std::string LOG_FILENAME = "UglyEngine.log";
}