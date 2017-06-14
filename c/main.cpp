#include <iostream>
#include <chrono>


void test1(int i);
int test2(int i);
long test3(int pos);

int main() {
    std::cout << "Hello, World!" << std::endl;


    for (int i = 0; i < 100; i++) {
        std::cout << test3(i) << "\n";
    }



    return 0;
}

void test1(int pos) {
    auto start = std::chrono::high_resolution_clock::now();

    // operation to be timed ...
    int total = 0;
    for (int i = 0; i < 10000; i++) {
        total += i;
    }


    auto finish = std::chrono::high_resolution_clock::now();


    std::cout << "iteration "
              << pos << " took " <<
              std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count()
              << "ns\n";

}

int test2(int pos) {
    auto start = std::chrono::high_resolution_clock::now();

    // operation to be timed ...
    int total = 0;
    for (int i = 0; i < 10000; i++) {
        total += i - total;
    }


    auto finish = std::chrono::high_resolution_clock::now();


    std::cout << "iteration "
              << pos << " took " <<
              std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count()
              << "ns\n";

    return total;
}

long test3(int pos) {
    const int NDIGITS = 100;          //max digits to compute
    const int LEN = (NDIGITS/4+1)*14;   //nec. array length

    long a[LEN];                   //array of 4-digit-decimals
    long b;                        //nominator prev. base
    long c = LEN;                  //index
    long d;                        //accumulator and carry
    long e = 0;                    //save previous 4 digits
    long f = 10000;                //new base, 4 decimal digits
    long g;                        //denom previous base
    long h = 0;                    //init switch

    auto start = std::chrono::high_resolution_clock::now();

    for(; (b=c-=14) > 0 ;){    //outer loop: 4 digits per loop
        for(; --b > 0 ;){      //inner loop: radix conv
            d *= b;            //acc *= nom prev base
            if( h == 0 )
                d += 2000*f;   //first outer loop
            else
                d += a[b]*f;   //non-first outer loop
            g=b+b-1;           //denom prev base
            a[b] = d % g;
            d /= g;            //save carry
        }
        h = printf("%d",e+d/f);//print prev 4 digits
        d = e = d % f;         //save currently 4 digits
        //assure a small enough d
    }

    auto finish = std::chrono::high_resolution_clock::now();


    std::cout << "iteration "
              << pos << " took " <<
              std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count()
              << "ns\n";

    return h;

}