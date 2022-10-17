## Observations
- The expected amount of gold from position i(Ex_Vi) : the total collectable gold starting from i * Probability of getting into i-th pos
- For pos i, We get an equal probability distribution 1/6 for the dice outcomes (i+6 <= N). For (i+6 > N), as we contine rolling until dice output doesn't go out of grid. Its also an equal distribution of 1/(N-i) 
- `Ex_V(i) = gold[i] + (1/6)*Ex_V(i+1) + (1/6)*Ex_V(i+2) + (1/6)*Ex_V(i+3) + (1/6)*Ex_V(i+4) + (1/6)*Ex_V(i+5) + (1/6)*Ex_V(i+6)`
- For i+6 > N, 
  `Ex_V(i) = gold[i] + (1/6)*Ex_V(i+j) + ...` where i+j <= N
- Its a recurring relation with base, Ex_V(N) = gold[N]
