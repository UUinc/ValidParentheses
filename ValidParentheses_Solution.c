#include<stdio.h>
#include<string.h>

//Functions Declaration
int ParenthesesValidator(char *s);
void Push(char c);
void Pop();
char Show();
//Global
char Stack[10000];int Index=-1;

int main()
{
	char s[10000];

	scanf("%s", s);

	printf("%s",Stack);

	if(ParenthesesValidator(s))
		printf("true");
	else
		printf("false");

	return 0;
}
//Parentheses Validator Function creation
int ParenthesesValidator(char *s)
{
    int i, len, counter=0;

	len = strlen(s);

	//the string should be pair
	if(len%2 != 0
    || (s[len-1] == '(' || s[len-1] == '{' || s[len-1] == '[')
    || (s[0] == ')' || s[0] == '}' || s[0] == ']'))
		return 0;

    for(i=0; i<len;i++)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            Push(s[i]); counter++;
        }
        else
        {
            //to know if the closing parenthese is the same type
            if((Show() == '(' && s[i] != ')')
            || (Show() == '{' && s[i] != '}')
            || (Show() == '[' && s[i] != ']')
            || Show() == ' ')
                return 0;
            Pop(); counter--;
        }
    }
    if(counter != 0)
        return 0;

    return 1;
}
void Push(char c)
{
    Index++;
    Stack[Index] = c;
}
void Pop()
{
    Stack[Index] = '\0';
    Index--;
}
char Show()
{
    if(Index > -1)
        return Stack[Index];
    else
        return ' ';
}
