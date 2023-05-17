/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarakat <nbarakat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:50:32 by nbarakat          #+#    #+#             */
/*   Updated: 2023/05/17 19:38:50 by nbarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

// Except for the map content, each type of element can be separated by one or
// more empty line(s).

// Except for the map content which always has to be the last, each type of
// element can be set in any order in the file.

// Except for the map, each type of information from an element can be separated
// by one or more space(s).


/*
    if more than one argument or isn't .cub file
        error 
    bubble check (no so we ea f c ) with space\uppercase before 1 (ignoring spaces / newlines)
        if something different than all parameters exit
        if one not found exit 
        if not all checked before map exit
        else set index to map

    check no so we ea have a path (ignoring spaces)
        check path
        if no path exit
        else if doesn't open exit ?

    check F C  if have colors right after (ignoring spaces)
        check if right syntax / range  [0,255]
    
    check map starting from index (ignoring spaces)
        if 1s aren't surrounding the map exit
        check if anything different than 1,0,N,S,E,W
        ofc no newlines
        
    
*/