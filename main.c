#include <stdio.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <dirent.h>

#include "include/linkedList.h"

struct Song {
    char* name;
    char* filename;
    char* autor;
    size_t length;
} typedef Song;

char* strdup (const char* s){
    size_t len = strlen (s) + 1;
    char* copy = malloc (len);

    if (copy) {
        memcpy (copy, s, len);
    }
    return copy;
}

void addSongsToList (LinkedList* list, const char* path) {
    DIR* directoryPointer;

    struct dirent* directory;

    directoryPointer = opendir (path);

    if (directoryPointer) {
        while ((directory = readdir (directoryPointer))) {

            if (strcmp(directory->d_name, ".") == 0 || strcmp(directory->d_name, "..") == 0) {
                continue;
            }

            Song* song = (Song*) malloc (sizeof (Song));
            song->autor = "";
            song->length = 0;
            song->filename = strdup (directory->d_name);

            char* dotPosition = strrchr (directory->d_name, '.');

            dotPosition[0] = '\0';

            song->name = directory->d_name;

            push (list, song);
        }
    }
}


int main (void) {
    LinkedList* list = linkedListInit ();

    char* directory = "./songs";

    addSongsToList (list, directory);
    Node* currentSong = getFirstNode(list);

    while (1) {
        if (currentSong) {
            Song* song = currentSong->data;
            printf ("Piosenka: %s\n(Kliknij 1 aby wlaczyc nastepna i 2 aby poprzednia):", song->name);

            char buffer[256];
            scanf ("%s", buffer);

            if (!strcmp (buffer, "1")) {
                currentSong = getNextNode (currentSong);
            }
            else if (!strcmp(buffer, "2")) {
                currentSong = getPrevNode (currentSong);
            }
        }
        else {
            currentSong = getFirstNode (list);
        }
    }

    freeList (list);
    list = NULL;
}