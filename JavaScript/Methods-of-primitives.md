# Methods of primitives

<b>primitives are not objects</b>

## A primitive as an object

- Primitives are still primitive. A single value, as desired.
- The language allows access to methods and properties of strings, numbers, booleans and symbols.
- In order for that to work, a special “object wrapper” that provides the extra functionality is created, and then is destroyed.

<hr />

*following example*

```javascript
let str = "Hello";

alert( str.toUpperCase() ); // HELLO
```

Here’s what actually happens in `str.toUpperCase()`:

1. The string `str` is a primitive. So in the moment of accessing its property, a special object is created that knows the value of the string, and has useful methods, like `toUpperCase()`.
2. That method runs and returns a new string (shown by `alert`).
3. The special object is destroyed, leaving the primitive `str` alone.

<br/>

*try running it*

```javascript
let str = "Hello";

str.test = 5; // (*)

alert(str.test);
```

Depending on whether you have `use strict` or not, the result may be:

1. `undefined` (no strict mode)
2. An error (strict mode).

Why? Let’s replay what’s happening at line `(*)`:

1. When a property of `str` is accessed, a “wrapper object” is created.
2. In strict mode, writing into it is an error.
3. Otherwise, the operation with the property is carried on, the object gets the `test` property, but after that the “wrapper object” disappears, so in the last line `str` has no trace of the property.

<br/>

<b>This example clearly shows that primitives are not objects.</b>

They can’t store additional data.

<hr />

*reference* : <a href="https://javascript.info/primitives-methods">JavaScript.Info</a>