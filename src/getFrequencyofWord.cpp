/*

Problem : Return the Count of how many times the word occurred in given string in two ways
Way1: Not using Recursion
Way2:Using Recursion [Optional]

Input : "Hello HelloAgain HelloAGAINAGAIN commonItsHelloagain","Hello"
Output : 4

Note: Dont modify original str or word,Just return count ,Spaces can also be part of words like "ab cd" in "ab cd ab cd" returns 2
*/

#include <stdlib.h>
#include <stdio.h>
int count_word_in_str_way_1(char *str, char *word){
	int index = 0, j, count = 0, len_str = 0;
	for (len_str = 0; str[len_str] != '\0'; len_str++);
	while (index < len_str){
		j = 0;
		if (word[1] == '\0'){//if word contains only one character
			if (str[index] == word[0])
				count = count + 1;
			index++;
		}
		else {
			if (str[index++] == word[j++]){//if a character in str string and first character in word string match
				while (word[j] != '\0'){//loop to check for remaining charactersin str string
					if (str[index] == word[j])
						index++, j++;
					else
						break;
				}
				if (word[j] == '\0'){//if word string present in str string
					count++;
				}
			}
			else{

				index++;
			}
			if (str[index - 1] == word[0] && str[index] != '\0'){//if the last character of the word string  in the str string is equal to the first character in the word string eg:str<-"aaaa", word<-"aa"
				index--;
			}
		}
	}
	return count;
}
int count_word_recursion(char *str, char *word, int len_str, int *count, int index){
	if (index >= len_str)
		return *count;
	int j = 0;
	if (word[1] == '\0'){//if word contains only one character
		if (str[index] == word[0])
			*count = *count + 1;
		index++;
	}
	else {
		if (str[index++] == word[j++]){//if a character in str string and first character in word string match
			while (word[j] != '\0'){//loop to check for remaining charactersin str string
				if (str[index] == word[j])
					index++, j++;
				else
					break;
			}
			if (word[j] == '\0'){//if word string present in str string
				(*count)++;
			}
		}
		else{

			index++;
		}
		if (str[index - 1] == word[0] && str[index] != '\0'){//if the last character of the word string  in the str string is equal to the first character in the word string eg:str<-"aaaa", word<-"aa"
			index--;
		}
	}
	*count = count_word_recursion(str, word, len_str, count, index);
	return *count;
}
int count_word_int_str_way_2_recursion(char *str, char *word){
	int count = 0;
	int len_str = 0, len_word = 0;
	for (len_str = 0; str[len_str] != '\0'; len_str++);
	count = count_word_recursion(str, word, len_str, &count, 0);
	return count;
}