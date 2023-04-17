#include "pch.h"
#include <gtest/gtest.h>
#include "musuFunkcija/updateUserRating.h"
#include <iostream>
using namespace std;

TEST(Pārklājums, Test1_GT10) {
	int userId = 2;
	int selectedUserID = userId;
	test test(userId, 10);

	test.priceSuggestions.push_back(priceSuggestion(userId, 11));

	test.updateUserRating(selectedUserID);
	EXPECT_EQ(test.userGlobal.userRating, 1);
}

TEST(Pārklājums, Test2_LT10) {
	int userId = 2;
	int selectedUserID = userId;
	test test(userId, 10);

	test.priceSuggestions.push_back(priceSuggestion(userId, -11));

	test.updateUserRating(selectedUserID);
	EXPECT_EQ(test.userGlobal.userRating, -1);
}

TEST(Pārklājums, Test3_Middle) {
	int userId = 2;
	int selectedUserID = userId;
	test test(userId, 10);

	test.priceSuggestions.push_back(priceSuggestion(userId, 0));

	test.updateUserRating(selectedUserID);
	EXPECT_EQ(test.userGlobal.userRating, 0);
}

TEST(Pārklājums, Test4_UserNoExist) {
	int userId = 2;
	int selectedUserID = 3;
	test test(userId, 10);

	test.priceSuggestions.push_back(priceSuggestion(userId, 0));

	EXPECT_ANY_THROW(test.updateUserRating(selectedUserID));
}

TEST(Pārklājums, Test5_PricesNoExist) {
	int userId = 2;
	int selectedUserID = 3;
	test test(userId, 10);

	EXPECT_EQ(test.userGlobal.userRating, 10);
}


TEST(Izmaiņas, Test1_NoChange) {
	int userId = 2;
	int selectedUserID = userId;
	test test(userId, 10);

	test.priceSuggestions.push_back(priceSuggestion(userId, -1));
	test.priceSuggestions.push_back(priceSuggestion(userId, 3));
	test.priceSuggestions.push_back(priceSuggestion(userId, -4));
	test.priceSuggestions.push_back(priceSuggestion(userId, 1));
	test.priceSuggestions.push_back(priceSuggestion(userId, 6));

	test.updateUserRating(selectedUserID);
	int original = test.userGlobal.userRating;

	test.priceSuggestions.push_back(priceSuggestion(userId, 7));
	test.priceSuggestions.push_back(priceSuggestion(userId, 8));
	test.priceSuggestions.push_back(priceSuggestion(userId, 9));
	test.priceSuggestions.push_back(priceSuggestion(userId, 10));

	test.updateUserRating(selectedUserID);

	EXPECT_EQ(original, test.userGlobal.userRating);
}

TEST(Izmaiņas, Test2_LowersRating) {
	int userId = 2;
	int selectedUserID = userId;
	test test(userId, 10);

	test.priceSuggestions.push_back(priceSuggestion(userId, 10));
	test.priceSuggestions.push_back(priceSuggestion(userId, 3));
	test.priceSuggestions.push_back(priceSuggestion(userId, 14));
	test.priceSuggestions.push_back(priceSuggestion(userId, 11));
	test.priceSuggestions.push_back(priceSuggestion(userId, 7));

	test.updateUserRating(selectedUserID);
	int original = test.userGlobal.userRating;

	test.priceSuggestions.push_back(priceSuggestion(userId, -11));
	test.priceSuggestions.push_back(priceSuggestion(userId, 3));
	test.priceSuggestions.push_back(priceSuggestion(userId, -14));
	test.priceSuggestions.push_back(priceSuggestion(userId, -10));
	test.priceSuggestions.push_back(priceSuggestion(userId, 6));

	test.updateUserRating(selectedUserID);
	EXPECT_GT(original, test.userGlobal.userRating);
}

TEST(Izmaiņas, Test3_RaisesRating) {
	int userId = 2;
	int selectedUserID = userId;
	test test(userId, 10);

	test.priceSuggestions.push_back(priceSuggestion(userId, -11));
	test.priceSuggestions.push_back(priceSuggestion(userId, 3));
	test.priceSuggestions.push_back(priceSuggestion(userId, -14));
	test.priceSuggestions.push_back(priceSuggestion(userId, -10));
	test.priceSuggestions.push_back(priceSuggestion(userId, 6));

	test.updateUserRating(selectedUserID);
	int original = test.userGlobal.userRating;

	test.priceSuggestions.push_back(priceSuggestion(userId, 10));
	test.priceSuggestions.push_back(priceSuggestion(userId, 3));
	test.priceSuggestions.push_back(priceSuggestion(userId, 14));
	test.priceSuggestions.push_back(priceSuggestion(userId, 11));
	test.priceSuggestions.push_back(priceSuggestion(userId, 7));

	test.updateUserRating(selectedUserID);
	EXPECT_LT(original, test.userGlobal.userRating);
}

TEST(Neveiksmigs, Test1_FAIL) {
	int userId = 2;
	int selectedUserID = userId;
	test test(userId, 10);

	test.priceSuggestions.push_back(priceSuggestion(userId, -11));
	test.priceSuggestions.push_back(priceSuggestion(userId, 3));
	test.priceSuggestions.push_back(priceSuggestion(userId, -14));
	test.priceSuggestions.push_back(priceSuggestion(userId, -10));
	test.priceSuggestions.push_back(priceSuggestion(userId, 6));

	test.updateUserRating(selectedUserID);
	EXPECT_EQ(test.userGlobal.userRating, 8);
}