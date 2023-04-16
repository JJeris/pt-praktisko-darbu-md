#pragma once
#include <list>
// UserID, ko liktu queryā.
// Sarakstā nebūtu jāeksistē cita tipa ID!
// funkcijā iegūtu sarakstu un lietotāju tikai ar šo ID, ja būtu DB
// const int USERID = 2;

// Cenas piedāvājuma objekts
struct priceSuggestion {
public:
    int rating;
    int userID;
    priceSuggestion(int userID, int rating);
};

// Lietotāja objekts
struct User {
public:
    int userID;
    int userRating;
    User(int userID, int userRating);
};

// query = $"SELECT * FROM priceSuggestions WHERE userID = $userID"
// query2 = $"SELECT * FROM Users WHERE userID = $userID"
// simulē query, ja būtu īsta datubāze


class test {
public:
    std::list<priceSuggestion> priceSuggestions;
    //User userGlobal(USERID, 10);
    User userGlobal;
    int USERID;
    int initialRating;
    test(int USERID, int initialRating) : userGlobal(USERID, initialRating) {
        this->USERID = USERID;
        this->initialRating = initialRating;
    }
    ~test();

    void updateUserRating(int userID);
};
