#include "logging.hpp"
#include <cstdarg>
#include <cstdio>
#include <ctime>
#include <filesystem>
#include <fmt/core.h>
#include <fmt/os.h>
#include <fstream>
#include <string>

namespace {
RE::Log::Level minLevel = RE::Log::Level::DEBUG;
bool           logging = true;
const char*    LogLevelNames[] = {"DEBUG", "INFO", "WARNING", "FATAL"};
} // namespace

const char* LogLevelToName_(RE::Log::Level level) {
  return LogLevelNames[level];
}
std::string GetFileName_(const char* path) {
  return std::filesystem::path(path).filename().string();
};
void RE_::Log::Log(RE::Log::Level level, const char* source, int linenum,
                   const char* fmt, ...) {
  if (level <= minLevel || !logging) {
    return;
  }
  va_list args;
  va_start(args, fmt);
  fmt::print("[{}:{}] ({}) ", GetFileName_(source), linenum,
             LogLevelToName_(level));
  std::vprintf(fmt, args);
  va_end(args);
}
int RE_::Log::Initialize() {
  std::time_t t = std::time(0);
  std::tm*    now = std::localtime(&t);
  return 0;
}
void RE_::Log::Exit() {}
