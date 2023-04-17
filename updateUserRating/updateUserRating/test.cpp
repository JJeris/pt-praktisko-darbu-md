#include "pch.h"
#include <gtest/gtest.h>
#include "musuFunkcija/updateUserRating.h"
#include <iostream>
using namespace std;

TEST(Robežgadījumi, Test1_Min) {
	int userId = 2;
	test test(userId, 10);

	test.priceSuggestions.push_back(priceSuggestion(userId, 11));	
	test.priceSuggestions.push_back(priceSuggestion(userId, 3));
	test.priceSuggestions.push_back(priceSuggestion(userId, 4));
	test.priceSuggestions.push_back(priceSuggestion(userId, 5));
	test.priceSuggestions.push_back(priceSuggestion(userId, 6));

	int selectedUserID = userId;
	test.updateUserRating(selectedUserID);

	EXPECT_EQ(test.userGlobal.userRating, 10);
}

TEST(Robežgadījumi, Test2_Max) {
	int userId = 2;
	test test(userId, 10);

	test.priceSuggestions.push_back(priceSuggestion(userId, 11));
	test.priceSuggestions.push_back(priceSuggestion(userId, 3));
	test.priceSuggestions.push_back(priceSuggestion(userId, 4));
	test.priceSuggestions.push_back(priceSuggestion(userId, 5));
	test.priceSuggestions.push_back(priceSuggestion(userId, 6));

	int selectedUserID = userId;
	test.updateUserRating(selectedUserID);

	EXPECT_EQ(test.userGlobal.userRating, 10);
}