#pragma once

namespace RE {
namespace Log {
enum Level { DEBUG = 0, INFO, WARNING, FATAL };
void SetLogging(int logging);
void SetMinLogLevel(RE::Log::Level level);
} // namespace Log
} // namespace RE

namespace RE_ {
namespace Log {
// You probably won't need to use this, you should most likely use a define
// Formats with vsprintf
void Log(RE::Log::Level level,
         const char*     source,  // File source, usually __FILE__
         int             linenum, // Line number, usually __LINE__
         const char*     fmt, ...);
int  Initialize();
void Exit();
} // namespace Log
} // namespace RE_

#define RE__LOG_DEBUG(...)                                                     \
  RE_::Log::Log(RE::Log::Level::DEBUG, __FILE__, __LINE__, __VA_ARGS__)
#define RE__LOG_INFO(...)                                                      \
  RE_::Log::Log(RE::Log::Level::INFO, __FILE__, __LINE__, __VA_ARGS__)
#define RE__LOG_WARNING(...)                                                   \
  RE_::Log::Log(RE::Log::Level::WARNING, __FILE__, __LINE__, __VA_ARGS__)
#define RE__LOG_FATAL(...)                                                     \
  RE_::Log::Log(RE::Log::Level::FATAL, __FILE__, __LINE__, __VA_ARGS__)
