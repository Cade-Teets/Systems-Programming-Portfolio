#!/usr/bin/env bash
pwd
echo Bash is fun
echo Bash is fun > now
date >> now
uname -r >> now
wc -l now
cat now
cp now pastnow
cd ~
find -name pastnow
cd cse374/hw1
ls -l
chmod u=rwx,g=rx,o=r now
ls -l
cd ~
alias ll="ls -al"
ll
vim
ctrl-z
fg
ctrl-z
ps
ps | grep "vim"
kill -9 [pid]
echo "$USER is great"
exit
