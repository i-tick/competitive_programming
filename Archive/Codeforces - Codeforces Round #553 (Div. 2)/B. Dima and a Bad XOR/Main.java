import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author cunbidun
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        BDimaAndABadXOR solver = new BDimaAndABadXOR();
        solver.solve(1, in, out);
        out.close();
    }

    static class BDimaAndABadXOR {
        private InputReader in;
        private PrintWriter out;

        public void solve(int testNumber, InputReader in, PrintWriter out) {
            this.in = in;
            this.out = out;
            int n = in.nextInt();
            int m = in.nextInt();
            int[][] a = in.nextIntTable(n, m, 1, 1);
            int cur = 0;
            for (int i = 1; i <= n; i++) {
                cur ^= a[i][1];
            }
            if (cur != 0) {
                out.println("TAK");
                for (int i = 1; i <= n; i++) {
                    out.print(1 + " ");
                }
                return;
            }
            for (int i = 1; i <= n; i++) {
                for (int j = 2; j <= m; j++) {
                    if (a[i][j] != a[i][1]) {
                        out.println("TAK");
                        for (int k = 1; k < i; k++) {
                            out.print(1 + " ");
                        }
                        out.print(j + " ");
                        for (int k = i + 1; k <= n; k++) {
                            out.print(1 + " ");
                        }
                        return;
                    }
                }
            }
            out.println("NIE");
        }

    }

    static class InputReader extends InputStream {
        private InputStream stream;
        private byte[] buf = new byte[1024];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (numChars == -1) {
                throw new InputMismatchException();
            }
            if (curChar >= numChars) {
                curChar = 0;
                try {
                    numChars = stream.read(buf);
                } catch (IOException e) {
                    throw new InputMismatchException();
                }
                if (numChars <= 0) {
                    return -1;
                }
            }
            return buf[curChar++];
        }

        public int nextInt() {
            int c = read();
            while (isSpaceChar(c))
                c = read();
            int sgn = 1;
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            int res = 0;
            do {
                if (c < '0' || c > '9') {
                    throw new InputMismatchException();
                }
                res *= 10;
                res += c - '0';
                c = read();
            } while (!isSpaceChar(c));
            return res * sgn;
        }

        public int[][] nextIntTable(int row, int col, int rowSt, int colSt) {
            int[][] arr = new int[row + rowSt][col + colSt];
            for (int i = rowSt; i < row + rowSt; i++) {
                for (int j = colSt; j < col + colSt; j++) {
                    arr[i][j] = nextInt();
                }
            }
            return arr;
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}