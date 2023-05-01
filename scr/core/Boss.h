
/**
@file Boss.h
@brief The Boss header file
*/
#ifndef BOSS_H_
#define BOSS_H_

#include <vector>
#include "Global.h"
#include "Bullet.h"
#include "Explode.h"

/**

@brief The width of the boss.
This constant represents the width of the boss in the game. It is used to set the boss's initial size and for collision detection.
*/
#define WIDTH_BOSS 200
/**

@brief The height of the boss.
This constant represents the height of the boss in the game. It is used to set the boss's initial size and for collision detection.
*/
#define HEIGHT_BOSS 117
/**

@brief The speed of the boss.
This constant represents the movement speed of the boss in the game. It is used to update the boss's position each frame.
*/
#define BOSS_SPEED 1
/**

@brief The speed of the boss's bullets.
This constant represents the movement speed of the boss's bullets in the game. It is used to update the position of the boss's bullets each frame.
*/
#define BOSS_BULLET_SPEED 13
/**
@class Boss
@brief Represents the boss character in the game.
The Boss class contains information about the boss's position, status, and health. It also provides methods to update the boss's position and health, as well as set its status.
*/
class Boss
{
public:
    /**
     * @brief si l'objet est dans le cache, il sera utilisé. autrement, un nouvel objet sera créé
     * @param creer objet Boss
     */
    Boss();
    /**
     * @brief Detruit l'objet boss
     * @param detruit objet Boss
     */
    ~Boss();

    /**
     * @brief Définir la coordonnée x du boss.
     * @param x la valeur à définir
     */
    void setX(const int &x);
    /**
     * @brief Définir la coordonnée y de boss.
     * @param y la valeur à définir pour y
     */
    void setY(const int &y);
    /**
     * @brief Il obtient la valeur x de boss.
     * @return La valeur x du patron ou 0 si aucune n' existe (par défaut) dans ce cas le boss est désactivé
     */
    int getX() const;
    /**
     * @brief Obtient la valeur y de boss.
     * @return y valeur de boss par ou 0 si aucune n' existe (par défaut) dans ce cas le boss est désactivé
     */
    int getY() const;
    /**
     * @brief Définit le statut du patron. Ceci est appelé par StatusChicken
     * @param s le statut à définir
     */
    StatusChicken getStatus() const;
    /**
     * @brief Obtien le status de boss
     * @return le statut de boss comme une constante afin que vous puissiez l'utiliser comme une fonction à vos propres fins
     */
    void setStatus(const StatusChicken &s);
    /**
     * @brief Il met le coeur du boss.
     * @param h Le cœur du patron en float
     */
    void setHeart(const float &h);
    /**
     * @brief Obtien le coeur du boss.
     * @return  le coeur du boss en float
     */
    float getHeart() const;
    /**
     * @brief Réduit le cœur du patron par bullet damage de Player
     * @param bullet_damage Montant des dommages à diminuer
     */
    void decrease(const float &bullet_damage);

    /**
     * @brief Teste de régression des propriétés du patron.
     */
    void testRegression();

private:
    float heart;          /*!< coeur du boss */
    int xVal;             /*!< position X du boss */
    int yVal;             /*!< position Y du boss */
    StatusChicken status; /*!< statut du boss */
};

#endif
