public class LevelOne{
    public static int max = 100000;

    public static String sieve(int n) {
        boolean[] flag = new boolean[max];
        String prime = "2";

    	for (int i=3; i*i<=n; i+=2) {
	    	if (flag[i]) continue;
		    for (int j=3; i*j <= n ; j+=2)
		    	flag[i*j] = true;
	    }
	    for (int i=3; i<=n; i+=2)
		    if (!flag[i]) prime += "" + i;
	    return prime;
    }
    public static String solution(int n) {
	    String primeString = sieve(max);
	    return primeString.substring(n, n+5);
    }

    public static void main(String[] args) {
    	int i = 10000;
    	String output = solution(i);
    	System.out.println(output);
    }
}
