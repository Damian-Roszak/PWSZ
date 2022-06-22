const { app, BrowserWindow} = require('electron');
const path = require('path');
let window;
function createWindow() {
  window = new BrowserWindow({
    webPreferences: {
      nodeIntegration: true,  contextIsolation: false,
    },
  });
  window.loadFile('index.html');
  window.openDevTools();
  window.on('closed', ()=>{ window = null;});
}
app.whenReady().then(() => {
  createWindow();
})
app.on('window-all-closed', () => {
  if (process.platform !== 'darwin') {
    app.quit()
  }
})