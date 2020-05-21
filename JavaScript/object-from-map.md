# Object from Map

```javascript
// Object from Map
let map = new Map([
    ['banana', 1],
    ['orange', 2],
    ['meat', 4],
]);
let obj = Object.fromEntries(map);
/* let obj = Object.fromEntries(map.entries()); */


// Map from Object
obj = {
    name : "john",
    age : 30,
};
map = new Map(Object.entries(obj));
```

`Object.fromEntries` expects an iterable object as the argument. Not necessarily an array. And the standard iteration for `map` returns same key/value pairs as `map.entries()`.

<hr />

*reference* : https://javascript.info/map-set

