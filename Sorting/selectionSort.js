/*  walkthrough to get algorithm straight in my head.
example unsorted array [1, 3, 100, 0, 12, 2]

1. find the smallest element = 0;
2. replace the smallest element with the 0th element in the array.
   [0, 3, 100, 1, 12, 2]
3. find the smallest element in the unsorted portion of the array = 1
4. replace that smallest element with the 1st element in the array.
   [0, 1, 100, 3, 12, 2]
5. find the smallest element in unsported portion of the array = 2
   replace that smallest element with the 2nd element in the array.
   [0, 1, 2, 3, 12, 100]
*/

function selectionSort(arr) {
  for (var i = 0; i < arr.length; i++) {
    //the unsortedPortion starts as the entire array, and decreases in size by 1 every iteration of the loop.
    var unsortedPortion = arr.slice(i, arr.length)
    //below is the trickiest line in the program. it's important to add i to the index of the of the smallest element in the unsorted portion
    //this is because the unsorted portion shrinks by 1 each time the for loop iterates.
    var posOfSmallest = getIndexOfSmallestElement(unsortedPortion) + i;
    //replace the element in the i'th position with the smallest element.
    var temp = arr[i];
    arr[i] = arr[posOfSmallest]
    arr[posOfSmallest] = temp;
  }
  return arr;
}
//helper function. gets the index of the smallest element.
//this is what we use on the unsorted portion to get the index of the next smallest.
function getIndexOfSmallestElement(arr) {
  var indexOfCurrentSmallest = 0
  for (var i = 0; i < arr.length; i++) {
    if (arr[i] < arr[indexOfCurrentSmallest]) {
      indexOfCurrentSmallest = i;
    }
  }
  return indexOfCurrentSmallest;
}
