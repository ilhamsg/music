//Salissou Gomna Ilham

#include <stdio.h>
#include <cs50.h>
#include <inttypes.h>
#define bool _Bool

//representation of a note
typedef struct note
{
    int frequency;
    int duration;
}
note;

//representation of a song
struct song
{
    string filename;
    note **notes;
    size_t capacity;
    size_t size;
    int duration;
};
typedef struct song *songs;

//add a note to the song
bool note_write ( struct song s, int frequency, int duration);

//add a pause to a song
bool rest_write (struct song s, int duration);

//save a song on the disque
bool song_close (struct song s);

//create a new song
struct song song_open (string filename);