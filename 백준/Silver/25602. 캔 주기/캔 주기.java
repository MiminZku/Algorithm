import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    static int N; //캔의 종류
    static int K; //일수
    static int[] A; // 각 캔의 개수
    static int[][] R; //랑이의 캔의 선호도
    static int[][] M; //메리의 캔의 선호도
    static int sum;
    static int max;
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken());
        K  = Integer.parseInt(st.nextToken());
        
        A = new int[N];
        R = new int[K][N];
        M = new int[K][N];
        
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            A[i] = Integer.parseInt(st.nextToken());
        }

        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                R[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for (int i = 0; i < K; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < N; j++) {
                M[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        dfs(0, false);


        System.out.print(max);


    }

    private static void dfs(int day, boolean isM) {
        if(day == K){
            if(isM) {
                max = Integer.max(max, sum);        
            }
            else {
                dfs(0, true);
            }
            return;
        }

        for (int i = 0; i < N; i++) {
            if(A[i] == 0)    continue;
            
            A[i]--;
            sum += isM ? M[day][i] : R[day][i];
            
            dfs(day+1, isM);
                        
            sum -= isM ? M[day][i] : R[day][i];
            A[i]++;                      
        }
    }
}