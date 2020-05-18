# Optional chaining '?.'

The optional chaining `?.` is an error-proof way to access nested object properties, even if an intermediate property doesn’t exist.

> optionalChaining.js

```javascript
let user1 = {
    firstName : "Violet",
    admin() {
        alert("Admin Account.");
    }
};

let user2 = null;

let key = "firstName";

alert( user1?.[key] ); // Violet
alert( user2?.[key] ); // undefined
alert( user1.admin?.() ); // Admin Account.
alert( user1.something?.() ); // undefined
```

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
<script src="optionalChaining.js"></script>
</body>
</html>
```

<hr/>

*reference* : <a href="https://javascript.info/optional-chaining#summary">JavaScript.Info</a>

