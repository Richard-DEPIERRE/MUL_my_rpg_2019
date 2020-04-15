/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** spells
*/

#include "rpg.h"

//0 ne bouge pas, 1 monte, 3 à droite, 5 descends, 7 à gauche

void pos_rotat(sfVector2f *pos, sfVector2f player_pos, int rad, sfSprite *sprt)
{
  if (rad == 90) {
    pos->y = player_pos.y + 300;
    pos->x = player_pos.x;
    sfSprite_setRotation(sprt, rad);
  } else if (rad == 270) {
    pos->y = player_pos.y - 300;
    pos->x = player_pos.x;
    sfSprite_setRotation(sprt, rad);
  } else if (rad == 0) {
    pos->y = player_pos.y;
    pos->x = player_pos.x + 300;
    sfSprite_setRotation(sprt, rad);
  } else if (rad == 180) {
    pos->y = player_pos.y;
    pos->x = player_pos.x - 300;
    sfSprite_setRotation(sprt, rad);
  }
}

void fireball(fight_t *fight, sfVector2f player_pos)
{
  sfVector2f final_pos = {0, 0};
  if (fight->spell[0].activated == 0) {
    if (fight->player.direct == 0 || fight->player.direct == 5) {
      pos_rotat(&final_pos, player_pos, 90, fight->spell[0].sprite);
    } else if (fight->player.direct == 1) {
      pos_rotat(&final_pos, player_pos, 270, fight->spell[0].sprite);
    } else if (fight->player.direct == 3) {
        pos_rotat(&final_pos, player_pos, 0, fight->spell[0].sprite);
    } else if (fight->player.direct == 7) {
        pos_rotat(&final_pos, player_pos, 180, fight->spell[0].sprite);
    }
    fight->spell[0].pos = player_pos;
    fight->spell[0].direction = fight->player.direct;
    sfSprite_setPosition(fight->spell[0].sprite, fight->spell[0].pos);
    fight->spell[0].final_pos = final_pos;
    fight->spell[0].activated = 1;
    printf("coucou\n");
  }
}

struct spell_s init_spell(char *path, enum spells_names_s type)
{
  spell_t spell;
  spell.sprite = sfSprite_create();
  spell.texture = sfTexture_createFromFile(path, NULL);
  sfSprite_setTexture(spell.sprite, spell.texture, sfTrue);
  sfSprite_setPosition(spell.sprite, (sfVector2f) {0, 0});
  sfSprite_setScale(spell.sprite, (sfVector2f) {1, 1});
  sfSprite_setTextureRect(spell.sprite, (sfIntRect) {0, 0, 56.125, 31});
  sfSprite_setOrigin(spell.sprite, (sfVector2f) {28, 15.5});
  spell.velocity = 0.5;
  spell.clock = sfClock_create();
  if (type == FIREBALL) {
      spell.damage = 10;
  } else if (type == SHIELD) {
      spell.protection = 10;
  }
  spell.activated = 0;
  return (spell);
}