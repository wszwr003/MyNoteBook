```html
<img src="https://www.your-image-source.com/your-image.jpg" alt="if the image fails to load">
//Note that `img` elements are self-closing.
```
```html
<a href="#contacts-header">Contacts</a>
//...
<h2 id="contacts-header">Contacts</h2>
```
```html
<a href="http://freecatphotoapp.com" target="_blank">open by new tabs</a>
```
* ul : unordered list
* ol : ordered list
* 表单form的action属性用于指定提交地址。
* require属性用于提交时必须的参数
* checked 默认选择值
```html 
<form action="/submit-cat-photo">
    <label><input type="radio" name="indoor-outdoor" checked> Indoor</label>
    <label><input type="radio" name="indoor-outdoor"> Outdoor</label><br>
    <label><input type="checkbox" name="personality" checked> Loving</label>
    <label><input type="checkbox" name="personality"> Lazy</label>
    <label><input type="checkbox" name="personality"> Energetic</label><br>
    <input type="text" placeholder="cat photo URL" required>
    <button type="submit">Submit</button>
  </form>
  ```