/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** update_spell
*/

#include "rpg.h"

void animation_spell(spell_t *spell, clock_s *clock)
{
    if (spell->rect.left < 393) {
        spell->rect.left += 56.125;
    } else {
        spell->rect.left = 0;
    }
}

void update_fireball(spell_t *spell, clock_s *clock)
{
    if (spell->activated == 1) {    
        clock->time = sfClock_getElapsedTime(clock->clock);
        clock->second = clock->time.microseconds / 1000000.0;
        if (clock->second > 0.09) {
            animation_spell(spell, &spell->clock);
            if (spell->final_pos.x != spell->pos.x && spell->final_pos.y != spell->pos.y) {
                if (spell->pos.x == spell->final_pos.x)
                    spell->pos.y += 5;
                if (spell->pos.y == spell->final_pos.y)
                    spell->pos.x += 5;
            } else {
                spell->activated = 0;
            }
            sfSprite_setPosition(spell->sprite, spell->pos);
            sfClock_restart(clock->clock);
        }
        // si la firaball n'est tjs pas arrivé à l'endroit de fin, += 10
        
        //si c'est arrivé à la fin (ou après) -> activated à 0
    }
}

void update_spell(fight_t *fight)
{
    update_fireball(&fight->spell[0], &fight->spell[0].clock);
}