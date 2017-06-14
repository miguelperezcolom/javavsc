package io.mateu.javavsc;

/**
 * Hello world!
 *
 */
public class AddIntegers
{
    public static void main( String[] args )
    {

        System.out.println( "Hello World!" );

        for (int i = 0; i < 1000; i++) {
            test(i);
        }

    }

    public static void test(int pos) {
        long t0 = System.nanoTime();

        for (int i = 0; i < 10000; i++) {
            i++;
        }

        long t1 = System.nanoTime();

        System.out.println("iteration " + pos
                + " took " + (t1 - t0) + " ns.");
    }
}
