#include <iostream>
using namespace std;

#define LEN 101

int stringToWordsList(char string[LEN], char* wordsList[LEN]);

void wordsListToString(char *wordsList[LEN], int wordsAmount);

void swapStrings(char str1[LEN], char str2[LEN]);
void sort(char *wordsList[LEN], int size);

int main()
{
	char string[LEN];
	char *wordsList[LEN];
	int wordCount = 0;

	cout << "Enter string: ";
	cin.get(string, LEN);

	cout << "String: " << string << "\n\n";

	wordCount = stringToWordsList(string, wordsList);
	sort(wordsList, wordCount);
	wordsListToString(wordsList, wordCount);
	system("pause");


	return 0;
}


int stringToWordsList(char string[LEN], char *wordsList[LEN])
{
	int i = 0;
	char delim[] = " ";
	char* ptr = strtok(string, delim);

	while (ptr != NULL)
	{
		wordsList[i++] = ptr;
		ptr = strtok(NULL, delim);
	}

	return i;
}

void wordsListToString(
	char *wordsList[LEN],
	int wordsAmount)
{
	for (int i = 0; i < wordsAmount; i++)
	{
		printf("%s ", wordsList[i]);
	}
	printf("\n");
}


void sort(char *wordsList[LEN], int size)
{
	for (int i = 1; i < size; i += 2)
	for (int j = 1; j < size - 2; j += 2)
	if (strcmp(wordsList[j], wordsList[j + 2]) > 0)
		std::swap(wordsList[j], wordsList[j + 2]);
}