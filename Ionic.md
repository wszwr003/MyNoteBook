##  [1.how to use **angular** ionic tabs](https://github.com/ionic-team/ionic/blob/master/CHANGELOG.md#angular-tabs)
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