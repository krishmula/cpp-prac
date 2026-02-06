#include <iostream>
#include <vector>

using namespace std;

vector<int> element(5);
vector<int> parent(5);

int main() {
  for (int i = 0; i < 5; i++) {
    element[i] = i;
    parent[i] = i;
  }
}

int find(int i) {
  if (element[i] == i)
    return i;
  else
    return find(parent[i]);
}
