public class EnRouteSalute{
	public static int solution(String s) {
		int[] suffixSum = new int[s.length()];
		int[] prefixSum = new int[s.length()];
		int res = 0;

		for (int i=0; i<s.length(); i++) {
			if (i==0) {
				prefixSum[i] += (s.charAt(i) == '>' ? 1 : 0);
				continue;
			}

			prefixSum[i] += prefixSum[i-1] + (s.charAt(i) == '>' ? 1 : 0);
		}

		for (int i=s.length()-1; i>=0; i--) {
			if (i==s.length()-1) {
				suffixSum[i] += (s.charAt(i) == '<' ? 1 : 0);
				continue;
			}

			suffixSum[i] += suffixSum[i+1] + (s.charAt(i) == '<' ? 1 : 0);
		}

		for (int i=0; i<s.length(); i++) {
			if (s.charAt(i) == '>' && i != s.length()-1)
				res += suffixSum[i+1];
			else if (s.charAt(i) == '<' && i != 0)
				res += prefixSum[i-1];
		}

		return res;
	}

  public static void main(String[] args) {
  	String s = ">----<";
  	int res = solution(s);
  	System.out.println(res);
  }
}
