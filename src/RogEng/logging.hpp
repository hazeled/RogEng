#pragma once

namespace RE_ {
enum LogLevel { DEBUG = 0, INFO, WARNING, FATAL };
// You probably won't need to use this, you should most likely use a define
// Formats with vsprintf
void Log(LogLevel    level,
         const char* source,  // File source, use __FILE__
         int         linenum, // Line number, use __LINE__
         const char* fmt, ...);
} // namespace RE_

#define RE__LOG_DEBUG(...)                                                     \
  RE_::Log(RE_::LogLevel::DEBUG, __FILE__, __LINE__, __VA_ARGS__)
#define RE__LOG_INFO(...)                                                      \
  RE_::Log(RE_::LogLevel::INFO, __FILE__, __LINE__, __VA_ARGS__)
#define RE__LOG_WARNING(...)                                                   \
  RE_::Log(RE_::LogLevel::WARNING, __FILE__, __LINE__, __VA_ARGS__)
#define RE__LOG_FATAL(...)                                                     \
  RE_::Log(RE_::LogLevel::FATAL, __FILE__, __LINE__, __VA_ARGS__)
