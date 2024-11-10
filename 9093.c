/* 
---------------------------------------------------------------------------------------
문제 : 
문장이 주어졌을 때, 단어를 모두 뒤집어서 출력하는 프로그램을 작성하시오.
단, 단어의 순서는 바꿀수 없다. 단어는 영어 알파벳으로만 이루어져 있다. 
---------------------------------------------------------------------------------------
입력 :
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있으며, 문장이 하나 주어진다.
단어의 길이는 최대 20, 문장의 길이는 최대 1000이다. 단어와 단어 사이에는 공백이 하나 있다.
---------------------------------------------------------------------------------------
출력 : 
각 테스트 케이스에 대해서, 입력으로 주어진 문장의 단어를 모두 뒤집어 출력한다.
---------------------------------------------------------------------------------------
*/

// 함수원형 : char* fgets(char* str, int num, FILE* pFile);
// -> fgets 함수는 공백을 포함한 전체줄을 읽음. / getchar()는 scanf로 정수를 입력받을 때 남아있는 개행문자를 제거함.
#include <stdio.h>
#include <string.h>

char str[1001] = {0};


void reversesentence(char *str)
{
    int length = strlen(str);
    int left = 0;
    int right = length - 1;

    while (left < right)
    {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;

        left++;
        right--;
    }
}

int main()
{
    int test;

    scanf ("%d\n", &test);
    //getchar();

    for (int i=0; i<test; i++)
    {
        fgets(str, sizeof(str), stdin);

        char words[1001][21] = {0};
        int word_count = 0;
        int word_index = 0;

        for (int j=0; j<strlen(str); j++)
        // strlen() : const char* 타입의 문자열을 받아서 해당 문자열의 길이를 반환하는 함수.
        {
            if (str[j]==' ' || str[j] == '\n' || str[j] == '\0')
            {
                word_count++;
                word_index = 0;

            }
            else
            {
                words[word_count][word_index] = str[j];
                word_index++;
            }
        }

        for (int k=0; k<word_count; k++)
        {
            reversesentence(words[k]);
            printf("%s", words[k]);
            if (k<word_count-1)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}