//inputs sorted arrays, outputs an array of their intersection.
//will duplicate repeats if they appear in the input arrays.
//works a lot like mergeSort, using array pointers and changing the pointer value based on which condition is satisfied.

function intersectSortedArrays (arr1,arr2) {
  var n = arr1.length;
  var m = arr2.length
  var p1 = 0;
  var p2 = 0;
  var intersectSorted = [];
  //the loop will terminate when either of the arrays has been iterated through (there won't be any more matches)
  //if there's a match, increase the 
  while (p1 < n && p2 < m) {
    if (arr1[p1] === arr2[p2]) {
      intersectSorted.push(arr1[p1]);
      p1++;
      p2++;
    } else if (arr1[p1] < arr2[p2]) {
      p1++;
    } else if (arr1[p1] > arr2[p2]) {
      p2++;
    }
  }
  return intersectSorted;
}

//test below
var expected = [0,8]
function assertArraysEqual(actual, expected, testName) {
  var actualString = JSON.stringify(actual);
  var expectedString = JSON.stringify(expected);
  if (actualString.length === expected.string.length && actualString === expectedString) {
    console.log('passed test');
  } else {
    console.log('FAILED [' + testName + '] Expected ' + expected + ' but got, ' + actual);
  }
}

var arr1 = [0,0,1,2,3,4,5,8,9,10];
var arr2 = [0,0,6,6,7,8];
var expected = [0,0,8];
assertArraysEqual(intersectSortedArrays(arr1,arr2), expected, 'arrays should be equal')  => passed
expected = [0,8];
assertArraysEqual(intersectSortedArrays(arr1,arr2), expected, 'arrays should be equal')  => 'FAILED [should be identical arrays] Expected "0,8", but got "0,0,8"
