# Searching in array

## find

if true is returned, item is returned and iteration is stopped.

for falsy scenario returns undefined.

```javascript
let users = [
  {id: 1, name: "John"},
  {id: 2, name: "Pete"},
  {id: 3, name: "Mary"}
];

let user = users.find(item => item.id == 1);

alert(user.name); // John
```

<hr />

## filter

if true item is pushed to results and the iteration continues.

returns empty array if nothing found.

```javascript
let users = [
  {id: 1, name: "John"},
  {id: 2, name: "Pete"},
  {id: 3, name: "Mary"}
];

// returns array of the first two users
let someUsers = users.filter(item => item.id < 3);

alert(someUsers.length); // 2
```

<hr />

*reference* : *https://javascript.info/array-methods*

