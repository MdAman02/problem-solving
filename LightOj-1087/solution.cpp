#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

#define MAX 50010

void buildSegmentTree(int l, int r, int node, int length, int* tree) {
  if (l == r) {
    tree[node] = l < length? 1: 0;
    return;
  }
  int mid = (l+r)/2;
  buildSegmentTree(l, mid, node*2, length, tree);
  buildSegmentTree(mid+1, r, node*2+1, length, tree);
  tree[node] = tree[node*2] + tree[node*2+1];
}

int rangeQuery(int l, int r, int tl, int tr, int v, int* tree) {
  if (l > r || l > tr || r < tl)
    return 0;
  if ((l <= tl && r >= tr) || tl == tr)
    return tree[v];

  return rangeQuery(l, r, tl, (tl+tr)/2, 2*v, tree)
    + rangeQuery(l, r, (tl+tr)/2+1, tr, 2*v+1, tree);
}

void updateQuery(int pos, int newVal, int tl, int tr, int v, int *tree) {
  if (tl == tr) {
    tree[v] = newVal;
    return;
  }

  int mid = (tl+tr)/2;
  if (pos <= mid)
    updateQuery(pos, newVal, tl, mid, v*2, tree);
  else
    updateQuery(pos, newVal, mid+1, tr, v*2+1, tree);
  tree[v] = tree[2*v] + tree[2*v+1];
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("ouput.txt", "w", stdout);

  int t;
  scanf("%d", &t);

  for (int c = 1; c <= t; c++) {
    cout<<"Case "<<c<<":"<<endl;
    int n,q;
    cin>>n>>q;

    int maxTreeIndex = (n+MAX)*4;
    int maxLength = n+MAX;
    int arr[n+MAX];
    int segmentTree[maxTreeIndex] = {0};

    for (int i=0; i<n; i++){
      cin>>arr[i];
      updateQuery(i, 1, 0, maxLength, 1, segmentTree);
    }

    int lastPos = n-1;
    for (int i=0; i<q; i++) {
      int val;
      char type;
      cin>>type>>val;


      if (type == 'a'){
        arr[++lastPos] = val;
        updateQuery(lastPos, 1, 0, maxLength, 1, segmentTree);
      } else {
        int lo = 0, hi = lastPos, absolutePos = -1;
        while(lo <= hi) {
          int mid = (lo+hi)/2;
          int maxRelPos = rangeQuery(0, mid, 0, maxLength, 1, segmentTree);
          if (maxRelPos >= val) {
            if (maxRelPos == val) absolutePos = mid;
            hi = mid-1;
          } else {
            lo = mid+1;
          }
        }
        if (absolutePos == -1) {
          cout<<"none"<<endl;
        }
        else {
          cout<<arr[absolutePos]<<endl;
          updateQuery(absolutePos, 0, 0, maxLength, 1, segmentTree);
        }
      }
    }
  }

  return 0;
}
