# java vs c++
real case java versus c++

Here I will try to compare java vs c++ performance with a real life case: a hotel availability request.

I think I will also add some microbenchmarks.

## Performance definition

For me performance means response time.

To decide who wins I will compare average response times for the same availability during, let's say, 20 minutes.

I will discard results during warm up, let's say 10 minutes, to let the JIT run.

I do not expect to see STWs (stop the world) pauses due to full garbage collector during the tests.


## Expected results before running tests

My idea today is that performance should be the same, or perhaps a little better in java.

This idea is because of string handling in java, because of java's JIT intelligence and because of jvm's garbage collection.

Yes, jvm's garbage collection should be an advantage as in java we can return our results as soon as we have built them, while with c++ the method execution won't finish until we have disposed of all our temporary objects. 

Anyway I think I will add also run the test measuring only the time to build the results, discarding c++'s objects disposing time, as we can argue that the important thing is the time that our client need to get the response and we could deliver the response and clean later. 

Naturally I expect to see good numbers for c++ from the begining, while I know I will have to let the jvm's JIT actuate before measuring results for java.


## Planing

I plan to build this during August 2017.


## Java vs c++ complete war

Performance is just a battle.

There are other considerations that we must think of before deciding to start a development with c++ or java.

I think no one would seriously consider to start a development with c++ unless he is crazy: 

- lack of trained developers
- horrible compilation times
- c++ is a really ugly language (not c which I like, but c++ seems to me like a bunch of patches to bring OOP to c and with a lot of misunderstandings)
- very poor ecosystem
- you must be very much more careful when programming with c++

Or unless he wants to develop a driver, a controller or something like this. Or if you plan to develop somethink that must run using only 4k ram.

The other reason to use c++ is performance, but this is something I think is a myth and I want to check by myself.

This project is born to verify this last point.




