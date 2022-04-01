class Solution {
    
    public int findCircleNum(int[][] isConnected) {
        int provinces = 0;
        
        boolean[] visited = new boolean[isConnected.length];
        
        for(int i = 0; i < visited.length;i++) {
            if(!visited[i]) {
                provinces++;
                visit(isConnected, visited, i);
            }
        }
        
        return provinces;
    }
    
    public void visit(int[][] isConnected, boolean[] visited, int city) {
        if(visited[city]) return;
        
        visited[city] = true;
        
        for(int i=0;i<isConnected[city].length;i++) {
            if(i!=city && isConnected[city][i]!=0) {
                visit(isConnected, visited, i);
            }
        }
    }
}