/*
Challenge 10 

Create a function defineFirstArg that accepts a function and an argument.
Also, the function being passed in will accept at least one argument.
defineFirstArg will return a new function that invokes the passed-in function with the passed-in argument as the passed-in function's first argument.
Additional arguments needed by the passed-in function will need to be passed into the returned function. 

*/

/*

I am not sure if my solution works because it assumes the passed in func (add in this case) accept 1 argument, namely an array.
If the passed in func accepts multiple parameters (x,y,z - for instance- in the case of add), then its arguments would have to be converted into an array before being passed into the hidden func.

*/
function defineFirstArg(func, arg) {
    function hidden(arr) {
        arr.unshift(arg);
        return func.call(func, arr);
    }
    return hidden;
}

function add(arr) {
    var sum = 0;
    for (var i = 0; i<arr.length; i++) {
      sum += arr[i];
    }
    return sum;
}

var add30 = defineFirstArg(add, 30);
var a1 = [1,2,3];
add30(a1);
