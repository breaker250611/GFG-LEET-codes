class Pair {
    int first, second; 
    Pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
}
class Solution {
    public int[][] updateMatrix(int[][] mat) {
        int n = mat.length;
        int m = mat[0].length; 
        
        Queue<Pair> qu = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    qu.add(new Pair(i, j));
                }
            }
        }
        
        int[] dr = new int[]{1, -1, 0, 0};
        int[] dc = new int[]{0, 0, -1, 1};
        
        int[][] dist = new int[n][m];
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) dist[i][j] = 0;
        
        while (!qu.isEmpty()) {
            Pair p = qu.poll();
            int r = p.first;
            int c = p.second;
            
            for (int d = 0; d < 4; d++) {
                int rr = r + dr[d];
                int cc = c + dc[d];
                
                if (rr < 0 || cc < 0 || rr >= n || cc >= m) continue; 
                if (mat[rr][cc] == 0) continue;
                if (dist[rr][cc] != 0) continue;
                
            // System.out.println(rr + " " + cc);
                qu.add(new Pair(rr, cc));
                dist[rr][cc] = dist[r][c] + 1;
            }
        }
        return dist;
    }
}