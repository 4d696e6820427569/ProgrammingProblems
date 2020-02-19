class Solution {
    public boolean isHappy(int n) {
        int t = n;
        List<Integer> records = new ArrayList<>();
        do {
            if (records.contains(t)) return false;
            records.add(t);
            int s = 0;
            while (t > 0) {
                s += (t % 10) * (t % 10);
                t = t / 10;
            }
            t = s;
            if (s == 1) return true;
        } while (true);
    }
}
