#include <stdio.h>

// This function will return a length of a string
int len(char c[])
{
    int a = 0;
    for (int i = 0; c[i] != '\0'; i++)
    {
        a++;
    }
    return a;
}

// This funtion will change case of a string
void changeCase(char c[])
{
    for (int i = 0; c[i] < '\0'; i++)
    {
        if (c[i] >= 'A' && c[i] <= 'Z')
        {
            c[i] = c[i] + 32;
        }
        else if (c[i] >= 'a' && c[i] <= 'z')
        {
            c[i] = c[i] - 32;
        }
    }
}

// Covert all letter to lowercase
void uppercase(char c[])
{
    for (int i = 0; i < c[i]; i++)
    {
        if (c[i] >= 'A' && c[i] <= 'Z')
        {
            c[i] += 32;
        }
    }
}

// Covert all letter to uppercase
void uppercase(char c[])
{
    for (int i = 0; i < c[i]; i++)
    {
        if (c[i] >= 'a' && c[i] <= 'z')
        {
            c[i] -= 32;
        }
    }
}

// This function will count vowel ,consonant and other word in a string and return an array
int *vowelConsonant(char c[])
{
    static int count[3];
    int a = 0, v = 0, o = 0;
    for (int i = 0; c[i] != '\0'; i++)
    {
        if (c[i] == 'a' || c[i] == 'e' || c[i] == 'i' || c[i] == 'o' || c[i] == 'u' || c[i] == 'A' || c[i] == 'E' || c[i] == 'I' || c[i] == 'O' || c[i] == 'U')
        {
            a++;
        }
        else if ((c[i] >= 'a' && c[i] <= 'z') || (c[i] >= 'A' && c[i] <= 'Z'))
        {
            v++;
        }
        else
        {
            o++;
        }
    }
    count[0] = a;
    count[1] = v;
    count[2] = o;
    return count;
}

// This function will chech that string is containg any non-alphanumberic character or not
int validString(char c[])
{
    int ans = 1;
    for (int i = 0; c[i] != '\0'; i++)
    {
        if (!(c[i] >= 'A' && c[i] <= 'Z') && !(c[i] >= 'a' && c[i] <= 'z') && !(c[i] >= '0' && c[i] <= '9'))
        {
            ans = 0;
            break;
        }
    }
    return ans;
}

// This function will reverse the string parameter required are length of a string with string
void reverseString(char c[], int j)
{
    int i = 0;
    j--;
    while (i < j)
    {
        char temp = c[i];
        c[i] = c[j];
        c[j] = temp;
        i++;
        j--;
    }
}

// This function will find duplicates letter in a string and display it using bit operator
void duplicates(char c[])
{
    int a = 0;
    for (int i = 0; c[i] != '\0'; i++)
    {
        int b = 1;
        if (c[i] >= 'A' && c[i] <= 'Z')
        {
            c[i] += 32;
        }
        b = b << c[i] - 97;
        if ((a & b) > 0)
        {
            printf("%c", c[i]);
            printf(" ");
        }
        else
        {
            a = b | a;
        }
    }
}

// This function will check that 2 string are anagram
int anagram(char s1[], char s2[])
{
    int ans = 1;
    if (len(s1) != len(s2))
    {
        ans = 0;
        return ans;
    }
    int h[26] = {0};
    for (int i = 0; s1[i] != '\0'; i++)
    {
        if (s1[i] >= 'A' && s1[i] <= 'Z')
        {
            s1[i] += 32;
        }
        int a = s1[i] - 97;
        h[a]++;
    }
    for (int i = 0; s2[i] != '\0'; i++)
    {
        if (s2[i] >= 'A' && s2[i] <= 'Z')
        {
            s2[i] += 32;
        }
        int a = s2[i] - 97;
        h[a]--;
    }
    for (int i = 0; i < 26; i++)
    {
        if (h[i] != 0)
        {
            ans = 0;
            return ans;
        }
    }
    return ans;
}

// This function will display string
void display(char c[])
{
    for (int i = 0; c[i] != '\0'; i++)
    {
        printf("%c", c[i]);
    }
    printf("\n");
}

int main()
{
    printf("Enter string : ");
    char s1[10], s2[10];
    scanf("%s", &s1);
    // scanf("%s", &s2);
    // To call any function write name give argrument such as display(s1);
    return 0;
}