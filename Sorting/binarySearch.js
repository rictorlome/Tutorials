//inputs sorted array and number, outputs index of number in array or prints failure message (if number is not in array)
//the binary search makes guess at the index position of the number in the array.

function binarySearch(arr, num) {
  var maxIndex = arr.length;
  var minIndex = 0;
  //the guess has to be an integer so that is why the Math.floor function is used.
  //it is always half-way between the maxIndex and minIndex.
  var guess = Math.floor((maxIndex+minIndex)/2);
  //if arr[guess] > num, the function updates the maxIndex to that guess and guesses again.
  //it's vice versa for arr[guess] < num. this updates the minIndex.
  //this continues until the guess is correct or the max and min are adjascent indices, meaning the number is not in the array.
  while (arr[guess] !== num) {
    guess = Math.floor((maxIndex+minIndex)/2);
    if (arr[guess] > num) {
      maxIndex = guess;
    }
    if (arr[guess] < num) {
      minIndex = guess;
    }
    if (maxIndex === minIndex + 1) {
      console.log('The number is not in the array.');
      break;
    }
  }
  if (arr[guess] === num) {
    return guess;
  }
}
