#include <stdio.h>
#include <string.h>
char* removeUtil(char* str, char* last_removed)
{

	// If length of string is 1 or 0
	if (str[0] == '\0' || str[1] == '\0')
		return str;
	if (str[0] == str[1]) {
		*last_removed = str[0];
		while (str[1] && str[0] == str[1])
			str++;
		str++;
		return removeUtil(str, last_removed);
	}
	char* rem_str = removeUtil(str + 1, last_removed);
	if (rem_str[0] && rem_str[0] == str[0]) {
		*last_removed = str[0];
		return (rem_str + 1);
	}
	if (rem_str[0] == '\0' && *last_removed == str[0])
		return rem_str;
	rem_str--;
	rem_str[0] = str[0];
	return rem_str;
}
char* removes(char* str)
{
	char last_removed = '\0';
	return removeUtil(str, &last_removed);
}

// Driver program to test above functions
int main()
{
	char str1[] = "geeksforgeeg";
	printf("%s\n", removes(str1));

	char str2[] = "azxxxzy";
	printf("%s\n", removes(str2));

	char str3[] = "caaabbbaac";
	printf("%s\n", removes(str3));

	char str4[] = "gghhg";
	printf("%s\n", removes(str4));

	char str5[] = "aaaacddddcappp";
	printf("%s\n", removes(str5));

	char str6[] = "aaaaaaaaaa";
	printf("%s\n", removes(str6));

	char str7[] = "qpaaaaadaaaaadprq";
	printf("%s\n", removes(str7));

	char str8[] = "acaaabbbacdddd";
	printf("%s\n", removes(str8));

	char str9[] = "acbbcddc";
	printf("%s\n", removes(str9));

	return 0;
}


