#include "MusicBox.h"
#include <iostream>
#include <algorithm>

/**
 * A music box will maintain a playlist which is implemented using a doubly linked list of
Songs.
 *
 * @author Zichen Men <zichen.men@bellevuecollege.edu>
 * @date 11/2/2023
 * @version ___1.0___
 */

/**
 * Default Constructor.
 * Initialize currentSong to null.
 */
MusicBox::MusicBox() : pCurrent(nullptr) {}

/**
 * Add a song to the end of the playlist.
 * @param title the title of the song.
 * @param duration the duration of the song.
 */
void MusicBox::addSong(const std::string &title, int duration)
{
    Song newSong(title, duration);
    playlist.pushBack(newSong);
    if (playlist.getSize() == 1)
    { // If it's the first song, set it as the current song
        pCurrent = playlist.at(0);
    }
}

/**
 * Remove a specified song from the playlist.
 * @param title the title of the song that need to be removed.
 */
bool MusicBox::removeSong(const std::string &title)
{
    Song targetSong(title, 0);

    // Check if the current song is the one to be removed
    if (pCurrent != nullptr && pCurrent->data.getTitle() == title)
    {
        playNext();

        if (pCurrent->data.getTitle() == title)
        {
            pCurrent = nullptr;
        }
    }

    return playlist.remove(targetSong);
}

/**
 * Searches for a specified song in the playlist.
 * @param title the titile of the song.
 */
bool MusicBox::searchSong(const std::string &title)
{
    Song targetSong(title, 0);
    return playlist.contains(targetSong);
}

/**
 * Advances the current position to the next song in the playlist.
 * If the current song is the last in the playlist, it wraps around to the first song.
 */
void MusicBox::playNext()
{
    if (playlist.isEmpty())
        return;
    if (pCurrent != nullptr && pCurrent->next != nullptr)
    {
        pCurrent = pCurrent->next;
    }
    else
    {
        pCurrent = playlist.at(0); // Wrap around to the first song
    }
}

/**
 * Advances the current position to the previous song in the playlist.
 * If the current song is the first in the playlist, it wraps around to the last song.
 */
void MusicBox::playPrevious()
{
    if (pCurrent != nullptr && pCurrent->prev != nullptr)
    {
        pCurrent = pCurrent->prev;
    }
    else
    {
        pCurrent = playlist.at(playlist.getSize() - 1); // Wrap around to the last song
    }
}

/**
 * Returns the currently playing song.
 */
void MusicBox::currentSong() const
{
    if (pCurrent != nullptr)
    {
        std::cout << "Now playing: \"" << pCurrent->data.getTitle()
                  << "\" Duration: " << pCurrent->data.getDuration() << " seconds\n";
    }
}

/**
 * Displays all the songs in the playlist.
 */
void MusicBox::displayPlaylist()
{
    std::cout << "Playlist:" << endl;
    for (int i = 0; i < playlist.getSize(); ++i)
    {
        Song song = playlist.at(i)->data;
        std::cout << song.getTitle() << " - " << song.getDuration() << " seconds\n";
    }
}

/**
 * Sorts the playlist by the titles of the songs using the quick sort algorithm,
 * choosing the initial song as the pivot point.
 */
void MusicBox::sort()
{
    Node<Song> *head = playlist.at(0);
    Node<Song> *tail = playlist.at(playlist.getSize() - 1);

    quickSort(head, tail);
}

/**
 * Helper function for quick sort.
 * @param low first song.
 * @param high last song.
 */
Node<Song> *MusicBox::partition(Node<Song> *low, Node<Song> *high)
{
    // Taking the leftmost element as pivot
    Song pivot = low->data;
    Node<Song> *i = low->prev;

    for (Node<Song> *j = low; j != high; j = j->next)
    {
        if (j->data.getTitle() <= pivot.getTitle())
        {
            // Similar to i++ for array
            i = (i == nullptr) ? low : i->next;

            // Swapping data at nodes i and j
            std::swap(i->data, j->data);
        }
    }
    // Swap the pivot element with the element at i+1 position
    i = (i == nullptr) ? low : i->next;
    std::swap(i->data, high->data);
    return i;
}

/**
 * The recursive quick sort utility.
 * @param low first song.
 * @param high last song.
 */
void MusicBox::quickSort(Node<Song> *low, Node<Song> *high)
{
    if (high != nullptr && low != high && low != high->next)
    {
        Node<Song> *p = partition(low, high);
        quickSort(low, p->prev);
        quickSort(p->next, high);
    }
}

/**
 * Shuffle the songs in the playlist
 */
void MusicBox::shuffle()
{
    if (playlist.getSize() <= 1)
        return;

    Node<Song> *current = playlist.at(0);
    srand((unsigned)time(0)); // Seed the random number generator

    for (int i = 0; current != nullptr && i < playlist.getSize() - 1; ++i, current = current->next)
    {
        int j = i + rand() % (playlist.getSize() - i); // Random remaining position.
        Node<Song> *randomNode = playlist.at(j);
        std::swap(current->data, randomNode->data);
    }

    // Reset the current song to the head of the playlist
    pCurrent = playlist.at(0);
}
