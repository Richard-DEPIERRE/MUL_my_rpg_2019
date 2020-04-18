/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** rafik
*/

#ifndef RAFIK_H_
#define RAFIK_H_

#include <SFML/Graphics.h>
#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Audio.h>
#include <SFML/Window/Export.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Window/Context.h>
#include <SFML/Window/JoystickIdentification.h>
#include <SFML/Graphics/Export.h>

typedef struct game_obj_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfVector2f scale;
    sfIntRect rect;
    sfClock *clock;
} game_obj_t;

#endif /* !RAFIK_H_ */