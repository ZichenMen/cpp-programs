/**
 * A comprehensive C++ class designed for a music recommender system. It
 * provides functionalities to manage user and artist data,
 * and generate music recommendations based on users' listening habits and their social network.
 *
 * @author Zichen Men <zichen.men@bellevuecollege.edu>
 * @date 12/1/2023
 * @version __1.0__
 *
 */

#ifndef RECOMMENDER_H
#define RECOMMENDER_H

#include "User.h"
#include "Artist.h"
#include "HashMap.h"
#include <string>
#include <vector>

class Recommender
{
private:
    // HashMaps for storing users and artists
    HashMap<int, User, 1000> users;
    HashMap<int, Artist, 1000> artists;

    // Private methods to load data from files
    void loadArtists(const std::string &fileName);
    void loadUserArtists(const std::string &fileName);
    void loadUserFriends(const std::string &fileName);

public:
    // Constructor
    Recommender(const std::string &artistsFile, const std::string &userArtistsFile, const std::string &userFriendsFile)
    {
        loadArtists(artistsFile);
        loadUserArtists(userArtistsFile);
        loadUserFriends(userFriendsFile);
    }

    // Lists all friends of a given user by their ID
    void listFriends(int userID);

    // Prints common friends between two users
    void commonFriends(int user1ID, int user2ID);

    // Lists artists listened to by both specified users
    void listArtists(int user1ID, int user2ID);

    // Generates and prints music artist recommendations for a given user
    void recommend(int userID, int top);
};

#include "Recommender.cpp"
#endif // RECOMMENDER_H
