using PIS = pair<int, string>;
auto cmp = [](const PIS & lhs, const PIS & rhs){
    if(lhs.first == rhs.first) {
        return lhs.second < rhs.second;
    }

    return lhs.first > rhs.first;
};

class FoodRatings {
public:
    FoodRatings(const vector<string> & foods, const vector<string> & cuisines, const vector<int> & ratings) {
        cin.tie(nullptr)->sync_with_stdio(false);

        int n = foods.size();
        for(int i = 0; i < n; ++i) {
            foodToCuisine[foods[i]] = cuisines[i];
            foodRating[foods[i]] = ratings[i];
            highestRatedCuisine[cuisines[i]].insert({ratings[i], foods[i]});
        }
    }
    
    void changeRating(const string & food, const int & newRating) {
        string cuisine = foodToCuisine[food];

        auto oldIter = highestRatedCuisine[cuisine].find({foodRating[food], food});
        highestRatedCuisine[cuisine].erase(oldIter);

        foodRating[food] = newRating;
        highestRatedCuisine[cuisine].insert({newRating, food});
    }
    
    string highestRated(const string & cuisine) {
        return (*highestRatedCuisine[cuisine].begin()).second;
    }

private:
    unordered_map<string, string> foodToCuisine;
    unordered_map<string, int> foodRating;

    using SPIS = set<PIS, decltype(cmp)>;
    unordered_map<string, SPIS> highestRatedCuisine;
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
