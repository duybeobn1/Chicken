/**
@file Base.h
@brief Contains the definition of the Base class and other inherited class such as Text, GiftSDL, PlayerSDL, BossSDL, ChickenSDL,
ExplodeSDL, BulletSDL, ChickenSDL, GameSDL.
*/
#ifndef BASE_H_
#define BASE_H_
#include "../core/Global.h"
#include "string"
#include "../core/Gift.h"
#include "../core/Bullet.h"
#include "../core/Explode.h"
#include "../core/Chicken.h"
#include "../core/Boss.h"
#include "../core/Player.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <fstream>
#define NUM_HIGH_SCORES 5
/**

@class Base

@brief The Base class represents the base object that can be used for game elements.

The Base class loads and displays images of game elements using the SDL library.

It contains methods for setting the object's position and dimensions, loading images,

rendering images, and cleaning up resources.
*/
class Base
{
public:
    /**

    @brief Constructs a new Base object.
    */
    Base();
    /**

    @brief Destroys the Base object and frees any allocated resources.
    */
    ~Base();
    /**

    @brief Sets the position and dimensions of the object's rectangle.
    @param x The x-coordinate of the top-left corner of the rectangle.
    @param y The y-coordinate of the top-left corner of the rectangle.
    */
    void setRect(const int &x, const int &y);
    /**

    @brief Returns the object's rectangle.
    @return The object's rectangle.
    */
    SDL_Rect getRect() const;
    /**

    @brief Loads an image from a file and sets it as the object's texture.
    @param filename The name of the image file to load.
    @param scr The SDL_Renderer to use for loading the image.
    @return True if the image was loaded successfully, false otherwise.
    */
    bool loadImg(std::string filename, SDL_Renderer *scr);
    /**

    @brief Renders the object's texture on the screen.
    @param scr The SDL_Renderer to use for rendering the texture.
    @param clip The rectangle to clip the texture to, or NULL for no clipping.
    */
    void render(SDL_Renderer *scr, const SDL_Rect *clip = NULL);
    /**

    @brief Frees any allocated resources for the object's texture.
    */
    void clean();
    /**
    @brief Performs regression testing on the Base class.
    */
    void testRegression();

protected:
    SDL_Rect rect;      /**< The rectangle representing the object's position and dimensions. */
    SDL_Texture *objet; /**< The texture representing the object's image. */
};

/**
@brief The Text class represents a text object that inherits from the Base class, use to generate Text in the game
*/
class Text : public Base
{
public:
    /*
     * @brief Construct a new Text object.
     *
     */
    Text();
    /**
     * @brief Destroy the Text object.
     *
     */
    ~Text();

    /**
     * @brief An enumeration of available text colors.
     *
     */
    enum TEXT_COLOR
    {
        RED = 5,
        WHITE = 6,
        BLACK = 7,
    };

    /**
     * @brief Sets the text of the Text object.
     *
     * @param txt The text to be set.
     */
    void setText(const std::string &txt);

    /**
     * @brief Sets the color of the Text object.
     *
     * @param type The color to be set.
     */
    void setColor(const int &type);

    /**
     * @brief Loads and shows the Text object using a font and a renderer.
     *
     * @param font The font to be used.
     * @param scr The renderer to be used.
     */
    void loadShowText(TTF_Font *font, SDL_Renderer *scr);

    /**
     * @brief Runs a regression test for the Text object.
     *
     */
    void testRegression();

private:
    std::string text;    /**< The text of the Text object. */
    SDL_Color textColor; /**< The color of the Text object. */
};

/**

@class GiftSDL
@brief Represents a gift in the game, inherited from the Base class.
The GiftSDL class manages the rendering, movement, and displaying of a gift on the screen.
The gift is represented by an image that is loaded using the loadImg() function from the Base class.
The GiftSDL class also manages the clipping of the gift image for animation purposes and stores the gift data using the Gift class.
*/
class GiftSDL : public Base
{
private:
    SDL_Rect clip[25]; /**< Array of SDL_Rectangles to manage clipping of gift image. */
    int frame;         /**< The current frame of the gift animation. */
    Gift *gift;        /**< A pointer to the Gift object associated with the gift image. */
public:
    /**
     * @brief Constructs a new GiftSDL object.
     */
    GiftSDL();
    /**
     * @brief Destroys the GiftSDL object.
     */
    ~GiftSDL();

    /**
     * @brief Gets the Gift object associated with the gift image.
     * @return A pointer to the Gift object.
     */
    Gift *getGift() const;

    /**
     * @brief Sets the Gift object associated with the gift image.
     * @param newGift A pointer to the Gift object.
     */
    void setGift(Gift *newGift);

    /**
     * @brief Displays the gift image on the screen.
     * @param scr A pointer to the SDL_Renderer object used for rendering.
     */
    void show(SDL_Renderer *scr);

    /**
     * @brief Moves the gift image on the screen.
     * @param x_border The border of the screen in the x-axis.
     * @param y_border The border of the screen in the y-axis.
     */
    void move(const int &x_border, const int &y_border);

    /**
     * @brief Loads the gift image using the loadImg() function from the Base class.
     * @param scr A pointer to the SDL_Renderer object used for rendering.
     */
    void loadImgGift(SDL_Renderer *scr);

    /**
     * @brief Sets the clipping rectangles for the gift image for animation purposes.
     */
    void setClip();

    /**
     * @brief Gets the SDL_Rectangle of the current frame of the gift animation.
     * @return The SDL_Rectangle of the current frame.
     */
    SDL_Rect getRectFrame();

    /**
     * @brief Runs the regression test for the GiftSDL class.
     */
    void testRegression();
};

/**

@class ExplodeSDL
@brief A class for managing the explosion animation of a chicken in the game.
This class inherits from the Base class and adds functionality to manage the animation
of the explosion when a chicken is hit in the game. It contains an instance of the Explode
class, an integer to keep track of the current animation frame, and an array of SDL_Rect
objects to define the position and size of each frame in the sprite sheet.
*/

class ExplodeSDL : public Base
{
private:
    Explode explode;                  /**< An instance of the Explode class to store the explosion animation data */
    int frame;                        /**< The current frame of the explosion animation */
    SDL_Rect clip[NUMBER_OF_CHICKEN]; /**< An array of SDL_Rect objects to store the coordinates of each frame of the explosion animation */

public:
    /**
     * @brief Constructor for the ExplodeSDL class.
     *
     */
    ExplodeSDL();

    /**
     * @brief Destructor for the ExplodeSDL class.
     *
     */
    ~ExplodeSDL();

    /**
     * @brief Sets the clip for each frame of the explosion animation.
     *
     */
    void setClip();

    /**
     * @brief Renders the explosion animation on the screen.
     *
     * @param scr SDL_Renderer object on which to render the animation.
     */
    void show(SDL_Renderer *scr);

    /**
     * @brief Sets the current frame of the explosion animation.
     *
     * @param Frame The frame to set as the current frame.
     */
    void setFrame(const int &Frame);

    /**
     * @brief Gets the current frame of the explosion animation.
     *
     * @return The current frame of the explosion animation.
     */
    int getFrame() const;

    /**
     * @brief Runs regression tests on the class.
     *
     */
    void testRegression();
};
/**

@brief The BulletSDL class inherits from Base and is responsible for handling the bullet objects in the game.
It contains an instance of the Bullet class, an boolean to keep track of the bullet.
*/
class BulletSDL : public Base
{
    /**
     * @brief Pointer to the Bullet object associated with the BulletSDL object.
     */
    Bullet *bullet;

    /**
     * @brief Boolean indicating whether the bullet is in motion.
     */
    bool is_move_;

public:
    /**
     * @brief Constructor for BulletSDL class.
     */
    BulletSDL();
    /**
     * @brief Destructor for BulletSDL class.
     */
    ~BulletSDL();

    /**
     * @brief Getter for is_move_ variable.
     * @return True if the bullet is moving, false otherwise.
     */
    bool getMove() const { return is_move_; }

    /**
     * @brief Setter for is_move_ variable.
     * @param s The boolean value to set for is_move_.
     */
    void setMove(const bool &s);

    /**
     * @brief Getter for bullet variable.
     * @return The Bullet object.
     */
    Bullet *getBullet() const;

    /**
     * @brief Setter for bullet variable.
     * @param bull The Bullet object to set for bullet.
     */
    void setBullet(Bullet *bull);

    /**
     * @brief Handles the player bullet movement and collision.
     */
    void handlePlayerBullet();

    /**
     * @brief Handles the chicken bullet movement and collision.
     */
    void handleChickenBullet();

    /**
     * @brief Handles the boss bullet movement and collision.
     * @param xBorbder The x boundary for the boss.
     * @param yBorbder The y boundary for the boss.
     */
    void handleBossBullet(const int &xBorbder, const int &yBorbder);

    /**
     * @brief Loads the bullet image.
     * @param scr The SDL_Renderer to render the image.
     * @param bulletLevel The bullet level.
     * @param bulletType The bullet type.
     */
    void loadImgBullet(SDL_Renderer *scr, int bulletLevel, int bulletType);

    /**
     * @brief Runs a regression test on the BulletSDL class.
     */
    void testRegression();
};

/**

@class ChickenSDL
@brief A class for managing the Chicken object in SDL environment.
This class provides methods for managing the Chicken object in SDL environment such as
moving the Chicken, showing the Chicken on the screen, initializing and handling bullets,
etc. It also contains a vector of BulletSDL objects which are used for shooting by the Chicken.
*/
class ChickenSDL : public Base
{
private:
    Chicken *chicken;                    /**< A pointer to the Chicken object. */
    int frame;                           /**< The current frame of the Chicken's animation. */
    SDL_Rect clip[18];                   /**< An array of SDL_Rect objects representing the clips of the Chicken's animation frames. */
    std::vector<BulletSDL *> bulletList; /**< A vector of BulletSDL pointers representing the Chicken's bullets. */
public:
    /**
     * @brief Constructor for the ChickenSDL class.
     */
    ChickenSDL();
    /**
     * @brief Destructor for the ChickenSDL class.
     */
    ~ChickenSDL();

    /**
     * @brief Returns the vector of BulletSDL pointers representing the Chicken's bullets.
     * @return A vector of BulletSDL pointers.
     */
    std::vector<BulletSDL *> getBulletList() const;

    /**
     * @brief Removes a bullet from the vector of BulletSDL pointers representing the Chicken's bullets.
     * @param idx The index of the bullet to be removed.
     */
    void removeBullet(const int &idx);

    /**
     * @brief Returns a pointer to the Chicken object.
     * @return A pointer to the Chicken object.
     */
    Chicken *getChicken() const;

    /**
     * @brief Sets the Chicken object to be used by the ChickenSDL object.
     * @param chic A pointer to the Chicken object.
     */
    void setChicken(Chicken *chic);

    /**
     * @brief Moves the Chicken object.
     * @param chicken A pointer to the Chicken object.
     */
    void move(Chicken *chicken);

    /**
     * @brief Renders the Chicken on the screen.
     * @param scr A pointer to the SDL_Renderer object representing the screen.
     * @param chicken A pointer to the Chicken object.
     */
    void show(SDL_Renderer *scr, Chicken *chicken);

    /**
     * @brief Sets the clips of the Chicken's animation frames.
     */
    void setClip();

    /**
     * @brief Returns the SDL_Rect object representing the current frame of the Chicken's animation.
     * @return An SDL_Rect object representing the current frame of the Chicken's animation.
     */
    SDL_Rect getRectFrame();

    /**
     * @brief Initializes a BulletSDL object to be used by the Chicken.
     * @param pBullet A pointer to the BulletSDL object.
     * @param chicken A pointer to the ChickenSDL object.
     * @param scr A pointer to the SDL_Renderer object representing the screen.
     */
    void initBullet(BulletSDL *pBullet, ChickenSDL *chicken, SDL_Renderer *scr);

    /**
     * @brief Handles the bullets shot by the Chicken.
     * @param scr A pointer to the SDL_Renderer object representing the screen.
     * @param chicken A pointer to the Chicken object.
     */
    void handleBullet(SDL_Renderer *scr, Chicken *chicken);
};

/**

@brief The BossSDL class represents the graphical interface of the Boss in the game.
The BossSDL class inherits from the Base class and contains the methods necessary for displaying and handling the Boss object.
It also contains a vector of BulletSDL objects for handling the Boss's bullets.
*/
class BossSDL : public Base
{
private:
    Boss *boss;                          /**< A pointer to the Boss object. */
    int frame;                           /**< The current frame of the Boss's animation. */
    SDL_Rect clip[10];                   /**< An array of SDL_Rect objects representing the clipping regions of the Boss's animation frames. */
    std::vector<BulletSDL *> bulletList; /**< A vector of BulletSDL objects representing the Boss's bullets. */
    bool is_move_;                       /**< A boolean value indicating whether the Boss is currently moving or not. */
public:
    /**
     * @brief Construct a new BossSDL object.
     *
     */
    BossSDL();
    /**
     * @brief Destroy the BossSDL object.
     *
     */
    ~BossSDL();
    /**
     * @brief Get the vector of BulletSDL objects representing the Boss's bullets.
     *
     * @return std::vector<BulletSDL*> The vector of BulletSDL objects representing the Boss's bullets.
     */
    std::vector<BulletSDL *> getBulletList() const;

    /**
     * @brief Get a pointer to the Boss object.
     *
     * @return Boss* A pointer to the Boss object.
     */
    Boss *getBoss() const;

    /**
     * @brief Set the Boss object.
     *
     * @param pBoss A pointer to the Boss object to be set.
     */
    void setBoss(Boss *pBoss);

    /**
     * @brief Move the Boss object.
     *
     * This method updates the Boss's position based on its current velocity and direction.
     */
    void move();

    /**
     * @brief Show the Boss object on the screen.
     *
     * This method renders the Boss object on the screen.
     *
     * @param scr A pointer to the SDL_Renderer object.
     */
    void show(SDL_Renderer *scr);

    /**
     * @brief Set the clipping regions for the Boss's animation frames.
     *
     */
    void setClip();

    /**
     * @brief Get the SDL_Rect object representing the current frame of the Boss's animation.
     *
     * @return SDL_Rect The SDL_Rect object representing the current frame of the Boss's animation.
     */
    SDL_Rect getRectFrame();

    /**
     * @brief Initialize a BulletSDL object for the Boss.
     *
     * @param p_bullet A pointer to the BulletSDL object to be initialized.
     * @param scr A pointer to the SDL_Renderer object.
     * @param boss A pointer to the BossSDL object.
     */
    void initBullet(BulletSDL *p_bullet, SDL_Renderer *scr, BossSDL *boss);

    /**
     * @brief Create a new bullet for the Boss and add it to the bulletList vector.
     *
     * @param scr A pointer to the SDL_Renderer object.
     * @param boss A pointer to the Boss object.
     */
    void makeBullet(SDL_Renderer *scr, Boss *boss);
    /**
     * @brief Displays the boss's heart on the screen at the given position and size.
     *
     * @param scr The renderer to use for rendering the heart.
     * @param x The x-coordinate of the top-left corner of the heart's bounding box.
     * @param y The y-coordinate of the top-left corner of the heart's bounding box.
     * @param w The width of the heart's bounding box.
     * @param h The height of the heart's bounding box.
     */
    void showHeartBoss(SDL_Renderer *scr, int x, int y, int w, int h);

    /**
     * @brief Performs regression testing on the BossSDL class.
     *
     * This function tests the various functionalities of the BossSDL class to ensure that they are working correctly. It may throw an exception if a test fails.
     */
    void testRegression();
};

/**

@brief The PlayerSDL class, derived from Base class, represents the Player object in SDL implementation.
*/
class PlayerSDL : public Base
{
private:
    Player *player;                      /**< A pointer to the Player object. */
    std::vector<BulletSDL *> bulletList; /**< A vector of pointers to BulletSDL objects representing the player's bullets. */

public:
    /**
     * @brief Construct a new PlayerSDL object.
     *
     */
    PlayerSDL();
    /**
     * @brief Destroy the PlayerSDL object.
     *
     */
    ~PlayerSDL();
    /**
     * @brief Remove a bullet from the bullet list.
     *
     * @param idx The index of the bullet to be removed.
     */
    void removeBullet(const int &idx);

    /**
     * @brief Get the bullet list of the player.
     *
     * @return std::vector<BulletSDL *> The vector of pointers to BulletSDL objects.
     */
    std::vector<BulletSDL *> getBulletList() const;
    /**
     * @brief Get the Player object.
     *
     * @return Player* A pointer to the Player object.
     */
    Player *getPlayer() const;

    /**
     * @brief Set the Player object.
     *
     * @param p A pointer to the Player object.
     */
    void setPlayer(Player *p);
    /**
     * @brief Handles user input and controls the player's movement and bullet firing.
     *
     * @param event The event object containing information about the user input.
     * @param scr The SDL_Renderer used to render the game.
     * @param bulletSound An array of Mix_Chunk pointers representing the different bullet firing sounds.
     * @param bulletLevel The current level of the player's bullets.
     * @param gSoundLevelUp The sound effect played when the player's bullet level increases.
     * @param player The Player object being controlled.
     */
    void control(SDL_Event event, SDL_Renderer *scr, Mix_Chunk *bulletSound[4], int bulletLevel, Mix_Chunk *gSoundLevelUp, Player *player);

    /**
     * @brief Moves the player's ship.
     *
     * @param player The Player object being moved.
     */
    void move(Player *player);

    /**
     * @brief Renders the player's ship.
     *
     * @param scr The SDL_Renderer used to render the game.
     * @param player The Player object being rendered.
     */
    void show(SDL_Renderer *scr, Player *player);

    /**
     * @brief Handles the logic for firing the player's bullets.
     *
     * @param scr The SDL_Renderer used to render the game.
     * @param player The PlayerSDL object firing the bullets.
     */
    void handleBullet(SDL_Renderer *scr, PlayerSDL *player);

    /**
     * @brief Runs a regression test for the PlayerSDL class.
     */
    void testRegression();
};

/**

@brief Class for controlling the game logic and rendering using SDL library.
*/

class GameSDL : public Base
{
private:
    int highScores[NUM_HIGH_SCORES];          ///< Array of high scores
    bool isRunning;                           ///< Flag indicating if the game is running
    int bullet_level;                         ///< The level of the player's bullet
    int kill;                                 ///< Number of chickens killed by the player
    float scrolling;                          ///< The scrolling speed of the background
    int time_end_game;                        ///< The time at which the game ends
    int count_num_exp;                        ///< The number of explosions
    int menu_number;                          ///< The number of menu items
    std::vector<ChickenSDL *> p_chicken_list; ///< List of chickens
    SDL_Window *gWindow;                      ///< The game window
    SDL_Renderer *gRenderer;                  ///< The game renderer
    SDL_Event gEvent;                         ///< The game event
    Mix_Chunk *gSoundBullet[3];               ///< Array of bullet sounds
    Mix_Chunk *gSoundExp[3];                  ///< Array of explosion sounds
    Mix_Chunk *gSoundChickenHit[3];           ///< Array of chicken hit sounds
    Mix_Chunk *gSoundLevelUp;                 ///< Sound played when the player levels up
    Mix_Music *gMusicStart;                   ///< Music played at the start of the game
    TTF_Font *gFontText;                      ///< Font used for text
    TTF_Font *gFontMenu;                      ///< Font used for menu items
    TTF_Font *gFontEndGame;                   ///< Font used for end game text
    Base *background;                         ///< The game background
    Text *kill_text;                          ///< The text displaying the number of kills
    Base *support;                            ///< The game support
    Text *heart_text;                         ///< The text displaying the number of hearts
    Text *lighting_text;                      ///< The text displaying the number of lightings
    Text *hint;                               ///< The hint text
    Text *end_game;                           ///< The end game text
    PlayerSDL *spaceship;                     ///< The player's spaceship
    ExplodeSDL *exp;                          ///< The explosion
    ExplodeSDL *exp_boss;                     ///< The explosion for the boss
    GiftSDL *gift;                            ///< The gift object
    BossSDL *boss;                            ///< The boss object

public:
    /**
     * @brief Construct a new GameSDL object
     *
     */
    GameSDL();
    /**
     * @brief Destroy the GameSDL object
     *
     */
    ~GameSDL();

    /**
     * @brief Get the running status of the game
     *
     * @return true if the game is running, false otherwise
     */
    bool getRunning()const;

    /**
     * @brief Initialize the game window, renderer and fonts
     *
     * @param title The title of the game window
     */
    void init(std::string title);

    /**
     * @brief Clean up the game resources and quit SDL
     *
     */
    void clean();

    /**
     * @brief Display the game menu and handle user input
     *
     * @param item The menu item selected by the user
     */
    void menu(const std::string &item);
    /**

    @brief Check if two SDL_Rectangles intersect.
    @param objet1 The first SDL_Rectangle to check.
    @param objet2 The second SDL_Rectangle to check.
    @return true if the two SDL_Rectangles intersect, false otherwise.
    */
    bool checkCollision(const SDL_Rect &objet1, const SDL_Rect &objet2);
    /**

    @brief Check if a point collides with an SDL_Rectangle.
    @param x The x-coordinate of the point.
    @param y The y-coordinate of the point.
    @param rect The SDL_Rectangle to check.
    @return true if the point collides with the SDL_Rectangle, false otherwise.
    */
    bool check_mouse_vs_item(const int &x, const int &y, const SDL_Rect &rect);
    /**

    @brief Sets the high scores for the game.
    */
    void setHighScore();
    /**

    @brief Runs regression tests on the GameSDL class.
    */
    void testRegression();
};

#endif