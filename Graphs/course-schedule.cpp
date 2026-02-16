#include <iostream>
#include <vector>
#include <queue>
using namespace std;

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int m = prerequisites.size();
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj;

        vector<int> res;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < 2; j++) {
                adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
                indegree[prerequisites[i][1]]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int top = q.front();
            res.push_back(top);
            q.pop();

            vector<int> res = adj[top];
            for (auto it: res) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }

        }

        if (res.size() == numCourses) return true;
        return false;
    }

int main() {
    // Test case 1: Simple valid course schedule
    // 2 courses, prerequisite: [1,0] means to take course 1 you need course 0
    int numCourses1 = 2;
    vector<vector<int>> prerequisites1 = {{1, 0}};
    cout << "Test 1 - numCourses: " << numCourses1 << ", prerequisites: [[1,0]]" << endl;
    cout << "Can finish: " << (canFinish(numCourses1, prerequisites1) ? "true" : "false") << endl;
    cout << "Expected: true" << endl << endl;

    // Test case 2: Cycle detected
    // 2 courses with circular dependency
    // int numCourses2 = 2;
    // vector<vector<int>> prerequisites2 = {{1, 0}, {0, 1}};
    // cout << "Test 2 - numCourses: " << numCourses2 << ", prerequisites: [[1,0],[0,1]]" << endl;
    // cout << "Can finish: " << (canFinish(numCourses2, prerequisites2) ? "true" : "false") << endl;
    // cout << "Expected: false" << endl << endl;

    // Test case 3: Multiple courses, no cycle
    // int numCourses3 = 4;
    // vector<vector<int>> prerequisites3 = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    // cout << "Test 3 - numCourses: " << numCourses3 << ", prerequisites: [[1,0],[2,0],[3,1],[3,2]]" << endl;
    // cout << "Can finish: " << (canFinish(numCourses3, prerequisites3) ? "true" : "false") << endl;
    // cout << "Expected: true" << endl << endl;

    // Test case 4: No prerequisites
    // int numCourses4 = 3;
    // vector<vector<int>> prerequisites4 = {};
    // cout << "Test 4 - numCourses: " << numCourses4 << ", prerequisites: []" << endl;
    // cout << "Can finish: " << (canFinish(numCourses4, prerequisites4) ? "true" : "false") << endl;
    // cout << "Expected: true" << endl << endl;

    // Test case 5: Complex cycle
    // int numCourses5 = 5;
    // vector<vector<int>> prerequisites5 = {{1, 0}, {2, 1}, {3, 2}, {4, 3}, {0, 4}};
    // cout << "Test 5 - numCourses: " << numCourses5 << ", prerequisites: [[1,0],[2,1],[3,2],[4,3],[0,4]]" << endl;
    // cout << "Can finish: " << (canFinish(numCourses5, prerequisites5) ? "true" : "false") << endl;
    // cout << "Expected: false (cycle: 0->1->2->3->4->0)" << endl << endl;

    return 0;
}
