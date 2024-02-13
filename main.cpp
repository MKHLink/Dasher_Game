#include "raylib.h"

int main(){
    //window
    const int windowHeight = 380;
    const int windowWidth = 512;

    InitWindow(windowWidth,windowHeight,"Dasher");
    //gravity
    const int gravity = 1000;
    const int jump = (-600);
    bool isInAir;

    Texture2D scarfy = LoadTexture("textures/scarfy.png");
    Rectangle scarfyRec;
    scarfyRec.width = scarfy.width/6;
    scarfyRec.height = scarfy.height;
    scarfyRec.x = 0;
    scarfyRec.y = 0;
    Vector2 scarfyPos;
    scarfyPos.x = windowWidth/2 - scarfyRec.width/2;
    scarfyPos.y = windowHeight/2 - scarfyRec.height;

    //frame count for animation
    int frame = 0;
    const float updateTime = 1.0/12.0;
    float runningTime;


    int velocity = 0;

    SetTargetFPS(60);
    while(!WindowShouldClose()){

         BeginDrawing();
         ClearBackground(WHITE);

        //delta time 
         float dT = GetFrameTime();
         
            
            //ground check
            if(scarfyPos.y >= windowHeight-scarfyRec.height){
                velocity = 0;
                isInAir = false;
            }else{
                 //apply gravity
            velocity+=gravity*dT;
            isInAir = true;
            } 

            if(IsKeyPressed(KEY_SPACE) && !isInAir){
                 velocity=jump;
               }

            //jump position
            scarfyPos.y+=velocity*dT;

            //update scarfy animation frame by frame
            runningTime+=dT;
            if(runningTime>=updateTime){
                runningTime = 0.0;
                scarfyRec.x = frame*scarfyRec.width;
                frame++;
                if(frame>5){
                    frame = 0;
                }
            }

            
            DrawTextureRec(scarfy,scarfyRec,scarfyPos,WHITE);

         EndDrawing();
    }
    UnloadTexture(scarfy);
    CloseWindow();
}