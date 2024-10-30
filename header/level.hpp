#ifndef LEVEL
    #define LEVEL

    #include "../header/platform.hpp"
    #include "../header/growingPlant.hpp"
    #include <vector>

    class Player;


    class Level
    {
        private:
            std::vector<Platform> platforms;
            std::vector<GrowingPlant> plants;
            Player* p;

        public:
            void addPlatform(Platform plat);
            void addPlant(GrowingPlant plant);
            void drawLevel();
            std::vector<Platform> getPlatforms();
            std::vector<GrowingPlant> getPlants();
            void handleInterract();
            Level(Player* p);
    };

    Level createLevel1(Cameraz* cam, Player* p);

#endif
