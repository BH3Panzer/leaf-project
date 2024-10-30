#ifndef CAMERA
    #define CAMERA
    class Platform;
    class Player;


    struct Cameraz
    {
        float x = 0;
        float y = 0;
        int scale = 3;
        float velX = 0;
        float velY = 0;
    };

    void cameraFollowPlayer(Cameraz* cam, Player* p);
    void cameraFollowPlatform(Cameraz* cam, Platform* p);
    void cameraMove(Cameraz* cam, float& delta);
    void cameraSetScale(Cameraz* cam, int q);
    void cameraDebugTest(Cameraz* cam);

#endif
