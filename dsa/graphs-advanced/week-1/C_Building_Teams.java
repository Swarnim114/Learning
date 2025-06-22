import java.io.*;
import java.util.*;

public class C_Building_Teams {

    //variables
    static ArrayList<ArrayList<Integer>> adj ;
    static int [] vis ;





    static boolean dfs(int node , boolean is_one){

        if(is_one){
            vis[node]=1;
        }else{
            vis[node]=2;
        }
        int cc = 0;

        if(is_one){
            cc=1;
        }else{
            cc=2;
        }

        for(int nb: adj.get(node)){
            if(vis[nb]!=0){
                if(vis[nb]==cc){
                    return false;
                }
            }
            else{
                if(!dfs(nb ,!is_one)) {
                    return false;
                }
            }
        }
        return true;
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
        // Your solution goes here
        String line = br.readLine();
        String[] parts = line.split(" "); // Splits the line by spaces
        int v = Integer.parseInt(parts[0]);
        int e = Integer.parseInt(parts[1]);

        adj = new ArrayList<>();

        for(int i = 0 ; i <= v ; i++){
            adj.add(new ArrayList<>());
        }


        vis = new int[v+1];
        boolean is_one = true;

        for(int i = 0 ; i < e ; i++){
            String str = br.readLine();
            String [] arr = str.split(" ");
            int one = Integer.parseInt(arr[0]) ;
            int two = Integer.parseInt(arr[1]) ;

            // out.println(one + " " + two);
            adj.get(one).add(two);
            adj.get(two).add(one);
        }

        // for(int i=0; i<adj.size(); ++i) {
        //     out.print("adj "+i+" : ");
        //     for(Integer nb : adj.get(i)) {
        //         out.print(nb+" ");
        //     }
        //     out.println();
        // }


        for(int i = 1 ; i <=v ; i++){
            if(vis[i]==0){
                if(!dfs(i , is_one)) {
                    out.println("Impossible");
                }
            }
        }

        for(int i = 1 ; i <=v ; i++){
            out.print(vis[i]+" ");
        }

    }
}
