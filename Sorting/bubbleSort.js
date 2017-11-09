//sort array of numbers using bubble sort algorithm.

function bubbleSort(arr) {
  //set counter to -1 to initialize while loop.
  var counter = -1;
  while (counter !==0) {                    
    //reset counter to 0 after every iteration of the while loop. this will remain 0 when no swaps have been made and the loop will break
    counter = 0;
    for (var i = 0; i<arr.length; i++) {                       
      if (arr[i] > arr[i+1]) {             
        //create variable to hold the value in the position which is going to be overwritten
        var temp = arr[i+1];
        arr[i+1] = arr[i];
        arr[i] = temp;
        counter++;
      }
    }
  }
  return arr;
}
