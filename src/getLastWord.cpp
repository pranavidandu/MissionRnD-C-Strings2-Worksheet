/*

Problem : Return the Last word in a string

Input : I will do this without using String Library
Output : Library

Note:Dont modify original string Neglect Spaces at the right end and at left end if required .
->Create a new string and return it , Use dynamic memory allocation .
*/
#include <stdlib.h>

char * get_last_word(char * str){
	if (str == NULL)
		return NULL;
	int len = 0;
	for (len = 0; str[len] != '\0'; len++);
	int index = len - 1;
	if (len > 1){
		while (str[index] != ' ')
			index--;
	}
	char *last_word = (char*)malloc(sizeof(char) * (len - index));
	int i = 0;
	while (index < len){
		last_word[i++] = str[index++];
	}
	last_word[i] = '\0';
	return last_word;
}
