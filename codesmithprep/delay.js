// Challenge 7

// Write a function delay that accepts a callback as the first parameter and the wait - in milliseconds
// before allowing the callback to be invoked - as the second parameter.
// Any additional arguments after wait are provided to func when it is invoked. 
// HINT: research setTimeout(); 


// sorry, phone died!

//Challenge 7
function delay(func, wait) {
    // https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Functions/arguments
    
    // 1. arguments local variable
    
  var possibleParameters = arguments.slice(2, arguments.length);
  function whenCalled () {
    // convert func from a function which takes a certain number of parameters
    // into a function that takes no parameters.
    // partially apply the function to the parameters.
    // 2. call: run the function with a LIST of parameters (in contrast to splayed out parameters: f(x, y, z)  )
    // 3. convert a function from a certain number of parameters to 0 parameters
    
    var f = function() { func.call(func, possibleParameters); };
    setTimeout(f, wait);
  }
  return whenCalled;
}
// https://www.w3schools.com/jsref/met_win_settimeout.asp


function myAlert(x, y) { alert("hello! x is " + x + ", and y is " + y); }

var f = delay(myAlert, 1000, 10, 20);

f() // countdown starts now!!
