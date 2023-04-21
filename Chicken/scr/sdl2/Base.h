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
class Base
{
public:
    Base();
    ~Base();

    void setRect(const int &x, const int &y);
    SDL_Rect getRect() const;
    bool loadImg(std::string filename, SDL_Renderer *scr);
    void render(SDL_Renderer *scr, const SDL_Rect *clip = NULL);
    void clean();
    void testRegression();

protected:
    SDL_Rect rect;
    SDL_Texture *objet;
};

class Text : public Base
{
public:
    Text();
    ~Text();

    enum TEXT_COLOR
    {
        RED = 5,
        WHITE = 6,
        BLACK = 7,
    };

    void setText(const std::string &txt) { text = txt; }
    void setColor(const int &type);
    void loadShowText(TTF_Font *font, SDL_Renderer *scr);
    void testRegression();

private:
    std::string text;
    SDL_Color textColor;
};

class GiftSDL : public Base
{
private:
    SDL_Rect clip[25];
    int frame;
    Gift* gift;

public:
    GiftSDL();
    ~GiftSDL();
    Gift* getGift() { return gift; }
    void setGift(Gift* gift) { this->gift = gift; }
    void show(SDL_Renderer *scr);
    void move(const int &x_border, const int &y_border);
    void loadImgGift(SDL_Renderer *scr);
    void setClip();
    SDL_Rect getRectFrame();
    void testRegression();
};

class ExplodeSDL : public Base
{
private:
    Explode explode;
    int frame;
    SDL_Rect clip[NUMBER_OF_CHICKEN];

public:
    ExplodeSDL();
    ~ExplodeSDL();
    void setClip();
    void show(SDL_Renderer *scr);
    void setFrame(const int &Frame) { frame = Frame; }
    int getFrame() const { return frame; }
    void testRegression();
};

class BulletSDL : public Base
{
private:
    Bullet *bullet;
    bool is_move_;

public:
    BulletSDL();
    ~BulletSDL();
    bool getMove() const { return is_move_; }
    void setMove(bool s) { is_move_ = s; }
    Bullet *getBullet() { return bullet; }
    void setBullet(Bullet *bull) { bullet = bull; }
    void handlePlayerBullet();
    void handleChickenBullet();
    void handleBossBullet(const int &xBorbder, const int &yBorbder);
    void loadImgBullet(SDL_Renderer *scr, int bulletLevel, int bulletType);
    void testRegression();
};

class ChickenSDL : public Base
{
private:
    Chicken *chicken;
    int frame;
    SDL_Rect clip[18];
    std::vector<BulletSDL *> bulletList;

public:
    ChickenSDL();
    ~ChickenSDL();
    std::vector<BulletSDL *> getBulletList() { return bulletList; }
    void removeBullet(const int &idx);

    Chicken *getChicken() { return chicken; }
    void setChicken(Chicken *chic) { chicken = chic; }
    void move(Chicken *chicken);
    void show(SDL_Renderer *scr, Chicken *chicken);
    void setClip();
    SDL_Rect getRectFrame();
    void initBullet(BulletSDL *pBullet, ChickenSDL *chicken, SDL_Renderer *scr);
    void handleBullet(SDL_Renderer *scr, Chicken *chicken);
};

class BossSDL : public Base
{
private:
    Boss *boss;
    int frame;
    SDL_Rect clip[10];
    std::vector<BulletSDL *> bulletList;
    bool is_move_;

public:
    BossSDL();
    ~BossSDL();
    bool getMove() const { return is_move_; }
    void setMove(bool s) { is_move_ = s; }
    std::vector<BulletSDL *> getBulletList() { return bulletList; }
    Boss *getBoss() { return boss; }
    void setBoss(Boss *pBoss) { boss = pBoss; }
    void move();
    void show(SDL_Renderer *scr);
    void setClip();
    SDL_Rect getRectFrame();
    void initBullet(BulletSDL *p_bullet, SDL_Renderer *scr, BossSDL *boss);
    void makeBullet(SDL_Renderer *scr, Boss *boss);
    void showHeartBoss(SDL_Renderer *scr, int x, int y, int w, int h);
    void testRegression();
};

class PlayerSDL : public Base
{
private:
    Player *player;
    std::vector<BulletSDL *> bulletList;

public:
    PlayerSDL();
    ~PlayerSDL();
    int getBulletType() { return player->getBulletType(); }
    bool getStatus() { return player->getStatus(); }
    void setBulletType(int s) { player->setBulletType(s); }
    void setStatus(bool s) { player->setStatus(s); }
    void setHeart(int h) { player->setHeart(h); }
    void decreaseHeart() { player->decreaseHeart(); }
    int getHeart() { return player->getHeart(); }
    float getBulletDamage() const { return player->getBulletDamage(); }
    void setBulletDamage(const float &damage) { player->setBulletDamage(damage); }
    void removeBullet(const int &idx);
    std::vector<BulletSDL *> getBulletList() { return bulletList; }
    Player *getPlayer() { return player; }
    void setPlayer(Player *p) { player = p; }
    void setBulletList(std::vector<Bullet *> bull) { player->setBulletList(bull); }
    void control(SDL_Event event, SDL_Renderer *scr, Mix_Chunk *bulletSound[4], int bulletLevel, Mix_Chunk *gSoundLevelUp, Player *player);
    void move(Player *player);
    void show(SDL_Renderer *scr, Player *player);
    void handleBullet(SDL_Renderer *scr, PlayerSDL *player);
    void testRegression();
};

class ControlSDL : public Base
{
private:
    bool isRunning;
    int bullet_level;
    int kill;
    float scrolling;
    int time_end_game;
    int count_num_exp;
    int menu_number;
    std::vector<ChickenSDL *> p_chicken_list;
    std::vector<int> highScore {0,0,0,0,0};

    SDL_Window *gWindow;
    SDL_Renderer *gRenderer;
    SDL_Event gEvent;
    Mix_Chunk *gSoundBullet[3];
    Mix_Chunk *gSoundExp[3];
    Mix_Chunk *gSoundChickenHit[3];
    Mix_Chunk *gSoundLevelUp;
    Mix_Music *gMusicStart;
    TTF_Font *gFontText;
    TTF_Font *gFontMenu;
    TTF_Font *gFontEndGame;
    Base *background;
    Text *kill_text;
    Base *support;
    Text *heart_text;
    Text *lighting_text;
    Text *hint;
    Text *end_game;
    PlayerSDL *spaceship;
    ExplodeSDL *exp;
    ExplodeSDL *exp_boss;
    GiftSDL *gift;
    BossSDL *boss;

public:
    ControlSDL();
    ~ControlSDL();
    bool getRunning() { return isRunning; }
    void init(std::string title);
    void handleGame();
    void clean();
    void menu(const std::string &item);
    void resetGame();
    bool checkCollision(const SDL_Rect &objet1, const SDL_Rect &objet2);
    bool check_mouse_vs_item(const int &x, const int &y, const SDL_Rect &rect);
    void testRegression();
};

#endif