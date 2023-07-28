#pragma once

#include "core.h"

namespace ugly
{
    class engine
    {
        public:

            engine(const engine&) = delete;
            engine& operator=(const engine&) = delete;

            /**
             * \brief Get the instance of the engine.
             */
            static engine* get_instance()
            {
                if(!_instance)
                    _instance = new engine();
                return _instance;
            }

            /**
             * \brief Run the engine.
             */
            void run();

        private:

            /**
             * Constructor.
             */
            engine();

            /**
             * \brief Destructor.
             */
            virtual ~engine();

            /**
             * @brief Initialize plog.
             */
            void initialize_plog();
            
            /**
             * \brief Initialize engine.
             */
            void initialize();

            /**
             * \brief Shutdown engine.
             */
            void shutdown();

            /**
             * \brief Main loop.
             */
            void mainLoop();

        private:

            /*! Singleton instance */
            inline static engine* _instance {nullptr};

            /*! Window width */
            int _window_width {640};

            /*! Window width */
            int _window_height {480};
    };
}