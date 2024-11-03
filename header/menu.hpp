#ifndef MENU
    #define MENU
    
    #include "../header/imageImportation.hpp"
    #include "../header/guiBar.hpp"
    #include "../header/player.hpp"

    class Menu
    {
        private:
            //Texture2D screenMainMenu;
            float delta;
            Player player;
            Level level;
            int levelNumber;
            Bar manaBar;
            Cameraz mainCamera;

            Texture2D screenLoading;
            Texture2D screenMainMenu;
            Texture2D growingVineVertical;
            Texture2D growingVineFLeftHorizontal;
            Texture2D growingVineFRightHorizontal;
            Texture2D manaBloc;
            Texture2D getManaBloc;
            Texture2D reloadManaBloc;
            Texture2D reconstitutionManaBloc;
            Texture2D texturesPlateformes;
            Texture2D endLevel;

        public:
            Menu(Image screenMainMenu, Image screenLoading, Image growingVine, Image manaBloc, Image getManaBloc, Image reloadManaBloc, Image reconstitutionManaBloc, Image texturesPlateformes, Image endLevel, int levelNumber);
            void drawMainMenu();
            void playFrame();
            void drawLoadingScreen();
            void handleLevels();
    };
#endif
