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
        CPalindromicMatrix solver = new CPalindromicMatrix();
        solver.solve(1, in, out);
        out.close();
    }

    static class CPalindromicMatrix {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            int n = in.nextInt();
            int[] cnt = new int[1001];
            int[] a = in.nextIntArray(n * n, 1);
            for (int i = 1; i <= n * n; i++) {
                cnt[a[i]]++;
            }
            if (n % 2 == 0) {
                for (int i = 1; i <= 1000; i++) {
                    if (cnt[i] % 4 != 0) {
                        out.println("NO");
                        return;
                    }
                }
                out.println("YES");
                int[][] ans = new int[n + 1][n + 1];
                for (int i = 1; i <= n / 2; i++)
                    for (int j = 1; j <= n / 2; j++)
                        for (int k = 1; k <= 1000; k++) {
                            if (cnt[k] >= 4) {
                                ans[i][j] = k;
                                cnt[k] -= 4;
                                break;
                            }
                        }
                for (int i = 1; i <= n / 2; i++) {
                    for (int j = 1; j <= n / 2; j++) {
                        out.print(ans[i][j] + " ");
                    }
                    for (int j = n / 2; j >= 1; j--) {
                        out.print(ans[i][j] + " ");
                    }
                    out.println();
                }
                for (int i = n / 2; i >= 1; i--) {
                    for (int j = 1; j <= n / 2; j++) {
                        out.print(ans[i][j] + " ");
                    }
                    for (int j = n / 2; j >= 1; j--) {
                        out.print(ans[i][j] + " ");
                    }
                    out.println();
                }
            } else {
                int check = 0;
                for (int i = 1000; i >= 1; i--) {
                    if (check < (n / 2) * (n / 2))
                        while (cnt[i] >= 4) {
                            cnt[i] -= 4;
                            check++;
                            if (check == (n / 2) * (n / 2)) break;
                        }
                    if (check == (n / 2) * (n / 2)) break;
                }
                for (int i = 1000; i >= 1; i--) {
                    while (cnt[i] >= 2) {
                        cnt[i] -= 2;
                        check++;
                    }
                    while (cnt[i] == 1) {
                        cnt[i] -= 1;
                        check++;
                    }
                }
                if (check != (n / 2 + 1) * (n / 2 + 1)) {
                    out.println("NO");
                    return;
                }
                out.println("YES");
                for (int i = 1; i <= n * n; i++) {
                    cnt[a[i]]++;
                }
                int[][] ans = new int[n + 1][n + 1];
                for (int i = 1; i <= n / 2; i++)
                    for (int j = 1; j <= n / 2; j++)
                        for (int k = 1; k <= 1000; k++) {
                            if (cnt[k] >= 4) {
                                ans[i][j] = k;
                                cnt[k] -= 4;
                                break;
                            }
                        }
                int[] row = new int[n + 1];
                int[] column = new int[n + 1];
                for (int j = 1; j <= n / 2; j++)
                    for (int k = 1; k <= 1000; k++) {
                        if (cnt[k] >= 2) {
                            row[j] = k;
                            cnt[k] -= 2;
                            break;
                        }
                    }
                for (int j = 1; j <= n / 2; j++)
                    for (int k = 1; k <= 1000; k++) {
                        if (cnt[k] >= 2) {
                            column[j] = k;
                            cnt[k] -= 2;
                            break;
                        }
                    }
                int centre = 0;
                for (int k = 1; k <= 1000; k++) {
                    if (cnt[k] == 1) {
                        centre = k;
                        break;
                    }
                }
                //       out.println("centre: " + centre);

                for (int i = 1; i <= n / 2; i++) {
                    for (int j = 1; j <= n / 2; j++) {
                        out.print(ans[i][j] + " ");
                    }
                    out.print(column[i] + " ");
                    for (int j = n / 2; j >= 1; j--) {
                        out.print(ans[i][j] + " ");
                    }
                    out.println();
                }
                for (int i = 1; i <= n / 2; i++) {
                    out.print(row[i] + " ");
                }
                out.print(centre + " ");
                for (int i = n / 2; i >= 1; i--) {
                    out.print(row[i] + " ");
                }
                out.println();
                for (int i = n / 2; i >= 1; i--) {
                    for (int j = 1; j <= n / 2; j++) {
                        out.print(ans[i][j] + " ");
                    }
                    out.print(column[i] + " ");
                    for (int j = n / 2; j >= 1; j--) {
                        out.print(ans[i][j] + " ");
                    }
                    out.println();
                }
            }
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

        public int[] nextIntArray(int length, int stIndex) {
            int[] arr = new int[length + stIndex + 10];
            for (int i = stIndex; i < stIndex + length; i++)
                arr[i] = nextInt();
            return arr;
        }

        private static boolean isSpaceChar(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

    }
}