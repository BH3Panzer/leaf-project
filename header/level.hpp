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
            Cameraz* cam;
            Texture2D growingVineVertical;
            Texture2D growingVineFLeftHorizontal;
            Texture2D growingVineFRightHorizontal;

        public:
            void addPlatform(Platform plat);
            void addPlant(GrowingPlant plant);
            void drawLevel();
            std::vector<Platform> getPlatforms();
            std::vector<GrowingPlant> getPlants();
            GrowingPlant* detectPlant();
            Level(Player* p, Cameraz* cam, Image growingVine);
            void actualisatePlant();
            Texture2D* getSprite(int n);
    };

    Level createLevel1(Cameraz* cam, Player* p, float* delta, Image growingVine);

#endif
