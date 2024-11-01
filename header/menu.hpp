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
            Bar manaBar;
            Cameraz mainCamera;

        public:
            Menu();
            void drawMainMenu();
            void playFrame();
    };
#endif