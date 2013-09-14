#include "stdio.h"
#include "string.h"
#include "ctype.h"
#include "math.h"
#define PATH_IN "/Users/veightz/Documents/base.in"
#define PATH_OUT "/Users/veightz/Documents/base3.out"

//Judge the character string, if it's legal, function returns 1,else return 0.
int toNum(char str[], int num[]);

//Return the index of the largest value.
int findMax(int num[], int length);

//Convert the number in array num to base 10 in any base, then store into array decimalism.
void convertTodecimalism(int num[], int decimalism[], int min, int length);

//Judge if there is same number existing in decimalism1 and decimalism2.
int compare(int decimalism1[], int max1, int decimalism2[], int max2, int index[]);

int main(int argc, char const *argv[])
{
	FILE *finp, *foutp;
	int mark1 = 0, mark2 = 0, num1[40] = {0}, num2[40] = {0}, max1, max2;
	char str1[20], str2[20] ;
	int decimalism1[36] = {-1}, decimalism2[36] = {-1};
	int result, index[2];
    

    finp  = fopen(PATH_IN, "r");
    foutp = fopen(PATH_OUT, "w");
    
    while(!feof(finp))
    {
		fscanf(finp, "%s", str1);
		if (str1[0] != '0')
		{
			fscanf(finp, "%s", str2);
		}else
		{
			continue;
		}
        
		mark1 = toNum(str1, num1);
		mark2 = toNum(str2, num2);
	    
		if((mark1 == 1) && (mark2 == 1))
		{
			max1 = findMax(num1, (int)strlen(str1));
			max2 = findMax(num2, (int)strlen(str2));
	        
			convertTodecimalism(num1, decimalism1, max1, (int)strlen(str1));
			convertTodecimalism(num2, decimalism2, max2, (int)strlen(str2));
	        
			result = compare(decimalism1, max1, decimalism2, max2, index);
	        
			if(result == 0)
			{
				fprintf(foutp, "%s is not equal to %s in any base 2..36\n", str1, str2);
			}else
			{
				fprintf(foutp, "%s(base%d) = %s(base%d)\n", str1, index[0], str2, index[1]);
			}
		}else
		{
			if(mark1 == 0)
			{
				fprintf(foutp, "%s is illegal number expression\n", str1);
			}
			if(mark2 == 0)
			{
				fprintf(foutp, "%s is illegal number expression\n", str2);
			}
		}
        
    }
    fclose(finp);
    fclose(foutp);

}


int toNum(char str[], int num[])
{
	int length, i;
	length = (int)strlen(str);
	for(i = 0; i < length; ++i)
	{
		if(isalnum(str[i]))
		{
			if(isdigit(str[i]))
			{
				num[i] = str[i] - '0';
			}
			if(isupper(str[i]))
			{
				num[i] = str[i] - 'A' + 10;
			}
			if(islower(str[i]))
			{
				num[i] = str[i] - 'a' + 10;
			}
		}else
		{
			return 0;
		}
	}
    return 1;
}

int findMax(int num[], int length)
{
	int i, min;
	min = 1;
    
	for(i = 0; i < length; ++i)
	{
		if(num[i] > min)
		{
			min = num[i];
		}
	}
    
	return min;
}

void convertTodecimalism(int num[], int decimalism[], int min, int length)
{
	int i, j;
	for(i = min + 1; i < 36; ++i)
	{
		decimalism[i] = 0;
		for(j = 0; j < length; ++j)
		{
			decimalism[i] += num[j] * (int)pow((double)(i), (double)(length - 1 - j));
		}
	}
}

int compare(int decimalism1[], int max1, int decimalism2[], int max2, int index[])
{
	int i, j;
	for(i = max1 + 1; i < 36; ++i)
	{
		for(j = max2 + 1; j < 36; ++j)
		{
			if(decimalism1[i] == decimalism2[j])
			{
				index[0] = i;
				index[1] = j;
				return 1;
			}
		}
	}
	return 0;
}
