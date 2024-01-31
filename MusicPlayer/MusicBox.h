#ifndef MUSIC_BOX
#define MUSIC_BOX
#include "DoublyLinkedList.h"
#include "Song.h"

/**
 * A music box will maintain a playlist which is implemented using a doubly linked list of
Songs.
 *
 * @author Zichen Men <zichen.men@bellevuecollege.edu>
 * @date 11/2/2023
 * @version ___1.0___
 */

class MusicBox
{
private:
    DoublyLinkedList<Song> playlist;
    Node<Song> *pCurrent;

public:
    /**
     * Default Constructor.
     * Initialize currentSong to null.
     */
    MusicBox();

    /**
     * Add a song to the end of the playlist.
     * @param title the title of the song.
     * @param duration the duration of the song.
     */
    void addSong(const std::string &title, int duration);

    /**
     * Remove a specified song from the playlist.
     * @param title the title of the song that need to be removed.
     */
    bool removeSong(const std::string &title);

    /**
     * Searches for a specified song in the playlist.
     * @param title the titile of the song.
     */
    bool searchSong(const std::string &title);

    /**
     * Advances the current position to the next song in the playlist.
     * If the current song is the last in the playlist, it wraps around to the first song.
     */
    void playNext();

    /**
     * Advances the current position to the previous song in the playlist.
     * If the current song is the first in the playlist, it wraps around to the last song.
     */
    void playPrevious();

    /**
     * Returns the currently playing song.
     */
    void currentSong() const;

    /**
     * Displays all the songs in the playlist.
     */
    void displayPlaylist();

    /**
     * Sorts the playlist by the titles of the songs using the quick sort algorithm,
     * choosing the initial song as the pivot point.
     */
    void sort();

    /**
     * Helper function for quick sort.
     * @param low first song.
     * @param high last song.
     */
    Node<Song> *partition(Node<Song> *low, Node<Song> *high);

    /**
     * The recursive quick sort utility.
     * @param low first song.
     * @param high last song.
     */
    void quickSort(Node<Song> *low, Node<Song> *high);

    /**
     * Shuffle the songs in the playlist
     */
    void shuffle();
};

#include "MusicBox.cpp"
#endif