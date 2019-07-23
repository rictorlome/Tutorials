/*
Challenge 6

Write a function after that takes the number of times the callback needs to be called before
being executed as the first parameter and the callback as the second parameter. 
*/
//Challenge 6
function after(count, func) {
  var countdown = count;
  function afterFunc () {
      countdown--;
      if (countdown <= 0) {
          func();
      }
  }
  return afterFunc;
}

var called = function() { console.log('hello') };
var afterCalled = after(3, called);

afterCalled(); // -> nothing is printed
afterCalled(); // -> nothing is printed
afterCalled(); // -> 'hello' is printed
