import sun.text.CollatorUtilities;

import static java.util.Arrays.sort;

/**
 * Created by Jaden on 14/02/2016.
 */

// 입력을 받아서 string 의 suffix 를 저장하여 가지고 있는다.


public class SuffixArray {


    private int[] lcp;

    private String[] suffixes;

    private int[] suffixArray;

    private String pattern;

    public SuffixArray(String pattern) {
        suffixes = new String[pattern.length()];
        suffixArray = new int[pattern.length()];
        this.pattern = pattern;
    }


    private void makeSuffixArray() {
        for(int i=0; i<suffixes.length; i++) {
            suffixes[i] = pattern.substring(i);

        }

        sort(suffixes);

        for(int i=0; i<suffixes.length; i++) {
            suffixArray[i] = pattern.length() - suffixes[i].length() + 1;
        }

    }

    public String[] getSuffixes() {
        return suffixes;
    }


    public int[] getArray() {
        return suffixArray;
    }

    public void makeLCP() {
        lcp = new int[suffixArray.length];
        lcp[0] = -1;


        for(int i=0; i< lcp.length-1; i++) {
            int cnt = 0;
            int length = suffixes[i].length() < suffixes[i + 1].length() ? suffixes[i].length() : suffixes[i + 1].length();

            for(int j=0; j<length; j++) {
                if(suffixes[i+1].charAt(j) == suffixes[i].charAt(j)) {
                    cnt++;
                } else {
                    break;
                }
            }
            lcp[i] = cnt;
        }
    }

    public int[] getLcp() {
        return lcp;
    }

    public static void main(String[] args) {
        SuffixArray sa = new SuffixArray("yeshowmuchiloveyoumydearmotherreallyicannotbelieveit" +
                "yeaphowmuchiloveyoumydearmother");

        sa.makeSuffixArray();
        sa.makeLCP();
        for(int i=0; i<sa.getArray().length; i++) {
            System.out.println(sa.getArray()[i] + "  " + sa.getSuffixes()[i] + "   " + sa.getLcp()[i]);
        }

    }
}
