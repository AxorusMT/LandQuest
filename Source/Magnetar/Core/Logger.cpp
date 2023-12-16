#include "Magnetar/Core/Logger.hpp"
#include "fmt/format.h"
#include "fmt/color.h"

#include <format>
#include <chrono>
#include <fstream>
#include <filesystem>

Magnetar::Logger::Logger(bool shouldLogToFile) {
    this->shouldLogToFile = shouldLogToFile;
    logFilename = std::format("{:%Y-%m-%d_%X}.log", std::chrono::system_clock::now());

    if (this->shouldLogToFile) {
        [[likely]]
        
        if (!std::filesystem::exists("./OutputLogs")) {
            std::filesystem::create_directory("./OutputLogs");
        }

        logFilestream = std::ofstream("./OutputLogs/" + logFilename);
    }
}

Magnetar::Logger::~Logger() {
    logFilestream.close();
}

void Magnetar::Logger::blockLogLevels(const std::vector<LogLevel>& levels) {
    for (LogLevel level : levels) {
        switch (level) {
            case LogLevel::Info:
                this->infoEnabled = false;
                break;
            case LogLevel::Debug:
                this->debugEnabled = false;
                break;
            case LogLevel::Warn:
                this->warnEnabled = false;
                break;
            case LogLevel::Error:
                this->errorEnabled = false;
                break;
            case LogLevel::Fatal:
                this->fatalEnabled = false;
                break;
            default:
                break;
        }
    }
}

void Magnetar::Logger::unblockLogLevels(const std::vector<LogLevel>& levels) {
    for (LogLevel level : levels) {
        switch (level) {
            case LogLevel::Info:
                this->infoEnabled = true;
                break;
            case LogLevel::Debug:
                this->debugEnabled = true;
                break;
            case LogLevel::Warn:
                this->warnEnabled = true;
                break;
            case LogLevel::Error:
                this->errorEnabled = true;
                break;
            case LogLevel::Fatal:
                this->fatalEnabled = true;
                break;
            default:
                break;
        }
    }
}


void Magnetar::Logger::info(std::string message, std::source_location location) {
    std::string formattedMessage = std::format(
        "Info: [{}]: {} : {}\n", 
        std::chrono::system_clock::now(),
        std::format("{} in function {}:{}", location.file_name(), location.function_name(), location.line()),
        message
    );

    if (infoEnabled) {
        [[likely]]
        fmt::print(fg(fmt::color::gray), formattedMessage);
        if (shouldLogToFile) {
            [[likely]]
            logFilestream << formattedMessage;
        }
    }

}

void Magnetar::Logger::debug(std::string message, std::source_location location) {
    std::string formattedMessage = std::format(
        "Debug: [{}]: {} : {}\n", 
        std::chrono::system_clock::now(),
        std::format("{} in function {}:{}", location.file_name(), location.function_name(), location.line()),
        message
    );

    if (debugEnabled) {
        [[likely]]
        fmt::print(fg(fmt::color::blue), formattedMessage);
        if (shouldLogToFile) {
            [[likely]]
            logFilestream << formattedMessage;
        }
    }

    
}

void Magnetar::Logger::warn(std::string message, std::source_location location) {
    std::string formattedMessage = std::format(
        "Warning: [{}]: {} : {}\n", 
        std::chrono::system_clock::now(),
        std::format("{} in function {}:{}", location.file_name(), location.function_name(), location.line()),
        message
    );

    if (warnEnabled) {
        [[likely]]
        fmt::print(fg(fmt::color::yellow), formattedMessage);
        if (shouldLogToFile) {
            [[likely]]
            logFilestream << formattedMessage;
        }
    }

    
}

void Magnetar::Logger::error(std::string message, std::source_location location) {
    std::string formattedMessage = std::format(
        "Error: [{}]: {} : {}\n", 
        std::chrono::system_clock::now(),
        std::format("{} in function {}:{}", location.file_name(), location.function_name(), location.line()),
        message
    );

    if (errorEnabled) {
        [[likely]]
        fmt::print(fg(fmt::color::crimson), formattedMessage);
        if (shouldLogToFile) {
            [[likely]]
            logFilestream << formattedMessage;
        }
    }

    
}

void Magnetar::Logger::fatal(std::string message, std::source_location location) {
    std::string formattedMessage = std::format(
        "Fatal Error: [{}]: {} : {}\n", 
        std::chrono::system_clock::now(),
        std::format("{} in function {}:{}", location.file_name(), location.function_name(), location.line()),
        message
    );

    if (fatalEnabled) {
        [[likely]]
        fmt::print(fg(fmt::color::red) | fmt::emphasis::bold, formattedMessage);
        if (shouldLogToFile) {
            [[likely]]
            logFilestream << formattedMessage;
        }
    }

}

