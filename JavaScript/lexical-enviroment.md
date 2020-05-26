# Lexical Enviroment

In JavaScript, every running function, code block `{...}`, and the script as a whole have an internal (hidden) associated object known as the *Lexical Environment*.

*<b>The Lexical Environment object consists of two parts:</b>*

- *<b>Environment Record</b>* – an object that stores all local variables as its properties (and some other information like the value of `this`).
- <b>A reference to the *outer lexical environment*</b>, the one associated with the outer code.

<hr />

```javascript
function makeCounter() {
  let count = 0;

  return function() {
    return count++;
  };
}

let counter = makeCounter();
```

At the beginning of each `makeCounter()` call, a new Lexical Environment object is created, to store variables for this `makeCounter` run.

<br />

All functions remember the Lexical Environment in which they were made.<br/>Technically, there’s no magic here: all functions have the hidden property named `[[Environment]]`, that keeps the reference to the Lexical Environment where the function was created:

<br/>

Later, when `counter()` is called, a new Lexical Environment is created for the call, and its outer Lexical Environment reference is taken from `counter.[[Environment]]`:

<br/>

## closure

A [closure](https://en.wikipedia.org/wiki/Closure_(computer_programming)) is a function that remembers its outer variables and can access them. In some languages, that’s not possible, or a function should be written in a special way to make it happen. But as explained above, in JavaScript, all functions are naturally closures (there is only one exception, to be covered in [The "new Function" syntax](https://javascript.info/new-function)).

<hr />

*reference* : https://javascript.info/closure#lexical-environment

