#include "Game.h"
#include "../OpenGL/OpenGL.h"
#include "../Constants/Constants.h"
#include "../Utils/Utils.h"
#include "../Screen Manager/ScreenManager.h"


Game::Game()
{
    m_StartingX = 10.0f;
    m_StartingY = 400.0f;
    m_TargetX = 10.0f;
    m_TargetY = 10.0f;
    m_TargetX2 = 450.0f;
    m_TargetY2 = 600.0f;
    m_TargetX3 = 750.0f;
    m_TargetY3 = 220.0f;
    m_CurrentX = m_StartingX;
    m_CurrentY = m_StartingY;
    m_Duration = 5.0;
    m_Duration = 2.5;
    m_Duration = 4.0;
    
    m_Target1Hit = false;
    m_Target2Hit = false;
    
    float distance = MathUtils::distance(m_StartingX, m_StartingY, m_TargetX, m_TargetY);
    m_Velocity = distance / m_Duration;
    
    float distance2 = MathUtils::distance(m_TargetX, m_TargetY, m_TargetX2, m_TargetY2);
    m_Velocity2 = distance2 / m_Duration;
    
    float distance3 = MathUtils::distance(m_TargetX2, m_TargetY2, m_TargetX3, m_TargetY3);
    m_Velocity3 = distance3 / m_Duration;
    
    float distanceX = fabsf(m_TargetX - m_StartingX);
    float distanceY = fabsf(m_TargetY - m_StartingY);
    float maxDistance = fmaxf(distanceX, distanceY);
    
    float distanceX2 = fabsf(m_TargetX2 - m_TargetX);
    float distanceY2 = fabsf(m_TargetY2 - m_TargetY);
    float maxDistance2 = fmaxf(distanceX2, distanceY2);
    
    float distanceX3 = fabsf(m_TargetX3 - m_TargetX2);
    float distanceY3 = fabsf(m_TargetY3 - m_TargetY2);
    float maxDistance3 = fmaxf(distanceX3, distanceY3);
    
    m_DeltaX = distanceX / maxDistance;
    m_DeltaY = distanceY / maxDistance;
    
    m_DeltaX2 = distanceX2 / maxDistance2;
    m_DeltaY2 = distanceY2 / maxDistance2;
    
    m_DeltaX3 = distanceX3 / maxDistance3;
    m_DeltaY3 = distanceY3 / maxDistance3;
}

Game::~Game()
{
    
}

void Game::update(double delta)
{
    //Process game logic here
    if(m_Target1Hit == false)
    {
        if(m_CurrentX < m_TargetX)
        {
            float distance = m_Velocity * delta;
            m_CurrentX += distance * m_DeltaX;
        }
    
        else
        {
            m_CurrentX = m_TargetX;
        }
    
        if(m_CurrentY > m_TargetY)
        {
            float distance = m_Velocity * delta;
            m_CurrentY -= distance * m_DeltaY;
        }
        else
        {
            m_CurrentY = m_TargetY;
        }
        
        if(m_CurrentX == m_TargetX && m_CurrentY == m_TargetY)
        {
            m_Target1Hit = true;
        }
    }
    
    if (m_Target1Hit == true && m_Target2Hit == false)
    {
        if(m_CurrentX < m_TargetX2)
        {
            float distance = m_Velocity2 * delta;
            m_CurrentX += distance * m_DeltaX2;
        }
        
        else
        {
            m_CurrentX = m_TargetX2;
        }
        
        if(m_CurrentY < m_TargetY2)
        {
            float distance = m_Velocity2 * delta;
            m_CurrentY += distance * m_DeltaY2;
        }
        else
        {
            m_CurrentY = m_TargetY2;
        }
        
        if(m_CurrentX == m_TargetX2 && m_CurrentY == m_TargetY2)
        {
            m_Target2Hit = true;
        }
    }
    
    if (m_Target1Hit == true && m_Target2Hit == true)
    {
        if(m_CurrentX < m_TargetX3)
        {
            float distance = m_Velocity3 * delta;
            m_CurrentX += distance * m_DeltaX3;
        }
        
        else
        {
            m_CurrentX = m_TargetX3;
        }
        
        if(m_CurrentY > m_TargetY3)
        {
            float distance = m_Velocity3 * delta;
            m_CurrentY -= distance * m_DeltaY3;
        }
        else
        {
            m_CurrentY = m_TargetY3;
        }
    }
    
}

void Game::paint()
{
    OpenGLRenderer::getInstance()->setForegroundColor(OpenGLColorGreen());
    OpenGLRenderer::getInstance()->drawCircle(m_StartingX, m_StartingY, 5.0f);
    
    OpenGLRenderer::getInstance()->setForegroundColor(OpenGLColorWhite());
    OpenGLRenderer::getInstance()->drawCircle(m_TargetX, m_TargetY, 5.0f);
    OpenGLRenderer::getInstance()->drawCircle(m_TargetX2, m_TargetY2, 5.0f);
    OpenGLRenderer::getInstance()->drawCircle(m_TargetX3, m_TargetY3, 5.0f);
    
    OpenGLRenderer::getInstance()->setForegroundColor(OpenGLColorOrange());
    OpenGLRenderer::getInstance()->drawCircle(m_CurrentX, m_CurrentY, 10.0f);
}

void Game::reset()
{
    //Reset all game data here
}

const char* Game::getName()
{
	return GAME_SCREEN_NAME;
}

void Game::mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY)
{
    //Handle mouse movement events here
}

void Game::mouseLeftClickDownEvent(float positionX, float positionY)
{
    //Handle mouse left click down events here
}

void Game::mouseRightClickDownEvent(float positionX, float positionY)
{
    //Handle mouse right click down events here
}

void Game::mouseLeftClickUpEvent(float positionX, float positionY)
{
    //Handle mouse left click up events here
}

void Game::mouseRightClickUpEvent(float positionX, float positionY)
{
    //Handle mouse right click up events here
}

void Game::keyDownEvent(int keyCode)
{
    //Handle keyboard down events here
}

void Game::keyUpEvent(int keyCode)
{
    //Handle keyboard up events here
}







