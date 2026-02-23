#include <bits/stdc++.h>
using namespace std;

// class Twitter {
//    private:
//     // followerId -> set of followeeIds
//     unordered_map<int, unordered_set<int>> followMap;

//     // Stores all tweets globally as (userId, tweetId)
//     vector<pair<int, int>> tweets;

//     // Time & Space Complexity: O(1)
//     bool isFollowing(int followerId, int followeeId) {
//         if (followMap.count(followerId)) {
//             return followMap[followerId].count(followeeId);
//         }
//         return false;
//     }

//    public:
//     Twitter() {
//     }

//     // Time & Space Complexity: O(1)
//     void postTweet(int userId, int tweetId) {
//         // Append tweet to global tweet list
//         tweets.push_back({userId, tweetId});
//     }

//     // Time Complexity: O(T), where T = total time, Space Complexity: O(1)
//     vector<int> getNewsFeed(int userId) {
//         vector<int> newsFeed;

//         // Traverse tweets from most recent to oldest
//         for (int i = tweets.size() - 1; i >= 0 && newsFeed.size() < 10; --i) {
//             auto& tweet = tweets[i];

//             // Include tweet if:
//             // 1. It is posted by user
//             // 2. OR user follows the author
//             if (tweet.first == userId ||
//                 isFollowing(userId, tweet.first)) {
//                 newsFeed.push_back(tweet.second);
//             }
//         }

//         return newsFeed;
//     }

//     // Time & Space Complexity: O(1)
//     void follow(int followerId, int followeeId) {
//         if (followerId == followeeId) return;

//         followMap[followerId].insert(followeeId);
//     }

//     // Time & Space Complexity: O(1)
//     void unfollow(int followerId, int followeeId) {
//         if (followMap.count(followerId)) {
//             followMap[followerId].erase(followeeId);
//         }
//     }
// };

// Optimised MaxHeap Method
// class Twitter {
//    private:
//     // followerId -> set of followeeIds
//     unordered_map<int, unordered_set<int>> followMap;

//     // userId -> list of {timestamp, tweetId}
//     unordered_map<int, vector<pair<int, int>>> userTweets;

//     int timeStamp = 0;  // global increasing timestamp

//    public:
//     Twitter() {
//     }

//     // Time & Space Complexity: O(1)
//     void postTweet(int userId, int tweetId) {
//         userTweets[userId].push_back({timeStamp++, tweetId});
//     }

//     // Time Complexity: O(n log n)  (n = number of followees) ≈ O(n log 10) since we only keep top 10
//     // Space Complexity : O(n)
//     vector<int> getNewsFeed(int userId) {
//         vector<int> result;

//         // Max heap ordered by timestamp
//         priority_queue<pair<int, int>> maxHeap;

//         // Ensure user follows themselves
//         followMap[userId].insert(userId);

//         // Collect tweets from user and followees
//         for (int followee : followMap[userId]) {
//             auto& tweets = userTweets[followee];

//             // Only need latest 10 tweets per user
//             for (int i = tweets.size() - 1;
//                  i >= 0 && i >= (int)tweets.size() - 10;
//                  i--) {
//                 maxHeap.push(tweets[i]);
//             }
//         }

//         // Extract top 10 most recent tweets
//         while (!maxHeap.empty() && result.size() < 10) {
//             result.push_back(maxHeap.top().second);
//             maxHeap.pop();
//         }

//         return result;
//     }

//     // Time & Space Complexity: O(1)
//     void follow(int followerId, int followeeId) {
//         if (followerId == followeeId) return;

//         followMap[followerId].insert(followeeId);
//     }

//     // Time & Space Complexity: O(1)
//     void unfollow(int followerId, int followeeId) {
//         if (followMap.count(followerId)) {
//             followMap[followerId].erase(followeeId);
//         }
//     }
// };

// Most Optimal Min Heap Appraoch with optimized k-way merge logic
class Twitter {
   private:
    // followerId -> set of followeeIds
    unordered_map<int, unordered_set<int>> followMap;

    // userId -> list of {timestamp, tweetId}
    unordered_map<int, vector<pair<int, int>>> userTweets;

    int timeStamp = 0;  // global decreasing timestamp

   public:
    Twitter() {
    }

    // Time & Space Complexity: O(1)
    void postTweet(int userId, int tweetId) {
        userTweets[userId].push_back({timeStamp, tweetId});
        if (userTweets[userId].size() > 10) {
            userTweets[userId].erase(userTweets[userId].begin());
        }
        timeStamp--;
    }

    // Time Complexity: O(F + 10 log F), F = number of followees of userId
    // { 1 tweet per followee initially → O(F) } + { Pop at most 10 tweets → O(10 log F) }
    // Space Complexity : O(F) Heap stores at most one entry per followee at a time.
    vector<int> getNewsFeed(int userId) {
        vector<int> result;

        // Ensure user follows themselves
        followMap[userId].insert(userId);

        /*
        Min heap ordered by timestamp.
        Each heap entry stores:
        {
            timeStamp,
            tweetId,
            userId,
            nextIndex (next older tweet index for that user)
        }
        */
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

        // Step 1: Push the most recent tweet of each followee
        for (int followee : followMap[userId]) {
            if (!userTweets.count(followee)) continue;

            int idx = userTweets[followee].size() - 1;

            auto& tweet = userTweets[followee][idx];

            // Push latest tweet of that user
            minHeap.push({
                tweet.first,   // timestamp
                tweet.second,  // tweetId
                followee,      // userId
                idx - 1        // pointer to next older tweet
            });
        }

        // Step 2: Extract top 10 most recent tweets
        while (!minHeap.empty() && result.size() < 10) {
            auto topTweet = minHeap.top();
            minHeap.pop();

            int tweetId = topTweet[1];
            int followee = topTweet[2];
            int nextIdx = topTweet[3];

            result.push_back(tweetId);

            // If that user has older tweets, push next one
            if (nextIdx >= 0) {
                auto& nextTweet = userTweets[followee][nextIdx];

                minHeap.push({nextTweet.first,   // timestamp
                              nextTweet.second,  // tweetId
                              followee,
                              nextIdx - 1});
            }
        }

        return result;
    }

    // Time & Space Complexity: O(1)
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }

    // Time & Space Complexity: O(1)
    void unfollow(int followerId, int followeeId) {
        if (followMap.count(followerId)) {
            followMap[followerId].erase(followeeId);
        }
    }
};

void printVector(vector<int> v) {
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    Twitter twitter;
    twitter.postTweet(1, 10);             // User 1 posts a new tweet with id = 10.
    twitter.postTweet(2, 20);             // User 2 posts a new tweet with id = 20.
    printVector(twitter.getNewsFeed(1));  // User 1's news feed should only contain their own tweets -> [10].
    printVector(twitter.getNewsFeed(2));  // User 2's news feed should only contain their own tweets -> [20].
    twitter.follow(1, 2);                 // User 1 follows user 2.
    printVector(twitter.getNewsFeed(1));  // User 1's news feed should contain both tweets from user 1 and user 2 -> [20, 10].
    printVector(twitter.getNewsFeed(2));  // User 2's news feed should still only contain their own tweets -> [20].
    twitter.unfollow(1, 2);               // User 1 unfollows user 2.
    printVector(twitter.getNewsFeed(1));  // User 1's news feed should only contain their own tweets -> [10].

    return 0;
}