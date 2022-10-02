#include "logging.hpp"
#include <cstdio>
#include <cstdarg>
#include <filesystem>

const char* LogLevelNames[] = { "DEBUG", "INFO", "WARNING", "FATAL" }; 

std::string GetFileName_(const char* path) {
  return std::filesystem::path(path).filename().string();
};

const char* LogLevelToName_(RE_::LogLevel level) {
  return LogLevelNames[level];
}

void RE_::Log (RE_::LogLevel level, const char* source, int linenum, const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  std::printf("[ %s %s:%d ] ", LogLevelToName_(level), GetFileName_(source).c_str(), linenum);
  std::vprintf(fmt, args);
  va_end(args);
}
