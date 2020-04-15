/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** spells
*/

#include "rpg.h"

//0 ne bouge pas, 1 monte, 3 à droite, 5 descends, 7 à gauche

void fireball(fight_t *fight, sfVector2f player_pos)
{
  sfVector2f final_pos = {0, 0};
  if (fight->spell[0].activated == 1) {
    if (fight->player.direct == 0 || fight->player.direct == 5) {
      final_pos.y += player_pos.y + 200;
      final_pos.x = player_pos.x;
    } else if (fight->player.direct == 1) {
      final_pos.y -= player_pos.y - 200;
      final_pos.x = player_pos.x;
    } else if (fight->player.direct == 3) {
        final_pos.y -= player_pos.y;
        final_pos.x = player_pos.x + 200;
    } else if (fight->player.direct == 7) {
        final_pos.y -= player_pos.y;
        final_pos.x = player_pos.x - 200;
    }
    fight->spell[0].pos = player_pos;
    fight->spell[0].final_pos = final_pos;
    fight->spell[0].activated = 1;
  }
}

void create_clock(clock_s *clock)
{
  clock->clock = sfClock_create();
}

spell_t init_spell(char *path, enum spells_names_s type)
{
  spell_t spell;
  spell.sprite = sfSprite_create();
  spell.texture = sfTexture_createFromFile(path, NULL);
  sfSprite_setTexture(spell.sprite, spell.texture, sfTrue);
  sfSprite_setPosition(spell.sprite, (sfVector2f) {0, 0});
  sfSprite_setScale(spell.sprite, (sfVector2f) {1, 1});
  sfSprite_setTextureRect(spell.sprite, (sfIntRect) {0, 0, 56.125, 31});
  spell.velocity = 0.5;
  create_clock(&spell.clock);
  if (type == FIREBALL) {
      spell.damage = 10;
  } else if (type == SHIELD) {
      spell.protection = 10;
  }
  spell.activated = 0;
  return (spell);
}