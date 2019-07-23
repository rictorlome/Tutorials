//this function inputs an array of arrays of numbers, and outputs an array with only the numbers that appear in all the arrays of numbers.
//it assumes there are no repititions of numbers within arrays, otherwise it breaks.

function intersect1(arrayOfArrays) {
    var result = [];
    var object = {};
    //loops through elements of arrayOfArrays. for each array...
    for (var i = 0; i<arrayOfArrays.length; i++) {
      var arr = arrayOfArrays[i];
      //loops through elements of array. for each number...
      for (var j = 0; j<arr.length; j++) {
        var element = arr[j];
        //set that number to be a property of an object. and set the value of that property to be its count.
        object[element] = (object[element] || 0) + 1;
      }
    }
    //loop through the properties of the object.
    for (var prop in object) {
      //if the value of the property (its count) is equal to the number of arrays in the arrayOfArrays, then it appears once in every array.
      //so convert that property to a number (it's a string), and push it into the result array.
      //again, this only works if there are no repetitions of numbers within arrays.
      if (object[prop] === arrayOfArrays.length) {
        var num = parseInt(prop, 10);
        result.push(num);
      }
    }
    return result;
}
