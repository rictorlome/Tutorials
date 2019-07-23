// i am really not sure if this mergeSort works correctly. i think it does, because there is only one loop statement in the entire function-pair
// which suggests that runtime would be less than < O(n^2).
// but i am not sure if my basecases (arr.length === 1) and (arr.length === 2) are both necessary, or if only one is required.
// also, with respect to memory, i am not sure if creating a mergedSorted[] in the helper function counteracts any efficiency gained with the recursive definition

function mergeSort(arr) {
  if (arr.length <= 0) {
    console.log('Please be reasonable.');
    return;
  } else if (arr.length === 1) {
    return arr;
  } else if (arr.length === 2) {
    if (arr[0] <= arr[1]) {
      return arr;
    } else {
      var temp = arr[1];
      arr[1] = arr[0];
      arr[0] = temp;
      return arr;
    }
    //the recursion happens below. sort left half. sort right half. merge them.
  } else {
    var n = Math.floor(arr.length/2);
    var arr1 = arr.slice(0,n);
    var arr1sorted = mergeSort(arr1);
    var arr2 = arr.slice(n, arr.length);
    var arr2sorted = mergeSort(arr2);
    return mergeSortedArrays(arr1sorted, arr2sorted);
  }
}
//basically merge the sorted arrays by looking at the first elements of each and then using .shift() to return the smaller.
//the .shift() method alters the original array so it isn't necessary to do anything fancy with the indices.
function mergeSortedArrays (arr1, arr2) {
//is it necessary to store the original lengths in separate variables because the lengths change? i thought so.
  var n = arr1.length;
  var m = arr2.length;
  var mergedSorted = [];
  while (mergedSorted.length !== n+m) {
    if (arr2.length === 0 || arr2[0] >= arr1[0]) {
      var nextMin = arr1.shift();
      mergedSorted.push(nextMin);
    } else if (arr1.length === 0 || arr1[0] > arr2[0]) {
      var nextMin = arr2.shift();
      mergedSorted.push(nextMin);
    }
  }
  return mergedSorted;  
}
