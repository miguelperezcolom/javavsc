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
            System.out.println(test3(i));
        }

    }

    public static void test1(int pos) {
        long t0 = System.nanoTime();

        int total = 0;
        for (int i = 0; i < 10000; i++) {
            total += i;
        }

        long t1 = System.nanoTime();

        System.out.println("iteration " + pos
                + " took " + (t1 - t0) + " ns.");

    }

    public static int test2(int pos) {
        long t0 = System.nanoTime();

        int total = 0;
        for (int i = 0; i < 10000; i++) {
            total += i - total;
        }

        long t1 = System.nanoTime();

        System.out.println("iteration " + pos
                + " took " + (t1 - t0) + " ns.");

        return total;
    }

    public static String test3(int pos) {

        int NDIGITS = 100;          //max digits to compute
        int LEN = (NDIGITS/4+1)*14;

        long[] a = new long[LEN];                   //array of 4-digit-decimals
        int b = 0;                        //nominator prev. base
        int c = LEN;                  //index
        long d = 0;                        //accumulator and carry
        long e = 0;                    //save previous 4 digits
        long f = 10000;                //new base, 4 decimal digits
        long g = 0;                        //denom previous base
        StringBuffer h = new StringBuffer();                    //init switch

        long t0 = System.nanoTime();

        for(; (b=c-=14) > 0 ;){    //outer loop: 4 digits per loop
            for(; --b > 0 ;){      //inner loop: radix conv
                d *= b;            //acc *= nom prev base
                if( h.length() == 0 )
                    d += 2000*f;   //first outer loop
                else
                    d += a[b]*f;   //non-first outer loop
                g=b+b-1;           //denom prev base
                a[b] = d % g;
                d /= g;            //save carry
            }
            h.append(e+d/f);//print prev 4 digits
            d = e = d % f;         //save currently 4 digits
            //assure a small enough d
        }

        long t1 = System.nanoTime();

        System.out.println("iteration " + pos
                + " took " + (t1 - t0) + " ns.");


        return h.toString();
    }
}
