fs = require('fs');
let dataKlient = [];
let dataRachunek = [];
let i = 0;

class recordKlient{
  constructor(nr_klienta, imie, nazwisko, data_urodzenia, miejsce_zamieszkania, PESEL, czyUsuniete){
    this.nr_klienta = nr_klienta;
    this.imie = imie;
    this.nazwisko = nazwisko;
    this.data_urodzenia = data_urodzenia;
    this.miejsce_zamieszkania = miejsce_zamieszkania;
    this.PESEL = PESEL;
    this.czyUsuniete = czyUsuniete;
  }
}


function createTableRowKlient(dataKlient,i){
  const wiersz = document.createElement('tr');
  const col = document.createElement('td');
  const col0 = document.createElement('td');
  const col1 = document.createElement('td');
  const col2 = document.createElement('td');
  const col3 = document.createElement('td');
  const col4 = document.createElement('td');
  const col5 = document.createElement('td');
  const col6 = document.createElement('td');
  col.innerHTML = i; 
  col0.innerHTML = dataKlient.nr_klienta; 
  col1.innerHTML = dataKlient.imie;
  col2.innerHTML = dataKlient.nazwisko;
  col3.innerHTML = dataKlient.data_urodzenia;
  col4.innerHTML = dataKlient.miejsce_zamieszkania;
  col5.innerHTML = dataKlient.PESEL;
  //col6.innerHTML = dataKlient.czyUsuniete;
  wiersz.append(col, col0,col1, col2, col3,col4,col5); 
  return wiersz;
}

function displayDataKlient(){
  const dataTableKlient = document.getElementById('data_table_klient');
  dataTableKlient.innerHTML = '<tr><th>L.p.0</th><th>Numer Klienta</th><th>Imię</th><th>Nazwisko</th><th>data urodzenia</th><th>miejsce zamieszkania</th><th>PESEL</th></tr>';
  for(let i=0; i<dataKlient.length; i++){
    const newRow = createTableRowKlient(dataKlient[i],i);
    dataTableKlient.append(newRow);
  }
}
function saveDataKlient(){
  const jsonData = JSON.stringify(dataKlient);
  fs.writeFileSync('dataKlient.txt', jsonData);
}

function loadDataKlient(){
  const jsonData = fs.readFileSync('dataKlient.txt');
  dataKlient = JSON.parse(jsonData);
  displayDataKlient();
}

class recordRachunek{
  constructor(id_klienta, typ_rachunku, stan, czyUsuniete){
    this.id_klienta = id_klienta;
    this.typ_rachunku = typ_rachunku;
    this.stan = stan;
    this.czyUsuniete = czyUsuniete;
  }
}

function displayDataRachunek(){
  const dataTableRachunek = document.getElementById('data_table_Rachunek');
  dataTableRachunek.innerHTML = '<tr><th>L.p.0</th><th>Numer Klienta</th><th>Typ Rachunku</th><th>Stan</th></tr>';
  for(let i=0; i<dataRachunek.length; i++){
    const newRow = createTableRowRachunek(dataRachunek[i],i);
    dataTableRachunek.append(newRow);
  }
}

function createTableRowRachunek(dataRachunek,i){
  const wiersz = document.createElement('tr');
  const col = document.createElement('td');
  const col0 = document.createElement('td');
  const col1 = document.createElement('td');
  const col2 = document.createElement('td');
  //const col3 = document.createElement('td');
  col.innerHTML = i; 
  col0.innerHTML = dataRachunek.id_klienta; 
  col1.innerHTML = dataRachunek.typ_rachunku;
  col2.innerHTML = dataRachunek.stan;
  //col3.innerHTML = dataRachunek.czyUsuniete;
  wiersz.append(col, col0,col1, col2); 
  return wiersz;
}

function saveDataRachunek(){
  const jsonData = JSON.stringify(dataRachunek);
  fs.writeFileSync('dataRachunek.txt', jsonData);
}

function loadDataRachunek(){
  const jsonData = fs.readFileSync('dataRachunek.txt');
  dataRachunek = JSON.parse(jsonData);
  displayDataRachunek();
}


function randomText(){
  const alphabet = 'ABCDEFGHIJKLMNOPRSTUWZ';
  const length = alphabet.length;
  let text = '';
	  for(let i=0; i< 5; i++){
	    const index = Math.round(Math.random() * length);
	    const char = alphabet.charAt(index);
	    text+=char;
	  }
  return text;
}

function randomNum(){
  let text = '';
  for(let i=0; i< 5; i++){
    const index = Math.round(Math.random() * 9);
    text+=index;
  }
  return text;
}

function randomPesel(){
  let text = '';
  for(let i=0; i< 11; i++){
    const index = Math.round(Math.random() * 9);
    text+=index;
  }
  return text;
}

function randomDataUr(){
  let text = '';
  for(let i=0; i< 2; i++){
    const index = Math.round(Math.random() * 9);
    text+=index;
  }
  text += '-';
  for(let i=0; i< 2; i++){
    const index = Math.round(Math.random() * 9);
    text+=index;
  }
  text += '-';
  for(let i=0; i< 4; i++){
    const index = Math.round(Math.random() * 9);
    text+=index;
  }
  return text;
}

function randomTyp(){
  const alphabet = ["Konto ROR","Konto Oszczędnościowe", "Lokata", "Pożyczka", "Kredyt", "Leasing"]; //[{"Konto ROR"},{"Konto Oszczędnościowe"}, {"Lokata"},{ "Pożyczka"}, {"Kredyt"},{ "Leasing"}];
//  const length = alphabet.length;
  let text = '';
	    const index = Math.round(Math.random() * 6);
	    text = alphabet[index];
  return text;
}

function randomDane(){
  const ile = Math.round(Math.random() * 99);
  for(let i = 1; i<= ile; i++){
    const lp = i;
    const randNr = randomNum();
    const randImie = randomText();
    const randNazwisko = randomText();
    const randData = randomDataUr();
    const randAdres = randomText();
    const randPESEL = randomPesel();
    const czyUsun = "TRUE";
    const dataKli = new recordKlient(randNr, randImie, randNazwisko, randData, randAdres, randPESEL, czyUsun);
    dataKlient.push(dataKli);
    
    const randTyp = randomTyp();
    const randStan = randomNum();
    const dataRach = new recordRachunek(randNr, randTyp, randStan, czyUsun);
    dataRachunek.push(dataRach);
  }
  displayDataRachunek();
  displayDataKlient();
  
  saveDataRachunek();
  saveDataKlient();
}

function randomData(){
  let randNo = parseInt(document.getElementById('rand_no').value);

  for(let i =1; i<= randNo; i++){
    const lp = i;
    const randNr = randomNum();
    const randImie = randomText();
    const randNazwisko = randomText();
    const randData = randomDataUr();
    const randAdres = randomText();
    const randPESEL = randomPesel();
    const czyUsun = "TRUE";
    const dataKli = new recordKlient(randNr, randImie, randNazwisko, randData, randAdres, randPESEL, czyUsun);
    dataKlient.push(dataKli);
    
    const randTyp = randomTyp();
    const randStan = randomNum();
    const dataRach = new recordRachunek(randNr, randTyp, randStan, czyUsun);
    dataRachunek.push(dataRach);
  }
  displayDataRachunek();
  displayDataKlient();
  
  saveDataRachunek();
  saveDataKlient();
}

function poka(){
 const dat = document.getElementById('outputs');
  dat.innerHTML = 'huj';
}


//   MySQL    MySQL   MySQL    MySQL   MySQL    MySQL   MySQL    MySQL   MySQL    MySQL   MySQL    MySQL
//   MySQL    MySQL   MySQL    MySQL   MySQL    MySQL   MySQL    MySQL   MySQL    MySQL   MySQL    MySQL
//   MySQL    MySQL   MySQL    MySQL   MySQL    MySQL   MySQL    MySQL   MySQL    MySQL   MySQL    MySQL


    const sql = require('mssql');
    sql.connect('Server=127.0.0.1,1433;User Id=sa;Password=Pass@word;Database=bazy;TrustServerCertificate=true');


    async function insertData(){
      const tekst1 = Math.round(Math.random()*100)+'abc';
      const tekst2 = Math.round(Math.random()*100)+'xyz';
      const result = await sql.query(`INSERT INTO tab(a, b) values ('${tekst1}', '${tekst2}')`);
      
    }

    function appendDataToBody(data){
      const table = document.createElement('table');
      data.forEach(row =>{
        const dataRow = document.createElement('tr');
        table.append(dataRow);
        const cell1 = document.createElement('td');
        const cell2 = document.createElement('td');
        cell1.innerHTML = row.a;
        cell2.innerHTML = row.b;
        dataRow.append(cell1);
        dataRow.append(cell2);
      });
      document.body.append(table);
    }

    async function selectData(){
      const result = await sql.query`select * from tab`;
      console.log(result);
      appendDataToBody(result.recordsets[0]);
    }

    async function deleteAllFromTab(){
      const result = await sql.query(`DELETE from tab`);
      console.log(result);
    }
    
    


    const { Client } = require('pg');

    const client = new Client({
      host: "127.0.0.1",
      port: 5432,
      database: "baza",
      user: "user",
      password: "password"
    });
    client.connect();

    function createTable(){
      const query = `
        CREATE TABLE studenci(
          name varchar,
          surname varchar,
          age int
        );
      `;
      client.query(query, (err, res)=>{
        if(err){
          console.log(err);
          return;
        }
        console.log("Tabela stworzona");
      })
    }

    function promiseExample(){
      client.query("SELECT NOW() as now")
      .then(res=>console.log(res.rows[0]))
      .catch(err=> console.log(e));
    }

    function parametersExample(){
      const sql = "INSERT INTO studenci(name, surname,age) VALUES($1, $2, $3) RETURNING *";
      const longName = [
        "Jan",
        "Marian",
        "Drugi",
        "z rodu Potockich"
      ];
      const parameters = [longName, "Kowalski", 15];
      client.query(sql, parameters)
      .then(res=>{
        console.log(res.rows[0]);
      })
      .catch(err=>console.log(err));
    }

    async function getFields(){
      const sql = "SELECT * FROM studenci";
      const query = {
        text: sql,
        rowMode: 'array',
      };
      const result = await client.query(query);
      const div = document.querySelector("#div");
      div.innerHTML = JSON.stringify(result.rows);
    }

    function endConnection(){
      client.end();
    }











