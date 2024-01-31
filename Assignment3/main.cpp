#include "MusicBox.h"
#include <iostream>
#include <string>

/**
 * Test file of MusicBox.
 *
 * @author Zichen Men <zichen.men@bellevuecollege.edu>
 * @date 11/2/2023
 * @version ___1.0___
 */

int main()
{
    MusicBox myMusicBox;
    std::string title;
    int duration;
    int choice;
    bool running = true;

    std::cout << "Welcome to the MelodyLinks!\n";

    while (running)
    {
        std::cout << "Menu:\n"
                  << "1. Add song to the playlist\n"
                  << "2. Remove song from the playlist\n"
                  << "3. Play the next song\n"
                  << "4. Play the previous song\n"
                  << "5. Display current song\n"
                  << "6. Display the entire playlist with durations\n"
                  << "7. Search for a song\n"
                  << "8. Sort the playlist\n"
                  << "9. Shuffle the playList\n"
                  << "10. Exit\n"
                  << "Choose an option: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice)
        {
        case 1:
            std::cout << "Enter song title: ";
            getline(std::cin, title);
            std::cout << "Enter song duration (in seconds): ";
            std::cin >> duration;
            myMusicBox.addSong(title, duration);
            std::cout << "\"" << title << "\" added to the playlist.\n";
            break;
        case 2:
            std::cout << "Enter song title to remove: ";
            getline(std::cin, title);
            if (myMusicBox.removeSong(title))
            {
                std::cout << "\"" << title << "\" removed from the playlist.\n";
            }
            else
            {
                std::cout << "Song not found in the playlist.\n";
            }
            break;
        case 3:
            myMusicBox.playNext();
            myMusicBox.currentSong();
            break;
        case 4:
            myMusicBox.playPrevious();
            myMusicBox.currentSong();
            break;
        case 5:
            myMusicBox.currentSong();
            break;
        case 6:
            myMusicBox.displayPlaylist();
            break;
        case 7:
            std::cout << "Enter song title to search for: ";
            getline(std::cin, title);
            if (myMusicBox.searchSong(title))
            {
                std::cout << "Song \"" << title << "\" found in the playlist!\n";
            }
            else
            {
                std::cout << "Song \"" << title << "\" not found in the playlist.\n";
            }
            break;
        case 10:
            std::cout << "Thank you for using MelodyLinks!\n";
            running = false;
            break;
        case 9:
            myMusicBox.shuffle();
            std::cout << "Playlist has been shuffled.\n";
            break;
        case 8:
            myMusicBox.sort();
            std::cout << "Playlist has been shuffled.\n";
            break;
        default:
            std::cout << "Invalid option, please try again.\n";
            break;
        }
    }

    return 0;
}
