#include <stdio.h>
#include <string.h>
#include "math.h"

void convertToBinary(char str[], int binary[]);

void convertToString(int binary[], char str[]);

void transitByMatrix(int binary_in[],int matrix[], int binary_out[]);


int main(int argc, const char * argv[])
{
    //Encryption matrix
	int encryption[65] ={0,
        58,50,42,34,26,18,10, 2,
        60,52,44,36,28,20,12, 4,
        62,54,46,38,30,22,14, 6,
        64,56,48,40,32,24,16, 8,
        57,49,41,33,25,17, 9, 1,
        59,51,43,35,27,19,11, 3,
        61,53,45,37,29,21,13, 5,
        63,55,47,39,31,23,15, 7};
    
    //Decryption matrix
	int decryption[65] ={0,
        40, 8,48,16,56,24,64,32,
        39, 7,47,15,55,23,63,31,
        38, 6,46,14,54,22,62,30,
        37, 5,45,13,53,21,61,29,
        36, 4,44,12,52,20,60,28,
        35, 3,43,11,51,19,59,27,
        34, 2,42,10,50,18,58,26,
        33, 1,41, 9,49,17,57,25};
    
    
	char str_input[30];
	char str_en[10];
	char str_de[10];
	int binary_input[65];
	int binary_en[65];
	int binary_de[65];
    scanf("%s", str_input);
	while(strlen(str_input) != 8)
	{
		printf("The length of string you input is not 8,please input again.\n");
		scanf("%s", str_input);
    }


    //Encryption
    convertToBinary(str_input, binary_input);
    transitByMatrix(binary_input, encryption, binary_en);
    convertToString(binary_en, str_en);
    printf("%s\n", str_en);
    
    //Decryption
    convertToBinary(str_en, binary_de);
    transitByMatrix(binary_en, decryption, binary_de);
    convertToString(binary_de, str_de);
    printf("%s\n", str_de);
}

void convertToBinary(char str[], int binary[])
{
    int length, i, j;
    length = (int)strlen(str);
    for (i = 0; i < length; ++i)
    {
    	for (j = 0; j < 8; ++j)
    	{
    		binary[i * 8 + 8 - j] = str[i] % 2;
    		str[i] = str[i] / 2;
    	}
    }
    if (length != 8)
    {
    	for (i = length; i < 8; ++i)
    	{
    		for (j = 0; i < 8; ++i)
    		{
    			binary[i * 8 + j + 1] = 0;
    		}
    	}
    }
}

void convertToString(int binary[], char str[])
{
	int i, j;
	for (i = 0; i < 8; ++i)
	{
		str[i] = 0;
		for (j = 0; j < 8; ++j)
		{
			str[i] += binary[i * 8 + j + 1] * pow(2, 7 - j);
		}
	}
    str[8] = '\0';
    
}
void transitByMatrix(int binary_in[],int matrix[], int binary_out[])
{
	int i;
	for (i = 1; i < 65; ++i)
	{
		binary_out[matrix[i]] = binary_in[i];
	}
}