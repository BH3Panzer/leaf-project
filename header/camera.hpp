#ifndef CAMERA
    #define CAMERA
    class Platform;
    class Player;


    struct Cameraz
    {
        float x = 0;
        float y = 0;
        int scale = 32;
    };

    void cameraFollowPlayer(Cameraz* cam, Player* p);
    void cameraFollowPlatform(Cameraz* cam, Platform* p);

#endif
