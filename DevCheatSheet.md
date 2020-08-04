# Dev Cheap Sheet for MAC

## MAC 常用快捷键

| 功能说明          | 快捷键                |
| ----------------- | --------------------- |
| 显示桌面          | `F11`                 |
| 选区截屏          | `Shift` `Command` `4` |
| 截屏或录制        | `Shift` `Command` `5` |
| 访达显示隐藏文件  | `Shift` `Command` `.` |
| iTerm 全局 Select | `Command` `h`         |

## Linux 常用命令

| 功能 | 命令 | 说明 |
| --- | --- | --- |
| **查看特定进程** | `ps -ef | grep ssh` |  |
| 查看所有进程 | `ps -ef` | 包括父进程信息 |
| 查看所有进程 | `ps aux` | 包括包括 cpu 和内存占用情况 |
| 查看当前用户进程 | `ps -u root` |  |
| 查看本 CLI 下进程 | `ps -l` | 显示属于这次登入的进程下的所有进程 |
| **查看监听端口** | `netstat -nlp | grep LISTEN` |  |
| MAC 查看所有监听端口 | `netstat -AaLlnW` |  |
| 查看 MAC/Linux 内核版本 | `uname -a;` | 备用:<br> `cat /proc/version;` |
| 查看 Linux 发行版本 | `cat /etc/issue;` | 备用:<br> `lsb_release -a;` <br> `cat /etc/redhat-release;` |
| SCP 文件发送 | `scp -P 22 -r ./filename hostname@remoteip:some/directory` | -P: 表示 port |
| SCP 文件获取 | `scp -P 22 -r hostname@remoteip:some/directory ./` | -r: 表示递归目录 |

## Visual Studio Code 常用快捷键

| **功能**                       | 命令                                | 说明                              |
| ------------------------------ | ----------------------------------- | --------------------------------- |
| `通用快捷窗口`                 | `Command` `P`                       | 输入 `?` 查询用法                 |
| `命令快捷窗口`                 | `Shift` `Command` `P`               | 通用命令、系统设置、插件命令      |
| **文本编辑**                   |                                     |                                   |
| `剪切行、删除行`               | `Command` `X`                       | **empty selection**               |
| `复制行`                       | `Command` `C`                       | **empty selection**               |
| `在下方添加行`                 | `Command` `Enter`                   |
| `缩进行->`                     | `Command` `]`                       |
| `到文本顶或底部`               | `Command` `↑` or `↓`                | →←↑↓                              |
| `行注释开关`                   | `Command` `/`                       |
| **`区块注释开关`**             | `Shift` `Alt` `A`                   |
| **多光标操作&选择操作**        |                                     |                                   |
| `添加光标`                     | `Alt` `click`                       | `Alt` `Command` `↑` or `↓`        |
| **`相同处同时修改`**           | `Shift` `Command` `L`               | 选中所有该词出现处, 进行批量修改  |
| **`按作用域来减少或增加选取`** | `Shift` `Ctrl` `Command` `→` or `←` | 方便的删除一个 for 循环或一个函数 |
| **代码操作**                   |                                     |                                   |
| `代码提示`                     | `Ctrl` `Space`                      |
| `快速修复`                     | `Command` `.`                       |
| **`变量重命名`**               | `F2`                                |                                   |
| **集成终端**                   |                                     |                                   |
| `集成终端开关`                 | `Ctrl` `` ` ``                      |                                   |
| `打开新的终端`                 | `Shift` `Ctrl` `` ` ``              |                                   |

## MySQL

## Docker
