/*
Challenge 5

Write a function once that accepts a callback as input and returns a function.
When the returned function is called the first time, it should call the callback 
and return that output. If it is called any additional times, instead of calling 
the callback again it will simply return the output value from the first time it
was called. 
*/


//Challenge 5
function once(func) {
  var beenUsed = false;
  var onceOutput;
  function onceFunc(x) {
      if (!beenUsed) {
        onceOutput = func(x);
        beenUsed = true;
      }
      return onceOutput;
  }
  return onceFunc;
}

function addByTwo(y) {
    return y + 2;
}

var secondOnceFunc = once(addByTwo);
var onceFunc = once(addByTwo);

console.log(secondOnceFunc(10));
console.log(onceFunc(4));  //should log 6
console.log(secondOnceFunc(200));
console.log(onceFunc(10));  //should log 6

// // UNCOMMENT THESE TO TEST YOUR WORK!

console.log(onceFunc(10));  //should log 6
console.log(onceFunc(9001));  //should log 6
// 1. define function once.
// 2. define function addByTwo
// 3. define variable onceFunc;
// -- INSIDE once --
// beenUsed = false
// function onceFunc(x)
// return onceFunc
// -- INSIDE onceFunc
// beenUsed = true
// func = addByTwo
// x = 4
// onceOutput = addByTwo(4) => 6.
// return onceOutput;



// -- INSIDE onceFunc
// beenUsed = true
// func = addByTwo 
// x = 10

// 4. assign result of once(addByTwo) to onceFunc
