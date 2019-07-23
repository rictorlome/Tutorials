//definition of intersection, built off a helper function. repetitions in subArrays won't break it.

//helper function describes how to intersect two arrays.
//checks whether every element in arr1, is in arr2 + not already in intersection array (this avoids repetitions)
//if element satisfies this condition, it pushes the element into the output array
function intersectTwoArrays(arr1, arr2) {
    var result = [];
    arr1.forEach(function(element) {
        if (arr2.includes(element) && !result.includes(element)) {
            result.push(element);
        }
    })
    return result;
}


//if arrOfArrs.length < 2, return nothing or the only subArray.
//else, this function establishes the base as the intersection of the first two arrays.
//then it cycles through all subsequent subArrays, and updates the value of intersection as the intersection between the current intersection and the next subArray. 
function intersectArrayOfArrays(arrOfArrs) {
     if (arrOfArrs.length === 0) {
       return;
     }
     if (arrOfArrs.length === 1) {
       return arrOfArrs[0];
     }
     var intersection = intersectTwoArrays(arrOfArrs[0], arrOfArrs[1]);
     for (var i = 2; i<arrOfArrs.length; i++) {
         intersection = intersectTwoArrays(intersection, arrOfArrs[i]);
     }
     return intersection;
}
