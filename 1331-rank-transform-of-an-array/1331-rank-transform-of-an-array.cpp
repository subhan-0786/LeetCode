class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortedArr = arr;  // Copy the original array
        sort(sortedArr.begin(), sortedArr.end());  // Sort the copy

        unordered_map<int, int> rankMap;  // Map to store ranks
        int rank = 1;

        // Assign ranks while skipping duplicates
        for (int num : sortedArr) {
            if (!rankMap.count(num)) {
                rankMap[num] = rank++;
            }
        }

        // Replace elements with their ranks
        vector<int> result;
        for (int num : arr) {
            result.push_back(rankMap[num]);
        }

        return result;
    }

    int main() {
        vector<int> arr = {40, 10, 20, 30};
        vector<int> result = arrayRankTransform(arr);

        for (int rank : result) {
            cout << rank << " ";
        }

        return 0;
    }
};