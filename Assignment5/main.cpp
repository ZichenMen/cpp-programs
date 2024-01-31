/**
 * Main program file with sample run of Recommender.
 *
 * @author Zichen Men <zichen.men@bellevuecollege.edu>
 * @date 11/27/2023
 * @version __1.0__
 *
 */

#include <iostream>
#include "Recommender.h"

int main()
{
    // Assuming the data files are named as follows and are in the same directory as your executable
    std::string artistsFile = "artists.dat";
    std::string userArtistsFile = "user_artists.dat";
    std::string userFriendsFile = "user_friends.dat";

    // Create a Recommender instance
    Recommender recommender(artistsFile, userArtistsFile, userFriendsFile);

    // Test listing friends of a user
    int testUserID = 2;
    std::cout << "Listing friends of user " << testUserID << ":\n";
    recommender.listFriends(testUserID);

    // Test finding common friends between two users
    int user1ID = 2;
    int user2ID = 124;
    std::cout << "\nFinding common friends between user " << user1ID << " and user " << user2ID << ":\n";
    recommender.commonFriends(user1ID, user2ID);

    // Test listing artists listened to by both users
    int userAID = 2;
    int userBID = 4;
    recommender.listArtists(userAID, userBID);

    // Test generating music artist recommendations for a user
    int userRecommendID = 2;
    int topArtists = 10;
    std::cout << "\nGenerating top " << topArtists << " artist recommendations for user " << userRecommendID << ":\n";
    recommender.recommend(userRecommendID, topArtists);

    return 0;
}
