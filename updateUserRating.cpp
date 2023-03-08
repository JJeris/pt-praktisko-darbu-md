#include <iostream>
#include <list>
using namespace std;

struct priceSuggestion {
  int rating;
  int userID;
  priceSuggestion(int userID, int rating) {
    this->userID = userID;
    this->rating = rating;
  }
};
list<priceSuggestion> priceSuggestions;

void updateUserRating(int userID)
{
    if(priceSuggestions.size() == 0){
        cout<<"Rating:0 (length==0)"<<endl;
        return;
    }
    int userRating = 0;
    list<priceSuggestion> userPriceSuggestions = priceSuggestions; // Analog "select where userID == ..."
    for (list<priceSuggestion>::iterator it=userPriceSuggestions.begin(); it != userPriceSuggestions.end(); ++it){
        if((*it).rating>10){
            userRating++;
        }
        else if ((*it).rating<-10){
            userRating--;
        }
    }
    cout<<"Rating:"<<userRating<<endl;
    cout<<"M010"<<endl;
}

int main(){
    priceSuggestions.push_back(priceSuggestion(1, 11));
    priceSuggestions.push_back(priceSuggestion(1, 3));
    priceSuggestions.push_back(priceSuggestion(1, 4));
    priceSuggestions.push_back(priceSuggestion(1, 5));
    priceSuggestions.push_back(priceSuggestion(1, 6));

    for (list<priceSuggestion>::iterator it=priceSuggestions.begin(); it != priceSuggestions.end(); ++it)
        cout<<(*it).userID<<" "<<(*it).rating<<endl;
    cout << '\n';
    
    int selectedUserID = 1; // Selected userID value for test
    updateUserRating(selectedUserID);
}