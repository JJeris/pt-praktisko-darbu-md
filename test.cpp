#include "musuFunkcija/updateUserRating.h"
#include <iostream>
using namespace std;

//std::list<priceSuggestion> priceSuggestions;
//User userGlobal(USERID, 10);

int main() {

    int userId = 2;
    test test(userId, 10);
    // priceSuggestions.push_back(priceSuggestion(userID, userRating))
    // Šeit ir domāts, ka userID ir tikai viens vienīgs, t.i. arguments.
    // Jo tas ir domāts kā query, nevis pilnā datubāze
    /*test.priceSuggestions.push_back(priceSuggestion(userId, 11));
    test.priceSuggestions.push_back(priceSuggestion(userId, 3));
    test.priceSuggestions.push_back(priceSuggestion(userId, 4));
    test.priceSuggestions.push_back(priceSuggestion(userId, 5));
    test.priceSuggestions.push_back(priceSuggestion(userId, 6));

    // Šī ir vienkārši izprintēšana, varbūt palīdz saprast
    // for (list<priceSuggestion>::iterator it=priceSuggestions.begin(); it != priceSuggestions.end(); ++it)
    //     cout<<(*it).userID<<" "<<(*it).rating<<endl;
    // cout << '\n';
    
    // Ja grib simulēt, ka nav cenu piedāvājumu, atkomentēt nākamo līniju:
    //priceSuggestions.clear();

    // Ja grib simulēt, ka neeksistē tāds lietotājs datubāzē
    // nomaina selectedUserID uz kaut ko, kas nav vienāds ar USERID
    cout << "User rating before: " << test.userGlobal.userRating << endl;
    int selectedUserID = userId;
    test.updateUserRating(selectedUserID);
    cout << "User rating after: " << test.userGlobal.userRating << endl;*/
}