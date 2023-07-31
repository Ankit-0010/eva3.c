#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random alphanumeric character
char generate_random_character()
{
    int random_character = rand() % 16;
    if (random_character < 10)
        return '0' + random_character;
    else
        return 'A' + (random_character - 10);
}

// Function to generate a random alphanumeric string of random length between 3 and 10 characters
void grs(char *rstr)
{
	int i;
    int l = rand() % 8 + 3; // Random length between 3 and 10
    for (i = 0; i < l; i++) {
        rstr[i] = generate_random_character();
    }
    rstr[l] = '\0'; // Null-terminate the string
}

// Function to determine the highest base of the alphanumeric string
int base(char *rstr)
{
    int b = 0;
    while (*rstr != '\0')
	{
        int r;
        if (*rstr >= '0' && *rstr <= '9')
            r = *rstr - '0';
        else if (*rstr >= 'A' && *rstr <= 'F')
            r = *rstr - 'A' + 10;
        else
		{
            printf("Invalid character in string: %c\n", *rstr);
            exit(1);
        }

        if (r > b)
            b = r;

        rstr++;
    }
    return b+1; // Adding 1 to get the highest base
}

int main()
{
    // Initialize random seed
    srand(time(0));

    char rs[11]; // Maximum length will be 10 + 1.
    
    grs(rs);
    
    //printf("Random Alphanumeric String: %s\n", rs);

    int B = base(rs);
    printf("The Highest Base of %s is %d\n", rs, B);

    return 0;
}

