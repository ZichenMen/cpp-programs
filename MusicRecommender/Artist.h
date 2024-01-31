/**
 * A straightforward data structure designed to encapsulate information
 * about an artist.
 *
 * @author Zichen Men <zichen.men@bellevuecollege.edu>
 * @date 11/27/2023
 * @version __1.0__
 *
 */

#ifndef ARTIST_H
#define ARTIST_H

#include <string>

class Artist
{
private:
    int id;
    std::string name;

public:
    // Default constructor
    Artist() : id(0), name("") {}

    // Parameterized constructor
    Artist(int _id, std::string _name) : id(_id), name(std::move(_name)) {}

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

    // Getter for name
    std::string getName() const
    {
        return name;
    }

    // Setter for name
    void setName(const std::string &_name)
    {
        name = _name;
    }
};

#endif // ARTIST_H
