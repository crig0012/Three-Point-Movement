#ifndef GAME_H
#define GAME_H

#include "../Screen Manager/Screen.h"
#include <vector>

//This is the Game class, add game objects and any
//game logic here. Inherits from Screen and must
//implement update(), paint() and getName()
class Game : public Screen
{
public:
    Game();
    ~Game();
    
    //Game lifecycle methods, inherited from Screen
    void update(double delta);
    void paint();
    void reset();
    
    //Returns the screen name, must be implemented,
    //it's a pure virtual method in the Screen class
    const char* getName();
    
private:
    //Mouse event methods, inherited from Screen
    virtual void mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY);
    virtual void mouseLeftClickDownEvent(float positionX, float positionY);
    virtual void mouseRightClickDownEvent(float positionX, float positionY);
    virtual void mouseLeftClickUpEvent(float positionX, float positionY);
    virtual void mouseRightClickUpEvent(float positionX, float positionY);
    
    //Key up and down event methods, inherited from Screen
    virtual void keyDownEvent(int keyCode);
    virtual void keyUpEvent(int keyCode);
    
    //Memer variables
    float m_StartingX;
    float m_StartingY;
    float m_TargetX;
    float m_TargetY;
    float m_TargetX2;
    float m_TargetY2;
    float m_TargetX3;
    float m_TargetY3;
    float m_CurrentX;
    float m_CurrentY;
    
    float m_Velocity;
    float m_Velocity2;
    float m_Velocity3;
    
    double m_Duration;
    double m_Duration2;
    double m_Duration3;
    
    float m_DeltaX;
    float m_DeltaY;
    float m_DeltaX2;
    float m_DeltaY2;
    float m_DeltaX3;
    float m_DeltaY3;
    
    bool m_Target1Hit;
    bool m_Target2Hit;
};

#endif