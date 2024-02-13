#include "raylib.h"

int main(){
    //window
    const int windowHeight = 380;
    const int windowWidth = 512;

    InitWindow(windowWidth,windowHeight,"Dasher");
    //gravity
    const int gravity = 1;
    const int jump = (-22);
    bool isInAir;

    //Rect
    const int width = 50;
    const int height = 80;

    int posY = windowHeight - height;
    int velocity = 0;

    SetTargetFPS(60);
    while(!WindowShouldClose()){

         BeginDrawing();
         ClearBackground(WHITE);
            
            //ground check
            if(posY >= windowHeight-height){
                velocity = 0;
                isInAir = false;
            }else{
                 //apply gravity
            velocity+=gravity;
            isInAir = true;
            } 

            if(IsKeyPressed(KEY_SPACE) && !isInAir){
                 velocity=jump;
               }

            //jump position
            posY+=velocity;
            DrawRectangle(windowWidth/2,posY,width,height,BLUE);

         EndDrawing();
    }
    CloseWindow();
}