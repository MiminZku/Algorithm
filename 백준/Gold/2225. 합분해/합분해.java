import java.io.*;

public class Main{
    static long[][] dp;
    static final long MOD = 1000000000;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        
        String line[] = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int k = Integer.parseInt(line[1]);
        
        dp = new long[k+1][n+1];
        
        topDown(k, n);
        
        bw.write(String.valueOf(dp[k][n]));
        br.close();
        bw.flush();
    }
    
    // Top-Down 방식
    public static long topDown(int k, int n){
        // 여기서 반환 조건식을 지정함
        // 값이 최소값이 아니거나 n=0이면 반환
        if(dp[k][n] > 0) return dp[k][n]; // 값이 있거나 n이 0이면 반환
        if(n == 0 || k == 1) return dp[k][n] = 1;
        
        // 재귀를 통해서 값을 구해온다.
        for(int m=n; m >= 0; m--){
            dp[k][n] += topDown(k-1, m);
            dp[k][n] %= MOD;
        }
        return dp[k][n];
    }
}