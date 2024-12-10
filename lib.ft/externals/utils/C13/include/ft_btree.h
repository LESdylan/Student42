/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyl-syzygy <dyl-syzygy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:46:52 by dyl-syzygy        #+#    #+#             */
/*   Updated: 2024/12/10 17:35:01 by dyl-syzygy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
#define FT_BTREE_H
#include <stdio.h>
#include <stdlib.h>
// Structure de l'arbre binaire
typedef struct s_btree {
    void *item;            // Donnée du nœud (générique, peut être n'importe quel type)
    struct s_btree *left;  // Pointeur vers le sous-arbre gauche
    struct s_btree *right; // Pointeur vers le sous-arbre droit
} t_btree;

// Fonction pour créer un nouveau nœud
t_btree *btree_create_node(void *item);

// Fonction d'insertion dans l'arbre binaire (en fonction d'un comparateur)
void btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *));

// Fonction de recherche d'un élément dans l'arbre (infixe)
void *btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *));

// Fonction pour appliquer une fonction à chaque élément de l'arbre en parcours préfixe
void btree_apply_prefix(t_btree *root, void (*applyf)(void *item));

// Fonction pour appliquer une fonction à chaque élément de l'arbre en parcours infixe
void btree_apply_infix(t_btree *root, void (*applyf)(void *item));

// Fonction pour appliquer une fonction à chaque élément de l'arbre en parcours suffixe
void btree_apply_suffix(t_btree *root, void (*applyf)(void *item));

// Fonction pour compter le nombre de niveaux de l'arbre (la profondeur maximale)
int btree_level_count(t_btree *root);

// Fonction pour appliquer une fonction à chaque nœud de l'arbre par niveau
void btree_apply_by_level(t_btree *root, void (*applyf)(void *item, int current_level, int is_first_elem));

#endif
