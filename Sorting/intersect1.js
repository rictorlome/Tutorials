//this function inputs an array of arrays of numbers, and outputs an array with only the numbers that appear in all the arrays of numbers.
//it assumes there are no repititions of numbers within arrays, otherwise it breaks.

function intersect1(arrayOfArrays) {
    var result = [];
    var object = {};
    for (var i = 0; i<arrayOfArrays.length; i++) {
      var arr = arrayOfArrays[i];
      for (var j = 0; j<arr.length; j++) {
        var element = arr[j];
        object[element] = (object[element] || 0) + 1;
      }
    }
    for (var prop in object) {
      if (object[prop] === arrayOfArrays.length) {
        var num = parseInt(prop, 10);
        result.push(num);
      }
    }
    return result;
}
