# CallBack

스크립트 안의 함수나 변수를 사용하려면 스크립트 로딩이 끝났는지 여부를 알 수 있어야 한다.

```javascript
function loadScript(src, callback) {
  let script = document.createElement('script');
  script.src = src;
  script.onload = () => callback(script);
  document.head.append(script);
}

loadScript('https://cdnjs.cloudflare.com/ajax/libs/lodash.js/3.2.0/lodash.js', script => {
  alert(`${script.src}가 로드되었습니다.`);
  alert( _ ); // 스크립트에 정의된 함수
});
```

> 무언가를 비동기적으로 수행하는 함수는 함수 내 동작이 모두 처리된 후 실행되어야 하는 함수가 들어갈 콜백을 인수로 반드시 제공해야 한다.

***

*reference* : https://ko.javascript.info/callbacks#ref-549

