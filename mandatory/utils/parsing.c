/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarakat <nbarakat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 14:24:13 by nbarakat          #+#    #+#             */
/*   Updated: 2023/05/21 20:45:38 by nbarakat         ###   ########.fr       */
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

int is_empty(char *s)
{
    int i;
    
    i = 0;
    while (s[i])
    {
        if (s[i] != ' ')
            return (0);
        i++;
    }
    return (1);
}

int is_map_line(char    *s)
{
    int i;

    i = 0;
    if (s[0] == 0 || is_empty(s))
        return (0);
    while (s[i])
    {
        if (s[i] != '0' && s[i] != '1' && s[i] != ' '
            && s[i] != 'N' && s[i] != 'S' && s[i] != 'E'
            && s[i] != 'W')
                return (0);
        i++;
    }
    return (1);
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
        while (map[i] && !is_map_line(map[i]))
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
        if (!map[i][0] || is_empty(map[i]) || !ft_strncmp(map[i],"NO ", 3) 
            || !ft_strncmp(map[i],"SO ", 3) || !ft_strncmp(map[i],"WE ", 3) 
            || !ft_strncmp(map[i],"EA ", 3) || !ft_strncmp(map[i],"F ", 2)
            || !ft_strncmp(map[i],"C ", 2) || is_map_line(map[i]))
                i++;
        else
            printf("check elements on map file :(\n"), exit(1);    
    }
    set_elements(elements);
    check_count(map, elements);
}

void fill_characters(int *characters)
{
    characters[0] = 0;
    characters[1] = 0;
    characters[2] = 0;
    characters[3] = 0;
    characters[4] = 0;
}

int get_index(char  **map)
{
    int i;
    
    i = 0;
    while (map[i])
    {
        if (is_map_line(map[i]))
            return (i);
        i++;
    }
    printf("check map file :(\n"), exit(1);
}

void check_chars(int *n)
{
    int i;
    int flag;

    i = 0;
    flag = 0;
    while (i < 4)
    {
        if (n[i] == 1)
            flag++;
        else if (n[i] != 0)
            printf("check map file :(\n"), exit(1);
        i++;
    }
    if (flag != 1)
        printf("check map file :(\n"), exit(1);
}

void check_characters(int   *characters, char  **map, int i)
{
    int l;
    
    l = 0;
    while (map[i])
    {
        l = 0;
        while (map[i][l])
        {
            if (map[i][l] == 'N')
                characters[0] += 1;
            if (map[i][l] == 'W')
                characters[1] += 1;
            if (map[i][l] == 'E')
                characters[2] += 1;
            if (map[i][l] == 'S')
                characters[3] += 1;
            l++;
        }
        i++;
    }
    check_chars(characters);
}

void check_num(char **s)
{
    int num;
    int i;
    
    i = 0;
    while (i < 3)
    {
        num = ft_atoi(s[i]);
        if (num < 0 || num > 255)
            printf("R,G,B colors in range [0,255]: 0, 255, 255\n"), exit(1);
        i++;
    }
}

void check_rgb(char **map, int i)
{
    int j;
    char    **split1 = NULL;

    j = 1;
    while (map[i][j] && map[i][j] == ' ')
        j++;
    if (map[i][j])
    {
        split1 = ft_split(&map[i][j], ',');
        if (!split1 || !split1[0] || !split1[1] || !split1[2] || split1[3])
            printf("R,G,B colors in range [0,255]: 0, 255, 255\n"), exit(1);
        if (split1 && split1[0])
            check_num(split1);
        free(split1);
    }
    else
        printf("R,G,B colors in range [0,255]: 0, 255, 255\n"), exit(1);

}

void check_colors(char **map)
{
    int i;

    i = 0;
    while (map[i])
    {
        if (map[i][0] == 'F' || map[i][0] == 'C')
            check_rgb(map, i);
        i++;
    }
}

void check_map(char **map)
{
    int    characters[5];

    fill_characters(characters);
    check_characters(characters, map, get_index(map));
}

void check_file(char  **map)
{
    check_elements(map);
    check_colors(map);
    check_map(map);
    printf("MAP IS READY\n");
    exit (1);
}
