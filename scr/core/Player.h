/**
@file Player.h
@brief The Player class header file.
*/
#ifndef PLAYER_H_
#define PLAYER_H_

#include <vector>
#include "Global.h"
#include "Bullet.h"

#define WIDTH_MAIN 70
#define HEIGHT_MAIN 57
#define MAIN_SPEED 6
#define MAIN_HEART 3

/**

@class Player
@brief The class that represents the player in the game.
The Player class holds information about the player's position,
bullet list, bullet type, status, heart, and bullet damage.
*/
class Player
{
private:
    std::vector<Bullet *> bulletList; /**< The list of bullets shot by the player. */
    int xVal;                         /**< The X coordinate of the player. */
    int yVal;                         /**< The Y coordinate of the player. */
    int bulletType;                   /**< The type of bullet used by the player. */
    bool status;                      /**< The status of the player, true if alive, false if dead. */
    int heart;                        /**< The amount of hearts the player has left. */
    float bulletDamage;               /**< The amount of damage done by the player's bullets. */
public:
    /**

    @brief Enumeration of the speeds for different types of bullets.
    */
    enum BULLET_SPEED
    {
        BLASTER_SPEED = 12, /**< Blaster bullet speed. */
        NEUTRON_SPEED = 18, /**< Neutron bullet speed. */
        BORON_SPEED = 30    /**< Boron bullet speed. */
    };
    /**
     * @brief Constructs a new Player object.
     */
    Player();
    /**
     * @brief Destroys the Player object.
     */
    ~Player();

    /**
     * @brief Gets the X coordinate of the player.
     * @return An integer representing the X coordinate of the player.
     */
    int getX() const;

    /**
     * @brief Gets the Y coordinate of the player.
     * @return An integer representing the Y coordinate of the player.
     */
    int getY() const;

    /**
     * @brief Sets the X coordinate of the player.
     * @param x The new X coordinate of the player.
     */
    void setX(const int &x);

    /**
     * @brief Sets the Y coordinate of the player.
     * @param y The new Y coordinate of the player.
     */
    void setY(const int &y);

    /**
     * @brief Sets the bullet damage of the player.
     * @param d The new bullet damage of the player.
     */
    void setBulletDamage(const float &d);

    /**
     * @brief Gets the list of bullets shot by the player.
     * @return A vector of pointers to Bullet objects.
     */
    std::vector<Bullet *> getBulletList() { return bulletList; }

    /**
     * @brief Sets the list of bullets shot by the player.
     * @param bullet_list A vector of pointers to Bullet objects.
     */
    void setBulletList(std::vector<Bullet *> bullet_list) { bulletList = bullet_list; }

    /**
     * @brief Sets the type of bullet used by the player.
     * @param bullet_type The type of bullet used by the player.
     */
    void setBulletType(const int &bullet_type);

    /**
     * @brief Gets the type of bullet used by the player.
     * @return An integer representing the type of bullet used by the player.
     */
    int getBulletType() const;

    /**
     * @brief Sets the status of the player.
     * @param Status The new status of the player.
     */
    void setStatus(const bool &Status);

    /**
     * @brief Gets the status of the player.
     * @return An integer representing the status of the player.
     */
    int getStatus() const;

    /**
     * @brief Gets the bullet damage of the player.
     * @return A float representing the bullet damage of the player.
     */
    float getBulletDamage() const;

    /**
     * @brief Sets the amount of hearts the player has left.
     * @param Heart The new amount of hearts the player has left.
     */
    void setHeart(const int &Heart);
    /**
     *@brief Get the heart of the player.
     *@return int the heart of the player
     */
    int getHeart() const;
    /**
     *@brief Decrease the heart of the player by 1.
     */
    void decreaseHeart();
    /**
     *@brief A function for testing the regression of the class.
     */
    void testRegression();
};

#endif