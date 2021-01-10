# ASCII-Transfer

Server-Client combo zum transfer von ASCII-TEXT.

## Install

$git clone https://github.com/STORCH-paul/storch_project_1.git
$cd storch_project_1
$mkdir build
$cd build
$meson
$ninja

## Platforms
* Linux, FreeBSD, OpenBSD, Solaris, AIX
* Windows 
* macOS 

## Usage samples

#### Basic usage

$cd build
$./server ASCII-Text Test
$./client

#### Change Port

$cd build
$./server ASCII-Text Test -p 2121
$./client -p 2121