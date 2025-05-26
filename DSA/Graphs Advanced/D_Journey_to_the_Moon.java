import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class D_Journey_to_the_Moon {

    static ArrayList<ArrayList<Integer>> adj;
    static boolean[] vis;

    static int dfsCountNodes(int node) {
        vis[node] = true;
        int count = 1;

        for (int nb : adj.get(node)) {
            if (!vis[nb]) {
                count += dfsCountNodes(nb);
            }
        }
        return count;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        solve(br, out);

        out.flush();
        out.close();
        br.close();
    }

    static void solve(BufferedReader br, PrintWriter out) throws IOException {
        StringTokenizer st = new StringTokenizer(br.readLine());
        int v = Integer.parseInt(st.nextToken());
        int e = Integer.parseInt(st.nextToken());

        adj = new ArrayList<>();
        for (int i = 0; i < v; i++) {
            adj.add(new ArrayList<>());
        }

        vis = new boolean[v];

        for (int i = 0; i < e; i++) {
            st = new StringTokenizer(br.readLine());
            int one = Integer.parseInt(st.nextToken());
            int two = Integer.parseInt(st.nextToken());

            adj.get(one).add(two);
            adj.get(two).add(one);
        }

        ArrayList<Integer> componentSizes = new ArrayList<>();
        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                componentSizes.add(dfsCountNodes(i));
            }
        }


        long total = (long)v * ((long)v - 1) / 2;

        long same = 0;
        for (int size : componentSizes) {
            same += (long) size * (size - 1) / 2;
        }

        long ans = total - same;

        out.println(ans);
    }
}
