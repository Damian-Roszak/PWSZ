




var bet;
var rnd;
var referenceToNewWindow;
var cash=0;
var objPole;
var konto = 100;
var RUNDY = 0;


function f(objButton){  
    ++RUNDY;
            //jakiBet(objButton);
    bet = objButton.value;

    console.log ("stawiam na = "+bet);
   objPole = objButton;
    console.log("stan konta: "+ konto);
    
        ruletLength();
}

var ruletka = 
[36,13,27,6,34,17,25,2,21,4,19,15,32,0,26,3,35,12,28,7,29,18,22,
9,31,14,20,1,33,16,24,5,10,23,8,30,11];

function ruletLength(){
   console.log('ruletka= '+ruletka.length);
    f3();
}

diva = document.getElementById("obr");
//setInterval(rul, 20);
var st = 10;
var st1 = 10;
var timing = 20;
var rys, rys1, rys2;
var mnoznikStopni;
var stopni = 9.7;
var degrees = 0;
var looper;
function rotateAnimation(elem,speed){
var el = document.getElementById(elem);
    diva.style.transform = "rotate("+ degrees +"deg)";
    looper = setTimeout("rotateAnimation('"+diva+"',"+speed+")",speed);
    degrees++;
    if(degrees>359) degrees = 1; 
    clearTimeout(looper);
}
function f2(objButton){
    cash = Number(objButton.value);
    cash = Number(cash);
    console.log ("gram za = "+ cash);

    /*let sp=20;   
    let d ="obr";
    rotateAnimation(d,sp);*/
    rys = setInterval(rulet, 11);
   	setTimeout(()=>{
        clearTimeout(rys);    	
	}, 3000);
	
    rys1 = setInterval(rulet, 114);
   	setTimeout(()=>{
        clearTimeout(rys1);    	
	}, 6000);
	
    rys2 = setInterval(rul, 314);
   	setTimeout(()=>{
        clearTimeout(rys2);    	
	}, 8000);
    f4();
}
function rul()
{
    //diva = document.getElementById("obr");   
      diva.style.transform = "rotate("+ (st + stopni*mnoznikStopni) +"deg)";
}

function rulet(){
diva.style.transform = "rotate("+ (++st1) +"deg)";
  
}

function f3() {
    var el = document.getElementById('cash');
    el.scrollIntoView(true);
}
var  pole;
var tagWynik = '';
var kolor;
var stawka = 'nie mnożona';
function f4() {
    var el1 = document.getElementById('obrazek');
    el1.scrollIntoView(true);
 
    rnd = Math.round(Math.random()*37);
    mnoznikStopni = rnd;
    console.log ("wylosowano IIII = "+rnd);
    rnd = ruletka[rnd];
    console.log ("wylosowano VVVV= "+rnd);
     pole = jakiBet(objPole);
     kolor = jakiKolor(rnd);
    //if(tagWynik == '')
    if (bet == rnd)
    {
    //debugger;
         obsługaKonta(tagWynik, pole);
         console.log (tagWynik +" = "+cash);
         wynik(tagWynik,kolor);
         return 0;
    }
    
    console.log (tagWynik );
    
    obsługaKonta(tagWynik, pole);
    wynik(tagWynik,kolor);
    
}
function jakiKolor(r){
     let tmp = 'bn'+r;
     let p = document.getElementById(tmp);
     let ar = p.className.split(' ');
     if (ar[0]=='btnBlk') return 'czarne';
     if (ar[0]=='btnRed') return 'czerwone';
     return 'zielone';
}
function jakiBet(objButton){
    let tNameKlasy = objButton.className.split(' ');
    let tNameValue = objButton.value.split(' ');
    let bt = 'bn'+ rnd;
    let hipotetykalBtn = document.getElementById(bt);

    if((tNameKlasy[0] == 'btnRed' || tNameKlasy[0] == 'btnBlk') && bet == rnd){
        tagWynik = 'WYGRANA';
        return tNameKlasy[0];
    }
    else if(tNameKlasy[0] == 'pole112' && (rnd >= 1 && rnd <= 12)){  
        tagWynik = 'WYGRANA';
        return 'pole112';
    }
    else if(tNameKlasy[0] == 'pole212' && (rnd >= 13 && rnd <= 24)){  
        tagWynik = 'WYGRANA';
        return 'pole212';
    }
    else if(tNameKlasy[0] == 'pole312' && (rnd >= 25 && rnd <= 36)){  
        tagWynik = 'WYGRANA';
        return 'pole312';
    }
    
    else if(tNameKlasy[0] == 'pole118' && (rnd >= 1 && rnd <= 18)){  
        tagWynik = 'WYGRANA';
        return 'pole118';
    }
    else if(tNameKlasy[0] == 'pole1936' && (rnd >= 19 && rnd <= 36)){  
        tagWynik = 'WYGRANA';
        return 'pole1936';
    }
    else if(tNameKlasy[0] == 'even' && (rnd % 2 == 0)){  
        tagWynik = 'WYGRANA';
        return 'even';
    }
    else if(tNameKlasy[0] == 'szansa' && (rnd % 2 != 0)){  
        tagWynik = 'WYGRANA';
        return 'szansa';
    }
    //================
    else if(tNameKlasy[0] == 'czer' )
    {  
        let tk = hipotetykalBtn.className.split(' ');
        if (tk[0] == 'btnRed') {
            tagWynik = 'WYGRANA';        
            return 'szansa';
        }        
        tagWynik = 'PRZEGRANA';
    }
    else if(tNameKlasy[0] == 'blak' )
    {
        let tk = hipotetykalBtn.className.split(' ');  
        if (tk[0] == 'btnBlk') {
            tagWynik = 'WYGRANA';        
            return 'szansa';
        }        
        tagWynik = 'PRZEGRANA';
    }
    else if(tNameKlasy[0] == 'strzałka3' )
    {
        let tk = tNameValue[1].split('-');  
        //console.log('tNameKlasy[0] == ' + tNameKlasy[0] +'|||| tk[0] = ' + tk[0] + ' tk[1] = ' + tk[1] +' tk2 = ' + tk[2]);
        if (rnd >= tk[0] && rnd <= tk[1] ) {
            tagWynik = 'WYGRANA';        
            return tNameKlasy[0];
        }        
        tagWynik = 'PRZEGRANA';
    }
    else if(tNameKlasy[0] == 'strzałka12' && tNameValue[1] == 1)
    {
    let i = 1;
        let tk = tNameValue[1].split('-');  
        console.log('tNameValue[0] == ' + tNameValue[0] +'|||| tk[0] = ' + tk[0] + ' tNameValue[1] = ' + tNameValue[1] +' tk2 = ' + tk[2]);
        for(i = 1; i<35; i += 3)
        {
             console.log('kolumna 1= ' + i);
             if (rnd == i){
                tagWynik = 'WYGRANA';        
                return tNameKlasy[0];
             }
        }
        tagWynik = 'PRZEGRANA';
    }
    else if(tNameKlasy[0] == 'strzałka12' && tNameValue[1] == 2)
    {
    let i = 1;
        let tk = tNameValue[1].split('-');  
        console.log('tNameValue[0] == ' + tNameValue[0] +'|||| tk[0] = ' + tk[0] + ' tNameValue[1] = ' + tNameValue[1] +' tk2 = ' + tk[2]);
        for(i = 2; i<36; i += 3)
        {
             console.log('kolumna 2= ' + i);
             if (rnd == i){
                tagWynik = 'WYGRANA';        
                return tNameKlasy[0];
             }
        }
        tagWynik = 'PRZEGRANA';
    }
    else if(tNameKlasy[0] == 'strzałka12' && tNameValue[1] == 3)
    {
    let i = 1;
        let tk = tNameValue[1].split('-');  
        console.log('tNameValue[0] == ' + tNameValue[0] +'|||| tk[0] = ' + tk[0] + ' tNameValue[1] = ' + tNameValue[1] +' tk2 = ' + tk[2]);
        for(i = 3; i<37; i += 3)
        {
             console.log('kolumna 3= ' + i);
             if (rnd == i){
                tagWynik = 'WYGRANA';        
                return tNameKlasy[0];
             }
        }
        tagWynik = 'PRZEGRANA';
    }
    
        
        tagWynik = 'PRZEGRANA';
    
}
var price;
function obsługaKonta(wygPrzeg, pole){    
//debugger;
   // let arr = pole.className.split(' ');

    if(wygPrzeg == 'WYGRANA')
    {
        if (pole== 'btnBlk' || pole == 'btnRed')
        {
                price = cash * 35;
                konto += price;
                stawka ="35:1";
        }        
        else if(pole == 'strzałka3')
        {
                price = cash * 11;
                konto += price;
                stawka ="11:1";
        }       
        else if(pole == 'strzałka12' || pole == 'pole112' || pole == 'pole212' || pole == 'pole312')
        {
                price = cash * 2;
                stawka ="2:1";
                konto += price;
        }
                
                
        else {
                price = cash;
                stawka ="1:1";
                konto += cash;
        }
        
        console.log("stan konta: "+ konto);
        return 0;
    }
        stawka ="odj";
        price = cash;
        konto -= cash;
        console.log("stan konta: "+ konto);
        if (konto <= 0) {
            console.log("stan konta: "+ konto + '; PRZEGRANA grałeś: ' + RUNDY + 'rund');
            modalWyniku.innerHTML = "stan konta: "+ konto + '; PRZEGRANA grałeś: ' + RUNDY + 'rund';
            flagaWyniku = 1;
        }
}
var flagaWyniku = 0;
    var modalWyniku = document.getElementById('modalBody');
function wynik(opcja, kolor){
if (flagaWyniku == 0)
    modalWyniku.innerHTML = ' Wylosowano: '+ rnd +' ' + kolor + '<br> wybrałeś: ' + bet 
                            + '<br> postawiłeś na to: ' + cash
                            +"<br> stawka: " + stawka
                             + '<br>'+ opcja + ' ' + price + '<br>' + 'Twój stan konta: ' + konto;
}



