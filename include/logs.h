#pragma once

#include <iostream>

inline void logError(const std::string& tag, const std::string& message) {
	std::cout << "ERROR::" << tag << "::" << message << std::endl;
}
