#ifndef LEVEL
    #define LEVEL

    #include "../header/platform.hpp"
    #include "../header/growingPlant.hpp"
    #include "../header/manaBloc.hpp"
    #include <vector>

    class Player;


    class Level
    {
        private:
            std::vector<Platform> platforms;
            std::vector<GrowingPlant> plants;
            std::vector<ManaBloc> manaBlocs;
            Player* p;
            Cameraz* cam;
            Texture2D* growingVineVertical;
            Texture2D* growingVineFLeftHorizontal;
            Texture2D* growingVineFRightHorizontal;
            Texture2D* manaBloc;
            Texture2D* getManaBloc;
            Texture2D* reloadManaBloc;
            Texture2D* reconstitutionManaBloc;
            bool finished = false;
            Rectangle end;
            Texture2D* texturesPlateformes;
            Texture2D* endLevel;

        public:
            void addPlatform(Platform plat);
            void addPlant(GrowingPlant plant);
            void addManaBloc(ManaBloc mBloc);
            void drawLevel();
            std::vector<Platform> getPlatforms();
            std::vector<GrowingPlant> getPlants();
            std::vector<ManaBloc> getManaBlocs();
            GrowingPlant* detectPlant();
            ManaBloc* detectManaBloc();
            Level();
            Level(Player* p, Cameraz* cam, Texture2D* gVV, Texture2D* gVFLH, Texture2D* gVFRH, Texture2D* MB, Texture2D* GMB, Texture2D* RLMB, Texture2D* RCMB, Texture2D* texturesPlateformes, Texture2D* endLevel);
            void actualisatePlant();
            void actualisateManaBlocs();
            Texture2D* getSprite(int n);
            bool isFinished();
            void finish();
            void unfinish();
            Rectangle getFinishRect();
            void setFinishRect(Rectangle rect);
            void checkLevelFinished();
    };

    Level createLevel(int numLevel, Cameraz* cam, Player* p, float* delta, Texture2D* gVV, Texture2D* gVFLH, Texture2D* gVFRH, Texture2D* MB, Texture2D* GMB, Texture2D* RLMB, Texture2D* RCMB, Texture2D* texturesPlateformes, Texture2D* endLevel);

#endif
