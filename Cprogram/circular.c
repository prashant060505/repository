#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
// Define the structure for a song node 
struct Song { 
char title[100]; 
char artist[100]; 
struct Song* next; 
}; 
// Function to create a new song node 
struct Song* createSong(const char* title, const char* artist) { 
struct Song* newSong = (struct Song*)malloc(sizeof(struct Song)); 
if (newSong == NULL) { 
printf("Memory allocation failed.\n"); 
return NULL; 
} 
strncpy(newSong->title, title, sizeof(newSong->title)); 
strncpy(newSong->artist, artist, sizeof(newSong->artist)); 
newSong->next = NULL; 
return newSong; 
} 
// Function to add a song to the end of the playlist 
struct Song* addSong(struct Song* playlist, const char* title, const char* artist) { 
struct Song* newSong = createSong(title, artist); 
if (newSong == NULL) { 
return playlist; 
} 
if (playlist == NULL) { 
playlist = newSong; 
playlist->next = playlist; // Circular link to itself 
} else { 
struct Song* current = playlist; 
while (current->next != playlist) { 
current = current->next; 
} 
current->next = newSong; 
newSong->next = playlist; 
} 
return playlist; 
} 
// Function to skip to the next song 
struct Song* skipToNext(struct Song* playlist) { 
if (playlist == NULL) { 
printf("Playlist is empty.\n"); 
return playlist; 
} 
playlist = playlist->next; // Move to the next song 
return playlist; 
} 
// Function to remove the currently playing song 
struct Song* removeCurrentSong(struct Song* playlist) { 
if (playlist == NULL) { 
printf("Playlist is empty.\n"); 
return playlist; 
} 
if (playlist->next == playlist) { 
// Only one song in the playlist 
free(playlist); 
return NULL; 
} 
struct Song* current = playlist; 
while (current->next != playlist) { 
current = current->next; 
} 
struct Song* temp = playlist; 
current->next = playlist->next; // Remove the current song from the circular list 
playlist = playlist->next; // Move to the next song 
free(temp); 
return playlist; 
} 
// Function to display the currently playing song 
void displayCurrentSong(struct Song* playlist) { 
if (playlist == NULL) { 
printf("Playlist is empty.\n"); 
} else { 
printf("Currently Playing: %s by %s\n", playlist->title, playlist->artist); 
} 
} 
// Function to display the entire playlist 
void displayPlaylist(struct Song* playlist) { 
if (playlist == NULL) { 
printf("Playlist is empty.\n"); 
return; 
} 
struct Song* current = playlist; 
do { 
printf("%s by %s\n", current->title, current->artist); 
current = current->next; 
} while (current != playlist); 
} 
int main() { 
struct Song* playlist = NULL; 
int choice; 
char title[100], artist[100]; 
while (1) { 
printf("\nMenu:\n"); 
printf("1. Add a Song\n"); 
printf("2. Skip to Next Song\n"); 
printf("3. Remove Currently Playing Song\n"); 
printf("4. Display Currently Playing Song\n"); 
printf("5. Display Playlist\n"); 
printf("6. Exit\n"); 
printf("Enter your choice: "); 
scanf("%d", &choice); 
switch (choice) { 
case 1: 
printf("Enter the title of the song: "); 
scanf(" %[^\n]s", title); 
printf("Enter the artist of the song: "); 
scanf(" %[^\n]s", artist); 
playlist = addSong(playlist, title, artist); 
break; 
case 2: 
playlist = skipToNext(playlist); 
break; 
case 3: 
playlist = removeCurrentSong(playlist); 
break; 
case 4: 
displayCurrentSong(playlist); 
break; 
case 5: 
displayPlaylist(playlist); 
break; 
case 6: 
// Clean up and exit 
while (playlist != NULL) { 
playlist = removeCurrentSong(playlist); 
} 
return 0; 
default: 
printf("Invalid choice. Please try again.\n"); 
} 
} 
return 0; 
}