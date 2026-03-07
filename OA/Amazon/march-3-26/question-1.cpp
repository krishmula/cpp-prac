// We have an array of resourceComposition, from which resourceConsumption[i] tells us the resource consumption of an element i. The idea is that, at every iteration, we need to remove the least resource consuming element, and it’s immediately adjacent elements, until all elements are removed. And, as for the cost, the minimum resource consumption element that is removed in every iteration is considered (not the adjacent elements). Return the total cost across all iterations.


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;

vector<int> removeResources(vector<int>& resourceComposition) {
}

int main() {
    vector<int> resourceComposition = {6, 4, 8, 2, 5};
    vector<int> result = removeResources(resourceComposition);
}