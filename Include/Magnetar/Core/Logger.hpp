#pragma once
#include <source_location>
#include <string>
#include <vector>
#include <fstream>
#include <format>
#include <chrono>
// Logger Library

namespace Magnetar {
    // Will be instanciated, so no need for static methods
    
    enum class LogLevel {
        Info,
        Debug,
        Warn,
        Error,
        Fatal
    };

    class Logger {
        public:
            Logger(bool shouldLogToFile = true);
            ~Logger(); 

            void info(std::string message, std::source_location location = std::source_location::current());
            void debug(std::string message, std::source_location location = std::source_location::current());
            void warn(std::string message, std::source_location location = std::source_location::current());
            void error(std::string message, std::source_location location = std::source_location::current());
            void fatal(std::string message, std::source_location location = std::source_location::current());

            void blockLogLevels(const std::vector<LogLevel>& levels);
            void unblockLogLevels(const std::vector<LogLevel>& levels);
        private:
            bool shouldLogToFile = true;

            // May not want these to be const in the future, let users change them in app.
            const int maximumLogsAllowed = 7;
            const std::string logOutputDir = "./OutputLogs/";

            void deleteOldestLog();
            // filters
            bool infoEnabled = true;
            bool debugEnabled = true;
            bool warnEnabled = true;
            bool errorEnabled = true;
            bool fatalEnabled = true;

            std::string logFilename = std::format("{:%Y%m%d%H%M}.log", std::chrono::system_clock::now());
            std::ofstream logFilestream;
    };
}