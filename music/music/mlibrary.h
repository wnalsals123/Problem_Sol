#ifndef MLIBRARY_H
#define MLIBRARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song Song;
typedef struct snode SNode;
typedef struct artist Artist;

struct song {
	Artist *artist;
	char *title;
	char *path;
	int index;
};

struct snode {
	struct snode *next, *prev;
	Song *song;
};

struct artist {
	char *name;
	struct artist *next;
	SNode *head, *tail;
};

int read_line(FILE *, char str[], int);
void initialize();
void add_song(char *, char *, char *);
void status();
void load(FILE *);
void search_song(char *, char *);
void search_song(char *);
void play(int);
void save(FILE *);
void remove(int);

#endif