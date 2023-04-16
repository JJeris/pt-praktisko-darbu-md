#pragma once
#include <list>
// UserID, ko liktu queryā.
// Sarakstā nebūtu jāeksistē cita tipa ID!
// funkcijā iegūtu sarakstu un lietotāju tikai ar šo ID, ja būtu DB
const int USERID = 2;

// Cenas piedāvājuma objekts
struct priceSuggestion {
  int rating;
  int userID;
  priceSuggestion(int userID, int rating);
};

// Lietotāja objekts
struct User {
    int userID;
    int userRating;
    User(int userID, int userRating);
};

// query = $"SELECT * FROM priceSuggestions WHERE userID = $userID"
// query2 = $"SELECT * FROM Users WHERE userID = $userID"
// simulē query, ja būtu īsta datubāze
std::list<priceSuggestion> priceSuggestions;
User userGlobal(USERID, 10);

void updateUserRating(int userID);