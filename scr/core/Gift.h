/**
@file Gift.h
@brief The Gift header file
*/
#ifndef GIFT_H_
#define GIFT_H_
#include "Global.h"
#define GIFT_WIDTH 49
#define GIFT_HEIGHT 58
#define WIDTH_LEVEL_UP 49
#define HEIGHT_LEVEL_UP 41
#define GIFT_SPEED 2
/**
 * @brief Class representing a gift in the game.
 */
class Gift
{
private:
    int xVal;       /*!< The x-coordinate of the gift's position. */
    int yVal;       /*!< The y-coordinate of the gift's position. */
    int giftType;   /*!< The type of gift. */
    bool comeBack;  /*!< Whether the gift is currently moving back to its starting position. */
public:
    /**
     * @brief Default constructor for a Gift object.
     */
    Gift();

    /**
     * @brief Destructor for a Gift object.
     */
    ~Gift();

    /**
     * @brief Set the x-coordinate of the gift's position.
     * @param x The new x-coordinate.
     */
    void setX(const int &x);

    /**
     * @brief Set the y-coordinate of the gift's position.
     * @param y The new y-coordinate.
     */
    void setY(const int &y);

    /**
     * @brief Get the current x-coordinate of the gift's position.
     * @return The current x-coordinate.
     */
    int getX() const;

    /**
     * @brief Get the current y-coordinate of the gift's position.
     * @return The current y-coordinate.
     */
    int getY() const;

    /**
     * @brief Set the type of gift.
     * @param type The new gift type.
     */
    void setGiftType(const int &type);

    /**
     * @brief Get the type of gift.
     * @return The current gift type.
     */
    int getGiftType() const;

    /**
     * @brief Set whether the gift is currently moving back to its starting position.
     * @param back True if the gift is moving back, false otherwise.
     */
    void setComeBack(const bool &back);

    /**
     * @brief Get whether the gift is currently moving back to its starting position.
     * @return True if the gift is moving back, false otherwise.
     */
    bool getComeBack() const;

    /**
     * @brief Choose a random gift type from the available options.
     * @return An integer representing the randomly selected gift type.
     */
    int randomGift() const;

    /**
     * @brief Perform a regression test on the Gift class.
     *
     * This method tests the Gift class by setting its attributes and verifying that the values are correctly returned by the class's getters.
     */
    void testRegression();

};


#endif