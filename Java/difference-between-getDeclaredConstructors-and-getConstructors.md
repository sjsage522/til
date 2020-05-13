# Difference between getDeclaredConstructors and getConstructors

<a href="https://docs.oracle.com/javase/7/docs/api/java/lang/Class.html#getDeclaredConstructors()">`getDeclaredConstructors`</a> (when you want <b>all</b> the constructors)

> Returns an array of Constructor objects reflecting all the constructors declared by the class represented by this Class object. These are public, protected, default (package) access, and private constructors.

<br />

<a href="https://docs.oracle.com/javase/7/docs/api/java/lang/Class.html#getConstructor(java.lang.Class...)">`getConstructors`</a> (when you want **only `public`** constructors)

> Returns an array containing Constructor objects reflecting all the public constructors of the class represented by this Class object.

<hr>

*reference* :  <a href="https://stackoverflow.com/questions/8249173/what-is-the-difference-between-getdeclaredconstructors-and-getconstructors-in-th">stackoverflow</a>

