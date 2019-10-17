##  [how to use **angular** ionic tabs](https://github.com/ionic-team/ionic/blob/master/CHANGELOG.md#angular-tabs)
```diff
 import { RouterModule, Routes } from '@angular/router';

 import { TabsPage } from './tabs.page';
 const routes: Routes = [
   {
     path: 'tabs',
     component: TabsPage,
     children: [

       {
         path: 'tab1',
+        children: [
+          {
+            path: '',
+            loadChildren: '../tab1/tab1.module#Tab1PageModule'
+          }
+        ]
       },
       {
         path: 'tab2',
+        children: [
+          {
+            path: '',
+            loadChildren: '../tab2/tab2.module#Tab2PageModule'
+          }
+        ]
       },
       {
         path: 'tab3',
+        children: [
+          {
+            path: '',
+            loadChildren: '../tab3/tab3.module#Tab3PageModule'
+          }
+        ]
+      },
+      {
+        path: '',
+        redirectTo: '/tabs/tab1',
+        pathMatch: 'full'
       }
     ]
   },
   {
     path: '',
+    redirectTo: '/tabs/tab1',
     pathMatch: 'full'
   }
 ];
```

```diff
 <ion-tabs>


   <ion-tab-bar slot="bottom">
+    <ion-tab-button tab="tab1">
       <ion-icon name="flash"></ion-icon>
       <ion-label>Tab One</ion-label>
     </ion-tab-button>

+    <ion-tab-button tab="tab2">
       <ion-icon name="apps"></ion-icon>
       <ion-label>Tab Two</ion-label>
     </ion-tab-button>

+    <ion-tab-button tab="tab3">
       <ion-icon name="send"></ion-icon>
       <ion-label>Tab Three</ion-label>
     </ion-tab-button>
   </ion-tab-bar>

 </ion-tabs>
```
## [在安卓设备上调试app时无法正常打开：net::ERR_CLEARTEXT_NOT_PERMITTED](https://stackoverflow.com/questions/54752716/why-am-i-seeing-neterr-cleartext-not-permitted-errors-after-upgrading-to-cordo)
* way1:
```xml
<!-- config.xml -->
<platform name="android">
  <edit-config file="app/src/main/AndroidManifest.xml" mode="merge" target="/manifest/application">
      <application android:usesCleartextTraffic="true" />
  </edit-config>
</platform>
```
* way2：如果way1不行
//resources/android/xml/network_security_config.xml 
```xml
<?xml version="1.0" encoding="utf-8"?>
<network-security-config>
    <domain-config cleartextTrafficPermitted="true">
        <domain>localhost</domain>
        <domain>192.168.43.145</domain><!-- add -->
    </domain-config>
</network-security-config>
```
//config.xml //to fix The connection to the server was unsuccessful.
```xml
<preference name="loadUrlTimeoutValue" value="60000" /> <!-- add -->
```
## [Ionic model/popover/page的使用及传递参数](https://www.youtube.com/watch?v=jRxPOs1OM34&list=PLMBoxY34XjTL_P7aKbwo_X_-8JXjWvNpl)