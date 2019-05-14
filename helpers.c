//Salissou Gomna Ilham

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include "helpers.h"
#include <math.h>

//convert a fraction to eighths
int duration (string fraction)
{
    int x = fraction[0] - '0';
    int y = fraction[2] - '0';
    int dur = x * (8 / y);
    return dur;
}

//calculate frequency of a note
int frequency (string note)
{
    //adjust for octave
    int octave;
    int n = 0;
    if (strlen(note) == 3)
    {
        octave = atoi (&note[2]);
        char accident = note[1];
        if (accident == '#')
        {
            n = n + 1;
        }
        else if (accident == 'b')
        {
            n = n - 1;
        }
    }
    else
    {
        octave = atoi (&note[1]);
    }

    char letter = note[0];
    if (letter == 'A')
    {
        n += 0;
    }
    else if (letter == 'B')
    {
        n += 2;
    }
    else if (letter == 'C')
    {
        n -= 9;
    }
    else if (letter == 'D')
    {
        n -= 7;
    }
    else if (letter == 'E')
    {
        n -= 5;
    }
    else if (letter == 'F')
    {
        n -= 4;
    }
    else if (letter == 'G')
    {
        n -= 2;
    }

    //printf("%i\n",n);
    n = n + (octave - 4)*12.;

    float power = n/12;
    //printf("%f\n", power);
    float f = round(pow(2, power)*440);
    //printf ("%f\n",f);
    return f;
}

//determines if a string represents a rest
bool is_rest (string s)
{
    return strlen(s) == 0;
}