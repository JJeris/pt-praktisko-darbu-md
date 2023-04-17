//#include "../pch.h"
#include <iostream>
#include <list>
#include "updateUserRating.h"
using namespace std;

// UserID, ko liktu queryā.
// Sarakstā nebūtu jāeksistē cita tipa ID!
// funkcijā iegūtu sarakstu un lietotāju tikai ar šo ID, ja būtu DB
//const int USERID = 2;

// Cenas piedāvājuma objekts
priceSuggestion::priceSuggestion(int userID, int rating) {
    this->userID = userID;
    this->rating = rating;
}

User::User(int userID, int userRating) {
    this->userID = userID;
    this->userRating = userRating;
}

// query = $"SELECT * FROM priceSuggestions WHERE userID = $userID"
// query2 = $"SELECT * FROM Users WHERE userID = $userID"
// simulē query, ja būtu īsta datubāze
//list<priceSuggestion> priceSuggestions;
//User userGlobal(USERID, 10);

void test::updateUserRating(int userID) {
    if(userID != USERID) { // Simulācija, ka neeksistē USER
        throw "WARNING: Tried to update user rating for a user which does not exist!";
    }

    User user = userGlobal; // query priekš user
    list<priceSuggestion> userPriceSuggestions = priceSuggestions; // query priekš cenu piedāvājumiem
    int userRating = 0;

    int length = (int)priceSuggestions.size();
    if(length == 0){
        //cout << "NOTE: Saving user " << userID << "rating: " << userRating <<endl;
        user.userRating = userRating;
        userGlobal = user; // update
        return;
    }

    list<priceSuggestion>::iterator it = userPriceSuggestions.begin();
    while(it != userPriceSuggestions.end()) {
        if((*it).rating>10){
            userRating++;
        }
        else if ((*it).rating<-10){
            userRating--;
        }
        ++it;
    }
    //cout << "NOTE: Saving user " << userID << "rating: " << userRating <<endl;
    user.userRating = userRating;
    userGlobal = user; //update
}

/*
int main() {
    // priceSuggestions.push_back(priceSuggestion(userID, userRating))
    // Šeit ir domāts, ka userID ir tikai viens vienīgs, t.i. arguments.
    // Jo tas ir domāts kā query, nevis pilnā datubāze
    priceSuggestions.push_back(priceSuggestion(USERID, 11));
    priceSuggestions.push_back(priceSuggestion(USERID, 3));
    priceSuggestions.push_back(priceSuggestion(USERID, 4));
    priceSuggestions.push_back(priceSuggestion(USERID, 5));
    priceSuggestions.push_back(priceSuggestion(USERID, 6));

    // Šī ir vienkārši izprintēšana, varbūt palīdz saprast
    // for (list<priceSuggestion>::iterator it=priceSuggestions.begin(); it != priceSuggestions.end(); ++it)
    //     cout<<(*it).userID<<" "<<(*it).rating<<endl;
    // cout << '\n';
    
    // Ja grib simulēt, ka nav cenu piedāvājumu, atkomentēt nākamo līniju:
    //priceSuggestions.clear();

    // Ja grib simulēt, ka neeksistē tāds lietotājs datubāzē
    // nomaina selectedUserID uz kaut ko, kas nav vienāds ar USERID
    cout << "User rating before: " << userGlobal.userRating << endl;
    int selectedUserID = USERID;
    updateUserRating(selectedUserID);
    cout << "User rating after: " << userGlobal.userRating << endl;
}
*/