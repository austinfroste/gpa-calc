#include <stdio.h>
#include <stdlib.h>

double addToGPA (char *tmpGrade)
{
    double result = 0.0;
    char tmpLetter = tmpGrade[0];
    char tmpSign = tmpGrade[1];
    
    // check letter grade
    if (tmpLetter == 'A')
    {
        result = 4.0;
    }
    else if (tmpLetter == 'B')
    {
        result = 3.0;
    }
    else if (tmpLetter == 'C')
    {
        result = 2.0;
    }
    else if (tmpLetter == 'D')
    {
        result = 1.0;
    }
    else if (tmpLetter == 'F')
    {
        result = 0.0;
    }
    else
    {
        printf("\"%s\" is not a valid grade.\n", tmpGrade);
        exit(EXIT_FAILURE);
    }
    
    // check if plus/minus exists
    if (tmpSign == '-' && result > 0)
    {
        result -= 0.3;
    }
    else if (tmpSign == '+')
    {
        result += 0.3;
    }
    
    return result;
}

int addToCredits(char *tempCredit)
{
    int result = 0;
    
    result = tempCredit[0] - 48;
    
    if (!(result > 0 && result <= 9)) // max credits is 9
    {
        printf("Invalid credit quantity was entered.\n");
        exit(EXIT_FAILURE);
    }
    
    return result;
}

int main (int argc, char *argv[])
{
    // validate class quantity
    if (argc < 3)
    {
        printf("Usage: [class_n_letter_grade] [class_n_credits]\n");
        exit(EXIT_FAILURE);
    }
    
    int classesCount = (argc-1)/2;
    int firstGradePos = 1;
    double GPA = 0.0;
    int creditsTemp = 0;
    int creditsTotal = 0;
    
    // calculate GPA
    for (int i = 0; i < classesCount; i++)
    {
        // evaluate credits amount
        creditsTemp = addToCredits(argv[firstGradePos + (i*2) + 1]);
        creditsTotal += creditsTemp;
        
        // evaluate gpa
        GPA += creditsTemp * addToGPA(argv[firstGradePos + (i*2)]);
    }
    
    // calculate the final gpa
    GPA = GPA / creditsTotal;
    
    // display the results
    printf("Your total GPA is %.3f\n", GPA);
}
