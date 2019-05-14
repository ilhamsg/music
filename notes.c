//Salissou Gomna Ilham

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include "helpers.h"
#include "wav.h"

//notes in an octave
const string NOTES[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};

//default octave
#define OCTAVE 4

int main (int argc, string argv[])
{
    //replace the default octave when it is specify in the command line
    int octave = OCTAVE;
    if (argc == 2)
    {
        octave = atoi (argv[1]);
        if (octave < 0 || octave > 8)
        {
            fprintf (stderr, "invalid octave\n");
            return 1;
        }
    }
    else if (argc > 2)
    {
        fprintf (stderr, "NOTES [OCTAVE]\n");
        return 1;
    }
struct song s = song_open ("notes.wav");

//add each semitone
for (int i = 0, n = sizeof(NOTES)/sizeof(string); i < n; i++)
{
    //add an octave to a note
    char note[4];
    sprintf (note, "%s%i", NOTES[i], octave);
    //calculate the frequency
    int f = frequency (note);
    printf ("%3s: %i\n", note, f);
}
song_close (s);
}