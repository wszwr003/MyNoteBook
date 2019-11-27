# archive under linux 
## tar
The program tar originally stands for Tape Archiver, it was used to back up data to tape drives. It is still very popular and widespread today. A pure tar archive is not compressed.  
* Extract an archive:  
`tar xfv archive.tar`
Legend: (x = extract, f = file, v = verbose)  
* Create an archive with files or folder:  
`tar cfv archive.tar file1 file2 file3`  
Legend: (c = create)  
* Create compressed archives:  
`tar cfzv archive.tar file1 file2 file3`  
Legend: (z = compress with gzip)  
* Show all files of an archive:  
`tar tvf archive.tar`  
## gz, bzw. gzip
As we know, a tar archive is not compressed without additional options, this can be done with the additional option gzip. gzip stands for GNU zip and the file extension .gz is appended to the tar archive.  
* Create a compressed file:  
`gzip file`  
Result: file.gz  
* Decompress a file:  
`gunzip file`  
* Combining files in a compressed archive:  
`tar cfvz archive.tar.gz file1 file2`  
Result: archiv.tar.gz  
* Decompress and extract an archive:  
`tar xfvz archive.tar.gz`    
## bz2, bzw. bzip2
Besides gzip there is also bzip2, it is very similar to gzip, but uses a different algorithm.   
* Create a compressed file:  
`bzip2 file`  
Result: file.bz2  
* Decompress a file:  
`bunzip2 file.bz2`  
* Combining files in a compressed archive:  
`tar cfvj archive.tar.bz2 file1 file2`  
Result: archive.tar.bz2  
* Decompress and extract an archive:  
`tar xfvj archive.tar.bz2`  
## zip  
The tool zip is mainly used in Windows , but is also available for Linux-based operating systems.  
* Combining individual files in a compressed archive:  
`zip archive.zip file1 file2`  
* Combining complete folders in a compressed archive:  
`zip -r archive.zip folder1 folder2 folder3`  
* Decompress and extract an archive:  
`unzip archive.zip`  
* Show all files of an archive:  
`unzip -l archive.zip`
# 查看linux系统版本
查看内核版本:  
`uname -a;`   
`cat /proc/version;`  
查看发行版本:  
`cat /etc/issue;`  
`lsb_release -a;`  
`cat /etc/redhat-release;`  
# 查看linux运行线程pid及关闭线程
`ps -h`  
`kill "pid"`
# 批量删除相似文件
`rm -rf name{1..200}name`  
# centos 安装samba
`rpm –qi samba`  
`yum remove –y samba`  
`yum -y install samba samba-client`  