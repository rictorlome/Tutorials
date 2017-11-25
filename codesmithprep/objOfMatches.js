/*
Challenge 7

Construct a function objOfMatches that accepts two arrays and a callback.
objOfMatches will build an object and return it.
To build the object, objOfMatches will test each element of the first array using the callback to see
if the output matches the corresponding element (by index) of the second array.
If there is a match, the element from the first array becomes a key in an object, and the element from the second array becomes the corresponding value.

//console.log(objOfMatches(['hi', 'howdy', 'bye', 'later', 'hello'], ['HI', 'Howdy', 'BYE', 'LATER', 'hello'], function(str) { return str.toUpperCase(); }));
// should log: { hi: 'HI', bye: 'BYE', later: 'LATER' }

*/

// every
// foreach
// sum
// reduce
// map
// filter

//Challenge 7
function objOfMatches(array1, array2, callback) {
  var obj = {};
  for (var i = 0; i<array1.length; i++) {
      if (array2[i] === callBack(array1[i])) {
          obj[array1[i]] = array2[i];
      }
  }
  return obj;
}

function callBack(s) {
    return s.toUpperCase();
}

console.log(objOfMatches(['hi', 'howdy', 'bye', 'later', 'hello'], ['HI', 'Howdy', 'BYE', 'LATER', 'hello'], callBack));
