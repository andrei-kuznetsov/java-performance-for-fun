package test;

import org.junit.Test;

public class ArithmeticProgressionTest {

    private static final long SZ = 630_000_000L;
    public volatile long res;

    @Test
    public void perfTest() {
        for (int i = 0; i < 4000; i++) {
            long started = System.nanoTime();
            res = calcArithmeticProgression(SZ);
            long ended = System.nanoTime();
            System.out.println((ended - started) / 1_000_000);
        }
    }

    private long calcArithmeticProgression(long sz) {
        long now = 1;
        long sum = 1;
        while (now < sz) {
            sum += now;
            now++;
        }
        return sum;
    }
}
