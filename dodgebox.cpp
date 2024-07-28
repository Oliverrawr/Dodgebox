
#include "raylib.h"

int main() 
{ 

    // Window settings
    int width{800};
    int height{450};
    InitWindow(width, height, "Oliver");

    // Rectangle settings
    int rectangleX = 400;
    int rectangleY = 0;
    int rectangleWidth = 50;
    int rectangleHeight = 50;

    // Rectangle Direction
    int directionX{10};
    int directionY{10};

    //Circle settings
    int circleX = 200;
    int circleY = 200;
    int radius = 25;

  

    // Game Settings
    SetTargetFPS(60);

    // Main Game
    while(WindowShouldClose() == false)
    {

    //Circle Collision
    int circleL{circleX - radius};
    int circleR{circleX + radius};
    int circleU{circleY - radius};
    int circleD{circleY + radius};

    //Rectangle Collision
    int rectangleL{rectangleX - rectangleWidth};
    int rectangleR{rectangleX + rectangleWidth};
    int rectangleU{rectangleY - rectangleHeight};
    int rectangleD{rectangleY + rectangleHeight};

    // Collision with Axe
    bool collisionWithAxe
    {rectangleD >= circleU &&
     rectangleU <= circleD &&
     rectangleL <= circleR &&
     rectangleR >= circleL};


        BeginDrawing();
        ClearBackground(WHITE);

        if(collisionWithAxe == true)
        {
            DrawText("Game Over!", 400, 200, 20, RED);
        }
        else
        {
        
            
        // Game Logic Start
        DrawCircle( circleX, circleY, radius, RED);
        DrawRectangle (rectangleX, rectangleY, rectangleWidth, rectangleHeight, RED);

        //Move the axe
        rectangleX += directionX;
        rectangleY += directionY;
        
        if( rectangleX >= width - rectangleWidth || rectangleX < 0)
        {
            directionX = -directionX;
        }
        if(rectangleY > height - rectangleHeight || rectangleY < 0)
        {
            directionY = -directionY;
        }
        
        


        // RIGHT
        if(IsKeyDown(KEY_D) && circleR <= width)
        {
            circleX += 10;
        }
            // LEFT
            if(IsKeyDown(KEY_A) && circleL >= 0)
            {
                circleX -= 10;
            }
                // DOWN
                if(IsKeyDown(KEY_S) && circleD<= height)
                {
                    circleY += 10;
                }
                    // UP
                    if(IsKeyDown(KEY_W) && circleU >= 0)
                    {
                        circleY -= 10;
                    }


        // Game Logic End

        }
        EndDrawing();
        


        
    }


}