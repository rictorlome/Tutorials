//updated version of intersectSortedArrays that repeats shouldn't break
//the way it avoids repeats is by keeping track of the lastpush, and then incrementing p1 or p2 if arr1[p1] or arr2[p2] matches the last pushed

function intersectSortedArrays (arr1,arr2) {
  var n = arr1.length;
  var m = arr2.length
  var p1 = 0;
  var p2 = 0;
  var lastPushed;
  var intersectSorted = [];
  //the loop will terminate when either of the arrays has been iterated through (there won't be any more matches)
  while (p1 < n && p2 < m) {
    if (arr1[p1] === lastPushed) {
      p1++;
    }
    if (arr2[p2] === lastPushed) {
      p2++;
    }
    //i only have it checking whether one of the current values is !== lastPushed because they have to be equal to push, and if 1 is equal to the lastPush, the other one will be too.
    if (arr1[p1] === arr2[p2] && arr1[p1] !== lastPushed) {
      lastPushed = arr1[p1];
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
