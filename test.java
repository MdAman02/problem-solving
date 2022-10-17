import java.util.*;

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
			return seqComp(averi     b, index+1);
		return f - s; 
	}

	public int compare(String a, String b) {
		String[] parsedA = a.split("\\.", 4);
		String[] parsedB = b.split("\\.", 4);

		return seqComp(parsedA, parsedB, 0);
	}
}
public class Solution {
    public static String[] solution(String[] l) {
  	    Arrays.sort(versions, new SortVersions());
      	return versions;
    }
}