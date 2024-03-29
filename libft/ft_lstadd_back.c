/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagiorgi <nagiorgi@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 12:35:11 by nagiorgi          #+#    #+#             */
/*   Updated: 2023/10/26 17:25:49 by nagiorgi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*   Fonctionnement : Ajoute un élément à la fin de la liste chaînée en       */
/*   parcourant la liste jusqu'à ce que le dernier élément soit trouvé, puis  */
/*   relie le dernier élément au nouvel élément. Si la liste est vide, le     */
/*   nouvel élément devient la première et la dernière entrée.                */
/*                                                                            */
/*   Paramètres :                                                             */
/*      - lst : Un pointeur vers un pointeur du premier élément de la liste.  */
/*      - new : Un pointeur vers l'élément à ajouter à la fin de la liste.    */
/* *****************************************************************   by.XVI */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*endlst;

	endlst = ft_lstlast(*lst);
	if (endlst)
		endlst->next = new;
	else
		*lst = new;
}
