#include <iostream>
#include <vector>

using namespace std;

vector<int> element(5);
vector<int> parent(5);

int find(int i) {
  if (element[i] == i) return i;
  else return find(parent[i]);
}

void combine(int u, int v) {
  int i = find(u);
  int j = find(v);
  if (i == j) return;
  else if (i > j) parent[i] = j;
  else parent[j] = i;
}

int main() {
  for (int i = 0; i < 5; i++) {
    element[i] = i;
    parent[i] = i;
  }

  combine(0, 1);
  combine(1, 2);
  combine(3, 4);

  cout << find(3) << endl;
  cout << find(4) << endl;
}
