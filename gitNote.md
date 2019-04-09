# GIT
[Learn Enough Git to Be Dangerous](https://www.learnenough.com/git-tutorial?single_page=1#cha-1_footnote-4)
### locate git cmd
```
where git //windows
which git //unix
```
### after install before use
```
git config --global user.name "HongliangWang"
git config --global user.email "whl7770@gmail.com"
```
this configuration allow GIT to identify your changes by name and email address,which is especially helpful when collaborating with others!
### alias
```
git config --gloable alias.co checkout //co means checkout
```
### initializing the repository
```
[C:\myproject] $ git init
```
### make new file
```
touch index.html //unix
type null>index.html  //win
echo null>index.html  //win
```
### query status&add track file
```
git status
git add -A //add all --all
```
### commit modify
```
git commit -m //--message -a --all
```
![](./git_status_sequence.png)
### query latest commit message
```
git log
```
