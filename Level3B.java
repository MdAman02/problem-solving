public class Level3B{
  public static int solution(int[] n) {
    int res = 0;
    int[] store = new int[2010];
    
    for (int i=0; i<n.length; i++)
      for (int j=i+1; j<n.length; j++)
        if (n[j] % n[i] == 0) {
          store[j]++;
          res += store[i];
        }

    return res;
  }

  public static void main(String[] args) {
    
  }
}
