# About wait(), notify() and notifyAll()

The `Object` class in Java has three final methods that allow threads to communicate about the locked status of a resource.

****

1. <b>wait()</b>

   It tells the calling thread to give up the lock and go to sleep until some other thread enters the same monitor and calls `notify()`.

2. <b>notify()</b>
   It wakes up one single thread that called `wait()` on the same object.

3. <b>notifyAll</b>
   It wakes up all the threads that called `wait()` on the same object. The highest priority thread will run first in most of the situation, though not guaranteed.

****

*reference* : https://howtodoinjava.com/java/multi-threading/wait-notify-and-notifyall-methods/