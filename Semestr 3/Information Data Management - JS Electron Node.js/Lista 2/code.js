
fs = require('fs');
let data = [];

class record{
  constructor(imie){
    this.imie = imie;
  }
}

function displayData(){
  const dataTable = document.getElementById('data_table');
  dataTable.innerHTML = '';
  for(let i=0; i<data.length; i++){
    const newRow = createTableRow(data[i]);
    dataTable.append(newRow);
  }
}

function createTableRow(data){
  const wiersz = document.createElement('tr');
  const col1 = document.createElement('td');
  const col2 = document.createElement('td');
  const col3 = document.createElement('td');
  col1.innerHTML = data.imie;
  col2.innerHTML = '...';
  col3.innerHTML = '...';
  wiersz.append(col1, col2, col3);
  return wiersz;
}

function addRow(){
  const inputName = document.getElementById('input_imie');
  const name = inputName.value;
  if(!inputName.checkValidity()) return;
  const dataObj = new record(name);
  data.push(dataObj);
  displayData();
}

function delRow(){
  const inputRowNo = document.getElementById('row_no');
  const n = parseInt(inputRowNo.value);
  data.splice(n,1);
  displayData();
}

function saveData(){
  const jsonData = JSON.stringify(data);
  fs.writeFileSync('data.txt', jsonData);
}

function loadData(){
  const jsonData = fs.readFileSync('data.txt');
  data = JSON.parse(jsonData);
  displayData();
}

function randomText(){
  const alphabet = 'abcdefghijklmnoprstuwz';
  const length = alphabet.length;
  let text = '';
  for(let i=0; i< 5; i++){
    const index = Math.round(Math.random() * length);
    const char = alphabet.charAt(index);
    text+=char;
  }
  return text;
}

function randomData(){
  const randNo = parseInt(document.getElementById('rand_no').value);
  data = [];
  for(let i =0; i< randNo; i++){
    const randText = randomText();
    const dataObj = new record(randText);
    data.push(dataObj);
  }
  displayData();
}