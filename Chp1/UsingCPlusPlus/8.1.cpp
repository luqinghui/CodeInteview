#include <stdio.h>
#include <string.h>

bool isUnique(char *str) {
	if (strlen(str) > 256)
		return false;

	bool char_set[256] = {false};

	for (char *p = str; *p != '\0'; *p++) {
		int i = (int)*p;
		if (char_set[i])
			return false;

		char_set[i] = true;
	}
	return true;
}

bool isUniqueVer2(char *str) {
	if (strlen(str) > 26)
		return false;
	int char_set = 0;
	for (char*p = str; *p != '\0'; *p++) {
		int i = (int)*p;
		if (char_set & (1 << i) > 0)
			return false;
		char_set |= (1 << i);
	}
	return true;
}

void AlgorithmOneOne() {
	char *str = "This";
	if (isUniqueVer2(str))
		printf("Unique");
	else
		printf("No Unique");
}



void reverse(char *str){
	int len = strlen(str);
	int mid = len/2;

	for (int i = 0; i < mid; i++) {
		char t = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = t;
	}
}

void AlgorithmOneTwo() {
	char *str = "This is one.";
	printf("%s\n", str);

	reverse(str);
	printf("%s\n", str);
}

