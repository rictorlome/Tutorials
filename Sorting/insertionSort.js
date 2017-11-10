//insertion sort works by defining the first element in the array as sorted.
//then inserting each subsequent element in the array in the correct location, progressively building a sorted array.


function insertionSort(arr) {
  var sortedPortion = arr.slice(0,1)
  for (var i = 1; i<arr.length; i++) {
    sortedPortion = insertNumberIntoSortedArray(arr[i],sortedPortion)
  }
  return sortedPortion;
}
//the helper function below was the trickiest part of this problem. i'm not sure that it's efficient. the flow is all bor
//given a sorted array and a number input, the function outputs an array with that number in the correct position.
function insertNumberIntoSortedArray(num, arr) {
  //if the array is empty, just put the number in it.
  if (arr.length === 0) {
    arr.push(num);
    return arr;
  //if the array has length one, determine if the current element is greater or larger than the num.
  //if smaller, add num to end of array. if larger, slide current element down one position and insert num in arr[0]
  } else if (arr.length === 1) {
    if (num <= arr[0]) {
    arr[1] = arr[0];
    arr[0] = num;
    return arr;
    } else if (num > arr[0]) {
      arr[1] = num;
      return arr;
    }
  //if the array has length 2 or more, determine if the num is greater than the largest element in the array.
  //if it is, add num to the end.
  //if it isn't, find the position where num belongs.
  //then slide every element > num down one position, and put num in the appropriate place.
  } else if (arr.length >= 2) {
    if (num > arr[arr.length-1]) {
      arr[arr.length] = num;
      return arr;
    } else {
        for (var i = 0; i<arr.length; i++) {
          if (num < arr[i]) {
            var index = i;
            break;
          }
        }
        for (var j = arr.length-1; j>=index; j--) {
          arr[j+1] = arr[j]
        }
        arr[index] = num;
        return arr;   
    }
  }
}
