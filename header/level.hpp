#ifndef LEVEL
    #define LEVEL

    #include "../header/platform.hpp"
    #include "../header/camera.hpp"
    #include <vector>

    class Level
    {
        private:
            std::vector<Platform> platformes;

        public:
            void addPlatform(Platform plat);
            void drawLevel();
    };

    extern Level level1;
    void createLevels(Cameraz &cam);

#endif
