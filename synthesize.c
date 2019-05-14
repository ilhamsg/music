//Salissou Gomna Ilham

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include "helpers.h"
#include "wav.h"

int main (int argc, string argv[])
{
    //command line arguments
    if (argc != 2)
    {
        fprintf (stderr,"synthesize FILE\n");
        return 1;
    }
    string filename = argv[1];

    //open file for writing
    struct song s = song_open (filename);

    //expect notes from user until end of file
    while (true)
    {
        string line = get_string (" ");
        if (line == NULL)
        {
            break;
        }
        //verify end of the list
        if (is_rest(line))
        {
            rest_write (s, 1);
        }
        else
        {
            string note = strtok (line, "@");
            string fraction = strtok (NULL, "@");
            //write a note to the chanson
            note_write (s, frequency(note), duration(fraction));
        }
    }
    song_close(s);
}