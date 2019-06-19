# Build a Desktop Application with Angular and Electron
[Angular and Electron 1](https://alligator.io/angular/electron/) |
[Angular and Electron 2](https://medium.com/@yannmjl/how-to-build-native-cross-platform-desktop-apps-with-angular-electron-bd1d6e3919b2)
```javascript
npm install -g @angular/cli@7.3.6
ng new angular2electron --routing --style=scss
npm install -g electron@latest
npm install -g electron-packager@latest
npm install --save-dev electron@latest
npm install --save-dev electron-packager@latest
```
## [编译ng项目并进行精简electron打包]([https://link](https://stackoverflow.com/questions/49643270/angular-5-with-electron-packager))

* step1:   
  `ng new project`
* setp2:   
  `npm i -D electron`     
  `npm i -D electron-packager`
* step3:  
  `type >main.js`

```javascript
const { app, BrowserWindow } = require("electron");
const path = require("path");
const url = require("url");
let win;
function createWindow() {
  win = new BrowserWindow({ width: 800, height: 600 });
  // load the dist folder from Angular
  win.loadURL(
    url.format({
      pathname: path.join(__dirname, `/dist/index.html`),
      protocol: "file:",
      slashes: true
    })
  );
  // The following is optional and will open the DevTools:
  // win.webContents.openDevTools()
  win.on("closed", () => {
    win = null;
  });
}
app.on("ready", createWindow);
// on macOS, closing the window doesn't quit the app
app.on("window-all-closed", () => {
  if (process.platform !== "darwin") {
    app.quit();
  }
});
// initialize the app's main window
app.on("activate", () => {
  if (win === null) {
    createWindow();
  }
});
```
* step4:edit src/index.html
```html
<base href=”./”>
```
* step5:config package.json script
  
```json
  "scripts": {
    "web": "ng serve --open",
    "electron": "electron .",
    "build-prod":"ng build --prod",
    "build-electron":"ng build --prod && electron .",
    "package":"electron-packager . myEXE --no-prune --ignore=/node_modules --ignore=/e2e --ignore=/src --overwrite --app-version=1.0.0"
  }
```
