//this is a sloppy workthrough to get the logic behind the printAllStrings function
// define your alphabet. each letter is an element in the array.
var alphabet = ['a','b','c','d'];

//create function printAllStrings
function printAllStrings(alphabet, ofLength) {
  //this array will be our output.
  var arrayOfAllStrings = [];
  //define a basecase. if you want all stings of length 1, print the elements of the initial array.
  if (ofLength === 1) {
    for (var i = 0; i<alphabet.length; i++) {
      arrayOfAllStrings.push(alphabet[i]);
    }
    return arrayOfAllStrings;
    console.log(arrayOfAllStrings);
  } else {
    //for ofLengths larger than 1, define your basecase as the arrayOfAllStrings for the previous ofLength.
    var baseCase = printAllStrings(alphabet, ofLength-1);
    //iterate through elements of baseCase array. for each element of the baseCase array...
    for (var j = 0; j<baseCase.length;j++) {
      //iterate through elements of alphabet array. for each character in the alphabet...
      for (var k = 0; k<alphabet.length; k++) {
        //concat that letter to the existing element in the baseCase.
        var string = baseCase[j].concat(alphabet[k]);
        //and push that new string into the arrayOfAllStrings;
        arrayOfAllStrings.push(string);
      }
    }
    return arrayOfAllStrings;
    //this prints the entire array. if you want each member of the array printed on a separate line, just iterate through the array and print each element.
    console.log(arrayOfAllStrings);
  }
}
