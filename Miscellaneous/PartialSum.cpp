void update(int x1, int y1, int x2, int y2, int val) {
    p_sum[x1][y1] += val;
    p_sum[x2 + 1][y2 + 1] += val;
    p_sum[x1][y2 + 1] -= val;
    p_sum[x2 + 1][y1] -= val;
}
