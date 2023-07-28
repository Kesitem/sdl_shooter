#include "engine.h"
#include "log_formatter.h"
#include "config.h"


ugly::engine::engine()
{
    initialize_plog();

    auto path = std::filesystem::current_path();
    LOG_INFO << "Current path: " << path.c_str();
}


ugly::engine::~engine()
{
}


void ugly::engine::run()
{
    try
    {
        initialize();
    }
    catch(const std::runtime_error& e)
    {
        LOG_ERROR << e.what();
        shutdown();
        return;
    }
    
    try
    {
        mainLoop();
    }
    catch(const std::runtime_error& e)
    {
        LOG_ERROR << e.what();
    }
    
    shutdown();
}


void ugly::engine::initialize_plog()
{
    // Remove log file if exists
    struct stat buffer;
    if (stat(LOG_FILENAME.c_str(), &buffer) == 0)
    {
        if (remove(LOG_FILENAME.c_str()) != 0)
        {
            LOG_ERROR << "Cannnot remove log file";
        }
    }

    // Create log
    static plog::RollingFileAppender<plog::log_formatter> file_appender(LOG_FILENAME.c_str(), 0, 0);
    static plog::ConsoleAppender<plog::log_formatter> console_appender;

    plog::init(plog::debug, &console_appender).addAppender(&file_appender);

    PLOG_INFO << "----- UglyEngine Log";
    PLOG_INFO << "----- Version: " << ugly::version::FULLVERSION_STRING;
}



void ugly::engine::initialize()
{

    LOG_INFO << "Initialize engine";
}



void ugly::engine::shutdown()
{
    LOG_INFO << "Shutdown engine";
}


void ugly::engine::mainLoop()
{
    LOG_INFO << "Enter main loop";
}