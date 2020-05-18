# chaining

Function chaining is a pattern in JavaScript where multiple functions are called on the same object consecutively. 

Using the same object reference, multiple functions can be invoked. It increases the readability of the code and means less redundancy.

We need multiple functions to accomplish all the functionality related to an entity. <br/><b>These functions can be defined in such a way that they can be chained together to accomplish the required results.</b>

> chaining.js

```javascript
let ladder = {
    step: 0,
    up() {
        this.step++;
        return this;
    },
    down() {
        this.step--;
        return this;
    },
    showStep: function () {
        alert(this.step);
    },
};

ladder.up().up().down().showStep();
```

<br/>

> index.html

```html
<!doctype html>
<html lang="ko">
<head>
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>Document</title>
</head>
<body>
<script src="chaining.js"></script>
</body>
</html>
```

<hr />

*reference* : <a href="https://ko.javascript.info/object-methods#ref-249">JavaScript.info</a>, <a href="https://medium.com/better-programming/javascript-function-chaining-8b2fbef76f7f">Midium</a>

