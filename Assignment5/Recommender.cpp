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

#include "Recommender.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>

// Private methods
void Recommender::loadArtists(const std::string &fileName)
{
    std::ifstream file(fileName);
    std::string line;
    while (getline(file, line))
    {
        std::istringstream iss(line);
        int id;
        iss >> id;

        std::string name;
        getline(iss, name, '\t');
        getline(iss, name); // Read the rest of the line as the name

        artists.insert(id, Artist(id, name));
    }
}

void Recommender::loadUserArtists(const std::string &fileName)
{
    std::ifstream file(fileName);
    std::string line;
    while (getline(file, line))
    {
        std::istringstream iss(line);
        int userID, artistID;
        if (iss >> userID >> artistID)
        {
            User user;
            if (!users.get(userID, user))
            {
                user = User(userID);
            }
            user.addArtist(artistID);
            users.insert(userID, user);
        }
    }
}

void Recommender::loadUserFriends(const std::string &fileName)
{
    std::ifstream file(fileName);
    std::string line;
    while (getline(file, line))
    {
        std::istringstream iss(line);
        int userID, friendID;
        if (iss >> userID >> friendID)
        {
            User user;
            if (!users.get(userID, user))
            {
                user = User(userID);
            }
            user.addFriend(friendID);
            users.insert(userID, user);
        }
    }
}

// Public methods
void Recommender::listFriends(int userID)
{
    User user;
    if (users.get(userID, user))
    {
        std::cout << "Friend ID: ";
        for (int friendID : user.getFriendIDs())
        {
            std::cout << friendID << " ";
        }
    }
    else
    {
        std::cout << "User not found." << std::endl;
    }
}

void Recommender::commonFriends(int user1ID, int user2ID)
{
    User user1, user2;
    if (users.get(user1ID, user1) && users.get(user2ID, user2))
    {
        const auto &friendsOfUser1 = user1.getFriendIDs();
        const auto &friendsOfUser2 = user2.getFriendIDs();

        std::cout << "Common friends of users " << user1ID << " and " << user2ID << ":\n";
        for (int friendID : friendsOfUser1)
        {
            if (friendsOfUser2.find(friendID) != friendsOfUser2.end())
            {
                std::cout << friendID << std::endl;
            }
        }
    }
    else
    {
        std::cout << "One or both users not found." << std::endl;
    }
}

void Recommender::listArtists(int user1ID, int user2ID)
{
    User user1, user2;
    if (users.get(user1ID, user1) && users.get(user2ID, user2))
    {
        const auto &artistsOfUser1 = user1.getArtistIDs();
        const auto &artistsOfUser2 = user2.getArtistIDs();

        std::cout << "Artists listened to by both users " << user1ID << " and " << user2ID << ":\n";
        for (int artistID : artistsOfUser1)
        {
            if (artistsOfUser2.find(artistID) != artistsOfUser2.end())
            {
                Artist artist;
                if (artists.get(artistID, artist))
                {
                    std::cout << artist.getName() << std::endl;
                }
            }
        }
    }
    else
    {
        std::cout << "One or both users not found." << std::endl;
    }
}

void Recommender::recommend(int userID, int top)
{
    User user;
    if (!users.get(userID, user))
    {
        std::cout << "User not found." << std::endl;
        return;
    }

    // HashMap to store cumulative listen counts for each artist
    HashMap<int, int, 1000> cumulativeListenCounts;

    // Function to update listen counts
    auto updateListenCounts = [&](const User &user)
    {
        for (int artistID : user.getArtistIDs())
        {
            int currentCount = 0;
            cumulativeListenCounts.get(artistID, currentCount);        // Get current count if exists
            cumulativeListenCounts.insert(artistID, currentCount + 1); // Update count
        }
    };

    // listen counts from the user
    updateListenCounts(user);

    // listen counts from the user's friends
    for (int friendID : user.getFriendIDs())
    {
        User friendUser;
        if (users.get(friendID, friendUser))
        {
            updateListenCounts(friendUser);
        }
    }

    // Sort the cumulative listen counts
    auto sortedList = cumulativeListenCounts.sortHashMapByValues();

    std::cout << "Top " << top << " artist recommendations for user " << userID << ":\n";

    // Display the top recommendations
    for (int i = 0; i < top && i < sortedList.size(); ++i)
    {
        int artistID = sortedList[i].first;
        int listenCount = sortedList[i].second;

        Artist artist;
        if (artists.get(artistID, artist))
        {
            std::cout << "Artist Name: " << artist.getName() << ", Listen count: " << listenCount << std::endl;
        }
    }
}
