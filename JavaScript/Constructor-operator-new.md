# Constructor, operator "new"

The regular `{...}` syntax allows to create one object. But often we need to create many similar objects, like multiple users or menu items and so on.

That can be done using constructor functions and the `"new"` operator.

> constructor.js

```javascript
function Accumulator(startingValue) {
    this.value = startingValue;
    this.read = function () {
        this.value += +prompt("Input value", "0");
    }
}

let accumulator = new Accumulator(1);

accumulator.read();
accumulator.read();

alert(accumulator.value);
```

<hr/>

*reference* : <a href="https://javascript.info/constructor-new#create-new-accumulator">JavaScript.Info</a>