/**
 * A  user in music recommendation systems. It provides
 * mechanisms to manage a user's connections and their interactions with artists, aiding in
 * features like friend lists and music preference tracking
 *
 * @author Zichen Men <zichen.men@bellevuecollege.edu>
 * @date 12/1/2023
 * @version __1.0__
 *
 */

#ifndef USER_H
#define USER_H

#include <set>
#include <string>

class User
{
private:
    int id;
    std::set<int> friendIDs; // Set of friend IDs
    std::set<int> artistIDs; // Set of artist IDs

public:
    // Default constructor
    User() : id(0) {}

    // Parameterized constructor
    User(int _id) : id(_id) {}

    // Getter for id
    int getId() const
    {
        return id;
    }

    // Setter for id
    void setId(int _id)
    {
        id = _id;
    }

    // Function to add a friend ID
    void addFriend(int friendID)
    {
        friendIDs.insert(friendID);
    }

    // Function to add an artist ID
    void addArtist(int artistID)
    {
        artistIDs.insert(artistID);
    }

    // Getter for friend IDs
    const std::set<int> &getFriendIDs() const
    {
        return friendIDs;
    }

    // Getter for artist IDs
    const std::set<int> &getArtistIDs() const
    {
        return artistIDs;
    }
};

#endif // USER_H
