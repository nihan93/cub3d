/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarakat <nbarakat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:50:32 by nbarakat          #+#    #+#             */
/*   Updated: 2023/05/18 20:20:31 by nbarakat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	ft_strncmp(const char	*str1, const char	*str2, size_t	n)
{
	unsigned int	i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *) str1;
	s2 = (unsigned char *) str2;
	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && (s1[i] == s2[i]) && i < n - 1)
		i++;
	return (s1[i] - s2[i]);
}

void check_args(int ac, char    *av[])
{
    int     len;
    char    *cub;
    int     i;
    
    if (ac != 2)
        printf("Wrong number of argument !\n"), exit(1);
    i = 3;
    len = ft_strlen(av[1]);
    cub = ".cub";
    while (i != -1 && len != 0)
    {
        if (av[1][len - 1] != cub[i])
            printf("Wrong file extension !\n"), exit(1);
        i--;
        len--;
    }
}

void set_elements(char **s)
{
    s[0] = "NO ";
    s[1] = "SO ";
    s[2] = "WE ";
    s[3] = "EA ";
    s[4] = "F ";
    s[5] = "C ";
    s[6] = NULL;
}

void check_count(char  **map, char **elements)
{
    int i;
    int j;
    int count;

    j = 0;
    while (elements[j])
    {
        i = 0;
        count = 0;
        while (map[i] && map[i][0] != '1')
        {
            if (!ft_strncmp(map[i], elements[j], ft_strlen(elements[j])))
                count++;
            i++;
        }
        if (count != 1)
            printf("check elements on map file :(\n"), exit(1);
        j++;
    }
}

void check_elements(char    **map)
{
    char    *elements[7];
    int     i;

    i  = 0;
    while (map[i])
    {
        if (!ft_strncmp(map[i],"\n", 1) || map[i][0] == '1' || !ft_strncmp(map[i],"NO ", 3) 
            || !ft_strncmp(map[i],"SO ", 3) || !ft_strncmp(map[i],"WE ", 3) 
            || !ft_strncmp(map[i],"EA ", 3) || !ft_strncmp(map[i],"F ", 2)
            || !ft_strncmp(map[i],"C ", 2))
                i++;
        else
            printf("check elements on map file :(\n"), exit(1);    
    }

    set_elements(elements);
    check_count(map, elements);
    
}

void check_map(char  **map)
{
    check_elements(map);
    
}

//check eof has to be map or \n