import java.util.Comparator;
import java.util.Arrays;

class SortVersions implements Comparator<String> {
	private int seqComp(String[] a, String[] b, int index) {
		if (a.length < index+1 || b.length < index+1) {
			if (a.length > b.length) return 1;
			else if (a.length < b.length) return -1;
			return 0;
		}

		int f = Integer.parseInt(a[index]);
		int s = Integer.parseInt(b[index]);

		if (f == s)
			return seqComp(a, b, index+1);
		return f - s; 
	}

	public int compare(String a, String b) {
		String[] parsedA = a.split("\\.", 4);
		String[] parsedB = b.split("\\.", 4);

		return seqComp(parsedA, parsedB, 0);
	}
} 

public class Solution {
	public static void print (String[] a) {
		for (int i=0; i<a.length; i++) {
			if (i == a.length - 1) {
				System.out.printf(a[i] + ",");
				break;							
			}
			System.out.printf(a[i] + ",");
		}
		System.out.println("");
	}

  public static String[] solution(String[] versions) {
	    Arrays.sort(versions, new SortVersions());
	    return versions;
  }

  public static void main(String[] args) {
  	// String a = "0.0.0";
  	// String b = "0.0.0";
  	// SortVersions sort = new SortVersions();
  	// int r = sort.compare(a, b);
  	// System.out.println(r);

  	String[] input = {"1.11", "2.0.0", "1.2", "2", "0.1", "1.2.1", "1.1.1", "2.0"};
  	var r = solution(input);
  	print(r);
  }
}