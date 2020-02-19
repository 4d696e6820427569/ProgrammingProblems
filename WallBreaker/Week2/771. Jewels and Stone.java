class Solution {
    public int numJewelsInStones(String J, String S) {
        char[] jewels_list = new char[128];
        for (int i = 0; i < 128; i++) jewels_list[i] = 0;
        for (char c : J.toCharArray()) jewels_list[c] += 1;

        int num_jewels = 0;
        for (char c : S.toCharArray()) {
            if (jewels_list[c] == 1) num_jewels++;
        }
        return num_jewels;
    }
}
