/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   morse_decoder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssama <youssama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 22:38:18 by youssama          #+#    #+#             */
/*   Updated: 2022/04/03 22:38:25 by youssama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

const char *morse[55] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", ".-.-.-", "--..--", "..--..", ".----.", "-.-.--", "-..-.", "-.--.", "-.--.-", ".-...", "---...", "-.-.-.", "-...-", ".-.-.", "-....-", "..--.-", ".-..-.", "...-..-", ".--.-.", "...---..."};  
const char *ascii[55] = {"A",  "B",    "C",    "D",   "E", "F",    "G",   "H",    "I",  "J",    "K",   "L",    "M",  "N",  "O",   "P",    "Q",    "R",   "S",   "T", "U",   "V",    "W",   "X",    "Y",    "Z",    "0",     "1",     "2",     "3",     "4",     "5",     "6",     "7",     "8",     "9",     ".",      ",",      "?",      "'",      "!",      "/",     "(",     ")",      "&",     ":",      ";",      "=",     "+",     "-",      "_",      "\"",     "$",       "@",      "SOS"};

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*p;
	int		p_len;
	int		i;
	int		j;

	j = 0;
	i = 0;
    if (!s1)
    {
        s1 = (char *)malloc(sizeof(char));
        s1[0] = '\0';
    }
	if (!s2)
		return (NULL);
	p_len = strlen(s1) + strlen(s2) + 1;
	p = (char *)malloc(sizeof(char) * p_len);
	if (!p)
		return (NULL);
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j])
		p[i++] = s2[j++];
	p[i] = '\0';
    free(s1);
	return (p);
}

int find(const char *mor_code, int min, int max, const char **mor)
{
    int i=0;
    int j=0;
    int k=0;
    while(mor[i])
    {
        j = min;
        k = 0;
        while(j < max && mor[i][k] && mor_code[j] == mor[i][k])
        {
            if (mor[i][k+1] == '\0' && max - min - 1 == k)
                return (i);
            j++;
            k++;
        }
        i++;
    }
    return (-1);
}

char *decode_morse(const char* morse_code)
{
    int i=0;
    int j=0;
    int j_ind= 0;
    int index = -1;

    char *res = NULL;
    while (morse_code[i])
        i++;
    j_ind = i - 1;
    while(morse_code[j_ind] == ' ')
        j_ind--;
    i = 0;
    while (morse_code[i])
    {
        while(morse_code[i] == ' ')
            i++;
        if (!morse_code[i])
            break;
        j = i;
        while (morse_code[j] && morse_code[j] != ' ')
            j++;
        index = find(morse_code, i, j, morse);
        res = ft_strjoin(res, ascii[index]);
        if (morse_code[j])
        {
            index = j;
            while (morse_code[index] == ' ')
                index++;
            if (morse_code[index] && morse_code[j] == ' ' && morse_code[j + 1] == ' ')
                res = ft_strjoin(res, " ");
        }
            
        index = -1;
        i = j;
    }
    return res;
}

// int main()
// {
//     printf("|%s|",decode_morse("      ...---... -.-.--   - .... .   --.- ..- .. -.-. -.-   -... .-. --- .-- -.   ..-. --- -..-   .--- ..- -- .--. ...   --- ...- . .-.   - .... .   .-.. .- --.. -.--   -.. --- --. .-.-.-      "));
// }
