#ifndef SONG_H
#define SONG_H

#include <string>

/**
 * Song class for Music Box
 *
 * @author Zichen Men <zichen.men@bellevuecollege.edu>
 * @date 11/2/2023
 * @version ___1.0___
 */

class Song
{
private:
    std::string title;
    int duration; // Duration in seconds

public:
    /**
     * Parameterized Constructor.
     * Initialize the tile of the song.
     * @param title the title of the song.
     * @param duration the duration of the song.
     */
    Song(const std::string &title, int duration) : title(title), duration(duration) {}

    /**
     * Assignment operator overload.
     * @param other another song that need to be compared.
     */
    bool operator==(const Song &other) const
    {
        return title == other.title;
    }

    /**
     * Getter method to get the tile of the song.
     */
    std::string getTitle() const { return title; }

    /**
     * Getter method to get the tile of the song.
     */
    int getDuration() const { return duration; }
};

#endif
