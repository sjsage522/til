# Remove element of Arrays

Arrays are objects, so can we delete elements using `delete`?

```javascript
let arr = ["I", "go", "home"];

delete arr[1]; // remove "go"

alert( arr[1] ); // undefined

// now arr = ["I",  , "home"];
alert( arr.length ); // 3
```

The element was removed, but the array still has 3 elements <br/>That’s natural, because `delete obj.key` removes a value by the `key`

## splice

\*\*\**syntax*

```javascript
arr.splice(index[, deleteCount, elem1, ..., elemN])
```

<hr />

**\*\*following example*

```javascript
let arr = ["I", "study", "JavaScript"];

arr.splice(1, 1); // from index 1 remove 1 element

alert( arr ); // ["I", "JavaScript"]
```

Starting from the index `1` it removed `1` element.

<br />

```javascript
let arr = ["I", "study", "JavaScript", "right", "now"];

// remove 2 first elements
let removed = arr.splice(0, 2);

alert( removed ); // "I", "study" <-- array of removed elements
```

`splice` returns the array of removed elements.

<br />

```javascript
let arr = ["I", "study", "JavaScript"];

// from index 2
// delete 0
// then insert "complex" and "language"
arr.splice(2, 0, "complex", "language");

alert( arr ); // "I", "study", "complex", "language", "JavaScript"
```

The `splice` method is also able to insert the elements without any removals.

<hr />

*reference* : <a href="https://javascript.info/array-methods">JavaScript.Info</a>

