/*
Challenge 9

Create a function majority that accepts an array and a callback.
The callback will return either true or false.
majority will iterate through the array and perform the callback on each element
until it can be determined if the majority of the return values from the callback are true.
If the number of true returns is equal to the number of false returns, majority should return false.
*/

// Challenge 9
function majority(array, callback) {
//   var counter = 0;
//   array.forEach(function (element) {
//       if (callback(element)) {
//           counter++;
//       }
//   });
  function addTrues(acc, x) {
      if (callback(x)) {
          return acc + 1;
      } else {
      return acc;
      }
  }
  
//   !! https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/Reduce
  var totalNumberOfTrues = array.reduce(addTrues, 0);
  return totalNumberOfTrues > array.length/2;
}

//reduce//
function reduce(array,func,init) {
    array.forEach(function (x) {
        init = func(init,x);
    });
    return init;
}

//





// To check if you've completed it, uncomment these lines!
const isOdd = function(num) { return num % 2 === 1; };
console.log(majority([1, 2, 3, 4, 5], isOdd)); // should log: true
console.log(majority([2, 3, 4, 5], isOdd)); // should log: false
