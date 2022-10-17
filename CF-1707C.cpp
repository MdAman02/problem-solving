// Unsolved
#include<iostream>
using namespace std;

int main() {

}

// Alternative solution for Div1C:

// Each of the edges not in MST gives us a restriction on which vertices can be good. We can view those restrictions as values, i.e. for each edge we can either add 1 to all good vertices or subtract 1 from all bad vertices. In the end vertices with values equal to the total number of additions are good.

// The trick is that we actually don't need to update all good or all bad vertices for every edge, but just 2.

// Pick an any vertex 𝑠 and run dfs on MST starting from 𝑠.

// Now suppose that we are at the some vertex 𝑣 and there is an edge (𝑣,𝑤) in the original graph, but not in MST. We can also assume that we have already visited 𝑤, since edges are bidirectional.

// There are 2 cases:

// 𝑤 is not an ancestor of 𝑣: the the only possible good vertices lie in subtrees of 𝑣 and 𝑤, so we can increment values of 𝑣 and 𝑤 by 1
// 𝑤 is an ancestor of 𝑣: let 𝑝 be an ancestor of 𝑣, such that 𝑤 is the parent of 𝑝, then all vertices that are descendants of 𝑝, but not descendants of 𝑣 are bad, so we can decrement value of 𝑝 by 1 and increment value of 𝑣 by 1
// After that the values of each vertex 𝑣 is sum of the values of vertices on the path between 𝑣 and root 𝑠, so we can just run another dfs from 𝑠 to calculate the answer.
