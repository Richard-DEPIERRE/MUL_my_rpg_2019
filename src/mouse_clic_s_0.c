/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** mouse_clic_s_0
*/

#include "rpg.h"
#include "my.h"

//le fichier se nomme mouse_clic_s_0

//tâches d'appeler les autres fichiers pour les fonctions de status différents de la façon suivante

//mouse_clic_s_<nb_statue_concerné>

void clic_status_zero(sfMouseButtonEvent event, sfVector2i mouse, rpg_t *rpg)
{
    //c'est ici qu'on va ranger toutes les forêt de if ^^'

    if (mouse.x > 200 && mouse.x < 600 && mouse.y > 200 && mouse.y < 600) {
        //ici tu mets les actions définis par le boutton appuyé
        // printf("je viens de cliquer sur un boutton mais il est invisible la vie\n");
    }
    if (mouse.x > 1000 && mouse.x < 1200 && mouse.y > 1000 && mouse.y < 1200) {
        // printf("imaginons ici c'est le boutton pour quitter le jeu dans le menu :D\n");
    }
    //et tu mets tous les autres bouttons.
}