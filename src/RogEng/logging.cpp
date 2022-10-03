#include "logging.hpp"
#include <cstdarg>
#include <cstdio>
#include <filesystem>
#include <fstream>
#include <string>
#include <ctime>

namespace {
bool           LogToFile = false;
RE::Log::Level MinLevel = RE::Log::DEBUG;
const char*    LogLevelNames[] = {"DEBUG", "INFO", "WARNING", "FATAL"};
std::ofstream  LogFile;
} // namespace

const char* LogLevelToName_(RE::Log::Level level) {
  return LogLevelNames[level];
}
std::string GetFileName_(const char* path) {
  return std::filesystem::path(path).filename().string();
};
void RE::Log::SetLogToFile(bool LogToFile) { ::LogToFile = LogToFile; };
void RE::Log::SetMinLogLevel(RE::Log::Level MinLevel) {
  ::MinLevel = MinLevel;
};
void RE_::Log::Log(RE::Log::Level level, const char* source, int linenum,
                   const char* fmt, ...) {
  if (level < MinLevel) {
    return;
  }
  va_list args;
  va_start(args, fmt);
  std::printf("[ %s %s:%d ] ", LogLevelToName_(level),
              GetFileName_(source).c_str(), linenum);
  std::vprintf(fmt, args);
  va_end(args);
}
int RE_::Log::Initialize() { 
  std::time_t t = std::time(0);
  std::tm* now = std::localtime(&t);
  LogFile = std::ofstream("log-");
  return 0; 
}
