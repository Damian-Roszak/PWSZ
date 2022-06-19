




var bet;
var rnd;
var referenceToNewWindow;
var cash=0;

function f(objButton){  
    bet = objButton.value;
    console.log ("stawiam na = "+bet); 
    rulet();
    
}
/*
let url = "popup.html";
let name = "okieneczko";
let features = "witdh=800, height=400";
    referenceToNewWindow = window.open(url, name, "width="+600+",height="+100);
*/

function rulet(){
   
    f3();
}

function f2(objButton){
    
    cash = Number(objButton.value);
    cash = Number(cash);
    console.log ("gram za = "+ cash);

    f4();
}

function f3() {
    var el = document.getElementById('cash');
    el.scrollIntoView(true);
}

function f4() {
    var el1 = document.getElementById('obrazek');
    el1.scrollIntoView(true);
    
    rnd = 10; //Math.round(Math.random()*37);      
    console.log ("wylosowano = "+rnd);
    if (bet == rnd)
    {
         cash = cash * 35;
         console.log ("WYGRANA = "+cash);
         return 0;
    }
    console.log ("PRZEGRANA ");
}





