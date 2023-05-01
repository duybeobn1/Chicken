/**
@file Chicken.h
@brief Contains the definition of the Chicken class and related constants.
*/
#ifndef CHICKEN_H_
#define CHICKEN_H_

#include <vector>
#include "Global.h"
#include "Bullet.h"
#include "Explode.h"
/**

@brief The width of the chicken sprite.
This constant represents the width of the chicken sprite in the game. It is used to set the initial size of the chicken and for collision detection.
*/
#define WIDTH_CHICKEN 75
/**

@brief The height of the chicken sprite.
This constant represents the height of the chicken sprite in the game. It is used to set the initial size of the chicken and for collision detection.
*/
#define HEIGHT_CHICKEN 68
/**

@brief The movement speed of the chicken.
This constant represents the movement speed of the chicken in the game. It is used to update the chicken's position each frame.
*/
#define CHICKEN_SPEED 1
/**

@brief The movement speed of the chicken's bullets.
This constant represents the movement speed of the chicken's bullets in the game. It is used to update the position of the chicken's bullets each frame.
*/
#define CHICKEN_BULLET_SPEED 1
/**

@brief The number of hearts the chicken has.
This constant represents the number of hearts the chicken has in the game. When the chicken's heart reaches zero, the chicken dies.
*/
#define CHICKEN_HEART 2
/**

@class Chicken
@brief Represents the chicken character in the game.
The Chicken class contains information about the chicken's position, status, and health. It also provides methods to update the chicken's position and health, as well as set its status.
*/
class Chicken
{
private:
    float heart;          /* !< The chicken's remaining hearts */
    int xVal;             /*!< The chicken's x-coordinate */
    int yVal;             /*!< The chicken's y-coordinate */
    StatusChicken status; /*!< The chicken's current status */
    bool comeBack;        /*!< Whether the chicken is currently moving back to its starting position */

public:
    /**
     * @brief Constructor for the Chicken class.
     *
     * This constructor initializes the chicken's position and health.
     */
    Chicken();
    /**
     * @brief Destructor for the Chicken class.
     */
    ~Chicken();
    /**
     * @brief Set the x-coordinate of the chicken.
     * @param x The new x-coordinate for the chicken.
     */
    void setX(const int &x);
    /**
     * @brief Set the y-coordinate of the chicken.
     * @param y The new y-coordinate for the chicken.
     */
    void setY(const int &y);
    /**
     * @brief Get the x-coordinate of the chicken.
     * @return The current x-coordinate of the chicken.
     */
    int getX() const;
    /**
     * @brief Get the y-coordinate of the chicken.
     * @return The current y-coordinate of the chicken.
     */
    int getY() const;
    /**
     * @brief Set the chicken's remaining hearts.
     * @param Heart The new number of hearts for the chicken.
     */
    void setHeart(const float &Heart);
    /**
     * @brief Get the chicken's remaining hearts.
     * @return The current number of hearts the chicken has.
     */
    float getHeart() const;
    /**
     * @brief Decrease the chicken's remaining hearts by a given amount.
     * @param bulletDamage The amount of damage done to the chicken by the bullet.
     */
    void decrease(const float &bulletDamage);
    /**
     * @brief Set whether the chicken is currently moving back to its starting position.
     * @param comeback True if the chicken is moving back, false otherwise.
     */
    void setComeBack(const bool &comeback);
    /**
     * @brief Get whether the chicken is currently moving back to its starting position.
     * @return True if the chicken is moving back, false otherwise.
     */
    bool getComeBack() const;
    /**
     * @brief Set the chicken's status to "facing right".
     *
     * This method is called when the chicken changes direction to face right.
     */
    void setStatusRight();
    /**
     * @brief Get the chicken's current status.
     * @return The current status of the chicken.
     */
    StatusChicken getStatus() const;
    /**
     * @brief Set the chicken's current status.
     * @param s The new status for the chicken.
     */
    void setStatus(const StatusChicken &s);
    /**
     * @brief Perform a regression test on the Chicken class.
     *
     * This method tests the Chicken class by setting its attributes and verifying that the values are correctly returned by the class's getters.
     */
    void testRegression();
};

#endif