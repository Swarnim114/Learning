import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class A_Labyrinth {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);

        // Read the number of test cases
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());

        while (t-- > 0) {
            solve(br, out);
        }

        out.flush();
        out.close();
        br.close();
    }

    static void solve(BufferedReader br, PrintWriter out) throws IOException {
        // Your solution goes here
        // Example: Reading two integers from a line
        // StringTokenizer st = new StringTokenizer(br.readLine());
        // int val1 = Integer.parseInt(st.nextToken());
        // int val2 = Integer.parseInt(st.nextToken());

        // Example: Reading a single integer from a line
        // int singleVal = Integer.parseInt(br.readLine());

        // Example: Reading a string token (space-separated)
        // String strToken = st.nextToken();

        // Example: Reading an entire line as a string
        // String entireLine = br.readLine();

        // Remember to use 'out.println()' or 'out.print()' for output.
    }
}
